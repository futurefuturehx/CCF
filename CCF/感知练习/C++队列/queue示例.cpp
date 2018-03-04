#include<cstdlib>
#include<iostream>
#include<queue>
using namespace std;
int main(){
    int e,n,m;
    queue<int> q1;
    for(int i=0;i<10;i++){
        q1.push(i);
    }//入队到队列的末端
    if(!q1.empty()){
     `   cout<<"队列不空\n"<<endl;
    }
    n=q1.size();
    cout<<n<<endl;
    m=q1.back();//接受队列的最后一个值
    cout<<m<<endl;
    for(int j=0;j<n;j++){
        e=q1.front();
        cout<<e<<" ";//接收队列的第一个值
        q1.pop();//接受完就弹出 这是一个很重要的操作
    }
    cout<<endl;
    if(q1.empty())
    cout<<"队列不空"<<endl;
    return 0;
}
