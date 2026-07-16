/*Password-strength-check-in-c-4th-part
Check password strength*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void chk(int, int, int, int);
int reop(int);
int main()
{
    int x = 1;
    char z[30], a[2];
    while (x == 1)
    {
        int i, c = 0, u = 0, s = 0, n = 0, sp = 0;
        printf("\n______________________________________\n");
        printf("enter your password :-");
        scanf(" %29[^\n]", z);
        {
            for (i = 0; z[i] != 0; i++)
            {
                c = c + 1;
                if (z[i] >= 'A' && z[i] <= 'Z')
                    u++;
                else if (z[i] >= 'a' && z[i] <= 'z')
                    s++;
                else if (z[i] >= '0' && z[i] <= '9')
                    n++;
                else
                    sp++;
            }
            printf("Length of your password is :- %d\n", c);
            {
                if (c >= 0 && c <= 7)
                {
                    printf("Your password length is too weak\n If you want to use this password press 'y' and if not press 'n' ");
                    scanf(" %c", &a[0]);
                    if (a[0] == 'y')
                    {
                        chk(u, s, n, sp);
                        printf("\nno of Uppercase character is = %d \nno of Lowercase character is = %d \nno of Numeric character is = %d \nno of Special character is = %d", u, s, n, sp);
                        x = reop(0);
                    }
                    else
                    {
                        printf("Try Again");
                        getch();
                        x = reop(x);
                    }
                }
                else if (c >= 8 && c <= 16)
                {
                    printf("Your password length is perfect\n");
                    {
                        chk(u, s, n, sp);
                    }
                    printf("\nno of Uppercase character is = %d \nno of Lowercase character is = %d \nno of Numeric character is = %d \nno of Special character is = %d", u, s, n, sp);
                    x = reop(0);
                }
                else if (c >= 17 && c <= 30)
                {
                    printf("Your password length is too long to use\n If you want to use this password press 'y' and if not press 'n' ");
                    scanf(" %c", &a[0]);
                    if (a[0] == 'y')
                    {
                        {
                            chk(u, s, n, sp);
                        }
                        printf("\nno of Uppercase character is = %d \nno of Lowercase character is = %d \nno of Numeric character is = %d \nno of Special character is = %d", u, s, n, sp);
                        x = reop(0);
                    }
                    else
                    {
                        printf("Try Again");
                        getch();
                        x = reop(0);
                    }
                }
            }
        }
    }

    return 0;
}

void chk(int u, int s, int n, int sp)
{
    if (u >= 1 && s >= 1 && n >= 1 && sp >= 1)
        printf("You generated a usable password\n");
    else
    {
        if (u == 0)
            printf("Uppercase character is missing");
        if (s == 0)
            printf("Lowercase character is missing");
        if (n == 0)
            printf("Numeric character is missing");
        if (sp == 0)
            printf("Special character is missing");
    }
}

int reop(int x)
{
    char b[2];
    printf("\nWould you like to check the strength of your passwords \nIf yes press 'y' else 'n'=");
    scanf(" %c", &b[0]);
    if (b[0] == 'n')
    {
        printf("\nPress any key to exit.......");
        getch();
        exit(0);
    }
    else
        printf("\nPress any key to continue.......");
    getch();
    return (1);
}