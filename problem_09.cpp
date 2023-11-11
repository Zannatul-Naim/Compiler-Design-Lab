#include <bits/stdc++.h>

using namespace std;

int main() {

    set<string> pn = {"Sagor", "Selim", "Salma", "Nipu"};
    set<string> p = {"he", "she", "I", "we", "you", "they"};
    set<string> n = {"book", "cow", "dog", "home", "grass", "rice", "mango"};
    set<string> v = {"read", "eat", "take", "run", "write"};

    string sentence;
    freopen("9.txt", "r", stdin);
    
    while(getline(cin, sentence)) {

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

        if(words.size() > 3 or words.size() < 2) {
            cout << sentence << ": Invalid Input" << endl;
            break;
        }
        bool isValid = true;
        for(string word : words) {
            cnt++;
            if(cnt == 1 and !pn.count(word) and !p.count(word)) {
                isValid = false;
                break;
            } else if(cnt == 2 and !v.count(word)) {
                isValid = false;
                break;
            } else if(cnt == 3 and !n.count(word)) {
                isValid = false;
            }
        }
        
        if(isValid) cout << sentence << ": Syntactically Valid" << endl;
        else cout << sentence << ": Syntactically Invalid!" << endl;

    }

    return 0;

}
