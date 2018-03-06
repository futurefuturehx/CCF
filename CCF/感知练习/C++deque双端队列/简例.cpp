#include<iostream>
#include<deque>
using namespace std;
int main(){
    int i;
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    deque<int>q;
    for(i=0;i<=9;i++){
        if(i%2==0)
            q.push_front(a[i]);
        else
            q.push_back(a[i]);
    }
    q.pop_front();
    printf("%d\n",q.front());
    q.pop_back();
    printf("%d\n",q.back());
    return 0;
}