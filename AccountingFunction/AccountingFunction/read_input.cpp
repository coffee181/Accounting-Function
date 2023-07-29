#include"common.h"

//读取菜单选择合法性判断
char readMenuSelection(int options)
{
	//用str保存用户输入的信息
	string str;
	while (true) {
		getline(cin, str);
		//进行合法性校验
		if (str.size() != 1 || str[0] - '0' <= 0 || str[0] - '0' > options)
		{
			cout << "输入错误，请重新选择：";
		}
		else
		{
			break;
		}
	}
	//输入合法
	return str[0];
}
//读取确认退出函数以及合法性校验
char readQuitConfirm()
{
	//用str保存用户输入的信息
	string str;
	while (true) {
		getline(cin, str);
		//进行合法性校验
		if (str.size() != 1 || toupper(str[0]) != 'Y' && toupper(str[0]) != 'N') //toupper 函数 自动转换成大写
		{
			cout << "输入错误，请重新输入（Y/N)：";
		}
		else
		{
			break;
		}
	}
	//输入合法
	return str[0];

}
//金额输入合法性判断
int readAmount()
{
	int amount;

	string str;
	while (true) {
		getline(cin, str);
		//进行合法性校验
		try
		{
			amount = stoi(str);
			break;
		}//stoi函数将字符串转化为int类型的数据 不合法函数会报错--抛出异常
		catch (invalid_argument e)//非法参数异常
		{
			cout << "输入错误，请正确输入数字：";
		}


	}
	//输入合法
	return amount;
}