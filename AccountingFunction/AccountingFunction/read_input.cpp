#include"common.h"

//��ȡ�˵�ѡ��Ϸ����ж�
char readMenuSelection(int options)
{
	//��str�����û��������Ϣ
	string str;
	while (true) {
		getline(cin, str);
		//���кϷ���У��
		if (str.size() != 1 || str[0] - '0' <= 0 || str[0] - '0' > options)
		{
			cout << "�������������ѡ��";
		}
		else
		{
			break;
		}
	}
	//����Ϸ�
	return str[0];
}
//��ȡȷ���˳������Լ��Ϸ���У��
char readQuitConfirm()
{
	//��str�����û��������Ϣ
	string str;
	while (true) {
		getline(cin, str);
		//���кϷ���У��
		if (str.size() != 1 || toupper(str[0]) != 'Y' && toupper(str[0]) != 'N') //toupper ���� �Զ�ת���ɴ�д
		{
			cout << "����������������루Y/N)��";
		}
		else
		{
			break;
		}
	}
	//����Ϸ�
	return str[0];

}
//�������Ϸ����ж�
int readAmount()
{
	int amount;

	string str;
	while (true) {
		getline(cin, str);
		//���кϷ���У��
		try
		{
			amount = stoi(str);
			break;
		}//stoi�������ַ���ת��Ϊint���͵����� ���Ϸ������ᱨ��--�׳��쳣
		catch (invalid_argument e)//�Ƿ������쳣
		{
			cout << "�����������ȷ�������֣�";
		}


	}
	//����Ϸ�
	return amount;
}