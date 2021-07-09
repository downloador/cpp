#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZÄÅÖabcdefghijklmnopqrstuvwxyzäåö ',#.1234567890:?";
string encrypted = "!#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

char index[75] = {};

bool hasUndefined() {
    for (int i = 0; i < 75; i++) {
        if (index[i] == '§') {
            return true;
        }
    }

    return false;
}

bool isLetterSet(char value) {
    for (int i = 0; i < 75; i++) {
        if (index[i] == value) {
            return true;
        }
    }

    return false;
}

char getPositionFromChar(char value) {
    for (int i = 0; i < 75; i++) {
        if (alphabet[i] == value) {
            return index[i];
        }
    }

    return '§';
}

int main() {
    for (int i = 0; i < 75; i++) { index[i] = '§'; };

    // 1 is true, 0 is false.

    srand(time(0));

    while (hasUndefined() == true) {
        for (int i = 0; i < 75; i++) {
            char value = index[i];
            if (value != '§') continue;

            int random = 0 + rand() % 75;
            char randomLetter = encrypted[random];

            while (isLetterSet(randomLetter) == 1) {
                randomLetter = encrypted[0 + rand() % 75];
            }
            index[i] = randomLetter;
        }
    }

    string toEncrypt = "Hi guys!";
    string Result = "";
    int loopX = toEncrypt.size();

    for (int i = 0; i < loopX; i++) {
        char encryptedChar = getPositionFromChar(toEncrypt[i]);

        Result = Result + encryptedChar;
    }

    cout << Result;
}
