#include <stdio.h>
#include <stdlib.h> // for abs()

int findClosest(int arr[], int size, int target) {
    int closest = arr[0];
    int minDiff = abs(arr[0] - target);

    for (int i = 1; i < size; i++) {
        int diff = abs(arr[i] - target);
        if (diff < minDiff) {
            minDiff = diff;
            closest = arr[i];
        }
    }

    return closest;
}

int main() {
    int numbers[] = {4, 10, 15, 23, 38,17};
    int target = 20;
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int result = findClosest(numbers, size, target);

    printf("Closest number to %d is %d\n", target, result);

    return 0;
}