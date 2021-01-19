#include <bits/stdc++.h>

using namespace std;

bool isNumber(string s) {
    int countn = 0;//数字的个数
    int countd = 0;//小数点的个数
    int counte = 0;//乘幂的个数
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            if (len == 1)
                return false;
            if (i == 0) {
                while (s[i] == ' ')
                    i++;
            }
            else if (i != len - 1) {
                for (int j = i; j < len; j++) {
                    if (s[j] != ' ')
                        return false;
                }
            }
        }//空格不在//开头//结尾

        if (s[i] != '+' && s[i] != '-' && s[i] != 'e' && s[i] != 'E' && s[i] != '.' && s[i] != ' ') {
//            if(s[i]!='0'||s[i]!='1'||s[i]!='2'||s[i]!='3'||s[i]!='4'||
//            s[i]!='5'||s[i]!='6'||s[i]!='7'||s[i]!='8'||s[i]!='9')
            if (!isdigit(s[i]))//判断是不是数字
                return false;
        }//出现其他字符

        if (isdigit(s[i]))//对数字计数
            countn += 1;

        if (s[i] == '+' || s[i] == '-') {
            if (i != 0) {
                if (s[i - 1] != 'e' && s[i - 1] != 'E' && s[i - 1] != ' ')
                    return false;
            }
            if (i == len - 1)
                return false;
        }//正负号出现在不是开头且不在乘幂后

        if (s[i] == 'e' || s[i] == 'E') {
            counte += 1;
            if (counte > 1)
                return false;
            if (i == 0)
                return false;
            else if (!isdigit(s[i - 1]) && s[i - 1] != '.')
                return false;
            else if (!isdigit(s[i + 1]) && s[i + 1] != '+' && s[i + 1] != '-')
                return false;
        }//判断乘幂

        if (s[i] == '.') {
            countd += 1;
            if (countd > 1)
                return false;
            if (i == 0) {
                continue;
            }
            else if (!isdigit(s[i - 1]) && s[i - 1] != ' ' && s[i - 1] != '+' && s[i - 1] != '-')//点前不是数字不是正负
                return false;
            if (counte == 1)
                return false;
            // else if (s[i + 1] == 'e' || s[i + 1] == 'E' || s[i + 1] == '.')
            //     //点后面有别的东西或者//没有东西//
            //     return false;
        }//小数点判断


    }
    if (countn == 0)
        return false;//如果没有数一定不对
    return true;
}

int main() {
    string s = " -54.53061";
    bool flag = isNumber(s);
    printf("%d", flag);
}
