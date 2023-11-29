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
    tmpNode = Stack->peek;
    Stack->peek = Stack->peek->next;
    Stack->size--;
}

int sum(listStack* Stack)
{
    int sum = 0;
    Node* horse = Stack->peek;
    for(int i=0; i<(Stack->size); i++)
    {
        sum += *horse->data;
        horse = horse->next;
    }
    return sum;
}

int main (void)
{
    int K;
    listStack* Stack;
    createStack(&Stack);
    scanf("%d", &K);

    for(int i=0; i<K; i++)
    {
        int num;
        scanf("%d", &num);
        if(num != 0)
            push(Stack, createNode(num));
        else 
            pop(Stack);
    }
    printf("%d\n", sum(Stack));
    return 0;
}