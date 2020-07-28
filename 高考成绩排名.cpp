#include<stdio.h>
#include<math.h>
#include<string.h>
struct
{
	int zongfen, wenli;	  //定义结构各成员
	char name[4];	
	int score[6];
	double zongpai, wenlipai;
	double ID;
} student[100];		//声明结构体变量student[100]

struct		//声明文科排序的结构体
{
	double wenpai, number;
} wenstu[100];
struct		//声明理科排序的结构体
{
	double lipai, number;
} listu[100];

int main()
{
	char num[10];
	char mz[4];
	double k;
	int i, j, f, n, gao, gaoi, m = 0;

	do
	{
		printf("请输入要录入的学生人数（不能超过100个）：\n");
		scanf("%d", &n);	
		if (n < 101 && n>0)
		{
			printf("请输入学生的成绩信息(包括准考证号、姓名、语文、数学、外语、综合)\n");
			for (i = 0; i < n; i++)
			{
				scanf("%lf %s %d %d %d %d", &student[i].ID, student[i].name, &student[i].score[0], &student[i].score[1], &student[i].score[2], &student[i].score[3]);
			}	//用for循环录入n个学生的成绩信息，放入student[100]中
		}
		else if (n >= 101 && n<=0)
		{
			printf("输入无效，输入的学生人数不能超过100个\n");	
		}
	}while(n >= 101);	//用直到型循环保证录入的学生人数不超过100个
	for(i = 0; i < n; i++)
	{
		student[i].zongfen = 0;
		student[i].zongfen = student[i].score[0] + student[i].score[1] + student[i].score[2] + student[i].score[3];
	}	//用for循环计算总分

	printf("系统功能及其编号：\n 1：输入 \n 2：修改 \n 3：删除 \n 4：排名 \n 5：查询 \n 6：文理科排名 \n 7：结束 \n");
	printf("请选择功能编号（1-7）:");

	scanf("%d", &m);
	while (m != 7)	//用当型循环实现功能的选择
	{
		if (m == 1)	//用if语句实现选择功能：输入
		{
			printf("请输入学生的成绩信息\n(包括准考证号、姓名、语文、数学、外语、综合；注意不要输入之前已录入的学生信息)\n");
			scanf("%lf %s %d %d %d %d", &student[n].ID, student[n].name, &student[n].score[0], &student[n].score[1], &student[n].score[2], &student[n].score[3]);
			student[n].zongfen = student[n].score[0] + student[n].score[1] + student[n].score[2] + student[n].score[3];
			n++;	//记录学生信息总数
		}
		else if (m == 2)	//用if语句实现选择功能：修改
		{
			printf("请输入准考证号\n");
			scanf("%lf", &k);
			for (j = 0; j <= n; j++)	//访问全部学生信息
			{
				if (student[j].ID == k)		//访问结构成员number以便找到相应准考证号的学生成绩信息
				{
					printf("请输入正确的成绩信息(包括语文、数学、外语、综合)\n");
					scanf("%d %d %d %d", &student[j].score[0], &student[j].score[1], &student[j].score[2], &student[j].score[3]);
					student[j].zongfen = 0;
					student[j].zongfen = student[j].score[0] + student[j].score[1] + student[j].score[2] + student[j].score[3];
					break;	//修改完成，跳出循环
				}
			}
		}
		else if (m == 3)	//用if语句实现选择功能：删除
		{
			printf("请输入准考证号：\n");
			scanf("%lf", &k);
			for (j = 0; j <= n; j++)
			{
				if (student[j].ID == k)
				{
					for (; j < n; j++)
					{
						student[j] = student[j + 1];	//用下一个覆盖前一个，达到删除功能
					}
					n--;	//记录学生信息总数
					break;
				}
			}
		}
		else if (m == 4)	//用if语句实现选择功能：排名
		{
			for (j = 0; j <= n; j++)
			{
				student[j].zongpai = student[j].zongfen + student[j].score[0] * 0.001 + student[j].score[1] * 0.000001 + student[j].score[2] * 0.000000001 + student[j].score[3] * 0.000000000001;
			}	//总分排名成绩分按总分、语文、数字、外语、综合方式从高到低生成,单关键字排序
			printf("\n----------------------------------------------------------------------\n");
			printf("                高考成绩汇总（按总分排名）\n");
			printf("┏━━━━━━━━━━━━━━━┳━━━━━━━┳━━━━━━┳━━━━━━┳━━━━━━┳━━━━━━┳━━━━━━┳━━━━━━┓\n");
			printf("    准考证号       姓名   语文   数学   英语   综合   总分   名次号   \n");
			for (j = 0; j < n; j++)
			{
				printf("┣━━━━━━━━━━━━━━━╋━━━━━━━╋━━━━━━╋━━━━━━╋━━━━━━╋━━━━━━╋━━━━━━╋━━━━━━┫\n");
				k = student[j].zongpai;		// k 用来代表存放总分排名成绩分最高分
				gaoi = j;		
				for (f = gaoi + 1; f < n; f++)		//用选择排序实现按总分排名成绩分从高到低进行排序
				{
					if (student[f].zongpai > k)		//高分替换前面的低分
					{
						k = student[f].zongpai;
						gaoi = f;		
					}
				
				gao = student[j].score[0];							//把相应的语文、数学、英语和综合的数据交换
				student[j].score[0] = student[gaoi].score[0];
				student[gaoi].score[0] = gao;

				gao = student[j].score[1];
				student[j].score[1] = student[gaoi].score[1];
				student[gaoi].score[1] = gao;

				gao = student[j].score[2];
				student[j].score[2] = student[gaoi].score[2];
				student[gaoi].score[2] = gao;
				
				gao = student[j].score[3];
				student[j].score[3] = student[gaoi].score[3];
				student[gaoi].score[3] = gao;

				k = student[j].ID;		//把相应的学号交换
				student[j].ID = student[gaoi].ID;
				student[gaoi].ID = k;
							
				gao = student[j].zongfen;		//把相应的总分交换
				student[j].zongfen = student[gaoi].zongfen;
				student[gaoi].zongfen = gao;

				k = student[j].zongpai;		//把相应的总排分交换
				student[j].zongpai = student[gaoi].zongpai;
				student[j].zongpai = k;

				strcpy(mz,student[j].name);		//用strcpy函数来交换相应的名字
                strcpy(student[j].name,student[gaoi].name); 
                strcpy(student[gaoi].name,mz); 
				student[gaoi].score[4] = j + 1;	//记录名次号
				}
				printf("  %12.0lf  %6s  %4d   %4d   %4d   %4d   %4d   %4d \n", 
					student[j].ID, student[j].name, student[j].score[0], student[j].score[1], student[j].score[2], student[j].score[3], student[j].zongfen, student[gaoi].score[4]);
			}
			printf("┗━━━━━━━━━━━━━━━┻━━━━━━━┻━━━━━━┻━━━━━━┻━━━━━━┻━━━━━━┻━━━━━━┻━━━━━━┛  ");
			printf("\n----------------------------------------------------------------------\n");
		}
		else if (m == 5)	//用if语句实现选择功能：查询
		{
			printf("请输入准考证号:\n");
			scanf("%lf", &k);
			for (j = 0; j <= n; j++)		//访问全部学生信息
			{
				if (k == student[j].ID)		//访问结构成员number以便找到相应准考证号的学生成绩信息
				{
					printf("%.lf %s %d %d %d %d %d %d\n ", student[j].ID, student[j].name, student[j].score[0], student[j].score[1], student[j].score[2], student[j].score[3], student[i].zongfen,student[j].score[4]);
							//访问结构成员并输出
					break;		//查询结束，跳出循环
				}
			}
			if (k == n+1)		//超出已存有的学生人数范围
			{
				printf("查无此人！\n");
			}
		}
		else if (m == 6)	//用if语句实现选择扩展功能：文理科排名
		{
			int vw = 0;
			int vl = 0;
			for (j = 0; j <= n; j++)
			{
				sprintf(num, "%lf", student[j].ID);		//把准考证号发送到字符数组num中
				if (num[0] == '1')		//检测准考证号第一个数
				{
					student[j].wenli = 1;	// 1 代表文科
					student[j].wenlipai = student[j].zongfen + student[j].score[0] * 0.001 + student[j].score[3] * 0.000001 + student[j].score[1] * 0.000000001 + student[j].score[2] * 0.000000000001;
					wenstu[vw].wenpai = student[j].wenlipai;	//按文科排名的成绩
					wenstu[vw].number = student[j].ID;		//文科考生准考证号
					vw++;	//记录文科考生
				}
				else
				{
					student[j].wenli = 5;	// 5 代表理科
					student[j].wenlipai = student[j].zongfen + student[j].score[1] * 0.001 + student[j].score[3] * 0.000001 + student[j].score[0] * 0.000000001 + student[j].score[2] * 0.000000000001;
					listu[vl].lipai = student[j].wenlipai;		//按理科排名的成绩
					listu[vl].number = student[j].ID;		//理科考生准考证号
					vl++;	//记录理科考生
				}
			}

			for (j = 0; j < vl; j++)	//用选择排序实现按理科成绩分从高到低进行排序
			{
				k = listu[j].lipai;		// k 用来代表存放理科成绩分最高分
				gaoi = j;
				for (int p = j + 1; p < vl; p++)
				{
					if (k < listu[p].lipai)
					{
						k = listu[p].lipai;
						gaoi = p;
					}
				}
				listu[gaoi].lipai = listu[j].lipai;
				listu[j].lipai = k;
				k = listu[gaoi].number;
				listu[gaoi].number = listu[j].number;
				listu[j].number = k;
				for (int z = 0; z < n; z++)
				{
					if (student[z].ID == listu[j].number)
					{
						student[z].score[5] = j + 1;	//记录理科名次号
					}
				}
			}

			for (j = 0; j < vw; j++)	//用选择排序实现按文科成绩分从高到低进行排序
			{
				k = wenstu[j].wenpai;	// k 用来代表存放文科成绩分最高分
				gaoi = j;
				for (int p = j + 1; p < vw; p++)
				{
					if (k < wenstu[p].wenpai)
					{
						k = wenstu[p].wenpai;
						gaoi = p;
					}
				}
				wenstu[gaoi].wenpai = wenstu[j].wenpai;
				wenstu[j].wenpai = k;
				k = wenstu[gaoi].number;
				wenstu[gaoi].number = wenstu[j].number;
				wenstu[j].number = k;
				for (int z = 0; z < n; z++)
				{
					if (student[z].ID == wenstu[j].number)
					{
						student[z].score[5] = j + 1;	//记录文科名次号
					}
				}
			}

			printf("\n------------------------------------------------------------------------------------------\n");
        	printf("                                      高考成绩汇总\n");
        	printf("┏━━━━━━━━━━━━━━━┳━━━━━━┳━━━━━━┳━━━━━━┳━━━━━━┳━━━━━━┳━━━━━━━┳━━━━━━━━┳━━━━━━━━━━━━━━━━┓\n");
        	printf("┃ 准考证号         姓名   语文   数学   英语   综合   总分    名次号    文理科排名\n");
			for (j = 0; j < n; j++)
			{
            printf("┣━━━━━━━━━━━━━━━╋━━━━━━╋━━━━━━╋━━━━━━╋━━━━━━╋━━━━━━╋━━━━━━━┳━━━━━━━━┳━━━━━━━━━━━━━━━━┫\n");
			printf("   %11.0lf  %6s   %4d    %4d   %4d   %4d    %4d    %4d     %4d-%2d\n",
			 student[j].ID, student[j].name, student[j].score[0], student[j].score[1], student[j].score[2], student[j].score[3], student[j].zongfen, student[j].score[4], student[j].wenli, student[j].score[5]);
			}
			printf("┗━━━━━━━━━━━━━━━┻━━━━━━┻━━━━━━┻━━━━━━┻━━━━━━┻━━━━━━┻━━━━━━━┻━━━━━━━━┻━━━━━━━━━━━━━━━━┛  \n");
			printf("\n------------------------------------------------------------------------------------------\n");
		}
		printf("系统功能及其编号：\n 1：输入 \n 2：修改 \n 3：删除 \n 4：排名 \n 5：查询 \n 6：文理科排名 \n 7：结束\n");
		printf("请选择功能编号（1-6）:");
		scanf("%d", &m);
	}
return 0;
}