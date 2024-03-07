#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *archivo;
    char comando[100];
    char salida[10000];
    int i;

    // Abrir el archivo para escritura
    archivo = fopen("salida.csv", "w");
    if (archivo == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo.");
        exit(1);
    }
    fputs("Tiempo,Iteracion\n",archivo);
    // Ejecutar el programa 100 veces y guardar la salida en el archivo
    for (i = 0; i < 100; i++) {
        // Construir el comando a ejecutar
        snprintf(comando, sizeof(comando), "./sen 100 45");
        
        // Ejecutar el comando y redirigir la salida al archivo
        FILE *pipe = popen(comando, "r");
        if (pipe == NULL) {
            fprintf(stderr, "Error al ejecutar el comando.");
            exit(1);
        }

        // Leer la salida del comando y escribirla en el archivo
	
        while (fgets(salida, sizeof(salida), pipe) != NULL) {
            fputs(salida, archivo);
        }
	int numero = i+1; // Número entero a convertir
    	char cadena3[20];   // Buffer para almacenar la cadena resultante
    
    	// Usando sprintf para convertir el entero a una cadena de caracteres
    	sprintf(cadena3, "%d", numero);
	fputs(cadena3,archivo);
	fputs("\n",archivo);

        // Cerrar el pipe
        pclose(pipe);
    }

    // Cerrar el archivo
    fclose(archivo);

    printf("Se han ejecutado y guardado las salidas en el archivo 'salida.csv'.\n");

    return 0;
}