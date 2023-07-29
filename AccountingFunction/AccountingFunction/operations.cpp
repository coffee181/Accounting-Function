#include"common.h"
#include"account_item.h"

void printItem(const AccountItem& item);
//---------------------------------����------------------------------------
//��ȡ�ļ��е���Ŀ����
void loadDateFromFile(vector<AccountItem>& items)
{
	ifstream input(FILENAME);

	//���ж�ȡÿһ����Ŀ����װ��AccountItem
	AccountItem item;
	while (input >> item.itemType >> item.amount >> item.detail)
	{
		items.push_back(item);
	}
	input.close();
}
//���˺���
void accounting(vector<AccountItem>& items)
{

	//��ȡ����ѡ�����Ϸ��ж�
	char key = readMenuSelection(3);

	switch (key)
	{
	case'1': //����
		income(items);
		break;
	case'2'://֧��
		expand(items);
		break;
	case'3'://�������˵�		
		break;
	default:
		break;
	}
	cout << endl;

}
//��¼һ������
void income(vector<AccountItem>& items)
{
	//�¹���һ��AccountItem����
	AccountItem item;
	//�����Ѿ�ȷ����������
	item.itemType = INCOME;

	//���û�����������������ͱ�ע��Ϣ
	cout << "\n���������";
	//����Ϸ���У��
	item.amount = readAmount();

	cout << "\n��ע";
	getline(cin, item.detail);

	//��ӵ�vector��
	items.push_back(item);

	//�־û�����--д���ļ���
	insertIntoFile(item);

	//��ʾ�ɹ���Ϣ
	cout << "\n---------------------���˳ɹ�--------------------\n" << endl;
	cout << "\n�밴�س����������˵�..." << endl;

	string line;
	getline(cin, line);
}

//����Ŀд���ļ���
void insertIntoFile(const AccountItem& item)
{
	//����һ���������
	ofstream output(FILENAME, ios::out | ios::app);//��׷��(ios::app)�ķ�ʽд��(ios::out)�ļ�

	output << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;

	output.close();
}
//��¼һ��֧��
void expand(vector<AccountItem>& items)
{
	//�¹���һ��AccountItem����
	AccountItem item;
	//�����Ѿ�ȷ����������
	item.itemType = EXPAND;

	//���û�����������������ͱ�ע��Ϣ
	cout << "\n����֧����";
	//����Ϸ���У��
	item.amount = -readAmount();//ȡ����


	cout << "\n��ע:";
	getline(cin, item.detail);

	//��ӵ�vector��
	items.push_back(item);

	//�־û�����--д���ļ���
	insertIntoFile(item);

	//��ʾ�ɹ���Ϣ
	cout << "\n---------------------���˳ɹ�--------------------\n" << endl;
	cout << "\n�밴�س����������˵�..." << endl;

	string line;
	getline(cin, line);
}
//-------------------------------��ѯ------------------------------------------
//��ѯ����
void query(const vector<AccountItem>& items)
{
	//��ȡ����ѡ�����Ϸ��ж�
	char key = readMenuSelection(4);

	switch (key)
	{
	case'1': //1-��ѯ������Ŀ����ͳ������֧
		queryItems(items);
		break;
	case'2'://2-��ѯ�������룬ͳ��������
		queryItems(items, INCOME);
		break;
	case'3'://3-��ѯ����֧����ͳ����֧��
		queryItems(items, EXPAND);
		break;
	default:
		break;
	}
	cout << endl;
}

void queryItems(const vector<AccountItem>& items)
{
	cout << "---------��ѯ���----------" << endl;
	cout << "\n����\t\t���\t\t��ע\n" << endl;

	//����������Ŀ��ͳ������֧
	int total = 0;
	for (auto item : items)
	{
		printItem(item);
		total += item.amount;
	}
	cout << "==============================================\n" << endl;
	cout << "����֧��" << total << endl;

	//��ʾ�ɹ���Ϣ
	cout << "\n�밴�س����������˵�..." << endl;

	string line;
	getline(cin, line);
}

//��ӡ���һ����Ŀ��Ϣ
void printItem(const AccountItem& item)
{
	cout << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;
}


//��������
void queryItems(const vector<AccountItem>& items, const string  itemType)
{
	cout << "---------��ѯ���----------" << endl;
	cout << "\n����\t\t���\t\t��ע\n" << endl;

	//����������Ŀ��ͳ��������/֧��
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
	cout << ((itemType == INCOME) ? "�����룺" : "��֧����") << total << endl;

	//��ʾ�ɹ���Ϣ
	cout << "\n�밴�س����������˵�..." << endl;

	string line;
	getline(cin, line);
}

