#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<int> list;
  int temp;
  int count=0;
  int n;
  cin >> n;
  while(n--){
    cin >> temp;
    list.push_back(temp);
  }
  for(int i=1;i<list.size()-1;i++){
    if(list.at(i)-list.at(i-1)!=list.at(i+1)-list.at(i)){
      count++;
    }
  }
  cout<<count<<endl;
}
