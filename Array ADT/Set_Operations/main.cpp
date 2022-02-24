#include <iostream>

using namespace std;
class Array{
    private:
int *A;
int size;
int length;
    public:

        Array(){
        size = 15;
        length = 0;
        A = new int[size];
        }

        Array(int sz){
        size = sz;
        length = 0;
        A = new int[sz];
        }

        void display()
{
    for(int i=0;i<length;i++)
        cout << A[i] << " ";
    cout << endl;

}



Array Union(Array &arr2){

    int i=0,j=0,k=0;
    Array arr3;
    while(i<length && j < arr2.length)
    {
        if(A[i]<arr2.A[j])      //Array1 element is smaller
            arr3.A[k++] = A[i++];
        else if(A[i]>arr2.A[j])     //Array2 element is smaller
            arr3.A[k++] = arr2.A[j++];
        else
            {   //Array1 and Array2 element is same
                arr3.A[k++] = arr2.A[i++];
                j++;
            }



    }

    for(;i<length;i++)
        arr3.A[k++]=A[i];
    for(;j<arr2.length;j++)
        arr3.A[k++]=arr2.A[j];

//        while(i<length)
//            arr3.A[k++] = A[i++];
//        while(j<arr2.length)
//            arr3.A[k++] = arr2.A[j++];

        arr3.length = k;

        return arr3;
}

void Insert(){

    cout<< "Enter the Number of Elements: ";
    cin >> length;
    for(int i =0;i <length;i++)
    {
        cout << "Enter element" << i+1 <<": ";
        cin >> A[i];
    }

}

Array Difference(Array &arr2){

    int i=0,j=0,k=0;
    Array arr3 (length + arr2.length);
    while(i<length && j < arr2.length)
    {
        if(A[i]<arr2.A[j])
            arr3.A[k++] = A[i++];
        else if(A[i]>arr2.A[j])
            j++;
        else
        {
            i++;j++;
        }

    }
        while(i<length)
            arr3.A[k++] = A[i++];

        arr3.length = k;

        return arr3;
}

Array Intersection(Array &arr2){

    int i=0,j=0,k=0;
    Array arr3 (length + arr2.length);
    while(i<length && j < arr2.length)
    {
        if(A[i]<arr2.A[j])
            i++;
        else if(A[i]>arr2.A[j])
            j++;
        else
            arr3.A[k++] = arr2.A[j++];

    }


        arr3.length = k;
        arr3.size = 15;

        return arr3;
}


};

int main()
{
    Array A,B,C;

    A.Insert();

    B.Insert();

    cout << endl;
    cout << "Union: ";
    C = A.Union(B);
    C.display();

    cout << endl;
    cout << "Intersection: ";
    C = A.Intersection(B);
    C.display();

    cout << endl;
    cout << "Difference: ";
    C = A.Difference(B);
    C.display();


    return 0;

}
