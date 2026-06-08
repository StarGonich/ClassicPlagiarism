#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long MOD = 1000000007;

vector<vector<long long> > mul44(vector<vector<long long> > A, vector<vector<long long> > B){
    vector<vector<long long> > C(4, vector<long long>(4, 0));
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            long long s = 0;
            for(int k = 0; k < 4; ++k){
                s = (s + A[i][k]*B[k][j]) % MOD;
            }
            C[i][j] = s;
        }
    }
    return C;
}

vector<vector<long long> > mul14(vector<vector<long long> > A, vector<vector<long long> > B){
    vector<vector<long long> > C(1, vector<long long>(4, 0));
    for(int i = 0; i < 1; ++i){
        for(int j = 0; j < 4; ++j){
            long long s = 0;
            for(int k = 0; k < 4; ++k){
                s = (s + A[i][k]*B[k][j]) % MOD;
            }
            C[i][j] = s;
        }
    }
    return C;
}

vector<vector<long long> > Mpow(vector<vector<long long> > A, int k){
    if(k == 1){
        return A;
    }else{
        if(k % 2 == 0){
            vector<vector<long long> > B = Mpow(A, k/2);
            return mul44(B, B);
        }else{
            return mul44(A, Mpow(A, k-1));
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<long long> > X(4, vector<long long>(4, 0));
    X[0][0] = 1;
    X[0][1] = 1;
    X[0][2] = 0;
    X[0][3] = 0;

    X[1][0] = 1;
    X[1][1] = 0;
    X[1][2] = 0;
    X[1][3] = 0;

    X[2][0] = 0;
    X[2][1] = 0;
    X[2][2] = 1;
    X[2][3] = 1;

    X[3][0] = 1;
    X[3][1] = 0;
    X[3][2] = 1;
    X[3][3] = 0;


    vector<vector<long long> > ANS(1, vector<long long>(4, 0));
    ANS[0][0] = 0;
    ANS[0][1] = 0;
    ANS[0][2] = 1;
    ANS[0][3] = 1;
    if(n == 1){
        cout << 1;
        return 0;
    }else{
        ANS = mul14(ANS, Mpow(X, n-1));
        cout << ANS[0][0];
    }
    return 0;
}
