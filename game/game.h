#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>

#define EAZY_COUNT 10		//��������
#define NORMAL_COUNT 40		//�м����� 
#define DEFFCULT_COUNT 99   //ר������ 

#define EAZY_ROW 9		//�� 
#define EAZY_COL 9		//�� 
#define NORMAL_ROW 16		//�� 
#define NORMAL_COL 16		//�� 
#define DEFFCULT_ROW 16		//�� 
#define DEFFCULT_COL 30		//�� 

int ROW,COL,COUNT,Mode,Start,End,Tool;

#define ROWS ROW+2
#define COLS COL+2

#define None '*'
#define Air '_'
#define Mine '#'

//��ʼ������ 
void InitBoard(char board[ROWS][COLS],int rows,int cols,char Init);

//��ӡ���� 
void DisplayBoard(char board[ROWS][COLS],int row,int col);

//������
void SetMine(char board[ROWS][COLS],int row,int col,int count);

//�Ų���
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col); 

//�Ѷ��Զ���
void Change();

//������ɫ
void Color(short col); 

//��¼�ɼ� 
void Timi();

//���а�
void Text(); 

