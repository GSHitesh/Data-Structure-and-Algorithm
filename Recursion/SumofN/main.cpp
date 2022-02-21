#include <iostream>

using namespace std;
    int i = 1;
    int sum(int n)
    {
        if(n==0)
            return 0;
        else
            return sum(n-1) + n;
    }
    
    int sum2(int n)
    {
        return n*(n+1)/2;
    }

    int main() {
    cout << sum(4) << " " << sum2(4);
    cout << endl;
    return 0;
    }
