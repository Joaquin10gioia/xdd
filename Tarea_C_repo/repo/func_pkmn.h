
// Estructura para un pokémon
typedef struct {
    char nombre[50];
    char tipo[20];
    int hp;
    int hp_max;
    int ataque;
    int defensa;
    int velocidad;
} pokemon;


// Funciones para manejo de memoria
pokemon * crear_pokemon(char *nombre, char *tipo, int hp, int ataque, int defensa, int velocidad);
void liberar_equipo_pokemon(pokemon *p);
pokemon * crear_equipo_pokemon();
pokemon * generar_rival_aleatorio();


// Funciones de display
int seleccionar_pokemon();
void mostrar_pokemon(pokemon *p);
int mostrar_menu_acciones(pokemon *jugador, pokemon *enemigo);


// Combate
int calcular_dano(pokemon *atacante, pokemon *defensor);
void aplicar_dano(pokemon *defensor, int dano);
int combate(pokemon *jugador, pokemon *enemigo);
