#include<iostream>
#include<stack>
#include<string>
#include "arraystack.h"
using namespace std;

// TODO implement this method.
// Use the ArrayStack to perform the stack operations needed.
int is_balanced_parentheses(string str) {
    ArrayStack* stack = new ArrayStack();
    // note to self
    // test case 8
    // ()[(){}]){}
    // answer must be: The parentheses are not balanced due to missing opening parentheses!
    // this is return 3
    // use stack top for return 1 answers

    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack->push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            char top = stack->top();
            if (stack->isEmpty()) {
                return 3;
            }
            else {
                stack->pop();
                if ((ch == ')' && top != '(')
                    || (ch == '}' && top != '{')
                    || (ch == ']' && top != '[')) {
                    return 1;
                }
            }
        }
    }

    if (stack->isEmpty()) {
        return 0;
    } else {
        return 2;
    }
}

int main() {
    string str;
    cout << "Enter a string with parentheses: ";
    cin >> str;
    int res = is_balanced_parentheses(str);
    switch (res) {
        case 0:
            cout << "The parentheses are balanced!" << endl;
            break;
        case 1:
            cout << "The parentheses are not balanced due to mismatch!" << endl;
            break;
        case 2:
            cout << "The parentheses are not balanced due to missing closing parentheses!" << endl;
            break;
        case 3:
            cout << "The parentheses are not balanced due to missing opening parentheses!" << endl;
            break;
    }
    return 0;
}