//就好像数学一样 轨迹是第一类思想过程思维 轨迹就是过程 轨迹必有规律
//空白模板就好比是数学中的辅助线 是简化思想 有时有奇效
//这边在空白模板重复赋值为1不会改变它有无的事实 因为把1再赋给值为1的变量 这个变量还是1
//如果按照正常的过程思维 会很麻烦 需要考虑重叠部分又被第三个矩形覆盖
#include<iostream>
using namespace std;
int main(){
  int n;
  int count=0;
  int youwu[100][100]={0};
  cin>>n;
  while(n--){
    int a[4];
    cin>>a[0]>>a[1]>>a[2]>>a[3];//这边每次都会初始化一个数组 接收四个数据
    for(int i=a[0];i<a[2];i++){
      for(int j=a[1];j<a[3];j++){
        youwu[i][j]=1;
      }
    }
  }
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      if (youwu[i][j]==1){
        count++;
      }
    }
  }
  cout<<count<<endl;
  return 0;
}
