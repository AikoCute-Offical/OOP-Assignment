    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    //Create 4 default phones.
    struct Phone {
        char Code [20];
        char Name [100];
        float Price;
        char ManuFacturer[20];
    };

    // Add new phones.
    struct Phone *addPhone(struct Phone *phone, int *size) {
        int newSize = *size + 1;
        struct Phone *newPhone = (struct Phone *) realloc(phone, newSize * sizeof(struct Phone));
        if (newPhone == NULL) {
            printf("Error! memory not allocated.");
            exit(0);
        }
        printf("Enter Code: ");
        scanf("%s", newPhone[newSize - 1].Code);

        // Enter Name Phone : Iphone 13 Pro Max
        printf("Enter Name: ");
        scanf("%s", newPhone[newSize - 1].Name);

        printf("Enter Price: ");
        scanf("%f", &newPhone[newSize - 1].Price);

        printf("Enter ManuFacturer: ");
        scanf("%s", newPhone[newSize - 1].ManuFacturer);

        *size = newSize;
        return newPhone;
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

// main func
    int main() {
        int n = 4;
        struct Phone *phone = (struct Phone *) malloc(n * sizeof(struct Phone));
        strcpy(phone[0].Code, "P01");
        strcpy(phone[0].Name, "Iphone");
        phone[0].Price = 1000;
        strcpy(phone[0].ManuFacturer, "Apple");
        strcpy(phone[1].Code, "P02");
        strcpy(phone[1].Name, "Samsung");
        phone[1].Price = 900;
        strcpy(phone[1].ManuFacturer, "Samsung");
        strcpy(phone[2].Code, "P03");
        strcpy(phone[2].Name, "Oppo");
        phone[2].Price = 800;
        strcpy(phone[2].ManuFacturer, "Oppo");
        strcpy(phone[3].Code, "P04");
        strcpy(phone[3].Name, "Vivo");
        phone[3].Price = 700;
        strcpy(phone[3].ManuFacturer, "Vivo");
        int choice;
        do {
            printf("1. Add new phone \n");
            printf("2. Display all phones \n");
            printf("3. Search for a phone by name \n");
            printf("4. Display sorted phones by name \n");
            printf("5. Save all phones to file ?dataP.txt? \n");
            printf("6. Load all phones from file ?dataP.txt? \n");
            printf("7. Exit \n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    phone = addPhone(phone, &n);
                    break;
                case 2:
                    DisplayPhone(phone, n);
                    break;
                case 3:
                    SearchPhone(phone, n);
                    break;
                case 4:
                    SortPhone(phone, n);
                    break;
                case 5:
                    SavePhone(phone, n);
                    break;
                case 6:
                    LoadPhone(phone, &n);
                    break;
                case 7:
                    printf("Goodbye! \n");
                    break;
                default:
                    printf("No choice! \n");
                    break;
            }
        } while (choice != 7);
        return 0;
    }

    
