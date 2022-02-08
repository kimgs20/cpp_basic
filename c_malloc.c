/*
dynamic memory allocation
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int student;
    int i, input;
    int *score;
    int sum = 0;

    printf("the number of students: ");
    scanf("%d", &student);

    score = (int *)malloc(sizeof(int) * student);
    // malloc: memory allocation, define in <stdlib.h>, use 'Heap' area of memory.
    // because we don't know the length of array.
    // make same size of array: int arr[SizeOfArray]

    for (i = 0; i < student; i++) {
        printf("the score of student %d: ", i);
        scanf("%d", &input);

        score[i] = input;
    }

    for (i = 0; i < student; i++) {
        sum += score[i];
    }

    printf("average score of student: %d\n", sum / student);
    free(score);  // important!!! free memory allocation

    return 0;
}
