/*
Задача 1. Длина окружности

Входной файл стандартный ввод / input.txt
Выходной файл стандартный вывод / output.txt
Ограничение времени (сек/тест) 1

Примечание
Данная задача является учебной для ознакомления с правилами оформления задач и
системой тестирования. Решение данной задачи не учитывается.

Условие задачи
Вам необходимо посчитать длину окружности радиуса R.

Входные данные
Во входного файла записано единственное целое число R – радиус окружности, длину
которой вам необходимо посчитать.

Выходные данные
В выходной файл требуется вывести одно вещественное число L – длину окружности
радиуса R.
Абсолютная погрешность ответа не должна превышать 10^–6.

+-----------------------+------------------------+
| Пример входного файла | Пример выходного файла |
| (stdin / input.txt)   | (stdout / output.txt)  |
+-----------------------+------------------------+
| 1                     | 6.283185               |
+-----------------------+------------------------+
*/

/*
1000000000
*/
import java.util.Scanner;

public class Main {
    private static double a, b, p, c, d, q;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextDouble();
        b = scanner.nextDouble();
        p = scanner.nextDouble();
        c = scanner.nextDouble();
        d = scanner.nextDouble();
        q = scanner.nextDouble();

        if (isContradiction()) {
            System.out.println("Contradiction");
        } else if (isAmbiguity()) {
            System.out.println("Ambiguity");
        } else {
            double y = (a * q - c * p) / (a * d - c * b);
            double x = (p - b * y) / a;

            if (x <= 0 || y <= 0) {
                System.out.println("Not positive");
            } else {
                System.out.println("Success");
                System.out.printf("%f %f%n", x * 100, y * 100);
            }
        }
    }

    private static boolean isAmbiguity() {
        return a == c && b == d && p == q;
    }

    private static boolean isContradiction() {
        return a == c && b == d && p != q;
    }

}