#include "iostream"
using namespace std;
class Animal
{
  public:
  int m_Age;


};
//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
class Sheep:virtual public Animal{};
class Tuo: virtual public Animal{};
class SheepTuo : public Sheep,public Tuo{};

void test1()
{

    SheepTuo st;
    st.Sheep::m_Age=100;
    st.Tuo::m_Age=200;
    //因为运用了虚继承，所以SheepTuo中的数据m_Age只有一份（只存在虚基类的m_Age）
    //下面st.Tuo::m_Age的赋值会把上面的覆盖掉
    
    //输出值相同，均是200
    cout<<"st.Sheep::m_Age="<<st.Sheep::m_Age<<endl;
    cout<<"st.Tuo::m_Age="<<st.Tuo::m_Age<<endl;
    cout<<"st.m_Age="<<st.m_Age<<endl;
}
int main()
{
  test1();
  return 0;
}