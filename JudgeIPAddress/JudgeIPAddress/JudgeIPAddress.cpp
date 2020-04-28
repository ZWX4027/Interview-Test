//如何判断合法的IP地址, 尽可能考虑各种情况(面试题)
//判断IPV4的地址是否合法的程序

#include<stdio.h>
#include<ctype.h>

static int PointNum(const char* str)
{
	int count = 0;
	if (str == NULL)
	{
		return 0;
	}
	while (*str != '\0')
	{
		if (*str == '.')
		{
			count++;
		}
		str++;
	}
	return count;
}
bool IsIP(char* str)
{
	int num = 0;
	if (str == NULL || str[0] == '0')//IP地址起始不能为0
	{
		return false;
	}
	if (PointNum(str) != 3)//IP地址只有3个'.'
	{
		return false;
	}
	while (*str != '\0')
	{
		if (isdigit(*str))
		{
			num = num * 10 + (*str) - '0';
		}
		else if (*str != '.' || num > 255)
		{
			return false;
		}
		else
		{
			num = 0;
		}
		str++;
		
	}
	if (num > 255)//最后一个数据不在进循环，所以最终处理尾部数据
		return false;
	return true;
}
int main()
{
	char *str[] = { "192.188.1.2", "256.3.4.1", "0.1.2.3", "123.256.3.4", "198.164.23.259" };
	for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++)
	{
		if (IsIP(str[i]))
		{
			printf("%s 是合法的IP\n", str[i]);
		}
		else
		{
			printf("%s 不是合法的IP\n", str[i]);
		}
	}
	return 0;
}