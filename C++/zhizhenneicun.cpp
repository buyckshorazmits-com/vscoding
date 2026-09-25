#include "iostream"
#include "windows.h"
using namespace std;
int main()
{
SetConsoleOutputCP(CP_UTF8);
SetConsoleCP(CP_UTF8);

 int *p1=NULL;

 cout<<*p1<<endl;//访问空指针的值，程序会报错
 cout<<p1<<endl;
 

return 0;

}