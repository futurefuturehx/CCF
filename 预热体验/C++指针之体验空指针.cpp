#include<iostream>
using namespace std;
int main(){
  int *p=NULL;
  cout<<&p<<endl;
  cout<<p<<endl;
  return 0;
}
//指针本身也会有地址
//如果将一个指针赋值为空指针 那么*p最后会输出0
