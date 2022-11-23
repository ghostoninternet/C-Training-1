/*
Down here are operations to work with Single Linked List
This is the first version, I did this by my own with the help from Lecture's slide: "Cấu trúc dữ liệu và thuật toán" - HUST
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
      int value;
      struct Node *next;
} Node;

Node *makeNode(int k)
{
      Node *p = (Node *)malloc(sizeof(Node));
      p->value = k;
      p->next = NULL;
      return p;
}

Node * emptyNode(Node * head)
{
      while(head->next != NULL)
      {
            head = head->next;
      }
      return head->next;
}

Node *firstPosition(Node * head)
{
      if(head == NULL)
      {
            return NULL;
      }

      Node *q = head;
      return q;
}

Node *lastPostion(Node * head)
{
      if(head == NULL)
      {
            return NULL;
      }

      Node * q = head;
      while(q->next != NULL)
      {
            q = q->next;
      }
      return q;
}

Node * deleteNode(Node * head, Node * p)
{
      if(head == NULL || p == NULL)
      {
            return head;
      }
      if(head == p)
      {
            head = head->next;
            return head;
      }

      Node * q = head;

      while(q->next != NULL)
      {
            if(q->next == p)
            {
                  q->next = p->next;
                  return head; 
            }
            q = q->next;
      }
}

Node *getPosition(Node *head, int k)
{
      Node *p = head;
      while (p != NULL)
      {
            if (p->value == k)
            {
                  return p;
            }
            p = p->next;
      }
      return NULL;
}

Node *nextNode(Node *head, Node *p)
{
      Node *q = head;
      while(q->next != NULL)
      {
            if(q->next == p)
            {
                  return p->next;
            }
            q = q->next;
      }
      return NULL;
}

Node *prevNode(Node *head, Node *p)
{
      Node *q = head;
      while (q->next != NULL)
      {
            if (q->next == p)
            {
                  return q;
            }
            q = q->next;
      }
      return NULL;
}

Node *insertBefore(Node *head, Node *p, int k)
{
      Node *before_p = prevNode(head, p);
      Node *newNode = makeNode(k);
      if (before_p == NULL)
      {
            if (head == NULL)
            {
                  return newNode;
            }
            newNode->next = head;
            return newNode;
      }
      else
      {
            newNode->next = before_p->next;
            before_p->next = newNode;
            return head;
      }
}

Node *insertAfter(Node *head, Node *p, int k)
{
      if (head == NULL)
      {
            return NULL;
      }
      if (p == NULL)
      {
            return head;
      }

      Node *q = makeNode(k);
      q->next = p->next;
      p->next = q;

      return head;
}

Node *insertLast(Node *head, int k)
{
      if (head == NULL)
      {
            return makeNode(k);
      }
      Node *p = head;
      while (p->next != NULL)
      {
            p = p->next;
      }
      Node *q = makeNode(k);
      p->next = q;
      return head;
}

Node *insertFirst(Node *head, int k)
{
      Node *p = makeNode(k);
      p->next = head;
      head = p;
      return head;
}

void printList(Node *head)
{
      if (head == NULL)
      {
            printf("List is empty\n");
            return;
      }
      while (head != NULL)
      {
            printf("%d ", head->value);
            head = head->next;
      }
      printf("\n");
}

int countElement(Node *head)
{
      int count = 1;
      if (head == NULL)
            return 0;
      while (head->next != NULL)
      {
            count++;
            head = head->next;
      }
      return count;
}

int main()
{
      Node *List;
      List = makeNode(18);
      List = insertFirst(List, 20);
      List = insertLast(List, 22);
      printList(List);
      printf("Co %d phan tu.\n", countElement(List));
      Node *p = List->next;
      List = insertAfter(List, p, 19);
      printList(List);
      p = getPosition(List, 19);
      List = insertBefore(List, p, 17);
      printList(List);
      p = getPosition(List, 17);
      Node *after_p = nextNode(List, p);
      printf("The Node's value after Node p is: %d\n", after_p->value);
      List = deleteNode(List, p);
      printList(List);
      p = getPosition(List , 20);
      List = deleteNode(List, p);
      printList(List);
      Node * first = firstPosition(List);
      printf("The first Node in the list: %d\n", first->value);
      Node * last = lastPostion(List);
      printf("The final Node in the list: %d\n", last->value);
      List = emptyNode(List);
      printList(List);
      return 0;
}