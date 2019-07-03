
// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) {
    int days_month [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string date_formatted = "";
    int mit = 0;
    int days = days_month[mit++];
    if (year < 1918 && year % 4 == 0) 
        ++days;
    else if (year > 1917) {
        if (year % 400 == 0 || (year % 4 == 0  && year % 100 != 0))
            ++days;
        if (year == 1918)
            days -= 13;
    }
    while ( (days + days_month[mit]) < 256 )
        days += days_month[mit++];
    date_formatted.append(to_string(256 - days)).append(".");
    ++mit;
    mit < 10 ? 
        date_formatted.append("0").append(to_string(mit)) : 
        date_formatted.append(to_string(mit));
    date_formatted.append(".");
    date_formatted.append(to_string(year));
    return date_formatted;
}