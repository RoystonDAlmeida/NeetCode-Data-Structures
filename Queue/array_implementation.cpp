#include<iostream>
using namespace std;

class Queue{
    public:
            int front,rear,size;
            unsigned cap;
            int *arr;
};

Queue* createQueue(unsigned cap)
{
    Queue *queue=new Queue();
    queue->front=queue->size=0;
    queue->rear=cap-1;
    queue->cap=cap;
    queue->arr=new int[(queue->cap*sizeof(int))];
    return queue;
}

bool isFull(Queue *queue)
{
    return (queue->size==queue->cap);
}

void enqueue(Queue *queue, int item)
{
    // First, check if the queue is full or not
    if(isFull(queue))
    {
        cout<<"\nQueue is full";
        return;
    }
    // Increment the rear and size of the queue
    queue->rear=((queue->rear)+1)%queue->cap;
    queue->size=queue->size+1;
    queue->arr[queue->rear]=item;
    cout<<item<<"is enqueued into the queue\n";
}

bool isEmpty(Queue *queue)
{
    return (queue->size==0);
}

void dequeue(Queue *queue)
{
    // First check if the queue is empty or not
    if(isEmpty(queue))
    {
        cout<<"Queue is empty\n";
        return;
    }
    
    // Increment front and decrement size
    int item=queue->arr[queue->front];
    cout<<item<<"is popped from the queue\n";
    queue->front=((queue->front)+1)%queue->cap;
    queue->size=queue->size-1;
}

int front(Queue *queue)
{
    return queue->arr[queue->front];
}

int rear(Queue *queue)
{
    return queue->arr[queue->rear];
}
int main()
{
    //Creation of a queue 
    Queue *queue=createQueue(1000);
    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);
    enqueue(queue,40);
    dequeue(queue);
    
    // Peeking front and rear element of the queue
    cout<<front(queue)<<"\t is the front element of the queue\n";
    cout<<rear(queue)<<"\t is the rear element of the queue\n";
    
    return 0;
}
