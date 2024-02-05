//@Mehedi-Hasan-Shakil

/*
Write a program that converts the C++ statement to an intermediate code of 
Post-fix notation form.
*/
#include <bits/stdc++.h>
using namespace std;

int precedence(char ch);
string infixtoPostfix(string infix);
string solve(string infix);

int main() {
    // string infix = "if a then if b then c else if d then e else f else if g then h else i ";
    freopen("17.txt", "r", stdin);
    string infix;
    getline(cin, infix);
    cout<<solve(infix);
    return 0;
}

string solve(string infix) {
    string temp = "", postfix = "";
    stack<string> stk;
    for(char ch : infix) {
        if(ch != ' ') temp += ch; // formation of keyword or expression
        else {
            if(temp == "then") {temp = ""; continue;}
            if(temp == "if") stk.push(temp);
            else if(temp == "else") {
                stk.push(temp);

            }
            else {
                // convert infix expression into postfix and add to the postfix string
                postfix += infixtoPostfix(temp);
                // pop if-else pair from stack and add "?" to the postfix string
                while(!stk.empty() && stk.top() == "else") {
                    postfix += "?";
                    stk.pop();
                    stk.pop();
                }
            }
            temp = "";
        }
    }
    return postfix;    
}

string infixtoPostfix(string infix) {
    string postfix = "";
    stack<char> stk;
    for(char ch : infix) {
        // add operands to postfix string
        if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
            postfix += ch;
        }
        // push open parentheses into stack
        else if(ch == '(') stk.push(ch);

        else if(ch == ')') {
            // pop from stack and add to postfix until open parentheses appears
            while (stk.top() != '(')
            {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        // push or pop operator based on their precedence
        else if(ch != ' ') {
            while(!stk.empty() && precedence(ch) <= precedence(stk.top())) {
                postfix += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }          
    }
    while (!stk.empty()) {
        postfix += stk.top();
        stk.pop();
    }
    return postfix;
}

int precedence(char ch) {
    switch (ch)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
