#include <iostream>

using namespace std;

void InsertionSort(int A[], int n)
{
   for(int i=1;i<n;i++)
   {
       int j=i-1;
       int x = A[i];    // we can keep it A[i] also
       while (j>=0 && A[j] > x) // Checks the elements left side of the main element if its greater then stores the value.
       {
        A[j+1] = A[j];
        // swap(A[j],A[j+1]);  // Swap operation can also be used
        j--;
       }

        A[j+1] = x; // when while loop ends it stores the temp (x) value in that index + 1
        
   }
}

void Display(int A[],int n)
{
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
}

int main(){

    int A[] = {1,2,7,4,2,3};
    InsertionSort(A,6);
    Display(A,6);
    
    
    
    return 0;
} 