#include<iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
static int total=0;//ְ������
class TWorker
{
 public:
     void set_worker()//����ְ����Ϣ
  {
   cout<<"������ְ�����:";   cin>>number;
      cout<<"������ְ������:";   cin>>name;
  }
 protected:
  char name[18],number[18];
};
class TSalary
{
 public:
  void set_salary()//���빤����
  {
   cout<<"���������û�������:";     cin>>BSalary;
   cout<<"����������ְ����:";     cin>>ZSalary;
         cout<<"���������ý���:";         cin>>bonus;
      cout<<"������ҽ�Ʊ���:";         cin>>Medical_insurance;
      cout<<"�����빫����:";           cin>>fund;
  }
    protected:
  float BSalary,ZSalary,bonus,Medical_insurance,fund;
};
class TWorker_salary:public TWorker,public TSalary
{
    public:
     friend class Tmanage;//��Ϊ��Ԫ�������� 
     void set_work_salary()
        {
       set_worker();
       set_salary();
  }
};
class Tmanage
{
 public:
  int Input();//����ְ���ĸ�����Ϣ
  void Print();//���ְ����Ϣ
  void Update();//�޸�ְ����Ϣ
  void Query();//����ְ����Ϣ
  void Delete();//ɾ��ְ����Ϣ
  void T_J();//ͳ��ְ����һ�������ڵİٷֱ�
 private:
  TWorker_salary worker;
};
int Tmanage::Input()
{
 ofstream ofile("D:\\worker.txt",ios::app);    //��׷�ӷ�ʽ�򿪣���ֹ����ĸ��� 
 if(!ofile)
 {
  cout<<"�ļ��в��ܴ�!"<<endl;
  return 0;
 }
 int n=1;
    while(n)//���������ж�
    {
        worker.set_work_salary(); //����ְ����Ϣ 
        ofile<<setw(10)<<worker.number<<setw(10)<<worker.name<<setw(10)<<worker.BSalary<<setw(10)<<worker.ZSalary<<setw(10)<<worker.bonus<<setw(10)<<worker.Medical_insurance <<setw(10)<<worker.fund<<endl;//��������Ϣд���ļ���
        cout<<"����ɹ���"<<endl;
        total++;  //ͳ������ְ�����ܸ��� 
        cout<<"���������밴1 / �˳��밴0:";
        cin>>n;
    }
    ofile.close();//�ر��ļ�
    return 0;
