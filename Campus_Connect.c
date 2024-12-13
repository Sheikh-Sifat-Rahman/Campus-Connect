#include <windows.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
struct StudentInfo
{
    char ID[30];
    char Name[30];
    char Email[30];
    char Phone[20];
    char Department[30];
    char Club[30];
    char sports[20];
    char Adress[40];
};

/*struct Annoucement
{
    int ID[30];
    char Title[100];
    char Message[500];
    char Date[20];
};*/

#define MAX_STUDENTS 2000
// #define MAX_ANNOUNCEMENTS 1000

// struct Announcement Announcements[MAX_ANNOUNCEMENTS];
struct StudentInfo Students[MAX_STUDENTS];

// Global Variables
int i, j;
int count = 0;
int TotalStudents = 0;
int TotalCourse = 0;
char StudentID[30];
char password[] = "@admin";
char buffer[MAX_STUDENTS][2000];
int numAnnouncements = 0;
////.....end.......////

// Functions
void Animation();
void Home();
void MenuInfoMessage();
void MenuModifyMessage();
void AddNewStudent();
int SearchStudent(char searchTerm[30], int searchType);
void DeleteStudent(char StudentID[30]);
void EditStudent(int StudentFoundIndex);
void AboutUs();
void GoBackOrExit();
void ExitProject();
void Menu_Info();
void Menu_Modify();
bool PasswordCheck();
void TakingDataFromFile();
void ImportingIntoVar();
void SearchStudentChoice();
void searchingMenu();
void AdressInfo();
void AdressMenu();
void DepartmentInfo();
void Menu_DepartmentInfo();
void ClubInfo();
void Menu_ClubInfo();
void SportsInfo();
void Menu_SportsInfo();

// int LoadAnnouncements(struct Announcement *Announcements, int MaxAnnoucements );
// void AddAnnouncement(struct Announcement Announcements[], int*numAnnouncements, int MaxAnnoucements );
// void DisplayAnnouncements(struct Announcement Announcements[], int numAnnoucements );

int main()
{
    Animation();
    count = 0;
    // numAnnouncements = LoadAnnouncements(Announcements, MAX_ANNOUNCEMENTS); // Load announcements
    TakingDataFromFile();
    ImportingIntoVar();
    bool Looping = true;
    while (Looping)
    {

        Home();
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            Menu_Info();
            // GoBackOrExit();
            break;
        case 2:
            system("cls");
            Menu_Modify();
            // GoBackOrExit();
            break;
        case 3:
            system("cls");
            printf("\n\n\n\t\t\t\t Feature Will be Added Soon.....\n\n\n\n");
            GoBackOrExit();
            break;
        case 4:
            system("cls");
            //  DisplayAnnouncements(Announcements, numAnnouncements);
            // printf("\n\n\n\t\t\t\t NO Announcement For Today.\n\n\n\n");
            GoBackOrExit();
            break;
        case 5:
            system("cls");
            AboutUs();
            GoBackOrExit();
            break;
        case 0:
            system("cls");
            ExitProject();
            break;
        default:
            system("cls");
            break;
        }
    } // end

    return 0;
}

void Home()
{
    printf("\n\n\n\t\t[1] Students \n");
    printf("\t\t[2] Modify Student Info\n");
    printf("\t\t[3] Alumni\n");
    printf("\t\t[4] Announcements\n");
    printf("\t\t[5] About US\n");
    printf("\t\t[0] Exit Program\n\n");
    printf("\t\tEnter your choice:  ");
}

//*************Information Functions*****************//
void Animation()
{
    system("cls");
    char welcome[100] = "\n\n\n\n\n\t\t\t\t|............WELCOME............| \n\n\n\n";
    char effect[100] = "\n\n\t\t\t ||||||||||||||||||||||||||||||||||||||||||||||| \n\n\n\n";
    char cms[100] = "\n\n\n\n\n\t\t\t\t |...........CAMPUS CONNECT...........|\n";
    for (i = 0; i < strlen(welcome); i++)
    {
        printf("%c", welcome[i]);
        Sleep(100);
    }
    // system ("cls");
    for (i = 0; i < strlen(effect); i++)
    {
        printf("%c", effect[i]);
        Sleep(50);
    }
    system("cls");
    for (i = 0; i < strlen(cms); i++)
    {
        printf("%c", cms[i]);
        Sleep(100);
    }
}

