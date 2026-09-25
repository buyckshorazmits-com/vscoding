#include "iostream"
#include "string"
#include <ctime>
#include <windows.h>
using namespace std;
struct Student
{
  string name;
  int score;

};
struct Teacher
{
  string name;
  Student SArray[5];


};
void allocateSpace(Teacher tArray[] , int len)
{
   string tName="教师";
   string sName="学生";
   string nameSeed="ABCDE";
   for(int i=0;i<len;i++)
 {
     tArray[i].name=tName+nameSeed[i];
     for(int j=0;j<5;j++)
     {
       tArray[i].SArray[j].name=sName+nameSeed[j];
       tArray[i].SArray[j].score=rand()%61+40;
      
     }

 }

}
void printTeacher(Teacher tArray[],int len)
{
    for(int i=0;i<len;i++)
    {
      cout<<tArray[i].name<<"的学生成绩如下："<<endl;
      for(int j=0;j<5;j++)
      {
        cout<<tArray[i].SArray[j].name<<"的成绩为："<<tArray[i].SArray[j].score<<endl;
      }
    }
}
int main()
{
  SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand((unsigned int)time(NULL));
   Teacher tArray[3];
   int len=sizeof(tArray)/sizeof(tArray[0]);
    allocateSpace(tArray, len);
    printTeacher(tArray,len);
    
}




