#include <bits/stdc++.h>

using namespace std;

// Using c++ STL
bool isBalanced(string str)
{
    stack <char> st;
    
    for(int i=0;i<str.length();i++){
        if(str[i] == '(')
            st.push(str[0]);

        else if(str[i] == ')'){
            if(!st.empty()){            
                st.pop();
            }
            else return 0;
        }
        
    }

    if(st.empty())  return 1;   //If stack is empty then its true
    else return 0;
    
    
}


bool isBalancedExteneded(string str)
{
    stack <char> st;
    
    for(int i=0;i<str.length();i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
            st.push(str[i]);

        else if((st.top()=='(' && str[i]==')')  ||  (st.top()=='{' && str[i]=='}')  ||  (st.top()=='[' && str[i]==']'))
         if(!st.empty()){            
                st.pop();
            }
         else return 0;
        }
        
    
    if(st.empty())  return 1;   //If stack is empty then its true
    else return 0;
    
    
}

int main(){

    string str = "{[}]";

    cout << isBalancedExteneded(str);



    return 0;
}
