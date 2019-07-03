
int reverse_number(int number)
{
    int revnum = 0, rem = 0;
    while (number != 0)
    {
        rem = number % 10;
        revnum = revnum * 10 + rem;
        number = number/10;
    }
    return revnum;
}

// Complete the beautifulDays function below.
int beautifulDays(int i, int j, int k) {
    string str_inv = "";
    int num_inv = 0, count_days = 0;
    for (int it = i; it <= j; ++it)
    {    
        num_inv = reverse_number(it);
        if ( (it - num_inv) % k == 0 )
            ++count_days;
    }
    return count_days;
}

