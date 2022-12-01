#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
      int data;
      struct ListNode *next;
} LN;

LN *CreateStack()
{
      return NULL;
}

LN *Push(LN *top, int data)
{
      LN *temp;
      temp = (LN *)malloc(sizeof(LN));
      if (!temp)
      {
            printf("Can't allocate memory!\n");
            return top;
      }
      temp->data = data;
      temp->next = top;
      top = temp;
}

int IsEmptyStack(LN *top)
{
      return top == NULL;
}

LN *Pop(LN *top)
{
      if(IsEmptyStack(top))
      {
            printf("Stack is now empty\n");
            return NULL;
      }
      return top->next;
}

int Top(LN * top)
{
      if(IsEmptyStack(top))
      {
            printf("Stack is now empty\n");
            return 0;
      }
      return top->data;
}

LN * DeleteStack(LN * top)
{
      LN * p, * temp;
      p = top;
      while(p->next != NULL)
      {
            temp = p->next;
            p->next = temp->next;
            free(temp);
      }
      free(p);
      return NULL;
}

void printStack(LN * top)
{
      if(top == NULL)
      {
            printf("Stack is now empty\n");
      }
      while(top != NULL)
      {
            printf("%d ", top->data);
            top = top->next;
      }
      printf("\n");
}

int main()
{
      LN * Stack = CreateStack();

      for(int i = 0; i < 10; i++)
      {
            Stack = Push(Stack, i+1);
      }
      printf("The top element of the stack is: %d\n", Top(Stack));
      printStack(Stack);
      for(int i = 10; i < 20; i++)
      {
            Stack = Push(Stack, i+1);
      }
      printf("The top element of the stack is: %d\n", Top(Stack));
      printStack(Stack);
      for(int i = 0; i < 20; i++)
      {
            Stack = Pop(Stack);
      }
      printStack(Stack);
      return 0;
}