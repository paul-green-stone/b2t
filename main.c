#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_input(char* bit_vector);

int _pow(int base, int power);

void b2t(char* bit_vector, long long int* x);

/* ================================================================ */

int main(int argc, char* argv[])
{   
    long long int value = 0;
    int result = 0;

    if (argc < 2)
    {
        fprintf(stderr, "usage: b2t bit_vector, [bit_vector2, ...]\n");
        result = 1;
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            if (check_input(argv[i]) == 0)
            {
                b2t(argv[i], &value);
                printf("%s - %lld\n", argv[i], value);
                value = 0;
            }
            else
                fprintf(stdout, "%s: Wrong input format\n", argv[i]);
        }
    }
    
    return result;
}

/* ================================================================ */

int check_input(char* bit_vector)
{
    for (int i = 0; bit_vector[i] != '\0'; i++)
    {
        if ((bit_vector[i] != '0') && (bit_vector[i] != '1'))
            return 1;
    }

    return 0;
}

int _pow(int base, int power)
{
    if (power == 0) return 1;
    else return base * _pow(base, power - 1);
}

void b2t(char* bit_vector, long long int* x)
{
    int w = strlen(bit_vector) - 1; // get a length of the bit vector

    if (bit_vector[0] == '1')
    {
        *x = -1 * _pow(2, w);
        printf("%lld\n", *x);
    }

    for (int i = 1; i < strlen(bit_vector); i++)
    {
        switch (bit_vector[i])
        {
            case '1':
                *x += 1 * _pow(2, w - i);
                break;

            default:
                break;
        }
    }
}