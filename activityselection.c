#include <stdio.h>

// Function to implement Activity Selection
void activitySelection(int start[], int finish[], int n) {
    int i, j;

    printf("Selected activities are:\n");

    // The first activity always gets selected
    i = 0;
    printf("(%d, %d)\n", start[i], finish[i]);

    // Consider rest of the activities
    for (j = 1; j < n; j++) {
        // If this activity has start time greater than or equal
        // to the finish time of previously selected activity
        if (start[j] >= finish[i]) {
            printf("(%d, %d)\n", start[j], finish[j]);
            i = j;
        }
    }
}

int main() {

    // Example input: start and finish times
    // Finish times must be sorted (Activity Selection Greedy Algorithm)
    int start[]  = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(finish) / sizeof(finish[0]);

    activitySelection(start, finish, n);

    return 0;
}
