#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
    int top;
    char data[10];

    Stack() { top = -1; }

    bool isFull() {
        return (top == 9);
    }

    void clearStack() {
        top = -1;
        cout << "Stack Cleared." << endl;
    }

    bool isEmpty() {
        return (top < 0);
    }

    void push(char symbol) {
        if (!isFull()) {
            data[++top] = symbol;
        }
        else {
            cout << "Stack is Full." << endl;
        }
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return '\0';
        }
        else {
            return data[top--];
        }
    }

    char peek() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return '\0';
        }
        else {
            return data[top];
        }
    }
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}

void validateExpression(const string& expression) {
    Stack stk;
    int len = expression.length();

    for (int i = 0; i < len; i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stk.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stk.isEmpty()) {
                cout << "This expression is NOT correct. Error at character # " << i + 1
                    << ". '" << ch << "' - no matching opening bracket." << endl;
                return;
            }
            else {
                char lastOpen = stk.pop();
                if (!isMatchingPair(lastOpen, ch)) {
                    cout << "This expression is NOT correct. Error at character # " << i + 1
                        << ". '" << lastOpen << "' - not closed correctly." << endl;
                    return;
                }
            }
        }
    }

    if (!stk.isEmpty()) {
        cout << "This expression is NOT correct. Error: Unclosed opening bracket(s)." << endl;
    }
    else {
        cout << "This expression is correct." << endl;
    }
}

int main() {
    string expr1 = "1 + 2 * (3 / 4)";
    string expr2 = "1 + 2 * [3 * 3 + {4 – 5 (6 (7/8/9) + 10) – 11 + (12*8)] + 14";
    string expr3 = "1 + 2 * [3 * 3 + {4 – 5 (6 (7/8/9) + 10)} – 11 + (12*8) / {13 +13}] + 14";

    cout << "Expression 1: " << expr1 << endl;
    validateExpression(expr1);
    cout << endl;

    cout << "Expression 2: " << expr2 << endl;
    validateExpression(expr2);
    cout << endl;

    cout << "Expression 3: " << expr3 << endl;
    validateExpression(expr3);
    cout << endl;

    string userExpr;
    while (userExpr != "end") {
        cout << "Enter an expression to check: ";
        getline(cin, userExpr);
        validateExpression(userExpr);
    }

    return 0;
}