void Menu_Info()
{
    bool Looping = true;
    while (Looping)
    {
        MenuInfoMessage();

        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            Looping = false;
            GoBackOrExit();
            break;
        case 1:
            system("cls");
            printf("\n\t\t **** Search Students ****\n\n");
            SearchStudentChoice();
            // GoBackOrExit();
            break;
        case 2:
            system("cls");
            printf("\n\t\t **** Dapartments ****\n\n");
            DepartmentInfo();
            // GoBackOrExit();
            break;
        case 3:
            system("cls");
            printf("\n\t\t **** Clubs ****\n\n");
            ClubInfo();
            // GoBackOrExit();
            break;
        case 4:
            system("cls");
            printf("\n\t\t **** Sports ****\n\n");
            SportsInfo();
            // GoBackOrExit();
            break;
        case 5:
            system("cls");
            printf("\n\t\t **** Adress ****\n\n");
            AdressInfo();
            // GoBackOrExit();
            break;
        case 6:
            system("cls");
            break;
        default:
            break;
        }
    } // end
}

void MenuInfoMessage()
{

    printf("\t\t\tINFO MENU\n");
    printf("\t\t=======================\n");
    // printf("\t\t[1] All students Info.\n");
    printf("\t\t[1] Search students\n");
    printf("\t\t[2] Department \n");
    printf("\t\t[3] Clubs \n");
    printf("\t\t[4] Sports \n");
    printf("\t\t[5] Adress \n");
    printf("\t\t[6] Clear  \n");
    printf("\t\t[0] Go Back OR Exit the Program.\n");
    printf("\t\t=======================\n");
    printf("\t\tEnter The Choice: ");
}

int SearchStudent(char searchTerm[30], int searchType)
{
    char lowersearchTerm[30];
    strcpy(lowersearchTerm, searchTerm);
    for (int i = 0; searchTerm[i]; i++)
    {
        lowersearchTerm[i] = tolower(searchTerm[i]);
    }
    int totalfound = 0;
    printf("\n\t\t **** Search Results ****\n\n");

    for (int i = 0; i < TotalStudents; i++)
    {
        char lowercaseStudentName[30];
        strcpy(lowercaseStudentName, Students[i].Name);
        for (int j = 0; lowercaseStudentName[j]; j++)
        {
            lowercaseStudentName[j] = tolower(lowercaseStudentName[j]);
        }

        // Search by ID (exact match)
        if (searchType == 1 && strcmp(searchTerm, Students[i].ID) == 0)
        {
            totalfound++;
            {
                printf("==================================================\n");
                printf("ID: \t\t%s\n", Students[i].ID);
                printf("Name: \t\t%s\n", Students[i].Name);
                printf("Email: \t\t%s\n", Students[i].Email);
                printf("Phone: \t\t%s\n", Students[i].Phone);
                printf("Department: \t%s\n", Students[i].Department);
                printf("Clubs: \t\t%s\n", Students[i].Club);
                printf("Sports: \t%s\n", Students[i].sports);
                printf("Address: \t%s\n\n", Students[i].Adress);
            }
        }
        else if (searchType == 2 && strstr(lowercaseStudentName, lowersearchTerm) != NULL)
        {
            // Search by Name (partial match)
            totalfound++;
            {
                printf("==================================================\n");
                printf("ID: \t\t%s\n", Students[i].ID);
                printf("Name: \t\t%s\n", Students[i].Name);
                printf("Email: \t\t%s\n", Students[i].Email);
                printf("Phone: \t\t%s\n", Students[i].Phone);
                printf("Department: \t%s\n", Students[i].Department);
                printf("Clubs: \t\t%s\n", Students[i].Club);
                printf("Sports: \t%s\n", Students[i].sports);
                printf("Address: \t%s\n\n", Students[i].Adress);
            }
        }
    }
    if (totalfound == 0)
    {
        printf("No student found matching the search term.\n");
        return -1; // Indicate not found
    }

    return 0; // Indicate success
}

