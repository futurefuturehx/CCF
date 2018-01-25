#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<int> list;
  int n;
  int temp;
  int count=0;
  cin>>n;
  while(n--){
    cin>>temp;
    list.push_back(temp);
  }
  for(int i=0;i<list.size()-1;i++){
    if(list.at(i+1)!=list.at(i)){
      count++;
    }
  }
  cout<<count+1<<endl;
}
