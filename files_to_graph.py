import os
import sys
import subprocess
from pathlib import Path
from multiprocessing import Pool, cpu_count
from functools import partial
from tqdm import tqdm

def process_file(input_file, output_dir, venv_python):
    """Обработка одного файла"""
    base_name = input_file.stem
    
    # joern-parse
    cpg_path = f"{output_dir}/cpg/{base_name}.bin"
    if not Path(cpg_path).exists():
        result = subprocess.run(f"joern-parse \"{input_file}\" -o \"{cpg_path}\"", 
                            shell=True, capture_output=True, text=True)
        if result.returncode != 0:
            return f"Failed to parse {input_file.name}: {result.stderr}"
    
    # joern-export --repr all
    repr_all_dir = f"{output_dir}/repr_all/{base_name}"
    if not Path(repr_all_dir).exists():
        result = subprocess.run(f"joern-export \"./{cpg_path}\" --repr all --out \"./{repr_all_dir}\"", 
                               shell=True, capture_output=True, text=True)
        if result.returncode != 0:
            return f"Failed to export all for {input_file.name}: {result.stderr}"
    
    # joern-export --repr pdg
    repr_pdg_dir = f"{output_dir}/repr_pdg/{base_name}"
    if not Path(repr_pdg_dir).exists():
        result = subprocess.run(f"joern-export \"./{cpg_path}\" --repr pdg --out \"./{repr_pdg_dir}\"", 
                               shell=True, capture_output=True, text=True)
        if result.returncode != 0:
            return f"Failed to export PDG for {input_file.name}: {result.stderr}"
    
    # merge.py
    output_file = f"{output_dir}/graphs/{base_name}.dot"
    if not Path(output_file).exists():
        merge_cmd = f"\"{venv_python}\" merge.py --pdg \"./{repr_pdg_dir}/*-pdg.dot\" --ref \"./{repr_all_dir}/export.dot\" -o \"./{output_file}\""
        result = subprocess.run(merge_cmd, shell=True, capture_output=True, text=True)
        if result.returncode != 0:
            return f"Failed to merge graphs for {input_file.name}: {result.stderr}"
    
    return f"Successfully processed {input_file.name}"

def main():
    if len(sys.argv) < 2:
        print(f"Usage: {os.path.basename(sys.argv[0])} <path/to/directory>")
        sys.exit(1)
    
    input_dir = os.path.abspath(sys.argv[1])
    if not os.path.isdir(input_dir):
        print(f"Directory \"{input_dir}\" does not exist")
        sys.exit(1)
    
    output_dir = f"{os.path.basename(input_dir)}_JOERN"
    Path(output_dir).mkdir(exist_ok=True)
    
    # os.environ["PATH"] = f"/home/alexey/bin/joern/joern-cli/bin:{os.environ.get('PATH', '')}"
    venv_python = sys.executable
    
    # Создаём все нужные директории
    for d in ["cpg", "repr_all", "repr_pdg", "graphs"]:
        Path(f"{output_dir}/{d}").mkdir(exist_ok=True)
    
    # Собираем все файлы для обработки
    files_to_process = [f for f in Path(input_dir).iterdir() if f.is_file()]
    
    if not files_to_process:
        print("No files found to process")
        return
    
    print(f"Processing {len(files_to_process)} files using {cpu_count()} cores...")
    
    # Создаём частичную функцию с фиксированными аргументами
    process_func = partial(process_file, output_dir=output_dir, venv_python=venv_python)
    
    # Запускаем параллельную обработку с tqdm
    with Pool(processes=cpu_count()) as pool:
        results = list(tqdm(
            pool.imap_unordered(process_func, files_to_process),
            total=len(files_to_process),
            desc="Processing files",
            unit="file"
        ))
    
    # Выводим результаты
    print("\n" + "=" * 50)
    for result in results:
        if "Successfully" not in result:
            print(result)
    
    print(f"\nAll files processed. Results saved to: {output_dir}")

if __name__ == "__main__":
    main()