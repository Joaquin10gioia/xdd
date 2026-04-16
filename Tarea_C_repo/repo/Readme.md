# Simulador de Combate Pokémon

## Integrantes
- [nombre]

## ¿Cómo compilar?

Primero asegúrate de tener gcc instalado. Luego en la terminal:

```bash
make
```

Para ejecutar:

```bash
./pkmn_sim
```

Para limpiar los archivos generados:

```bash
make clean
```

## Funciones principales

**crear_pokemon**: Reserva memoria dinámica con malloc y asigna los stats del pokémon (nombre, tipo, hp, ataque, defensa, velocidad).

**liberar_equipo_pokemon**: Libera la memoria reservada por crear_pokemon para evitar memory leaks.

**crear_equipo_pokemon**: Muestra el menú de selección y retorna el pokémon que eligió el jugador.

**generar_rival_aleatorio**: Elige un pokémon enemigo al azar usando rand().

**calcular_dano**: Calcula el daño de un ataque según el ataque del atacante y la defensa del defensor.

**aplicar_dano**: Resta el daño calculado al HP del defensor.

**combate**: Maneja el loop principal del combate turno a turno hasta que uno de los dos pokémon llegue a 0 HP.

## Notas
- Desarrollado en Linux. Compilado y probado con gcc.
