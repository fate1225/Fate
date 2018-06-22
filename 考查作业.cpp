// 课程考察.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include<iostream>
using namespace std;
#define NUM 100      //系统容量
void enter();        //输入职工工资数据函数
int read();          //读取职工工资数据函数
void write(int);     //保存职工工资数据函数
void find();         //查询职工工资数据函数
void list();         //浏览职工工资数据函数
void modify();       //修改职工工资数据函数
void del();          //删除职工工资数据函数
void add();          //添加职工工资数据函数
void grsds();        //计算个人所得税函数
void menu();         //主页菜单
int n;               //职工总数
struct employee      //职工数据结构
{
 char number[11];    //1~10位数字
 char name[11];      //1~10个字母或1~5个汉字
 float gwgz;         //岗位工资                   
 float xjgz;         //薪级工资                   
 float zwjt;         //职务津贴                  
 float jxgz;         //绩效工资                   
 float yfgz;         //应发工资                   
 float sui;          //个人所得税
 float sfgz;         //实发工资                   
}zggz[NUM];
void menu()
{
      printf("************* 职工工资管理系统 **************\n");
      printf("*            1-----输入职工信息             *\n");
	  printf("*            2-----查询职工信息             *\n");
      printf("*            3-----修改职工信息             *\n");
      printf("*            4-----添加职工信息             *\n");
      printf("*            5-----删除职工信息             *\n");
      printf("*            6-----浏览全部职工             *\n");
      printf("*            7-----保存职工信息             *\n");
      printf("*            8-----退出程序                 *\n");
      printf("*********************************************\n");
     
}
int main()
{
	int n,flag;
	while(1)
	{
		do
		{
			menu();	
			cout<<"       输入您的选择(1-8):[ ]\b\b";
			cin>>n;
			if(n>=1&&n<=8)
			{
				flag=1;
				break;
			}
			else
			{
				flag=0;
				cout<<"请输入正确选项！"<<endl;
			}
		}
	while(flag==0);
	switch(n)
	{
		case 1: enter(); break;
	    case 2: find(); break;
	    case 3: modify(); break;
	    case 4: add(); break;
	    case 5: del(); break;
	    case 6: list(); break;
	    //case 7: write(m); break; 
        case 8:printf("\n×××××××欢迎下次使用×××××××\n\n");
        default:exit(0);  //退出系统,exit(0)函数功能是退出程序。
	}
	}
	return 0;
}
//======================输入模块======================完成
void enter()
{
	int i,m;
	cout<<"请输入需要输入的职工人数(1--100)：";
	cin>>m;
	for(i=0;i<m;i++)
	{
		cout<<"职工工号：";
		cin>>zggz[i].number;
		cout<<"职工姓名：";
		cin>>zggz[i].name;
		cout<<"岗位工资：";
		cin>>zggz[i].gwgz;
		cout<<"薪级工资：";
		cin>>zggz[i].xjgz;
		cout<<"职务津贴：";
		cin>>zggz[i].zwjt;
		cout<<"绩效工资：";
		cin>>zggz[i].jxgz;
		cout<<"应发工资：";
		cin>>zggz[i].yfgz;
		cout<<"个人所得税：";
		cin>>zggz[i].grsds;
		cout<<"实发工资：";
		cin>>zggz[i].sfgz;
		zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz+zggz[i].yfgz+zggz[i].grsds+zggz[i].sfgz+zggz[i];
	}
	cout<<"职工信息录入成功！";
	system("cls");
	write(m);
}
//======================保存模块======================
void write(int m)
{
	int i;
	FILE *fp;
	if ((fp=fopen("gz.dat","wb"))==NULL) 
	{
		cout<<"无法打开文件"<<endl;
		exit(0);
	}
   for (i=0;i<m;i++)                        /*将内存中职工的信息输出到磁盘文件中去*/
   if (fwrite(&zggz,sizeof(struct employee),1,fp)!=1)   //如果没有正确写入
   printf("file write error\n");
   fclose(fp);

}
//======================读取模块======================完成
int read()
{
	FILE *fp;
	int i=0;
	if((fp=fopen("gz.dat","rb"))==NULL)
	{
		cout<<"无法打开文件"<<endl;
		exit(0);
	}
	else
	{
		do
		{
			fread(&zggz,sizeof(struct employee),1,fp);
			i++;
		}
		while(feof(fp)==0);
	}
	fclose(fp);
	return(i-1);
}
//======================浏览模块======================完成
void list()
{
	int i;
	int m=read();
	cout<<"工号  姓名  岗位工资  薪级工资  职务津贴  绩效工资  应发工资   个人所得税   实发工资"<<endl;
	for(i=0;i<m;i++)
	{
		cout<<zggz[i].number<<"     "
			<<zggz[i].name<<"     "
			<<zggz[i].gwgz<<"     "
			<<zggz[i].xjgz<<"     "
			<<zggz[i].zwjt<<"     "
			<<zggz[i].jxgz<<"     "
			<<zggz[i].yfgz<<
			<<zggz[i].grsds<<
			<<zggz[i].sfgz<<endl;
	}
	cout<<"按任意键继续";
	getchar();
	getchar();
	system("cls");
}
//======================删除模块======================
void del()
{
	int m=read();
	int i,j,n,t,flag;
	char gonghao[12];
	cout<<"当前职工信息："<<endl;
	list();
	cout<<endl;
	cout<<"请输入要删除的职工工号：";
	cin>>gonghao[12];
	for(flag=1,i=0;flag&&i<m;i++)
	{
		if(strcmp(zggz[i].number,gonghao)==0)
		{
			cout<<"要删除的职工信息："<<endl;
			cout<<"工号  姓名  岗位工资  薪级工资  职务津贴  绩效工资  应发工资   个人所得税   实发工资"<<endl;
			cout<<zggz[i].number<<" "<<zggz[i].name<<" "<<zggz[i].gwgz<<" "<<zggz[i].xjgz<<" "<<zggz[i].zwjt<<" "<<zggz[i].jxgz<<" "<<zggz[i].yfgz<<endl;
		    cout<<"确认删除请按1，放弃删除请按0"<<endl;
		    cin>>n;
		    if(n==1)                               //从该记录开始每条记录向前移一条记录
		    {
			for(j=i;j<m;j++)
			{
				zggz[j]=zggz[j+1];
			}
		    }
		flag=0;		
	    }
	}
	if(!flag)
	{
		m=m-1;
	}
	else
	{
		cout<<"查无此人"<<endl;
	}
	cout<<"当前所有职工信息"<<endl;
	write(m);
	list();
	cout<<"继续删除请按1，不在删除请按2"<<endl;
	cin>>t;
	switch(t)
	{
	    case 1:del(); break;
		case 2:break;
		default:break;
	}
	system("cls");
}

