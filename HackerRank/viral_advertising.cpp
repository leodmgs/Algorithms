
// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    int acc = 0;
    int i = 0, p = 5, l = 0;
    while (i < n)
    {
        l = (p / 2);
        acc += l;
        p = l * 3;
        ++i;
    }
    return acc;
}