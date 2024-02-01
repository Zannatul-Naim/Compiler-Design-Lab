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
