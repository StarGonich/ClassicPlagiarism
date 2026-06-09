# Инструкция для Windows 64bit
### Предустановка необходимых программ
- Установка Joern 4.0.xxx версии, к примеру при тестах использовалась 4.0.426 [(скачать)](https://github.com/joernio/joern/releases/download/v4.0.426/joern-cli.zip). Добавьте папку .../joern-cli/bin в переменные среды PATH
- PyPy 3.11 [(скачать)](https://downloads.python.org/pypy/pypy3.11-v7.3.23-win64.zip), и также добавьте pypy3.11-v7.3.23-win64 в переменные среды PATH
- graphviz 12.2.1 [(скачать)](https://gitlab.com/api/v4/projects/4207231/packages/generic/graphviz-releases/12.2.1/windows_10_cmake_Release_graphviz-install-12.2.1-win64.exe), при установке поставьте галочку "Добавить в PATH"

### Создание виртуального окружения и импорт библиотек
Перед началом в сессии командной строки выполним команды, для корректного отображения кириллицы:
```
[Console]::InputEncoding = New-Object System.Text.UTF8Encoding
[Console]::OutputEncoding = New-Object System.Text.UTF8Encoding
```

1) Создание виртуального окружения
```sh
pypy3 -m venv .venv
```
2) Активация виртуального окружения
```sh
.\.venv\Scripts\activate
```
3) Установка основных библиотек
```
pip install -r requirements.txt
```
4) Установка библиотеки pygraphviz
```
pip install --config-settings="--global-option=build_ext"                  --config-settings="--global-option=-IC:\Program Files\Graphviz\include"                  --config-settings="--global-option=-LC:\Program Files\Graphviz\lib" pygraphviz==1.14
```

### Работа с файлами

Для примера будет работать с архивом `submits-911-2` и логом `log-911-2.xml`

1) Возьмём только полные решения и с теми языками, которые поддерживает Joern. Значения констант меняются в исходном файле
```
pypy3 PreDelete.py
```
2) Преобразуем исходные файлы в PDG графы. Папка с посылками указывается в качестве арумента командной строки
```
pypy3 files_to_graph.py submits-911-2_OK
```
3) Сравним решения попарно и занесём данные в БД. Значения констант меняются в исходном файле. Выберем номера задач (латиница для Codeforces и цифры для Яндекс Контест) для анализа.
```
pypy3 main.py
```
4) Визуализируем данные из БД.
```
pypy3 gui.py
```

