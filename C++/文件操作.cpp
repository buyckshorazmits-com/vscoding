#include <fstream>
#include"iostream"
#include"string"
using namespace std;
//写文件操作
//写文件步骤如下：

//包含头文件 #include <fstream>
//创建流对象 ofstream ofs;
//打开文件 ofs.open("文件路径",打开方式);
//写数据 ofs << "写入的数据";
//关闭文件 ofs.close();
void test1()
{
    ofstream ofs;
    ofs.open("text.txt",ios::out);
    ofs<<"姓名：张三"<<endl;
    ofs<<"性别：男"<<endl;
    ofs<<"年龄 ：19"<<endl;
    ofs.close();
}
//读文件操作
//包含头文件 #include <fstream>
//创建流对象 ifstream ifs;
//打开文件并判断文件是否打开成功 ifs.open("文件路径",打开方式);
//读数据 四种方式读取
//关闭文件ifs.close();
void test2()
{
  ifstream ifs;
  ifs.open("text.txt",ios::in);

  if(!ifs.is_open())//!ifs.is_open()文件流对象的一个成员函数  返回类型是bool
  {
    cout<<"文件打开失败"<<endl;
    return ;
  }

  string buf;
  while (getline(ifs,buf))
  {
   cout<<buf<<endl;    
  }
  ifs.close();
  
}
int main()
{
    test1();
    test2();
    return 0;
}