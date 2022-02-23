#include <iostream>

using namespace std;

struct array{
int A[10];
int size;
int length;


};

int linear_search(struct array *arr,int key){ // Transposition Technique
    for(int i =0;i<arr->length;i++){
        if(arr->A[i] == key){
            swap(arr->A[i],arr->A[i-1]);
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


int Binary_search(struct array arr,int key)
{

    int l,h,mid;
    l=0;
    h = arr.length -1;
    mid = (l+h)/2;
//    cout << Rbinary_search(arr.A,l,h,key);

    while(l<=h)
    {
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            h = mid-1;
        else
            l = mid + 1;
    }

    return -1;

}







void display(struct array arr)
{
    for(int i=0;i<arr.length;i++)
        cout << arr.A[i] << " ";
    cout << endl;

}
int main()
{
    struct array arr = {{1,2,3,4,5},10,5};

    display(arr);

    cout << "Binary Search: " << Binary_search(arr,3) << endl;
    cout << "Recursive Binary Search: " << Rbinary_search(arr.A,0,arr.length,12) << endl;



//    cout << "Linear Search: " << linear_search(&arr,13) << endl;
//
//    display(arr);

    return 0;
}
