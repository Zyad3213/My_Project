#include <stdio.h>
#include <time.h>
#define GREEN_FOREGROUND 2
#define RED_FOREGROUND 12
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
int count ;
int i_show ;


int num_select, num_scan ;

struct StudentInfo
{
    char Name[20];
    int  ID;
    char Email[30];
    char Phone[20];
    int  NumberOfCourse;
    int  Password;
};

struct CourseInfo
{
    char StudentID[10];
    char Code[10];
    char Name[20];
};

struct StudentInfo students[101];
struct CourseInfo course[50];


void student_scan(struct StudentInfo StudentInfo[]);

void start (void);
void ShowStudents(int index);
void EditStudent(void);
void ringPhone(void);
void DeleteStudent(void);
int selects (int num) ;
void saveCountToFile(int count);




/***************************************Header*************************************************************************************************************/

int TotalStudents = 0 ;
int i=0, j=0, count=0, flag_found = 0 ;
void setConsoleColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void start (void)
{
    setConsoleColor(0x80);
    printf("\n              \t                                                                           \t\n");
    printf("              \t                                                                           \t\n");
    setConsoleColor(7);
    setConsoleColor(0x0f);
    printf("                              _    _       _____       _____                                    \n");
    printf("                             | |  | |     |_   _|     |_   _|                                   \n");
    printf("                             | |__| |       | |         | |                                     \n");
    printf("                             |  __  |       | |         | |                                     \n");
    printf("                             | |  | |       | |        _| |_                                    \n");
    printf("                             |_|  |_|       |_|       |_____|                                   \n");

    printf("                           ____         _                     _                                 \n");
    printf("                          / ___|  ___  | |       ___    ___  | |                                \n");
    printf("                          \\___ \\ / __| | |____  / _ \\  / _ \\ | |                                \n");
    printf("                           ___) | (__  |  __  || |_) || |_) || |___                             \n");
    printf("                          |____/ \\ \__| |_|  |_||____/ |____/ |_____|                            \n");
    setConsoleColor(7);
    setConsoleColor(0x80);
    printf("\n              \t                                                                           \t\n");
    printf("              \t                                                                           \t\n");
    setConsoleColor(7);
    printf("              \t                                                                           \t\n");
    printf("              \t**********************************************************                 \t\n");
    printf("              \t*                                                        *                 \t\n");
    printf("              \t***              WELCOME TO HTI SCHOOL                 ***                 \t\n");
    printf("              \t*                     HTI School                         *                 \t\n");
    printf("              \t*               Address : 10th Of Ramadan                *                 \t\n");
    printf("              \t*                    Tel.0554789332                      *                 \t\n");
    printf("              \t*                                                        *                 \t\n");
    printf("              \t**********************************************************                 \t\n");
    printf("              \t                                                                           \t\n");
    setConsoleColor(0x80);
    printf("              \t                                                                           \t\n");
    printf("              \t                                                                           \t\n");

    setConsoleColor(7);
    setConsoleColor(7);
    for(int i=0; i<96; i++)
        printf("-");
    setConsoleColor(0x0A);
    printf("                     \n   \t \t \t \t  ENTER ANY KEY TO CONTINUE . . ");
    setConsoleColor(7);

    printf("\n");
    for(int i=0; i<96; i++)
        printf("-");

    getch();
    system("cls");
    printf("\n");

    setConsoleColor(0xfA);
    printf("                                                                                          \t\n");
    setConsoleColor(7);

    printf("\n\n\t\t\t || WELCOME TO  HTI SCHOOL SYSTEM  || \n\n\n");

    setConsoleColor(0xfA);
    printf("                                                                                          \t\n");
    setConsoleColor(7);

    setConsoleColor(0x0A);
    printf("\n LOADING PLEASE WAIT");
    for(int i=0; i<4; i++)
    {
        printf(".");
        delay(1);
    }
    printf("\n");
    setConsoleColor(7);

}
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int selects (int num)
{
    printf("\n");
    setConsoleColor(0xf9);
    printf("                                                                                         \t\n");
    printf("                 **********************************************************              \t\n");
    printf("                 *                                                        *              \t\n");
    printf("                 ***            Enter 1 to Add new student:        ***              \t\n");
    printf("                 *              Enter 2 to Edit in student`s Data:        *              \t\n");
    printf("                 *              Enter 3 to Remove student                 *              \t\n");
    printf("                 *              Enter 4 to Call student`s Father :        *              \t\n");
    printf("                 *              Enter 5 to Print All students             *              \t\n");
    printf("                 *                                                        *              \t\n");
    printf("                 **********************************************************              \t\n");
    printf("                                                                                         \t\n");
    setConsoleColor(7);
    scanf("%d",&num);
    fflush(stdin);
    fflush(stdout);
    return num ;
}


