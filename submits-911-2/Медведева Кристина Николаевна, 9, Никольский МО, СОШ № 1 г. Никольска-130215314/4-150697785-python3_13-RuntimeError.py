# Код для оценки качества классификации по методу k-ближайших соседей
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score

# Загружаем датасет
iris = load_iris()
X = iris.data
y = iris.target

# Разделяем данные на обучающую и тестовую выборки
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Обучаем модель k-ближайших соседей с выбранным числом соседей
k = 3  # Можно изменить значение k
model = KNeighborsClassifier(n_neighbors=k)
model.fit(X_train, y_train)

# Предсказываем классы для тестовой выборки
y_pred = model.predict(X_test)

# Оцениваем точность классификации
accuracy = accuracy_score(y_test, y_pred)

print(f"Точность классификации при k={k}: {accuracy:.2f}")