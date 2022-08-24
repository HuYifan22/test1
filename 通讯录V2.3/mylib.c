#include "menu.h"
#include "mylib.h"

int my_strlen(char *src)
{
    int num = 0;
    while (*src != '\0')
    {
        src++;
        num++;
    }

    return num;
}

int my_strcmp(char *s1,char *s2)
{
    while (*s1 == *s2 && *s1 != '\0')
    {
        s1++;
        s2++;
    }
    if (*s1 > *s2)
    {
        return 1;
    }
    else if (*s1 < *s2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

char my_strcpy(char *str1, char *str2)
{
	while (*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return 0;
}

int my_atoi(char *s)
{
    int flag = 1;
    int result = 0;

    if (*s == '-')
    {
        flag = -1;
        s++;
    }

    while (*s)
    {
        if (*s >= '0' && *s <= '9')
        {
            result = result * 10 + (*s - '0');
        }
        else
        {
            break;
        }
        s++;
    }

    return result * flag;
}

// void copy_struct(struct Student *s1, const struct Student *s2)
// {
//     (*s1).num = (*s2).num;
//     (*s1).age = (*s2).age;

//     int len = strlen((*s2).name);
//     (*s1).name = (char *)malloc(sizeof(char) * len + 1);
//     strcpy((*s1).name, (*s2).name);
// }
