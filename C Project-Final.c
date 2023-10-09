#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>

#define MAX_PATIENTS 100
#define MAX_DOCTORS 50
#define MAX_APPOINTMENTS 500
#define MAX_QUANTITY 500

// define patient structures
struct patient
{
    char username[20];
    char password[20];
    char name[50];
    int age;
    int id;
    char gender[10];
    char phone[15];
    char address[100];
    char disease[50];
    char blood[10];
};
// define Doctor structures
struct doctor
{
    char username[20];
    char password[20];
    char name[50];
    char specialization[50];
    char phone[15];
    int age;
    int id;
    char gender[10];
    char address[50];
    char disease[50];
};

// define appointment structures
struct appointment
{
    int id;
    char patient_name[50];
    char doctor_name[50];
    char date[20];
    char time[20];
    char status[20];
};

// Inventory structure
struct inventory
{
    char name[50];
    float price;
    int quantity;
    int id;
};


// global arrays for patients and doctors
struct patient patients[MAX_PATIENTS];
struct doctor doctors[MAX_DOCTORS];
struct inventory inventory[MAX_QUANTITY];
struct appointment appointments[MAX_APPOINTMENTS];

// global variables for tracking number of patients and doctors
int num_patients = 0;
int num_doctors = 0;
int num_items = 0;
int num_appointments = 0;

