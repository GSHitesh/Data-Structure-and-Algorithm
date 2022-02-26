#include <iostream>

using namespace std;

//To find the first missing value in an array
void missingElement(int A[], int n)
{
    int l = A[0];
    int h = A[n-1];
    int diff = l -0;
    for (int  i = 0; i < n; i++)
    {
        if ((A[i]-i)!= diff)
        {
            cout <<"Missing Element is: " << diff + i << endl;
            break;
        }
        
    }
    
}

// To find the more than two missing elements in an array
void TwoMissingElement(int A[], int n)
{
    int l = A[0];
    int h = A[n-1];
    int diff = l -0;
    for (int  i = 0; i < n; i++)
    {
        if ((A[i]-i)!= diff)
        {
            while (diff < (A[i] -i))
            {
                cout <<"Missing Element is: " << diff + i << endl;
                diff++;
            }
            
            
        }
        
    }
    
}

// Alternative method to find the more than two missing elements in an array
void AlternativeTwoMissingElement(int A[], int n)
{
    int l = A[0];
    int h = A[n-1];
    int H[h] = {0}; // Should be the size of the largest element in an array
    
    for (int  i = 0; i < n; i++)
    {
       H[A[i]]++;          
               
    }
    // This is HashMap Technique using 0 and 1
    for (int  i = 1; i <=h; i++)    //Natural Numbers starts from 1
    {
       if(H[i] == 0)
       {
           cout << "Missing Elements: " << i << endl;
       }         
               
    }
    
}

int main(){

    int A [] = {6,7,8,10,11,12,13,16,17};
    // missingElement(A,7);
    // TwoMissingElement(A,9);
    AlternativeTwoMissingElement(A,9);
    return 0;
}