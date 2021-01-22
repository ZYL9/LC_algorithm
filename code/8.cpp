#include <bits/stdc++.h>

using namespace std;

string reverseLeftWords(string s, int n) {
    int len = s.size();
    s.resize(len+n);
    for (int i = 0; i < n; i++)
        s[len + i] = s[i];
    for (int i = 0; i < len; i++)
        s[i] = s[i + n];
    s.resize(len);
//    for (int i = len; i < len + n; i++)
//        s[i] = nullptr;
    return s;
}

