#include <bits/stdc++.h>

using namespace std;

int prec(char ch)    // Precedence checking
{
    if(ch =='+' || ch == '-')
        return 1;
    else if(ch== '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return -1;
}


// to check the operand
bool isOperand(char ch)
{
    if(ch =='+' || ch == '-' || ch== '*' || ch == '/')
        return false;
    else 
        return true;
}

string InfixtoPostfix(string s)
{
    stack<char> st; // For stack operations, we are using
                    // C++ built in stack
    string result;
  
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
  
        // If the scanned character is
        // an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'))
            result += c;
  
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');
  
        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
  
        // If an operator is scanned
        else {
            while (!st.empty()
                   && prec(s[i]) <= prec(st.top())) {
                if (c == '^' && st.top() == '^')
                    break;
                else {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }
  
    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    return result;
    
}


int main(){

    string infix = "a+b*c-d/e";
    cout << "Infix: " << infix << endl;

    cout << "Postfix: " << InfixtoPostfix(infix) << endl;

    return 0;
} 