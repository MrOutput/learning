#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point p1;
    Point p2;
} Line;

int main(int argc, char const* argv[])
{
    Line l = { { x: 2.3, y: 4.0 }, { x: 32.2323, y: 89.989 } };

    Line *lines = NULL;
    lines = (Line *) malloc(5 * sizeof(Line));

    printf("Point 1\n============\n\nx is %6.2f\ny is %6.2f\n", l.p1.x, l.p1.y);
    printf("Point 2\n============\n\nx is %6.2f\ny is %6.2f\n", l.p2.x, l.p2.y);

    printf("x: ");
    scanf("%f", &l.p2.x);
    printf("Point 2\n============\n\nx is %6.2f\ny is %6.2f\n", l.p2.x, l.p2.y);

    free(lines);
    return 0;
}
