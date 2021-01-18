#include <bits/stdc++.h>
#include "string"

using namespace std;

int main() {
    string s = "12345";
    int len = s.size();
    char a[len];
    //printf("%d \n",len);
    // printf("%s \n",s.c_str());
    for (int i = 1; i < len; i++) {
        //printf("%d",s[i]);
        a[i]=s[i];
    }
}

