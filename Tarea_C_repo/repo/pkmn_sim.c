#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "func_pkmn.h"



// Función principal
int main() {
    srand(time(NULL));
    
    printf("======================================\n");
    printf("|   SIMULADOR DE POKÉMON EN CONSOLA  |\n");
    printf("======================================\n");
    
    // Selección del pokémon del jugador
    int seleccion;
    do {
        seleccion = seleccionar_pokemon();
        if (seleccion < 1 || seleccion > 4) {
            printf("Opción inválida. Intenta de nuevo.\n");
        }
    } while (seleccion < 1 || seleccion > 4);
    
    
    // Creamos la instancia del pokemon
    pokemon *mi_equipo = crear_equipo_pokemon();    
    printf("\n¡Felicidades! ¡Elegiste a %s!\n", mi_equipo->nombre);
    


    int jugar = 1;
    int res = 0;
    while(jugar){
        // Creamos al equipo pokemon del rival
        pokemon *rival = generar_rival_aleatorio();

        printf("Tu rival sera: %s\n", rival->nombre);
        printf("Presiona Enter para comenzar el combate...");
        getchar();

        // Inicio del combate
        printf("\n");
        printf("===========================================\n");
        printf("========== ¡COMIENZA EL COMBATE! ==========\n");
        printf("===========================================\n");

        res = combate(mi_equipo, rival);

        // Mostrar resultado
        printf("\n");

        printf("========== FIN DEL COMBATE ==========\n");
        if (res == 1) {
            printf("¡USTED GANA!\n");
        } else if (res == 2) {
            printf("¡SU RIVAL GANA!\n");
        }
        printf("====================================\n");

        // Liberamos memoria del pokemon rival
        free(rival);

        // Preguntamos si quiere seguir jugando

        printf("\n¿Deseas jugar de nuevo? (s/n): ");
        char opcion;
        int valid = 0;
        
        do {
            // Verificando caracter
            scanf("%c", &opcion);

            if (opcion == 's' || opcion == 'S'){
                system("cls");
                valid = 1;
            } 
            else if (opcion == 'n' || opcion == 'N') {
                system("cls");
                jugar = 0;
                valid = 1;
            }
        } while (valid == 0);
         
    }
    
    printf("\n¡Gracias por jugar!\n");
    return 0;
}
