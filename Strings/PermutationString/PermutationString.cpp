#include <iostream>

using namespace std;

void perString(string S, int l,int h){

    if(l == h)
        cout << S << " ";
    else{
        for(int i =l;i<=h;i++){
            swap(S[l],S[i]);
            perString(S,l+1,h);
            swap(S[l],S[i]);
        }
    }
}

int main(){

    // Works for only distinct letter in a String
    string s = "abc";
    perString(s,0,2);
    return 0;
}