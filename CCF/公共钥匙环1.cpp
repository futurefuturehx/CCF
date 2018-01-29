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
vector<teacher> p,q;//结构体和动态容器的结合
int keyn,tean;
int key[1024];
bool cmpp(const teacher &a,const teacher &b)
{
    return a.s<b.s;//对于sort（）函数 <是从小到大的意思
    //而这边又有一个结构体所以又有一个按照哪一个部分进行排序的语义
}//布尔型函数的好处就是自动判断 只返回真假0与1
bool cmpq(const teacher &a,const teacher &b)//结构题可能体积很大，用单纯的拷贝可能很占空间，所以这边是用引用，
{
    return a.e==b.e?a.num<b.num:a.e<b.e;//经典 包装又包装
    //相等就按第一套规则 不想等就按照第二套规则
}//这是一个三目运算符，如果为真就取前面了，如果为假就去后面，
//也就是说通过判断选择return合适的部分，
//三目运算符加上return和bool完成了两层判断的包装
//如果同时又许多老师换钥匙 就按从编号小到大额顺序 不正好附和三目运算符的精髓吗
int searchkeypos(int keyid)//接收用户的钥匙编号与已有的钥匙一一比对 有的话返回数组索引 虚实结合
{
    for(int i=1;i<=keyn;++i)
        if(keyid==key[i]) return i;
    cout<<"can't find "<<keyid<<endl;
    return -1;
}//这边很清楚 语义是如果找到就返回索引的值
//找到就返回i 没有找到就返回-1
int main()
{
    cin>>keyn>>tean;//两个变量分别表示，教师数量，以及教室钥匙的数量，
    for(int i=1;i<=keyn;++i)
        key[i]=i;
    for(int i=0;i<tean;++i)
    {//注意你刚才的思维误区 不是两段记录而是两张表
        teacher x;//表示有这些字段的记录 teacher表示有这些字段 x是一条待定记录
        cin>>x.num>>x.s>>x.e;//这三个变量分别表示，钥匙的编号，开始上课的时间，补课的时长，
        x.e+=x.s;//补课时长最后变成了课堂结束时间 结束时间也就是放钥匙的时间 开始时间是拿钥匙的时间
        p.push_back(x);//p表
        q.push_back(x);//q表
    }
    sort(p.begin(),p.end(),cmpp);
    sort(q.begin(),q.end(),cmpq);
    int i=0,j=0;//对于while的循环i j初始化可以写在外面
    while(i<tean&&j<tean)//while可以结合逻辑运算和是非运算
    {//语义 任意两两比
        if(p[i].s<q[j].e)//p在拿 谁先先考虑谁
        {
            int pos=searchkeypos(p[i++].num);//这是一个拿操作
            key[pos]=-1;//相当于pv操作 -1标识该位置空了 就标上-1 pv标识
        }//每部分按每部分的规则
        else if(p[i].s>=q[j].e)//q在放 谁先先考虑谁
        {
            int pos=searchkeypos(-1);//虚与实 表与里 表面标识 内部位置
            key[pos]=q[j++].num;//这是一个放操作 找到第一个空位置 放上去
        }//你看 结构体可以异位比较 甚至可以对角线比较
    }
    while(j<tean)
    {
        int pos=searchkeypos(-1);
        key[pos]=q[j++].num;
    }//不断找到空位置 放上去
    for(int i=1;i<=keyn;++i)
        cout<<key[i]<<" ";
    return 0;
}
//题目中的“若果有多位老师换钥匙...”已经被排序解决了
//排序可以预先解决许多特殊情况
