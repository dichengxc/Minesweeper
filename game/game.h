#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>

#define EAZY_COUNT 10		//基础雷数
#define NORMAL_COUNT 40		//中级雷数 
#define DEFFCULT_COUNT 99   //专家雷数 

#define EAZY_ROW 9		//列 
#define EAZY_COL 9		//行 
#define NORMAL_ROW 16		//列 
#define NORMAL_COL 16		//行 
#define DEFFCULT_ROW 16		//列 
#define DEFFCULT_COL 30		//行 

int ROW,COL,COUNT,Mode,Start,End,Tool;

#define ROWS ROW+2
#define COLS COL+2

#define None '*'
#define Air '_'
#define Mine '#'

//初始化棋盘 
void InitBoard(char board[ROWS][COLS],int rows,int cols,char Init);

//打印棋盘 
void DisplayBoard(char board[ROWS][COLS],int row,int col);

//布置雷
void SetMine(char board[ROWS][COLS],int row,int col,int count);

//排查雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col); 

//难度自定义
void Change();

//设置颜色
void Color(short col); 

//记录成绩 
void Timi();

//排行榜
void Text(); 