// function to handle the login menu
void login_menu()
{
    int choice;
    do
    {
        printf("\n\n\n\n\t\t\t\t*******************************************************");
        printf("\n\t\t\t\t*********** Northern University Bangladesh ************");
        printf("\n\t\t\t\t***********            Project             ************");
        printf("\n\t\t\t\t*********** HOSPITAL MANAGEMENT SYSTEM     ************");
        printf("\n\t\t\t\t*******************************************************");
        printf("\n\n\n\t\t\t\t1. Login as patient\n");
        printf("\n\t\t\t\t2. Login as doctor\n");
        printf("\n\t\t\t\t3. Register as patient\n");
        printf("\n\t\t\t\t4. Register as doctor\n");
        printf("\n\t\t\t\t5. Exit\n");
        printf("\n\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);


        switch(choice)
        {
        case 1:
            login_patient();
            break;
        case 2:
            login_doctor();
            break;
        case 3:
            register_patient();
            break;
        case 4:
            register_doctor();
            break;
        case 5:
            exit(0);
            break;
        case 6:
            return;
        default:
            printf("\t\t\t\tInvalid choice\n");
        }
    }
    while (1);
}
// function to register a patient
void register_patient()
{
    printf("\t\t\t\tEnter username: ");
    scanf("%s", patients[num_patients].username);
    printf("\t\t\t\tEnter password: ");
    scanf("%s", patients[num_patients].password);
    printf("\t\t\t\tEnter name: ");
    num_patients++;
    clrscr();
    printf("\t\t\t\tRegistration successful!\n");
}

// function to register a doctor
void register_doctor()
{
    printf("\t\t\t\tEnter username: ");
    scanf("%s", doctors[num_doctors].username);
    printf("\t\t\t\tEnter password: ");
    scanf("%s", doctors[num_doctors].password);
    printf("\t\t\t\tEnter name: ");
    num_doctors++;
    clrscr();
    printf("\t\t\t\tRegistration successful!\n");
}

// function to login a patient
int login_patient()
{
    char username[20], password[20];
    printf("\t\t\t\tEnter username: ");
    scanf("%s", username);
    printf("\t\t\t\tEnter password: ");
    scanf("%s", password);
    for (int i = 0; i < num_patients; i++)
    {
        if (strcmp(patients[i].username, username) == 0 && strcmp(patients[i].password, password) == 0)
        {


            clrscr();
            printf("\t\t\t\tLogin successful!\n");
            main_menu();
            return i;
        }
    }
    clrscr();
    printf("\t\t\t\tInvalid username or password.\n");

    return -1;
}

// function to login a doctor
int login_doctor()
{
    char username[20], password[20];
    printf("\t\t\t\tEnter username: ");
    scanf("%s", username);
    printf("\t\t\t\tEnter password: ");
    scanf("%s", password);
    for (int i = 0; i < num_doctors; i++)
    {
        if (strcmp(doctors[i].username, username) == 0 && strcmp(doctors[i].password, password) == 0)
        {


            printf("\t\t\t\tLogin successful!\n");
            main_menu();
            return i;
        }
    }
    clrscr();
    printf("\t\t\t\tInvalid username or password.\n");
    return -1;
}
// function to patient menu
void patient_menu()
{
    int choice;
    do
    {
        printf("\n\n\n\n\t\t\t\t*************************************************");
        printf("\n\t\t\t\t         *** HOSPITAL MANAGEMENT SYSTEM ***");
        printf("\n\t\t\t\t*************************************************");
        printf("\n\n\t\t\t\t             ---Patient Menu---\n");
        printf("\n\n\t\t\t\t1. Add patient\n");
        printf("\n\t\t\t\t2. Edit Patient\n");
        printf("\n\t\t\t\t3. Delete Patient\n");
        printf("\n\t\t\t\t4. List patients\n");
        printf("\n\t\t\t\t5. Search Patient\n");
        printf("\n\t\t\t\t6. Back to main Menu\n");
        printf("\n\t\t\t\tEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_patient();
            break;
        case 2:
            edit_patient();
            break;
        case 3:
            delete_patient();
            break;
        case 4:
            list_patients();
            break;
        case 5:
            search_patient();
            break;
        case 6:
            clrscr();
            main_menu();
            break;
        default:
            printf("\t\t\t\tInvalid choice\n");
            break;
        }
    }
    while (1);
}

// function to add a patient
void add_patient()
{
    printf("\t\t\t\tEnter name: ");
    scanf("%s", patients[num_patients].name);
    printf("\t\t\t\tEnter age: ");
    scanf("%d", &patients[num_patients].age);
    printf("\t\t\t\tEnter gender (M/F): ");
    scanf(" %c", &patients[num_patients].gender);
    printf("\t\t\t\tEnter address: ");
    scanf("%s", patients[num_patients].address);
    printf("\t\t\t\tEnter phone number: ");
    scanf("%s", patients[num_patients].phone);
    printf("\t\t\t\tEnter disease: ");
    scanf("%s", patients[num_patients].disease);
    printf("\t\t\t\tEnter Blood Group: ");
    scanf("%s", patients[num_patients].blood);

    clrscr();
    printf("\t\t\t\tPatient added successfully!\n");
    num_patients++;
}

// function to edit a patient
void edit_patient()
{
    int id, choice;
    printf("\t\t\t\tEnter patient id to edit: ");
    scanf("%d", &id);
    if (id >= num_patients)
    {
        clrscr();
        printf("\t\t\t\tInvalid patient id!\n");
        return;
    }
    printf("\t\t\t\t1. Name\n");
    printf("\t\t\t\t2. Age\n");
    printf("\t\t\t\t3. Gender\n");
    printf("\t\t\t\t4. Address\n");
    printf("\t\t\t\t5. Phone\n");
    printf("\t\t\t\t6. Disease\n");
    printf("\t\t\t\t7. Disease\n");
    printf("\t\t\t\tEnter field to edit: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("\t\t\t\tEnter new name: ");
        scanf("%s", patients[id].name);
        break;
    case 2:
        printf("\t\t\t\tEnter new age: ");
        scanf("%d", &patients[id].age);
        break;
    case 3:
        printf("\t\t\t\tEnter new gender: ");
        scanf(" %c", &patients[id].gender);
        break;
    case 4:
        printf("\t\t\t\tEnter new address: ");
        scanf("%s", patients[id].address);
        break;
    case 5:
        printf("\t\t\t\tEnter new phone number: ");
        scanf("%s", patients[id].phone);
        break;
    case 6:
        printf("\t\t\t\tEnter new disease: ");
        scanf("%s", patients[id].disease);
        break;
    case 7:
        printf("\t\t\t\tEnter new Blood Group: ");
        scanf("%s", patients[id].blood);
        break;
    default:
        printf("\t\t\t\tInvalid choice!\n");
        break;
    }
    clrscr();
    printf("\t\t\t\tPatient details updated successfully!\n");
}

// function to delete a patient
void delete_patient()
{
    int id;
    printf("\t\t\t\tEnter patient id to delete: ");
    scanf("%d", &id);
    if (id >= num_patients)
    {
        clrscr();
        printf("\t\t\t\tInvalid patient id!\n");
        return;
    }
    for (int i = id; i < num_patients - 1; i++)
    {
        patients[i] = patients[i+1];
    }
    num_patients--;
    clrscr();
    printf("\t\t\t\tPatient deleted successfully!\n");
}

// function to list all patients
void list_patients()
{

    printf("ID\tName\t\tAge\tGender\tAddress\t\tPhone\t\tDisease\tBlood Group\n");
    for (int i = 0; i < num_patients; i++)
    {

        printf("%d\t%s\t\t%d\t%c\t%s\t\t%s\t\t%s\n", i, patients[i].name, patients[i].age, patients[i].gender, patients[i].address, patients[i].phone, patients[i].disease,patients[i].blood);

    }
    getch();
    clrscr();
}

// function to search for a patient by name
void search_patient()
{
    char name[50];
    printf("\t\t\t\tEnter patient name to search: ");
    scanf("%s", name);
    for (int i = 0; i < num_patients; i++)
    {

        if (strcmp(name, patients[i].name) == 0)
        {
            printf("ID\tName\t\tAge\tGender\tAddress\t\tPhone\t\tDisease\tBlood Group\n");
            printf("%d\t%s\t\t%d\t%c\t%s\t\t%s\t\t%s\n",
                   patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].address, patients[i].phone, patients[i].disease,patients[i].blood);

            return;

        }
    }
    clrscr();
    printf("\t\t\t\tPatient not found.\n");
}
// function to doctor menu
void doctor_menu()
{
    int choice;
    do
    {
        printf("\n\n\n\n\t\t\t\t*************************************************");
        printf("\n\t\t\t\t  *** WELCOME TO HOSPITAL MANAGEMENT SYSTEM ***");
        printf("\n\t\t\t\t*************************************************");
        printf("\n\n\t\t\t\t             ---Doctor Menu---\n");
        printf("\n\n\t\t\t\t1. Add Doctor\n");
        printf("\n\t\t\t\t2. Edit Doctor\n");
        printf("\n\t\t\t\t3. Delete Doctor\n");
        printf("\n\t\t\t\t4. List Doctor\n");
        printf("\n\t\t\t\t5. Search Doctor\n");
        printf("\n\t\t\t\t6. Back to main Menu\n");
        printf("\n\t\t\t\tEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_doctor();
            break;
        case 2:
            edit_doctor();
            break;
        case 3:
            delete_doctor();
            break;
        case 4:
            list_doctors();
            break;
        case 5:
            search_doctor();
            break;
        case 6:
            clrscr();
            main_menu();
            break;
        default:
            printf("\t\t\t\tInvalid choice\n");
            break;
        }
    }
    while (1);
}

