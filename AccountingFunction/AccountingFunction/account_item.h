#pragma once
#include "common.h"
//����ṹ��
struct AccountItem
{
	string itemType;//����
	int amount = 0; //���
	string detail;//��ע
};

//�����Ŀ���ݽ��в����ĺ�������
// 
//������Ŀ����
void loadDateFromFile(vector<AccountItem>& items);
//���˲���
void accounting(vector<AccountItem>& items);
void income(vector<AccountItem>& items);
void expand(vector<AccountItem>& items);
//��ѯ����
void query(const vector<AccountItem>& items);
void queryItems(const vector<AccountItem>& items);
void queryItems(const vector<AccountItem>& items, const string itemType);
//д���ļ�����
void insertIntoFile(const AccountItem& item);

