#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNode
{
    int *data;
    struct sNode* next;
} Node;

typedef struct listStack
{
    Node *peek;
    int size;
} listStack;

void createStack (listStack** Stack)
{
    (*Stack) = (listStack*)malloc(sizeof(listStack));
    (*Stack)->peek = NULL;
    (*Stack)->size = 0;
}

Node* createNode (int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = (int*)malloc(sizeof(int));

    *newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void push (listStack* Stack, Node* newNode)
{
    if(Stack->size == 0)
    {
        Stack->peek = newNode;
    }
    else
    {
        newNode->next = Stack->peek;
        Stack->peek = newNode;
    }
    Stack->size++;
}

void pop (listStack* Stack)
{
    Node* tmpNode;
    if(Stack->size == 0)
    {
        printf("-1\n");
        return;
    }
    else
    {
        tmpNode = Stack->peek;
        Stack->peek = Stack->peek->next;
        Stack->size--;
    }
    printf("%d\n", *tmpNode->data); 
    return;
}

void size(listStack* Stack)
{
    printf("%d\n", Stack->size);
}

void empty(listStack* Stack)
{
    if(Stack->size == 0)
        printf("1\n");
    else
        printf("0\n");
}

void top(listStack* Stack)
{
    if(Stack->size == 0)
        printf("-1\n");
    else
        printf("%d\n", *Stack->peek->data);
}

int main (void)
{
    int i, N;
    listStack* Stack;
    createStack(&Stack);

    scanf("%d", &N);
    for(i=0; i<N; i++)
    {
        char cmd[6];
        scanf("%s", cmd);
        if(strcmp(cmd, "push") == 0)
        {
            int num;
            scanf("%d", &num);
            push(Stack, createNode(num));
        }
        else if (strcmp(cmd, "pop") == 0)
            pop(Stack);
        else if (strcmp(cmd, "size") == 0)
            size(Stack);
        else if (strcmp(cmd, "empty") == 0)
            empty(Stack);
        else if (strcmp(cmd, "top") == 0)
            top(Stack);
    }

    return 0;
}