void SearchStudentChoice()
{
    bool looping = true;
    while (looping)
    {
        searchingMenu();
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            looping = false;
            GoBackOrExit();
            break;
        case 1:
            system("cls");
            printf("\n\t\t **** Search Students By Id****\n\n");
            scanf("%s", StudentID);
            SearchStudent(StudentID, 1); // 1 indicates search by ID
            GoBackOrExit();
            break;
        case 2:
            system("cls");
            printf("\n\t\t **** Search Students By Name****\n\n");
            scanf("%s", StudentID);
            SearchStudent(StudentID, 2); // 2 indicates search by Name
            GoBackOrExit();
            break;
            /*case 3:
                 system("cls");
                 break;*/
        default:
            break;
        }
    }
}

void searchingMenu()
{
    printf("[1] Search By ID\n");
    printf("[2] Search By Name\n");
    printf("[0] Go Back OR Exit]\n");
}

void DepartmentInfo()
{
    bool Looping = true;
    while (Looping)
    {
        Menu_DepartmentInfo();

        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            Looping = false;
            GoBackOrExit();
            break;
        case 1:
            system("cls");
            printf("\n\t\t **** Students Of CSE ****\n\n");

            for (int i = 0; i < TotalStudents; i++)
            {
                if (strcasecmp(Students[i].Department, "CSE") == 0)
                {
                    printf("==================================================\n");
                    printf("ID: \t\t%s\n", Students[i].ID);
                    printf("Name: \t\t%s\n", Students[i].Name);
                    printf("Email: \t\t%s\n", Students[i].Email);
                    printf("Phone: \t\t%s\n", Students[i].Phone);
                    printf("Clubs: \t\t%s\n", Students[i].Club);
                    printf("Sports: \t%s\n", Students[i].sports);
                    printf("Address: \t%s\n\n", Students[i].Adress);
                }
            }
            GoBackOrExit();
            break;
        default:
            break;

        } // end
    }
}

void Menu_DepartmentInfo()
{
    printf("[1] CSE\n");
    printf("[0] Go Back OR Exit the Program.\n");
    printf("Enter your Choice: ");
}

void ClubInfo()
{
    bool Looping = true;
    while (Looping)
    {
        Menu_ClubInfo();

        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            Looping = false;
            GoBackOrExit();
            break;
        case 1:
            system("cls");
            printf("\n\t\t **** Students Of Computer Programming Club ****\n\n");
            // Here was buffer array.
            // TotalStudents = 0;
            // ImportingIntoVar();

            for (int i = 0; i < TotalStudents; i++)
            {
                if (strstr(Students[i].Club, "BUPCPC") != 0)
                {
                    printf("==================================================\n");
                    printf("ID: \t\t%s\n", Students[i].ID);
                    printf("Name: \t\t%s\n", Students[i].Name);
                    printf("Email: \t\t%s\n", Students[i].Email);
                    printf("Phone: \t\t%s\n", Students[i].Phone);
                    printf("Department: \t%s\n\n", Students[i].Department);
                }
            }
            // GoBackOrExit();
            break;
        case 2:
            system("cls");
            printf("\n\t\t **** Students Of Robotics Club ****\n\n");
            // Here was buffer array.
            // TotalStudents = 0;
            // ImportingIntoVar();

            for (int i = 0; i < TotalStudents; i++)
            {
                if (strstr(Students[i].Club, "BUPRC") != 0)
                {
                    printf("==================================================\n");
                    printf("ID: \t\t%s\n", Students[i].ID);
                    printf("Name: \t\t%s\n", Students[i].Name);
                    printf("Email: \t\t%s\n", Students[i].Email);
                    printf("Phone: \t\t%s\n", Students[i].Phone);
                    printf("Department: \t%s\n\n", Students[i].Department);
                }
            }
            // GoBackOrExit();
            break;
        case 3:
            system("clear");
            break;
        default:
            break;

        } // end
    }
}

