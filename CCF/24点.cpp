#include <tchar.h>//用来存放通用字符串
#include <vector>
#include <string>
using namespace std;
//因为中间结果可能有非整数，所以使用float 保存数值
typedef pair<float,string> VALUE_DESC;
//
typedef vector<VALUE_DESC> VEC_DESC;
/**
 *  \fn string gen_op(char* op,string &desc1,string &desc2)
 *  \brief 生成二值计算的表达式
 *  \param op 操作符 + - * /
 *  \param desc1 第一个操作数的表达式
 *  \param desc2 第二个操作数的表达式
 */
string gen_op(char* op,string &desc1,string &desc2)
{
    string result ="(";
    result.append(op);
    result.push_back(' ');
    result.append(desc1);
    result.push_back(' ');
    result.append(desc2);
    result.push_back(')');
    return result;
}

/**
 *  \fn VEC_DESC four_calc(VALUE_DESC &a1,VALUE_DESC &a2)
 *  \brief 四则运算
 *  \param a1 --第一个值和它的表达式
 *  \param a2 --第二个值和它的表达式
 *  \return 值和它的表达式
 */
VEC_DESC four_calc(VALUE_DESC &a1,VALUE_DESC &a2)
{
#define APPEND_RESULT(vec,op,a1,a2) vec.push_back(make_pair(a1.first##op##a2.first,gen_op(#op,a1.second,a2.second)));
    VEC_DESC result ;
    char op[4] ={'+','-','*','/'};
    for(int i=0;i<4;i++)
    {
        char c = op[i];
        switch(c)
        {
        case '+':
            {
                APPEND_RESULT(result,+,a1,a2);
                break;
            }
        case '-':
            {
                APPEND_RESULT(result,-,a1,a2);
                APPEND_RESULT(result,-,a2,a1);
                break;
            }
        case '*':
            {
                APPEND_RESULT(result,*,a1,a2);
                break;
            }
        case '/':
            {
                if(a1.first!=0)
                {
                    APPEND_RESULT(result,/,a2,a1);
                }
                if(a2.first!=0)
                {
                    APPEND_RESULT(result,/,a1,a2);
                }
                break;
            }

        }
    }
    return result;
}
/**
 *  \fn void calc(VALUE_DESC value,VEC_DESC &vec,VEC_DESC &result)
 *  \brief 递归计算vec和输入的value 之间的值，结果保存result
 *  \param value - 输入的值，初始值为0
 *  \param vec - 一组数,初始为4个数
 *  \param result - 结果为最终通过四则混合运算计算的可能结果，很多很多
 */
void calc(VALUE_DESC value,VEC_DESC &vec,VEC_DESC &result)
{
    if(value.first==0)//还没有中间结果
    {
        if(vec.size()==1) //得到结果
        {
            result.push_back(vec[0]);
            return ;
        }
        for(size_t i=0;i<vec.size();i++) //顶层的计算，4个则可能有4种取的可能
        {
            VEC_DESC t = vec;
            t.erase(t.begin()+i);
            calc(vec[i],t,result);//输出可能的值
        }
    }
    else
    {
        //有了中间结果,从vec中获取1个元素，参与运算，结果继续运算
        for(size_t i=0;i<vec.size();i++)
        {
            VEC_DESC t = vec;
            t.erase(t.begin()+i);
            //中间结果
            VEC_DESC vcalc=four_calc(value,vec[i]);
            for(size_t j=0;j<vcalc.size();j++)
            {
                VEC_DESC tt = t;
                tt.push_back(vcalc[j]);
                //中间结果,剩下的元素,结果
                calc(make_pair(0.0,string("")),tt,result);
            }
        }
    }
}
//初始化数据
void init_vec_desc(VEC_DESC &vec,int value[],int len)
{
    for(int i=0;i<len;i++)
    {
        char buf[10]={};
        itoa(value[i],buf,10);

        vec.push_back(make_pair(value[i],buf));
    }
}
//获得等于24的结果
VALUE_DESC get_correct_value(VEC_DESC &r)
{
    for(size_t i=0;i<r.size();i++)
    {
        if(r[i].first >=24.0000000 && r[i].first<24.00000001 )
        {
            return r[i];
        }
    }
    return make_pair(0,"");
}
int to24(VEC_DESC &vec)
{
    VEC_DESC r;
    calc(make_pair(0.0,string("")),vec,r);
    VALUE_DESC result = get_correct_value(r);
    if(result.first==0)
    {
        printf("[%d %d %d %d] cannot calculate 24\n",(int)vec[0].first,(int)vec[1].first,(int)vec[2].first,(int)vec[3].first);
    }
    else
    {
    printf("[%d %d %d %d] : %s\n",(int)vec[0].first,(int)vec[1].first,(int)vec[2].first,(int)vec[3].first,result.second.c_str());
    }
    return 0 ;
}
void test()
{
    VEC_DESC input;
    VEC_DESC r;
    int buf[][4]={
            {5,1,4,2},
            {3,3,3,1},
            {5,5,5,1},
            {1,1,6,8},
            {1,1,6,9},
            {1,1,7,10},
            {1,1,8,8},
    };
    for(int i=0;i<sizeof(buf)/sizeof(buf[0]);i++)
    {
        input.clear();
        init_vec_desc(input,buf[i],4);
        to24(input);
    }
}
void test1()
{
    int i,j,k,m;
    for(i=1;i<=13;i++)
        {
        for(j=1;j<=13;j++)
            {
            for(k=1;k<=13;k++)
                {
                for(m=1;m<=13;m++)
                    {
                    VEC_DESC input;
                    int buf[4]={i,j,k,m};
                    init_vec_desc(input,buf,4);
                    to24(input);
                    }
                }
            }
        }
}
int _tmain(int argc, _TCHAR* argv[])
{
    test1();
    return 0;
    VEC_DESC input;
    VEC_DESC r;
    int buf[4]={5,1,4,2};
    printf("\nPlease input 4 number:");
    scanf("%d%d%d%d",&buf[0],&buf[1],&buf[2],&buf[3]);
    init_vec_desc(input,buf,4);
    to24(input);

    return 0;
}
