#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<int> list;
  int temp;
  int n;
  cin>>n;
  int count=0;
  while(n--){
    cin >>temp;
    list.push_back(temp);
  }
  for(int i=1;i<list.size()-1;i++){
    if((list.at(i-1)-list.at(i))*(list.at(i+1)-list.at(i))>0){
      count++;
    }
  }
  cout<<count<<endl;
  return 0;
}
//改成乘 并且改成大于号之后正确
