#include<iostream>
#include<string>
using namespace std;
int main(){
  string str1="Hello";
  string str2="World";
  string str3;
  int len;
  str3=str1;//相比strcpy更加方便
  cout<<str3<<endl;
  str3=str1+str2;//相比strcat更加简介
  cout<<str3<<endl;
  len=str3.size();//相对.len()更加明确
  cout<<len<<endl;
  return 0;
}
