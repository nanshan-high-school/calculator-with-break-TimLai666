#include <iostream>
#include <math.h>
using namespace std;
float first(void);
void gowhile(float);
float makefloat(string);
int stringlen(string);
int reallen(string);
float selectfunction(string, float, float);
float add(float, float);
float mi(float, float);
float mul(float, float);
float di(float, float);

int main() {
    float firstn = first();
    gowhile(firstn);
}


// the first num
float first(void) {
    float firstn = 0;
    cout << "Hello World!\n我是一個快樂的計算機\n支援小數\n請輸入數字：";
    cin >> firstn;
    return firstn;
}


// 重複執行直到'='
void gowhile(float total) {
    while(true) {
        string num;
        float mathnum = 0;
        cout << "請輸入運算符號與數字(ex: +5.2):";
        cin >> num;
        if(num[0] == '=') {
            break;
        }
        mathnum = makefloat(num);
        total = selectfunction(num, total, mathnum);
    }
    cout << "\n答案是：" << total;
}


// make string into float
float makefloat(string num) {
    float floatnum = 0;
    int len = stringlen(num);
    int real = reallen(num);
    real--;// 為了配合pow使用

    for(int i = 1/* 跳過運算符號 */; i < len; i++) {
        // 跳過小數點
        if(num[i] == '.') {
            continue;
        }

        num[i] -= '0';
        floatnum += num[i] * pow(10, real);
        real--;

    }

    return floatnum;
}


// see how long the num is
int stringlen(string num) {
    int len = 0;
    for(int i = 0; num[i] != '\0'; i++) {
        len++;
    }
    return len;
}


// 計算整數部分長度
int reallen(string num) {
    int real = 0;
    for(int i = 1/* 跳過運算符號 */; num[i] != '.' || num[i] != '\0'; i++) {
        real++;
    }
    return real;
}


// 決定運算方式
float selectfunction(string num, float total, float mathnum) {
    if(num[0] == '+') {
        total = add(total, mathnum);
    }else if(num[0] == '-') {
        total = mi(total, mathnum);
    }else if(num[0] == '*') {
        total = mul(total, mathnum);
    }else if(num[0] == '/') {
        total = di(total, mathnum);
    }

    return total;
}


// 加法
float add(float total, float mathnum) {
    total += mathnum;
    return total;
}


// 減法
float mi(float total, float mathnum) {
    total -= mathnum;
    return total;
}


// 乘法
float mul(float total, float mathnum) {
    total *= mathnum;
    return total;
}


// 除法
float di(float total, float mathnum) {
    if(mathnum == 0) {
        cout << "\n無法除以0";
    }else{
        total /= mathnum;
    }
    return total;
}
