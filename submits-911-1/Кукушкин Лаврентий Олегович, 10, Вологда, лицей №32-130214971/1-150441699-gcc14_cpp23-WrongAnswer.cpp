#include <iostream>

using namespace std;

int main()
{
    long long h1,m1,h2,m2,k=0,h12,m12,m123,h13;
    cin >> h1 >> m1 >> h2 >> m2;
    h12=h1;
    m12=m1;
    m123=m1;
    h13=h1;
    if(h1==h2)
    {
        for(int e=m1; e<=m2; e++)
        {
            if ((h12==m12)||(h12==(m12%10)*10+m12/10)||(h12/10+m12%10==h12%10+m12/10))
            {
                k++;
            }
            m12++;
        }
    }
    else
    {
        for(int g=m1; g<60; g++)
        {
            if ((h1==m123)||(h1==(m123%10)*10+m123/10)||(h1/10+m123%10==h1%10+m123/10))
            {
                k++;
            }
            m123++;
        }
        for (int i=h1+1; i<h2; i++)
        {
            for(int p=0; p<60; p++)
            {
                if ((h13==p)||(h13==(p%10)*10+p/10)||(h13/10+p%10==h13%10+p/10))
                {
                    k++;
                }
            }
            h13++;
        }
        for(int y=0; y<=m2; y++)
        {
            if ((h2==y)||(h2==(y%10)*10+y/10)||(h2/10+y%10==h2%10+y/10))
            {
                k++;
            }
        }
    }
    cout << k << endl;
    return 0;
}
