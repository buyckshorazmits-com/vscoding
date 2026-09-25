#pragma once
#include<iostream>
using namespace std;
template <class T>
class Myarry
{
    public:
    //Myarry的有参构造  参数容量 大小
    Myarry(int Capacity)
    {
        this->m_Capacity=Capacity;
        this->m_Size=0;
        this->pAddress=new T[this->m_Capacity];
    }
    //Myarry的拷贝构造
    Myarry(const Myarry &arr)
    {
        cout<<"Myarry的拷贝构造"<<endl;
        this->m_Capacity=arr.m_Capacity;
        this->m_Size=arr.m_Size;
        //深拷贝
        this->pAddress= new T[arr.m_Capacity];
        //将arr中的数据全部拷过来

        for(int i=0;i<this->m_Size;i++)
        {
            this->pAddress[i]=arr.pAddress[i];
        }
    }
    //运算符重载  防止浅拷贝的问题
    Myarry &operator=(const Myarry &arr)
    {
        //cout<<"opreator=的调用<<endl;
        //判断堆区中是否有数据
        if(this->pAddress!=NULL)
        {
            delete [] this->pAddress;
            this->pAddress=NULL;
            this->m_Capacity=0;
            this->m_Size=0;

        }
        //深拷贝
        this->m_Capacity=arr.m_Capacity;
        this->m_Size=arr.m_Size;
        this->pAddress= new T [arr.m_Capacity];

        for(int i=0;i<this->m_Size;i++)
        {
            this->pAddress[i]=arr.pAddress[i];
        }
        return *this;
    }
    //尾插法  插入数据
    void PushBack(const T &val)
    {
        if(this->m_Capacity==this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size]=val;
        this->m_Size++;

    }
    //尾删法  让用户访问不到最后一个元素
    void PopBack()
    {
        if(this->m_Size==0)
        {
            return ;
        }
        this->m_Size--;
    } 

    //通过下标的方式访问元素
    T &operator [](int index)
    {
        return this->pAddress[index];
    }

    //返回数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }
    //返回大小
    int getSize()
    {
        return this->m_Size;
    }

    //析构函数
    ~Myarry()
    {
        if(this->pAddress !=NULL)
        {
            delete [] this->pAddress;
            this->pAddress=NULL;
        }
    }



    private:
    T *pAddress;//指向堆区开辟的数组地址
    int m_Capacity;//数组容量
    int m_Size;//数组大小

};
