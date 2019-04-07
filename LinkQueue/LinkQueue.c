#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Queue.h"

typedef struct UserData
{
	void* ptr;
	char name[128];
	int id;
}UserData, *pUserData;

void PrintFunc(DataType* data)
{
	pUserData temp = (pUserData)data;
	printf("%s---%d\n", temp->name, temp->id);
	
}
int main(void)
{
	pQueueManager queue_instance = Init_Queue();

	UserData p1 = { NULL,"Liu, Bei",1 };
	UserData p2 = { NULL,"Guan, Yu",2 };
	UserData p3 = { NULL,"Zhang, Fei",3 };
	UserData p4 = { NULL,"Zhao, Yun",4 };
	UserData p5 = { NULL,"Huang, Zhong",5 };
	UserData p6 = { NULL,"Wei, Yan",6 };
	
	InsertData_Queue(queue_instance, &p1);
	InsertData_Queue(queue_instance, &p2);
	InsertData_Queue(queue_instance, &p3);
	InsertData_Queue(queue_instance, &p4);
	InsertData_Queue(queue_instance, &p5);
	InsertData_Queue(queue_instance, &p6);
	
	TraversalPrint_queue(queue_instance,PrintFunc);
	printf("-----------------------------------------------------100\n");
	UserData head_element = *(pUserData)GetHeadElement_Queue(queue_instance);
	printf("%s----%d\n", head_element.name, head_element.id);
	UserData tail_element = *(pUserData)GetTailElement_Queue(queue_instance);
	printf("%s----%d\n", tail_element.name, tail_element.id);
	printf("-----------------------------------------------------200\n");
	DeleteData_Queue(queue_instance);
	printf("-----------------------------------------------------300\n");
	head_element = *(pUserData)GetHeadElement_Queue(queue_instance);
	printf("%s----%d\n", head_element.name, head_element.id);
	tail_element = *(pUserData)GetTailElement_Queue(queue_instance);
	printf("%s----%d\n", tail_element.name, tail_element.id);
	printf("-----------------------------------------------------400\n");
	TraversalPrint_queue(queue_instance,PrintFunc);
	
	Free_Queue(queue_instance);





	printf("\n");
	system("pause");
	return 0;
}
