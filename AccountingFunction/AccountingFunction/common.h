#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#define INCOME "����"
#define EXPAND "֧��"
#define FILENAME "G:\\360MoveData\\Users\\liboz\\Desktop\\AccountingFunction\\AccountingBook.txt"
using namespace std;


//ͨ�ù����Ժ�������
//���Ʋ˵�����
void showMainMenu();
void showAccountingMenu();
void showQueryMenu();


//��ȡ����������кϷ����жϺ���
char readMenuSelection(int options);
char readQuitConfirm();
int  readAmount();
#pragma once
