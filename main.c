//
//  main.c
//  StrcutDynamicAllocation_2
//
//  Created by Asad mero on 5/25/21.
//  Copyright © 2021 Asad merouani. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct point {
    int x;
    int y;
};

// Prototypes declaration
struct point **createRandPoint(int size, int maxVal);

int main() {

    srand(time(0));

    struct point **point;

    point = createRandPoint(10, 5);
    for (int i = 0; i < 10; i++) {
        printf("(%d) = (%d,%d)", i, point[i]->x, point[i]->y);

        printf("\n");
    }

    for (int i = 0; i < 10; i++) {
        free(point[i]);
    }
    free(point);

    return 0;
}

// pre
// post
struct point **createRandPoint(int size, int maxVal) {
    struct point **temp;

    // Dynamic allocation of the memory of type struct point.
    temp = (struct point **) malloc(size * sizeof(struct point *));

    for (int i = 0; i < size; i++) {
        temp[i] = (struct point *) malloc(size * sizeof(struct point));
        temp[i]->x = rand() %
                     maxVal;
        temp[i]->y = rand() % maxVal;
    }

    return temp;
}
