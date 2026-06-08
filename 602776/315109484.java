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
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    private static class Node {
        boolean visited = false;
        List<Node> children = new ArrayList<>();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
        }
        int[] d = new int[n];
        for (int i = 0; i < n; i++) {
            d[i] = scanner.nextInt();
        }
        int k = scanner.nextInt();

        Node[] graph = new Node[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new Node();
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = Math.abs(x[i] - x[j]);
                if (dist <= d[i]) {
                    graph[i].children.add(graph[j]);
                }
                if (dist <= d[j]) {
                    graph[j].children.add(graph[i]);
                }
            }
        }
        dfs(graph[k - 1]);
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (graph[i].visited) {
                result++;
            }
        }
        System.out.println(result);
    }

    private static void dfs(Node curr) {
        if (curr.visited) {
            return;
        }
        curr.visited = true;
        for (Node node : curr.children) {
            dfs(node);
        }
    }

}