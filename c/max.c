#include <stdio.h>

/* assumes that array length > 1
*/
__attribute__ ((pure)) int max(int *num, int len)
{
    int *n = num + len - 1;
    int m = *n;
    do {
        n--;
        if (*n > m) {
            m = *n;
        }
    } while (n != num);
    return m;
}

int main(int argc, char const* argv[])
{
    int num[] = {
        2, -222, 28, 1098, 104, 23, 66, 9879,
        -48, -272, 27, 850, 5, -177, 16, 7079,
        202, 127, 528, 1800, 455, 223, 266, 10379,
        351, -122, 228, 1200, 455, 123, 266, 9979,
        251, 178, 128, 1200, 255, 123, 366, 9979,
        851, 1078, 428, 1300, 1155, 4123, 1066, 9979,
        500, 123, 226, 1247, 204, 972, 266, 9979
    };
    printf("%d\n", max(num, sizeof num / sizeof(int)));
    return 0;
}
