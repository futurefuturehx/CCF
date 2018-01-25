#include<iostream>
using namespace std;
int main(){
  int i=0;
  int *p;
  p=&i;
  cout<<i<<endl;
  cout<<p<<endl;
  cout<<*p<<endl;
  return 0;
}
//指针变量与指针通过地址进行关联
//p表示地址 *p表示变量的值
