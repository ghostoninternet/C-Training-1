#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayQueue
{
      int front, rear;
      int capacity;
      int *array;
} AQ;

AQ *Queue(int size)
{
      AQ *Q = (AQ *)malloc(sizeof(AQ));
      if (Q == NULL)
      {
            printf("Can't allocate\n");
            return NULL;
      }
      Q->capacity = size;
      Q->front = -1;
      Q->rear = -1;
      Q->array = (int *)malloc(sizeof(int) * Q->capacity);
      if (Q->array == NULL)
      {
            printf("Can't allocate memory for array!\n");
            return NULL;
      }
      return Q;
}

int IsEmptyQueue(AQ *Q)
{
      return (Q->front == -1);
}

int IsFullQueue(AQ *Q)
{
      return ((Q->rear + 1) % Q->capacity == Q->front);
}

int QueueSize(AQ *Q)
{
      return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}

AQ *EnQueue(AQ *Q, int data)
{
      if (IsFullQueue(Q))
      {
            printf("Queue Overflow!\n");
            return Q;
      }
      else
      {
            Q->rear = (Q->rear + 1) % Q->capacity;
            Q->array[Q->rear] = data;
            if (Q->front == -1)
            {
                  Q->front = Q->rear;
            }
      }
      return Q;
}

AQ *DeQueue(AQ *Q)
{
      if (IsEmptyQueue(Q))
      {
            printf("Queue is Empty!\n");
            return Q;
      }
      else
      {
            if (Q->front == Q->rear)
            {
                  Q->front = -1;
                  Q->rear = -1;
            }
            else
            {
                  Q->front = (Q->front + 1) % Q->capacity;
            }
            return Q;
      }
}

void DeleteQueue(AQ *Q)
{
      if (Q != NULL)
      {
            if (Q->array != NULL)
            {
                  free(Q->array);
            }
            free(Q);
      }
}

void printQueue(AQ *Q)
{
      if (Q == NULL)
      {
            printf("Queue is empty!\n");
            return;
      }
      for (int i = 0; i < Q->capacity; i++)
      {
            printf("%d ", Q->array[i]);
      }
      printf("\n");
}

int main()
{
      AQ *List = Queue(10);
      for (int i = 0; i < List->capacity; i++)
      {
            List = EnQueue(List, i + 1);
      }
      printQueue(List);
      for (int i = 0; i <= List->capacity; i++)
      {
            printf("%d %d\n", List->front, List->rear);
            List = DeQueue(List);
      }
      if(List == NULL)
      {
            printf("YES\n");
      }

      return 0;
}