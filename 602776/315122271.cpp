#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {
    int money = 210;
    int fails = 0;

    while (true) {
        int bet = fails == 3 ? money : 1;
        cout << bet << " R" << endl;

        int res;
        cin >> res;
        switch (res) {
        case -1:
            return 0;
            break;
        case 0:
            money -= bet;
            ++fails;
            break;
        case 1:
            money += bet;
            fails = 0;
            break;
        }

        if (money >= 1000)
            return 0;
    }

    return 0;
}
