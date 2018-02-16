#include <bits/stdc++.h>
using namespace std;
int n,cnt[1024];
struct node//类型名写前面
{
    int idx,w;
    node(int a,int b):idx(a),w(b){}//这边是将结构体函数化 使得结构体能够接收参数
    //结构体类型的函数 成员类型的参数 两边都是形参 最后还别忘大括号
};
vector<node> v;
bool cmp(const node &a,const node &b)//对于结构体的cmp可能都要&取地址 再加const
//引文node类型 所以const &
{
    return a.w==b.w?a.idx<b.idx:a.w>b.w;//利用三目运算符加上结构体的多角度存储 实现多条件排序
    //个数相等的话就按照第一个角度排 如果不想等就按照第二个角度排
}//cmp的第一个参数表示前一个数字 第二个参数表示后一个数字
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        cnt[x]++;//利用索引唯一性加上计数器可以实现相同数字的统计
    }
    for(int i=0;i<=1000;++i)
    {
        if(cnt[i])//也就是说如果cnt[i]不等于0
            v.push_back(node(i,cnt[i]));//push_back的是一个值 变量是一个值 函数也是一个值 甚至函数就可以看成一个高级的变量
    }//这也是充分利用坐标 用数组的坐标来存储数字本身 数组里面的值来存储次数
    //充分利用这一个方法可以用在中间过度的时候 又简便又高效
    sort(v.begin(),v.end(),cmp);
    for(size_t i=0;i<v.size();++i)//size_t是类型
    {
        cout<<v[i].idx<<" "<<v[i].w<<endl;
    }
    return 0;
}
