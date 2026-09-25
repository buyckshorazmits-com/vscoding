#include "iostream"
#include "string.h"
#include <windows.h>
#define MAX 1000
using namespace std;
struct Person 
{
    string m_name;
    int m_age;
    int m_sex;
    string m_phone;
    string m_addr;

};
struct absaddress
{

    struct Person pArray[MAX];
    int  m_size;

};
void showMeau()
{
  cout<<"*******************"<<endl;
  cout<<"***1.添加联系人***"<<endl;
  cout<<"***2.显示联系人***"<<endl;
  cout<<"***3.删除联系人***"<<endl;
  cout<<"***4.查找联系人***"<<endl;
  cout<<"***5.修改联系人***"<<endl;
  cout<<"***6.清空联系人***"<<endl;
  cout<<"***0.退出通讯录***"<<endl;
}
void addPerson(absaddress *abs)
{
  if(abs->m_size==MAX)
  {
    cout<<"通讯录已满，无法加入"<<endl;

  }
  else
  {
    string name;
    cout<<"请输入姓名："<<endl;
    cin>>name;
    abs->pArray[abs->m_size].m_name=name;

    cout<<"请输入性别："<<endl;
    cout<<"1---男"<<endl;
    cout<<"2---女"<<endl;
    int sex=0;
    while(true)
    {
       cin>>sex;
       if(sex==1||sex==2)
       {
        abs->pArray[abs->m_size].m_sex=sex;
        break;
       }
       cout<<"输入有误，重新输入"<<endl;

    }

    cout<<"请输入年龄："<<endl;
    int age=0;
    cin>>age;
    abs->pArray[abs->m_size].m_age=age;

    cout<<"请输入电话："<<endl;
    string phone;
    cin>>phone;
    abs->pArray[abs->m_size].m_phone=phone;

    cout<<"请输入家庭地址："<<endl;
    string adr;
    cin>>adr;
    abs->pArray[abs->m_size].m_addr=adr; 
    abs->m_size++;
    cout<<"添加成功"<<endl;
    system("pause");
    system("cls");
  }
}
void showperson(absaddress *abs)
{
    if(abs->m_size==0)
    {
     cout<<"记录为空"<<endl;
    }
    else
    {
       for(int i=0;i<abs->m_size;i++)
        {
          cout<<"姓名："<<abs->pArray[i].m_name<<"\t";
          cout<<"性别："<<(abs->pArray[i].m_sex == 1?"男":"女")<<"\t";
          cout<<"年龄："<<abs->pArray[i].m_age<<"\t";
          cout<<"电话："<<abs->pArray[i].m_phone<<"\t";
          cout<<"地址："<<abs->pArray[i].m_addr<<endl;
        }


    }
      
      system("pause");
      system("cls");

}
int isExist(absaddress *abs,string name)
{ 
   for(int i=0;i<abs->m_size;i++)
   {
     if(abs->pArray[i].m_name==name)
     {
       return i;
 

     }
   }
   return -1;
}
void deleteperson(absaddress *abs)
{
  cout<<"请输入要删除的联系人姓名："<<endl;
  string name;
  cin>>name;

  int ret=isExist(abs,name);
  if(ret!=-1)
  {
    for(int i=ret;i<abs->m_size-1;i++)
    {
      abs->pArray[i]=abs->pArray[i+1];//数据前移

    }
    abs->m_size--;
    cout<<"删除成功"<<endl;
  }
else
{
  cout<<"查无此人"<<endl;
}

      system("pause");
      system("cls");
}
void findperson(absaddress*abs)
{
  cout<<"请输入要查找的联系人的姓名："<<endl;
  string name;
  cin>>name;
  int ret=isExist(abs,name);
  if(ret!=-1)
  {
   cout<<""<<abs->pArray[ret].m_name<<"\t";
   cout<<""<<(abs->pArray[ret].m_sex==1?"男":"女")<<"\t";
   cout<<""<<abs->pArray[ret].m_age<<"\t";
   cout<<""<<abs->pArray[ret].m_phone<<"\t";
   cout<<""<<abs->pArray[ret].m_addr<<endl;
  }
  else
  {
    cout<<"查无此人"<<endl;
  }
   system("pause");
   system("cls");
}

void modifyperson(absaddress *abs)
{
  cout<<"请输入要修改的联系人的姓名："<<endl;
  string name;
  cin>>name;
  int ret=isExist(abs,name);
  if(ret!=-1)
  {
    cout<<"请输入新的姓名："<<endl;
    string newname;
    cin>>newname;
    abs->pArray[ret].m_name=newname;

    cout<<"请输入年龄："<<endl;
    int newage=0;
    cin>>newage;
    abs->pArray[ret].m_age=newage;

    cout<<"请输入性别："<<endl;
    cout<<"1----男"<<endl;
    cout<<"2----女"<<endl;
    int newsex=0;
    while(true)
    { 
        cin>>newsex;
      if(newsex==1||newsex==2)
       {
        abs->pArray[ret].m_sex=newsex;
        break;
       }
       cout<<"输入有误，重新输入"<<endl;
    }
   
    
   
    cout<<"请输入电话："<<endl;
    string newphone;  
    cin>>newphone;
    abs->pArray[ret].m_phone=newphone;

    cout<<"请输入家庭地址："<<endl;
    string newaddr;
    cin>>newaddr;
    abs->pArray[ret].m_addr=newaddr;

  cout<<"修改成功"<<endl;

  }
  else 
  {
    cout<<"查无此人"<<endl;
  }

  system("pause");
   system("cls");
}
void clearperson(absaddress *abs)
{
   abs->m_size=0;
   cout<<"通讯录已清空"<<endl;
   system("pause");
   system("cls");

}
int main()
{
    // 设置控制台代码页为 UTF-8，配合源文件的 UTF-8 编码，保证中文不乱码
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
  
   absaddress  abs;
   abs.m_size=0;
  int  select=0;
  while(true)
  {
     showMeau();
      cin>>select;
    switch (select)
    {
      case 1:
      addPerson(&abs);
        break;
      case 2:
      showperson(&abs);
        break;
      case 3:
      deleteperson(&abs);
        break;
      case 4:
      findperson(&abs);
        break;
      case 5: 
      modifyperson(&abs);
        break;
      case 6:
        clearperson(&abs);
        break;
      case 0:
        cout<<"欢迎下次使用"<<endl;
         system("pause");
         return 0;
    break;
    default:
        break;

    }

  } 

}