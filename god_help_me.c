#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


#define MAX_LENGTH 50

typedef struct
{
    int year, month, day;
} Date;

typedef struct
{
    int index;
    char name[MAX_LENGTH];
} Student;

typedef struct
{
    char group_name[MAX_LENGTH];
    Student students[MAX_LENGTH];
}Group_sheet;

typedef struct 
{
    Group_sheet group_sheet[MAX_LENGTH];
    Date date[MAX_LENGTH];
    bool attendace_entry[MAX_LENGTH];
}Attendance_sheet;



void registration(Group_sheet group_sheet[], 
                  Student students[], 
                  int *n, 
                  int *attendance_sheet_record);

void attendance(Group_sheet group_sheet[],
                Attendance_sheet[], 
                Date date[],
                Student students[], 
                int n, 
                int *date_record, 
                int *group_record);

int main(void){
    int option;
    Attendance_sheet attendance_sheet[MAX_LENGTH];
    Group_sheet group_sheet[MAX_LENGTH];
    Date date[MAX_LENGTH];
    Student students[MAX_LENGTH];
    int  n = 0;
    int date_record = 0;
    int attendance_sheet_record = 0;
    int group_record = 0;

    do{
    system("clear");
    printf ("What do you want to do today?\n");
    printf ("1)Want to take attendace of today?\n");
    printf ("2)Want to search by date?\n");
    printf ("3)Want to search by student?\n");
    printf ("4)Want to create list of students?\n");
    printf ("5)Exit\n");
    printf ("Option:");
    scanf ("%d", &option);

    switch(option){
        case 1:
            attendance(group_sheet, attendance_sheet, date, students, n, &date_record, &group_record);
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        case 4:
            registration(group_sheet, students, &n, &attendance_sheet_record);
            break;
        case 5:
            printf("Exiting...");
            break;
        default:
            printf("Invalid option\n");
            break;
    }
} while(option != 5);

return 0;
}

void registration(Group_sheet group_sheet[], Student students[], int *n, int *attendance_sheet_record){
    system("clear");
    int validation;
    int idx = (*attendance_sheet_record)++;
    printf("Set name of the group:\t");
     if (scanf(" %49[^\n]", group_sheet[idx].group_name) != 1) {
        fprintf(stderr, "Failed to read group name\n");
        return;
    }
    printf ("How many students will be added?\t");
    scanf ("%d", &validation);

    if (validation <= 0 || validation > MAX_LENGTH ){
    *n = 0;
}

*n = validation;

for (int i = 0; i < *n; i++){
system("clear");
students[i].index = i+1;
printf ("Set the name of the student %d:\n", i+1);
scanf (" %49[^\n]", group_sheet[idx].students[i].name);
system("clear");
}
}

void attendance(Group_sheet group_sheet[],
                Attendance_sheet attendance_sheet[], 
                Date date[], 
                Student students[], 
                int n, 
                int *date_record, 
                int *group_record){
    int k = 0;
    int day, month, year, temp;
    char temp_name[MAX_LENGTH];

    system("clear");
    printf("Set the name of the group:\t");
    if (scanf(" %49[^\n]", temp_name) != 1) {
        fprintf(stderr, "Failed to read group name\n");
        return;
    }

    /* find the group in the Group_sheet array */
    while (k < MAX_LENGTH && strcmp(temp_name, group_sheet[k].group_name) != 0) {
        k++;
    }
    if (k == MAX_LENGTH) {
        printf("Group not found\n");
        return;
    }

    printf("Set date (dd/mm/yyyy): ");
    if (scanf("%d/%d/%d", &day, &month, &year) != 3 ||
        day < 1 || day > 31 ||
        month < 1 || month > 12 ||
        year <= 0) {
        printf("Date not valid\n");
        return;
    }

    if (*date_record >= MAX_LENGTH) {
        fprintf(stderr, "Date storage full\n");
        return;
    }

    /* store date in the separate date[] array */
    date[*date_record].year  = year;
    date[*date_record].month = month;
    date[*date_record].day   = day;
    (*date_record)++;

    printf("Set attendance of the day:\n");

    /* print each student from the found group and record attendance into Attendance_sheet */
    for (int j = 0; j < n; j++) {
        printf("%s\t", group_sheet[k].students[j].name);
        if (scanf("%d", &temp) != 1) temp = 0;
        /* attendance entries belong in attendance_sheet[*group_record].attendace_entry */
        attendance_sheet[*group_record].attendace_entry[j] = (temp != 0);
    }
    (*group_record)++;
}

void search_name(Group_sheet group_sheet){
    char temp_st;
    printf("Set name of student:\t");
    scanf("%49[^\n]", &temp_st);
}
