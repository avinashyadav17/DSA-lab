#include <iostream>
#include <stack>
using namespace std;

bool checkParentheses(string expr) {
    stack<char> s;
    for (int i = 0; i < expr.size(); i++) {
        char ch = expr[i];
        if (ch == '(') s.push(ch);
        else if (ch == ')') {
            if (s.empty()) return false;
            s.pop();
        }
    }
    return s.empty();
}

int main() {
	string expr;
	 cout << "Enter expression: ";
      getline(cin, expr); 
    if (checkParentheses(expr))
        cout << "Parentheses are balanced." << endl;
    else
        cout << "Parentheses are NOT balanced." << endl;
    return 0;
}