//======================查询模块======================完成
void find()
{
	int t,i;
	int m=read();
	char gonghao[11];
	cout<<"请输入想要查询的职工工号"<<endl;
	cin>>gonghao;
	for(i=0;i<m;i++)
	{
		if(strcmp(gonghao,zggz[i].name)==0)
		{
			cout<<"你要查找的人是："<<endl;
			cout<<"工号  姓名  岗位工资  薪级工资  职务津贴  绩效工资  应发工资   个人所得税   实发工资"<<endl;
			cout<<zggz[i].number<<"     "
			    <<zggz[i].name<<"     "
			    <<zggz[i].gwgz<<"     "
			    <<zggz[i].xjgz<<"     "
			    <<zggz[i].zwjt<<"     "
			    <<zggz[i].jxgz<<"     "
			    <<zggz[i].yfgz<<
				<<zggz[i].grsds<<
			    <<zggz[i].sfgz<<endl;
			break;
		}
	}
	if(i==m)
	{
		cout<<"查无此人"<<endl;
	}
	cout<<"继续查询请按1，返回请按2"<<endl;
	cin>>t;
	switch(t)
	{
	    case 1:find(); break;
		case 2: system("cls"); break;
		default:break;
	}
}
//======================修改模块======================
void modify()
{
	 char num[11];    //1~10位数字
     char nam[11];      //1~10个字母或1~5个汉字
     float Gwgz;         //岗位工资                   
     float Xjgz;         //薪级工资                   
     float Zwjt;         //职务津贴                  
     float Jxgz;         //绩效工资                                    
	 int b,c,i,n,t,flag;
	 char gonghao[20];
	 int m=read();
	 cout<<"当前职工信息："<<endl;
	 list();
	 cout<<"请输入要修改的职工工号：";
	 cin>>gonghao[20];
	 for(flag=1,i=0;flag&&i<m;i++)
	 {
		 if(strcmp(zggz[i].number,gonghao)==0)
		{
			cout<<"要修改的职工信息："<<endl;
			cout<<"工号  姓名  岗位工资  薪级工资  职务津贴  绩效工资  应发工资   个人所得税   实发工资"<<endl;
			cout<<zggz[i].number<<"     "
			    <<zggz[i].name<<"     "
			    <<zggz[i].gwgz<<"     "
			    <<zggz[i].xjgz<<"     "
			    <<zggz[i].zwjt<<"     "
			    <<zggz[i].jxgz<<"     "
			    <<zggz[i].yfgz<<
				<<zggz[i].grsds<<
			    <<zggz[i].sfgz<<endl;
	 	cout<<"确认要修改这名职工请按1，放弃修改请按0"<<endl;
		cin>>n;
		if(n==1)
		{
			cout<<"请输入要修改的选项：1.工号 2.姓名 3.岗位工资  4.薪级工资 5.职务津贴  6.绩效工资  7.应发工资  8.个人所得税  9.实发工资 "<<endl;
			cin>>c;
			if(c>6||c<1)
			{
				cout<<"选择错误请重新输入"<<endl;
			}	
		}
		flag=0;
		}
	 }
	 if(flag==1)
	 {
		 cout<<"查无此人"<<endl;
	 }
		 do
		 {
			 switch(c)          //当找到第i个职工时,for语句后i自加了1,所以下面的应该把改后的信息赋值给第i-1个人
			 {
			    case 1:
					   cout<<"工号改为：";
					   cin>>num[11];
					   strcpy(zggz[i-1].number,num);
					   break;
				case 2:
					   cout<<"姓名改为：";
					   cin>>nam[11];
					   strcpy(zggz[i-1].name,nam);
					   break;
				case 3:
					   cout<<"岗位工资改为：";
					   cin>>Gwgz;
					   zggz[i-1].gwgz=Gwgz;
					   break;
			    case 4:
					   cout<<"薪级工资改为：";
					   cin>>Xjgz;
					   zggz[i-1].xjgz=Xjgz;
					   break;
				case 5:
					   cout<<"职务津贴改为：";
					   cin>>Zwjt;
					   zggz[i-1].zwjt=Zwjt;
					   break;
				case 6:
					   cout<<"绩效工资改为：";
					   cin>>Jxgz;
					   zggz[i-1].jxgz=Jxgz;
					   break;
                case 7:
					   cout<<"应发工资改为：";
					   cin>>Yfgz;
					   zggz[i-1].yfgz=Yfgz;
					   break;
				case 8:
					   cout<<"个人所得税改为：";
					   cin>>Grsds;
					   zggz[i-1].grsds=Grsds;
					   break;
				case 9:
					   cout<<"实发工资改为：";
					   cin>>Sfgz;
					   zggz[i-1].sfgz=Sfgz;
					   break;
			 }
			 cout<<endl;
			 cout<<"确认请按1，重新修改请按2"<<endl;
			 cin>>b;
		 }
		 while(b==1);
		 {
			 cout<<"修改后的所有职工信息为："<<endl;
			 write(m);
			 list();
		 }
		 cout<<"继续修改请按1";
		 cin>>t;
		 switch(t)
			{
			     case 1:modify(); break;
				 default:break;
			 }
		 system("cls");
}
//======================添加模块======================完成
void add()
{
	FILE *fp;
	int n,i,j;
	if((fp=fopen("gz.dat","ab+"))==NULL)
	{
		cout<<"无法打开gx文件"<<endl;
		exit(0);
	}
	cout<<"要添加的职工人数：";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"职工号：";
		cin>>zggz[i].number;
		cout<<"姓名：";
		cin>>zggz[i].name;
		cout<<"岗位工资：";
		cin>>zggz[i].gwgz;
		cout<<"薪级工资：";
		cin>>zggz[i].xjgz;
		cout<<"职务津贴：";
		cin>>zggz[i].zwjt;
		cout<<"绩效工资：";
		cin>>zggz[i].jxgz;
		cout<<"应发工资：";
		cin>>zggz[i].yfgz;
		cout<<"个人所得税：";
		cin>>zggz[i].grsds;
		cout<<"实发工资：";
		cin>>zggz[i].sfgz;
		zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjgz+zggz[i].zwjt+zggz[i].jxgz+zggz[i].yfgz+zggz[i].grsds+zggz[i].sfgz+zggz[i];
		fwrite(&zggz,sizeof(struct employee),1,fp);
	}
	cout<<"添加成功"<<endl;
	system("cls");
	fclose(fp);
}
