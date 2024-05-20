
#include <stdio.h>


void add2PB(char *name, char *phone_number, char *filename) {
    FILE *f = fopen(filename, "a");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }

    
    fprintf(f, "%s,", name);

    
    fprintf(f, "%s\n", phone_number);

    fclose(f);
}

int main() {
    char name[100];
    char phone_number[20];
    char filename[] = "phoneBook.txt";

   
    printf("Enter name and phone number: ");
    scanf("%99[^,\n]%*c", name); 
    scanf("%19[^\n]%*c", phone_number); 
    add2PB(name, phone_number, filename);

    printf("Added to phoneBook!\n");

    return 0;
}
