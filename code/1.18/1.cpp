#include <bits/stdc++.h>
#include "string"

using namespace std;

string replaceSpace(string s) {
    int len = s.size();
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            count += 2;
        }
    }
    s.resize(len + count);
    for (int j = len; j >= 0; j--) {
        if (s[j] != ' ') {
            s[j + count] = s[j];
        }
        else {

            s[j + count ] = '0';
            s[j + count - 1] = '2';
            s[j + count - 2] = '%';
            count -= 2;
        }
    }
    return s;
}

int main() {
    string s = "   ";
    s = replaceSpace(s);
    printf("%s", s.c_str());
}