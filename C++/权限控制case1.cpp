#include "iostream"
#include <windows.h>
using namespace std;
 
class Cube
{
  public:
  void setL(int l)
  {
    m_L=l;
  }
  int getL()
  {
        return m_L;
  }

void setW(int w)
  {
    m_W=w;
  }
  int getW()
  {
        return m_W;
  }
void setH(int h)
  {
    m_H=h;
  }
  int getH()
  {
        return m_H;
  }
  int CubeS()
  {
   return 2*m_L*m_W+2*m_H*m_W+2*m_L*m_H;

  }
  int CubeV()
  {
   return m_L*m_W*m_H;

  }
  bool Cubecompare(Cube &c2)
  {
    if(m_L==c2.getL()&&m_H==c2.getH()&&m_W==c2.getW())
    {
      return true;
    }  
      
     return false;
  }

private:
int m_L;
int m_W;
int m_H;


};
bool wabuCubecompare(Cube &c1,Cube &c2)
{
  if(c1.getL()==c2.getL()&&c1.getH()==c2.getH()&&c1.getW()==c2.getW())
    {
      return true;
    }  
      
     return false;  

}
int main()
{
   // 设置控制台代码页为 UTF-8，配合源文件的 UTF-8 编码，避免中文乱码
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
    Cube c1;
    c1.setW(10);
    c1.setH(10);
    c1.setL(10);
   cout<<"立方体的面积:"<< c1.CubeS()<<endl;
   cout<<"立方体的体积:"<<c1.CubeV()<<endl;

    Cube c2;
    c2.setH(10);
    c2.setW(100);
    c2.setL(10);
   bool ret=wabuCubecompare(c1,c2);
 if(ret)
 {
   cout<<"两个立方体相等"<<endl;

 }
else
{
 cout<<"两个立方体不相等"<<endl;
}
}