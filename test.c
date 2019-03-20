#include <stdio.h>
#include <string.h>


int main()
{
	char s[50];
	char *p, *p1, *p2;
	int i;
	int num1 = 0, num2 = 0;
	int sum = 0;
	int jiaOrNot = 0;

	scanf("%s", &s);
	//printf("debug:in is %s\r\n", s);
	p1 = strchr(s, '+');
	p2 = strchr(s, '-');
	if (p1 != NULL && p2 != NULL)
	{
		if (p1 < p2)
		{
			p = p1;
		}
		else
		{
			p = p2;
		}
	}
	else if (p1 == NULL && p2 != NULL)
	{
		p = p2;
	}
	else if (p1 != NULL && p2 == NULL)
	{
		p = p1;
	}
	else   /* p1 == NULL && p2 == NULL  */
	{
		for (i = 0, num1 = 0; i < (int)strlen(s); i++)
		{
			num1 = (int)(s[i] - '0') + num1 * 10;
		}
		sum = num1;
		printf("%d\r\n", sum);
		return 0;
	}

	for (i = 0, num1 = 0; i < (int)(p - s); i++)
	{
		num1 = (s[i] - '0') + num1 * 10;
	}
	sum = num1;
	//printf("debug:No.1 is %d\r\n", num1);
	strcpy(s, p);
	//printf("debug:without No.1 is %s\r\n", s);
	//取出第一个数

	while (1)
	{
		p1 = strchr(s, '+');
		p2 = strchr(s, '-');
		if (p1 != NULL && p2 != NULL)
		{
			if (p1 < p2)
			{
				p = p1;
			}
			else
			{
				p = p2;
			}
		}
		else if (p1 == NULL && p2 != NULL)
		{
			p = p2;
		}
		else if (p1 != NULL && p2 == NULL)
		{
			p = p1;
		}
		if (*p == '+')
		{
			jiaOrNot = 1;
		}
		else
		{
			jiaOrNot = -1;
		}
		strcpy(s, (p+1));
		//printf("debug:%s\r\n", s);
		//printf("debug:%d\r\n", jiaOrNot);
		//return 0;
		//取出第一个符号

		p1 = strchr(s, '+');
		p2 = strchr(s, '-');
		if (p1 != NULL && p2 != NULL)
		{
			if (p1 < p2)
			{
				p = p1;
			}
			else
			{
				p = p2;
			}
		}
		else if (p1 == NULL && p2 != NULL)
		{
			p = p2;
		}
		else if (p1 != NULL && p2 == NULL)
		{
			p = p1;
		}
		else   /* p1 == NULL && p2 == NULL  */
		{
			//后面再无符号
			for (i = 0, num2 = 0; i < (int)strlen(s); i++)
			{
				num2 = (int)(s[i] - '0') + num2 * 10;
			}
			switch (jiaOrNot)
			{
			case 1:
				sum += num2;
				break;
			case -1:
				sum -= num2;
				break;
			default:
				break;
			}
			printf("%d\r\n", sum);
			return 0;
		}
		//后面还有符号
		for (i = 0, num2 = 0; i < (int)(p - s); i++)
		{
			num2 = (s[i] - '0') + num2 * 10;
		}
		switch (jiaOrNot)
		{
		case 1:
			sum += num2;
			break;
		case -1:
			sum -= num2;
			break;
		default:
			break;
		}
		//取第二个数

		strcpy(s, p);
	}
}
