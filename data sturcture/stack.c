#include <stdlib.h>
#include <stdio.h>


#define EmptyTOS    -1  //空栈
#define MinStackSize    5   //栈的最小值

typedef int elementType;    //数据类型

typedef struct stackRecord
{
    int capacity;//容量
    int stackTop;//栈顶
    elementType *array; 
}STACK;

int isEmpty(STACK *s);  //判空
int isFull(STACK *s);   //判满
STACK *createStack(int maxElements);    //栈的创建
void disposeStack(STACK *s);        //栈的释放
void makeEmpty(STACK *s);       //创建空栈
void push(elementType element, STACK *s);//入栈
elementType top(STACK *s);      //返回栈顶元素
void pop(STACK *s);         //出栈
elementType topAndTop(STACK *s);    //出栈并返回栈顶元素



int isEmpty(STACK *s)
{
    return (s->stackTop == EmptyTOS);
}

int isFull(STACK *s)
{
    return (s->stackTop == s->capacity -1);
}

STACK *createStack(int maxElements)
{
    STACK *s;

    if(maxElements < MinStackSize) {
        printf("Stack size si too small\n");    
        return NULL;
    }
    s = (STACK *)malloc(sizeof(struct stackRecord));
    s->array = (elementType *)malloc(sizeof(elementType) * maxElements);
    s->capacity = maxElements;
    makeEmpty(s);

    return s;

}
void disposeStack(STACK *s)
{
    if(s != NULL) {
        free(s->array); 
        free(s);
    }
}

void makeEmpty(STACK *s)
{
    if(s != NULL) {
        s->stackTop = EmptyTOS; 
    }
}

void push(elementType element, STACK *s)
{
    if(!isFull(s)) {
        s->stackTop++;
        s->array[s->stackTop] = element;
    } else {
        printf("full stack\n");
    }
}

elementType top(STACK *s)
{
    if(!isEmpty(s)) {
        return s->array[s->stackTop];   
    } else {
        printf("empty stack\n");
        return 0;
    }
}

void pop(STACK *s)
{
    if(!isEmpty(s))
        s->stackTop--;  
    else
        printf("empty stack\n");
}

elementType topAndTop(STACK *s)
{
    if(!isEmpty(s)) {
        return s->array[s->stackTop--];
    } else {
        printf("empty stack\n");    
        return 0;
    }
}


int main(int argc, char const *argv[])
{
    STACK* s = createStack(6);
    for(int i = 0; i<6; i++){
        printf("s[%d] = %d\n", i, s->array[i]);
    }
    return 0;
}