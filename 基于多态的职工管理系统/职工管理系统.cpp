#include"iostream"
#include"workManger.h"
#include"woker.h"
#include "manger.h"
#include"employee.h"
using namespace std;

int main()
{
    //统一控制台代码页为UTF-8，避免中文姓名读写时出现乱码（GBK/UTF-8混用）
    system("chcp 65001>nul");
    //实例化管理对象
    WorkManger VM;
    //显示菜单
    int choice=0;
    while(true)
    {    //显示菜单
        VM.ShowMeau();
        cout<<"请输入选项："<<endl;
        cin>>choice;
        switch (choice)
        {
             //退出管理程序
            case 0:
            VM.ExitSystem();
            break;
            //1.增加职工信息
            case 1:
            VM.Add_Emp();
            break;
            //2.显示职工信息
            case 2:
            VM.show_Emp();
            break;
            //3.删除离职职工
            case 3:
             VM.Del_Emp();
            break; 
            //4.修改职工信息
            case 4:
            VM.Mod_Emp();
            break;
            // 5.查找职工信息
            case 5:
            VM.Find_Emp();
            break;
            //6.按照编号排序
            case 6:
            VM.Sort_Emp();
            break;
            //7.清除所有文档
            case 7:
            VM.Clean_File();
            break;

            default:
            break;

        }
        



    }
    

    system("pause");
    return 0;
}