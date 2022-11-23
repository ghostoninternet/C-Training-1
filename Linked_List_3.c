#include <stdio.h>
#include <stdlib.h>

typedef struct CircularLinkListNode
{
      int value;
      struct CircularLinkListNode *next;
} CLLNode;

CLLNode *makeNode(int k)
{
      CLLNode *p = (CLLNode *)malloc(sizeof(CLLNode));
      p->value = k;
      p->next = p;
      return p;
}

CLLNode *insertLast(CLLNode *head, int k)
{
      CLLNode *p = makeNode(k);
      p->next = head;
      head->next = p;
      return head;
}

void printList(CLLNode *head)
{
      if (head == NULL)
      {
            printf("List is empty\n");
            return;
      }
      CLLNode *p = head;
      do
      {
            printf("%d ", p->value);
            p = p->next;
      } while (p != head);
      printf("\n");
}

int countList(CLLNode *head)
{
      int count = 0;
      if (head == NULL)
      {
            return 0;
      }

      CLLNode *p = head;
      do
      {
            p = p->next;
            count++;
      } while (p != head);
      return count;
}

int main()
{
      CLLNode *CircularList = makeNode(10);
      CircularList = insertLast(CircularList, 20);
      printf("Number of elements: %d\n", countList(CircularList));
      printList(CircularList);
      return 0;
}