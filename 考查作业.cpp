#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<iomanip>
using namespace std;

int n=0;	//记录职工人数

//声明自定义的相关函数
void read();
void write();
void find();
void list();
void modify();
void del();
void add();
float grsd(float v);

struct zhigong		//职工数据结构
{   char number[10];
    char name[10];
    float post_wage;		//员工的岗位工资
    float pay_salary;		//员工的薪级工资
    float duty_allowance;	//员工的政务津贴
    float merit_pay;		//绩效工资
    float gross_pay;		//应发工资
    float income_tax;		//个人所得税
    float payroll;			//实发工资
    
};
struct zhigong zggz[100];	//声明记录职工工资情况的100个元素的结构体

void read()		//从文件中读取数据
{
    FILE*Read=fopen("gx.dat","ab+");
    if(Read)	//文件打开成功
    {   
        while(!feof(Read))
        {
            char lock=fgetc(Read);		
            if(lock!=EOF)	//检测文件末尾是否为空字符
            {
                fscanf(Read,"%s%s%f%f%f%f%f%f%f",
					&zggz[n].number,&zggz[n].name,&zggz[n].post_wage,
					&zggz[n].pay_salary,&zggz[n].duty_allowance,&zggz[n].merit_pay,
					&zggz[n].gross_pay,&zggz[n].income_tax,&zggz[n].payroll);
                n++;
            }	//将n个职工记录写入文件
        }
        fclose(Read);
    }
    else
    {
        printf("\n文件打开失败！");
    }
    
}


void write()		//保存文件函数
{
    FILE*DF_05=fopen("gx.dat","wb");
    if(DF_05)
    {   
         for(int i=0;i<n;i++)	//在职工限定人数内循环
        {
            fprintf(DF_05,"\t%-10s%-10s%-10f\t%-10f\t%-10f\t%-10f\t%-10f\t%-10f\t%-10f",
				zggz[i].number,zggz[i].name,zggz[i].post_wage,
                zggz[i].pay_salary,zggz[i].duty_allowance,zggz[i].merit_pay,
				zggz[i].gross_pay,zggz[i].income_tax,zggz[i].payroll);
        }
        fclose(DF_05);
        printf("\n文件保存成功！");
    }
    else
    {
        printf("\n文件打开失败！");
    }
    printf("\n按任意键返回主菜单");
    if(getch())
    {   
        return;
    }
}

void find()		//查询职工信息函数
{	
	int i;
    char gonghao[10];
    printf("请输入查询的工号");
    scanf("%s",gonghao);
    for(i=0;i<n;i++)	//在职工限定人数内循环
    {   
        if(strcmp(gonghao,zggz[i].number)==0)	//检测输入的工号是否与文件中的工号相同	
        {
            printf("-------------------------------该职工工资信息如下------------------------------");
            printf( "丨职工工号:%-15s丨职工姓名:%-15s丨岗位工资:%-15f\n"
                    "丨薪级工资:%-15f丨职务津贴:%-15f丨绩效工资:%-15f\n"
                    "丨应发工资:%-15f丨个人所得税:%-13f丨实发工资:%-15f\n",
                zggz[i].number, zggz[i].name, zggz[i].post_wage, 
                zggz[i].pay_salary, zggz[i].duty_allowance, zggz[i].merit_pay, 
                zggz[i].gross_pay, zggz[i].income_tax, zggz[i].payroll);
            i=1;
        }
    }
    if(!i)
    {
    printf("您所输入的职工工号有误或不存在！");
    }

    printf("\n按任意键返回主菜单");
    if(getch())
    {   
        return;
    }
    
}

void list()		//浏览职工信息函数
{
	if(n==0)
	{
		printf("目前职工数为0");
	}
    else
	{
		printf("------------------------------全体职工工资信息如下------------------------------\n");
		for(int i=0;i<n;i++)	//在职工限定人数内循环
		{
			printf( "丨职工工号:%-15s丨职工姓名:%-15s丨岗位工资:%-15f\n"
					"丨薪级工资:%-15f丨职务津贴:%-15f丨绩效工资:%-15f\n"
					"丨应发工资:%-15f丨个人所得税:%-13f丨实发工资:%-15f\n\n",
					zggz[i].number, zggz[i].name, zggz[i].post_wage, 
					zggz[i].pay_salary, zggz[i].duty_allowance, zggz[i].merit_pay, 
					zggz[i].gross_pay, zggz[i].income_tax, zggz[i].payroll);
		}
	}

    printf("\n按任意键返回主菜单");
    if(getch())
    {   
        return;
    }
}

