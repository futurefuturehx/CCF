#include <iostream>
using namespace std;


int main()
{
int year;
int day;
int monthday[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };


cin >> year;
cin >> day;


if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
monthday[1] = 29;


for (int i = 0; i < 12;i++)
{
if ((day -= monthday[i]) <= 0)//自反运算符加上for循环 自带累加器
{
cout << i + 1 << endl;
day += monthday[i];
cout << day;//cout得单独来看 将所有的cout紧凑到一起才是屏幕上的显示结果
break;
}
}
return 0;
}