// function to add a doctor
void add_doctor()
{
    printf("\t\t\t\tEnter name: ");
    scanf("%s", doctors[num_doctors].name);
    printf("\t\t\t\tEnter age: ");
    scanf("%d", &doctors[num_doctors].age);
    printf("\t\t\t\tEnter gender (M/F): ");
    scanf(" %c", &doctors[num_doctors].gender);
    printf("\t\t\t\tEnter address: ");
    scanf(" %[^\n]s", doctors[num_doctors].address);
    printf("\t\t\t\tEnter phone number: ");
    scanf("%s", doctors[num_doctors].phone);
    printf("\t\t\t\tEnter department: ");
    scanf("%s", doctors[num_doctors].specialization);
    num_doctors++;
    clrscr();
    printf("\t\t\t\tDoctor added successfully.\n");
}
// function to edit a Doctor
void edit_doctor()
{
    int id, choice;
    printf("\t\t\t\tEnter Doctor id to edit: ");
    scanf("%d", &id);
    if (id >= num_doctors)
    {
        clrscr();
        printf("\t\t\t\tInvalid Doctor id!\n");
        return;
    }
    printf("\t\t\t\t1. Name\n");
    printf("\t\t\t\t2. Age\n");
    printf("\t\t\t\t3. Gender\n");
    printf("\t\t\t\t4. Address\n");
    printf("\t\t\t\t5. Phone\n");
    printf("\t\t\t\t6. Department\n");
    printf("\t\t\t\tEnter field to edit: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("\t\t\t\tEnter new name: ");
        scanf("%s", doctors[id].name);
        break;
    case 2:
        printf("\t\t\t\tEnter new age: ");
        scanf("%d", &doctors[id].age);
        break;
    case 3:
        printf("\t\t\t\tEnter new gender: ");
        scanf(" %c", &doctors[id].gender);
        break;
    case 4:
        printf("\t\t\t\tEnter new address: ");
        scanf("%s", doctors[id].address);
        break;
    case 5:
        printf("\t\t\t\tEnter new phone number: ");
        scanf("%s", doctors[id].phone);
        break;
    case 6:
        printf("\t\t\t\tEnter new Department: ");
        scanf("%s", doctors[id].specialization);
        break;
    default:
        printf("\t\t\t\tInvalid choice!\n");
        break;
    }
    clrscr();
    printf("\t\t\t\tDoctor details updated successfully!\n");
}

