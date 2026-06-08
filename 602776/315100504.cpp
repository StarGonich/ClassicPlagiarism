#include<bits/stdc++.h>

using namespace std;

double eps =  0.00000001;
int main()
{
    double A, B, P, C, D, Q;
    cin >> A >>  B >> P >> C >> D >> Q;

    double d = (A * D - B * C) / (100*100);
    double dx = P * (D/100.0)  - (B/100.0 * Q);
    double dy = (A/100.0) * (Q)  - (P*C/100.0);
    
    if(abs(d) < eps && abs(dx) < eps && abs(dy) < eps)
        cout << "Ambiguity";
    else
    if(abs(d) < eps)
        cout << "Contradiction";
    else
    {
        double x = dx / d;
        double y = dy / d;
        if(dx < eps || dy < 0)
            cout << "Not positive";
        else{
            cout << "Success\n";
            cout.precision(9);
            cout << fixed << x << " " << y;
        }
        
    }   
    
    return 0;
}