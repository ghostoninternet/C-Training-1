#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicArrayStack
{
      int top;
      int capacity;
      int *array;
} DAS;

DAS *CreateStack()
{
      DAS *S = (DAS *)malloc(sizeof(DAS));
      if (S == NULL)
      {
            printf("Can't allocate !");
            return NULL;
      }

      S->capacity = 1;
      S->top = -1;
      S->array = (int *)malloc(sizeof(int) * S->capacity);
      if (S->array == NULL)
      {
            printf("Can't allocate memory for stack");
            return NULL;
      }
      return S;
}

int IsEmptyStack(DAS *S)
{
      return (S->top == -1); // if the condition is true then 1 is returned else 0 is returned
}

int IsFullStack(DAS *S)
{
      return (S->top == S->capacity - 1);
}

DAS *DoubleStack(DAS *S)
{
      S->capacity *= 2;
      S->array = realloc(S->array, S->capacity * sizeof(int));
      return S;
}

DAS *Push(DAS *S, int data)
{
      if (IsFullStack(S))
      {
            S = DoubleStack(S);
      }
      S->top += 1;
      S->array[S->top] = data;
      return S;
}

DAS *Pop(DAS *S)
{
      if (IsEmptyStack(S))
      {
            printf("Empty Stack\n");
            return NULL;
      }
      else
      {
            S->top -= 1;
            return S;
      }
}

void DeleteStack(DAS *S)
{
      if (S != NULL)
      {
            if (S->array != NULL)
            {
                  free(S->array);
            }
            free(S);
      }
}

void printStack(DAS *S)
{
      if (S == NULL)
      {
            printf("The stack is now empty\n");
            return;
      }
      for (int i = 0; i <= S->top; i++)
      {
            printf("%d ", S->array[i]);
      }
      printf("\n");
}

int main()
{
      DAS *stack_of_number = CreateStack();
      for (int i = 0; i < 40; i++)
      {
            stack_of_number = Push(stack_of_number, i + 1);
      }
      printStack(stack_of_number);

      for (int i = 0; i <= 40; i++)
      {
            stack_of_number = Pop(stack_of_number);
            printStack(stack_of_number);
      }
      return 0;
}