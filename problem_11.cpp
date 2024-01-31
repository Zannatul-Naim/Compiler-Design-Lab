#include<bits/stdc++.h>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right; 
    Node(char data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

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

bool isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}

Node* parse(string sentence) {
    
    stack<Node*> stack;
    
    for (char ch : sentence) {
        if (isOperand(ch)) {
            Node* node = new Node(ch);
            stack.push(node);
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            Node* node = new Node(ch);
            node->right = stack.top();
            stack.pop();
            node->left = stack.top();
            stack.pop();
            stack.push(node);
        }
    }
    return stack.top();
}

void print(Node* root, int space = 0, int indent = 4) {
    if (root == NULL) return;
    space += indent;
    print(root->right, space);
    cout << endl;
    for (int i = indent; i < space; i++) {
        cout << " ";
    }
    cout << root->data << endl;
    print(root->left, space);
}

int main() {
    string sentence = "a*b+c";

    sentence = infixToPostfix(sentence);
    // getline(cin, sentence);
    Node* tree = parse(sentence);
    print(tree);
    cout << endl;
    return 0;
}
