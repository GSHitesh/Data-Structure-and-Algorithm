#include <iostream>

using namespace std;


class term
{
public:
    int coeff;
    int exp;
    
};




class Polynomial
{
private:
    int n;
    term *t;

public:
    Polynomial(int n);
    ~Polynomial();
    friend istream &operator >> (istream & is, Polynomial &P);
    friend ostream &operator<< (ostream & os, Polynomial &P);
    Polynomial operator+(Polynomial &P2);
    Polynomial operator-(Polynomial &P2);
};

Polynomial::Polynomial(int n)
{
    this->n=n;
    t = new term[this->n];
}

Polynomial::~Polynomial()
{
}

istream &operator >> (istream &is,Polynomial &P){
    cout << "Enter the number of terms ";
    cin >> P.n;
    int k=0;
    cout << "Enter the polynomial ";
    for(int i=0;i<P.n;i++){
        cin >> P.t[k].coeff >> P.t[k].exp;
        k++;
    }

    return is;

}


ostream &operator << (ostream &os, Polynomial &P){
    int k=0;
    cout << "Polynomial: ";
    for(int i=0;i<P.n;i++){
        cout << P.t[k].coeff << "x^" << P.t[k].exp;
        if(k<P.n-1)
            cout <<" + "; 
        k++;
    }
    return os;
}
 Polynomial Polynomial::operator+ (Polynomial &P2){
     int i=0,j=0,k=0;
     Polynomial *P3 = new Polynomial(n + P2.n);
     while (i<n && j<P2.n)
     {
         if(t[i].exp > P2.t[j].exp)
            P3->t[k++] = t[i++];
        else if(t[i].exp < P2.t[j].exp)
            P3->t[k++] = P2.t[j++];
        else
        {
            P3->t[k].exp = t[i].exp;
            P3->t[k++].coeff = t[i++].coeff + P2.t[j++].coeff;            

        }

     }
     
     while(i<n)
     {
         P3->t[k++] = t[i++];
     }

    while(j<P2.n)
    {
        P3->t[k++] = P2.t[j++];
    }

    P3->n = k;

    return *P3;



 }

int main(){

    Polynomial P1(5),P2(6);
    cin >> P1 >> P2;
    cout << "Polynomial P1: " << P1 << endl;
    cout << "Polynomial P2: " <<  P2 << endl;
    
    Polynomial P3 = P1 + P2;
    cout << "P1 + P2: " << P3;




    return 0;
}