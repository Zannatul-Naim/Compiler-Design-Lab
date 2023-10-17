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

string arithmetic_operators[] = { "+", "-", "*", "/", "%" };
string relational_operators[] = { "==", "!=", "<", ">", "<=", ">=" };
string logical_operators[] = { "&&", "||", "!" };
string bitwise_operators[] = { "&", "|", "^", "~", "<<", ">>" };
string assignment_operators[] = { "=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=" };
string increment_decrement_operators[] = { "++", "--" };

int main() {

    cout << endl << endl;

    freopen("input.txt", "r", stdin);
    string str;

    while (getline(cin, str)) {
        if (find(begin(keywords), end(keywords), str) != end(keywords)) {
            cout << str << " : " << "Keyword "<< endl;;
        }
        else if (find(begin(arithmetic_operators), end(arithmetic_operators), str) != end(arithmetic_operators)) {
            cout << str << " : " << "Arithmetic Operator" << endl;
        }
        else if (find(begin(relational_operators), end(relational_operators), str) != end(relational_operators)) {
            cout << str << " : " << "Relational Operator" << endl;
        }
        else if (find(begin(logical_operators), end(logical_operators), str) != end(logical_operators)) {
            cout << str << " : " << "Logical Operator "<< endl;;
        }
        else if (find(begin(assignment_operators), end(assignment_operators), str) != end(assignment_operators)) {
            cout << str << " : " << "Assignment Operator "<< endl;;
        }
        else if (find(begin(increment_decrement_operators), end(increment_decrement_operators), str) != end(increment_decrement_operators)) {
            cout << str << " : " << "Increment or Decrement Operator "<< endl;;
        }
        else if (str[0] == '_' || isalpha(str[0])) {
            bool flag = true;
            for (int i = 1; i < str.length(); i++) {
                if (!isalnum(str[i]) && str[i] != '_') {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << str << " : " << "Identifier "<< endl;;
            }
            else {
                cout << str << " : " << "Invalid Lexeme "<< endl;;
            }
        }
        else if (str[0] == '"' and str[str.length() - 1] == '"') {
            cout << str << " : " << "String Literal "<< endl;;
        }
        else if (str[0] == '.' or isdigit(str[0])) {
            
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
            if (flag && decimal == 0) {
                cout << str << " : " << "Integer "<< endl;;
            }
            else if (flag && decimal == 1) {
                cout << str << " : " << "Float "<< endl;;
            }
            else {
                cout << str << " : " << "Invalid Lexeme "<< endl;;
            }
        }
        else {
            cout << str << " : " << "Invalid Lexeme "<< endl;;
        }
    }
    cout << endl << endl;
    return 0;
}


/*
input.txt
646.45
do
554
abc
+
*/