void Menu_ClubInfo()
{
    printf("[1] Computer Programming Club\n");
    printf("[2] Robotics CLub\n");
    printf("[3] Clear\n");
    printf("[0] Go BAck Or Exit\n");
}

void SportsInfo()
{
    bool Looping = true;
    while (Looping)
    {
        Menu_SportsInfo();

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            Looping = false;
            GoBackOrExit();
            break;
        case 1:
            system("cls");
            printf("\n\t\t **** Cricket Players****\n\n");
            // Here was buffer array.
            // TotalStudents = 0;
            // ImportingIntoVar();

            for (int i = 0; i < TotalStudents; i++)
            {
                if (strstr(Students[i].sports, "Cricket") != 0)
                {
                    printf("==================================================\n");
                    printf("ID: \t\t%s\n", Students[i].ID);
                    printf("Name: \t\t%s\n", Students[i].Name);
                    printf("Email: \t\t%s\n", Students[i].Email);
                    printf("Phone: \t\t%s\n", Students[i].Phone);
                    printf("Department: \t%s\n\n", Students[i].Department);
                }
            }
            GoBackOrExit();
            break;
        case 2:
            system("cls");
            printf("\n\t\t **** Football Players ****\n\n");
            // Here was buffer array.
            // TotalStudents = 0;
            // ImportingIntoVar();

            for (int i = 0; i < TotalStudents; i++)
            {
                if (strstr(Students[i].sports, "Football") != 0)
                {
                    printf("==================================================\n");
                    printf("ID: \t\t%s\n", Students[i].ID);
                    printf("Name: \t\t%s\n", Students[i].Name);
                    printf("Email: \t\t%s\n", Students[i].Email);
                    printf("Phone: \t\t%s\n", Students[i].Phone);
                    printf("Department: \t%s\n\n", Students[i].Department);
                }
            }
            GoBackOrExit();
            break;
        case 3:
            system("cls");
            printf("\n\t\t **** Voleyball Players ****\n\n");
            // Here was buffer array.
            // TotalStudents = 0;
            // ImportingIntoVar();

            for (int i = 0; i < TotalStudents; i++)
            {
                if (strstr(Students[i].sports, "Voleyball") != 0)
                {
                    printf("==================================================\n");
                    printf("ID: \t\t%s\n", Students[i].ID);
                    printf("Name: \t\t%s\n", Students[i].Name);
                    printf("Email: \t\t%s\n", Students[i].Email);
                    printf("Phone: \t\t%s\n", Students[i].Phone);
                    printf("Department: \t%s\n\n", Students[i].Department);
                }
            }
            GoBackOrExit();
            break;
        case 4:
            system("cls");
            printf("\n\t\t **** Handball Players ****\n\n");
            // Here was buffer array.
            // TotalStudents = 0;
            // ImportingIntoVar();

            for (int i = 0; i < TotalStudents; i++)
            {
                if (strstr(Students[i].sports, "Handball") != 0)
                {
                    printf("==================================================\n");
                    printf("ID: \t\t%s\n", Students[i].ID);
                    printf("Name: \t\t%s\n", Students[i].Name);
                    printf("Email: \t\t%s\n", Students[i].Email);
                    printf("Phone: \t\t%s\n", Students[i].Phone);
                    printf("Department: \t%s\n\n", Students[i].Department);
                }
            }
            GoBackOrExit();
            break;
        default:
            break;

        } // end
    }
}

void Menu_SportsInfo()
{
    printf("[1] Cricket\n");
    printf("[2] Football\n");
    printf("[3] Volleyball\n");
    printf("[4] Handball\n");
    printf("[0] Go Back OR EXIT\n");
}

