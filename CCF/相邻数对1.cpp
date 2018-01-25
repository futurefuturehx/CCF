#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n;
  int temp;
  int count=0;
  vector<int> list;
  cin>>n;
  while(n--){
    cin>>temp;
    list.push_back(temp);
  }
  for(int i=0;i<list.size();i++){
    for(int j=0;j<list.size();j++){
      if(abs(list.at(i)-list.at(j))==1){
        count++;
    }
  }
  }
  count<<count/2;
  return 0;
}
