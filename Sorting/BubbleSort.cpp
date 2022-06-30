#include <iostream>

using namespace std;

// int * BubbleSort(int A[], int n)
void BubbleSort(int A[], int n)
{
    for(int i=0;i<n-1;i++)  // if the first element is the largest, then its stored at the last index
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(A[j] > A[j+1])   // Comparing the consecutive elements
                swap(A[j],A[j+1]);
        }
    }
    // return A;
}

void Display(int A[],int n)
{
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
}

int main(){

    int A[] = {1,7,4,2,3};
    BubbleSort(A,5);
    Display(A,5);
    
    // int *C = BubbleSort(A,5);
    // Display(C,5);
    
    return 0;
} 