void ShowStudents(int index)
{
    printf("\n");
    printf("|==========|====================|==============================|====================|=============|\n");
    printf("|    ID    |        Name        |            Email             |       Phone        |  NO.Course  |\n");
    printf("|==========|====================|==============================|====================|=============|\n");

    printf("%d",students[index].ID);
    for(j=0; j < 4; j++)
    {
        printf(" ");
    }
    printf("|");
    printf("%s",students[index].Name);
    for(j=0; j < (20-strlen(students[i].Name)); j++)
    {
        printf(" ");
    }
    printf("|");
    printf("%s",students[index].Email);
    for(j=0; j < (30-strlen(students[i].Email)); j++)
    {
        printf(" ");
    }
    printf("|");
    printf("%s",students[index].Phone);
    for(j=0; j < (20-strlen(students[i].Phone)); j++)
    {
        printf(" ");
    }
    printf("|");
    printf("%d",students[index].NumberOfCourse);
    for(j=0; j < 12; j++)
    {
        printf(" ");
    }
    printf("|\n");
    printf("|----------|--------------------|------------------------------|--------------------|-------------|\n");
    printf("\n");
}

void UpdateAllStudents()
{
    FILE *file = fopen("students.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    if(i_show==0)
    {
        fprintf(file, "\n");
        fprintf(file, "|==========|====================|==============================|====================|=============|\n");
        fprintf(file, "|    ID    |        Name        |            Email             |       Phone        |  NO.Course  |\n");
        fprintf(file, "|==========|====================|==============================|====================|=============|\n");

    }
    for (; i_show < count; i_show++)
    {

        fprintf(file, "|");

        fprintf(file, "%d", students[i_show].ID);
        for (j = 0; j < 3; j++)
        {
            fprintf(file, " ");
        }
        fprintf(file, "|");
        fprintf(file, "%s", students[i_show].Name);
        for (j = 0; j < (20 - strlen(students[i_show].Name)); j++)
        {
            fprintf(file, " ");
        }
        fprintf(file, "|");
        fprintf(file, "%s", students[i_show].Email);
        for (j = 0; j < (30 - strlen(students[i_show].Email)); j++)
        {
            fprintf(file, " ");
        }
        fprintf(file, "|");
        fprintf(file, "%s", students[i_show].Phone);
        for (j = 0; j < (20 - strlen(students[i_show].Phone)); j++)
        {
            fprintf(file, " ");
        }
        fprintf(file, "|");
        fprintf(file, "%d", students[i_show].NumberOfCourse);
        for (j = 0; j < 12; j++)
        {
            fprintf(file, " ");
        }
        fprintf(file, "|\n");
        fprintf(file, "|----------|--------------------|------------------------------|--------------------|-------------|\n");
    }
    fclose(file);
}

void ShowAllStudents (void)
{
    FILE * file = fopen("students.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }
    fclose(file);
}


void student_scan(struct StudentInfo StudentInfo[])
{
    int IsValidName = 0;

    while (!IsValidName)
    {
        printf("\n");
        printf("Enter The student Name: ");
        scanf("%s", StudentInfo[count].Name);
        fflush(stdin);
        fflush(stdout);

        if (strlen(StudentInfo[count].Name) > 20)
        {
            printf("Error: Name cannot be more than 20 characters.\n\n");
            IsValidName = 0;
        }
        else if (strlen(StudentInfo[count].Name) <= 1 )
        {
            printf("Error: Name cannot be empty.\n\n");
            IsValidName = 0;
        }
        else
        {
            IsValidName = 1;
        }
    }

    int IsValidEmail = 0;

    while (!IsValidEmail)
    {
        printf("Enter student's Email : ");
        scanf("%s", StudentInfo[count].Email);
        fflush(stdin);
        fflush(stdout);

        if (strlen(StudentInfo[count].Email) > 30)
        {
            printf("Error: Email cannot be more than 30 characters.\n\n");
            IsValidEmail = 0;
        }
        else if (strlen(StudentInfo[count].Email) <= 0)
        {
            printf("Error: Email cannot be empty.\n\n");
            IsValidEmail = 0;
        }
        else
        {
            IsValidEmail = 1;
        }
    }

    int IsValidPhone = 0;

    while (!IsValidPhone)
    {
        printf("Enter The Phone Number : ");
        scanf("%s", StudentInfo[count].Phone);
        fflush(stdin);
        fflush(stdout);

        if (strlen(StudentInfo[count].Phone) > 11)
        {
            printf("Error: Phone cannot be more than 11 characters.\n\n");
            IsValidPhone = 0;
        }
        else if (strlen(StudentInfo[count].Phone) <= 0)
        {
            printf("Error: Phone cannot be empty.\n\n");
            IsValidPhone = 0;
        }
        else
        {
            IsValidPhone = 1;
        }
    }
    int IsValidNumberOfCourse = 0;

    while (!IsValidNumberOfCourse)
    {
        printf("Number of courses: ");
        scanf("%d", &StudentInfo[count].NumberOfCourse);
        fflush(stdin);
        fflush(stdout);

        if (StudentInfo[count].NumberOfCourse > 4 || StudentInfo[count].NumberOfCourse < 0)
        {
            printf("Error: A Student can have a maximum of 4 and a minimum of 0 number of courses.\n\n");
            IsValidNumberOfCourse = 0;
        }
        else
        {
            IsValidNumberOfCourse = 1;

            for (int j = 0; j < StudentInfo[count].NumberOfCourse; j++)
            {
                printf("Enter a Course %d Code: ", j);
                scanf("%s", course[j].Code);
                fflush(stdin);
                fflush(stdout);
                printf("Enter a Course %d Name: ", j);
                scanf("%s", course[j].Name);
                fflush(stdin);
                fflush(stdout);
            }
        }
    }

    int IsValidPass = 0;
    while (!IsValidPass)
    {
        printf("Enter your password : ");
        scanf("%d",&StudentInfo[count].Password);
        fflush(stdin);
        fflush(stdout);
        if (strlen(StudentInfo[count].Name) > 10)
        {
            printf("Error: Password cannot be more than 10 numbers.\n\n");
            IsValidName = 0;
        }
        else if (StudentInfo[count].Password <= 3 )
        {
            printf("Error: Password cannot be less than 4.\n\n");
            IsValidName = 0;
        }
        else
        {
            IsValidPass = 1;
        }
    }

    setConsoleColor(0x0A);
    printf("\n LOADING PLEASE WAIT");
    for(int i=0; i<2; i++)
    {
        printf(".");
        delay(0.7);
    }
    printf("\n");
    setConsoleColor(7);
    setConsoleColor(0xf0);
    printf("\nStudent Updated Successfully.");
    setConsoleColor(7);
    printf("\n");
    printf("\n");
    students[count].ID = count+2024000 ;
    count++ ;
    saveCountToFile(count);
}


void EditStudent(void)
{
    int  ID;
    int  Password;

    int IsValidFound = 0;
    while(!IsValidFound)
    {


        printf(" Enter The Student ID : ");
        scanf("%d",&ID);

        printf(" Enter The Student Password : ");
        scanf("%d",&Password);

        setConsoleColor(0x0A);
        printf("\n LOADING PLEASE WAIT");
        for(int i=0; i<3; i++)
        {
            printf(".");
            delay(1);
        }
        printf("\n");
        setConsoleColor(7);
        for(i=0; i<count; i++)
        {
            if(ID==(students[i].ID) && Password==(students[i].Password))
            {
                flag_found = 1 ;
                break;
            }
        }
        if(flag_found==1)
        {
            IsValidFound = 1 ;
            setConsoleColor(0x4f);
            ShowStudents(i);
            setConsoleColor(0x0c);
            printf("              \t                                                                        \t\n");
            printf("              \t**********************************************************              \t\n");
            printf("              \t*                                                        *              \t\n");
            printf("              \t***            Enter 1 to Edit in Your Name            ***              \t\n");
            printf("              \t*              Enter 2 to Edit in Your Email             *              \t\n");
            printf("              \t*              Enter 3 to Edit in Your Phone             *              \t\n");
            printf("              \t*              Enter 4 to Edit in Your Courses           *              \t\n");
            printf("              \t*              Enter 5 to change the Password            *              \t\n");
            printf("              \t*                                                        *              \t\n");
            printf("              \t**********************************************************              \t\n");
            printf("              \t                                                                        \t\n");
            setConsoleColor(0x0f);
            printf("Which object to you want to Edit :");
            int edit_index ;
            scanf("%d",&edit_index);
            fflush(stdin);fflush(stdout);

            int IsValidName = 0;
            int IsValidEmail = 0;
            int IsValidPhone = 0;
            int IsValidNumberOfCourse = 0;
            int IsValidPass = 0;

            switch (edit_index)
            {
            case 1 :
                while (!IsValidName)
                {
                    printf("Enter The New student Name: ");
                    scanf("%s", students[i].Name);
                    fflush(stdin);
                    fflush(stdout);

                    if (strlen(students[i].Name) > 20)
                    {
                        printf("Error: Name cannot be more than 20 characters.\n\n");
                        IsValidName = 0;
                    }
                    else if (strlen(students[i].Name) <= 1 )
                    {
                        printf("Error: Name cannot be empty.\n\n");
                        IsValidName = 0;
                    }
                    else
                    {
                        IsValidName = 1;
                    }
                }
                break ;
            case 2 :
                while (!IsValidEmail)
                {
                    printf("Enter The New Email : ");
                    scanf("%s", students[i].Email);
                    fflush(stdin);
                    fflush(stdout);

                    if (strlen(students[i].Email) > 30)
                    {
                        printf("Error: Email cannot be more than 30 characters.\n\n");
                        IsValidEmail = 0;
                    }
                    else if (strlen(students[i].Email) <= 0)
                    {
                        printf("Error: Email cannot be empty.\n\n");
                        IsValidEmail = 0;
                    }
                    else
                    {
                        IsValidEmail = 1;
                    }
                }
                break ;

            case 3 :
                while (!IsValidPhone)
                {
                    printf("Enter The New Phone: ");
                    scanf("%s",&students[i].Phone);
                    fflush(stdin);
                    fflush(stdout);

                    if (strlen(students[i].Phone) > 11)
                    {
                        printf("Error: Phone cannot be more than 11 characters.\n\n");
                        IsValidPhone = 0;
                    }
                    else if (strlen(students[i].Phone) <= 0)
                    {
                        printf("Error: Phone cannot be empty.\n\n");
                        IsValidPhone = 0;
                    }
                    else
                    {
                        IsValidPhone = 1;
                    }
                }
                break ;
            case 4 :
                while (!IsValidNumberOfCourse)
                {
                    printf("Enter The New Number of courses: ");
                    scanf("%d", &students[i].NumberOfCourse);

                    if (students[i].NumberOfCourse > 4 || students[i].NumberOfCourse < 0)
                    {
                        printf("Error: A Student can have a maximum of 4 and a minimum of 0 number of courses.\n\n");
                        IsValidNumberOfCourse = 0;
                    }
                    else
                    {
                        IsValidNumberOfCourse = 1;

                        for (int j = 0; j < students[i].NumberOfCourse; j++)
                        {
                            printf("Enter a Course %d Code: ", j);
                            scanf("%s", course[j].Code);
                            printf("Enter a Course %d Name: ", j);
                            scanf("%s", course[j].Name);
                        }
                    }
                }
                break ;
            case 5 :
                while (!IsValidPass)
                {
                    printf("Enter The new password : ");
                    scanf("%d",&students[i].Password);

                    if ((students[i].Password) > 999999999)
                    {
                        printf("Error: Password cannot be more than 10 numbers.\n\n");
                        IsValidPass = 0;
                    }
                    else if ((students[i].Password) < 999 )
                    {
                        printf("Error: Password cannot be less than 4.\n\n");
                        IsValidPass = 0;
                    }
                    else
                    {
                        IsValidPass = 1;
                    }
                }
                break ;
            }
        }
        else
        {
            printf("Wrong Data. Try again");
            IsValidFound = 0 ;
        }
    }
    setConsoleColor(0xf9);
    printf(" Student Updated Successfully.\n\n");
    setConsoleColor(7);
}
void ringPhone()
{

    Beep(800, 300);
    Beep(800, 300);
    delay(1);
    Beep(800, 300);
    Beep(800, 300);
    delay(1);
    Beep(800, 300);
    Beep(800, 300);
}
void CallFather(void)
{
    int call_father = 0 ;
    while (!call_father)
    {
        int i=0 ;
        flag_found = 1 ;
        int str[20]= {0};
        printf("Enter The Student Name : ");
        scanf("%s",&str);

        for( i=0 ; i<count ; i++)
        {
            flag_found=strcmp(&str,&students[i].Name);
            if(flag_found==0)
            {
                break ;
            }
        }
        if(flag_found!=0)
        {
            printf("There Is No Student Called : %s ",str);
            call_father = 0 ;
        }
        if(flag_found==0)
        {
            printf("The Student Name is : %s \n",students[i].Name);
            printf("The Student`s Phone : %s \n",students[i].Phone);
            setConsoleColor(0x0A);

            printf("\n Calling Father Please Wait");
            for(int i=0; i<3; i++)
            {
                printf(".");
                Beep(800, 300);
                Beep(800, 300);
                delay(1);
            }
            printf("\n");
            setConsoleColor(7);
            setConsoleColor(0xf0);
            printf("\nCall answered \n");
            setConsoleColor(7);
            call_father = 1 ;
        }
    }

}

void DeleteStudent(void)
{
    char str[20]= {0};
    int  ID;
    int  Password;
    int  press ;
    int  i=0;

    printf("Enter The Student Name : ");
    scanf("%s",&str);
    fflush(stdin);
    fflush(stdout);
    printf("Enter The Student ID : ");
    scanf("%d",&ID);
    printf("Enter The Student Password : ");
    scanf("%d",&Password);

    setConsoleColor(0x0A);
    printf("\n LOADING PLEASE WAIT");
    for(i=0; i<3; i++)
    {
        printf(".");
        delay(1);
    }
    printf("\n");
    setConsoleColor(7);

    int IsValidFound = 0;
    while(!IsValidFound)
    {
        for(i=0; i<count; i++)
        {
            if((ID==(students[i].ID)) && (Password==(students[i].Password)) && (!strcmp(str,students[i].Name)))
            {
                flag_found = 1 ;
                break;
            }
        }
        if(flag_found==1)
        {
            IsValidFound = 1;
            ShowStudents(i);
            setConsoleColor(0xcf);
            printf("\n To Delete Student Press 1 else Press 0.\n\n");
            scanf("%d",&press);
            fflush(stdin);fflush(stdout);
            setConsoleColor(7);

            if(press==1)
            {
                students[i]=students[100];
                setConsoleColor(0xfA);

                if (press == 1)
                {
                    for (; i < count - 1; i++)
                    {
                        students[i] = students[i + 1];
                        students[i].ID = (students[i].ID)-1;
                    }
                }
                printf(" Student Deleted Successfully.\n\n");
                setConsoleColor(7);
            }
            else
            {
                printf("\n To Delete Another Student Press 2 \n");
                printf("\n To Return To The Home Page Press 0 \n");
                scanf("%d",&press);
                if(press==2)
                {
                    DeleteStudent();
                }
                IsValidFound = 1;
            }
            count--;
            i_show--;
        }

    }

}




/*****************************************************file.c***************************************************************************************************/

int loadCountFromFile()
{
    FILE *file = fopen("count.txt", "r");
    if (file == NULL)
    {
        return 0;
    }

    int count;
    fscanf(file, "%d", &count);
    fclose(file);
    return count;
}

void saveCountToFile(int count)
{
    FILE *file = fopen("count.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%d", count);
    fclose(file);
}
int loadi_showFromFile()
{
    FILE *file = fopen("i_showw.txt", "r");
    if (file == NULL)
    {
        return 0;
    }

    int count;
    fscanf(file, "%d", &i_show);
    fclose(file);
    return count;
}

void savei_showToFile(int count)
{
    FILE *file = fopen("i_show.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%d", i_show);
    fclose(file);
}
void update_file (void)
{

    for (int i=0; i < num_scan ; i++)
        student_scan(students);
    {
        FILE *file = fopen("Data.txt", "w");
        if (file == NULL)
        {
            printf("Error opening file.\n");
            return;
        }
        for (int i = 0; i < count ; i++)
        {
            fprintf(file, "%s\n", students[i].Name);
            fprintf(file, "%s\n", students[i].Email);
            fprintf(file, "%s\n", students[i].Phone);
            fprintf(file, "%d\n", students[i].NumberOfCourse);
            fprintf(file, "%d\n", students[i].Password);
            fprintf(file, "%d\n", students[i].ID);
        }
        fclose(file);
    }

}


int main()
{

    count = loadCountFromFile();
    saveCountToFile(count);

    i_show = loadCountFromFile();
    saveCountToFile(i_show);

    students[100].ID = 0 ;
    start();
    {
        FILE *file = fopen("Data.txt", "r");
        for (int i = 0; i < count ; i++)
        {
            fscanf(file, "%s", students[i].Name);
            fscanf(file, "%s", students[i].Email);
            fscanf(file, "%s", students[i].Phone);
            fscanf(file, "%d", &students[i].NumberOfCourse);
            fscanf(file, "%d", &students[i].Password);
            fscanf(file, "%d", &students[i].ID);
        }
        fclose(file);
    }
    while(1)
    {
        switch (selects(num_select))
        {
        case 1 :
            printf("How many student would you enroll: ");
            scanf("%d",&num_scan);
            for (int ii=0; ii < num_scan/2-1 ; ii++)
                student_scan(students);
            update_file ();
            UpdateAllStudents();
            break ;
        case 2 :
            EditStudent();
            update_file ();
            remove("students.txt");
            rename("students.txt", "students.txt");
            for (i_show=0; i_show < count; )
            {
                UpdateAllStudents();
            }
            break ;
        case 3 :
            remove("students.txt");
            rename("students.txt", "students.txt");
            DeleteStudent();
            for (i_show=0; i_show < count; )
            {
                UpdateAllStudents();
            }
            update_file ();

            break ;
        case 4 :
            CallFather();
            break ;
        case 5 :
            ShowAllStudents();
            break ;
        }
    }
    return 0;
}




