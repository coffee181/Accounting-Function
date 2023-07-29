#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#define INCOME "收入"
#define EXPAND "支出"
#define FILENAME "G:\\360MoveData\\Users\\liboz\\Desktop\\AccountingFunction\\AccountingBook.txt"
using namespace std;


//通用功能性函数声明
//绘制菜单函数
void showMainMenu();
void showAccountingMenu();
void showQueryMenu();


//读取键盘输入进行合法性判断函数
char readMenuSelection(int options);
char readQuitConfirm();
int  readAmount();
#pragma once
