#include<iostream>
#include<cstring>//当需要操作字符串的时候需要加上#include<cstring>
using namespace std;
int main(){
  char str1[11]="Hello";
  char str2[11]="World";
  char str3[11];
  int len;
  //strcpy用来实现字符串复制 将字符串str1复制到str3
  strcpy(str3,str1);
  cout<<str3<<endl;
  //strcat用来拼接 将str2拼接到str1
  strcat(str1,str2);
  cout<<str1<<endl;
  //strlen用来获得字符串的长度
  len=strlen(str1);
  cout<<len<<endl;
  return 0;
}
