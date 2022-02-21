#include <iostream>

using namespace std;

    double taylor_series(int x,int n)
    {
        static double p=1,f=1;
        double r;
        if(n==0)
            return 1;
        r = taylor_series(x,n-1);
        p *= x;
        f *= n;
        return r + p/f;
    }
    
    double e(int x, int n)
    {
        double s=1,p=1,f=1;
        for(int i=1;i<=n;i++)
        {
            p *= x;
            f *= i;
            s += p/f;
        }
        return s;        
    }
    
    int main() {
    cout << taylor_series(1,10) << endl;
    cout << e(1,10) << endl;
    return 0;
    }