void AdressInfo()
{
    bool Looping = true;
    while (Looping)
    {
        AdressMenu();

        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            Looping = false;
            GoBackOrExit();
            break;
        case 1:
            system("cls");
            printf("\n\t\t **** Search Adress Of Students ****\n\n");

            int totalfound = 0;
            scanf("%s", StudentID);
            for (int i = 0; StudentID[i]; i++)
            {
                StudentID[i] = tolower(StudentID[i]);
            }
            printf("ID\tName\t\tEmail\t\t\tPhone\n");

            for (int i = 0; i < TotalStudents; i++)
            {
                char lowercaseStudentAdress[40];
                strcpy(lowercaseStudentAdress, Students[i].Adress);
                for (int j = 0; lowercaseStudentAdress[j]; j++)
                {
                    lowercaseStudentAdress[j] = tolower(lowercaseStudentAdress[j]);
                }
                // Search by Adress (exact match)
                if (strcmp(StudentID, lowercaseStudentAdress) == 0)
                {
                    totalfound++;
                    printf("%s\t%-15s\t%-30s\t%-15s\t%-15s\t%-15s\t%s\n",
                           Students[i].ID, Students[i].Name, Students[i].Email, Students[i].Phone,
                           Students[i].Department, Students[i].Club, Students[i].Adress);
                }
            }

            GoBackOrExit();
            break;
        case 2:
            system("sys");
            break;
        default:
            break;

        } // end
    }
}

void AdressMenu()
{
    printf("[1] Search Adress\n");
    printf("[2] clear\n");
    printf("[0] Go BAck OR Exit\n");
}

//*****************Modify Functions***********************//

void Menu_Modify()
{
    if (PasswordCheck())
    {
        system("cls");
        bool Looping = true;
        while (Looping)
        {

            MenuModifyMessage();
            int choice;
            scanf("%d", &choice);

            switch (choice)
            {
            case 0:

                Looping = false;
                GoBackOrExit();
                break;
            case 1:
                system("cls");
                AddNewStudent();
                GoBackOrExit();
                break;
                /*case 2:
                    system("cls");
                        printf("\n\t\t **** Edit a Student ****\n\n");
                        printf(" Enter The Student ID: ");
                        scanf("%s",StudentID);
                        int StudentFoundIndex = SearchStudent(StudentID);

                        if(StudentFoundIndex>=0)
                        {
                            EditStudent(StudentFoundIndex);
                        }
                        else
                        {
                            printf(" No Student Found\n\n");
                        }
                        GoBackOrExit();
                        */
                break;

            case 2:

                system("cls");
                printf("\n\t\t **** Delete a Student ****\n\n");
                printf(" Enter The Student ID: ");
                scanf("%s", &StudentID);
                DeleteStudent(StudentID);
                GoBackOrExit();
                break;
            case 3:
                system("cls");
                break;

            default:
                break;
            }
        }
    }
}

bool PasswordCheck()
{
    char inputPassword[30];
    int attempts = 3; // Allow 3 attempts

    while (attempts > 0)
    {
        printf("Enter password (Attempts remaining: %d): ", attempts);
        scanf("%s", inputPassword); // Get password input

        if (strcmp(inputPassword, password) == 0)
        {
            return true; // Correct password
        }
        else
        {
            printf("Incorrect password.\n");
            attempts--;
        }
    }

    printf("Too many incorrect attempts. Access denied.\n");
    return false; // Incorrect
}

void MenuModifyMessage()
{
    printf("\t\t[1] Add A New student.\n");
    // printf("\t\t[2] Edit A student.\n");
    printf("\t\t[2] Delete A student.\n");
    printf("\t\t[3] Clear The window.\n");
    printf("\t\t[0] Go Back OR Exit the Program.\n");
    printf("\t\t=======================\n");
    printf("\t\tEnter Your Choice: ");
}

