#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
  int temp;
  int n;
  vector<int> list;
  cout << "请输入总共的数字个数" << '\n';
  cin >> n /* variable */;
  while(n--){
    cin >> temp;
    list.push_back(temp);
  }
  int min=10010;
  for(int i=0;i<list.size();i++)
  {
    for(int j=i+1;j<list.size();j++)
    {
      int gap=abs(list[i]-list[j]);
      if(gap<min)
        min=gap;
    }
  }
  cout << min << '\n';
  return 0;
}
