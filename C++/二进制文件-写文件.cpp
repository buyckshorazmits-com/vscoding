#include <iostream>
using namespace std;
#include <fstream>//1、包含头文件
class  Person 
{
    public:
    char m_Name[64];
    int m_Age;

};
//二进制文件  写文件
void test1()//二进制方式写文件主要利用流对象调用成员函数write.函数原型 ：ostream& write(const char * buffer,int len);
{
    //2、创建输出流对象
    ofstream ofs;
    //3、打开文件 可以和上一步合二为一
    ofs.open("person.txt",ios::out | ios::binary);

    Person p={"张三",18};
    //4、写文件
    ofs.write((const char*)&p,sizeof(Person));
   //5、关闭文件
    ofs.close();
}
void test2()
{
    ifstream ifs;
    ifs.open("person.txt",ios::in|ios::binary);
    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
    }

    Person p;
    ifs.read((char *)&p,sizeof(p));
    cout<<"姓名："<<p.m_Name<<"年龄："<<p.m_Age<<endl;

    ifs.close();
}
int main()
{
    test1();
    test2();
    return 0;

}