void AddNewStudent()
{

    struct StudentInfo newStudent;
    system("cls");
    // ... (Get input for Name, Phone, Email, Club, Sports, Address) ..
    printf("\n\t\t **** Add new Student ****\n\n");
    printf("Enter Student ID: ");
    scanf("%s", newStudent.ID);

    printf("Enter Student's Name: ");
    scanf("%s", newStudent.Name);

    printf("Enter Student's Email address: ");
    scanf("%s", newStudent.Email);

    printf("Enter Student's phone number: ");
    scanf("%s", newStudent.Phone);

    printf("Enter Student's Department: ");
    scanf("%s", newStudent.Department);

    printf("Enter Student's joined clubs: ");
    scanf("%s", newStudent.Club);

    printf("Enter Student's sports info: ");
    scanf("%s", newStudent.sports);

    printf("Enter Student's address: ");
    scanf("%s", newStudent.Adress);

    FILE *fp = fopen("CseDepartmentRecord.csv", "a"); // Open in append mode

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s\n",
            newStudent.ID, newStudent.Name, newStudent.Phone, newStudent.Email, newStudent.Department,
            newStudent.Club, newStudent.sports, newStudent.Adress);

    fclose(fp);
    printf("Student information added successfully.\n");
}

void EditStudent(int StudentFoundIndex)
{
}

