#include"workManger.h"
#include"employee.h"
#include "manger.h"
#include "boss.h"
#include "woker.h"



WorkManger::WorkManger()
{
  //1.文件不存在
  ifstream ifs;
  ifs.open(FILENAME,ios::in);
  if(!ifs.is_open())
  {
    cout<<"文件不存在"<<endl;
      this->m_EmpNum=0;//初始化属性  记录人数
      this->m_EmpArray=NULL;//初始化数组指针
      this->m_FileIsEmpty=true;//初始化文件是否为空
    ifs.close();
    return ;
  }

  //2.文件存在数据为空
  char ch;
  ifs >>ch;
  if(ifs.eof())
  {
    //文件为空
    cout<<"文件为空"<<endl;
    this->m_EmpNum=0;//初始化属性  记录人数
    this->m_EmpArray=NULL;//初始化数组指针
    this->m_FileIsEmpty=true;//初始化文件是否为空
    ifs.close();
    return;
  }
  //3.文件存在，并且记录数据
  int num=this->get_EmpNum();
  
  this->m_EmpNum=num;
  this->m_FileIsEmpty=false;//文件有数据，标记不为空
  //开辟空间
  this->m_EmpArray=new Worker*[this->m_EmpNum];
  //将文件中的数据，存到数组中
  this->init_Emp();
  /*for(int i=0;i<this->m_EmpNum;i++)
  {
    cout<<"职工编号:"<<this->m_EmpArray[i]->m_Id
        <<"姓名："<<this->m_EmpArray[i]->m_Name
        <<"岗位编号:"<<this->m_EmpArray[i]->m_DeptId<<endl;
  }
*/
}
//显示菜单
void WorkManger::ShowMeau()
{
  cout<<"------------------------"<<endl;
  cout<<"-----0.退出管理程序-----"<<endl;
  cout<<"-----1.增加职工信息-----"<<endl;
  cout<<"-----2.显示职工信息-----"<<endl;
  cout<<"-----3.删除离职职工-----"<<endl;
  cout<<"-----4.修改职工信息-----"<<endl;
  cout<<"-----5.查找职工信息-----"<<endl;
  cout<<"-----6.按照编号排序-----"<<endl;
  cout<<"-----7.清除所有文档-----"<<endl;
  cout<<"------------------------"<<endl;
}
//退出系统
void WorkManger::ExitSystem()
{
  cout<<"欢迎下次使用"<<endl;
  system("pause");
  exit(0);// ← 直接结束整个程序
}
void WorkManger::Add_Emp()
{
  cout<<"请输入需要添加的职工人数:"<<endl;
  int addNum=0;//保存用户的输入数量
  cin>>addNum;
  if(addNum>0)
  {
    //计算新空间大小
    int newSize=this->m_EmpNum+addNum;
    //开辟新空间
    Worker** newSpace=new Worker*[newSize];
    //将原来空间下的数据  拷贝到新空间下
    if(this->m_EmpArray!=NULL)
    {
      for(int i=0;i<this->m_EmpNum;i++)
      {
        newSpace[i]=this->m_EmpArray[i];
      }
    }
    //添加新数据
     for(int i=0;i<addNum;i++)
     {
      int  id;//职工编号
      string name;//职工姓名
      int dSelect; //部门选择
      cout<<"请输入第"<<i+1<<"个员工信息"<<endl;
      cout<<"请输入第"<<i+1<<"个新员工的编号:";
      cin>>id;
      cout<<"请输入第"<<i+1<<"个新员工的姓名:";
      cin>>name;

      cout<<"请选择该职工的岗位:"<<endl;
      cout<<"1.普通职工"<<endl;
      cout<<"2.经理"<<endl;
      cout<<"3.老板"<<endl;
    
      cin>>dSelect;

      Worker* worker=NULL;
      switch (dSelect) 
      { 
        case 1:
        worker=new Employee(id,name,1);
        break;
        case 2:
        worker=new Manger(id,name,2);
        break;
        case 3:
        worker=new Boss(id,name,3);
        break;
      
      
      default:
        break;
      }
     //将创建的职工  保存到数组中
     newSpace[this->m_EmpNum+i]=worker;

     }
     //释放原有空间
     delete[]this->m_EmpArray;
     //更新数组指针指向新空间
     this->m_EmpArray=newSpace;
     //更新职工人数
     this->m_EmpNum=newSize;
     //提示添加成功
     this->m_FileIsEmpty=false;
     cout<<"添加成功"<<addNum<<"名职工"<<endl;
     //保存数据
     this->save();
  }
  else
  {
    cout<<"输入有误"<<endl;
  }
  system("pause");
  system("cls");
}
void WorkManger::save()
{
  ofstream ofs;//创建流对象
  ofs.open(FILENAME,ios::out);//打开文件 ofs.open("文件路径",打开方式);
//写数据 ofs << "写入的数据"    将每个人的数据写入到文件中
  for(int i=0;i<m_EmpNum;i++)
  {
   ofs<<this->m_EmpArray[i]->m_Id<<"  "
      <<this->m_EmpArray[i]->m_Name<<" "
      <<this->m_EmpArray[i]->m_DeptId<<endl;
  }
  ofs.close();//关闭文件
}
int WorkManger::get_EmpNum()
{
  ifstream ifs;
  ifs.open(FILENAME,ios::in);

  int id;
  string name;
  int did;
  int num=0;
  while(ifs>>id&&ifs>>name&&ifs>>did)
  {
    //统计添加的人数
    num++;
  }
   return num;
}
void WorkManger::init_Emp()
{
   ifstream ifs;
  ifs.open(FILENAME,ios::in);

  int id;
  string name;
  int did;

  int index=0;
  while(ifs>>id&&ifs>>name&&ifs>>did)
  {
    Worker *worker=NULL;
    if(did==1)
    {
       worker=new Employee(id,name,did);
    }
    else if(did==2)
    {
      worker=new Manger(id,name,did);
    }
    else 
    {
      worker=new Boss(id,name,did);
    }
     this->m_EmpArray[index]=worker;
     index++;
  }
  ifs.close();//关闭文件
}
void WorkManger::show_Emp()
{
  //判断文件是否为空
  if(this->m_FileIsEmpty)
  {
    cout<<"文件不存在或为空"<<endl;

  }
  else
  {
    for(int i=0;i<m_EmpNum;i++)
    {
      //利用多态调用程序接口；
      this->m_EmpArray[i]->showinfo();
    }
  }
  system("pause");
  system("cls");
}
void WorkManger::Del_Emp()
{

  if(this->m_FileIsEmpty)
  {
    cout<<"文件不存在或记录为空"<<endl;

  }
  else
  {
    //按照职工编号删除
    cout<<"请输入想要删除的职工编号"<<endl;
    int id=0;
    cin>>id;
    int index=this->IsExist(id);
    if(index!=-1)//职工存在，执行删除操作
    {
      //数据前移
     for(int i=index;i<this->m_EmpNum;i++)
     {
      this->m_EmpArray[i]=this->m_EmpArray[i+1];
     }
     //更新数组中的人数
     this->m_EmpNum--;
     //同步更新到文件里
     this->save();
    }
    else
     {
    cout<<"删除失败，未找到该员工"<<endl;
     }
  
  }
  system("pause");
  system("cls");
}
//判断职工是否存在，不存在则返回-1
int WorkManger::IsExist(int id)
{
 
  int index=-1;
  for(int i=0;i<this->m_EmpNum;i++)
  {
    if(this->m_EmpArray[i]->m_Id==id)
    {
      index=i;
      break;
    }
  }
  return index;

}
//修改职工信息
void WorkManger::Mod_Emp()
{
  if(this->m_FileIsEmpty)
    {
     cout<<"文件不存在"<<endl;
    }
    else
    {
      int id;
      cout<<"请输入要修改的编号"<<endl;
      cin>>id;
      int ret=this->IsExist(id);
      if(ret!=-1)
      {
        //查找到该编号员工
        delete this->m_EmpArray[ret];
        int newid=0;
        string newname="";
        int newdid=0;

        cout<<"查找到："<<id<<"号员工，请输入新的职工号："<<endl;
         cin>>newid;

        cout<<"请输入姓名:"<<endl;
        cin>>newname;

        cout<<"请输入新的岗位编号:"<<endl;
        cout<<"1.普通员工"<<endl;
        cout<<"2.经理"<<endl;
        cout<<"3.总裁"<<endl;
        int dSelect=0;
        cin>>dSelect;
        
        Worker *worker=NULL;
        switch (dSelect)
        {
          case 1:
          worker=new Employee(newid,newname,dSelect);
          break;
          case 2:
          worker=new Manger(newid,newname,dSelect);
          break;
          case 3:
          worker=new Boss(newid,newname,dSelect);
           break;
        default:
          break;
        }
        //更新到数组中
        this->m_EmpArray[ret]=worker;
        cout<<"修改成功"<<endl;
        //保存到文件中
        this->save();
      }
      else{
        cout<<"查无此人"<<endl;
      }
     
    }
    system("pause");
    system("cls");
}
void WorkManger::Find_Emp()
{
  if(this->m_FileIsEmpty)
  {
    cout<<"文件不存在或记录为空"<<endl;

  }
  else
  {
    cout<<"请输入查找方式"<<endl;
    cout<<"1.按照职工编号查找"<<endl;
    cout<<"2.按照职工姓名查找"<<endl;
    int select;
    cin>>select;
    if(select==1)
    {
      int id;
      cout<<"请输入职工编号："<<endl;
      cin>>id;

      int ret=this->IsExist(id);
      if(ret!=-1)
      {
        cout<<"查找成功，该员工的信息如下："<<endl;
        this->m_EmpArray[ret]->showinfo();
      }
      else
      {
        cout<<"查找失败"<<endl;
      }
    }
    else if(select==2)
    {
       cout<<"请输入要查找的姓名："<<endl;
       string name;
       cin>>name;
      //加入判断是否查到的标志
       bool flag=false;
       for(int i=0;i<m_EmpNum;i++)
       {
        if(this->m_EmpArray[i]->m_Name==name)
        {
          cout<<"查到该员工，职工编号为:"<<this->m_EmpArray[i]->m_Id<<"号员工的信息如下："<<endl;
         //调用显示信息接口
          this->m_EmpArray[i]->showinfo();
             flag=true;
        }
        if(flag==false)
        {
          cout<<"查找失败，查无此人"<<endl;
        }
       }
    }
    else
    {
      cout<<"输入有误，请重新输入"<<endl;
    }
  }
  system("pause");
  system("cls");
}
void WorkManger::Sort_Emp()
{
   if(this->m_FileIsEmpty)
   {
    cout<<"文件不存在或记录为空"<<endl;
    system("pause");
    system("cls");
   }
   else
   {
    cout<<"输入排序方式："<<endl;
    cout<<"1.降序排列"<<endl;
    cout<<"2.升序排列"<<endl;
    int select=0;
    cin>>select;


    if(select==2)
    {
      //升序排列
      for(int i=0;i<this->m_EmpNum;i++)
      {
        
        for(int j=0;j<this->m_EmpNum-1;j++)
        {
          if(this->m_EmpArray[j]->m_Id > this->m_EmpArray[j+1]->m_Id)
          {
            Worker *temp=this->m_EmpArray[j];
            this->m_EmpArray[j]=this->m_EmpArray[j+1];
            this->m_EmpArray[j+1]=temp;
          }

        }
      }
    }
    else if(select==1)
    {
      //降序排列
      for(int i=0;i<this->m_EmpNum;i++)
      {
        
        for(int j=0;j<this->m_EmpNum-1;j++)
        {
          if(this->m_EmpArray[j]->m_Id < this->m_EmpArray[j+1]->m_Id)
          {
            Worker *temp=this->m_EmpArray[j];
            this->m_EmpArray[j]=this->m_EmpArray[j+1];
            this->m_EmpArray[j+1]=temp;
          }

        }
      }
    
    }
  else
  {
    cout<<"输入有误请重新输入："<<endl;
  }
  cout<<"排序成功，排序后结果为:"<<endl;
  this->save();
  this->show_Emp();
 }
 
}
void WorkManger::Clean_File()
{
  cout<<"确定清空？"<<endl;
  cout<<"1.确定"<<endl;
  cout<<"2.返回"<<endl;
  int select=0;
  cin>>select;

  if(select==1)
  {
    //清空文件
        ofstream ofs(FILENAME,ios::trunc);//删除文件 重新创建
        ofs.close();

        if(this->m_EmpArray!=NULL)
        {//删除堆区的每个职工对象
          for(int i=0;i<m_EmpNum;i++)
          {
           delete this->m_EmpArray[i];
              this->m_EmpArray[i]=NULL;
            
          }
          //删除堆区数组指针
          delete [] this->m_EmpArray;
          this->m_EmpArray=NULL;
          this->m_EmpNum=0;
          this->m_FileIsEmpty=true;

        }
        cout<<"清空成功"<<endl;

  }
  system ("pause");
  system ("cls");
}
WorkManger::~WorkManger()
{
  //释放每个职工对象
  if(this->m_EmpArray!=NULL)
  {
    for(int i=0;i<this->m_EmpNum;i++)
    {
      if(this->m_EmpArray[i]!=NULL)
      {
        delete this->m_EmpArray[i];
        this->m_EmpArray[i]=NULL;
      }
    }
    //释放数组本身
    delete[] this->m_EmpArray;
    this->m_EmpArray=NULL;
  }
}
