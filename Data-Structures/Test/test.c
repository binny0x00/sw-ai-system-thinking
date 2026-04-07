// 1
int main(void)
{

    int arr[5] = {1, 2, 3, 4, 5};

    // 코드 작성
    int size = sizeof(arr);

    for (int i = size - 1; i > -1; i--)
    {
        print(arr[i]);
    }

    printf("\n");

    return 0;
}

// 2
#include <stdio.h>

#include <stdlib.h>

int main()
{

    int *arr = (int *)malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {

        arr[i] = i * i;
    }

    printf("%d\n", arr[3]); // 결과 기입

    // start of code

    ….
        // end of code

        return 0;
}

/*
기존 코드는 arr의 주소로 접근해 주소가 가리키는 값을 바꾸는 게 아닌, 메모리상 stack에 올라가는 지역변수의 값을 수정하는 코드이다. printf문으로 출력되는 값은 쓰레기값으로 코드 작성자가 알 수 없다.
올바르게 수정하면 *(arr+i) = i * i; 이다.
수정 후 출력하면 결과는 9이다.
*/

// 3

#include <stdio.h>

void func(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        (*(arr + 1))++;
    }
}

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};

    func(arr, 5);

    for (int i = 0; i < 5; i++)
    {

        printf("%d ", arr[i]);
    }

    return 0;
}

// 4
// 없다

// 5
void update(int p) { p = 200; }

void update1(int *p) { *p = 100; }

void update2(int **p) { **p = 1000; }

int main()
{

    int x = 10;

    int *p = &x; // p는 x를 가리키는 포인터

    update(x);
    printf("%d\n", x); // 10

    update1(&x);
    printf("%d\n", x); // 100

    update2(&p);
    printf("%d\n", x); // 에러가 발생하거나 알 수 없는 값 출력

    update1(p);
    printf("%d\n", x); // 100
}

// 6
ypedef struct _listnode
{

    int item;

    struct _listnode *next;

} ListNode;

typedef struct _linkedlist
{

    int size;

    ListNode *head;

} LinkedList;

ListNode *findNode(LinkedList *ll, int index)
{

    ListNode *temp;

    if (ll == NULL || ll->size < index)
    {
        return -1;
    }

    temp->item = 0;
    temp->next = NULL;

    temp = ll->head;

    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }

    return temp;
}