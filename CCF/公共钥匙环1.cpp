#include <bits/stdc++.h>
//这是万金油头文件啊 写了这个头文件 其他所有的头文件都不用写了
//但是编译速度好像有所影响
using namespace std;
struct teacher
{
    int num,s,e;
    teacher(int x=0,int y=0,int z=0):num(x),s(y),e(z){}
};//前面表示是空函数，后面表示调用，这个空函数之前，会先调用后面几个函数，
//C++结构体允许定义函数，跟类很相似，但是前者默认是公开的，后者默认是私有的，
vector<teacher> p,q;
int keyn,tean;
int key[1024];
bool cmpp(const teacher &a,const teacher &b)
{
    return a.s<b.s;
}//布尔型函数的好处就是自动判断 只返回真假0与1
bool cmpq(const teacher &a,const teacher &b)//结构题可能体积很大，用单纯的拷贝可能很占空间，所以这边是用引用，
{
    return a.e==b.e?a.num<b.num:a.e<b.e;
}//这是一个三目运算符，如果为真就取前面了，如果为假就去后面，
//也就是说通过判断选择return合适的部分，
int searchkeypos(int keyid)
{
    for(int i=1;i<=keyn;++i)
        if(keyid==key[i]) return i;
    cout<<"can't find "<<keyid<<endl;
    return -1;
}//这边很清楚 语义是如果找到就返回索引的值
int main()
{
    cin>>keyn>>tean;//两个变量分别表示，教师数量，以及教室钥匙的数量，
    for(int i=1;i<=keyn;++i)
        key[i]=i;
    for(int i=0;i<tean;++i)
    {
        teacher x;
        cin>>x.num>>x.s>>x.e;//这三个变量分别表示，钥匙的编号，开始上课的时间，补课的时长，
        x.e+=x.s;
        p.push_back(x);
        q.push_back(x);
    }
    sort(p.begin(),p.end(),cmpp);
    sort(q.begin(),q.end(),cmpq);
    int i=0,j=0;
    while(i<tean&&j<tean)
    {
        if(p[i].s<q[j].e)
        {
            int pos=searchkeypos(p[i++].num);
            key[pos]=-1;
        }
        else if(p[i].s>=q[j].e)
        {
            int pos=searchkeypos(-1);
            key[pos]=q[j++].num;
        }
    }
    while(j<tean)
    {
        int pos=searchkeypos(-1);
        key[pos]=q[j++].num;
    }
    for(int i=1;i<=keyn;++i)
        cout<<key[i]<<" ";
    return 0;
}
