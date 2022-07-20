#include <iostream>

using namespace std;

int Partition(int A[],int l, int h)
{
    int i = l;
    int pivot = A[l];
    int j = h;
    do{
    do
    {
        i++;
    } while (pivot >= A[i]); // stops if the A[i] is greater than pivot

    do
    {
        j--;
    } while (pivot < A[j]); // stops if the A[j] is smaller than pivot to swap

    if(i<j) swap(A[i],A[j]);    // swaping the smaller element with the greater element

    }while (i<j); 

    swap(A[l],A[j]);    // swaping the pivot/first element of the array with jth element

    

    return j;   // returning the index for partitioning

    
    
}

void QuickSort(int A[], int l,int h)
{
    int j;
  if (l<h)
  {
    j = Partition(A,l,h);
    QuickSort(A,l,j);
    QuickSort(A,j+1,h);
    
  }
  
}

void Display(int A[],int n)
{
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
}

int main(){

    int A[] = {8,7,4,2,1,2,67,34,3,2};
    QuickSort(A,0,10);
    Display(A,10);
    
    
    
    return 0;
} 