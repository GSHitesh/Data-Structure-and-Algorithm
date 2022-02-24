#include <iostream>

using namespace std;
class array{
    private:
int *A;
int size;
int length;
void Swap(int *x,int *y)
 {
 int temp=*x;
 *x=*y;
 *y=temp;
 }
    public:
        array(){
        size = 10;
        length = 0;
        A = new int[size];
        }

        array(int sz){
        size = sz;
        length = 0;
        A = new int[sz];
        }

        int linear_search(int key){ // Transposition Technique
    for(int i =0;i<length;i++){
        if(A[i] == key){
            Swap(&A[i],&A[i-1]);
            return i-1;
        }
    }

    return -1;
}


int Rbinary_search(int A[], int l, int h,int key)
{
int mid = (l+h)/2;

    if(l<=h)
    {
        if(key == A[mid])
            return mid;
        else if(key < A[mid])
            return Rbinary_search(A,l,mid-1,key);
        else
            return Rbinary_search(A,mid+1,h,key);
    }

    return -1;

}


int Binary_search(int key)
{

    int l,h,mid;
    l=0;
    h = length -1;
    mid = (l+h)/2;
//    cout << Rbinary_search(arr.A,l,h,key);

    while(l<=h)
    {
        if(key == A[mid])
            return mid;
        else if(key < A[mid])
            h = mid-1;
        else
            l = mid + 1;
    }

    return -1;

}

void reverse(){
    int i,j;
    for( i = 0, j =length-1;i<j;i++,j--){
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

void Insert(int key)
{
    A[length++] = key;

}



void Rearrange( )
{

    int i =0;
    int j = length-1;
    while(i<j){
        while(A[i]<0)i++;
        while(A[i]>=0)j--;

    if(i<j)Swap(&A[i],&A[j]);
        }
}


void display()
{
    for(int i=0;i<length;i++)
        cout << A[i] << " ";
    cout << endl;

}



array Merge(array &arr2){

    int i=0,j=0,k=0;
    array arr3 (length + arr2.length);
    while(i<length && j < arr2.length)
    {
        if(A[i]<arr2.A[j])
            arr3.A[k++] = A[i++];
        else
            arr3.A[k++] = arr2.A[j++];

    }
    while(i<length)
            arr3.A[k++] = A[i++];
        while(j<arr2.length)
            arr3.A[k++] = arr2.A[j++];

        arr3.length = length + arr2.length;

        return arr3;
}

~array(){
    delete [] A;
//    cout << "Array Destroyed" <<endl;
}

};


int main()
{

    array A;

    int x;
    cout << "Enter the Elements of A: " ;
    for(int i =0;i<5;i++){
        cin >> x;
    A.Insert(x);
    }
//    A->display();
//    A->reverse();
//    A->display();


    array B,C;

    int y;
    cout << "Enter the Elements of B: " ;
    for(int i =0;i<5;i++){
        cin >> y;
    B.Insert(y);
    }


    C = A.Merge(B);
    cout << endl;
    C.display();




    return 0;
}
