#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct listitem
{
  struct listitem *next;
  struct listitem *prev;
  int data;
} LISTITEM;

int main()
{
  LISTITEM *temp, head;

  head.next = (LISTITEM*)&head;
  head.prev = (LISTITEM*)&head;
  head.data = -1;

  for (int i = 0; i < 3; i++)
  {
    temp = malloc(sizeof(LISTITEM));
    temp->data = i;
    temp->next = head.next;
    head.next = temp;
    temp->prev = &head;
    temp->next->prev = temp;
  }

  // Now let's see what we got going forwards
  temp = head.next;
  while(temp != &head) 
  {
    printf("forward list item: current is %p; next is %p; prev is %p; data is %d\n", temp, temp->next, temp->prev, temp->data);
  }

  // Now let's see what we got going backwards
  temp = head.prev;
  while(temp != &head) 
  {
    printf("backward list item: current is %p; next is %p; prev is %p; data is %d\n", temp, temp->next, temp->prev, temp->data);
  }

  return 0;
}