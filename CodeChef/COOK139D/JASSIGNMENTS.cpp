#include <iostream>
using namespace std;

int main() {
	int n,x;
	cin>>n;
	while(n--){
	    cin>>x;
	    if(x+3 <= 10)
	        cout << "Yes" << endl;
	   else
	        cout << "No" << endl;
	}
	return 0;
}
