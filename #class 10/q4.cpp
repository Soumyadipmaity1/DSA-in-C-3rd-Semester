#include <stdio.h>
#include <math.h>

int main() {
    int X[] = {2, 1, 6};
    int Y[] = {1, 5};
    int count = 0;

    int sizeX = sizeof(X) / sizeof(X[0]);
    int sizeY = sizeof(Y) / sizeof(Y[0]);

    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            if (pow(X[i], Y[j]) > pow(Y[j], X[i])) {
                count++;
            }
        }
    }

    printf("Number of pairs where x^y > y^x: %d\n", count);

    return 0;
}
