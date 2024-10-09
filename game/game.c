#include "game.h"

//��ʼ������ 
void InitBoard(char board[ROWS][COLS],int rows,int cols,char Init){
	int i,j;
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			board[i][j]=Init;
}

//��ӡ���� 
void DisplayBoard(char board[ROWS][COLS],int row,int col){
	int i,j;
	Color(15);
	printf(" 0");
	for(i=1;i<=col;i++)
		printf("%2d",i);
	printf("\n");
	for(i=1;i<=row;i++){
		Color(15);
		printf("%2d",i);
		for(j=1;j<=col;j++)
			switch(board[i][j]){
				case Air:Color(7);printf(" %c",board[i][j]);break;
				case None:Color(7);printf(" %c",board[i][j]);break;
				case Mine:Color(4);printf(" %c",board[i][j]);break;
				case '0':Color(8);printf(" %c",board[i][j]);break;
				case '1':Color(11);printf(" %c",board[i][j]);break;
				case '2':Color(10);printf(" %c",board[i][j]);break;
				case '3':Color(12);printf(" %c",board[i][j]);break;
				case '4':Color(3);printf(" %c",board[i][j]);break;
				case '5':Color(4);printf(" %c",board[i][j]);break;
				case '6':Color(2);printf(" %c",board[i][j]);break;
				case '7':Color(0);printf(" %c",board[i][j]);break;
				case '8':Color(4);printf(" %c",board[i][j]);break;
				default:Color(2);printf(" %c",board[i][j]);break;
			}
		printf("\n");
	}
}

//������
void SetMine(char board[ROWS][COLS],int row,int col, int count){
	srand((unsigned)time(NULL));
	while(count){
		int r=rand()%ROW+1;
		int c=rand()%COL+1;
		if(board[r][c]==Air){
			board[r][c]=Mine;
			count--;
		}
	}
}

//��Χ����
int GetMine(char mine[ROWS][COLS],int row,int col){
	return ((int)(mine[row-1][col-1])+(int)(mine[row-1][col])+(int)(mine[row-1][col+1])+(int)(mine[row][col-1])+(int)(mine[row][col+1])+(int)(mine[row+1][col-1])+(int)(mine[row+1][col])+(int)(mine[row+1][col+1])-8*(int)Air)/((int)Mine-(int)Air);
}

//��ɢ���� 
int GetM(char mine[ROWS][COLS],char show[ROWS][COLS],int x,int y){
	int win=0;
	if(x<1||x>ROW||y<1||y>COL)
		return 0;
	if(show[x][y]==None){
		show[x][y]=GetMine(mine,x,y)+'0';
		win++;
		if(show[x][y]=='0'){
			win+=GetM(mine,show,x-1,y-1);
			win+=GetM(mine,show,x-1,y);
			win+=GetM(mine,show,x-1,y+1);
			win+=GetM(mine,show,x,y-1);
			win+=GetM(mine,show,x,y+1);
			win+=GetM(mine,show,x+1,y-1);
			win+=GetM(mine,show,x+1,y);
			win+=GetM(mine,show,x+1,y+1);
		}
	}
	return win;
}

//�Ų���
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col){
	int x,y,win;
	while(win<ROW*COL-COUNT){
		Color(7);printf("������Ҫ��ѯ������:\n");
		scanf("%d%d",&x,&y);
		if(x>=1&&x<=row&&y>=1&&y<=col){
			system("cls");
			if(mine[x][y]==Air){
				win+=GetM(mine,show,x,y);
				int x;
				for(x=col/2;x>0;x--)printf("  ");
				Color(14);printf("o_O\n");
				DisplayBoard(show,row,col);
				if(Tool)DisplayBoard(mine,ROW,COL);
			}else{
				int x;
				for(x=col/2;x>0;x--)printf("  ");
				Color(14);printf("*o*\n");
				DisplayBoard(mine,row,col);
				break;
			}
		}else{
			Color(12);printf("����Ƿ�������������:\n"); 
		}
	}
	if(win==ROW*COL-COUNT){
		system("cls");
		int x;
		for(x=col/2;x>0;x--)printf("  ");
		Color(14);printf("^o^\n");
		DisplayBoard(show,row,col);
		Color(10);printf("��ϲ�㣬���׳ɹ���\n");
		End=time(NULL);
		Timi();
	}else{
		Color(4);printf("���ź� �㱻ը����.\n"); 
	}
}

