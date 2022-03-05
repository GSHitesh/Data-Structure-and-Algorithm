#include <iostream>
using namespace std;

int main() {
	int t,x,a,b,c;
	std::cin >> t;
	while(t--){
	    cin >>x>>a>>b>>c;
	    if(a<=b && a<=c){
	        if(b<=c)
	            cout << (x-1)*a + b << endl;
	       else 
	            cout << (x-1)*a +c << endl;
	    }
	    else if(b<=a && b<=c){
	        if(a<=c)
	            cout << (x-1)*b + a << endl;
	       else 
	            cout << (x-1)*b +c << endl;
	    }
	    else{
	        if(a<=b)
	            cout << (x-1)*c + a << endl;
	       else 
	            cout << (x-1)*c +b << endl;
	    }
	}
	return 0;
}
