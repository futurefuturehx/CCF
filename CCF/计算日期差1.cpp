#include<isotream>
int daysofyear(int a){
  if((a%4==0&&a%100!=0)||a%400==0){
    return 366;
  }else{
    return 365;
  }
}
int daysofmonth(int b){
  if(b==2){
    return 28;
  }else if(b==1,3,5,7,8,10,12){
    return 31;
  }else){
    return 30;
  }
}
int main(){
  int time1[3];
  int time2[3]
  int temp;
  int yeartotal=0;
  int monthtotal;
  int daytotal;
  int total;
  for(i=0;i<3;i++){
    cin>>temp;
    time1[i]=temp;
  }
  cout<<next!<<endl;
  for(i=0;i<3;i++){
    cin>>temp;
    time2[i]=temp;
  }
  }
  for(int i=time1[0];i<time2[0];i++){
    yeartotal+=daysofyear(i);
  }
  for(int i=time1[1];i<time2[1];i++){
    monthtotal+=daysofmonth(i);
  }
  daytotal=time2[2]-time1[2];
  total=yeartotal+monthtotal+daytotal;
  cout<<total<<endl;
}
//很局限 只能第二个日期 每一项都比第一项大的时候用
