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

    friend istream & operator >> (istream & is, sparse &s);
    friend ostream & operator << (ostream & os, sparse &s);
    sparse operator + (sparse &s);
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

istream & operator >> (istream & is, sparse &s){
    int k=0;    // for indexing the array of objects of elements
    cout << "Enter the all elements: ";
    for(int i=0; i<s.num;i++){
        cin>>s.ele[k].i>>s.ele[k].j>>s.ele[k].x;
        k++;
    }
    return is;
}

ostream & operator << (ostream & os, sparse &s){
    int k=0;
    for(int i=0;i<s.m;i++){
        for(int j=0;j<s.n;j++){
            if(s.ele[k].i==i && s.ele[k].j==j)
                cout <<s.ele[k++].x << " ";
            else    
                cout << "0 ";
        }
        cout << "\n";
    }

    return os;


}


sparse sparse::operator+(sparse &s){
    int i=0,j=0,k=0;    // for indexing s1,s2
    if(m!=s.m || n!=s.n)
        return sparse(0,0,0);
    
    sparse *sum = new sparse(m,n,num+s.num);

    while(i < num && j < s.num){
        if(ele[i].i < s.ele[j].i)
            sum->ele[k++] = ele[i++];
        else if(ele[i].i > s.ele[j].j)
            sum->ele[k++] = s.ele[j++];
        else{

            if(ele[i].j < s.ele[j].j)
                sum->ele[k++] = ele[i++];
            else if(ele[i].j > s.ele[j].j)
                sum->ele[k++] = s.ele[j++];
            else
            {
                sum->ele[k] = ele[i];
                sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
            }
            
        }
    }

    for(;i<num;i++)sum->ele[k++] = ele[i];
    for(;j<s.num;j++)sum->ele[k++] = s.ele[j];
    // while(i<num){
    //     sum->ele[k++] = ele[i++];
    // }
    // while(j<s.num){
    //     sum->ele[k++] = s.ele[j++];
    // }

    sum->num = k;
    
    return *sum;


}



int main(){

    sparse s1(4,4,4);
    sparse s2(4,4,4);
    cin >> s1 >>s2;
    
    sparse sum = s1 + s2; // To call operator +


    cout << "First Matrix: " << endl << s1;
    cout << "Second Matrix: " << endl << s2;
    cout << "Sum of Matrix: " << endl << sum;
  

    return 0;
}