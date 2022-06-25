#include <bits/stdc++.h>

using namespace std;

int pre(char ch)    // Precedence checking
{
    if(ch =='+' || ch == '-')
        return 1;
    else if(ch== '*' || ch == '/')
        return 2;
    return 0;
}


// to check the operand
bool isOperand(char ch)
{
    if(ch =='+' || ch == '-' || ch== '*' || ch == '/')
        return false;
    else 
        return true;
}

string InfixtoPostfix(string infix)
{
    stack <char> st;
    infix += '@';
    string postfix;
    int i=0,j=0;int l = infix.length();
   while(infix[i] != '@')
    {
        if(isOperand(infix[i])){
            postfix += infix[i++];
        }
        else
        {
        if(pre(infix[i]) > pre(st.top()))
            st.push(infix[i++]); 
       else if(st.empty())
            st.push(infix[i++]);
       else 
        {     
            postfix += st.top();
            st.pop();
        }     
                    
                       
        } 
            
    }

    while (!st.empty())
    {
       postfix += st.top();
       st.pop();
    }
    
    return postfix;
    
}


int main(){

    string infix = "a+b*c-d/e";
    cout << "Infix: " << infix << endl;

    cout << "Postfix: " << InfixtoPostfix(infix) << endl;

    return 0;
} 