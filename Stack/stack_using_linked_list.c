#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int isFull(struct node *top)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct node *top)
{
    if(top==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

struct node *push(struct node *top, int data)
{
    if(isFull(top))
    {
        printf("\n Stack Overflow");
    }
    else
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->link=top;
        top=temp;
    }
    return top;
}


void display_stack(struct node *top)
{
    while(top!=NULL)
    {
        printf("%d\t",top->data);
        top=top->link;
    }
}

int pop(struct node **top)
{
    if(isEmpty(*top))
    {
        printf("Stack Underflow");
    }
    else{
        struct node *temp=*top;
        *top=(*top)->link;
        int el=temp->data;
        free(temp);
        return el;
    }
}

void peek(struct node **top)
{
    printf("\n Top element:%d",(*top)->data);
}

void main()
{
    struct node *top=NULL;
    top=push(top,7);
    top=push(top,78);
    top=push(top,15);
    display_stack(top);
    
    int el=pop(&top);
    printf("\n Element popped:%d",el);
    display_stack(top);
}
