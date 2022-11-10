    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    //Create 4 default phones.
    struct Phone {
        char Code [20];
        char Name [50];
        float Price;
        char ManuFacturer[20];
    };

    // Add new phones.
    void AddPhone(struct Phone *p, int *n) {
        printf("Enter the code of the phone: ");
        scanf("%s", p[*n].Code);
        printf("Enter the name of the phone: ");
        scanf("%s", p[*n].Name);
        printf("Enter the price of the phone: ");
        scanf("%f", &p[*n].Price);
        printf("Enter the manufacturer of the phone: ");
        scanf("%s", p[*n].ManuFacturer);
        *n = *n + 1;
    }

    // Display all phones.
    void DisplayPhone(struct Phone *p, int n) {
        int i;
        for (i = 0; i < n; i++) {
            printf("Code: %s - Name: %s - Price: %f - Manufacturer: %s \n", p[i].Code, p[i].Name, p[i].Price, p[i].ManuFacturer);
        }
    }

    // Search for a phone by name.

    void SearchPhone(struct Phone *p, int n) {
        char name[50];
        int i;
        printf("Enter the name of the phone: ");
        scanf("%s", name);
        for (i = 0; i < n; i++) {
            if (strcmp(p[i].Name, name) == 0) {
                printf("Code: %s - Name: %s - Price: %f - Manufacturer: %s \n", p[i].Code, p[i].Name, p[i].Price, p[i].ManuFacturer);
            }
        }
    }

    // Display sorted phones by name (the original list did not change)

    void SortPhone(struct Phone *p, int n) {
        int i, j;
        struct Phone temp;
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (strcmp(p[i].Name, p[j].Name) > 0) {
                    temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
                }
            }
        }
        DisplayPhone(p, n);
    }

    // Save all phones to file ?dataP.txt?

    void SavePhone(struct Phone *p, int n) {
        FILE *f;
        f = fopen("dataP.txt", "w");
        int i;
        for (i = 0; i < n; i++) {
            fprintf(f, "%s %s %f %s \n", p[i].Code, p[i].Name, p[i].Price, p[i].ManuFacturer);
        }
        fclose(f);
    }

    // Load all phones from file ?dataP.txt?

    void LoadPhone(struct Phone *p, int *n) {
        FILE *f;
        f = fopen("dataP.txt", "r");
        while (!feof(f)) {
            fscanf(f, "%s %s %f %s \n", p[*n].Code, p[*n].Name, &p[*n].Price, p[*n].ManuFacturer);
            *n = *n + 1;
        }
        fclose(f);
    }

    int main() {
        struct Phone p[100];
        int n = 4;
        int choice;
        strcpy(p[0].Code, "P01");
        strcpy(p[0].Name, "Iphone");
        p[0].Price = 1000.5;
        strcpy(p[0].ManuFacturer, "Apple");
        strcpy(p[1].Code, "P02");
        strcpy(p[1].Name, "Samsung");
        p[1].Price = 900.5;
        strcpy(p[1].ManuFacturer, "Samsung");
        strcpy(p[2].Code, "P03");
        strcpy(p[2].Name, "Nokia");
        p[2].Price = 800.0;
        strcpy(p[2].ManuFacturer, "Nokia");
        strcpy(p[3].Code, "P04");
        strcpy(p[3].Name, "Oppo");
        p[3].Price = 700.5;
        strcpy(p[3].ManuFacturer, "Oppo");
        do {
            printf("1. Add a new phone \n");
            printf("2. Display all phones \n");
            printf("3. Search for a phone by name \n");
            printf("4. Display sorted phones by name \n");
            printf("5. Save all phones to file ?dataP.txt? \n");
            printf("6. Load all phones from file ?dataP.txt? \n");
            printf("0. Exit \n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    AddPhone(p, &n);
                    break;
                case 2:
                    DisplayPhone(p, n);
                    break;
                case 3:
                    SearchPhone(p, n);
                    break;
                case 4:
                    SortPhone(p, n);
                    break;
                case 5:
                    SavePhone(p, n);
                    break;
                case 6:
                    LoadPhone(p, &n);
                    break;
                case 7:
                    printf("Goodbye! \n");
                    break;
                default:
                    printf("No choice! \n");
            }
        } while (choice != 7);
        return 0;
    }


