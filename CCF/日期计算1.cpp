#include<iostream>
using namespace std;
bool isleap(int a){
    if((a%4==0&&a%100!=0)||a%400==0){
        return true;
    }else{
        return false;
    }
}//返回判断结果
int main(){
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int y;
    cin>>y;
    int d;
    int mon,day;
    int leijia=0;//准备累加器
    if(isleap(y)){
        month[1]+=1;
    }
    cin>>d;
    for(int i=0;i<12;i++){
        leijia+=month[i];
        if(d-leijia<month[i+1]){
            mon=i+2;
            day=d-leijia;
            if(d-leijia==0){
            	mon--;
            	day=month[i];
			}
            break;//找到为止			
        }
    }//要考虑到最后一天不能写为3月0日
    cout<<mon<<endl;
    cout<<day<<endl;
    return 0;
}