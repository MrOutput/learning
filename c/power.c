static int power(int num, int pow) {
    int cur = num;

    while (pow > 1) {
        cur *= num;
        pow--;
    }

    return  cur;
}

int main(void)
{
    return power(3, 3);
}
