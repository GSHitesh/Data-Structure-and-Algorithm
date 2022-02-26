#include <iostream>
#include<vector>

using namespace std;

int main(){

    //Program to find duplicates in an array

    vector <int> A {2,3,5,5,5,6,7,1,7,1,7};
    
    // int lastDuplicate = 0;

    // for(int i =0; i<A.size()-2;i++){
    //     if(A[i] == A[i+1])
    //     {
    //         if(lastDuplicate != A[i])
    //             cout << "Duplicate Element: " << A[i] << endl;
    //         lastDuplicate = A[i];
    //     }
    // }

//For Sorted Array
    for(int i =0; i<A.size()-1;i++){
            if(A[i] == A[i+1])
            {
                int j = i+1;
                while (A[j] == A[i])
                {
                    j++;
                }
                
                    cout << "Duplicate Element: " << A[i] << " " << j-i << endl;
                i = j - 1;
            }
        }

    // Hash Technique to solve
    int m = A.size();
    int n = A[m-1];
        vector <int> H (n+1);
        for(int j =0; j<m;j++){
            H[A[j]]++;
        }

        for(int k =0;k<=n;k++){
            if(H[k] > 1)
                cout << "Duplicate Element: " << k << " " << H[k];

            cout << endl;



        }

        


    
    return 0;
}