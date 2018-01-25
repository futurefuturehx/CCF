#include<iostream>
using namespace std;
int n;
int shuzu[10000];
void shuru(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>shuzu[i];
  }
}
void chuli(){
  int o=0;
  int b[10000],c[10000],d[10000];
  for(int i=0;i<10000;i++){
    d[i]=0;
  }
  for(int i=0;i<n;i++){
    b[i]=1;
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(shuzu[i]==shuzu[j]){
        b[i]++;
      }
    }
  }
  for(int i=0;i<n;i++){
  	c[i]=b[i];
  }
  int max=c[0];
  for(int i=1;i<n;i++){
    if(c[i]>max){
      max=b[i];
    }
  }
  for(int i=0;i<n;i++){
    if(b[i]==max){
      d[o]=shuzu[i];
      o++;//因为是另一个数组坐标作为循环变量 可以加一个变量进行过滤赋值
    }
  }
  int min=d[0];
  for(int i;i<n;i++){
    if((d[i]<min)&&d[i]!=0){
      min=d[i];
    }
  }
  cout<<min;
}
int main(){
  shuru();
  chuli();
  return 0;
}
