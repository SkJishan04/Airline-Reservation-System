#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max = 0;
int seat = 0;

struct node
{
    char name[100];
    char passport_number[10];
    char Email[100];
    int seat_number;
    struct node *next;
};

struct node *insert(struct node *head, char *name, char *pass, char *email)
{

    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *temp = NULL;
    strcpy(new->name, name);
    strcpy(new->passport_number, pass);
    strcpy(new->Email, email);
    new->seat_number = ++seat;
    if (head == NULL)
    {
        new->next = NULL;
        head = new;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
    max++;
    printf("\n\t\t\tYOUR RESERVATION IS SUCCESSFUL.\n");
    return head;
}

struct node *RESERVATION(struct node *head)
{

    char name[100];
    char pass[10];
    char email[100];
    printf("\n\t\t\tWELCOME TO THE RESERVTION SYSTEM ~~\n\n");

    fflush(stdin);
    printf("\n\t\t\tPLEASE ENTER YOUR NAME : ");
    gets(name);

    printf("\n\t\t\tPLEASE ENTER YOUR PASS-PORT NUMBER : ");
    gets(pass);
    fflush(stdin);
    printf("\n\t\t\tPLEASE ENTER YOUR E-MAIL : ");
    gets(email);
    fflush(stdin);
    if (max <= 40)
    {
        head = insert(head, name, pass, email);
        return head;
    }
    else
    {
        printf("\t\t\tYOU HAVE REACHED THE MAX LIMIT OF PASSENGERS . SORRY FOR THE INCONVENIENCE .\n");
        return head;
    }
}

void PRINT(struct node *head)
{
    struct node *ptr = NULL;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\n\t\t\tTHERE IS NOT A SINGLE ENTRY .\n");
    }
    else
    {
        while (ptr)
        {
            printf("\n\t\t\tNAME            : %s\n", ptr->name);
            printf("\t\t\tPASSPORT NUMBER : %s\n", ptr->passport_number);
            printf("\t\t\tE-MAIL          : %s\n", ptr->Email);
            printf("\t\t\tSEAT NUMBER     : 2A-%d\n", ptr->seat_number);
            ptr = ptr->next;
        }
    }
}

void CANCEL(struct node *head)
{
    struct node *temp = head;
    struct node *ptr = NULL;
    if (temp == NULL)
    {
        printf("\n\t\t\tTHERE ARE NO RESERVATIONS .\n");
        return;
    }

    printf("\n\t\t\tPLEASE ENTER THE PASSSPORT-NUMBER OF THE PASSENGER YOU WANT TO CANCEL : ");
    char pass[10];
    fflush(stdin);
    gets(pass);
    if (strcmp(temp->passport_number, pass) == 0 && temp == head)
    {
        ptr = head;
        temp = temp->next;
        head = temp;
        ptr->next = NULL;
        free(ptr);
        printf("\n\t\t\tBOOKING HAS BEEN CANCELED\n");
        max--;
        return;
    }

    while (temp->next)
    {
        if (strcmp(temp->next->passport_number, pass) == 0)
        {
            ptr = temp->next;
            temp->next = temp->next->next;
            free(ptr);
            printf("\n\t\t\tBOOKING HAS BEEN DELETED .\n");
            max--;
            return;
        }
        temp = temp->next;
    }
    printf("\n\t\t\tERROR ! YOU HAVE ENTERED THE WRONG PASSPORT NUMBER .\n");
}

void SAVEFILE(struct node *head)
{
    FILE *fpointer = fopen("AIRLINE RESERVATION", "w");
    if (!fpointer)
    {
        printf("\t\t\tTHERE IS AN ERROR IN  OPENING THE FILE .\n");
        return;
    }
    fprintf(fpointer, "\t\tPASSPORT NUMBER\t\t\tNAME\t\t\t\t\tE-MAIL\n\n\n");
    struct node *temp = head;
    while (temp)
    {
        fprintf(fpointer, "\t\t%s\t\t", temp->passport_number);
        fprintf(fpointer, "\t\t%s\t\t", temp->name);
        fprintf(fpointer, "\t\t%s\t\t", temp->Email);
        fprintf(fpointer, "\n");
        temp = temp->next;
    }
    printf("\n\n\t\t\tTHE DETAILS HAVE BEEN SAVED IN FILE(AIRLINE RESERVATION).\n");
    fclose(fpointer);
}

void SHOW_NUMBER_OF_PASSENGERS()
{
    printf("\n\t\t\tTHE TOTAL NUMBER OF RESERVATIONS ARE %d .\n\t\t\tTHERE ARE %d RESERVATIONS LEFT .\n", max, (40 - max));
}

int main()
{
    printf("\t\t\t\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("\t\t\t\t\t\t|_________________________________________________________________|\n");
    printf("\t\t\t\t\t\t|              WELCOME TO THE AIRLINE RESERVATION SYSTEM .        |\n");
    printf("\t\t\t\t\t\t|_________________________________________________________________|\n");
    printf("\t\t\t\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = NULL;

    int choice;
    do
    {
        printf("\t\t\t\t\t\t _________________________________________________________________ \n");
        printf("\t\t\t\t\t\t|           1. RESERVATION                                        |\n");
        printf("\t\t\t\t\t\t|           2. CANCEL RESERVATION.                                |\n");
        printf("\t\t\t\t\t\t|           3. PRINT ALL THE PASSENGER RESERVATIONS.              |\n");
        printf("\t\t\t\t\t\t|           4. SHOW THE NUMBER OF RESERVATIONS.                   |\n");
        printf("\t\t\t\t\t\t|           5. EXIT.                                              |\n");
        printf("\t\t\t\t\t\t|_________________________________________________________________|\n");
        printf("\n\t\t\t\t\t\tPLEASE ENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = RESERVATION(head);
            break;
        case 2:
            CANCEL(head);
            break;
        case 3:
            PRINT(head);
            break;

        case 4:
            SHOW_NUMBER_OF_PASSENGERS();
            break;
        case 5:
            SAVEFILE(head);
            break;
        default:
            printf("\n\t\t\tYOU HAVE ENTERED THE WRONG OPTION .\n");
            break;
        }
    } while (choice != 5);

    return 0;
}