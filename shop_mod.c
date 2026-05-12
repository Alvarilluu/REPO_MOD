#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_INVENTORY 5

typedef struct {
    char name[50];
    int price;
    int is_tranquilizer;
} Weapon;

void generate_shop_inventory(Weapon shop[], int first_time) {
    srand(time(NULL));

    for (int i = 0; i < MAX_INVENTORY; i++) {
        // REGLA DEL MOD: Si es la primera tienda (i == 0), garantizar pistola
        if (i == 0 && first_time) {
            if (rand() % 2 == 0) {
                strcpy(shop[i].name, "Pistola Estandar");
                shop[i].is_tranquilizer = 0;
            } else {
                strcpy(shop[i].name, "Pistola Tranquilizante");
                shop[i].is_tranquilizer = 1;
            }
            shop[i].price = 150;
        } 
        else {
            // REGLA DEL MOD: Pueden seguir apareciendo mas pistolas despues
            int random_roll = rand() % 100;
            if (random_roll < 40) { // 40% de probabilidad de otra pistola
                strcpy(shop[i].name, "Pistola Adicional");
                shop[i].price = 100;
            } else {
                strcpy(shop[i].name, "Municion/Botiquin");
                shop[i].price = 25;
            }
        }
    }
}

int main() {
    Weapon current_shop[MAX_INVENTORY];
    
    printf("--- Generando Tienda del Mod ---\n");
    generate_shop_inventory(current_shop, 1); // 1 = Primera visita

    for (int i = 0; i < MAX_INVENTORY; i++) {
        printf("Slot %d: %s - Precio: %d$\n", i+1, current_shop[i].name, current_shop[i].price);
    }

    return 0;
}
