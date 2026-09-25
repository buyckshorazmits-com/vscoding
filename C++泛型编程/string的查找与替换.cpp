#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
 //字符串的查找与替换
 /*find查找是从左往右，rfind从右往左
  find找到字符串后返回查找的第一个字符位置，找不到返回1
  replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串
*/
 
 
 
 void test1()
 {
    string str1="abcdefg";
    int pos1=str1.find("c");
    //找到返回下标  找不到返回-1
    cout<<"pos1="<<pos1<<endl;
    int pos2=str1.find("de");//返回第一个字母的下标
    cout<<"pos2="<<pos2<<endl;
    int pos3=str1.rfind("ab");//从右往左
    cout<<"pos3="<<pos3<<endl;//匹配字符串第一个字符的位置 返回第一个字母的下标

 }
 void test2()
 {
    string str2="abcdef";
    str2.replace(1,3,"1111111");//从1号位置起，3个字符替换为1111
    cout<<"str2="<<str2<<endl; 
}
 int main()
 {
    test1();
    test2();
    system("pause");
    return 0;

 }