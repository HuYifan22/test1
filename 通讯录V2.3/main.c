#include "menu.h"
#include "mylib.h"

int main(int argc, char const *argv[])
{
    linklist *head = LinklistCreate(); //创建空的单链表

    FILE *fp = fopen("./a.txt", "r");
    if (NULL == fp)
    {
        perror("fopen");
        return 0;
    }
    while (1)
    {
        //临时变量
        linklist tmp;
        //将文件中的数据存到链表中
        linklist *node = (linklist *)malloc(sizeof(linklist));
        node->next = NULL;
        if (0 == fread(&tmp, sizeof(tmp), 1, fp))
        {

            if (feof(fp))
            {
                printf("读到文件末尾\n");
                break;
            }
            else
            {
                perror("fread");
                return 0;
            }
        }
        node->id = tmp.id;
        my_strcpy(node->name, tmp.name);
        node->age = tmp.age;
        my_strcpy(node->tel, tmp.tel);

        node->next = head->next;
        head->next = node;
    }
    // fclose(fp);

    int choice;
    int n = 1;
    while (n)
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            AddInfo(head);
            break;
        }
        case 2:
        {
            DelInfo(head);
            break;
        }
        case 3:
        {
            ChangeInfo(head);
            break;
        }
        case 4:
        {
            FindInfo(head);
            break;
        }
        case 5:
        {
            LinklistPrint(head);
            break;
        }
        case 6:
        {

            printf("退出通讯录！\n");

            FILE *fp = fopen("./a.txt", "w+");
            if (fp == NULL)
            {
                perror("fopen");
                return 0;
            }

            for (linklist *p = head->next; p != NULL;)
            {
                linklist tmp;
                tmp.id = p->id;
                my_strcpy(tmp.name, p->name);
                tmp.age = p->age;
                my_strcpy(tmp.tel, p->tel);

                if (1 != fwrite(&tmp, sizeof(tmp), 1, fp))
                {
                    perror("fwrite");
                    return 0;
                }

                p = p->next;
            }

            // linklist *p = head->next;
            // while (p != NULL)
            // {
            //     linklist tmp;
            //     if (0 == fwrite(&tmp, sizeof(tmp), 1, fp))
            //     {

            //         if (feof(fp))
            //         {
            //             printf("写到文件末尾\n");
            //             break;
            //         }
            //         else
            //         {
            //             perror("fwrite");
            //             return 0;
            //         }
            //     }
            // }
            // fclose(fp);
            n = 0;
            break;
        }
        default:
        {
            printf("请重新输入(1-6)\n");
        }
        }
    }
    return 0;
}
