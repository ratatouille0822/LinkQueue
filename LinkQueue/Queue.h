#pragma once

typedef struct Node
{
	struct Node* next;
}Node, *pNode;

typedef struct QueueManager
{
	Node head;
	pNode tail;
	int size;
}QueueManager, *pQueueManager;


typedef void* QueueType;
typedef void* DataType;

pQueueManager Init_Queue();
int InsertData_Queue(QueueType queue_manager, DataType data);
int DeleteData_Queue(QueueType queue_manager);
int GetSize_Queue(QueueType queue_manager);
int IsEmpty_Queue(QueueType queue_manager);
DataType GetHeadElement_Queue(QueueType queue_manager);
DataType GetTailElement_Queue(QueueType queue_manager);
int TraversalPrint_queue(QueueType queue_manager, void (*PrintFunc)(void* data));
int Free_Queue(QueueType queue_manager);

