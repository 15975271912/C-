#include<stdio.h>
#include<math.h>
#include<string.h>
struct
{
	int zongfen, wenli;	  //����ṹ����Ա
	char name[4];	
	int score[6];
	double zongpai, wenlipai;
	double ID;
} student[100];		//�����ṹ�����student[100]

struct		//�����Ŀ�����Ľṹ��
{
	double wenpai, number;
} wenstu[100];
struct		//�����������Ľṹ��
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
		printf("������Ҫ¼���ѧ�����������ܳ���100������\n");
		scanf("%d", &n);	
		if (n < 101 && n>0)
		{
			printf("������ѧ���ĳɼ���Ϣ(����׼��֤�š����������ġ���ѧ������ۺ�)\n");
			for (i = 0; i < n; i++)
			{
				scanf("%lf %s %d %d %d %d", &student[i].ID, student[i].name, &student[i].score[0], &student[i].score[1], &student[i].score[2], &student[i].score[3]);
			}	//��forѭ��¼��n��ѧ���ĳɼ���Ϣ������student[100]��
		}
		else if (n >= 101 && n<=0)
		{
			printf("������Ч�������ѧ���������ܳ���100��\n");	
		}
	}while(n >= 101);	//��ֱ����ѭ����֤¼���ѧ������������100��
	for(i = 0; i < n; i++)
	{
		student[i].zongfen = 0;
		student[i].zongfen = student[i].score[0] + student[i].score[1] + student[i].score[2] + student[i].score[3];
	}	//��forѭ�������ܷ�

	printf("ϵͳ���ܼ����ţ�\n 1������ \n 2���޸� \n 3��ɾ�� \n 4������ \n 5����ѯ \n 6����������� \n 7������ \n");
	printf("��ѡ���ܱ�ţ�1-7��:");

	scanf("%d", &m);
	while (m != 7)	//�õ���ѭ��ʵ�ֹ��ܵ�ѡ��
	{
		if (m == 1)	//��if���ʵ��ѡ���ܣ�����
		{
			printf("������ѧ���ĳɼ���Ϣ\n(����׼��֤�š����������ġ���ѧ������ۺϣ�ע�ⲻҪ����֮ǰ��¼���ѧ����Ϣ)\n");
			scanf("%lf %s %d %d %d %d", &student[n].ID, student[n].name, &student[n].score[0], &student[n].score[1], &student[n].score[2], &student[n].score[3]);
			student[n].zongfen = student[n].score[0] + student[n].score[1] + student[n].score[2] + student[n].score[3];
			n++;	//��¼ѧ����Ϣ����
		}
		else if (m == 2)	//��if���ʵ��ѡ���ܣ��޸�
		{
			printf("������׼��֤��\n");
			scanf("%lf", &k);
			for (j = 0; j <= n; j++)	//����ȫ��ѧ����Ϣ
			{
				if (student[j].ID == k)		//���ʽṹ��Աnumber�Ա��ҵ���Ӧ׼��֤�ŵ�ѧ���ɼ���Ϣ
				{
					printf("��������ȷ�ĳɼ���Ϣ(�������ġ���ѧ������ۺ�)\n");
					scanf("%d %d %d %d", &student[j].score[0], &student[j].score[1], &student[j].score[2], &student[j].score[3]);
					student[j].zongfen = 0;
					student[j].zongfen = student[j].score[0] + student[j].score[1] + student[j].score[2] + student[j].score[3];
					break;	//�޸���ɣ�����ѭ��
				}
			}
		}
		else if (m == 3)	//��if���ʵ��ѡ���ܣ�ɾ��
		{
			printf("������׼��֤�ţ�\n");
			scanf("%lf", &k);
			for (j = 0; j <= n; j++)
			{
				if (student[j].ID == k)
				{
					for (; j < n; j++)
					{
						student[j] = student[j + 1];	//����һ������ǰһ�����ﵽɾ������
					}
					n--;	//��¼ѧ����Ϣ����
					break;
				}
			}
		}
		else if (m == 4)	//��if���ʵ��ѡ���ܣ�����
		{
			for (j = 0; j <= n; j++)
			{
				student[j].zongpai = student[j].zongfen + student[j].score[0] * 0.001 + student[j].score[1] * 0.000001 + student[j].score[2] * 0.000000001 + student[j].score[3] * 0.000000000001;
			}	//�ܷ������ɼ��ְ��ܷ֡����ġ����֡�����ۺϷ�ʽ�Ӹߵ�������,���ؼ�������
			printf("\n----------------------------------------------------------------------\n");
			printf("                �߿��ɼ����ܣ����ܷ�������\n");
			printf("���������������������������������ש��������������ש������������ש������������ש������������ש������������ש������������ש�������������\n");
			printf("    ׼��֤��       ����   ����   ��ѧ   Ӣ��   �ۺ�   �ܷ�   ���κ�   \n");
			for (j = 0; j < n; j++)
			{
				printf("�ǩ������������������������������贈�������������贈�����������贈�����������贈�����������贈�����������贈�����������贈������������\n");
				k = student[j].zongpai;		// k �����������ܷ������ɼ�����߷�
				gaoi = j;		
				for (f = gaoi + 1; f < n; f++)		//��ѡ������ʵ�ְ��ܷ������ɼ��ִӸߵ��ͽ�������
				{
					if (student[f].zongpai > k)		//�߷��滻ǰ��ĵͷ�
					{
						k = student[f].zongpai;
						gaoi = f;		
					}
				
				gao = student[j].score[0];							//����Ӧ�����ġ���ѧ��Ӣ����ۺϵ����ݽ���
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

				k = student[j].ID;		//����Ӧ��ѧ�Ž���
				student[j].ID = student[gaoi].ID;
				student[gaoi].ID = k;
							
				gao = student[j].zongfen;		//����Ӧ���ֽܷ���
				student[j].zongfen = student[gaoi].zongfen;
				student[gaoi].zongfen = gao;

				k = student[j].zongpai;		//����Ӧ�����ŷֽ���
				student[j].zongpai = student[gaoi].zongpai;
				student[j].zongpai = k;

				strcpy(mz,student[j].name);		//��strcpy������������Ӧ������
                strcpy(student[j].name,student[gaoi].name); 
                strcpy(student[gaoi].name,mz); 
				student[gaoi].score[4] = j + 1;	//��¼���κ�
				}
				printf("  %12.0lf  %6s  %4d   %4d   %4d   %4d   %4d   %4d \n", 
					student[j].ID, student[j].name, student[j].score[0], student[j].score[1], student[j].score[2], student[j].score[3], student[j].zongfen, student[gaoi].score[4]);
			}
			printf("���������������������������������ߩ��������������ߩ������������ߩ������������ߩ������������ߩ������������ߩ������������ߩ�������������  ");
			printf("\n----------------------------------------------------------------------\n");
		}
		else if (m == 5)	//��if���ʵ��ѡ���ܣ���ѯ
		{
			printf("������׼��֤��:\n");
			scanf("%lf", &k);
			for (j = 0; j <= n; j++)		//����ȫ��ѧ����Ϣ
			{
				if (k == student[j].ID)		//���ʽṹ��Աnumber�Ա��ҵ���Ӧ׼��֤�ŵ�ѧ���ɼ���Ϣ
				{
					printf("%.lf %s %d %d %d %d %d %d\n ", student[j].ID, student[j].name, student[j].score[0], student[j].score[1], student[j].score[2], student[j].score[3], student[i].zongfen,student[j].score[4]);
							//���ʽṹ��Ա�����
					break;		//��ѯ����������ѭ��
				}
			}
			if (k == n+1)		//�����Ѵ��е�ѧ��������Χ
			{
				printf("���޴��ˣ�\n");
			}
		}
		else if (m == 6)	//��if���ʵ��ѡ����չ���ܣ����������
		{
			int vw = 0;
			int vl = 0;
			for (j = 0; j <= n; j++)
			{
				sprintf(num, "%lf", student[j].ID);		//��׼��֤�ŷ��͵��ַ�����num��
				if (num[0] == '1')		//���׼��֤�ŵ�һ����
				{
					student[j].wenli = 1;	// 1 �����Ŀ�
					student[j].wenlipai = student[j].zongfen + student[j].score[0] * 0.001 + student[j].score[3] * 0.000001 + student[j].score[1] * 0.000000001 + student[j].score[2] * 0.000000000001;
					wenstu[vw].wenpai = student[j].wenlipai;	//���Ŀ������ĳɼ�
					wenstu[vw].number = student[j].ID;		//�Ŀƿ���׼��֤��
					vw++;	//��¼�Ŀƿ���
				}
				else
				{
					student[j].wenli = 5;	// 5 �������
					student[j].wenlipai = student[j].zongfen + student[j].score[1] * 0.001 + student[j].score[3] * 0.000001 + student[j].score[0] * 0.000000001 + student[j].score[2] * 0.000000000001;
					listu[vl].lipai = student[j].wenlipai;		//����������ĳɼ�
					listu[vl].number = student[j].ID;		//��ƿ���׼��֤��
					vl++;	//��¼��ƿ���
				}
			}

			for (j = 0; j < vl; j++)	//��ѡ������ʵ�ְ���Ƴɼ��ִӸߵ��ͽ�������
			{
				k = listu[j].lipai;		// k ������������Ƴɼ�����߷�
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
						student[z].score[5] = j + 1;	//��¼������κ�
					}
				}
			}

			for (j = 0; j < vw; j++)	//��ѡ������ʵ�ְ��ĿƳɼ��ִӸߵ��ͽ�������
			{
				k = wenstu[j].wenpai;	// k �����������ĿƳɼ�����߷�
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
						student[z].score[5] = j + 1;	//��¼�Ŀ����κ�
					}
				}
			}

			printf("\n------------------------------------------------------------------------------------------\n");
        	printf("                                      �߿��ɼ�����\n");
        	printf("���������������������������������ש������������ש������������ש������������ש������������ש������������ש��������������ש����������������ש���������������������������������\n");
        	printf("�� ׼��֤��         ����   ����   ��ѧ   Ӣ��   �ۺ�   �ܷ�    ���κ�    ���������\n");
			for (j = 0; j < n; j++)
			{
            printf("�ǩ������������������������������贈�����������贈�����������贈�����������贈�����������贈�����������贈�������������ש����������������ש���������������������������������\n");
			printf("   %11.0lf  %6s   %4d    %4d   %4d   %4d    %4d    %4d     %4d-%2d\n",
			 student[j].ID, student[j].name, student[j].score[0], student[j].score[1], student[j].score[2], student[j].score[3], student[j].zongfen, student[j].score[4], student[j].wenli, student[j].score[5]);
			}
			printf("���������������������������������ߩ������������ߩ������������ߩ������������ߩ������������ߩ������������ߩ��������������ߩ����������������ߩ���������������������������������  \n");
			printf("\n------------------------------------------------------------------------------------------\n");
		}
		printf("ϵͳ���ܼ����ţ�\n 1������ \n 2���޸� \n 3��ɾ�� \n 4������ \n 5����ѯ \n 6����������� \n 7������\n");
		printf("��ѡ���ܱ�ţ�1-6��:");
		scanf("%d", &m);
	}
return 0;
}