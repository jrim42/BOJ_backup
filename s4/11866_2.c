//circular queue
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int Data;
    struct node* Next;
} Node;

typedef struct listQueue
{
    Node *Front;
    Node *Rear;
    int size;
} cirQueue;

cirQueue* createList(void)
{
    cirQueue *ls = (cirQueue*)malloc(sizeof(cirQueue)); 
    ls->Front = NULL;
    ls->Rear = NULL;
    ls->size = 0;

    return ls;
}

Node* createNode (int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->Data = data;
    newNode->Next = NULL;

    return newNode;
}

void addFront(cirQueue *ls, Node* newNode)
{
    
    if(ls->Front == NULL)
    {
        ls->Front = newNode;
        ls->Rear = newNode;
        newNode->Next = newNode;
    }
    else //unempty list
    {
        newNode->Next = ls->Front;
        ls->Rear->Next = newNode;
        ls->Front = newNode;
    }
    ls->size++;
}

void removeNode(cirQueue *ls, int pos)
{
    Node *tmp;
    Node *cur = ls->Front;

    if(pos == 1)
    {
        tmp = ls->Front->Next;
        ls->Rear->Next = tmp;

        printf("%d", cur->Data);

        free(cur);
        ls->Front = tmp;
        ls->size--;
    }
    else
    {
        for(int i=1; i<pos-1; i++)
        {
            cur = cur->Next;
        }
        for(int i=0; i<pos; i++)
        {
            ls->Front = ls->Front->Next;
            ls->Rear = ls->Rear->Next;
        }
        //tmp는 지워야 할 노드
        //cur은 지워야할 노드의 이전 노드가 된다
        tmp = cur->Next;
        cur->Next = tmp->Next;
        printf("%d", tmp->Data);
        free(tmp);
        ls->size--;

        //꼬리를 cur에, 머리를 cur->Next로 만든다
    }
}

int main (void)
{
    int N, K;
    scanf("%d %d", &N, &K);
    cirQueue *ls = createList();
    for(int i=N; i>0; i--)
    {
        addFront(ls, createNode(i));
    }
    
    printf("<");
    for(int i=0; i<N; i++)
    {
        removeNode(ls, K);
        if(i != N-1)
            printf(", ");
    }
    printf(">\n");
    return 0;
}