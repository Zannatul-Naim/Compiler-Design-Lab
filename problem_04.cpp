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

    if((tolower(word[0] < 'i' and tolower(word[0]) > 'n')) or word[0] == '0') return false;

    for(int i = 1; word[i]; i++) {
        if(tolower(word[i] >= 'a' and tolower(word[i]) <= 'z')) continue;
        else if(word[i] >= '0' or word[i] <= '9') continue;
        else return false;
    }
    return true;
}


int main() {

    ifstream file;
    file.open("input.txt");
    string word;
    getline(file, word);

    if(isVariable(word)) {
        cout << "Integer Variable." << endl;
    } else if(word.size() <= 4) {
        if(isInt(word)) {
            cout << "Short Integer." << endl;
        } else {
            cout << "Invalid input | not integer | Undefined" << endl;
        }
    } else if(word.size() > 4 and word.size() <= 20) {
        if(isInt(word)) {
            cout << "Long Integer." << endl;
        } else {
            cout << "Invalid input | not integer | Undefined" << endl;
        }
    } else {
        cout << "Invalid input | not integer | Undefined" << endl;
    }

    return 0;
}