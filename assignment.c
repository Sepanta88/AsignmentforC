#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>

#define FORMAT "YYMMDD-nnnc"
#define YEAR_MIN 0U
#define YEAR_MAX 99U
#define MONTH_MIN 1U
#define MONTH_MAX 12U
#define DAY_MIN 1
#define FEBRUARY 2U

int main(void)
{
    char format[] = FORMAT;
    char string[sizeof(FORMAT)] = {0};

    printf("Enter swdish COD: ", format);

    
    uint8_t i = 0;
    while (i < sizeof(FORMAT) - 1)
    {
        char chr = getchar();
        if ((chr == '\n') || (chr == EOF))
        {
            break;
        }
        string[i++] = chr;
    }

    bool status = true; 

    i = 0;
    while (i < sizeof(FORMAT) - 1)
    {
        if (isalpha(format[i])) 
        {
            if (!isdigit(string[i]))
            {
                status = false;
                break;
            }
        }
        else
        {
            if (format[i] != string[i]) 
            {
                status = false;
                break;
            }
        }
        i++;
    }

    if (status)
    {
        unsigned int year = 0, month = 0, day = 0, NNN = 0, c = 0;

        
        sscanf(string, "%02u%02u%02u-%03u%01u", &year, &month, &day, &NNN, &c);

        if ((year < YEAR_MIN) || (year > YEAR_MAX) ||
            (month < MONTH_MIN) || (month > MONTH_MAX) || (day < DAY_MIN))
        {
            status = false;
        }
        else
        {
            uint8_t days[MONTH_MAX] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            if (day > days[month - 1])
            {
                status = false;

                if (month == FEBRUARY)
                {
                    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) // If the year is a leap year
                    {
                        if (day == days[month - 1] + 1) // In february we can have 29 days
                        {
                            status = true;
                        }
                    }
                }
            }
            unsigned int y1 = 0, y2 = 0, y3 = 0, y4 = 0, m1 = 0, m2 = 0, m3 = 0, m4 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, a = 0, b = 0, d = 0, f = 0, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, g = 0;
            y1 = ((year / 10)) * 2;
            y2 = year % 10;
            if (y1 > 9)
            {
                y1 = (y1 / 10 + y1 % 10);
            }
            m1 = ((month / 10)) * 2;
            m2 = month % 10;
            if (m1 > 9)
            {
                m1 = (m1 / 10 + m1 % 10);
            }

            d1 = ((day / 10)) * 2;
            d2 = day % 10;
            if (d1 > 9)
            {
                d1 = (d1 / 10 + d1 % 10);
            }

            n1 = (NNN / 100) * 2;
            n2 = (NNN % 100) / (10);
            n3 = ((NNN % 100) % (10)) * 2;
            if (n1 > 9)
            {
                n1 = (n1 / 10 + n1 % 10);
            }
            if (n3 > 9)
            {
                n3 = (n3 / 10 + n3 % 10);
            }
            n4 = n1 + n2 + n3;
            f = y1 + y2 + m1 + m2 + d1 + d2 + n4;
            g = (10 - (f % 10)) % 10;
            if (g == c)
                status = true;
            else
                status = false;
        }
    }

    printf("Swedish personal identity numbers is%s valid!\n", status ? "" : " not");

    return 0;
}
