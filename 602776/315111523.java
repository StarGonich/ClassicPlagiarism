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
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    private static int result = 0;
    private static long[] x;
    private static long[] d;
    private static boolean[] boomed;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        x = new long[n];
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
        }
        d = new long[n];
        for (int i = 0; i < n; i++) {
            d[i] = scanner.nextInt();
        }
        boomed = new boolean[n];
        Arrays.fill(boomed, false);

        int k = scanner.nextInt();

        boom(k - 1);
        System.out.println(result);
    }

    private static void boom(int k) {
        if (boomed[k]) {
            return;
        }
        result++;
        boomed[k] = true;
        int i = k - 1;
        while (0 <= i && x[k] - x[i] <= d[k]) {
            boom(i);
            i--;
        }
        i = k + 1;
        while (i < x.length && x[i] - x[k] <= d[k]) {
            boom(i);
            i++;
        }
    }
}