#include <iostream>

int main(){
    unsigned long long int n, i, j, k, s;
    std::cin >> n;
    s = 0;
    while (i <= n){
    if (i <= n){
        if ((i % 4 == 0) and (i % 5 != 0) and (i % 6 != 0)) s += 1;
        if ((i % 4 != 0) and (i % 5 == 0) and (i % 6 != 0)) s += 1;
        if ((i % 4 != 0) and (i % 5 != 0) and (i % 6 == 0)) s += 1;
    }
    if (j <= n){
        if ((j % 4 == 0) and (j % 5 != 0) and (j % 6 != 0)) s += 1;
        if ((j % 4 != 0) and (j % 5 == 0) and (j % 6 != 0)) s += 1;
        if ((j % 4 != 0) and (j % 5 != 0) and (j % 6 == 0)) s += 1;
    }
    if (k <= n){
        if ((k % 4 == 0) and (k % 5 != 0) and (k % 6 != 0)) s += 1;
        if ((k % 4 != 0) and (k % 5 == 0) and (k % 6 != 0)) s += 1;
        if ((k % 4 != 0) and (k % 5 != 0) and (k % 6 == 0)) s += 1;
    }
    i += 4;
    j += 5;
    k += 6;
    }
    std::cout << s;
}