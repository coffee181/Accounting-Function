#include"common.h"
#include"account_item.h"

void printItem(const AccountItem& item);
//---------------------------------记账------------------------------------
//读取文件中的账目数据
void loadDateFromFile(vector<AccountItem>& items)
{
	ifstream input(FILENAME);

	//逐行读取每一条账目，包装成AccountItem
	AccountItem item;
	while (input >> item.itemType >> item.amount >> item.detail)
	{
		items.push_back(item);
	}
	input.close();
}
//记账函数
void accounting(vector<AccountItem>& items)
{

	//读取键盘选择并做合法判断
	char key = readMenuSelection(3);

	switch (key)
	{
	case'1': //收入
		income(items);
		break;
	case'2'://支出
		expand(items);
		break;
	case'3'://返回主菜单		
		break;
	default:
		break;
	}
	cout << endl;

}
//记录一笔收入
void income(vector<AccountItem>& items)
{
	//新构建一个AccountItem对象
	AccountItem item;
	//类型已经确定就是收入
	item.itemType = INCOME;

	//与用户交互，键盘输入金额和备注信息
	cout << "\n本次收入金额：";
	//输入合法性校验
	item.amount = readAmount();

	cout << "\n备注";
	getline(cin, item.detail);

	//添加到vector中
	items.push_back(item);

	//持久化保存--写入文件中
	insertIntoFile(item);

	//显示成功信息
	cout << "\n---------------------记账成功--------------------\n" << endl;
	cout << "\n请按回车键返回主菜单..." << endl;

	string line;
	getline(cin, line);
}

//将账目写入文件中
void insertIntoFile(const AccountItem& item)
{
	//创建一个输出对象
	ofstream output(FILENAME, ios::out | ios::app);//以追加(ios::app)的方式写入(ios::out)文件

	output << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;

	output.close();
}
//记录一笔支出
void expand(vector<AccountItem>& items)
{
	//新构建一个AccountItem对象
	AccountItem item;
	//类型已经确定就是收入
	item.itemType = EXPAND;

	//与用户交互，键盘输入金额和备注信息
	cout << "\n本次支出金额：";
	//输入合法性校验
	item.amount = -readAmount();//取负数


	cout << "\n备注:";
	getline(cin, item.detail);

	//添加到vector中
	items.push_back(item);

	//持久化保存--写入文件中
	insertIntoFile(item);

	//显示成功信息
	cout << "\n---------------------记账成功--------------------\n" << endl;
	cout << "\n请按回车键返回主菜单..." << endl;

	string line;
	getline(cin, line);
}
//-------------------------------查询------------------------------------------
//查询函数
void query(const vector<AccountItem>& items)
{
	//读取键盘选择并做合法判断
	char key = readMenuSelection(4);

	switch (key)
	{
	case'1': //1-查询所有账目，并统计总收支
		queryItems(items);
		break;
	case'2'://2-查询所有收入，统计总收入
		queryItems(items, INCOME);
		break;
	case'3'://3-查询所有支出，统计总支出
		queryItems(items, EXPAND);
		break;
	default:
		break;
	}
	cout << endl;
}

void queryItems(const vector<AccountItem>& items)
{
	cout << "---------查询结果----------" << endl;
	cout << "\n类型\t\t金额\t\t备注\n" << endl;

	//遍历所有账目，统计总收支
	int total = 0;
	for (auto item : items)
	{
		printItem(item);
		total += item.amount;
	}
	cout << "==============================================\n" << endl;
	cout << "总收支：" << total << endl;

	//显示成功信息
	cout << "\n请按回车键返回主菜单..." << endl;

	string line;
	getline(cin, line);
}

//打印输出一条账目信息
void printItem(const AccountItem& item)
{
	cout << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;
}


//函数重载
void queryItems(const vector<AccountItem>& items, const string  itemType)
{
	cout << "---------查询结果----------" << endl;
	cout << "\n类型\t\t金额\t\t备注\n" << endl;

	//遍历所有账目，统计总收入/支出
	int total = 0;
	for (auto item : items)
	{
		if (item.itemType == itemType) {
			printItem(item);
			total += item.amount;
		}
		else
		{
			continue;
		}
	}
	cout << "==============================================\n" << endl;
	cout << ((itemType == INCOME) ? "总收入：" : "总支出：") << total << endl;

	//显示成功信息
	cout << "\n请按回车键返回主菜单..." << endl;

	string line;
	getline(cin, line);
}

