#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayQueue
{
      int front, rear;
      int capacity;
      int *array;
} DAQ;

DAQ *Queue(int size)
{
      DAQ *Q = (DAQ *)malloc(sizeof(DAQ));
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

int IsEmptyQueue(DAQ *Q)
{
      return (Q->front == -1);
}

int IsFullQueue(DAQ *Q)
{
      return ((Q->rear + 1) % Q->capacity == Q->front);
}

int QueueSize(DAQ *Q)
{
      return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}

DAQ *ResizeQueue(DAQ *Q)
{
      int size = Q->capacity;
      Q->capacity = Q->capacity * 2;
      Q->array = realloc(Q->array, Q->capacity);
      if (Q->array == NULL)
      {
            printf("Can't realloc memory!\n");
            return NULL;
      }
      if (Q->front > Q->rear)
      {
            for (int i = 0; i < Q->front; i++)
            {
                  Q->array[i + size] = Q->array[i];
            }
      }
      Q->rear = Q->rear + size;
      return Q;
}

DAQ *EnQueue(DAQ *Q, int data)
{
      if (IsFullQueue(Q))
      {
            Q = ResizeQueue(Q);
      }

      Q->rear = (Q->rear + 1) % Q->capacity;
      Q->array[Q->rear] = data;
      if (Q->front == -1)
      {
            Q->front = Q->rear;
      }

      return Q;
}

DAQ *DeQueue(DAQ *Q)
{
      if (IsEmptyQueue(Q))
      {
            printf("Queue is Empty!\n");
            return NULL;
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

void DeleteQueue(DAQ *Q)
{
      if (Q)
      {
            if (Q->array)
            {
                  free(Q->array);
            }
            free(Q);
      }
}

void printQueue(DAQ *Q)
{
      if (IsEmptyQueue(Q))
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
      DAQ *List = Queue(10);
      for (int i = 0; i < List->capacity; i++)
      {
            List = EnQueue(List, i + 1);
      }
      printQueue(List);
      for (int i = 0; i < List->capacity; i++)
      {
            printf("%d %d\n", List->front, List->rear);
            List = DeQueue(List);
      }
      
      printQueue(List);
}