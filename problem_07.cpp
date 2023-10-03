#include <bits/stdc++.h>

using namespace std;

bool is_keyword(string x)
{
    vector<string> keywords = {
        "true", "false",
        "or", "and", "xor",
        "for", "if", "else", "do", "while", "break", "continue",
        "int", "float", "double", "bool", "long", "unsigned",
        "char", "string", "void", "auto", "new", "switch",
        "namespace", "class", "const", "sizeof", "typedef",
        "delete", "nullptr"
    };
    for (int i = 0; i < keywords.size(); i++) {
        if (keywords[i].compare(x) == 0) {
            return true;
        }
    }
    return false;
}

bool is_operator(string x)
{
    vector<string> operators = {
        "+",
        "-",
        "*", 
        "/",
        "%"
    };

    for (int i = 0; i < operators.size(); i++) {
        if (operators[i].compare(x) == 0) {
            return true;
        }
    }
    return false;
}

bool id_identifier(string x) {
    if (isdigit(x[0])) return false;
    if (x[0] == '_' or (tolower(x[0]) >= 'a' and tolower(x[0]) <= 'z')) {
        return true;
    }
    return false;
}

bool is_string_constant(string x) {
    
    char ch = '"';
    if (x[0] == ch and x[x.size() - 1] == ch) {
        return true;
    }
}

bool is_constant(string x) {
    for (int i = 0; x[i]; i++) {
        if (isdigit(x[i]) or x[i] == '.') {
            continue;
        } else return false;
    }
    return true;
}

int main() {

    string word;
    cin >> word;

    if (is_keyword(word)) cout << word << " is aReserved Keyword\n";
    else if (id_identifier(word)) cout << word << " is an Identifier" << endl;
    else if (is_operator(word)) cout << word << " is an Operator" << endl;
    else if(is_string_constant(word)) cout << word << " is a String Constant" << endl;
    else if (is_constant(word)) cout << word << " is a Constant" << endl;
    else cout << word << " is Invalid" << endl;

    return 0;
}
