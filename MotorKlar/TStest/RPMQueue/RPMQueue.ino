// C program for array implementation of queue
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include<LiquidCrystal.h>


//creating a circular queue
struct Queue {
  int front, rear, sizeIs;
  unsigned int capacity;                                          //array size
  long* array;                                                
};

struct Queue* createQueue(unsigned capacity)                    //create queue
{
  struct Queue* queue = (struct Queue*)calloc(1,                //make space in memory for queue
    sizeof(struct Queue));
  queue->capacity = capacity;
  queue->front = queue->sizeIs = 0;

  queue->rear = capacity - 1;
  queue->array = (long*)calloc(
    queue->capacity, sizeof(long));                        
  return queue;
}

int isFull(struct Queue* queue)
{
  return (queue->sizeIs == queue->capacity);
}

int isEmpty(struct Queue* queue)
{
  return (queue->sizeIs == 0);
}

void enqueueAndUpdate(struct Queue* queue, long item, long minItem)
{
  while( (!isEmpty(queue)) && (queue->array[queue->front] < minItem))
  {
    dequeue(queue);
  }
  if (isFull(queue))
    return;
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = item;
  queue->sizeIs = queue->sizeIs + 1;
  
}

long dequeue(struct Queue* queue)                             // remove from queue
{
  if (isEmpty(queue))
    return -1;
  long item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->sizeIs = queue->sizeIs - 1;
  return item;
}

double getLastEntries(Queue* queue, long minTime)
{
  if(isEmpty(queue))
    return 0;
    
  double rev = 0;
  int index = queue->rear;
  while( (minTime < queue->array[index]) && (rev < queue->sizeIs))
  {
    rev = rev + 1;
    index = index - 1;
    if(index < 0)
      index = queue->capacity - 1;
  }
  return rev;
}

long front(struct Queue* queue)                               // beginning of queue
{
  if (isEmpty(queue))
    return -1;
  return queue->array[queue->front];
}

long rear(struct Queue* queue)                                // end of queue
{
  if (isEmpty(queue))
    return -1;
  return queue->array[queue->rear];
}
