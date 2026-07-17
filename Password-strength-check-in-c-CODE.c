/*Password-strength-check-in-c-5th-part
Check password strength*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void chk(int, int, int, int);
int reop(int);
int flreop(void);
int file(char[], int); 
int main()
{
    int x = 1, y = 1, ch;
    char z[30], a[2], sch, s;
    do
    {
        x = 1;
        printf("\n________________________________________________________________________________\n");
        printf("1. Enter your password to Check the strength of your password\n2. View all the saved passwords\n3. Delete all the saved passwords\n4. Exit\nSelect choice:- ");
        do
        {
            scanf("%c", &s);
            while (getchar() != '\n');
            ch = s - '0';
        } while (ch < 0 || ch > 4);

        switch (ch)
        {
        case 1:
        {
            while (x == 1)
            {
                int i, c = 0, u = 0, s = 0, n = 0, sp = 0;
                printf("________________________________________________________________________________\n");
                printf("Enter your password :- ");
                scanf(" %29[^\n]", z);
                while (getchar() != '\n');
                for (i = 0; z[i] != '\0'; i++)
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
                printf("==> Length of your password is :- %d\n", c);

                if (c >= 0 && c <= 7)
                {
                    printf("==> Your password length is too weak.\n    If you want to use this password press 'y' and if not press 'n':- ");
                    scanf(" %c", &a[0]);
                    while (getchar() != '\n');
                    if (a[0] == 'y')
                    {
                        chk(u, s, n, sp);
                        printf("\nNo. of Uppercase characters = %d \nNo. of Lowercase characters = %d \nNo. of Numeric characters = %d \nNo. of Special characters = %d", u, s, n, sp);
                        printf("\n==> To save your password in a file press 'y' else 'n':- ");
                        scanf(" %c", &sch);
                        while (getchar() != '\n')
                            ;
                        if (sch == 'y' || sch == 'Y')
                        {
                            y = file(z, 0);
                            x = 0;
                        }
                        else
                        {
                            x = reop(0);
                        }
                    }
                    else
                    {
                        printf("Try Again\n");
                        x = reop(0);
                    }
                }
                else if (c >= 8 && c <= 16)
                {
                    printf("==> Your password length is perfect.\n");
                    chk(u, s, n, sp);
                    printf("\nNo. of Uppercase characters = %d \nNo. of Lowercase characters = %d \nNo. of Numeric characters = %d \nNo. of Special characters = %d", u, s, n, sp);
                    printf("\n==> To save your password in a file press 'y' else 'n':- ");
                    scanf(" %c", &sch);
                    while (getchar() != '\n');
                    if (sch == 'y' || sch == 'Y')
                    {
                        y = file(z, 0);
                        x = 0;
                    }
                    else
                    {
                        x = reop(0);
                    }
                }
                else if (c >= 17 && c <= 30)
                {
                    printf("==> Your password length is too long to use.\n    If you want to use this password press 'y' and if not press 'n':- ");
                    scanf(" %c", &a[0]);
                    while (getchar() != '\n');
                    if (a[0] == 'y' || a[0] == 'Y')
                    {
                        chk(u, s, n, sp);
                        printf("\nNo. of Uppercase characters = %d \nNo. of Lowercase characters = %d \nNo. of Numeric characters = %d \nNo. of Special characters = %d", u, s, n, sp);
                        printf("\n==> To save your password in a file press 'y' else 'n':- ");
                        scanf(" %c", &sch);
                        while (getchar() != '\n')
                            ;
                        if (sch == 'y' || sch == 'Y')
                        {
                            y = file(z, 0);
                            x = 0;
                        }
                        else
                        {
                            x = reop(0);
                        }
                    }
                    else
                    {

                        x = reop(0);
                    }
                }
                else
                {
                    printf("==> Try Again\n");
                    x = reop(0);
                }
            }
            break;
        }

        case 2:
            y = file(z, 1);
            break;
        case 3:
            y = file(z, 2);
            break;
        case 4:
            printf("==> Exiting program...\n");
            exit(0);
            break;
        default:
            printf("==> Invalid choice!\n");
            break;
        }

    } while (y == 1);
    return 0;
}

void chk(int u, int s, int n, int sp)
{
    if (u >= 1 && s >= 1 && n >= 1 && sp >= 1)
        printf("==> You generated a usable password.");
    else
    {
        if (u == 0)
            printf("\nUppercase character is missing.");
        if (s == 0)
            printf("\nLowercase character is missing.");
        if (n == 0)
            printf("\nNumeric character is missing.");
        if (sp == 0)
            printf("\nSpecial character is missing.");
    }
}

int reop(int x)
{
    char b[2];
    printf("\n________________________________________________________________________________\n");
    printf("\n==> Would you like to check the strength of another password? (OR Go to Main Menu)?\n    If yes press 'y' else 'n':- ");
    scanf(" %c", &b[0]);
    while (getchar() != '\n')
        ;
    if (b[0] == 'n' || b[0] == 'N')
    {
        printf("\n==> Returning to the main menu.......\n");
        return 0;
    }
    else
    {
        printf("\n==> Preparing to create a new password.......\n");
        return 1;
    }
}

int flreop(void)
{
    char b[2];
    printf("\n________________________________________________________________________________\n");
    printf("\n==> Would you like to go to the main menu?\n    If yes press 'y' else 'n':- ");
    scanf(" %c", &b[0]);
    while (getchar() != '\n')
        ;
    if (b[0] == 'n' || b[0] == 'N')
    {
        printf("\n==> Exiting program.......\n");
        exit(0);
    }
    else
    {
        printf("\n==> Returning to the main menu.......\n");
        return 1;
    }
}

int file(char pass[], int type)
{
    if (type == 0)
    {
        FILE *Ptr = fopen("password.bin", "ab");
        if (Ptr != NULL)
        {
            fputs(pass, Ptr);
            fputs("\n", Ptr);
            fclose(Ptr);
            printf("________________________________________________________________________________\n");
            printf("==> Your password is saved successfully.\n");
        }
        return flreop();
    }
    else if (type == 1)
    {
        int i = 1;
        FILE *Ptr = fopen("password.bin", "rb");
        char Str[30];

        if (Ptr == NULL)
        {
            printf("________________________________________________________________________________\n");
            printf("\n==> No saved passwords database found yet.\n");
            return flreop();
        }

        printf("________________________________________________________________________________\n");
        int f = 0;
        while (fgets(Str, sizeof(Str), Ptr) != NULL)
        {
            f = 1;
            printf("%d. Password = %s", i++, Str);
        }
        if (!f)
        {
            printf("\n==> No passwords found inside the file database.\n");
        }

        fclose(Ptr);
        return flreop();
    }
    else if (type == 2)
    {
        char file[] = "password.bin";
        FILE *testPtr = fopen(file, "rb");
        if (testPtr == NULL)
        {
            printf("________________________________________________________________________________\n");
            printf("==> Error: No database file exists to delete.\n");
            return flreop();
        }
        fclose(testPtr);
        if (remove(file) == 0)
        {
            printf("________________________________________________________________________________\n");
            printf("==> File '%s' deleted successfully.\n", file);
        }
        else
        {
            printf("________________________________________________________________________________\n");
            printf("==> Error: Unable to delete the file securely.\n");
        }
        return flreop();
    }
    return 1;
}
