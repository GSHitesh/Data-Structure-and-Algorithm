int main() {
 
    char A[] = "{([a+b]*[c-d])/e}";
    cout << isBalanced(A) << endl;
 
    char B[] = "{([a+b]}*[c-d])/e}";
    cout << isBalanced(B) << endl;
 
    char C[] = "{([{a+b]*[c-d])/e}";
    cout << isBalanced(C) << endl;
 
    return 0;
}