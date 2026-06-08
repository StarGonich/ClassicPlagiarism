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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] perm = new int[n];
        for (int i = 0; i < n; i++) {
            perm[i] = scanner.nextInt();
        }

        int pos1 = -1, len1 = -1, pos2 = -1, len2 = -1;
        int k, p;

        k = perm[0] == 1 ? 0 : -1;
        while (0 <= k && k < n - 1 && perm[k] + 1 == perm[k + 1]) {
            k++;
        }
        p = perm[n - 1] == n ? n - 1 : n;
        while (0 < p && p < n && perm[p] - 1 == perm[p - 1]) {
            p--;
        }

        pos1 = k + 1;
        pos2 = k >= 0 ? find(perm, perm[k] + 1) : find(perm, 1);
        len1 = pos2 - pos1;
        len2 = p - pos2;
        if (pos1 >= pos2 || !isSorted(perm, pos1, len1) || !isSorted(perm, pos2, len2)) {
            System.out.println("-1");
        } else {
            System.out.printf("%d %d%n%d %d%n", pos1 + 1, len1, pos2 + 1, len2);
        }
    }

    static int find(int[] arr, int v) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == v) {
                return i;
            }
        }
        return -1;
    }

    static boolean isSorted(int[] arr, int start, int len) {
        for (int i = start + 1; i < start + len; i++) {
            if (arr[i - 1] != arr[i] - 1) {
                return false;
            }
        }
        return true;
    }
}