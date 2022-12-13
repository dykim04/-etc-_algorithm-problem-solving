#include <stdio.h>
int main(void)
{
    int month_list[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *day_list[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    
    int month;
    int date;
    int idx;

    month = 0;
    date = 0;
    idx = 0;
    scanf("%d %d", &month, &date);
    if (month == 1 && month > 0)
        printf("%s", day_list[date % 7]);
    else if (month >= 2 && month <= 12)
    {
        month -= 2;
        while (month >= 0)
        {
            idx += month_list[month];
            month--;
        }
        date += idx;
        printf("%s", day_list[date % 7]);
    }
    return (0);
}