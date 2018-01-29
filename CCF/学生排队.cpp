//算法本质 步骤思维
//1.先将1-n录入
//2.将操作次数录入 录入所有操作
//3.找到对应值编号的位置 弹出
    //用temp先进行备份
//4.找到符合要求的位置插入
//5.输出最后的编号顺序
#include<bits/c++.h>
using namespace std;
struct{
  int p;
  int q;
}std[1001];
int main(){
  int n;
  cin>>n;
  vector<int> list;
  for(int i=0;i<n;i++){
    list.at(i)=i+1;
  }
  int cishu;
  int p;
  int q;
  int temp;
  cin>>cishu;
  while(cishu){
    cin>>p>>q;
  }
  for(int i=0;i<;i++){
      temp=list.at(i);    
  }
}
