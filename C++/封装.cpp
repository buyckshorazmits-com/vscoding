#include "iostream"
#include <windows.h>
using namespace std;
const double PI=3.14;
//设计一个圆类，球员的周长
//周长的公式 2*PI*半径
//class代表设计一个类，类后面紧跟着就是类名称
class Circle
{
  //访问权限
  //公共权限
  public:
  //属性：半径
  int m_r;
  //行为：获取圆的周长
  double calculateZC()
  {
    return 2*PI*m_r;
  }



};
int main()
{
    // 设置控制台代码页为 UTF-8，配合源文件的 UTF-8 编码，避免中文乱码
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

//通过圆类  创建具体圆（对象）
//给圆对象  的属性进行赋值
Circle  c1;
c1.m_r=10;

cout<<"圆的周长："<<c1.calculateZC()<<endl;





}