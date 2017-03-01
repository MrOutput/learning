#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint;

struct vector {
    uint len;
    uint cap;
    void **array;
};

struct vector *
vector_create(uint s)
{
    struct vector *v = malloc(sizeof(struct vector));
    if (s == 0) {
        s = 16;
    }
    v->array = malloc(sizeof(void *) * s);
    v->cap = s;
    v->len = 0;
    return v;
}

uint
vector_grow(struct vector *v)
{
    v->cap = v->cap * 2;
    v->array = realloc(v->array, sizeof(void *) * v->cap);
    return v->cap;
}

uint
vector_fit(struct vector *v, uint s)
{
    while (v->cap < v->len + s) {
        vector_grow(v);
    }
    return v->cap;
}

void *
vector_index(struct vector *v, uint i)
{
    return v->array[i];
}

uint
vector_insert(struct vector *v, uint i, void *a)
{
    vector_fit(v, 1);
    memmove(
        v->array + i + 1,
        v->array + i,
        sizeof(void *) * (v->len - i)
    );
    v->array[i] = a;
    v->len += 1;
    return v->cap;
}

void *
vector_remove(struct vector *v, uint i)
{
    void *a = vector_index(v, i);
    memmove(
        v->array + i,
        v->array + i + 1,
        sizeof(void *) * (v->len - i + 1)
    );
    v->len -= 1;
    return a;
}

uint
vector_push(struct vector *v, void *a)
{
    vector_insert(v, v->len, a);
    return v->len;
}

void *
vector_pop(struct vector *v)
{
    v->len -= 1;
    return vector_index(v, v->len);
}

void
vector_delete(struct vector *v)
{
    free(v->array);
    free(v);
}

int main(int argc, char *argv[])
{
    struct vector *v = vector_create(10);
    for (int i = 0; i < 15; i++) {
        vector_push(v, strdup("hello, world"));
        printf("%s %10d\n", (char *) vector_index(v, i), v->cap);
    }

    char *s = vector_pop(v);
    printf("%s\n", s);
    free(s);

    free(vector_remove(v, 0));
    vector_insert(v, 0, strdup("rafael cepeda"));

    for (int i = 0; i < v->len; i++) {
        printf("%s\t%10d\n", (char *) vector_index(v, i), v->cap);
    }

    for (int i = 0; i < v->len; i++) {
        free(v->array[i]);
    }
    vector_delete(v);
    return 0;
}
