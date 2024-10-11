/*

Name:        Evan Rutten
ID:          1189483
Date:        10/15/2022
Assignment:  2.1 Linked Lists

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Car_
{
    char plate_number[8];
    int mileage;
    int return_date;
    struct _Car_ *next;
} Car;

// restore list data from text file
Car *restoreList(Car *head, FILE *file)
{
    Car *current = head;

    while (!feof(file))
    {
        fscanf(file, "%s", current->plate_number);
        fscanf(file, "%d", &current->mileage);
        fscanf(file, "%d", &current->return_date);

        if (!feof(file))
        {
            current->next = (Car *)malloc(sizeof(Car));
            current = current->next;
            current->next = NULL;
        }
    }

    return head;
}

// generate new car
Car *createCar(char plate_number[], int mileage, int return_date)
{
    Car *new = (Car *)malloc(sizeof(Car));

    strcpy(new->plate_number, plate_number);
    new->mileage = mileage;
    new->return_date = return_date;
    new->next = NULL;

    return new;
}

// add car to specific list using sorting method
Car *addToList(Car *new, Car *head, char name[], char method[])
{
    if (strcmp(method, "by mileage") == 0)
    {
        if (head->mileage >= new->mileage)
        {
            new->next = head;
            head = new;
        }
        else
        {
            Car *current = head;
            while (current->next != NULL && current->next->mileage < new->mileage)
            {
                current = current->next;
            }
            new->next = current->next;
            current->next = new;
        }
    }

    if (strcmp(method, "by return date") == 0)
    {
        if (head->return_date >= new->return_date)
        {
            new->next = head;
            head = new;
        }
        else
        {
            Car *current = head;
            while (current->next != NULL && current->next->return_date < new->return_date)
            {
                current = current->next;
            }
            new->next = current->next;
            current->next = new;
        }
    }

    printf("\n[%s, %d, %d] was added to the %s list\n\n", new->plate_number, new->mileage, new->return_date, name);
    return head;
}

// remove car from specific list
Car *removeFromList(Car *old, Car *head, char name[])
{
    if (strcmp(head->plate_number, old->plate_number) == 0)
    {
        head = head->next;
    }
    else
    {
        Car *current = head;
        Car *previous = head;
        while (current->next != NULL)
        {
            current = current->next;
            if (strcmp(current->plate_number, old->plate_number) == 0)
            {
                previous->next = current->next;
                break;
            }
            previous = previous->next;
        }
        if (current->next == NULL)
        {
            previous->next = NULL;
        }
    }

    printf("\n[%s, %d, %d] was removed from the %s list", old->plate_number, old->mileage, old->return_date, name);
    return head;
}

// retrieve car from specific list
Car *getCar(char plate_number[], Car *head)
{
    Car *current = head;

    while (current != NULL)
    {
        if (strcmp(current->plate_number, plate_number) == 0)
        {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// calculate profit based on mileage
float getCharge(Car *car, int mileage)
{
    int difference = mileage - car->mileage;

    if (difference <= 200)
    {
        return 80.00;
    }
    else if (difference > 200)
    {
        return 80.00 + 0.15 * (difference - 200);
    }
    else
    {
        return 0.00;
    }
}

// print full list contents
void printList(Car *current)
{
    while (current != NULL)
    {
        printf("%s, %d, %d\n", current->plate_number, current->mileage, current->return_date);
        current = current->next;
    }
}

// update text file with new cars
void updateFile(Car *head, FILE *file)
{
    Car *current = head;
    while (current != NULL)
    {
        fprintf(file, "%s\n", current->plate_number);
        fprintf(file, "%d\n", current->mileage);
        fprintf(file, "%d", current->return_date);
        if (current->next != NULL)
        {
            fprintf(file, "\n\n");
        }
        else
        {
            break;
        }
        current = current->next;
    }
}

int main()
{
    // create major lists
    Car *available = (Car *)malloc(sizeof(Car));
    Car *rented = (Car *)malloc(sizeof(Car));
    Car *in_repair = (Car *)malloc(sizeof(Car));
    // declare associated files
    FILE *available_txt;
    FILE *rented_txt;
    FILE *in_repair_txt;
    // open all files
    available_txt = fopen("txt/available.txt", "r");
    rented_txt = fopen("txt/rented.txt", "r");
    in_repair_txt = fopen("txt/in_repair.txt", "r");
    // restore empty lists from files
    available = restoreList(available, available_txt);
    rented = restoreList(rented, rented_txt);
    in_repair = restoreList(in_repair, in_repair_txt);
    // print transaction code options
    printf("(1) add a new car to the available-for-rent list\n");
    printf("(2) add a returned car to the available-for-rent list\n");
    printf("(3) add a returned car to the repair list\n");
    printf("(4) transfer a car from the repair list to the available-for-rent list\n");
    printf("(5) rent the first available car\n");
    printf("(6) print all the lists\n");
    printf("(7) quit\n\n");
    // create values for user input
    char plate_number[8];
    int mileage;
    int return_date;
    // create values for calculating total income
    float charge;
    float total_income = 0;
    // create empty nodes for certain transaction code options
    Car *new = (Car *)malloc(sizeof(Car));
    Car *transfer = (Car *)malloc(sizeof(Car));
    // ask for transaction code until quit
    int transaction_code;
    while (transaction_code != 7)
    {
        printf("Transaction code: ");
        scanf("%d", &transaction_code);
        switch (transaction_code)
        {
        // add a new car to the available-for-rent list
        case 1:
            // recieve data
            printf("Plate number: ");
            scanf("%s", plate_number);
            printf("Mileage: ");
            scanf("%d", &mileage);
            // create car and add to list
            new = createCar(plate_number, mileage, 0);
            available = addToList(new, available, "available-for-rent", "by mileage");
            break;
        // add a returned car to the available-for-rent list
        case 2:
            // recieve data
            printf("Plate number: ");
            scanf("%s", plate_number);
            printf("Mileage: ");
            scanf("%d", &mileage);
            // ensure car exists
            transfer = getCar(plate_number, rented);
            if (transfer != NULL)
            {
                // calculate profit and add to total
                charge = getCharge(transfer, mileage);
                total_income += charge;
                printf("\nCharge: $%0.2f\n", charge);
                // remove from list
                rented = removeFromList(transfer, rented, "rented");
                // update mileage and return date then add to list
                transfer->mileage = mileage;
                transfer->return_date = 0;
                available = addToList(transfer, available, "available-for-rent", "by mileage");
            }
            else
            {
                printf("\nPlate number not found, try again\n\n");
            }
            break;
        // add a returned car to the repair list
        case 3:
            // recieve data
            printf("Plate number: ");
            scanf("%s", plate_number);
            printf("Mileage: ");
            scanf("%d", &mileage);
            // ensure car exists
            transfer = getCar(plate_number, rented);
            if (transfer != NULL)
            {
                // calculate profit and add to total
                charge = getCharge(transfer, mileage);
                total_income += charge;
                printf("\nCharge: $%0.2f\n", charge);
                // remove from list
                rented = removeFromList(transfer, rented, "rented");
                // update mileage and return date then add to list
                transfer->mileage = mileage;
                transfer->return_date = 0;
                in_repair = addToList(transfer, in_repair, "repair", "by mileage");
            }
            else
            {
                printf("\nPlate number not found, try again\n\n");
            }
            break;
        // transfer a car from the repair list to the available-for-rent list
        case 4:
            // recieve data
            printf("Plate number: ");
            scanf("%s", plate_number);
            // ensure car exists
            transfer = getCar(plate_number, in_repair);
            if (transfer != NULL)
            {
                // remove from one list and add to the other
                in_repair = removeFromList(transfer, in_repair, "repair");
                available = addToList(transfer, available, "available-for-rent", "by mileage");
            }
            else
            {
                printf("\nPlate number not found, try again\n\n");
            }
            break;
        // rent the first available car
        case 5:
            // recieve data
            printf("Return date: ");
            scanf("%d", &return_date);
            // select head of list and remove it
            transfer = available;
            available = removeFromList(transfer, available, "available-for-rent");
            // update return date and add to new list
            transfer->return_date = return_date;
            rented = addToList(transfer, rented, "rented", "by return date");
            break;
        // print all the lists
        case 6:
            printf("\n[Available for rent]\n");
            printList(available);
            printf("\n[Rented]\n");
            printList(rented);
            printf("\n[In repair]\n");
            printList(in_repair);
            printf("\n");
            break;
        // quit
        case 7:
            printf("\nTotal income: $%0.2f\n", total_income);
            printf("\n[Press any key to quit]\n");
            getchar();
            break;
        // error
        default:
            printf("Invalid transaction code, try again\n\n");
            break;
        }
    }
    // update available-for-rent file
    fclose(available_txt);
    available_txt = fopen("txt/available.txt", "w");
    updateFile(available, available_txt);
    // update rented file
    fclose(rented_txt);
    rented_txt = fopen("txt/rented.txt", "w");
    updateFile(rented, rented_txt);
    // update repair file
    fclose(in_repair_txt);
    in_repair_txt = fopen("txt/in_repair.txt", "w");
    updateFile(in_repair, in_repair_txt);
    // close all files
    fclose(available_txt);
    fclose(rented_txt);
    fclose(in_repair_txt);
    return 0;
}