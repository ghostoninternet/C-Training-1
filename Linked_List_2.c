/*
Down here are operations to work with Single Linked List
This is the first version, I did this by my own with the help from Lecture's slide: "Cấu trúc dữ liệu và thuật toán" - HUST and "Data Structure and Algorithms Made Easy Chapter 3"
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
      int value;
      struct DNode * next;
      struct DNode * prev;
}DNode;

DNode * makeNode(int k)
{
      DNode * p = (DNode *)malloc(sizeof(DNode));
      p->value = k;
      p->next = NULL;
      p->prev = NULL;
      return p;
}

DNode * lastNode(DNode * head)
{
      while(head->next != NULL)
      {
            head = head->next;
      }
      return head;
}

DNode * firstNode(DNode * head)
{
      if(head == NULL)
      {
            printf("List is empty!\n");
            return NULL;
      }
      DNode * p = head;
      return p;
}

DNode * getPosition(DNode * head, int k)
{
      DNode * p = head;
      while(p != NULL)
      {
            if(p->value == k)
            {
                  return p;
            }
            p = p->next;
      }
      printf("Can't find value %d in list\n", k);
      return NULL;
}

DNode *nextPosition(DNode * head, DNode *p)
{
      DNode * q = head;
      while(q != NULL)
      {
            if(q->prev == p)
            {
                  return q;
            }
            q = q->next;
      }
      printf("Can't find postion after p\n");
      return NULL;
}

DNode * prevPositon(DNode * head, DNode * p)
{
      DNode * q = head;
      while(q  != NULL)
      {
            if(q->next == p)
            {
                  return q;
            }
            q = q->next;
      }
      printf("Can't find postion previous q\n");
      return NULL;
}

DNode * emptyList(DNode * head)
{
      while(head->next != NULL)
      {
            head = head -> next;
            free(head->prev);
      }
      return head->next;
}

DNode * deleteNode(DNode * head, DNode *p)
{
      if(head == NULL)
      {
            printf("List is empty\n");
            return NULL;
      }
      if(p == NULL)
      {
            printf("Can't found value to delete\n");
      }
      if(head == p)
      {
            return head->next;
      }

      DNode * q = head;
      while(q != NULL)
      {
            if(q->next == p)
            {
                  if(p->next == NULL)
                  {
                        q->next = NULL;
                        return head;
                  }
                  else if(p->next != NULL)
                  {
                        q->next = p->next;
                        p = p->next;
                        p->prev = q;
                        return head;
                  }
            }
            q = q->next;
      }
}

DNode * insertBefore(DNode * head, DNode * p, int k)
{
      DNode * q = makeNode(k);
      DNode * before_p = prevPositon(head, p);

      if(before_p == NULL)
      {
            if(head == NULL)
            {
                  return q;
            }
            q->next = head;
            head->prev = q;
            return q;
      }
      before_p->next = q;
      q->prev = before_p;
      q->next = p;
      p->prev = q;
      return head;
}

DNode * insertAfter(DNode * head, DNode * p, int k)
{
      DNode * q = makeNode(k);
      if(head == NULL)
      {
            return q;
      }
      DNode * next_pos = nextPosition(head, p);
      p->next = q;
      q->prev = p;
      q->next = next_pos;
      next_pos->prev = q;
      return head;
}

DNode * insertLast(DNode * head, int k)
{
      DNode * p = makeNode(k);
      if(head == NULL)
      {
            return p;
      }
      DNode *q = head;
      while(q->next != NULL)
      {
            q = q->next;
      }
      q->next = p;
      p->prev = q;
      return head;
}

DNode * insertFirst(DNode * head, int k)
{
      DNode *p = makeNode(k);
      p->next = head;
      head->prev = p;
      head = p;
      return head;
}

void printList(DNode * head)
{
      if(head == NULL)
      {
            printf("This List is empty\n");
            return;
      }
      while(head != NULL)
      {
            printf("%d ", head->value);
            head = head->next;
      }
      printf("\n");
}

int main()
{
      DNode * List = makeNode(10);
      List = insertFirst(List, 20);
      printList(List);
      List = insertLast(List, 40);
      printList(List);
      DNode * p = getPosition(List, 10);
      List = insertAfter(List, p, 30);
      printList(List);
      p = getPosition(List, 30);
      List = insertBefore(List, p, 50);
      printList(List);
      p = getPosition(List, 20);
      List = deleteNode(List, p);
      printList(List);
      List = emptyList(List);
      printList(List);
      return 0;
}