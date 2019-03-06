#include <iostream>
using namespace std;
int addit(void); // +
int miit(void); // -
int muit(void); // *
float diit(void); // /

int main() {
  float total = 0;
  string how;
  cout << "請輸入運算符號";
  cin >> how;

  if(how == "+") {
    total = addit();
  }else if(how == "-") {
    total = miit();
  }else if(how == "*") {
    total = muit();
  }else if(how == "/") {
    total = diit();
  }else {
    cout << "不支援的計算方式\n";
  }

  cout << "答案: " << total;
}

// +
int addit(void) {
  int add = 0;
  
  while(true) {
    int inp = 0;
    cout << "輸入整數";
    cin >> inp;
    if(inp == 0) {
      break;
    }else {
      add += inp;
    }
  } 

  return add;
}


// -
int miit(void) {
  int mi = 0;
  int i = 0;
  while(true) {
    int inp = 0;
    cout << "輸入整數";
    cin >> inp;
    if(i == 0) {
      mi = inp;
      i++;
      continue;
    }
    if(inp == 0) {
      break;
    }else {
      mi -= inp;
    }
  } 

  return mi;
}


// *
int muit(void) {
  int mu = 1;

  while(true) {
    int inp = 0;
    cout << "輸入整數";
    cin >> inp;
    
    if(inp == 0) {
      break;
    }else {
      mu *= inp;
    }
  } 

  return mu;
}


// /
float diit(void) {
  float di = 0;
  int i = 0;
  while(true) {
    float inp = 0;
    cout << "輸入整數";
    cin >> inp;
    if(i == 0) {
      di = inp;
      i++;
      continue;
    }
    
    if(inp == 0) {
      break;
    }else {
      di /= inp;
    }
  } 

  return di;
}
