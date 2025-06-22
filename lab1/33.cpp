#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int toInt(const string& s) {
    stringstream ss(s);
    int x;
    ss >> x;
    return x;
}

int evaluatePostfix(string expr) {
    stack<int> s;
    stringstream ss(expr);
    string token;

    while (ss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
            s.push(toInt(token));
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (token[0]) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
              
                default:
                    cout << "Unsupported operator: " << token << endl;
                    return 0;
            }
        }
    }
    return s.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (space separated): ";
    getline(cin, postfix);

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}







/*#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int toInt(const string& s) {
    stringstream ss(s);
    int x;
    ss >> x;
    return x;
}

int evaluatePostfix(string expr) {
    stack<int> s;
    stringstream ss(expr);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            s.push(toInt(token));
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (token[0]) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    return s.top();
}

int main() {
    string postfix = "5 6 + 2 *";
    cout << "Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}*/

