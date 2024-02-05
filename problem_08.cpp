#include <bits/stdc++.h>
using namespace std;

vector<string> keywords = {
    "true", "false",
    "or", "and", "xor",
    "for", "if", "else", "do", "while", "break", "continue",
    "int", "float", "double", "bool", "long", "unsigned",
    "char", "string", "void", "auto", "new", "switch",
    "namespace", "class", "const", "sizeof", "typedef",
    "delete", "nullptr"
};

vector<string> arithmetic_operators = { "+", "-", "*", "/", "%" };
vector<string> relational_operators = { "==", "!=", "<", ">", "<=", ">=" };
vector<string> logical_operators = { "&&", "||", "!" };
vector<string> bitwise_operators = { "&", "|", "^", "~", "<<", ">>" };
vector<string> assignment_operators = { "=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=" };
vector<string> increment_decrement_operators = { "++", "--" };

int main() {

    cout << endl << endl;

    freopen("8.txt", "r", stdin);
    string str;

    while (getline(cin, str)) {
        if (find(keywords.begin(), keywords.end(), str) != end(keywords)) {
            cout << str << " : " << "Keyword "<< endl;;
        } else if (find(arithmetic_operators.begin(), arithmetic_operators.end(), str) != arithmetic_operators.end()) {
            cout << str << " : " << "Arithmetic Operator" << endl;
        } else if (find(relational_operators.begin(), relational_operators.end(), str) != relational_operators.end()) {
            cout << str << " : " << "Relational Operator" << endl;
        } else if (find(logical_operators.begin(), logical_operators.end(), str) != logical_operators.end()) {
            cout << str << " : " << "Logical Operator "<< endl;;
        } else if (find(assignment_operators.begin(), assignment_operators.end(), str) != assignment_operators.end()) {
            cout << str << " : " << "Assignment Operator "<< endl;;
        } else if (find(increment_decrement_operators.begin(), increment_decrement_operators.end(), str) != increment_decrement_operators.end()) {
            cout << str << " : " << "Increment or Decrement Operator "<< endl;;
        } else if (str[0] == '_' or isalpha(str[0])) {
            bool flag = true;
            for (int i = 1; i < str.length(); i++) {
                if (!isalnum(str[i]) && str[i] != '_') {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << str << " : " << "Identifier "<< endl;;
            } else {
                cout << str << " : " << "Invalid Lexeme "<< endl;;
            }
        } else if (str[0] == '"' and str[str.length() - 1] == '"') {
            cout << str << " : " << "String Literal "<< endl;;
        } else if (str[0] == '.' or isdigit(str[0])) {
            bool flag = true;
            int decimal = 0;
            for (char c : str) {
                if (!isdigit(c) && c != '.') {
                    flag = false;
                }
                if (c == '.') {
                    decimal++;
                }
            }
            if (flag and decimal == 0) {
                cout << str << " : " << "Integer "<< endl;;
            } else if (flag && decimal == 1) {
                cout << str << " : " << "Float "<< endl;;
            } else {
                cout << str << " : " << "Invalid Lexeme "<< endl;;
            }
        } else {
            cout << str << " : " << "Invalid Lexeme "<< endl;;
        }
    }
    cout << endl << endl;
    return 0;
}
