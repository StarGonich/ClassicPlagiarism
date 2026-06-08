#include <bits/stdc++.h)

bool check(int time) {
    int h = time / 60;
    int m = time % 60;

    return (
        h == m ||
        h == (m%10*10 + m/10) ||
        (
           (h/10 + 1) == h%10 &&
           (h%10 + 1) == m/10 &&
           (m/10 + 1) == m%10 
        )
    );
}

int main() {
    int h1,m1,h2,m2;
    std::cin >> h1 >> m1 >> h2 >> m2;
    int time1 = h1*60 + m1;
    int time2 = h2*60 + m2;
    unsigned int result = 0;
    while (time1 != time2){
        if (check(time1))
            ++result;
        ++time1;
        if (time1 == 24*60)
            time1 = 0;
    }
    if (check(time2))
        ++result;
	std::cout << result << std::endl;
    return 0;
}