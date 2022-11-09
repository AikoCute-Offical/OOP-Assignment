#include <stdio.h>

// Create default 4 phones with their information
struct Phone {
    char name[20];
    char model[20];
    int price;
    int year;
};

// Add new phones
void addPhone(Phone *phones, int &n) {
    printf("Enter name: ");
    scanf("%s", phones[n].name);
    printf("Enter model: ");
    scanf("%s", phones[n].model);
    printf("Enter price: ");
    scanf("%d", &phones[n].price);
    printf("Enter year: ");
    scanf("%d", &phones[n].year);
    n++;
}

// Search phone by name
void searchPhone(Phone *phones, int n) {
    char name[20];
    printf("Enter name: ");
    scanf("%s", name);
    for (int i = 0; i < n; i++) {
        if (strcmp(phones[i].name, name) == 0) {
            printf("Name: %s Model: %s Price: %d Year: %d \r ", phones[i].name, phones[i].model, phones[i].price, phones[i].year);
        }
    }
}

// List all phones
void listPhones(Phone *phones, int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s Model: %s Price: %d Year: %d \r ", phones[i].name, phones[i].model, phones[i].price, phones[i].year);
    }
}

// List all phones after sorting by phone name
void sortPhones(Phone *phones, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(phones[i].name, phones[j].name) > 0) {
                Phone temp = phones[i];
                phones[i] = phones[j];
                phones[j] = temp;
            }
        }
    }
    listPhones(phones, n);
}

// Save all phones to a files
void savePhones(Phone *phones, int n) {
    FILE *f = fopen("phones.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s %s %d %d \r ", phones[i].name, phones[i].model, phones[i].price, phones[i].year);
    }
    fclose(f);
}

int main() {
    Phone phones[100];
    int n = 4;
    strcpy(phones[0].name, "Samsung");
    strcpy(phones[0].model, "Galaxy S10");
    phones[0].price = 1000;
    phones[0].year = 2019;
    strcpy(phones[1].name, "Apple");
    strcpy(phones[1].model, "Iphone 11");
    phones[1].price = 1200;
    phones[1].year = 2019;
    strcpy(phones[2].name, "Xiaomi");
    strcpy(phones[2].model, "Mi 9");
    phones[2].price = 800;
    phones[2].year = 2019;
    strcpy(phones[3].name, "Huawei");
    strcpy(phones[3].model, "P30");
    phones[3].price = 900;
    phones[3].year = 2019;
    int choice;
    do {
        printf("1. Add new phone \r ");
        printf("2. Search phone \r ");
        printf("3. List all phones \r ");
        printf("4. List all phones after sorting by phone name \r ");
        printf("5. Save all phones to a file \r ");
        printf("6. Exit \r ");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPhone(phones, n);
                break;
            case 2:
                searchPhone(phones, n);
                break;
            case 3:
                listPhones(phones, n);
                break;
            case 4:
                sortPhones(phones, n);
                break;
            case 5:
                savePhones(phones, n);
                break;
            case 6:
                printf("Goodbye! \r ");
                break;
            default:
                printf("No choice! \r ");
        }
    } while (choice != 6);
    return 0;
}