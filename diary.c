#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dates {
    char date[15];
    char status[20];

    struct dates* next; 
};

struct diary {
    char ptnr[50];
    char advptnr[50];
    char rspn[50];
    char advrspn[50];
    char cnum[20];
    char court[10];
    struct dates* date;

    struct diary* next;
};
struct diary* head = NULL;

void addCase (char ptnr[], char advptnr[], char rspn[], char advrspn[], char cnum[], char court[], char firstDate[]);
void addDate (char cnum[], char date[], char status[]);
void display (char cnum[]);

int main () {
    int choice;
    char ptnr[50], advptnr[50], rspn[50], advrspn[50], cnum[20], date[15], status[20], court[10];

    do {
        printf ("Select a No. from the given Menu To:\n");
        printf ("1. Add a Case in the diary.\n2. Add a Date to an existing case\n3. Display a Case.\n4. EXIT\n");
        scanf ("%d", &choice);
        getchar();

        if (choice == 1) {
            printf ("Enter the following details:\n");
            printf ("Petitioner: ");
            fgets (ptnr, 50, stdin);
            ptnr[strcspn(ptnr, "\n")] = '\0';

            printf ("Advocate of Petitioner: ");
            fgets (advptnr, 50, stdin);
            advptnr[strcspn(advptnr, "\n")] = '\0';

            printf ("Respondent: ");
            fgets (rspn, 50, stdin);
            rspn[strcspn(rspn, "\n")] = '\0';

            printf ("Advocate of Respondent: ");
            fgets (advrspn, 50, stdin);
            advrspn[strcspn(advrspn, "\n")] = '\0';

            printf ("Case No.: ");
            fgets (cnum, 50, stdin);
            cnum[strcspn(cnum, "\n")] = '\0';

            printf ("Court: ");
            fgets (court, 11, stdin);
            court[strcspn(court, "\n")] = '\0';

            printf ("First Date: ");
            fgets (date, 50, stdin);
            date[strcspn(date, "\n")] = '\0';

            addCase (ptnr, advptnr, rspn, advrspn, cnum, court, date);
        } else if (choice == 2) {
            printf ("Case No.: ");
            fgets (cnum, 50, stdin);
            cnum[strcspn(cnum, "\n")] = '\0';
            
            printf ("Date: ");
            fgets (date, 50, stdin);
            date[strcspn(date, "\n")] = '\0';

            printf ("Status: ");
            fgets (status, 50, stdin);
            status[strcspn(status, "\n")] = '\0';

            addDate (cnum, date, status);
        } else if (choice == 3) {
            printf ("Case No.: ");
            fgets (cnum, 50, stdin);
            cnum[strcspn(cnum, "\n")] = '\0';

            display (cnum);
        } else if (choice == 4) {
            printf ("Thank You!\n");
        } else {
            printf("Enter Valid Choice!!\n");
        }
    } while (choice != 4);
    return 0;
}

void addCase (char ptnr[], char advptnr[], char rspn[], char advrspn[], char cnum[], char court[], char firstDate[]) {
    struct diary* newcase = (struct  diary*)malloc(sizeof(struct diary));

    strcpy (newcase->ptnr, ptnr);
    strcpy (newcase->advptnr, advptnr);
    strcpy (newcase->rspn, rspn);
    strcpy (newcase->advrspn, advrspn);
    strcpy (newcase->cnum, cnum);
    strcpy (newcase->court, court);

    struct dates *newdate = (struct dates*)malloc(sizeof(struct dates));
    strcpy (newdate->date, firstDate);
    strcpy (newdate->status, "First Hearing");
    newdate->next = NULL;
    newcase->date = newdate;

    newcase->next = head;
    head = newcase;

    printf ("Case Added Succesfully!!\n");
}

void addDate (char cnum[], char date[], char status[]) {
    if (head == NULL) {
        printf ("Diary is Empty\n");
        return;
    }

    struct diary* search = head;

    while (search != NULL) {
        if (strcmp(search->cnum, cnum) == 0) {
            struct dates *newdate = (struct dates*)malloc(sizeof(struct dates));
            
            strcpy (newdate->date, date);
            strcpy (newdate->status, status);
            newdate->next = NULL;

            struct dates* temp = search->date;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newdate;

            printf("Date added succefully!!\n");
            return;
        }
        search = search->next;
    }
    printf ("No such case found!!\n");
}

void display (char cnum[]) {
    if (head == NULL) {
        printf ("Diary is Empty!!\n");
        return;
    }

    struct diary* search = head;

    while (search != NULL) {
        if (strcmp(search->cnum, cnum) == 0) {
            int value, count = 0;

            printf ("Petitioner: %s, Advocate: %s.\n", search->ptnr, search->advptnr);
            printf ("Respondent: %s, Advocate: %s.\n", search->rspn, search->advrspn);
            printf ("Court: %s.\n", search->court);

            printf ("Enter 1 to get CASE HISTORY, 0 to STOP: ");
            scanf ("%d", &value);

            if (value == 1) {
                struct dates* history = search->date;

                while (history != NULL) {
                    count++;
                    printf("%d. Date: %s, Status: %s\n", count, history->date, history->status);
                    history = history->next;
                }
            }

            return;
        }
        search = search->next;
    }

    printf ("No such case found!\n");
}