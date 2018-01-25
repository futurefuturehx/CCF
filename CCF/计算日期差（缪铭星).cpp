#include<iostream>
using namespace std;
struct date{
  int year;
  int month;
  int days;
};
bool isleap(int year){
  return(year%4==0&&year%100!=0||year%400==0);
}
int DayEachMonth(int year,int month){
  int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  if(month!=2){
    return days[month-1];
  }else{
    return 28+isleap(year);
  }
}
int TotalDays(date d){
    int days=d.days;
    for(int i=1;i<d.year;i++)
      days+=365+isleap(d.year);
    for(int i=1;i<d.month;i++)
      days+=DayEachMonth(d.year,i);
      return days;
  }
  int main(){
    date day1,day2;
    cin>>day1.year>>day1.month>>day1.days;
    cin>>day2.year>>day2.month>>day2.days;
    int days1=TotalDays(day1);
    int days2=TotalDays(day2);
    cout <<days2-days1<<endl;
  }
//用结构体 输入也清晰明了写代码也清晰明了
//依赖关系画出来最先被依赖的写在最前面 例如二月的天数取决于是否为闰年
//整体计算还是分别计算 依据题意来选择 这里需要先计算出总的天数