void modify()	//修改职工信息函数
{
    char gonghao[10];
    printf("请输入查询的工号");
    scanf("%s",gonghao);

	int i;
    for(i=0;i<n;i++)	//在职工限定人数内循环
    {
        if(strcmp(zggz[i].number,gonghao)==0)	//检测输入的工号是否与文件中的工号相同
        {
            printf("-------------------------------该职工工资信息如下-------------------------------");
            printf( "丨职工工号:%-15s丨职工姓名:%-15s丨岗位工资:%-15f\n"
                    "丨薪级工资:%-15f丨职务津贴:%-15f丨绩效工资:%-15f\n"
                    "丨应发工资:%-15f丨个人所得税:%-13f丨实发工资:%-15f\n",
                    zggz[i].number, zggz[i].name, zggz[i].post_wage, 
                    zggz[i].pay_salary, zggz[i].duty_allowance, zggz[i].merit_pay, 
                    zggz[i].gross_pay, zggz[i].income_tax, zggz[i].payroll);        

            printf("请输入该职工新的岗位工资：");
            scanf("%f",&zggz[i].post_wage);
            printf("\n请输入该职工新的薪级工资：");
            scanf("%f",&zggz[i].pay_salary);
            printf("\n请输入该职工新的政务津贴：");
            scanf("%f",&zggz[i].duty_allowance);
            printf("\n请输入该职工新的绩效工资：");
            scanf("%f",&zggz[i].merit_pay);
    
            zggz[i].gross_pay=zggz[i].post_wage+zggz[i].pay_salary+zggz[i].duty_allowance+zggz[i].merit_pay;    //计算应发工资
            zggz[i].income_tax=grsd(zggz[i].gross_pay);    //计算个人所得税
            zggz[i].payroll=zggz[i].gross_pay-zggz[i].income_tax;    //计算应发工资

            printf("---------------------------该职工修改后的工资信息如下---------------------------");
            printf( "丨职工工号:%-15s丨职工姓名:%-15s丨岗位工资:%-15f\n"
                    "丨薪级工资:%-15f丨职务津贴:%-15f丨绩效工资:%-15f\n"
                    "丨应发工资:%-15f丨个人所得税:%-13f丨实发工资:%-15f\n",
                    zggz[i].number, zggz[i].name, zggz[i].post_wage, 
                    zggz[i].pay_salary, zggz[i].duty_allowance, zggz[i].merit_pay, 
                    zggz[i].gross_pay, zggz[i].income_tax, zggz[i].payroll);  
			i=1;
        }
    }

	if(!i)
    {
    printf("您所输入的职工工号有误或不存在！");
    }
    printf("\n按任意键返回主菜单");
    
    printf("\n按任意键返回主菜单");
    if(getch())
    {   
        return;
    }
}

void del()		//删除职工信息函数
{
    char gonghao[10];
    cout<<"请输入要删除的职工号";
    scanf("%s",gonghao);
   
	int i;
    for(i=0;i<n;i++)	//在职工限定人数内循环
    {
        if(strcmp(zggz[i].number,gonghao)==0)	//检测输入的工号是否与文件中的工号相同
        {
            printf("--------------------------------查到该职工工资信息如下--------------------------------\n");;
            printf( "丨职工工号:%-15s丨职工姓名:%-15s丨岗位工资:%-15f\n"
                    "丨薪级工资:%-15f丨职务津贴:%-15f丨绩效工资:%-15f\n"
                    "丨应发工资:%-15f丨个人所得税:%-13f丨实发工资:%-15f\n",
                    zggz[i].number, zggz[i].name, zggz[i].post_wage, 
                    zggz[i].pay_salary, zggz[i].duty_allowance, zggz[i].merit_pay, 
                    zggz[i].gross_pay, zggz[i].income_tax, zggz[i].payroll);
			int i=1;
            printf("你真的要删除这个职工的工资信息？\n");
            printf("是，请按1\t\t否，请按2\n");
            int flg;
            scanf("%d",&flg);
            if(flg==1)
            {
                for(int j=i;j<n-1;j++)
                {
                    zggz[j]=zggz[j+1];		//将职工工资信息往前移
                }
                strcpy(zggz[n-1].number, " "); 
                strcpy(zggz[n-1].name, " "); 
                zggz[n-1].post_wage=0; 
                zggz[n-1].pay_salary=0;
                zggz[n-1].duty_allowance=0; 
                zggz[n-1].merit_pay=0;
                zggz[n-1].gross_pay=0;
                zggz[n-1].income_tax=0;
                zggz[n-1].payroll=0;	//将最后一个职工工资信息清零
                n=n-1;
                printf("这条记录已成功删除");
            }
            else if(flg==2)
            {
                printf("取消删除这条记录");
            }
        }
    }
	if(!i)
    {
    printf("您所输入的职工工号有误或不存在！");
    }
  
    printf("\n按任意键返回主菜单");
    if(getch())
    {   
        system("cls");
        return;
    }
    
}

