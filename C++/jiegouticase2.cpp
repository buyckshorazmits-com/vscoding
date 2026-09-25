#include "iostream"
#include "string"
#include <windows.h>
using namespace std;

struct Hero
{
  string name;
  int age;
 string sex;

};
void burport(Hero hArray[],int len)
{
    for(int i=0;i<len-1;i++)
    {
      for(int j=0;j<len-i-1;j++)
      {
         if(hArray[j].age>hArray[j+1].age)
         {
           Hero temp=hArray[j];
           hArray[j]=hArray[j+1];
           hArray[j+1]=temp;
         }
      }

    }


}
void printHero(Hero hArray[],int len)
{
   for(int i=0;i<len;i++)
   {
      cout<<hArray[i].name<<"的年龄为："<<hArray[i].age<<"，性别为："<<hArray[i].sex<<endl;
   }

}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
  Hero hArray[5]={{"刘备",23,"男"},{"关羽",22,"男"},{"张飞",21,"男"},{"赵云",20,"男"},{"貂蝉",19,"女"}};
  int len=sizeof(hArray)/sizeof(hArray[0]);
  burport(hArray,len);
  printHero(hArray,len);


}


