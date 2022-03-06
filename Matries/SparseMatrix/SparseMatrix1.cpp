#include <iostream>

using namespace std;

class element
{
public:
    int i;
    int j;
    int x;

};

class sparse
{
private:
    int m;
    int n;
    int num;
    element *ele;
public:
    sparse(int m,int n,int num);
    ~sparse();

    void read();
    void display();
};

sparse::sparse(int m,int n,int num)
{
    this->n = n;
    this->m= m;
    this->num = num;
    ele = new element[this->num];   // to create dynamic size array of objects
}

sparse::~sparse()
{
    delete [] ele;
}

void sparse::read(){
    int k=0;    // for indexing the array of objects of elements
    cout << "Enter the all elements: ";
    for(int i=0; i<num;i++){
        cin>>ele[k].i>>ele[k].j>>ele[k].x;
        k++;
    }
}

void sparse::display(){
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(ele[k].i==i && ele[k].j==j)
                cout <<ele[k++].x << " ";
            else    
                cout << "0 ";
        }
        cout << "\n";
    }


}



int main(){

    sparse s(4,4,4);
    s.read();
    s.display();

    return 0;
}