void DeleteStudent(char StudentID[30])
{
    FILE *fp, *tempfp;
    char line[2000];
    int found = 0;

    fp = fopen("CseDepartmentRecord.csv", "r");
    tempfp = fopen("temp.csv", "w"); // Temporary file

    if (fp == NULL || tempfp == NULL)
    {
        printf("Error opening files.\n");
        return;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char currentID[30];
        sscanf(line, "%[^,]", currentID); // Extract ID from the line

        if (strcmp(currentID, StudentID) != 0)
        {
            fputs(line, tempfp); // Write to temp file if not the target ID
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(tempfp);

    if (found)
    {
        remove("CseDepartmentRecord.csv");             // Delete original file
        rename("temp.csv", "CseDepartmentRecord.csv"); // Rename temp file
        printf("Student with ID %s deleted successfully.\n", StudentID);
    }
    else
    {
        remove("temp.csv"); // Remove temp file if student not found
        printf("Student with ID %s not found.\n", StudentID);
    }
}

//***************Navigation Function *************************//

void GoBackOrExit()
{
    getchar();
    char choice;
    printf(" Go back[b]? or Exit[0] ?: ");
    scanf("%c", &choice);
    if (choice == '0')
    {
        ExitProject();
    }
    else
    {
        system("cls");
    }
}

void AboutUs()
{
    printf("\n\n\t\t\t\t  Presented by-\n");
    printf("\t\t\t\t ==============-\n");
    printf("\n\t\t\t\tSumehra Afsheen Nuhaa");
    printf("\n\t\t\t\tID: 23524202122");
    printf("\n\t\t\t\tMehrab Hossain");
    printf("\n\t\t\t\tID: 23524202112");
    printf("\n\t\t\t\tSheikh Sifat Rahman");
    printf("\n\t\t\t\tID: 23524202108");
    printf("\n\t\t\t\tNafiz Al Anjim");
    printf("\n\t\t\t\tID: 23524202146");
    printf("\n\t\t\t\tRifat Al Hasan");
    printf("\n\t\t\t\tID: 23524202096\n");
}

void ExitProject()
{
    system("cls");
    int i;
    char ThankYou[100] = "\n\n\t\t\t\t ========== THANK YOU =========\n";
    char SeeYouSoon[100] = "\n\n\t\t\t\t========= COME AGAIN ======\n";
    for (i = 0; i < strlen(ThankYou); i++)
    {
        printf("%c", ThankYou[i]);
        Sleep(40);
    }
    for (i = 0; i < strlen(SeeYouSoon); i++)
    {
        printf("%c", SeeYouSoon[i]);
        Sleep(40);
    }
    exit(0);
}

///////////////////////////////

void TakingDataFromFile()
{

    char line[1024];
    FILE *CseDepartmentRecord_file = fopen("CseDepartmentRecord.csv", "r");
    if (CseDepartmentRecord_file == NULL)
    {
        printf("Error: could not open file\n");
        exit(-1);
    }
    fgets(line, sizeof(line), CseDepartmentRecord_file);
    count = 0;

    while (fgets(line, sizeof(line), CseDepartmentRecord_file) != NULL && count < MAX_STUDENTS)
    {
        strcpy(buffer[count], line);
        count++;
    }
    fclose(CseDepartmentRecord_file);
}

void ImportingIntoVar() // importing data into struct varibales from buffer array.
{
    char *data;
    TotalStudents = 0;
    // count is a global var and is number of students

    for (int i = 0; i < count; i++)
    {
        data = strtok(buffer[i], ",");
        if (data)
            strcpy(Students[TotalStudents].ID, data);

        data = strtok(NULL, ",");
        if (data)
            strcpy(Students[TotalStudents].Name, data);

        data = strtok(NULL, ",");
        if (data)
            strcpy(Students[TotalStudents].Email, data);

        data = strtok(NULL, ",");
        if (data)
            strcpy(Students[TotalStudents].Phone, data);

        data = strtok(NULL, ",");
        if (data)
            strcpy(Students[TotalStudents].Department, data);

        data = strtok(NULL, ",");
        if (data)
            strcpy(Students[TotalStudents].Club, data);

        data = strtok(NULL, ",");
        if (data)
            strcpy(Students[TotalStudents].sports, data);

        data = strtok(NULL, ",");
        if (data)
            strcpy(Students[TotalStudents].Adress, data);

        Students[TotalStudents].Adress[strcspn(Students[TotalStudents].Adress, "\r\n")] = 0;
        TotalStudents++;
    }
}

/*
int LoadAnnouncements(struct Announcement Announcements[], int MaxAnnoucements )
{
     FILE *AnnouncementFile = fopen("AnnouncementFile.csv", "r"); // Replace with your file name
    if (AnnouncementFile == NULL)
    {
        printf("Error opening announcements file.\n");
        return 0; // No announcements loaded
    }

    int numAnnouncements = 0;
    char line[MAX_ANNOUNCEMENTS]; // may use 1000 instead

    fgets(line, sizeof(line), AnnouncementFile); //for skiping header of the file)

    while (fgets(line, sizeof(line), fgets(line, sizeof(line), AnnouncementFile) != NULL && numAnnouncements < MaxAnnoucements) )
    {
        char *token;

        token = strtok(line, ",");
        Announcements[numAnnouncements].ID = atoi(token);

        token = strtok(NULL, ",");
        strcpy(Announcements[numAnnouncements].Date, token);

        token = strtok(NULL, "\""); // Start reading quoted string
        strcpy(Announcements[numAnnouncements].Title, token);
        token = strtok(NULL, "\""); // Finish reading quoted string

        // Get Message (handling potential commas)
        token = strtok(NULL, "\"");
        strcpy(Announcements[numAnnouncements].Message, token);
        token = strtok(NULL, "\"");

        numAnnouncements++;

    }
    fclose(AnnouncementFile);
    return numAnnouncements;
}

 void AddAnnouncement(struct Announcement Announcements[], int*numAnnouncements, int MaxAnnoucements )
{

}

void DisplayAnnouncements(struct Announcement Announcements[], int numAnnoucements )
{
    if (numAnnouncements == 0) {
        printf("There are no announcements yet.\n");
        return;
    }

    printf("\n\t\t **** Announcements ****\n\n");
    printf("ID\tDate\t\tTitle\t\t\tMessage\n");

    for (int i = 0; i < numAnnouncements; i++) {
        printf("%d\t%s\t%-30s\t%s\n",
            Announcements[i].ID, Announcements[i].Date, Announcements[i].Title, Announcements[i].Message);
    }

    GoBackOrExit();
}
*/