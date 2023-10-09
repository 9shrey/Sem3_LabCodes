#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char str[20];
} String;

typedef struct {
    String* q;
    int front, rear;
    int maxSize;
} Queue;

void enqueue(Queue* q, String s) {
    if (q->rear == q->maxSize - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (q->rear == -1)
        q->front = 0;
    strcpy((q->q[++(q->rear)]).str, s.str);
}

void prioEnqueue(Queue* q, String s) {
    if (q->rear == q->maxSize - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    for (int i = q->rear; i >= q->front; i--)
        q->q[i + 1] = q->q[i];
    q->rear++;
    strcpy((q->q[q->front]).str, s.str);
}

String dequeue(Queue* q) {
    String s;
    strcpy(s.str, (q->q[0]).str);
    int i;
    for (i = 1; i <= q->rear; i++)
        q->q[i - 1] = q->q[i];
    q->rear--;
    return s;
}

int main() {
    int inp, n;
    String t;
    Queue q;
    q.front = -1;
    q.rear = -1;
    printf("Enter max size of queue: ");
    scanf("%d", &n);
    q.maxSize = n;
    q.q = (String*)malloc(n * sizeof(String));
    printf("1. Enqueue, 2. Priority Enqueue, 3. Dequeue, 4. Exit\n");
    do {
        printf("Enter choice: ");
        scanf("%d", &inp);

        if (inp == 1) {
            printf("Enter word to enqueue: ");
            scanf("%s", t.str);
            enqueue(&q, t);
        } else if (inp == 2) {
            printf("Enter word to priority enqueue: ");
            scanf("%s", t.str);
            prioEnqueue(&q, t);
        } else if (inp == 3) {
            if (q.front == -1) {
                printf("Queue is empty. Cannot dequeue.\n");
            } else {
                printf("Word dequeued is: %s\n", dequeue(&q).str);
            }
        } else {
            inp = 4;
        }
    } while (inp != 4);

    free(q.q);

    return 0;
}
