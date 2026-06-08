#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int get_bet(int fails) {
    switch (fails) {
        case 0:
            return 8;
        case 1:
            return 24;
        case 2:
            return 64;
    }
}

int main() {
    int money = 210;
    int fails = 0;
    int wins  = 0;

    while (true) {
        int bet = fails == 3 ? money : get_bet(fails);
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

        //cout << "money: " << money << '\n';
        if (money >= 1000)
            return 0;
    }

    return 0;
}
