#include <iostream>

using namespace std;
    
    int power(int n,int m)
    {
        if(m==0)
            return 1;
        return power(n,m-1)*n;
    }
    
    
    
    int pow(int n, int m)
    {
        if(m==0)
            return 1;
        if(m%2 == 0)
            return pow(n*n,m/2);
        else
            return n*pow(n*n,(m-1)/2);
    }

    int main() {
    cout << power(4,4) << endl;
    cout << pow(4,4) << endl;
    return 0;
    }
