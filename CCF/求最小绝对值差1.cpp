#include<iostream>
#include<cmath>
int main()
{
  int min=10000;
  int b=0;
  int a[100];
  int n;
  std::cout << "请输入总共的数字个数" << '\n';
  std::cin >> n ;
  for (int i = 0; i < n; i++)
    std::cin >> a[i]/* variable */;
  for (int i = 0; i < n; i++){
      for(int j = i+1;j < n;j++){
         b=abs(a[j]-a[i]);
         if (b<min)
            min=b;/* code */
      }
  }
  std::cout << min << '\n';
  return 0;
}
