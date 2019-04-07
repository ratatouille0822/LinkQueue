#include "Queue.h"
#include <stdio.h>

pQueueManager Init_Queue()
{
	pQueueManager temp = (pQueueManager)malloc(sizeof(QueueManager));
	temp->head.next = NULL;
	temp->tail = temp->head.next;
	temp->size = 0;

	return (QueueType)temp;
}
int InsertData_Queue(QueueType queue_manager, DataType data)
{
	if (NULL == queue_manager || NULL == data)
	{
		perror("Empty !\n");
		return -1;
	}
	pQueueManager temp = (pQueueManager)queue_manager;

	pNode p_new = (pNode)data;

	temp->tail = p_new;
	p_new->next = temp->head.next;
	temp->head.next = p_new;
	temp->size += 1;

	return temp->size;
}
int DeleteData_Queue(QueueType queue_manager)
{
	if (NULL == queue_manager)
	{
		perror("Empty !\n");
		return -1;
	}
	pQueueManager temp = (pQueueManager)queue_manager;

	pNode real_tail = temp->tail;

	while(NULL != real_tail->next->next)
	{ 
		real_tail = real_tail->next;
	}

	real_tail->next = NULL;
	temp->size -= 1;
	return 0;
}
int GetSize_Queue(QueueType queue_manager)
{
	if (NULL == queue_manager)
	{
		perror("Empty !\n");
		return -1;
	}
	pQueueManager temp = (pQueueManager)queue_manager;
	return temp->size;
}
int IsEmpty_Queue(QueueType queue_manager)
{
	if (NULL == queue_manager)
	{
		perror("Empty !\n");
		return -1;
	}
	pQueueManager temp = (pQueueManager)queue_manager;
	
	return temp->size == 0 ? 1 : 0;
}
DataType GetHeadElement_Queue(QueueType queue_manager)
{
	if (NULL == queue_manager)
	{
		perror("Empty !\n");
		return -1;
	}
	pQueueManager temp = (pQueueManager)queue_manager;

	return (DataType)temp->head.next;

}
DataType GetTailElement_Queue(QueueType queue_manager)
{
	if (NULL == queue_manager)
	{
		perror("Empty !\n");
		return -1;
	}
	pQueueManager temp = (pQueueManager)queue_manager;

	while (temp->tail->next != NULL)
	{
		temp->tail = temp->tail->next;
	}

	return (DataType)temp->tail;

}
int TraversalPrint_queue(QueueType queue_manager, void (*PrintFunc)(void* data))
{
	if (NULL == queue_manager)
	{
		perror("Empty !\n");
		return -1;
	}
	pQueueManager temp = (pQueueManager)queue_manager;

	while (temp->tail->next != NULL)
	{
		PrintFunc(temp->tail);
		temp->tail = temp->tail->next;
	}
	return 0;
}
int Free_Queue(QueueType queue_manager)
{
	if (NULL == queue_manager)
	{
		perror("Empty !\n");
		return -1;
	}
	free(queue_manager);
}

