#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calc(float money,int guests){
    float needed_money = 0;
    int c_glasses_and_plates = 6;
    int c_table = 8;
    for(int i=0;i<guests;i++){
        needed_money +=13.99;
        if(c_glasses_and_plates == 6){
            needed_money+=5.98 + 21.02;
            c_glasses_and_plates = 0;
        }else{
            c_glasses_and_plates++;
        }
        if(c_table == 8){
            needed_money+=42;
            c_table = 0;
        }else{
            c_table++;
        }
    }
    if(needed_money != money){
        printf("Haralambi needs %.2f lv", needed_money - money);
    }
}
int zad1() {
    int guests;
    int tables = 0;
    int chairs = 0;
    int glasses_packet = 0;
    int plates_packet = 0;
    float money = 0;
    printf("Enter number of guests: ");
    scanf("%d", &guests);
    char commands[7];
    while (1) {
        printf("Enter command (or 'PARTY!' to end): ");
        scanf("%s", commands);
        if (strcmp(commands, "PARTY!") == 0) {
            break;
        } else if (strcmp(commands, "Chair") == 0) {
            chairs++;
            money += 13.99;
        } else if (strcmp(commands, "Table") == 0) {
            tables++;
            money += 42;
        } else if (strcmp(commands, "Cups") == 0) {
            glasses_packet++;
            money += 5.98;
        } else if (strcmp(commands, "Dishes") == 0) {
            plates_packet++;
            money += 21.02;
        }
    }
    printf("Total number of chairs: %d\n", chairs);
    printf("Total number of tables: %d\n", tables);
    printf("Total number of glasses packets: %d\n", glasses_packet);
    printf("Total number of plates packets: %d\n", plates_packet);
    printf("Total money spent: %.2f\n", money);
    calc(money, guests);
    return 0;
}

