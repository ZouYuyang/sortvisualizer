#include <stdio.h>
#include "sortVisualizer.h"

/*
 * THIS IS A DEMO OF THE SORT-VISUALIZER LIBRARY.
 * FOR FURTHER USAGE, SEE sortVisualizer.h
 */
sortVis *vis1;

void bubble_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++){
        for (j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                updateVisualizer(vis1);
            }
        }
    }
}

int main() {
    int a[] = {6,3,5,9,-4,8};
    vis1 = createVisualizer(a,6,"A");
    bubble_sort(a,6);
    verifyVisualizer(vis1,1);
    killVisualizer(vis1);
    printf("END OF PROG\n");
    return 0;
}
