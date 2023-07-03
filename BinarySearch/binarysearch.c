#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>


int sorted_numbers[] = {0,5,10,22,64,78,99,123,126,129,222,333,555};

int binary_search(int numbers[], int target, int low, int high){
    if (high >= low){
        int middle = low + (high - low) / 2;
        if (numbers[middle] == target)
                return target;
        if (numbers[middle] > target)
            return binary_search(numbers, target, low, middle - 1);
        return binary_search(numbers, target, middle + 1,high);
    }
    return -1;
}

int main(){
    int size = sizeof(sorted_numbers) / sizeof(sorted_numbers[0]);
    int result = binary_search(sorted_numbers, 123, 0, size - 1);
    printf("-> %d\n",result);
}
