#include<stdio.h>
#include<stdlib.h>

typedef struct nd{
    char c[1000]; // เปลืองแต่ง่ายต่อการสร้าง เพราะสมการมันก็คงยาวไม่เกิน 1000 ตัวอักษร
    struct nd *next;
}node;
node *top = NULL;
int count = 0;

void push(char ch[],int chSize){
    node *n = malloc(sizeof(node));
    n->next = top;
    top = n;
    for(int i = 0;i<chSize;i++){
        n->c[i] = ch[i];
        //printf("[%c][%d]",n->c[i],i);
    }
    count++;
}

char* pop(){
    static char ch[1000]; node *n;
    n = top;
    top = top->next;
    for(int i = 0;i<sizeof(n->c);i++)
        ch[i] = n->c[i];
    free(n);
    count--;
    return ch;
}

char* top_of_stack(){
    if(top == NULL){
        return '\0';
    }else{
        static char ch[1000];
        for(int i = 0;i<sizeof(top->c);i++)
            ch[i] = top->c[i];
        return ch;
    }
}

void destroy_stack(){
    node *n;
    while (top != NULL){
        n = top;
        top = top->next;
        free(n);
        count--;
    }
    
}