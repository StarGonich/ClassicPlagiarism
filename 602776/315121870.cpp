#include <iostream>

using namespace std;

main(){
    int n, cnt=0;
    bool arr[3];
    cin >> n;
    for (int i=4; i<=n; i++)
        if ((i % 4 == 0) + (i % 5 == 0) + (i % 6 == 0) == 1)
            cnt += 1;
    cout << cnt;
    return 0;
}
