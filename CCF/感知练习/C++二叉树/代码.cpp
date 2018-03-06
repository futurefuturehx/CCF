#include<iostream>
#include<string>
#include<stack>
#include<fstream>
using namespace std;
class Node
{
    public:
        char data;
        class Node *lchild;
        class Node *rchild;
};//定义了一个节点作为结点类型
class Tree
{
    public:
        Tree(){}
        ~Tree(){}
        void Creat(string name){
            ifstream readfile;
            string str;
            readfile.open(name);
            if(readfile.open(name)){
                getline.(readfile,str);//读取一行
            }
            readfile.close();
            CreateNode(str);//构建二叉树
        }//从文件读入 进行构造
}
//先序遍历非递归算法
void Disp(){
    if(t==NULL){
        return;
    }
    stack<Node *>m_stack;
    m_stack.push(t);
    while(!m_stack.empty()){
        Node *p=m_stack.top();//赋值一份当前双亲节点
        cout<<p->data<<ends;//因为是结点指针类型 所以使用p->data
        m_stack.pop();
        if(p->rchild)//先存储右子树 确保先输出左子树
        {
            m_stack.push(p->rchild);
        }
        if(p->lchild){//后存储左子树
            m_stack.push(p->lchild);
        }
    }
}
//非递归中序遍历二叉树
void DispMid(){
    if(t==NULL){
        return;
    }
    Node *p=t;
    stack<Node *>m_stack;
    while(p!=NULL||!m_stack.empty()){
        while(p!=NULL){
            m_stack.push(p);
            p=p->lchild;
        }
        if(!m_stack.empty()){
            p=m_stack.top();
            m_stack.pop();
            cout<<p->data<<ends;
            p=p->rchild;
        }
    }
}