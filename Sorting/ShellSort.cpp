#include <iostream>

using namespace std;

void ShellSort(int A[], int n)
{
    int temp;
   for(int gap=n/2;gap>1;gap /=2)
    {    
        for(int i=gap;i<n;i++)
        {
            int j = i-gap;  // 0 1 2 3...
            temp = A[i];    // A[5] A[6]...
            while (j>=0 && A[j] > temp)
            {
                A[j+gap]=A[j];
                j = j-gap;  // to check previous values if greater then swap
            }
            A[j+gap] = temp;
            
        }
   }
}

void Display(int A[],int n)
{
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
}

int main(){

    int A[] = {8,7,4,2,1,2,67,34,3,2};
    Display(A,10);
    ShellSort(A,10);
    cout << endl;
    Display(A,10);
    
    
    
    return 0;
} 