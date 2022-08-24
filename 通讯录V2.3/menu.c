#include "menu.h"

//创建空的单链表
linklist *LinklistCreate()
{
    //头节点
    linklist *head = (linklist *)malloc(sizeof(linklist));
    head->next = NULL;

    return head;
}

void list_order(linklist *head) //插入排序
{
    linklist *p, *q, *r;
    p = head->next;
    head->next = NULL;

    while (p != NULL)
    {
        q = p;
        p = p->next;
        r = head;

        while (r->next != NULL && my_strcmp(r->next->name, q->name) == -1)
        {
            r = r->next;
        }

        q->next = r->next;
        r->next = q;
    }
}

//判空
bool LinklistIsEmpty(linklist *head)
{
    return head->next == NULL ? 1 : 0;
}

void menu() //菜单
{
    printf("****************WELCOME****************\n");
    printf("***************************************\n");
    printf("************1***增加联系人*************\n");
    printf("************2***删除联系人*************\n");
    printf("************3***修改联系人*************\n");
    printf("************4***查找联系人*************\n");
    printf("************5***显示联系人*************\n");
    printf("************6***退      出*************\n");
    printf("***************************************\n");
    printf("请输入序号：");
}

//添加联系人
void AddInfo(linklist *head)
{
    int n = 1;
    while (n) //循环添加的控制开关
    {
        linklist *tmp = (linklist *)malloc(sizeof(linklist));

        printf("请输入id:\n");
        scanf("%d", &tmp->id);
        printf("请输入姓名:\n");
        scanf("%s", tmp->name);
        printf("请输入年龄:\n");
        scanf("%d", &tmp->age);
        while (tmp->age < 1 && tmp->age > 100)
        {
            printf("请输入正确的年龄(1-100):\n");
            scanf("%d", &tmp->age);
            if (tmp->age > 1 && tmp->age < 100)
            {
                break;
            }
        }

        printf("请输入电话:\n");
        scanf("%s", tmp->tel);
        while (my_strlen(tmp->tel) != 11)
        {
            printf("请输入11位电话号码:\n");
            scanf("%s", tmp->tel);
            if (my_strlen(tmp->tel) == 11)
            {
                break;
            }
        }

        tmp->next = head->next;
        head->next = tmp;
        FILE *fp = fopen("./a.txt", "a");
        if (fp == NULL)
        {
            perror("fopen");
            return;
        }
        if (1 != fwrite(tmp, sizeof(*tmp), 1, fp))
        {
            perror("fwrite");
            return;
        }
        fclose(fp);

        printf("添加信息成功!\n");
        printf("是否继续添加？(y/n)\n");
        char j;
        scanf("%*c%c%*c", &j);
        switch (j)
        {
        case 'y':
        {
            break;
        }
        case 'n':
        {
            n = 0;
            break;
        }
        default:
        {
            printf("请输入'y'或'n'\n");
            break;
        }
        }
    }
}

//删除联系人
void DelInfo(linklist *head)
{
    if (LinklistIsEmpty(head))
    {
        printf("链表为空!\n");
    }
    else
    {
        char name1[32];
        int i = 1;
        printf("请输入联系人的姓名：\n");
        scanf("%s", name1);
        linklist *p, *q;
        p = head->next;
        q = head;
        if (p->next == NULL)
        {
            if (my_strcmp(p->name, name1) == 0)
            {
                head->next = p->next;
                p->next = p;
                free(p);
                p = NULL;
                printf("删除成功!\n");
                i = 0;
            }
        }
        else
        {
            while (p != NULL)
            {

                if (my_strcmp(p->name, name1) == 0)
                {
                    printf("删除00000000000!\n");
                    q->next = p->next;
                    p->next = p;
                    free(p);
                    p = NULL;
                    printf("删除成功!\n");
                    i = 0;
                    break;
                }
                q = q->next;
                p = q->next;
            }
        }
        if (i)
        {
            printf("删除失败,未找到该联系人!\n");
        }
    }
}

