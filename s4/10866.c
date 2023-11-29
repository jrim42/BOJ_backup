#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
    int Data;
    struct listNode* Next;
    struct listNode* Prev;
} Node;

typedef struct deque
{
    Node* head;
    Node* tail;
} Deque;


Node* createNode (int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->Data = data;
    newNode->Next = NULL;
    newNode->Prev = NULL;

    return newNode;
}

void deleteNode (Node* Node)
{
    free(Node);
}

void size(Node* head)
{
    int cnt = 0;
    Node* horse = head;

    while(horse !=NULL)
    {
        horse = horse->Next;
        cnt++;
    }
    printf("%d\n", cnt);
}

int empty(Node* head)
{
    int cnt = 0;
    Node* horse = head;

    while(horse !=NULL)
    {
        horse = horse->Next;
        cnt++;
    }
    if(cnt == 0)
    {
        printf("1\n");
        return 1;
    }
    else
    {
        printf("0\n", cnt);
        return 0;
    }   
}

void front(Node* head)
{
    printf("%d\n", head->Next->Data);
}

void back(Node* head)
{
    Node* horse = head;

    while(horse !=NULL)
    {
        horse = horse->Next;
    }
    printf("%d\n", horse->Data);
}

void pushFront (Node** head, Node* newNode)
{
    if((*head) == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node* horse = (*head);

        horse->Next = newNode;
        newNode->Prev = horse;
    }
}

void pushBack (Node** head, Node* newNode)
{
    if((*head) == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node* horse = (*head);

        while(horse->Next != NULL)
        {
            horse = horse->Next;
        }
        horse->Next = newNode;
        newNode->Prev = horse;
    }
}

void popFront (Deque* )
{
    if(empty(*head))

    Node* tmpNode = head;
    *head = *head->Next;
    deleteNode(remove);
}

void removeNode (Node** head, Node* remove)
{
    //remove head
    if(*head == remove)
    {
        *head = remove->Next; //헤드를 뒤로 밀어준다. 그냥 지워버리면 안됨.
    }
    //when remove has next link to go 
    if(remove->Next != NULL)
    {
        remove->Next->Prev = remove->Prev;
        //remove 다음노드의 prev를 remove 의 prev로 바꿔준다.
    }
    //when remove has prev link to go
    if(remove->Prev != NULL)
    {
        remove->Prev->Next = remove->Next;
    }

    //여기까지 하면 remove라는 노드를 가리키고 있는 노드는 아무것도 없어진다.
    deleteNode(remove);
}

int main (void)
{
    int i, N;
    Node* Deque = NULL;
    Node* newNode = NULL;
    Node* Current = NULL;

    scanf("%d", &N);
    for(i=0; i<N; i++)
    {
        char cmd[6];
        scanf("%s", cmd);
        if(strcmp(cmd, "push_front") == 0)
        {
            int num;
            scanf("%d", &num);
            newNode = createNode(i);
            pushFront(&Deque, newNode);
            
        }
        else if(strcmp(cmd, "push_back") == 0)
        {
            int num;
            scanf("%d", &num);
            newNode = createNode(i);
            pushBack(&Deque, newNode);
            
        }
        else if (strcmp(cmd, "pop_front") == 0)

        else if (strcmp(cmd, "pop_back") == 0)
            
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
    