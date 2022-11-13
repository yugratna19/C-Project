// This code has been written and compiled in VS Code
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

struct subject
{
    char name[100];
    char formulaName[100];
    char formula[100];
};
typedef struct subject subject;
subject arr[100];

// function decleration
void display(FILE *);
int searchNDisp(FILE *);
void subList();
char error();
void checkFile(FILE *);
void print_formula_list(FILE *);
char formula_list();

int main()
{
    int ch, i = 0, n, d, r;
    char e, y, z;
    FILE *ptr;
    system("cls");
    system("color 70");
    printf("\n\t\t\t **** Welcome to Your Formula Encyclopedia ****");
top:
    printf("\n\n\n\t\t\t\t\tMAIN MENU\n\t\t\t\t========================\n\t\t\t\t[1] Look for a formula\n\t\t\t\t[2] View Formula sorted by Subjects\n\t\t\t\t[3] List all formulas\n\t\t\t\t[4] Add new formulas\n\t\t\t\t[0] Exit\n\t\t\t\t========================");
    printf("\n\n\t\t\t\tEnter the choice (0-5): ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 0:
        system("cls");
        fflush(stdin);
        printf("\n\n\t\t\t\tAre you sure you want to exit(y/n)? ");
        scanf("%c", &e);
        if (e == 'n' || e == 'N')
        {
            system("cls");
            goto top;
        }
        break;
    // Look for formula
    case 1:
        system("cls");
    one:
        printf("\t\t\t\tSelect the subject you are searching for\n");
        subList();
        scanf("%d", &n);
        printf("\n");
        switch (n)
        {
        case 1:
            ptr = fopen("physics.txt", "r");
            checkFile(ptr);
            r = searchNDisp(ptr);
            printf("\n");
            if (r != 1)
            {
                // z = formula_list();
                // if (z == 'Y' || z == 'y')
                // {
                //     print_formula_list(ptr);
                // }
                // printf("\n");
                y = error();
                if (y == 'Y' || y == 'y')
                {
                    goto four;
                }
            }
            fclose(ptr);
            goto down;
            break;
        case 2:
            ptr = fopen("math.txt", "r");
            checkFile(ptr);
            r = searchNDisp(ptr);
            printf("\n");
            if (r != 1)
            {
                // z = formula_list();
                // if (z == 'Y' || z == 'y')
                // {
                //     print_formula_list(ptr);
                // }
                // printf("\n");
                y = error();
                if (y == 'Y' || y == 'y')
                {
                    goto four;
                }
            }
            goto down;
            break;
        case 3:
            ptr = fopen("electric.txt", "r");
            checkFile(ptr);
            r = searchNDisp(ptr);
            printf("\n");
            if (r != 1)
            {
                // z = formula_list();
                // if (z == 'Y' || z == 'y')
                // {
                //     print_formula_list(ptr);
                // }
                // printf("\n");
                y = error();
                if (y == 'Y' || y == 'y')
                {
                    goto four;
                }
            }
            goto down;
        default:
            printf("\t\t\t\tEnter a valid number.\n");
            goto one;
            break;
        }
    down:
        fflush(stdin);
        printf("\n");
        printf("\t\t\t\tDo you want to go back to home page(y/n): ");
        scanf("%c", &e);
        if (e == 'y' || e == 'Y')
        {
            system("cls");
            goto top;
        }
        break;

    // View for formula sorted by subjects
    case 2:
        system("cls");
    two:
        printf("\t\t\t\tSelect the subject\n");
        subList();
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            system("cls");
            printf("\t\t\t\tThe formula of physics are:\n");
            ptr = fopen("physics.txt", "r");
            checkFile(ptr);
            display(ptr);
            fclose(ptr);
            goto downwards;
            break;
        case 2:
            system("cls");
            printf("\t\t\t\tThe formula of math are:\n");
            ptr = fopen("math.txt", "r");
            checkFile(ptr);
            display(ptr);
            fclose(ptr);
            goto downwards;
            break;
        case 3:
            system("cls");
            printf("\t\t\t\tThe formula of electric are:\n");
            ptr = fopen("electric.txt", "r");
            checkFile(ptr);
            display(ptr);
            fclose(ptr);
            goto downwards;
            break;
        default:
            printf("\t\t\t\tEnter a valid number: ");
            goto two;
            break;
        }
    downwards:
        fflush(stdin);
        printf("\t\t\t\tDo you want to go back to home page(y/n): ");
        scanf("%c", &e);
        if (e == 'y' || e == 'Y')
        {
            system("cls");
            goto top;
        }
        break;

    // List of all formula
    case 3:
        system("cls");
        printf("\t\t\t\tDisplaying all formula:\n");
        printf("\t\t\t\tThe formula of physics are:\n");
        printf("\nName\t\t\t\tFormula\n");
        ptr = fopen("physics.txt", "r");
        checkFile(ptr);
        display(ptr);
        fclose(ptr);
        printf("\t\t\t\tThe formula of math are:\n");
        printf("\nName\t\t\t\tFormula\n");
        ptr = fopen("math.txt", "r");
        checkFile(ptr);
        printf("\n");
        display(ptr);
        fclose(ptr);
        printf("\t\t\t\tThe formula of electric are:\n");
        printf("\nName\t\t\t\tFormula\n");
        ptr = fopen("electric.txt", "r");
        checkFile(ptr);
        printf("\n");
        display(ptr);
        fclose(ptr);
        fflush(stdin);
        printf("\t\t\t\tDo you want to go to home page(y/n): ");
        scanf("%c", &e);
        if (e == 'y' || e == 'Y')
        {
            system("cls");
            goto top;
        }
        break;
    // Adding new formula
    case 4:
    four:
        system("cls");
        printf("\t\t\t\tSelect the subject you want the add the formula to:\n");
        subList();
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            system("cls");
            printf("\t\t\t\tEnter name for the formula: ");
            scanf("%s", arr[0].formulaName);
            printf("\t\t\t\tNow enter the formula: ");
            scanf("%s", arr[0].formula);
            ptr = fopen("physics.txt", "a");
            checkFile(ptr);
            fprintf(ptr, "physics %s %s\n", arr[0].formulaName, arr[0].formula);
            fclose(ptr);
            break;
        case 2:
            system("cls");
            printf("\t\t\t\tEnter name for the formula: ");
            scanf("%s", arr[0].formulaName);
            printf("\t\t\t\tNow enter the formula: ");
            scanf("%s", arr[0].formula);
            ptr = fopen("math.txt", "a");
            checkFile(ptr);
            fprintf(ptr, "math %s %s\n", arr[0].formulaName, arr[0].formula);
            fclose(ptr);
            break;
        case 3:
            system("cls");
            printf("\t\t\t\tEnter name for the formula: ");
            scanf("%s", arr[0].formulaName);
            printf("\t\t\t\tNow enter the formula: ");
            scanf("%s", arr[0].formula);
            ptr = fopen("electric.txt", "a");
            checkFile(ptr);
            fprintf(ptr, "electric %s %s\n", arr[0].formulaName, arr[0].formula);
            fclose(ptr);
            break;
        }
    default:
        system("cls");
        printf("\t\t\t\tPlease enter a valid choice(0-5)");
        goto top;
        break;
    }
    return 0;
}
// defination
// display

