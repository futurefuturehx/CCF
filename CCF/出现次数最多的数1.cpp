#include<iostream>
using namespace std;
int main(){
	int n;
	int temp;
	int maxloc=0;
  struct{
    int num;
    int count;
  }std[10000];
  cin>>n;
  for(int p=0;p<n;p++){
  	std[p].count=0;
  }
  for(int i=0;i<n;i++){
    cin>>temp;
    std[i].num=temp;
  }
  for(int j=0;j<n;j++){
    for(int k=j+1;k<n;k++){
      if(std[k].num==10001){
        continue;
      }
      if(std[j].num==std[k].num){
        std[k].num=10001;
        std[j].count++;
      }
    }
  }
  for(int m=0;m<n;m++){
    if(std[m].count>std[maxloc].count){
      maxloc=m;
    }else if(std[m].count==std[maxloc].count){
			if(std[m].num<std[maxloc].num){
				maxloc=m;
			}
		}
  }
  cout<<std[maxloc].num;
}
//结构体里面初始化。
//因为定义结构体时，并未给其分配内存，所以初值是无法存储的。
//应该声明结构体变量后，手工赋值。
//初始化不正确 尽管可以运行 但是有警告 会扣50分

//将无用位置标废(通过溢出值) 可以避免无用的干扰计算
//结构体数组就好比把数组向下延伸了 增加了更多的比较角度(可实现关联比较赋值):我的腿比你长 所以我手上可以拿西瓜
//std[i].count哪个位置的哪个部分
//注意break跳出的位置 是内层循环 不是外层循环
//有时候适合使用压缩式实验机

//break是跳出整个循环不再循环 continue是跳出本次循环

//看清题目 是输出最小的不是最前面的
