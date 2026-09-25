#pragma once//防止头文件重复包含
#include "iostream"
#include  "string"
#include "woker.h"
#include <fstream>
//用纯 ASCII 的绝对路径固定数据文件位置，彻底避免：
// 1. 相对路径"从哪个目录启动"导致找不到文件
// 2. fstream 打开含中文的路径时（UTF-8源码 vs GBK系统编码）打不开
#define FILENAME "D:/vscoding/empFlie.txt"
using namespace std;

class WorkManger
{
public:
//管理类的构造函数
WorkManger();
//菜单界面
void ShowMeau();
//退出系统
void ExitSystem();
//记录职工人数
int m_EmpNum;
//职工数组指针
Worker **m_EmpArray;
//添加职工
void Add_Emp();
//保存文件
void save();
//判断文件是否为空
bool m_FileIsEmpty;
//统计文件中的人数
int get_EmpNum();
//初始化员工
void init_Emp();
//显示职工信息
void show_Emp();
//删除职工
void Del_Emp();
//公告函数，按照职工编号判断职工是否存在，若存在返回职工在数组中的位置，不存在返回-1
int IsExist(int id);
//修改职工
void Mod_Emp();
//查找职工
void Find_Emp();
//排序，按照职工编号进行排序，排序顺序由用户指定
void Sort_Emp();
//清空文件
void Clean_File();
//析构函数
~WorkManger();


};