void display(FILE *ptr)
{
    char x;
    int j = 0;
    do
    {
        fscanf(ptr, "%s", arr[j].name);
        fscanf(ptr, "%s", arr[j].formulaName);
        fscanf(ptr, "%s", arr[j].formula);
        j++;
    } while ((x = (fgetc(ptr))) != EOF);
    for (int i = 0; i < j; i++)
    {
        printf("%s\t\t\t\t\t%s\n", arr[i].formulaName, arr[i].formula);
    }
}
// search and display specific formula
int searchNDisp(FILE *ptr)
{
    int j = 0;
    char x, y;
    char name[100];
    printf("\t\t\t\tThe name of formula you are searching for is: ");
    scanf("%s", name);
    do
    {
        fscanf(ptr, "%s", arr[j].name);
        fscanf(ptr, "%s", arr[j].formulaName);
        fscanf(ptr, "%s", arr[j].formula);
        j++;
    } while ((x = (fgetc(ptr))) != EOF);
    for (int i = 0; i <= j; i++)
    {
        if (stricmp(name, arr[i].formulaName) == 0)
        {
            printf("\t\t\t\t%s\t%s\n", arr[i].formulaName, arr[i].formula);
            return 1;
            break;
        }
    /*
    code for ohm == ohm_law;
        for (int i = 0; i <= j; i++)
    {   
        while(num<= strlen(name) || num<= strlen(arr[i].formulaName)){
        if(name[num]==arr[i].formulaName[num]){
            count =count+1;
        }
    num++;
    }
        if (count>2)
        {
            printf("\t\t\t\t%s\t%s\n", arr[i].formulaName, arr[i].formula);
            return 1;
            break;
        }
    }
    */
    }
}
// print
void subList()
{
    printf("\t\t\t\t[1] Physics\n\t\t\t\t[2] Math\n\t\t\t\t[3] Eletric\n");
    printf("\t\t\t\tYour choice: ");
}
// formula not find
char error()
{
    char y;
    printf("\t\t\t\tCouldn't find the formula\n");
    fflush(stdin);
    printf("\t\t\t\tDo you want to add formula(y/n)?: ");
    scanf("%c", &y);
    return y;
}
// list of formula
char formula_list()
{
    char z;
    printf("\t\t\t\tDo you want to view list of formula?");
    fflush(stdin);
    scanf("%c", &z);
    printf("\n");
    return z;
}

// check if file open or not
void checkFile(FILE *fp)
{
    if (!fp)
    {
        printf("File cannot be opened !!! Exiting...");
        exit(1);
    }
}
/*
print_list of names of formula
void print_formula_list(FILE *ptr)
{
    char x;
    int j = 0;
    do
    {
        fscanf(ptr, "%s", arr[j].name);
        fscanf(ptr, "%s", arr[j].formulaName);
        fscanf(ptr, "%s", arr[j].formula);
        j++;
    } while ((x = (fgetc(ptr))) != EOF);
    for (int i = 0; i < j; i++)
    {
        printf("%s\t\t\t\t\t%s\n", arr[i].formulaName, arr[i].formula);
    }
}
*/