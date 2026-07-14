/*Password-strength-check-in-c-2nd-part
Check password strength*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    int x = 1;
    char z[30], a[2];
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

                    if (u >= 1 && s >= 1 && n >= 1 && sp >= 1)
                        printf("You generated a usable password\n");
                    else if (u == 0)
                        printf("Uppercase character is missing");
                    else if (s == 0)
                        printf("Lowercase character is missing");
                    else if (n == 0)
                        printf("Numeric character is missing");
                    else if (sp == 0)
                        printf("Special character is missing");

                    printf("\nNo of Uppercase character is = %d \nNo of Lowercase character is = %d \nNo of Numeric character is = %d \nNo of Special character is = %d", u, s, n, sp);
                }
                else
                {
                    printf("Try Again");
                }
            }
            else if (c >= 8 && c <= 16)
            {
                printf("Your password length is perfect\n");
                {

                    if (u >= 1 && s >= 1 && n >= 1 && sp >= 1)
                        printf("You generated a usable password\n");
                    else if (u == 0)
                        printf("Uppercase character is missing");
                    else if (s == 0)
                        printf("Lowercase character is missing");
                    else if (n == 0)
                        printf("Numeric character is missing");
                    else if (sp == 0)
                        printf("Special character is missing");
                }
                printf("\nNo of Uppercase character is = %d \nNo of Lowercase character is = %d \nNo of Numeric character is = %d \nNo of Special character is = %d", u, s, n, sp);
            }
            else if (c >= 17 && c <= 30)
            {
                printf("Your password length is too long to use\n If you want to use this password press 'y' and if not press 'n' ");
                scanf(" %c", &a[0]);
                if (a[0] == 'y')
                {
                    {

                        if (u >= 1 && s >= 1 && n >= 1 && sp >= 1)
                            printf("You generated a usable password\n");
                        else if (u == 0)
                            printf("Uppercase character is missing");
                        else if (s == 0)
                            printf("Lowercase character is missing");
                        else if (n == 0)
                            printf("Numeric character is missing");
                        else if (sp == 0)
                            printf("Special character is missing");
                    }
                    printf("\nNo of Uppercase character is = %d \nNo of Lowercase character is = %d \nNo of Numeric character is = %d \nNo of Special character is = %d", u, s, n, sp);
                }
                else
                {
                    printf("Try Again");
                }
            }
        }
    }
    printf("\n\nEXITING FORM THE PROGRAM.....");
    printf("\n______________________________________\n");

    return 0;
}
