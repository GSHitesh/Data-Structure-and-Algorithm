#include <iostream>

using namespace std;

class Matrices
{
private:
    int n;    
    int arr[6];
    // int *arr;
public:
    Matrices(int n);
    ~Matrices();

//  Diagonal Matrix
    void setA( int i, int j, int x){
        if(i ==j )
            arr[i] = x;
    }

    int getA(int i, int j){
        if(i ==j )
            return arr[i];
        return 0;
    }

    void display(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)
                    cout << getA(i,j) <<" ";
                else    
                    cout << "0" << " ";
            }
            cout << endl;
        }
    }
};

Matrices::Matrices(int n)
{
    this->n = n;
    // arr = new int[n];
}

Matrices::~Matrices()
{
    delete [] arr;
}



int main(){

    Matrices m(3);
    m.setA(0,0,2);  
    m.setA(1,1,5);
    m.setA(2,2,7);
    // cout << m.getA(2,2);
    m.display();
    return 0;
}