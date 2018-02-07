/*
* @Author: wind
* @Date:   2017-08-23 23:46:29
* @Last Modified by:   wind
* @Last Modified time: 2017-08-24 18:23:36
*
* Point: 80%
*/
//模块分类 清晰明了
#include <iostream>
#include <vector>
#include <map>
//map是一个关联容器
using namespace std;

const int M = 15, N = 10;
// int v[M + 8][N];
vector<vector<int> > v;
//vector<int>类型的vector
int b[4][4];
int q;

void input()//录入函数
{
    v.resize(M + 10);//对于二维数组 先调整第一列 也就是每一行的第一个元素
    for (int i = 0; i < v.size(); ++i)
    {
        v[i].resize(N, 0);
    }//再调整每一行
    v[4].resize(N, 1);
    //将第五行的所有值初始化为1
    //resize()用来调整大小
    //N为大小 1为初始值
    for (int i = M + 4; i > 4; --i)
    {+
        for (int j = 0; j < N; ++j)
        {
            cin >> v[i][j];
        }
    }//

    for (int i = 3; i >= 0; --i)
    {
        for (int j = 0; j < 4; ++j)
            cin >> b[i][j];
    }//与题目中不仅起始位置不同
    //甚至顺序也不一样 这里是上下逆序的

    cin >> q;
    --q;
}1

void fallDown()
{
    int l;
    for (l = M + 4; l > 4; --l)
    {
        bool touch = false;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (b[i][j] && v[l + i][q + j])//表示两个都等于1
                //用偏移表示来代替移动
                {
                    touch = true;//表示成功触底
                    break;
                }
            }

            if (touch)
            {
                break;
            }
        }

        if (touch)
        {
            ++l;
            break;
        }//遇到break都要注意对于for的步骤影响
    }

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            v[l + i][q + j] += b[i][j];
        }
    }
}

void output()
{
    for (int i = M + 4; i > 4; --i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    input();
    fallDown();
    output();
    return 0;
}
