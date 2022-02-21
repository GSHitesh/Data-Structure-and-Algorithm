#include <iostream>
#include <string>

using namespace std;

struct student{
string name;
int roll;
};

int main()
{
    struct student s = {"GSHitesh" , 10};
    //s.name = "Hitesh";
    //s.roll = 12;
    cout << "Name: " << s.name << endl;
    cout << "Roll No: " << s.roll << endl;
    return 0;
}
