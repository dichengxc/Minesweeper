#include "game.h"

//初始化棋盘 
void InitBoard(char board[ROWS][COLS],int rows,int cols,char Init){
	int i,j;
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			board[i][j]=Init;
}

//打印棋盘 
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

//布置雷
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

//周围雷数
int GetMine(char mine[ROWS][COLS],int row,int col){
	return ((int)(mine[row-1][col-1])+(int)(mine[row-1][col])+(int)(mine[row-1][col+1])+(int)(mine[row][col-1])+(int)(mine[row][col+1])+(int)(mine[row+1][col-1])+(int)(mine[row+1][col])+(int)(mine[row+1][col+1])-8*(int)Air)/((int)Mine-(int)Air);
}

//扩散排雷 
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

//排查雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col){
	int x,y,win;
	while(win<ROW*COL-COUNT){
		Color(7);printf("输入需要查询的坐标:\n");
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
			Color(12);printf("坐标非法，请重新输入:\n"); 
		}
	}
	if(win==ROW*COL-COUNT){
		system("cls");
		int x;
		for(x=col/2;x>0;x--)printf("  ");
		Color(14);printf("^o^\n");
		DisplayBoard(show,row,col);
		Color(10);printf("恭喜你，排雷成功！\n");
		End=time(NULL);
		Timi();
	}else{
		Color(4);printf("很遗憾 你被炸死了.\n"); 
	}
}

void Change(){
	Color(7);printf("请输入改变的高:\n");
	do{
	scanf("%d",&ROW);
	if(ROW<2||ROW>99)printf("输入错误，请输入2-99的数:\n"); 
	}while(ROW<2||ROW>99);
	printf("请输入改变的宽:\n");
	do{
	scanf("%d",&COL);
	if(COL<2||COL>99)printf("输入错误，请输入2-99的数:\n"); 
	}while(COL<2||COL>99);
	printf("请输入改变的雷数:\n");
	do{
		scanf("%d",&COUNT);
		if(COUNT>ROW*COL||COUNT<0)
			printf("输入错误，请输入不大于格子数量的自然数:\n");
	}while(COUNT>ROW*COL);
	system("cls");
} 

void Timi(){
	int tm=End-Start;
	char name[10];
	Color(7);printf("请留下你的昵称(10字符内):\n");
	do{scanf("%s",name);
	if(strlen(name)>10)printf("输入错误，请重新输入:\n"); 
	}while(strlen(name)>10);
	printf("%s，你的通关时间是%d分%d秒/n",name,tm/60,tm%60);
	FILE *f;
	switch(Mode){
		case 1:f=fopen("score1.txt","a");break;
		case 2:f=fopen("score2.txt","a");break;
		case 3:f=fopen("score3.txt","a");break;
		case 4:f=fopen("score4.txt","a");break;
		default: printf("失败\n");break;
	}
	if(f==NULL)
		printf("打开错误");
	fprintf(f,"%-23s%02d分%02d秒",name,tm/60,tm%60);
	if(Mode==4)fprintf(f,"          %-2d         %-3d       %-2d个",ROW,COL,COUNT);
	fprintf(f,"\n");
	fclose(f);
}

void Text(){
	FILE *f;
	char *p;
	int choice=6,filesize;
	while(choice>4||choice<1){
	printf("--------------------------\n"); 
	printf("----选择需要查看的模式----\n"); 
	printf("--------------------------\n"); 
	printf("---------1.基础-----------\n"); 
	printf("--------------------------\n"); 
	printf("---------2.中级-----------\n"); 
	printf("--------------------------\n");
	printf("---------3.专家-----------\n"); 
	printf("--------------------------\n");
	printf("--------4.自定义----------\n"); 
	printf("--------------------------\n");
	scanf("%d",&choice); 
	system("cls");
	switch(choice){
		case 1:f=fopen("score1.txt","r");printf("          基础模式分数\n\n");break;
		case 2:f=fopen("score2.txt","r");printf("          中级模式分数\n\n");break;
		case 3:f=fopen("score3.txt","r");printf("          专家模式分数\n\n");break;
		case 4:f=fopen("score4.txt","r");printf("         自定义模式分数\n\n");break;
		default: printf("输入错误，请重新输入:\n");break;
	}
	}
	if(f==NULL){
		printf("         无该模式成绩记录\n\n"); 
	}
	else{
		printf("昵称                   通关时间");
		if(choice==4)
			 printf("          高度       宽度      雷数");
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
