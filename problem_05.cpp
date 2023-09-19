#include <bits/stdc++.h>

using namespace std;

bool is_varibale(string s) {
    if((tolower(s[0]) >= 'i' and tolower(s[0]) <= 'n')) return false;
    if(isdigit(s[0])) return false;
    int n = s.size();

    for(int i = 1; i < n; i++) {
        if(tolower(s[i]) >= 'a' and tolower(s[i]) <= 'z') continue;
        if(isdigit(s[i])) continue;
        else return false;
    }

    return true;
}

bool isFloat(string s) 
{ 
    istringstream iss(s); 
    float dummy; 
    iss >> skipws >> dummy; 
    return (iss && iss.eof() );
} 

int isValidForFloat(string s) {
    int n = s.size(); 
    int cnt = 0;
    bool isDot = false;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == '.') {
            isDot = true;
            break;
        } else cnt++;
    }
    if(isDot) return cnt;
    else return 0;
}

int main() {

    ifstream file;
    file.open("input.txt");
    string text = "", line;
    while(getline(file, line)) {
        text += line;
        if(text[text.size()-1] != ' ') text += ' ';
    }
    cout << text << endl;
    int n = text.size();
    vector < string > words;
    string tmp;
    for(int i = 0; i < n; i++) {
        if(text[i] == ' ') {
            words.push_back(tmp);
            tmp = "";
        } else {
            tmp += text[i];
        }
    } // words.push_back(tmp);

    for(auto word : words) {
        if(is_varibale(word)) {
            cout << word << " is variable" << endl;
        }else if(isValidForFloat(word) == 2 and isFloat(word)) {
            cout << word << " is float" << endl;
        } else if(isValidForFloat(word) > 2 and isFloat(word)) {
            cout << word << " is double" << endl;
        } else {
            cout <<word << " is Undefined!" << endl;
        }
    }

    return 0;

}
