#include <iostream>
using namespace std;

int main() {
    int sum = 210;
    int result;
    while (sum < 1000) {
        cout << 10 << " R\n";
        cout << std::flush;
        cin >> result;
        if (result == -1) return 0;
        if (result == 1) {
            sum += 10;
            continue;
        }
        sum -= 10;
        cout << 20 << " R\n";
        cout << std::flush;
        cin >> result;
        if (result == -1) return 0;
        if (result == 1) {
            sum += 20;
            continue;
        }
        sum -= 20;

        cout << 40 << " R\n";
        cout << std::flush;
        cin >> result;
        if (result == -1) return 0;
        if (result == 1) {
            sum += 40;
            continue;
        }
        sum -= 40;

        cout << sum << " R\n";
        cout << std::flush;
        cin >> result;
        if (result == -1) return 0;
        if (result == 1) {
            sum += sum;
            continue;
        }
        sum -= sum; // :(
    }
}
