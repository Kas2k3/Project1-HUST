#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int countWords(string text) {
    stringstream ss(text); //Phan tach chuoi thanh cac tu rieng le  
    string word;
    int wordCount = 0;
    
    while (ss >> word) { //Doc vao 1 tu va luu no vao bien word
        wordCount++;
    }
    
    return wordCount;
}

int main() {
    string text;//Chuoi de luu tru toan bo van ban
    string line;//Luu tru dong doc vao tu dau den chuoi
    int emptyLineCount = 0;//Dem so dong trong

    while (getline(cin, line)) { //Doc tung dong van van dau vao tieu chuan, neu empty thi tang emptyLineCount
        if (line.empty()) {
            emptyLineCount++;
            if (emptyLineCount > 7) {//Co qua 7 dong trong lien tiep thi dung lai
                break;
            }
        } else {
            text += line + ' ';
        }
    }

    int wordCount = countWords(text);

    cout << wordCount << endl;

    return 0;
}

