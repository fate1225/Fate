#include<iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
static int total=0;//职工总数
class TWorker
{
 public:
     void set_worker()//输入职工信息
  {
   cout<<"请输入职工编号:";   cin>>number;
      cout<<"请输入职工姓名:";   cin>>name;
  }
 protected:
  char name[18],number[18];
};
class TSalary
{
 public:
  void set_salary()//输入工资数
  {
   cout<<"请输入所得基本工资:";     cin>>BSalary;
   cout<<"请输入所得职务工资:";     cin>>ZSalary;
         cout<<"请输入所得津贴:";         cin>>bonus;
      cout<<"请输入医疗保险:";         cin>>Medical_insurance;
      cout<<"请输入公积金:";           cin>>fund;
  }
    protected:
  float BSalary,ZSalary,bonus,Medical_insurance,fund;
};
class TWorker_salary:public TWorker,public TSalary
{
    public:
     friend class Tmanage;//作为友元函数访问 
     void set_work_salary()
        {
       set_worker();
       set_salary();
  }
};
class Tmanage
{
 public:
  int Input();//输入职工的个人信息
  void Print();//输出职工信息
  void Update();//修改职工信息
  void Query();//查找职工信息
  void Delete();//删除职工信息
  void T_J();//统计职工在一定区域内的百分比
 private:
  TWorker_salary worker;
};
int Tmanage::Input()
{
 ofstream ofile("D:\\worker.txt",ios::app);    //以追加方式打开，防止输入的覆盖 
 if(!ofile)
 {
  cout<<"文件夹不能打开!"<<endl;
  return 0;
 }
 int n=1;
    while(n)//继续输入判断
    {
        worker.set_work_salary(); //输入职工信息 
        ofile<<setw(10)<<worker.number<<setw(10)<<worker.name<<setw(10)<<worker.BSalary<<setw(10)<<worker.ZSalary<<setw(10)<<worker.bonus<<setw(10)<<worker.Medical_insurance <<setw(10)<<worker.fund<<endl;//将输入信息写入文件中
        cout<<"输入成功！"<<endl;
        total++;  //统计输入职工的总个数 
        cout<<"继续输入请按1 / 退出请按0:";
        cin>>n;
    }
    ofile.close();//关闭文件
    return 0;
