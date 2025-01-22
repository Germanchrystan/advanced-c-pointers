#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct listitem
{
  struct listitem *next;
  int data
} LISTITEM;

int main ()
{
  LISTITEM *listhead, *temp;

  listhead = NULL;

  for (int i = 0; i < 3; i++)
  {
    temp = malloc(sizeof(LISTITEM));
    temp -> data = i;
    temp -> next = listhead;
    listhead = temp;
  }

  temp = listhead;
  while(temp != NULL)
  {
    printf("list item: current is %p; next is %p; data is %d\n", temp, temp->next, temp->data);
    temp = temp->next;
  }

  return 0;
}