void Change(){
	Color(7);printf("������ı�ĸ�:\n");
	do{
	scanf("%d",&ROW);
	if(ROW<2||ROW>99)printf("�������������2-99����:\n"); 
	}while(ROW<2||ROW>99);
	printf("������ı�Ŀ�:\n");
	do{
	scanf("%d",&COL);
	if(COL<2||COL>99)printf("�������������2-99����:\n"); 
	}while(COL<2||COL>99);
	printf("������ı������:\n");
	do{
		scanf("%d",&COUNT);
		if(COUNT>ROW*COL||COUNT<0)
			printf("������������벻���ڸ�����������Ȼ��:\n");
	}while(COUNT>ROW*COL);
	system("cls");
} 

void Timi(){
	int tm=End-Start;
	char name[10];
	Color(7);printf("����������ǳ�(10�ַ���):\n");
	do{scanf("%s",name);
	if(strlen(name)>10)printf("�����������������:\n"); 
	}while(strlen(name)>10);
	printf("%s�����ͨ��ʱ����%d��%d��/n",name,tm/60,tm%60);
	FILE *f;
	switch(Mode){
		case 1:f=fopen("score1.txt","a");break;
		case 2:f=fopen("score2.txt","a");break;
		case 3:f=fopen("score3.txt","a");break;
		case 4:f=fopen("score4.txt","a");break;
		default: printf("ʧ��\n");break;
	}
	if(f==NULL)
		printf("�򿪴���");
	fprintf(f,"%-23s%02d��%02d��",name,tm/60,tm%60);
	if(Mode==4)fprintf(f,"          %-2d         %-3d       %-2d��",ROW,COL,COUNT);
	fprintf(f,"\n");
	fclose(f);
}

void Text(){
	FILE *f;
	char *p;
	int choice=6,filesize;
	while(choice>4||choice<1){
	printf("--------------------------\n"); 
	printf("----ѡ����Ҫ�鿴��ģʽ----\n"); 
	printf("--------------------------\n"); 
	printf("---------1.����-----------\n"); 
	printf("--------------------------\n"); 
	printf("---------2.�м�-----------\n"); 
	printf("--------------------------\n");
	printf("---------3.ר��-----------\n"); 
	printf("--------------------------\n");
	printf("--------4.�Զ���----------\n"); 
	printf("--------------------------\n");
	scanf("%d",&choice); 
	system("cls");
	switch(choice){
		case 1:f=fopen("score1.txt","r");printf("          ����ģʽ����\n\n");break;
		case 2:f=fopen("score2.txt","r");printf("          �м�ģʽ����\n\n");break;
		case 3:f=fopen("score3.txt","r");printf("          ר��ģʽ����\n\n");break;
		case 4:f=fopen("score4.txt","r");printf("         �Զ���ģʽ����\n\n");break;
		default: printf("�����������������:\n");break;
	}
	}
	if(f==NULL){
		printf("         �޸�ģʽ�ɼ���¼\n\n"); 
	}
	else{
		printf("�ǳ�                   ͨ��ʱ��");
		if(choice==4)
			 printf("          �߶�       ���      ����");
		printf("\n\n");
		fseek(f,0,SEEK_END);
		filesize=ftell(f);
		p=malloc(filesize*sizeof(char));
		memset(p,'\0',filesize*sizeof(char));
		fseek(f,0,SEEK_SET);
		fread(p,sizeof(char),filesize,f);
		printf("%s\n",p);
		fclose(f);
	}
}

void Color(short col){
	if(col>=0&&col<=15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),col);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
