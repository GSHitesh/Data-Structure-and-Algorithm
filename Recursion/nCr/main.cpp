#include <iostream>

using namespace std;

    int nC(int n, int r)
    {
        if(r==0||r==n)
            return 1;
        else
            return nC(n-1,r-1) + nC(n-1,r);
    }
    
    int fact(int n);
    int C(int n, int r)
    {
        int t1 = fact(n);
        int t2 = fact(r);
        int t3 = fact(n-r);
        return t1/(t2*t3);
    }
    
    int fact(int n)
    {
        if(n<=1)
            return 1;
        return fact(n-1)*n;
    }
    int main() {
    cout << C(5,2) << endl;
    cout << nC(5,2) << endl;
    return 0;
    }
