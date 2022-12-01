#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
      int data;
      struct ListNode *next;
} LN;

typedef struct Queue
{
      LN *front;
      LN *rear;
} Queue;

Queue *CreateQueue()
{
      Queue *Q;
      LN *temp;
      Q = (Queue *)malloc(sizeof(Queue));
      if (!Q)
      {
            return NULL;
      }
      temp = (LN *)malloc(sizeof(LN));
      Q->front = NULL;
      Q->rear = NULL;
      return Q;
}

int IsEmptyQueue(Queue *Q)
{
      return (Q->front == NULL);
}

Queue *EnQueue(Queue *Q, int data)
{
      LN *newNode;
      newNode = (LN *)malloc(sizeof(LN));
      if (!newNode)
      {
            return NULL;
      }
      newNode->data = data;
      newNode->next = NULL;
      if (Q->rear)
      {
            Q->rear->next = newNode;
      }
      Q->rear = newNode;

      if (Q->front == NULL)
      {
            Q->front = Q->rear;
      }
      return Q;
}

Queue *DeQueue(Queue *Q)
{
      LN *temp;
      if (IsEmptyQueue(Q))
      {
            printf("Queue is empty!\n");
            return NULL;
      }
      else
      {
            temp = Q->front;
            Q->front = Q->front->next;
            free(temp);
      }
      return Q;
}

void *DeleteQueue(Queue *Q)
{
      Queue *p = CreateQueue();
      p->front = Q->front;
      p->rear = Q->rear;

      LN *temp1;
      while (p->front != NULL)
      {
            printf("WORK!\n");
            temp1 = p->front;
            p->front = p->front->next;
            free(temp1);
      }
      free(p);
}

void printQueue(Queue *Q)
{
      if (IsEmptyQueue(Q))
      {
            printf("Queue is now empty!\n");
            return;
      }

      Queue *p = CreateQueue();
      p->front = Q->front;
      p->rear = Q->rear;

      while (p->front != NULL)
      {
            printf("%d ", p->front->data);
            p->front = p->front->next;
      }
      printf("\n");
}

int main()
{
      Queue *List = CreateQueue();
      for (int i = 0; i < 10; i++)
      {
            List = EnQueue(List, i + 1);
      }
      printQueue(List);
      printQueue(List);
      for(int i = 0; i < 10; i++)
      {
            List = DeQueue(List);
      }
      printQueue(List);
      return 0;
}