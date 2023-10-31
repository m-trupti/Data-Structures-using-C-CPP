#include <stdio.h>


// Recursive function to solve the Tower of Hanoi puzzle
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
       printf("Move disk %d from %c to %c\n", n, source, destination);
        return;
    }

    // Move (n-1) disks from the source to the auxiliary peg using the destination peg
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the remaining disk from the source peg to the destination peg
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move (n-1) disks from the auxiliary peg to the destination peg using the source peg
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int numDisks;

    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    if (numDisks <= 0) {
        printf("Number of disks should be greater than zero.\n");
        return 1;
    }

    // Function call to solve the Tower of Hanoi
    towerOfHanoi(numDisks, 'A', 'B', 'C');

    return 0;
}

