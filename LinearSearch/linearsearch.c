#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool linear(int target, int numbers[], int length){
    for (int i = 0; i < length; i++){
        if (numbers[i] == target)
            return true;
    }
    return false;
}

int main(){
    int numbers[] = {0,99,2,5,224,2222,24,24,543};
    if (linear(22323,numbers, sizeof(numbers) / sizeof(numbers[0])))
        printf("Found!\n");
    else
        printf("Not Found!\n");

    return 0;

}
