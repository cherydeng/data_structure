#include <stdio.h>
#include <stdlib.h>
// #define int ElemType
#define initSize 20
typedef struct
{
    /* data */
    int *data;
    int length;
    int MaxSize;
}sqlist;
void init(sqlist &sq){
    sq.data = (int*)malloc(sizeof(int)*initSize);
    sq.length = 0;
    sq.MaxSize = initSize;
}
void increaseLen(sqlist &sq,int len){
    int * p = sq.data;
    sq.data = (int *)malloc(sizeof(int) * (initSize+len));
    for(int i = 0;i<sq.length;i++){
        sq.data[i] = p[i];
    }
    free(p);
    sq.MaxSize += len;
    // printf("动态增加存储空间成功\n");
}
bool insertElement(sqlist &sq,int i, int e){
    if(i < 0 || i > sq.MaxSize){
        return false;
    }
    else if(sq.length >= sq.MaxSize){
        return false;
    }
    for(int j = sq.length;j >= i;j--){
        sq.data[j+1] = sq.data[j];
    }
    sq.data[i-1] = e;
    sq.length += 1;
    sq.MaxSize += 1;
    return true;

}
void display(sqlist &sq){
    for(int i =0;i<sq.length;i++){
        printf("%d\t",sq.data[i]);
    }
}
int main(){
    sqlist sq;
    init(sq);
    // printf("%d\n",sq.MaxSize);
    // increaseLen(sq,5);
    // printf("%d\n",sq.MaxSize);
    insertElement(sq,1,1);
    insertElement(sq,2,2);
    insertElement(sq,3,3);
    insertElement(sq,4,4);
    insertElement(sq,2,1);

    display(sq);

}