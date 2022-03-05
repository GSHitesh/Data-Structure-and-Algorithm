#include <iostream>
using namespace std;

int main() {
	int n,x,y,i=0,j=0;
	std::cin >> n;
	while(n--){
	    cin >>x>>y;
	    for(int i=0;i<y;i++){
	        if(i%2 ==0)
	            x++;
	       else 
	            x--;
	            
	    }
	    if(x%2 == 0)
	        cout << "Janmansh" << endl;
	   else
	        cout << "Jay" << endl;
	}
	return 0;
}
