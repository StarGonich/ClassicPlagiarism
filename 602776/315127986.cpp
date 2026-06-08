#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int get_bet(int fails, int money) {
    switch (fails) {
        case 0:
            return 0.04 * money;
        case 1:
            return 0.08 * money;
        case 2:
            return 0.24 * money;
        case 3:
            return money;
    }
}

int main() {
    int money = 210;
    int fails = 0;
    int wins  = 0;
    int k = 0;

    while (true) {
        int bet = get_bet(fails, money);
        cout << bet << " R" << endl;
        cout.flush();

        int res;
        cin >> res;
        switch (res) {
        case -1:
            return 0;
            break;
        case 0:
            money -= bet;
            ++fails;
            wins = 0;
            break;
        case 1:
            money += bet;
            ++wins;
            fails = 0;
            break;
        }

        if (++k == 100) {
            return 0;
        }

        /*cout << "money: " << money << endl;
        cout << "round: " << k << endl;*/
        if (money >= 1000)
            return 0;
    }

    return 0;
}
