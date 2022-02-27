#include <iostream>
#include <vector>

using namespace std;

bool CheckAnagram(string word1,string word2){
    vector <int> H(128,0);   //Initializing all zeroes
    //128 for numbers and symbols 26 for only alphabets
    int n = word1.length();
    int m = word2.length();
    if(n==m){
        for(int i =0;i<n;i++){
            H[word1[i]-97]++;

        }

    }
    else
        return false;

    for(int i =0;i<m;i++){
            H[word1[i]-97]--;
            if(H[word1[i]-97]<0){
                return false;
                break;
            }

        }

    return true;

}

int main(){

    string word1 {"decimdal"};
    string word2 {"medicadl"};

    cout << CheckAnagram(word1,word2) << endl; // 1 
    cout << CheckAnagram("Hitesh123","123Hitesh") << endl; // 1
    cout << CheckAnagram("India124$%india","421%$indiandia") << endl; // 0
    

    return 0;
}