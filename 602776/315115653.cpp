#include <iostream>
using namespace std;

int main() {
    int c = 0;
    int sum = 210;
    int result;
    while (c == 0 && sum < 1000) {
        cout << 10 << " R" << std::endl;
        cin >> result;
        if (result == -1) return 0;
        if (result == 1) {
            sum += 10;
            continue;
        }
        sum -= 10;
        cout << 20 << " R" << std::endl;
        cin >> result;
        if (result == -1) return 0;
        if (result == 1) {
            sum += 20;
            continue;
        }
        sum -= 20;

        cout << 40 << " R" << std::endl;
        cin >> result;
        if (result == -1) return 0;
        if (result == 1) {
            sum += 40;
            continue;
        }
        sum -= 40;

        cout << sum << " R" << std::endl;
        cin >> result;
        if (result == -1) return 0;
        if (result == 1) {
            sum += sum;
            continue;
        }
        sum -= sum; // :(
    }
}
