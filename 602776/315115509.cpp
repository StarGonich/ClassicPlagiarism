#include <iostream>

using namespace std;

int main() {
    int sum = 210;

    int fail = 0;
    int part = 0;
    while (true) {
        if (fail == 0) {
            part = sum / 15;
        }
        int bet = (fail < 3 ? part * (fail + 1) : sum);
        cout << bet << " R" << endl;
        int res;
        cin >> res;
        if (res == -1) {
            return 0;
        } else if (res == 0) {
            sum -= bet;
            fail++;
        } else {
            sum += bet;
            fail = 0;
        }
        if (sum >= 1000) {
            return 0;
        }
    }
}