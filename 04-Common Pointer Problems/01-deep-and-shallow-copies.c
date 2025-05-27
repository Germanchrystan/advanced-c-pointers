#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBUFLEN 10

typedef struct listitem {
    struct listitem *next;
    struct listitem *prev;
    char *data;
} LISTITEM;

typedef struct {
    struct listitem *first;
    struct listitem *last;
} LISTHDR;

LISTHDR original;
LISTHDR deep_copy;
LISTHDR shallow_copy;

void enqueue(LISTHDR *queue, LISTITEM *item) {
  LISTITEM *temp;

  temp = queue->last;
  queue->last = item;
  item->prev = temp;

  item->next = (LISTITEM*)queue;
  temp->next = item;
}

LISTITEM *dequeue(LISTHDR *queue) {
  LISTITEM *temp;

  temp = queue->first;
  if(temp == (LISTITEM*)queue) {
    return NULL; // Queue is empty
  }
  queue->first = temp->next;
  queue->first->prev = (LISTITEM*)queue;

  return temp;
}

int queue_length(LISTHDR *queue) {
  LISTITEM *temp;
  int length;

  temp = queue->first;
  length = 0;

  do {
    if(temp == (LISTITEM*)queue) {
      temp = NULL;
      break;
    }
    temp = temp->next;
    length = length + 1;
    
  } while(temp != NULL);
  
  return length;
}

int main() {
  LISTITEM *temp, *temp1;

  char *pdata;

  original.first = (LISTITEM*)&original;
  original.last = (LISTITEM*)&original;
  deep_copy.first = (LISTITEM*)&deep_copy;
  deep_copy.last = (LISTITEM*)&deep_copy;
  shallow_copy.first = (LISTITEM*)&shallow_copy;
  shallow_copy.last = (LISTITEM*)&shallow_copy;

  for(int i = 0; i < 3; i++)  {
    temp = malloc(sizeof(LISTITEM));
    temp->data = (char*)malloc(MAXBUFLEN); // temp->data = (char*)malloc(MAXBUFLEN * sizeof(char));
    snprintf(temp->data, MAXBUFLEN, "%d", i); // set it to the character string of the index
    enqueue(&original, temp);
  }

  // NOTE: this shows how to iterate over a queue explicitly
  printf("The length of the original queue is %d\n", queue_length(&original));
  temp = original.first;
  do {
    printf("data in original queue is '%s' at address %p\n", temp->data, temp->data);
    temp = temp->next;
  } while (temp->next != original.first);

  // CREATE A DEEP COPY
  temp = original.first;
  do {
    temp1 = (LISTITEM*)malloc(sizeof(LISTITEM)); // allocate memory ofr a new queue item
    memcpy(temp1, temp, sizeof(LISTITEM)); // make a copy
    pdata = (char*)malloc(MAXBUFLEN); // allocate memory for new data
    memcpy(pdata, temp->data, MAXBUFLEN); // copy the data from the original item
    temp1->data = pdata;
    enqueue(&deep_copy, temp1); // add to the deep copy queue
    temp = temp->next;
  } while(temp->next != original.first);
  

  printf("the length of the deep copy queue is %d\n", queue_length(&deep_copy));
  temp = deep_copy.first;
  do {
    printf("data is deep copy queue is '%s' at address %p\n",temp->data, temp->data);
    temp = temp->next;
  } while(temp->next != deep_copy.first);

  // CREATE A SHALLOW COPY
  // Note: the difference between deep and shallow is that the payload or data item is NOT copied.
  // So the original and the copy queue items point to the same data.
  temp = original.first;
  do {
    temp1 = (LISTITEM*)malloc(sizeof(LISTITEM));
    memcpy(temp1, temp, sizeof(LISTITEM));
    enqueue(&shallow_copy, temp1);
    temp = temp->next;
  } while(temp->next != original.first);

  printf("the length of the shallow copy queue is %d\n", queue_length(&shallow_copy));
  temp = shallow_copy.first;
  do {
    printf("data in shallow copy queue is '%s' at address %p\n",temp->data, temp->data);
    temp = temp->next;
  } while(temp->next != shallow_copy.first);

  // FREE THE ORIGINAL
  do {
    temp = dequeue(&original);
    if (temp != NULL) {
      free(temp->data);
      free(temp);
    }
  } while (temp != NULL);

  // LOOK AT THE SHALLOW AND DEEP COPIES
  printf("\n\nafter deleting the original queue\n");
  printf("The length of the deep copy queue is %d\n", queue_length(&deep_copy));
  temp = deep_copy.first;

  do {
    printf("data in deep copy queue is '%s' at address %p\n", temp->data, temp->data);
    temp = temp->next;
  } while (temp->next != deep_copy.first);

  printf("the length of the shallow copy queue is %d\n", queue_length(&shallow_copy));
  temp = shallow_copy.first;
  do {
    printf("data in shallow copy queue is '%s' at address %p\n", temp->data, temp->data);
    temp = temp->next;
  } while(temp->next != shallow_copy.first);

  return 0;
}