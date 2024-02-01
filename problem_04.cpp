#include <bits/stdc++.h>
using namespace std;

bool isInt(string word) {

    if(word[0] == '0') return false;

    for(int i = 1; i < word.size(); i++) {
        if(!isdigit(word[i])) return false;
    }
    return true;
}

bool isVariable(string word) {

    if(!(tolower(word[0] >= 'i' and tolower(word[0]) <= 'n'))) return false;

    for(int i = 1; word[i]; i++) {
        if(tolower(word[i] >= 'a' and tolower(word[i]) <= 'z')) continue;
        else if(word[i] >= '0' or word[i] <= '9') continue;
        else return false;
    }
    return true;
}


int main() {

    freopen("input.txt", "r", stdin);
    string word;
    
    while(getline(cin, word)) {

        if(isVariable(word)) {
            cout << word << " : Integer Variable." << endl;
        } else if(word.size() <= 4) {
            if(isInt(word)) {
                cout << word << " : Short Integer." << endl;
            } else {
                cout << word << " : Invalid input | not integer | Undefined" << endl;
            }
        } else if(word.size() > 4 and word.size() <= 20) {
            if(isInt(word)) {
                cout << word << " : Long Integer." << endl;
            } else {
                cout << word << " : Invalid input | not integer | Undefined" << endl;
            }
        } else {
            cout << word << " : Invalid input | not integer | Undefined" << endl;
        }
    }

    return 0;
}
