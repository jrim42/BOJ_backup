#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct qNode
{
    int* Data;
    struct qNode* Next;
} Node;

typedef struct listQueue
{
    Node* Front;
    Node* Rear;
    int size;
} listQueue;

void createQ(listQueue** Queue)
{
    (*Queue) = (listQueue*)malloc(sizeof(listQueue)); 
    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
    (*Queue)->size = 0;
}

Node* createNode (int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Data = (int*)malloc(sizeof(data));
    
    *newNode->Data = data; 
    newNode->Next = NULL;

    return newNode;
}


void push(listQueue* Queue, Node* newNode)
{
    if(Queue->size == 0)
    {
        Queue->Front = newNode;
        Queue->Rear = newNode;
    }
    else
    {
        Queue->Rear->Next = newNode;
        Queue->Rear = newNode;
    }
    Queue->size++;
}

Node* pop(listQueue* Queue)
{
    Node* tmpNode = Queue->Front;

    if(Queue->size == 0)
    {
        printf("-1\n");
        return NULL;
    }
    else if (Queue->size == 1)
    {
        Queue->Front = NULL;
        Queue->Rear = NULL;
        Queue->size--;
    }
    else
    {
        Queue->Front = Queue->Front->Next;
        Queue->size--;
    }
    printf("%d\n", *tmpNode->Data); 
    return tmpNode;
}

void deleteNode (Node* removeNode)
{
    free(removeNode->Data);
    free(removeNode);
}

void size(listQueue* Queue)
{
    printf("%d\n", Queue->size);
}

void empty(listQueue* Queue)
{
    if(Queue->size == 0)
        printf("1\n");
    else
        printf("0\n");
}

void front(listQueue* Queue)
{
    if(Queue->size == 0)
        printf("-1\n");
    else
        printf("%d\n", *Queue->Front->Data);
}

void back(listQueue* Queue)
{
    if(Queue->size == 0)
        printf("-1\n");
    else
        printf("%d\n", *Queue->Rear->Data);
}

void deleteQ (listQueue* Queue)
{
    int cnt = Queue->size;
    while(cnt-- != 0)
    {
        Node* tmpNode = pop(Queue);
        deleteNode(tmpNode);
    }
    free(Queue);
}

int main (void)
{
    int i, N;
    listQueue* Queue;
    createQ(&Queue);

    scanf("%d", &N);
    for(i=0; i<N; i++)
    {
        char cmd[6];
        scanf("%s", cmd);
        if(strcmp(cmd, "push") == 0)
        {
            int num;
            scanf("%d", &num);
            push(Queue, createNode(num));
        }
        else if (strcmp(cmd, "pop") == 0)
            pop(Queue);
        else if (strcmp(cmd, "size") == 0)
            size(Queue);
        else if (strcmp(cmd, "empty") == 0)
            empty(Queue);
        else if (strcmp(cmd, "front") == 0)
            front(Queue);
        else if (strcmp(cmd, "back") == 0)
            back(Queue);
    }

    return 0;
}