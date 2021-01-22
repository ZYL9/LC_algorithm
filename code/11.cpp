#include <bits/stdc++.h>

using namespace std;


int strToInt(string str) {
    int res = 0, bond = INT_MAX / 10;
    int i = 0, sign = 1;
    int len = str.size();
    if (len == 0)
        return 0;
    while (str[i] == ' ') {
        if (++i == len)
            return 0;
    }
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;

    for (int j = i; j < len; j++) {
        if (str[j] < '0' || str[j] > '9')
            break;
        if (res > bond || res == bond && str[j] > '7')
            return sign == 1 ? INT_MAX : INT_MIN;
        res = res * 10 + (str[j] - '0');
    }
    return sign * res;
}

int main(){
    string s="4193 with words";
    int a=strToInt(s);
    printf("%d",a);
}