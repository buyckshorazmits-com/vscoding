#include "iostream"
using namespace std;

int* func()
{
  //利用new关键字  可以将数据开辟在堆区  这样数据就不会随着函数的调用而释放
  //指针本身也是局部变量  放在栈上  栈上保存的是堆区的地址  指针保存的数据是放在堆区
  int *p=new int (10);
  return p;
}
//在堆区利用new开辟数组
void test02()
{
  int *arr=new int[10];
  for(int i=0;i<10;i++)
  {
    arr[i]=i+20;

  }
   for(int i=0;i<10;i++)
   {
    cout<<arr[i]<<endl;

   }
 delete []arr;  //释放堆区数组
}

int main()
{
  //在堆区开辟数据
  int *p=func();
  cout<<*p<<endl;
  cout<<*p<<endl;
  cout<<*p<<endl;
  cout<<*p<<endl;//可以利用关键字delete释放堆区数据  但是指针本身是局部变量  放在栈上  栈上保存的是堆区的地址  指针保存的数据是放在堆区
 
  test02();

}