// function to delete a doctor
void delete_doctor()
{
    int id;
    printf("\t\t\t\tEnter Doctor id to delete: ");
    scanf("%d", &id);
    if (id >= num_doctors)
    {
        clrscr();
        printf("\t\t\t\tInvalid Doctor id!\n");
        return;
    }
    for (int i = id; i < num_doctors - 1; i++)
    {
        doctors[i] = doctors[i+1];
    }
    num_doctors--;
    clrscr();
    printf("\t\t\t\tdoctor deleted successfully!\n");
}

// function to list all doctor
void list_doctors()
{
    printf("ID\tName\t\tAge\tGender\tAddress\t\tPhone\t\tDepartment\n");
    for (int i = 0; i < num_doctors; i++)
    {
        printf("%d\t%s\t\t%d\t%c\t%s\t\t%s\t\t%s\n", i, doctors[i].name, doctors[i].age, doctors[i].gender, doctors[i].address, doctors[i].phone, doctors[i].specialization);
    }
    getch();
    clrscr();
}

// function to search for a doctor by name
void search_doctor()
{
    char name[50];
    printf("\t\t\t\tEnter doctor name to search: ");
    scanf("%s", name);
    for (int i = 0; i < num_doctors; i++)
    {
        if (strcmp(name, doctors[i].name) == 0)
        {
            printf("ID\tName\t\tAge\tGender\tAddress\t\tPhone\t\tDepartment\n");
            printf("%d\t%s\t\t%d\t%c\t%s\t\t%s\t\t%s\n", doctors[i].id, doctors[i].name, doctors[i].age, doctors[i].gender, doctors[i].address, doctors[i].phone, doctors[i].specialization);
            return;
        }
    }
    clrscr();
    printf("\t\t\t\tDoctor not found.\n");
}

// function to Appointment menu
void appointment_menu()
{
    int choice;
    do
    {
        printf("\n\n\n\n\t\t\t\t*************************************************");
        printf("\n\t\t\t\t  *** WELCOME TO HOSPITAL MANAGEMENT SYSTEM ***");
        printf("\n\t\t\t\t*************************************************");
        printf("\n\n\t\t\t\t           ---Appointment Menu---");
        printf("\n\n\n\t\t\t\t1. Add Appointment\n");
        printf("\n\t\t\t\t2. Edit Appointment\n");
        printf("\n\t\t\t\t3. Delete Appointment\n");
        printf("\n\t\t\t\t4. List Appointment\n");
        printf("\n\t\t\t\t5. Search Appointment\n");
        printf("\n\t\t\t\t6. Back to main Menu\n");
        printf("\n\t\t\t\tEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_appointment();
            break;
        case 2:
            edit_appointment();
            break;
        case 3:
            delete_appointment();
            break;
        case 4:
            list_appointments();
            break;
        case 5:
            search_appointment();
            break;
        case 6:
            clrscr();
            main_menu();
            break;
        default:
            printf("\t\t\t\tInvalid choice\n");
            break;
        }
    }
    while (1);
}

