#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

// Función para calcular el factorial de un número dado
unsigned long long calcular_factorial(int n)
{
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    return factorial;
}

long poow(long numero, long potencia)
{
    long resultado = numero;
    while (potencia > 1)
    {
        resultado = resultado * numero;
        potencia--;
    }
    return resultado;
}

// Función para realizar la tarea que se va a medir
void realizar_tarea(int n)
{
    unsigned long long resultado = 0;
    bool par = true;
    for (int i = 1; i<=n; i=i+2)
    {
        if(par){
            resultado += poow(n, i)/calcular_factorial(i);
            par = !par;
        }else{
            resultado -= poow(n, i)/calcular_factorial(i);
            par = !par;
        }
    }
    // Realizar el cálculo del factorial
    
    // Imprimir el resultado para evitar que el compilador lo optimice
}

int main(int argc, char *argv[])
{
    int numero = atoi(argv[2]); // Número para calcular el seno
    // Obtener el tiempo de inicio
    struct timeval inicio, fin;
    gettimeofday(&inicio, NULL);

    int n = atoi(argv[1]);

    // Crear un proceso hijo para realizar la tarea
    for (int i = 0; i <n; i++)
    {
        if (fork() == 0)
        {
            // Proceso hijo
            realizar_tarea(numero);
            exit(0);
        }
    }

    // Esperar a que el proceso hijo termine
    wait(NULL);

    // Obtener el tiempo de finalización
    gettimeofday(&fin, NULL);

    // Calcular el tiempo transcurrido en segundos y microsegundos
    double tiempo_transcurrido = (fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec) / 1000000.0;
	
    printf("%.6f;", tiempo_transcurrido);
    return 0;
}