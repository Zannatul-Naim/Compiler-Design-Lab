#include<iostrem>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string infix) {
    stack<char> st;
    st.push('N');
    int l = infix.length();
    string postfix;
    for(int i = 0; i < l; i++) {
        if((infix[i] >= 'a' && infix[i] <= 'z')||(infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix+= infix[i];
        }
        else if(infix[i] == '(') {
            st.push('(');
        }
        else if(infix[i] == ')') {
            while(st.top() != 'N' && st.top() != '(') {
                char c = st.top();
                st.pop();
                postfix += c;
            }
            if(st.top() == '(') {
                char c = st.top();
                st.pop();
            }
        }
        else {
            while(st.top() != 'N' && precedence(infix[i]) <= precedence(st.top())) {
                char c = st.top();
                st.pop();
                postfix += c;
            }
            st.push(infix[i]);
        }
    }
    while(st.top() != 'N') {
        char c = st.top();
        st.pop();
        postfix += c;
    }
    return postfix;
}


int main() {

    string sentence = "(a+b)*c";
    string postfix = infixToPostfix(sentence);

    cout << postfix << endl;

    return 0;
}
