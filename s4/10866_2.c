#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode
{
    int Data;
    struct listNode* Next;
    struct listNode* Prev;
} Node;

typedef struct listDeque
{
    Node* Head;
    Node* Tail;
    int size;
} listDeque;

void createDeque(listDeque** Deque)
{
    (*Deque) = (listDeque*)malloc(sizeof(listDeque)); 
    (*Deque)->Head = NULL;
    (*Deque)->Tail = NULL;
    (*Deque)->size = 0;
}

void size(listDeque* Deque)
{
    printf("%d\n", Deque->size);
}

void empty(listDeque* Deque)
{
    if(Deque->size == 0)
        printf("1\n");
    else
        printf("0\n"); 
}

void front(listDeque* Deque)
{
    if(Deque->size == 0)
        printf("-1\n");
    else
        printf("%d\n", Deque->Head->Data);
}

void back(listDeque* Deque)
{
    if(Deque->size == 0)
        printf("-1\n");
    else
        printf("%d\n", Deque->Tail->Data);
}

void pushFront (listDeque* Deque, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Data = data;
    newNode->Next = Deque->Head;
    
    if(Deque->size == 0)
        Deque->Tail = newNode;
    else
        Deque->Head->Prev = newNode;

    newNode->Prev = NULL;
    Deque->Head = newNode;
    Deque->size++;
}

void pushBack (listDeque* Deque, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Data = data;
    newNode->Prev = Deque->Tail;
    
    if(Deque->size == 0)
        Deque->Head = newNode;
    else
        Deque->Tail->Next = newNode;
    
    newNode->Next = NULL;
    Deque->Tail = newNode;
    Deque->size++;
}

void popFront (listDeque* Deque)
{
    Node* tmpNode = Deque->Tail;

    if(Deque->size == 0)
    {
        printf("-1\n");
        return;
    }
    else if (Deque->size == 1)
    {
        Deque->Head = NULL;
        Deque->Tail = NULL;
        Deque->size--;
    }
    else
    {
        Deque->Tail = Deque->Tail->Prev;
        Deque->Tail->Next = NULL;
        Deque->size--;
    }
    printf("%d\n", tmpNode->Data);
    free(tmpNode);
}


void popBack (listDeque* Deque)
{
    Node* tmpNode = Deque->Head;

    if(Deque->size == 0)
    {
        printf("-1\n");
        return;
    }
    else if (Deque->size == 1)
    {
        Deque->Head = NULL;
        Deque->Tail = NULL;
        Deque->size--;
    }
    else
    {
        Deque->Head = Deque->Head->Next;
        Deque->Head->Prev = NULL;
        Deque->size--;
    }
    printf("%d\n", tmpNode->Data);
    free(tmpNode);
}

int main (void)
{
    int i, N;
    listDeque* Deque;
    createDeque(&Deque);

    scanf("%d", &N);
    for(i=0; i<N; i++)
    {
        char cmd[12];
        scanf("%s", cmd);
        if(strcmp(cmd, "push_front") == 0)
        {
            int num;
            scanf("%d", &num);
            pushFront(Deque, num);  
        }
        else if(strcmp(cmd, "push_back") == 0)
        {
            int num;
            scanf("%d", &num);
            pushBack(Deque, num);
        }
        else if (strcmp(cmd, "pop_front") == 0)
            popBack(Deque);
        else if (strcmp(cmd, "pop_back") == 0)
            popFront(Deque);
        else if (strcmp(cmd, "size") == 0)
            size(Deque);
        else if (strcmp(cmd, "empty") == 0)
            empty(Deque);
        else if (strcmp(cmd, "front") == 0)
            front(Deque);
        else if (strcmp(cmd, "back") == 0)
            back(Deque);
    }
    return 0;
}
    