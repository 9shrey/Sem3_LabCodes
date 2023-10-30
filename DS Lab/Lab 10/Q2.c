#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} node;

node* makeList(char x[50], node **h){
    int n=strlen(x);
    
    *h=(node*)malloc(sizeof(node));
    (*h)->data=-1;
    
    node *p=*h;
    for(int i=0; i<n; i++){
        node *temp=(node*)malloc(sizeof(node));
        p->right=temp;
        temp->left=p;
        (*h)->left=temp;
        temp->right=*h;
        temp->data=(x[i]-'0');
        p=p->right;
    }
    return p;
}

void add(node **p, node **q, node **r, int m, int n){

    *r=(node*)malloc(sizeof(node));
    (*r)->data=-1;
    int a = m>n?m:n;

    node *ptr=*r;
    for(int i=0; i<a; i++){
        node *temp=(node*)(malloc(sizeof(node)));
        temp->data=0;
        ptr->right=temp;
        temp->left=ptr;
        (*r)->left=temp;
        temp->right=(*r);
        ptr=ptr->right;
    }

    int carry=0;
    for(int i=0; i<a; i++){
        int res = carry;

        if(((*p))->data==-1){
            (ptr)->data=(*q)->data+carry;
            carry=0;
            ptr=ptr->left;
            *q=(*q)->left;
            continue;
        }

        else if(((*q))->data==-1){
            (ptr)->data=(*p)->data+carry;
            carry=0;
            ptr=ptr->left;
            *p=(*p)->left;
            continue;
        }

        else{
            res = (*p)->data + (*q)->data + carry;
            carry=res/10;
            int result=res%10;
            (ptr)->data=result;
            (*p)=(*p)->left;
            (*q)=(*q)->left;
            (ptr)=(ptr)->left;
        }

    }
}

void display(node *p){
    p=p->right;
    while(p->data!=-1){
        printf("%d", p->data);
        p=p->right;
    }
}

int main(){
    node *h1, *h2, *r;

    char x[50], y[50];
    printf("Enter first integer: ");
    gets(x);
    printf("Enter second integer: ");
    gets(y);

    int m, n;
    m=strlen(x);
    n=strlen(y);

    node* p = makeList(x, &h1);
    node* q = makeList(y, &h2);

    add(&p, &q, &r, m, n);

    display(h1);
    printf(" + ");
    display(h2);
    printf(" = ");
    display(r);
}