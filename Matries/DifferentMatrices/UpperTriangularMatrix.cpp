#include <iostream>

using namespace std;

class LTMatrices
{
private:
    int n;    
    int arr[100];
    // int *arr;
public:
    LTMatrices(int n);
    ~LTMatrices();

//  Upper Triangular Matrix
    void ColMajor_setA( int j, int i, int x){    // Row Major formula
        if(i >= j )
            arr[((i-1)/2) + j-1] = x;        //Index formula for Upper Triangular Matrix
        else
           arr[((i-1)/2) + j-1] = 0;
            
            
    }

    int ColMajor_getA(int j, int i ){
        if(i >= j )           
            return arr[((i-1)/2) + j-1];
        return 0;
    }

    void RowMajor_setA( int j, int i, int x){    // Row Major formula
        if(i >= j ){
            int index = (n * (j-1) - (((j-2) * (j-1))/2)) + (i-j);
            arr[index] = x;
        }     //Index formula for Upper Triangular Matrix
        
    }

    int RowMajor_getA(int j, int i){
        if(i >=j ){
            int index = (n * (j-1) - (((j-2) * (j-1))/2)) + (i-j);
            return index;
        }
        return 0;
    }


    void display(bool row){     // Interchanging i <-> j to reverse the variables in the formula
        for(int j=1;j<=n;j++){   // Starting from 1 otherwise index will be -ve value on (0,0)
            for(int i=1;i<=n;i++){
                if(i>=j){
                    if(!row)
                        cout << arr[((i-1)/2) + j-1] <<" ";
                    else{
                        int index = n * (j-1) - (((j-2) * (j-1))/2) + (i-j);
                        cout << arr[index] << " ";                    
                    }
                }
                else    
                    cout << "0" << " ";
            }
            cout << endl;
        }
    }
    
};

LTMatrices::LTMatrices(int n)
{
    this->n = n;
    // arr = new int[n*(n+1)/2];
    arr[(n*(n+1))/2]; // Initializing the size
}

LTMatrices::~LTMatrices()
{
    delete [] arr;
}



int main(){

    cout << "Enter the dimesions for the matrix: ";
    int n,x;
    cin >> n;
    LTMatrices Lr(n),Lc(n);
    cout << "Enter all the elements: ";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> x;
            Lr.RowMajor_setA(i,j,x);
        }
    }

    cout << endl;
    Lr.display(true);

    //======================COL MAJOR NOT WORKING===========

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cin >> x;
    //         Lc.ColMajor_setA(i,j,x);
    //     }

    // }

    // cout << endl;
    // Lc.display(false);
    
    
    return 0;
}