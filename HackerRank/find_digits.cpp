
// Complete the findDigits function below.
int findDigits(int n) {
    int numcpy = n, lastn = 0, count = 0;
    while (numcpy != 0)
    {
        lastn = numcpy % 10;
        if (lastn > 0)
            if (n % lastn == 0)
                ++count;
        numcpy /= 10;
    }
    return count;
}