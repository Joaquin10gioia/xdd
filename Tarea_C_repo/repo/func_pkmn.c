#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "func_pkmn.h"

// Devuelve un puntero de la clase pokemon con sus valores rellenado
pokemon * crear_pokemon(char *nombre, char *tipo, int hp, int ataque, int defensa, int velocidad) {
    pokemon *nuevo = (pokemon *)malloc(sizeof(pokemon));
    if (nuevo == NULL) return NULL;

    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo->tipo, tipo);
    nuevo->hp = hp;
    nuevo->hp_max = hp;  // guardo el hp inicial para la barra despues
    nuevo->ataque = ataque;
    nuevo->defensa = defensa;
    nuevo->velocidad = velocidad;

    return nuevo;
}

void liberar_equipo_pokemon(pokemon *p){
    if (p != NULL) {
        free(p);
    }
}


// Función para obtener un pokémon según la selección
pokemon * crear_equipo_pokemon(){
    /*
    Esta funcion solo crea 1 pokemon por equipo, 
    modificar en caso de querer tener más de un pokemon en el equipo
    */
    int eleccion = seleccionar_pokemon();
    switch(eleccion) {
        case 1:
            return crear_pokemon("Charizard", "Fuego", 30, 12, 10, 11);
        case 2:
            return crear_pokemon("Blastoise", "Agua", 32, 11, 13, 10);
        case 3:
            return crear_pokemon("Venusaur", "Planta", 31, 10, 12, 11);
        case 4:
            return crear_pokemon("Pikachu", "Eléctrico", 25, 10, 8, 15);
        
        //Ingrese más casos si desean

        default:
            return crear_pokemon("Charizard", "Fuego", 30, 12, 10, 11);
    }
}


// Función de selección de enemigo aleatorio
pokemon * generar_rival_aleatorio(){
    /*
    Esta funcion solo crea 1 pokemon por equipo, 
    modificar en caso de querer tener más de un pokemon en el equipo
    */
    srand(time(NULL));
    int enemigo = (rand() % 4) + 1;
    // use el mismo switch que en crear_equipo para no repetir tanto codigo
    switch(enemigo) {
        case 1:
            return crear_pokemon("Charizard", "Fuego", 30, 12, 10, 11);
        case 2:
            return crear_pokemon("Blastoise", "Agua", 32, 11, 13, 10);
        case 3:
            return crear_pokemon("Venusaur", "Planta", 31, 10, 12, 11);
        case 4:
            return crear_pokemon("Pikachu", "Eléctrico", 25, 10, 8, 15);
        default:
            return crear_pokemon("Charizard", "Fuego", 30, 12, 10, 11);
    }
}

// Funciones basicas --------------------------------------------------------------------------------

// Función para mostrar el menú de selección
int seleccionar_pokemon(){
    int opcion;
    printf("\n========== ELIGE TU POKÉMON ==========\n");
    printf("1. Charizard (Fuego) - Ataque: 12, Defensa: 10, Velocidad: 11\n");
    printf("2. Blastoise (Agua) - Ataque: 11, Defensa: 13, Velocidad: 10\n");
    printf("3. Venusaur (Planta) - Ataque: 10, Defensa: 12, Velocidad: 11\n");
    printf("4. Pikachu (Eléctrico) - Ataque: 10, Defensa: 8, Velocidad: 15\n");
    
    // Pueden agregar opciones si desean...

    printf("=====================================\n");
    printf("Opción (1-4): ");
    scanf("%d", &opcion);
    getchar(); // Consumir el salto de línea
    return opcion;
}

// Función para mostrar el estado de un pokémon
void mostrar_pokemon(pokemon *p){
    printf("\n%s (%s)\n", p->nombre, p->tipo);
    printf("HP: [");
    int barra_llena = (p->hp * 20) / p->hp_max;
    for (int i = 0; i < 20; i++) {
        if (i < barra_llena) printf("=");
        else printf("-");
    }
    printf("] %d/%d\n", p->hp, p->hp_max);
}




// Función para mostrar el menú de acciones
int mostrar_menu_acciones(pokemon *jugador, pokemon *enemigo){
    int accion;
    printf("\n--- Turno de %s ---\n", jugador->nombre);
    mostrar_pokemon(jugador);
    mostrar_pokemon(enemigo);
    printf("\nOpciones:\n");
    printf("1. Atacar\n");
    printf("2. Defensa\n");;
    printf("3. Ver estado\n");
    printf("4. Rendirse\n");
    printf("Elige (1-4): ");
    scanf("%d", &accion);
    getchar();
    return accion;
}


// --------------------------------------------------------------------------------------------------



// Función para calcular el daño
int calcular_dano(pokemon *atacante, pokemon *defensor){
    int dano = atacante->ataque - defensor->defensa;
    // para que no haga dano negativo
    if (dano <= 0) dano = 1;
    return dano;
}


void aplicar_dano(pokemon *defensor, int dano){
    defensor->hp -= dano;
    // que no quede en negativo el hp
    if (defensor->hp < 0) defensor->hp = 0;
}



// Función para realizar el combate
int combate(pokemon *jugador, pokemon *enemigo){   
    while (jugador->hp > 0 && enemigo->hp > 0) {

        int accion = mostrar_menu_acciones(jugador, enemigo);

        if (accion == 1) {
            int dano = calcular_dano(jugador, enemigo);
            aplicar_dano(enemigo, dano);
            printf("\n%s atacó e hizo %d de daño!\n", jugador->nombre, dano);

        } else if (accion == 2) {
            // subi la defensa un poco temporalmente
            jugador->defensa += 3;
            printf("\n%s se puso en defensa!\n", jugador->nombre);

        } else if (accion == 3) {
            mostrar_pokemon(jugador);
            mostrar_pokemon(enemigo);

        } else if (accion == 4) {
            printf("\nTe rendiste...\n");
            return 0;
        }

        // turno del enemigo si sigue vivo
        if (enemigo->hp > 0) {
            int dano_enemigo = calcular_dano(enemigo, jugador);
            aplicar_dano(jugador, dano_enemigo);
            printf("%s atacó y te hizo %d de daño!\n", enemigo->nombre, dano_enemigo);
        }
    }

    if (jugador->hp > 0) {
        printf("\nGanaste!\n");
        return 1;
    } else {
        printf("\nPerdiste...\n");
        return 0;
    }
}