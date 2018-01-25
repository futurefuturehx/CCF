#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
  int temp;
  int temp1;
  int n;
  int max;
  vector<int> list;
  vector<int> list1;
  cin >> n;
  while(n--){
    cin >> temp;
    list.push_back(temp);
  }
  for(int i=0;i<list.size()-1;i++){
    temp1=abs(list.at(i+1)-list.at(i));
    list1.push_back(temp1);
  }
	max=list1.at(0);
  for(int j=1;j<list1.size();j++){
    if(list1.at(j)>max){
      max=list1.at(j);
    }
  }
  cout<<max;
}
//compare
//每一次 
