#include <bits/stdc++.h>

using namespace std;

int main() {

    set<string> pn = {"Sagor", "Selim", "Salma", "Nipu"};
    set<string> p = {"he", "she", "I", "we", "you", "they"};
    set<string> n = {"book", "cow", "dog", "home", "grass", "rice", "mango"};
    set<string> v = {"read", "eat", "take", "run", "write"};

    string sentence;
    getline(cin, sentence);

    vector<string> words;

    string tmp = "";
    for(int i = 0; sentence[i]; i++) {
        if(sentence[i] == ' ') {
            words.push_back(tmp);
            tmp = "";
        } else {
            tmp += sentence[i];
        }
    } words.push_back(tmp);

    int cnt = 0;

    for(string word : words) {
        cnt++;
        if(cnt == 1 and !pn.count(word) and !p.count(word)) {
            cout << "Syntactically Invalid!" << endl;
            return 0;
        } else if(cnt == 2 and !v.count(word)) {
            cout << "Syntactically Invalid!" << endl;
            return 0;
        } else if(cnt == 3 and !n.count(word)) {
            cout << "Syntactically Invalid!" << endl;
            return 0;
        }
    }

    cout << "Syntactically Valid" << endl;

    return 0;

}
