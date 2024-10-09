#include "game.h"

void game(){
	int choice=5;
	while(choice<1||choice>4){
	printf("--------------------------\n"); 
	printf("--------选择难度----------\n"); 
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
		case 1:ROW=EAZY_ROW;COL=EAZY_COL;COUNT=EAZY_COUNT;Mode=1;break;
		case 2:ROW=NORMAL_ROW;COL=NORMAL_COL;COUNT=NORMAL_COUNT;Mode=2;break;
		case 3:ROW=DEFFCULT_ROW;COL=DEFFCULT_COL;COUNT=DEFFCULT_COUNT;Mode=3;break;
		case 4:Change();Mode=4;break;
		case 114514:if(Tool==0){printf("''透视模式开启''\n");Tool=1;}else{Color(2);printf("''取消作弊''\n");Tool=0;}system("pause");system("cls");Color(12);break;
		default:printf("输入错误，请重新输入:\n");break;
	}
	}
	char board[ROWS][COLS],show[ROWS][COLS];
	InitBoard(board,ROWS,COLS,Air);
	InitBoard(show,ROWS,COLS,None);
	SetMine(board,ROW,COL,COUNT);
	Start=time(NULL);
	int x;
	for(x=COL/2;x>0;x--)printf("  ");
	Color(14);printf("-_-\n");
	DisplayBoard(show,ROW,COL);
	if(Tool)DisplayBoard(board,ROW,COL);
	FindMine(board,show,ROW,COL);
}

int main() {
	Tool=0;
	while(1){
	Color(2); 
	printf("--------------------------\n"); 
	printf("----------扫雷------------\n");
	printf("--------------------------\n");
	printf("---------1.游玩-----------\n"); 
	printf("--------------------------\n"); 
	printf("--------2.成绩榜----------\n"); 
	printf("--------------------------\n"); 
	printf("---------3.退出-----------\n"); 
	printf("--------------------------\n");
	int choice;
	scanf("%d",&choice); 
	system("cls");
	switch(choice){
		case 1: Color(12); game(); break;
		case 2: Color(3); Text(); break;
		case 3: Color(7); printf("游戏结束。。。"); exit(0); break;
		default: Color(6); printf("\n 构  思 - 廖  伟？\ndog shit neo why?\n\n"); break;
	}
	system("pause");
	system("cls");
	}
	return 0;
}
