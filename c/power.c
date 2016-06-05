static int power(int base, int exp) {
    if (exp == 0) {
        return 1;
    }

    int ans = base;

    while (exp > 1) {
        ans *= base;
        exp--;
    }

    return  ans;
}

int main(void)
{
    return power(3, 0);
}