// function to add a new appointment
void add_appointment()
{
    if (num_appointments >= MAX_APPOINTMENTS)
    {
        printf("\t\t\t\tAppointment limit reached\n");
        return;
    }
    printf("\n\n\n\n\t\t\t\t*************************************************");
    printf("\n\t\t\t\t\t\t*** ADD APPOINTMENT *** ");
    printf("\n\t\t\t\t**********************************************");
    struct appointment new_appointment;
    new_appointment.id = num_appointments + 1;
    printf("\n\n\t\t\t\tEnter patient name: ");
    scanf("%s", new_appointment.patient_name);
    printf("\n\t\t\t\tEnter doctor name: ");
    scanf("%s", new_appointment.doctor_name);
    printf("\n\t\t\t\tEnter date (DD/MM/YYYY): ");
    scanf("%s", new_appointment.date);
    printf("\n\t\t\t\tEnter time (HH:MM AM/PM): ");
    scanf("%s", new_appointment.time);
    appointments[num_appointments] = new_appointment;
    num_appointments++;
    printf("\n\t\t\t\tAppointment added successfully!\n");
}

// function to edit an appointment
void edit_appointment()
{
    int id, choice, found = 0;
    printf("\n\t\t\t\tEnter appointment ID: ");
    scanf("%d", &id);
    for (int i = 0; i < num_appointments; i++)
    {
        if (appointments[i].id == id)
        {
            found = 1;
            printf("\n\t\t\t\t1. Edit patient name");
            printf("\n\t\t\t\t2. Edit doctor name");
            printf("\n\t\t\t\t3. Edit date");
            printf("\n\t\t\t\t4. Edit time");
            printf("\n\t\t\t\t5. Return to appointment menu");
            printf("\n\t\t\t\tEnter choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\n\t\t\t\tEnter new patient name: ");
                scanf("%s", appointments[i].patient_name);
                printf("\n\t\t\t\tPatient name updated successfully!\n");
                break;
            case 2:
                printf("\n\t\t\t\tEnter new doctor name: ");
                scanf("%s", appointments[i].doctor_name);
                printf("\n\t\t\t\tDoctor name updated successfully!\n");
                break;
            case 3:
                printf("\n\t\t\t\tEnter new date (DD/MM/YYYY): ");
                scanf("%s", appointments[i].date);
                printf("\n\t\t\t\tDate updated successfully!\n");
                break;
            case 4:
                printf("\n\t\t\t\tEnter new time (HH:MM): ");
                scanf("%s", appointments[i].time);
                printf("\n\t\t\t\tTime updated successfully!\n");
                break;
            case 5:
                return;
            default:
                printf("\n\t\t\t\tInvalid choice\n");
                break;
            }
            return;
        }
    }
    if (!found)
        printf("\n\t\t\t\tAppointment not found\n");
}

// function to delete an appointment
void delete_appointment()
{
    int id, found = 0;
    printf("\n\t\t\t\tEnter appointment ID: ");
    scanf("%d", &id);
    for (int i = 0; i < num_appointments; i++)
    {
        if (appointments[i].id == id)
        {
            found = 1;
            for (int j = i; j < num_appointments - 1; j++)
            {
                appointments[j] = appointments[j + 1];
            }
            num_appointments--;
            printf("\n\t\t\t\tAppointment deleted successfully!\n");
            break;
        }
    }
    if (!found)
        printf("\n\t\t\t\tAppointment not found\n");
}

