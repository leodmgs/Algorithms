
// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) 
{
    long rem, piv;
    long kap = 0;
    long head = 0, tail = 0;
    int count = 0;
    int s = 0;
    for (long i = p; i <= q; ++i) 
    {
        if (i == 1) {
            printf("%ld ", i);
            continue;
        }
        piv = 1;
        rem = 10;
        kap = (i*i);
        s = to_string(kap).size();
        while (rem <= kap)
        {
            if ((2*piv)-1 > s) break;
            head = kap/rem;
            tail = kap%rem;
            if (head + tail == i && head > 0 && tail > 0) {
                // printf("s = %d, piv = %d\n", s, piv);
                // printf("%d -> (%d + %d) = %d\n", i, head, tail, (head+tail));
                printf("%ld ", i);
                ++count;
                break;
            }
            ++piv;
            rem *= 10;
        }
        
    }
    if (count == 0)
        printf("INVALID RANGE");
}

