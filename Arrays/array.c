#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef struct {
    int* data;
    uint32_t capacity; // Max Size
    uint32_t size;    //  Number of items
} Array;


Array* new_array(uint32_t capacity, ssize_t item_size){
    Array* array = (Array*)malloc(sizeof(Array));
    assert(array != NULL);
    array->capacity = capacity;
    array->data = (int*)malloc(sizeof(int) * capacity);
    return array;
}

void array_push(Array* a, int item){
    if ((a->size + 1) >= a->capacity){
        // resize
        uint32_t new_cap = a->capacity * 2;
        void* tmp = realloc(a->data, sizeof(int) * new_cap);
        assert(tmp != NULL);
        a->data = tmp;
        a->capacity = new_cap;
    }
    a->data[a->size] = item;
    a->size++;
}

void array_remove(Array* a, int index){
    if (a->size == 0)
        return;
    if (index > a->size)
        return;
    // shift everything to the left
    while (index < a->size){
        int next = a->data[index + 1];
        a->data[index] = next;
        index++;
    }
    a->size--;
    // if we are less than have of capacity resize
    if (a->size < (a->capacity / 2)){
        uint32_t new_cap = a->capacity / 2;
        void* tmp = realloc(a->data, sizeof(int) * new_cap);
        a->data = tmp;
        a->capacity = new_cap;
    }
}

int main(){
    Array* vector = new_array(50,sizeof(int));
    int test = 10;
    int test2 = 20;
    int test3 = 30;
    array_push(vector,test);
    array_push(vector,test2);
    array_push(vector,test3);
    array_push(vector,test2);
    array_push(vector,test3);
    array_push(vector,test);
    array_push(vector,test2);
    array_push(vector,test3);
    array_push(vector,test2);
    array_push(vector,test3);
    array_push(vector,test3);
    printf("Size: %d Capacity: %d Item At Position 0: %d\n",vector->size,vector->capacity,vector->data[0]);
    printf("Size: %d Capacity: %d Item At Position 1: %d\n",vector->size,vector->capacity,vector->data[1]);
    printf("Size: %d Capacity: %d Item At Position 2: %d\n",vector->size,vector->capacity,vector->data[2]);
    array_remove(vector,1);
    printf("Size: %d Capacity: %d Item At Position 0: %d\n",vector->size,vector->capacity,vector->data[0]);
    printf("Size: %d Capacity: %d Item At Position 1: %d\n",vector->size,vector->capacity,vector->data[1]);
    printf("Size: %d Capacity: %d Item At Position 2: %d\n",vector->size,vector->capacity,vector->data[2]);
    return 0;
}
