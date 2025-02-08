#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listitem 
{
  struct listitem *next;
  struct listitem *prev;
  int data;
} LISTITEM;

typedef struct 
{
  struct listitem *first;
  struct listitem *last;
} LISTHDR;

LISTHDR head;

void enqueue (LISTITEM *item) 
{
  LISTITEM *temp;

  temp = head.last; // Get the last item in the queue and keep hold of it
  head.last = item; // put the item in the queue at the end
  item -> prev = temp; // link back to old last item
  item -> next = (LISTITEM*)&head; // set the forward link of the new item
  temp->next = item; // finally set the forward link of the old last item to the new one
}

LISTITEM* dequeue()
{
  LISTITEM *temp;

  temp = head.first; // Get the first element
  if (temp == (LISTITEM*)&head)
  {
    temp = NULL;
  }
  else 
  {
    head.first = temp->next;
    head.last -> prev = (LISTITEM*) &head;
  }

  return temp;
}

int main()
{
  LISTITEM *temp;

  head.first = (LISTITEM*) &head;
  head.last = (LISTITEM*) &head;

  for (int i = 0; i < 3; i++)
  {
    temp = malloc(sizeof(LISTITEM));
    temp->data = i;
    enqueue(temp);
  }

}