#include "game.h"

void game(){
	int choice=5;
	while(choice<1||choice>4){
	printf("--------------------------\n"); 
	printf("--------ѡ���Ѷ�----------\n"); 
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
		case 1:ROW=EAZY_ROW;COL=EAZY_COL;COUNT=EAZY_COUNT;Mode=1;break;
		case 2:ROW=NORMAL_ROW;COL=NORMAL_COL;COUNT=NORMAL_COUNT;Mode=2;break;
		case 3:ROW=DEFFCULT_ROW;COL=DEFFCULT_COL;COUNT=DEFFCULT_COUNT;Mode=3;break;
		case 4:Change();Mode=4;break;
		case 114514:if(Tool==0){printf("''͸��ģʽ����''\n");Tool=1;}else{Color(2);printf("''ȡ������''\n");Tool=0;}system("pause");system("cls");Color(12);break;
		default:printf("�����������������:\n");break;
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
	printf("----------ɨ��------------\n");
	printf("--------------------------\n");
	printf("---------1.����-----------\n"); 
	printf("--------------------------\n"); 
	printf("--------2.�ɼ���----------\n"); 
	printf("--------------------------\n"); 
	printf("---------3.�˳�-----------\n"); 
	printf("--------------------------\n");
	int choice;
	scanf("%d",&choice); 
	system("cls");
	switch(choice){
		case 1: Color(12); game(); break;
		case 2: Color(3); Text(); break;
		case 3: Color(7); printf("��Ϸ����������"); exit(0); break;
		default: Color(6); printf("\n ��  ˼ - ��  ΰ��\ndog shit neo why?\n\n"); break;
	}
	system("pause");
	system("cls");
	}
	return 0;
}
