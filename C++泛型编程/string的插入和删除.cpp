#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
// insert()：在指定位置插入字符串
// 用法1：
// insert(pos, const char* s)
// 从pos位置开始插入C风格字符串

// 用法2：
// insert(pos, const string& str)
// 从pos位置开始插入string对象
// 用法3：
// insert(pos, n, char c)
// 从pos位置开始插入n个字符c

// erase()：删除字符串中的字符
// erase(pos, n)
// 从pos位置开始删除n个字符
// erase(pos)
// 从pos位置开始删除到字符串末尾

//字符串的插入和删除
void test1()
{
  string str1="hello" ;
  //插入
  str1.insert(1,"111");//在str1字符串的1号位置上 插入111

  cout<<"str1="<<str1<<endl;
  //删除
  str1.erase(1,3);//在str1字符串的1号位置上 删除往后开始的3个字符
  cout<<"str1="<<str1<<endl;


}
int main()
{
   test1();
   system("pause");
   return 0;
}