void add()		//添加职工工资信息函数
{
    n=n+1;		//职工人数加一
    printf("请输入该职工的职工工号,职工姓名,岗位工资,薪级工资,政务津贴,绩效工资\n");
    scanf("%s%s%f%f%f%f",
		&zggz[n-1].number,&zggz[n-1].name,&zggz[n-1].post_wage,
		&zggz[n-1].pay_salary,&zggz[n-1].duty_allowance,&zggz[n-1].merit_pay);

    zggz[n-1].gross_pay=zggz[n-1].post_wage + zggz[n-1].pay_salary + zggz[n-1].duty_allowance + zggz[n-1].merit_pay;    //计算应发工资
    zggz[n-1].income_tax=grsd(zggz[n-1].gross_pay);    //计算个人所得税
    zggz[n-1].payroll=zggz[n-1].gross_pay - zggz[n-1].income_tax;    //计算应发工资

    printf( "------------------------添加成功，这个职工的信息为：------------------------\n");
    printf( "丨职工工号:%-15s丨职工姓名:%-15s丨岗位工资:%-15f\n"
            "丨薪级工资:%-15f丨职务津贴:%-15f丨绩效工资:%-15f\n"
            "丨应发工资:%-15f丨个人所得税:%-13f丨实发工资:%-15f\n",
            zggz[n-1].number,zggz[n-1].name,zggz[n-1].post_wage,
            zggz[n-1].pay_salary,zggz[n-1].duty_allowance,zggz[n-1].merit_pay,
            zggz[n-1].gross_pay,zggz[n-1].income_tax,zggz[n-1].payroll);

    printf("\n按任意键返回主菜单");
    if(getch())
    {   
        return;
    }
}

float grsd(float v)		//计算个人所得税
{
    float x=v;		//应纳税所得额
    float y=0;		//应纳税额
    int n;
    
    if(x>0)
    {
        if(x<500)    n=1;
        else if(x<2000)    n=2;
        else if(x<5000)    n=3;
        else if(x<20000)    n=4;
        else if(x<40000)    n=5;
        else if(x<60000)    n=6;
        else if(x<80000)    n=7;
        else if(x<100000)    n=8;
        else n=9;
    }
    
    switch(n)
    {
        case 8:y=y+(x-80000)*0.4;
        case 7:y=y+(x-60000)*0.35;
        case 6:y=y+(x-40000)*0.3;
        case 5:y=y+(x-20000)*0.25;
        case 4:y=y+(x-5000)*0.2;
        case 3:y=y+(x-2000)*0.15;
        case 2:y=y+(x-500)*0.1;
        case 1:y=y+x*0.05;
    }

    return y;
}

void main()		//主函数
{

    
    read();

    while(1)
    {
		system("cls");		//清屏操作
        printf("        ### 欢迎使用广西民族大学软件与信息安全学院职工工资管理系统 ###\n\n");
        printf("        请选择数字<1-7>                                   \n");
        printf("        ==============================================================\n");
        printf("        :                     1、 查询职工工资记录                   :\n");
        printf("        :                     2、 修改职工工资记录                   :\n");
        printf("        :                     3、 添加职工工资记录                   :\n");
        printf("        :                     4、 删除职工工资记录                   :\n");
        printf("        :                     5、 保存职工工资记录                   :\n");
        printf("        :                     6、 浏览职工工资记录                   :\n");
        printf("        :                     7、 退出系统                           :\n");
        printf("        ==============================================================\n");
        printf("                        \n");
        printf("                        \n");
        printf("		           请输入一个数字*[ ]\b\b");

		int flg;
        scanf("%d",&flg);
        if(flg>=1&&flg<=7)		//对输入字数进行判断
        {
            switch(flg)
            {
                case 1:find();break;
                case 2:modify();break;
                case 3:add();break;
                case 4:del();break;
                case 5:write();break;
                case 6:list();break;
                case 7:exit(0);		//退出系统
            }
        }
        else
        {
            printf("无效指令，请重新输入");
            getch();
            system("cls");
        }
    }
    
}
