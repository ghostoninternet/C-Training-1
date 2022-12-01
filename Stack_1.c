#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 40

typedef struct ArrayStack
{
      int top;
      int capacity;
      int * array;
}AS;

AS * CreateStack()
{
      AS * S = (AS *)malloc(sizeof(AS));
      if(S == NULL)
      {
            printf("Can't allocate !");
            return NULL;
      }

      S->capacity = MAXSIZE;
      S->top = -1;
      S->array = (int *)malloc(sizeof(int) * S->capacity);
      if(S->array == NULL)
      {
            printf("Can't allocate memory for stack");
            return NULL;
      }
      return S;
}

int IsEmptyStack(AS * S)
{
      return (S->top == - 1); //if the condition is true then 1 is returned else 0 is returned
}

int IsFullStack(AS * S)
{
      return (S->top == S->capacity - 1);
}

AS * Push(AS * S, int data)
{
      if(IsFullStack(S))
      {
            printf("Stackoverflow\n");
            return S;
      }
      else
      {
            S->top += 1;
            S->array[S->top] = data;
            return S;
      }
}

AS * Pop(AS * S)
{
      if(IsEmptyStack(S))
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

void DeleteStack(AS * S)
{
      if(S != NULL)
      {
            if(S->array != NULL)
            {
                  free(S->array);
            }
            free(S);
      }
}

void printStack(AS * S)
{
      if(S == NULL)
      {
            printf("The stack is now empty\n");
            return ;
      }
      for(int i = 0; i <= S->top; i++)
      {
            printf("%d ", S->array[i]);
      }
      printf("\n");
}

int main()
{
      AS * stack_of_number = CreateStack();
      for(int i = 0; i <= MAXSIZE; i ++)
      {
            stack_of_number = Push(stack_of_number, i+1);
      }
      printStack(stack_of_number);
      
      /*for(int i = 0; i <= MAXSIZE; i++)
      {
            stack_of_number = Pop(stack_of_number);
            printStack(stack_of_number);
      }*/
      DeleteStack(stack_of_number);
      printStack(stack_of_number);
      return 0;
}