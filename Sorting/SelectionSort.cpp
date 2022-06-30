#include <iostream>

using namespace std;

//In the each iteration it gives the smallest element in the array
void SelectionSort(int A[], int n)
{
   for(int i=0;i<n-1;i++)
   {
    int j,k;
        for( j=i,k=i;j<n;j++)
        {
            if(A[j] < A[k]) // If the value is small, stores the index
                k = j;
        }
        swap(A[i],A[k]);    // Then swaps the value of the index with the smallest element
   }
}

void Display(int A[],int n)
{
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
}

int main(){

    int A[] = {8,7,4,2,3};
    SelectionSort(A,5);
    Display(A,5);
    
    
    
    return 0;
} 