//修改联系人
void ChangeInfo(linklist *head)
{
    if (LinklistIsEmpty(head))
    {
        printf("链表为空\n");
        return;
    }
    printf("****************WELCOME****************\n");
    printf("***************************************\n");
    printf("*************请输入要修改的联系人*********\n");
    char name2[32];
    printf("请输入姓名:");
    scanf("%*c%s%*c", name2);
    linklist *p = head->next;
    while (p != NULL)
    {
        if (my_strcmp(p->name, name2) == 0)
        {
            printf("id\t\tname\t\tage\t\ttel\t\t\n");
            printf("%0d\t\t", p->id);
            printf("%s\t\t", p->name);
            printf("%0d\t\t", p->age);
            printf("%s\t\t", p->tel);
            putchar(10);
            int j = 1;
            while (j)
            {
                printf("请选择你要修改的选项(1.id/2.姓名/3.年龄/4.电话/0.退出)\n");
                int choice;
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                {
                    // int id1;
                    printf("请输入你想修改的ID:\n");
                    scanf("%d", &p->id);

                    break;
                }
                case 2:
                {
                    // char name1[32];
                    printf("请输入你想修改的姓名:\n");
                    scanf("%s", p->name);

                    break;
                }
                case 3:
                {
                    printf("请输入你想修改的年龄:\n");
                    scanf("%d", &p->age);
                    break;
                }
                case 4:
                {
                    printf("请输入你想修改的电话:\n");
                    scanf("%s", p->tel);

                    break;
                }
                default:
                {
                    j = 0;
                    break;
                }
                }
                printf("id\t\tname\t\tage\t\ttel\t\t\n");
                printf("%0d\t\t", p->id);
                printf("%s\t\t", p->name);
                printf("%0d\t\t", p->age);
                printf("%s\t\t", p->tel);
                putchar(10);
            }
        }
        p = p->next;
    }
}

//查找联系人
void FindInfo(linklist *head)
{
    if (LinklistIsEmpty(head))
    {
        printf("链表为空\n");
        return;
    }
    printf("****************WELCOME****************\n");
    printf("***************************************\n");
    printf("***************1按id搜索**************\n");
    printf("*************2按用户名搜索*************\n");
    printf("**************请输入(1/2):************\n");

    int i;
    scanf("%d", &i);
    if ((i >= 0) && (i < 10))
    {
        switch (i)
        {
        case 1:
        {
            printf("请输入id:\n");
            int j;
            scanf("%d", &j);
            if ((j > 0) && (j < 1024))
            {
                linklist *p = head->next;
                int flag = 0;
                while (p != NULL)
                {

                    if (p->id == j)
                    {
                        printf("id\t\tname\t\tage\t\ttel\t\t\n");
                        printf("%0d\t\t", p->id);
                        printf("%s\t\t", p->name);
                        printf("%0d\t\t", p->age);
                        printf("%s\t\t", p->tel);
                        putchar(10);
                        flag = 1;
                        break;
                    }
                    p = p->next;
                }
                if (flag == 0)
                {
                    printf("id:%d不存在，查找失败\n", j);
                }
                return;
            }
            else
            {
                printf("id有误；请输入正确的id(0-1024)\n");
            }

            break;
        }
        case 2:
        {
            printf("请输入用户名:\n");
            char name1[32];
            scanf("%s", name1);
            linklist *p = head;
            int flag = 0;
            while (p->next != NULL)
            {
                p = p->next;
                if (my_strcmp(p->name, name1) == 0)
                {
                    printf("id\t\tname\t\tage\t\ttel\t\t\n");
                    printf("%0d\t\t", p->id);
                    printf("%s\t\t", p->name);
                    printf("%0d\t\t", p->age);
                    printf("%s\t\t", p->tel);
                    putchar(10);
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                printf("姓名:%s不存在，查找失败\n", name1);
            }
            return;
            break;
        }
        default:
        {
            printf("请输入(1/2)!\n");
            break;
        }
        }
    }
    else
    {
        printf("请输入0-9任意键退出\n");
    }
}

//遍历
void LinklistPrint(linklist *head)
{
    // FILE *fp = fopen("./a.txt", "r");
    // if (fp == NULL)
    // {
    //     perror("fopen");
    //     return;
    // }
    // printf("id\t\tname\t\tage\t\ttel\t\t\n");
    // while (1)
    // {
    //     linklist tmp;

    //     if (0 == fread(&tmp, sizeof(tmp), 1, fp))
    //     {

    //         if (feof(fp))
    //         {
    //             printf("读到文件末尾\n");
    //             break;
    //         }
    //         else
    //         {
    //             perror("fread");
    //             return;
    //         }
    //     }
    //     printf("%0d\t\t", tmp.id);
    //     printf("%s\t\t", tmp.name);
    //     printf("%0d\t\t", tmp.age);
    //     printf("%s\t\t", tmp.tel);
    //     putchar(10);
    // }
    if (LinklistIsEmpty(head))
    {
        printf("链表为空\n");
        return;
    }
    list_order(head); //插入排序
    linklist *p = head->next;
    printf("id\t\tname\t\tage\t\ttel\t\t\n");
    while (p != NULL)
    {
        printf("%0d\t\t", p->id);
        printf("%s\t\t", p->name);
        printf("%0d\t\t", p->age);
        printf("%s\t\t", p->tel);
        putchar(10);
        p = p->next;
    }
}