#include <iostream>
#include <vector>

using namespace std;

int maxElement(vector<int> &A,int n){
    int maxi = INT_MIN;
    for(int i: A){
        maxi = max(maxi,i);
    }

    return maxi;

}

void CountSort(vector<int> &A, int n)
{
    int maxi = maxElement(A,n);
    vector<int> B(maxi+1,0);

    for(int i=0;i<n;i++){
        B[A[i]]++;
    }

    int i=0;
    int j=0;
    while(j < maxi+1){  // i is used for updating A[] and j is for iteration
        if(B[j] > 0){
            A[i++] = j;
            B[j]--; // how many times number appearing which is index
        }
        else
            j++;
    }
  
}

void Display(vector<int> &A,int n)
{
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
}

int main(){

    vector<int> A {8,7,4,2,1,2,67,34,3,2};
    Display(A,10);
    CountSort(A,10);
    cout << endl;
    Display(A,10);
    
    
    
    return 0;
} 