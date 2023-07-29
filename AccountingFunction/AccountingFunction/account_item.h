#pragma once
#include "common.h"
//定义结构体
struct AccountItem
{
	string itemType;//类型
	int amount = 0; //金额
	string detail;//备注
};

//针对账目数据进行操作的函数声明
// 
//加载账目数据
void loadDateFromFile(vector<AccountItem>& items);
//记账操作
void accounting(vector<AccountItem>& items);
void income(vector<AccountItem>& items);
void expand(vector<AccountItem>& items);
//查询操作
void query(const vector<AccountItem>& items);
void queryItems(const vector<AccountItem>& items);
void queryItems(const vector<AccountItem>& items, const string itemType);
//写入文件操作
void insertIntoFile(const AccountItem& item);

