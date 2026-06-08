import tkinter as tk
from tkinter import ttk, messagebox
from typing import List
from PlagiarismDB import PlagiarismDB


class PlagiarismViewer:
    def __init__(self, root, db_file="plagiarism.db"):
        self.root = root
        self.db_file = db_file
        self.db = PlagiarismDB(db_file)
        self.current_results = []
        self.last_selected_button = None

        # Переменные для пагинации
        self.current_offset = 0
        self.results_limit = 50
        self.current_filters = None  # для хранения текущих фильтров
        self.load_more_button = None

        # Настройка окна
        self.root.attributes('-fullscreen', True)
        self.root.title("Plagiarism Detection Results")

        self.setup_ui()
        self.load_initial_data()

    def setup_ui(self):
        """Настройка интерфейса"""
        main_frame = ttk.Frame(self.root)
        main_frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)

        # ФИЛЬТРЫ
        self.setup_filters(main_frame)

        # ОСНОВНОЕ СОДЕРЖИМОЕ
        content_frame = ttk.Frame(main_frame)
        content_frame.pack(fill=tk.BOTH, expand=True, pady=10)

        # Левая часть - результаты
        self.setup_results_section(content_frame)

        # Правая часть - коды
        self.setup_codes_section(content_frame)

        # СТАТУС БАР
        self.setup_status_bar(main_frame)

    def setup_filters(self, parent):
        """Панель фильтров"""
        filter_frame = ttk.LabelFrame(parent, text="Filters", padding=10)
        filter_frame.pack(fill=tk.X)

        ttk.Label(filter_frame, text="Contest:").grid(row=0, column=0, padx=5, pady=5)
        self.contest_var = tk.StringVar()
        self.contest_combo = ttk.Combobox(filter_frame, textvariable=self.contest_var, state="readonly", width=25)
        self.contest_combo.grid(row=0, column=1, padx=5, pady=5)
        self.contest_combo.bind('<<ComboboxSelected>>', self.on_contest_selected)

        ttk.Label(filter_frame, text="Problem:").grid(row=0, column=2, padx=5, pady=5)
        self.problem_var = tk.StringVar()
        self.problem_combo = ttk.Combobox(filter_frame, textvariable=self.problem_var, state="readonly", width=8)
        self.problem_combo.grid(row=0, column=3, padx=5, pady=5)

        ttk.Label(filter_frame, text="Size:").grid(row=0, column=4, padx=5, pady=5)
        self.size_var = tk.StringVar()
        self.size_combo = ttk.Combobox(filter_frame, textvariable=self.size_var, state="readonly", width=8)
        self.size_combo.grid(row=0, column=5, padx=5, pady=5)

        ttk.Button(filter_frame, text="Show Results", command=self.show_results).grid(row=0, column=6, padx=10, pady=5)
        ttk.Button(filter_frame, text="Clear", command=self.clear_all).grid(row=0, column=7, padx=5, pady=5)
        ttk.Button(filter_frame, text="Exit FS", command=self.toggle_fullscreen).grid(row=0, column=8, padx=5, pady=5)

    def setup_results_section(self, parent):
        """Левая панель с результатами"""
        results_container = ttk.LabelFrame(parent, text="Results", padding=5)
        results_container.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=(0, 5))

        # Создаем фрейм для прокрутки
        self.results_frame = ttk.Frame(results_container)
        self.results_frame.pack(fill=tk.BOTH, expand=True)

        # Создаем Canvas и Scrollbar
        self.canvas = tk.Canvas(self.results_frame, bg='white')
        scrollbar = ttk.Scrollbar(self.results_frame, orient="vertical", command=self.canvas.yview)

        # Настраиваем Canvas
        self.canvas.configure(yscrollcommand=scrollbar.set)
        self.canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

        # Создаем фрейм внутри Canvas для результатов
        self.results_inner_frame = ttk.Frame(self.canvas)
        self.canvas_window = self.canvas.create_window((0, 0), window=self.results_inner_frame, anchor="nw")

        # Привязка событий для правильной работы прокрутки
        self.results_inner_frame.bind("<Configure>", self.on_frame_configure)
        self.canvas.bind("<Configure>", self.on_canvas_configure)

        # Привязка колесика мыши к Canvas - ИСПРАВЛЕНО
        self.canvas.bind("<MouseWheel>", self.on_mousewheel)
        self.results_inner_frame.bind("<MouseWheel>", self.on_mousewheel)

    def setup_codes_section(self, parent):
        """Правая панель с кодами"""
        codes_container = ttk.LabelFrame(parent, text="Source Codes", padding=10)
        codes_container.pack(side=tk.RIGHT, fill=tk.BOTH, expand=True, padx=(5, 0))

        self.codes_info = ttk.Label(codes_container, text="Select a result to view codes", font=("", 10, "bold"))
        self.codes_info.pack(fill=tk.X, pady=(0, 10))

        codes_paned = ttk.PanedWindow(codes_container, orient=tk.HORIZONTAL)
        codes_paned.pack(fill=tk.BOTH, expand=True)

        # Левый код
        left_frame = ttk.LabelFrame(codes_paned, text="Code 1", padding=5)
        codes_paned.add(left_frame, weight=1)

        self.left_text = tk.Text(left_frame, wrap=tk.WORD, font=("Courier", 9), bg='#f5f5f5')
        left_scroll = ttk.Scrollbar(left_frame, orient="vertical", command=self.left_text.yview)
        self.left_text.configure(yscrollcommand=left_scroll.set)
        self.left_text.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        left_scroll.pack(side=tk.RIGHT, fill=tk.Y)

        # Правый код
        right_frame = ttk.LabelFrame(codes_paned, text="Code 2", padding=5)
        codes_paned.add(right_frame, weight=1)

        self.right_text = tk.Text(right_frame, wrap=tk.WORD, font=("Courier", 9), bg='#f5f5f5')
        right_scroll = ttk.Scrollbar(right_frame, orient="vertical", command=self.right_text.yview)
        self.right_text.configure(yscrollcommand=right_scroll.set)
        self.right_text.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        right_scroll.pack(side=tk.RIGHT, fill=tk.Y)

        self.left_text.config(state=tk.DISABLED)
        self.right_text.config(state=tk.DISABLED)

    def setup_status_bar(self, parent):
        """Статус бар"""
        self.status_var = tk.StringVar(value="Ready")
        status_bar = ttk.Label(parent, textvariable=self.status_var, relief=tk.SUNKEN)
        status_bar.pack(side=tk.BOTTOM, fill=tk.X, pady=(10, 0))

    def on_frame_configure(self, event):
        """Обновление области прокрутки при изменении размера фрейма"""
        self.canvas.configure(scrollregion=self.canvas.bbox("all"))

    def on_canvas_configure(self, event):
        """Обновление ширины внутреннего фрейма при изменении размера канваса"""
        self.canvas.itemconfig(self.canvas_window, width=event.width)

    def on_mousewheel(self, event):
        """Прокрутка колесиком мыши"""
        # Плавная прокрутка с правильным направлением
        self.canvas.yview_scroll(int(-1 * (event.delta / 60)), "units")

    def load_initial_data(self):
        """Загрузка начальных данных"""
        if not self.db.connect_db():
            messagebox.showerror("Error", "Cannot connect to database")
            return

        contests = self.db.get_all_contests()
        contest_values = [f"{c.id}: {c.name}" for c in contests]
        self.contest_combo['values'] = contest_values

        sizes = self.db.get_subgraph_sizes()
        self.size_combo['values'] = sizes

        self.status_var.set(f"Loaded {len(contests)} contests and {len(sizes)} subgraph sizes")

    def on_contest_selected(self, event):
        """Обработчик выбора контеста"""
        contest_str = self.contest_var.get()
        if not contest_str:
            return

        contest_id = int(contest_str.split(':')[0])
        problem_codes = self.db.get_problem_codes_by_contest(contest_id)
        self.problem_combo['values'] = problem_codes
        self.problem_combo.set('')

        self.status_var.set(f"Loaded {len(problem_codes)} problems for contest {contest_id}")

    def clear_all(self):
        """Очистка всех данных"""
        for widget in self.results_inner_frame.winfo_children():
            widget.destroy()

        self.clear_codes()
        self.last_selected_button = None  # Очищаем ссылку на кнопку
        self.current_offset = 0
        self.current_filters = None
        self.load_more_button = None
        self.status_var.set("All cleared")

    def clear_codes(self):
        """Очистка панели с кодами"""
        self.codes_info.config(text="Select a result to view codes")

        self.left_text.config(state=tk.NORMAL)
        self.right_text.config(state=tk.NORMAL)
        self.left_text.delete(1.0, tk.END)
        self.right_text.delete(1.0, tk.END)
        self.left_text.config(state=tk.DISABLED)
        self.right_text.config(state=tk.DISABLED)

    def replace_tabs(self, text):
        """Замена табов на 2 пробела"""
        return text.replace('\t', '  ')

    def show_codes(self, button, sub1, sub2, code1, code2, team1, team2, final_result):
        """Показать коды программ с выделением кнопки"""
        # Сбрасываем стиль предыдущей кнопки, если она все еще существует
        if self.last_selected_button:
            try:
                # Проверяем, существует ли виджет и не был ли он уничтожен
                if self.last_selected_button.winfo_exists():
                    self.last_selected_button.config(style="TButton")
            except (tk.TclError, AttributeError):
                # Виджет уже уничтожен или не существует
                pass

        # Устанавливаем новый стиль для текущей кнопки
        if button.winfo_exists():
            button.config(style="Accent.TButton")
            self.last_selected_button = button
        else:
            self.last_selected_button = None
            return

        # Обновляем информацию
        info_text = f"{team1}:{sub1}.cpp vs {team2}:{sub2}.cpp - Final: {final_result:.4f}"
        self.codes_info.config(text=info_text)

        # Очищаем и заполняем коды
        self.left_text.config(state=tk.NORMAL)
        self.right_text.config(state=tk.NORMAL)

        self.left_text.delete(1.0, tk.END)
        self.right_text.delete(1.0, tk.END)

        self.left_text.insert(tk.END, self.replace_tabs(code1))
        self.right_text.insert(tk.END, self.replace_tabs(code2))

        self.left_text.config(state=tk.DISABLED)
        self.right_text.config(state=tk.DISABLED)

        # Прокручиваем к началу
        self.left_text.see(1.0)
        self.right_text.see(1.0)

    def show_results(self, load_more=False):
        """Показать результаты по фильтрам с пагинацией"""
        if not load_more and not all([self.contest_var.get(), self.problem_var.get(), self.size_var.get()]):
            messagebox.showwarning("Warning", "Please select all filters")
            return

        try:
            contest_id = int(self.contest_var.get().split(':')[0])
            problem_code = self.problem_var.get()
            subgraph_size = int(self.size_var.get())

            # Сохраняем текущие фильтры для пагинации
            if not load_more:
                self.current_filters = (contest_id, problem_code, subgraph_size)
                self.current_offset = 0
                # Очищаем предыдущие результаты
                for widget in self.results_inner_frame.winfo_children():
                    widget.destroy()
                self.load_more_button = None

            # Используем пагинированный запрос
            results = self.db.get_final_results_by_filters(
                contest_id, problem_code, subgraph_size,
                self.results_limit, self.current_offset
            )

            if not results:
                if not load_more:
                    self.status_var.set(f"No results found for problem {problem_code}, size {subgraph_size}")
                else:
                    self.status_var.set("No more results to load")
                return

            # Создаем стиль для выделенной кнопки
            style = ttk.Style()
            style.configure("Accent.TButton", background="#4CAF50", foreground="white")

            # Добавляем результаты в интерфейс
            start_index = len(self.current_results) if load_more else 0
            for i, row in enumerate(results):
                sub1, sub2, team1, team2, size, result1, result2, code1, code2, final_result = row

                # Фрейм для одного результата
                result_frame = ttk.Frame(self.results_inner_frame, relief="solid", borderwidth=1)
                result_frame.pack(fill=tk.X, pady=2, padx=2)

                # Основной контейнер
                main_container = ttk.Frame(result_frame)
                main_container.pack(fill=tk.X, padx=5, pady=5)

                # Левая часть - текстовые метки
                text_frame = ttk.Frame(main_container)
                text_frame.pack(side=tk.LEFT, fill=tk.X, expand=True)

                ttk.Label(text_frame, text=f"{sub1}.cpp & {sub2}.cpp: {result1:.4f}",
                          font=("Courier", 9)).pack(anchor=tk.W)
                ttk.Label(text_frame, text=f"{sub2}.cpp & {sub1}.cpp: {result2:.4f}",
                          font=("Courier", 9)).pack(anchor=tk.W)
                ttk.Label(text_frame, text=f"Final result: {final_result:.4f}",
                          font=("Courier", 9, "bold"), foreground="blue").pack(anchor=tk.W)

                # Правая часть - кнопка
                button_frame = ttk.Frame(main_container)
                button_frame.pack(side=tk.RIGHT, padx=(10, 0))

                # Создаем кнопку с передачей кодов
                button = ttk.Button(
                    button_frame,
                    text="View Codes",
                    command=lambda b=None, s1=sub1, s2=sub2, t1=team1, t2=team2,
                        c1=code1, c2=code2, r1=result1, r2=result2, fr=final_result:
                    self.show_codes(b if b else button, s1, s2, c1, c2, t1, t2, fr)
                )
                button.pack()

            # Обновляем offset для следующей загрузки
            self.current_offset += len(results)

            # Удаляем старую кнопку "Load More" если есть
            if self.load_more_button:
                self.load_more_button.destroy()

            # Добавляем кнопку "Load More" если есть еще результаты
            if len(results) == self.results_limit:
                self.add_load_more_button()

            total_loaded = self.current_offset
            self.status_var.set(f"Loaded {total_loaded} results for problem {problem_code}, size {subgraph_size}")

        except Exception as e:
            messagebox.showerror("Error", f"Cannot load results: {e}")
            self.status_var.set("Error loading results")

    def toggle_fullscreen(self):
        """Переключение полноэкранного режима"""
        self.root.attributes('-fullscreen', not self.root.attributes('-fullscreen'))

    def add_load_more_button(self):
        """Добавить кнопку для загрузки дополнительных результатов"""
        load_more_frame = ttk.Frame(self.results_inner_frame)
        load_more_frame.pack(fill=tk.X, pady=10)

        self.load_more_button = ttk.Button(
            load_more_frame,
            text="Load More Results",
            command=self.load_more_results,
            style="Accent.TButton"
        )
        self.load_more_button.pack(pady=5)

    def load_more_results(self):
        """Загрузить следующие результаты"""
        if self.current_filters:
            self.show_results(load_more=True)


def main():
    root = tk.Tk()
    app = PlagiarismViewer(root)
    root.mainloop()


if __name__ == "__main__":
    main()