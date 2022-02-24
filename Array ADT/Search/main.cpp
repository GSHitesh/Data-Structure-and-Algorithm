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

void reverse(struct array *arr){
    int i,j;
    for( i = 0, j =arr->length-1;i<j;i++,j--){
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

void Insert(struct array *arr,int key)
{
    int i = arr->length-1;
    while(arr->A[i] > key)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }

      arr->A[i+1] = key;
      arr->length++;
}

void swap(int *x,int *y)
 {
 int temp=*x;
 *x=*y;
 *y=temp;
 }

void Rearrange( struct array *arr)
{

    int i =0;
    int j = arr->length-1;
    while(i<j){
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;

    if(i<j)swap(&arr->A[i],&arr->A[j]);
        }
}


void display(struct array arr)
{
    for(int i=0;i<arr.length;i++)
        cout << arr.A[i] << " ";
    cout << endl;

}
int main()
{
//    struct array arr = {{1,2,3,4,5},10,5};

//    display(arr);
//
//    cout << "Binary Search: " << Binary_search(arr,3) << endl;
//    cout << "Recursive Binary Search: " << Rbinary_search(arr.A,0,arr.length,12) << endl;



//    cout << "Linear Search: " << linear_search(&arr,13) << endl;
//
//    display(arr);

struct array arr = {{10,-20,25,-34,50},10,5};


//    reverse(&arr);
//    cout << "Reversed Array: ";
//    display(arr);

//    Insert(&arr,30);
//    cout << "Insertion in Sorted Array: ";
//    display(arr);

    Rearrange(&arr);
    cout << "Rearranged Array: ";
    display(arr);

    return 0;
}
