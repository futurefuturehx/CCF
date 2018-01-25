#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  vector<int> list;
  vector<int> list1;
  int temp1;
  int temp;
  int count=1;
  cin>>n;
  while(n--){
    cin>>temp;
    list.push_back(temp);
  }
  for(int i=0;i<list.size();i++){
    for(int j=0;j<i;j++){
      if(list.at(j)==list.at(i)){
        count++;
      }
    }
    list1.push_back(count);
    count=1;
  }
  for(int k=0;k<list1.size();k++){
    cout<<list1.at(k)<<" ";
  }
  return 0;
}
//一层实验机(循环)不够就用两层实验机(循环)
//注意同时浮现的不是一个实验机 而是两个 因为空间比时间容易理解
