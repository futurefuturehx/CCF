#include<iostream>
#include<vector>
using namespace std;
int main(){
  int m;
  int n;
  cin>>m;
  cin>>n;
  vector<vector<int> > array(m);
  for (int i=0;i<m;i++){
    array[i].resize(n);
  }
  for(int j=0;j<array.size();j++){
    for(int k=0;k<array[0].size();k++){
      cin>>array[j][k];
    }
  }
  for(int a=0;a<array[0].size();a++){
    for(int b=0;b<array.size();b++){
      cout<<array[b][n-a-1]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
//声明vector的二维数组
//vector<vector<int> > array(m);
//这个m一定不能少
//初始化一个m*n的二维数组
/*for(int i=0;i<m;i++) {
    array[i].resize(n);
}*/
//倒数第一列变成第一行
//array.size()表示有多少行
//array[0].size()表示
//这边搞错了 a是原来的列 现在的行
//这边搞错了 b是原来的行 现在的列
//参照点思想 当问题比较混淆复杂的时候 最好选择一个参照点
//可以是原点 也可以是初始点 关键是所有变形形式的参照点唯一
//注意用数组长度来确定位置的时候一定要减一
//因为数组的长度本来就比最高位置的索引多一
