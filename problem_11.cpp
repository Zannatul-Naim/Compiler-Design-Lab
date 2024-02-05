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
    return (c == '+' or c == '-' or c == '*' or c == '/' or c == '^');
}

int precedence(char c) {
    if(isOperator(c)) return 1;
    else
        return -1;
}

string infixToPostfix(string infix) {
    stack<char> st;
    st.push('N');
    int l = infix.length();
    string postfix;
    for(int i = 0; i < l; i++) {
        if(isdigit(infix[i])) return postfix;
        if(infix[i] != 'a' and infix[i] != 'b' and infix[i] != 'c' and !isOperator(infix[i]) and infix[i] != '(' and infix[i] != ')') return postfix;
        if(infix[i] == 'a' or infix[i] == 'b' or infix[i] == 'c') {
            postfix+= infix[i];
        } else if(infix[i] == '(') {
            st.push('(');
        } else if(infix[i] == ')') {
            while(st.top() != 'N' && st.top() != '(') {
                char c = st.top();
                st.pop();
                postfix += c;
            }
            st.pop();
        } else {
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
    return (ch == 'a' or ch == 'b' or ch == 'c');
}

Node* parse(string sentence) {
    
    stack<Node*> stack;
    
    for (char ch : sentence) {
        if (isOperand(ch)) {
            Node* node = new Node(ch);
            stack.push(node);
        } else if (isOperator(ch)) {
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
    Node* tree = parse(sentence);
    print(tree);
    cout << endl;
    // cout << sentence << endl;
    return 0;
}


/*
//Syntax tree
#include <bits/stdc++.h>

using namespace std;

vector<string> tree(50, "                              ");

void syntaxTree(string ex);
bool isOp(char x);

int main()
{
    string expression;
    // Input format = A+B*C/D*G+F-T
    cin >> expression;
    syntaxTree(expression);
    cout << "Syntax Tree:\n";
    for (string x : tree)
    {
        cout << x << "\n";
    }
}

void syntaxTree(string ex)
{
    int row = 0, col = 2;
    for (int i = 0; ex[i]; i++)
    {
        if (isOp(ex[i]))
        {
            tree[row][col] = ex[i];
            tree[row + 1][col - 1] = '/';
            tree[row + 1][col + 1] = '\\';
            tree[row + 2][col - 2] = ex[i - 1];
            row += 2;
            col += 2;
        }
    }
    tree[row][col] = ex.back();
}

bool isOp(char x)
{
    return (x == '+' or x == '-' or x == '*' or x == '\\');
}

*/
