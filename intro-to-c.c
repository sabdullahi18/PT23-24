#include <stdio.h>
#include <stdlib.h>

//For-loop
int forLoop(int n){
    for (int i=0; i<n; i++){
        //code goes here
    }
    return 0;
}

//Nested for-loop
int nestedForLoop(int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            //code goes here
        }
    }
    return 0;
}

//Half nested for-loop
int halfNestedForLoop(int n){
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            //code goes here
        }
    }
    return 0;
}

//While-loop
int whileLoop(int n){
    int i=0;
    while (i<n){
        //code goes here
        i++;
    }
    return 0;
}

//Do-while-loop
int doWhileLoop(int n){
    int i=0;
    do{
        //code goes here
        i++;
    }while (i<n);
    return 0;
}

//Recursion
int recursion(int n){
    //base case
    if (n==0){
        return 0;
    }
    else{
        //code goes here
        return recursion(n-1);
    }
}

//Structs
typedef struct point{
    int x;
    int y;
} point;

int structExample(){
    point p;
    p.x = 1;
    p.y = 2;
    return 0;
}

//String manipulation
int stringCopy(){
    char str[] = "Hello World";
    //12 characters long because the last character is '\0'
    char str2[12];
    strcpy(str2, str);
    return 0;
}

int stringConcat(){
    char str1[] = "Hello ";
    char str2[] = "World";
    char str3[12];
    strcpy(str3, str1);
    strcat(str3, str2);
    return 0;
}

int stringLength(){
    char str[] = "Hello World";
    int len = strlen(str);
    return 0;
}

int stringCompare(){
    char str1[] = "Hello World";
    char str2[] = "Hello World";
    int result = strcmp(str1, str2);
    return 0;
}

int waysToCreateStrings(){
    char str1[] = "Hello World";
    char *str2 = "Hello World";
    return 0;
}

//Arrays
int arrayExample(){
    int arr[5];
    for (int i=0; i<5; i++){
        arr[i] = i;
    }
    int arr2[] = {1,2,3,4,5};
    return 0;
}

//Pointers
int pointerExample(){
    //Pointer to an integer
    int* x;
    int y = 5;

    //                 y
    // &:  address->[value]
    //        ^
    //
    // always spits out an address of whatever you give it
    // if y is a pointer then &y is a pointer to a pointer
    x = &y;

    //                 z
    // *:  address->[value]
    //                 ||
    //                 \/
    //            [other value]
    //                  ^
    //
    // interprets the content of the variable as a pointer and dereferences it
    int z = *x;

    //pointer to a struct
    point* p;
    //set values of a struct but you only have a pointer
    p->x = 1;
    p->y = 2;

    //or
    point p2 = *p;
    p2.x = 1;
    p2.y = 2;
}

//Memory allocation
int memoryAllocation(){
    //allocate memory for 5 integers
    int *arr = (int*)malloc(5*sizeof(int));
    //can still use indexing syntax
    arr[0] = 1;
    int *arr2 = (int*)calloc(5, sizeof(int));

    point *p = (point*)malloc(sizeof(point));
    p->x = 1;
    p->y = 2;

    //free memory
    free(arr);
    free(arr2);
    return 0;
}

//2D arrays using double malloc
int twoDArray(){
    int **arr = (int**)malloc(5*sizeof(int*));
    for (int i=0; i<5; i++){
        arr[i] = (int*)malloc(5*sizeof(int));
    }
    //can still use indexing syntax
    arr[0][0] = 1;
    free(arr);
    return 0;
}

//2D arrays using single malloc
int twoDArray2(){
    int *arr = (int*)malloc(5*5*sizeof(int));
    //can still use indexing syntax
    arr[0*5+0] = 1;
    free(arr);
    return 0;
}

//Linked lists
typedef struct node{
    int value;
    struct node* next;
} node;

typedef struct linkedList{
    node* head;
    node* tail;
} linkedList;

//Useful information
// char is 1 byte
// int is 4 bytes
// float is 4 bytes
// double is 8 bytes
// long is 8 bytes

int main(){
    return 0;
}