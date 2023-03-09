#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int rear;
    int front;
    int * arr;
};

int isEmpty(struct queue *q){
    if(q->rear == q->front){
        return 1;
    }
    return 0;
}

int isFull(struct queue *q){
    if(q->rear == q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("Queue overflow\n");
    }
    else{
        q->rear++;
        q->arr[q->rear] = val;
        // printf("%d added to the queue\n",val);
    }
}

int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("Queue underflow\n");
        return a;
    }
    q->front++;
    a = q->arr[q->front];
    return a;
}

void bfs(struct queue *q){
    int node;
    int i=5;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d ",i);
    visited[i] = 1;
    enqueue(q,i);//enqueue i for exploration
    while(!isEmpty(q)){
        int node = dequeue(q);
        for(int j=0;j<7;j++){
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d ",j);
                visited[j]=1;
                enqueue(q,j);
            }
        }
    }
}

int main(){
    struct queue * q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 100;
    q->rear = q->front = 0;
    q->arr = (int *)malloc(q->size*sizeof(int));
    // struct queue q;
    // q.size = 400;
    // q.front = q.rear = 0;
    // q.arr = (int*) malloc(q.size*sizeof(int));
    
    //BFS implementation
    // int node;
    // int i=5;
    // int visited[7] = {0,0,0,0,0,0,0};
    // int a[7][7] = {
    //     {0,1,1,1,0,0,0},
    //     {1,0,1,0,0,0,0},
    //     {1,1,0,1,1,0,0},
    //     {1,0,1,0,1,0,0},
    //     {0,0,1,1,0,1,1},
    //     {0,0,0,0,1,0,0},
    //     {0,0,0,0,1,0,0}
    // };
    // printf("%d ",i);
    // visited[i] = 1;
    // enqueue(q,i);//enqueue i for exploration
    // while(!isEmpty(q)){
    //     int node = dequeue(q);
    //     for(int j=0;j<7;j++){
    //         if(a[node][j] == 1 && visited[j] == 0){
    //             printf("%d ",j);
    //             visited[j]=1;
    //             enqueue(q,j);
    //         }
    //     }
    // }
    bfs(q);
}