// function to list of appointments
void list_appointments()
{
    printf("\n\n\t\t\t\t\t\t LIST OF APPOINTMENTS \n\n");
    printf("%-15s%-15s%-20s%-20s%-20s%-15s\n", "Appointment ID", "Patient ID", "Patient Name", "Doctor ID", "Doctor Name", "Appointment Date");
    for (int i = 0; i < num_appointments; i++)
    {
        printf("%-15d%-15d%-20s%-20d%-20s%-15s\n", appointments[i].id, appointments[i].id, appointments[i].patient_name, appointments[i].id, appointments[i].doctor_name, appointments[i].date);
    }
}
// function to search for an appointment by ID
void search_appointment()
{
    int id;
    printf("\n\n\t\t\t\t\t\t SEARCH APPOINTMENT \n\n");
    printf("Enter the appointment ID: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < num_appointments; i++)
    {
        if (appointments[i].id == id)
        {
            printf("\n\nAppointment found!\n");
            printf("Appointment ID: %d\n", appointments[i].id);
            printf("Patient Name: %s\n", appointments[i].patient_name);
            printf("Doctor Name: %s\n", appointments[i].doctor_name);
            printf("Appointment Date: %s\n", appointments[i].date);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("\n\nAppointment not found!\n");
    }
}

// function to Medicine menu
void medicine_menu()
{
    int choice;
    do
    {
        printf("\n\n\n\n\t\t\t\t*************************************************");
        printf("\n\t\t\t\t  *** WELCOME TO HOSPITAL MANAGEMENT SYSTEM ***");
        printf("\n\t\t\t\t*************************************************");
        printf("\n\n\t\t\t\t             ---Medicine Menu---\n");
        printf("\n\n\n\t\t\t\t1. Add Medicine\n");
        printf("\n\t\t\t\t2. Edit Medicine\n");
        printf("\n\t\t\t\t3. Delete Medicine\n");
        printf("\n\t\t\t\t4. Back to main Menu\n");
        printf("\n\t\t\t\tEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_item();
            break;
        case 2:
            edit_item();
            break;
        case 3:
            delete_item();
            break;
        case 4:
            clrscr();
            main_menu();
            break;
        default:
            printf("\t\t\t\tInvalid choice\n");
            break;
        }
    }
    while (1);
}

// function to Inventory menu
void inventory_menu()
{
    int choice;
    do
    {
        printf("\n\n\n\n\t\t\t\t*************************************************");
        printf("\n\t\t\t\t  *** WELCOME TO HOSPITAL MANAGEMENT SYSTEM ***");
        printf("\n\t\t\t\t*************************************************");
        printf("\n\n\t\t\t\t           ---Inventory Menu---");
        printf("\n\n\n\t\t\t\t1. Add Item\n");
        printf("\n\t\t\t\t2. Edit Item\n");
        printf("\n\t\t\t\t3. Delete Item\n");
        printf("\n\t\t\t\t4. List Items\n");
        printf("\n\t\t\t\t5. Search Item\n");
        printf("\n\t\t\t\t6. Back to main Menu\n");
        printf("\n\t\t\t\tEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_item();
            break;
        case 2:
            edit_item();
            break;
        case 3:
            delete_item();
            break;
        case 4:
            list_items();
            break;
        case 5:
            search_item();
            break;
        case 6:
            clrscr();
            main_menu();
            break;
        default:
            printf("\t\t\t\tInvalid choice\n");
            break;
        }
    }
    while (1);
}

// function to add an item to the inventory
void add_item()
{
    printf("Enter item name: ");
    scanf("%s", inventory[num_items].name);
    printf("Enter item price: ");
    scanf("%f", &inventory[num_items].price);
    printf("Enter item quantity: ");
    scanf("%d", &inventory[num_items].quantity);
    num_items++;
}

// function to edit an item in the inventory
void edit_item()
{
    int id;
    printf("Enter item ID to edit: ");
    scanf("%d", &id);
    if (id < 1 || id > num_items)
    {
        printf("Invalid ID\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", inventory[id-1].name);
    printf("Enter item price: ");
    scanf("%f",&inventory[id-1].price);
    printf("Enter item quantity: ");
    scanf("%d", &inventory[id-1].quantity);
    printf("Item edited successfully!\n");
}

// function to delete an item from the inventory
void delete_item()
{
    int id;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);
    if (id < 1 || id > num_items)
    {
        printf("Invalid ID\n");
        return;
    }
// shift the remaining items to fill the gap
    for (int i = id-1; i < num_items-1; i++)
    {
        inventory[i] = inventory[i+1];
    }
    num_items--;
    printf("Item deleted successfully!\n");
}

// function to list all the items in the inventory
void list_items()
{
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < num_items; i++)
    {
        printf("%d\t%s\t%.2f\t%d\n", i+1, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// function to search for an item by name
void search_item()
{
    char name[50];
    printf("Enter item name to search: ");
    scanf("%s", name);
    for (int i = 0; i < num_items; i++)
    {
        if (strcmp(name, inventory[i].name) == 0)
        {
            printf("ID\tName\t\tPrice\tQuantity\n");
            printf("%d\t%s\t%.2f\t%d\n", i+1, inventory[i].name, inventory[i].price, inventory[i].quantity);
            return;
        }
    }
    printf("Item not found\n");
}

// function to bill an item
void bill_item()
{
    int id, quantity;
    printf("Enter item ID to bill: ");
    scanf("%d", &id);
    if (id < 1 || id > num_items)
    {
        printf("Invalid ID\n");
        return;
    }
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    if (quantity > inventory[id-1].quantity)
    {
        printf("Insufficient quantity\n");
        return;
    }
    float total = quantity * inventory[id-1].price;
    inventory[id-1].quantity -= quantity;
    printf("Item billed successfully!\n");
    printf("Total amount: %.2f\n", total);
}

// function to generate a report
void report()
{
    float total_sales = 0;
    printf("ID\tName\t\tPrice\tQuantity\tSales\n");
    for (int i = 0; i < num_items; i++)
    {
        float sales = inventory[i].price * (MAX_QUANTITY - inventory[i].quantity);
        printf("%d\t%s\t%.2f\t%d\t\t%.2f\n", i+1, inventory[i].name, inventory[i].price, inventory[i].quantity, sales);
        total_sales += sales;
    }
    printf("Total sales: %.2f\n", total_sales);
}

// function to handle the billing and reporting menu
void billing_reporting_menu()
{
    int choice;
    do
    {
        printf("\n\n\n\n\t\t\t\t*************************************************");
        printf("\n\t\t\t\t  *** WELCOME TO HOSPITAL MANAGEMENT SYSTEM ***");
        printf("\n\t\t\t\t*************************************************");
        printf("\n\n\t\t\t\t       ----Billing and Reporting Menu-----\n");
        printf("\n\t\t\t\t1. Bill Item\n");
        printf("\n\t\t\t\t2. Generate Report\n");
        printf("\n\t\t\t\t3. Back to Main Menu\n");
        printf("\n\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            bill_item();
            break;
        case 2:
            report();
            break;
        case 3:
            clrscr();
            main_menu();
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    while (choice != 3);
}


// function to handle the main menu
void main_menu()
{
    int choice;
    do
    {
        printf("\n\n\t\t\t\t|*************************************************|");
        printf("\n\t\t\t\t|  *** WELCOME TO HOSPITAL MANAGEMENT SYSTEM ***  |");
        printf("\n\t\t\t\t|*************************************************|");
        printf("\n\t\t\t\t|_________________________________________________|");
        printf("\n\t\t\t\t|     |                                           |");
        printf("\n\t\t\t\t|  1. | Patient Menu                              |");
        printf("\n\t\t\t\t|     |                                           |");
        printf("\n\t\t\t\t|  2. | Doctor Menu                               |");
        printf("\n\t\t\t\t|     |                                           |");
        printf("\n\t\t\t\t|  3. | Appointment Menu                          |");
        printf("\n\t\t\t\t|     |                                           |");
        printf("\n\t\t\t\t|  4. | Pharmacy Menu                             |");
        printf("\n\t\t\t\t|     |                                           |");
        printf("\n\t\t\t\t|  5. | Inventory Menu                            |");
        printf("\n\t\t\t\t|     |                                           |");
        printf("\n\t\t\t\t|  6. | Billing and Reporting Menu                |");
        printf("\n\t\t\t\t|     |                                           |");
        printf("\n\t\t\t\t|  7. | Register Menu                             |");
        printf("\n\t\t\t\t|     |                                           |");
        printf("\n\t\t\t\t|  8. | Logout                                    |");
        printf("\n\t\t\t\t|     |                                           |");
        printf("\n\t\t\t\t|  9. | Exit                                      |");
        printf("\n\t\t\t\t|_____|___________________________________________|\n");
        printf("\n\t\t\t\t       Enter choice: ");
        scanf("%d", &choice);
        clrscr();
        switch (choice)
        {
        case 1:
            patient_menu();
            break;
        case 2:
            doctor_menu();
            break;
        case 3:
            appointment_menu();
            break;
        case 4:
            medicine_menu();
            break;
        case 5:
            inventory_menu();
            break;
        case 6:
            billing_reporting_menu();
            break;
        case 7:

            break;
        case 8:
            printf("\t\t\t\tLogged out successfully!\n");
            login_menu();
            return;
        case 9:
            printf("\t\t\t\tExiting...\n");
            exit(0);
        default:
            printf("\t\t\t\tInvalid choice\n");
            break;
        }
    }
    while (1);
}
void clrscr(void)
{
    system("cls()");
}
int main()
{
    system("COLOR F5");
    login_menu();
    return 0;
}
