#include<iostream>
using namespace std;
int main() {
  int n;
  int fin;
  int pre;
  int fiver;
  int threer;
  cin >> n;
  pre = n/10;
  fiver = pre/5;
  threer = (pre-(fiver*5))/3;
  fin = pre+2*fiver+threer;
  cout << fin;
  return 0;
}
