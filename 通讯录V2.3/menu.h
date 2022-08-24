#ifndef _MENU_H_
#define _MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "mylib.h"

typedef struct node
{
    int id;
    char name[32];
    int age;
    char tel[20];
    struct node *next;
} linklist;

linklist *LinklistCreate();           //创建空的单链表
bool LinklistIsEmpty(linklist *head); //判空
void list_order(linklist *head);      //插入排序
void AddInfo(linklist *head);         //添加联系人
void DelInfo(linklist *head);         //删除联系人
void FindInfo(linklist *head);        //查找联系人
void ChangeInfo(linklist *head);      //修改联系人
void menu();                          //菜单
void LinklistPrint(linklist *head);   //遍历

#endif