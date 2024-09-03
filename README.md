# Minitalk
Minitalk 42

Run MiniTalk
1️⃣ make

2️⃣ ./server

3️⃣ ./client <name from the server> <"any message you want to write in strings">

4️⃣ control-z on your keyboard to close the program.


Introducción
====================================
El propósito de este proyecto es codificar un pequeño programa de intercambio de datos usando señales UNIX. Es un proyecto introductorio para los proyectos UNIX más grandes que aparecerán más adelante en el curso. El objetivo de este wiki es explicar algunos conceptos básicos del proyecto.

El tema del proyecto dice que tenemos que crear dos ejecutables, un servidor y un cliente, y esos dos procesos deben comunicarse pasando una cadena a través del cliente al servidor. Esta comunicación debe hacerse usando señales (sólo podemos usar las señales SIGUSR1 y SIGUSR2) y el PID del proceso servidor.

Instrucciones del proyecto
=================================
Generalidades
***********************************
Nombra tus ficheros ejecutables cliente y servidor.
Debes entregar un Makefile que compile tus ficheros fuente. No debe revincularse.
Debes crear un programa de comunicación en forma de cliente y servidor.
Puedes tener una variable global por programa (una para el cliente y otra para el servidor), pero tendrás que justificar su uso.
--------------------------------------------------------------------------------------------------------------------------------------
A continuación crearemos dos ficheros c, server.c y client.c, un fichero de cabecera y nuestro Makefile. Dado que el tema establece que nuestros ejecutables deben llamarse cliente y servidor, en nuestra regla make all, compilaremos nuestros archivos usando cc -o <nombre del ejecutable> <nombre del archivo c>:

cc -o cliente cliente.c compilará el archivo cliente y creará un ejecutable llamado cliente.
cc -o servidor servidor.c compilará el archivo servidor y creará un ejecutable llamado servidor.

El servidor
========================================
Primero hay que iniciar el servidor. Después de su lanzamiento, tiene que imprimir su PID.
El servidor tiene que mostrar la cadena con bastante rapidez. Rápido significa que si crees que tarda demasiado, probablemente sea demasiado.
Tu servidor debe ser capaz de recibir cadenas de varios clientes seguidos sin necesidad de reiniciarse.
La comunicación entre tu cliente y tu servidor debe hacerse sólo usando señales UNIX.
Sólo puedes utilizar estas dos señales SIGUSR1 y SIGUSR2.
‼️ NOTA: ¡1 segundo para mostrar 100 caracteres es demasiado!

El cliente
=========================================================
El cliente toma dos parámetros:
El PID del servidor.
La cadena a enviar.
El cliente debe enviar al servidor la cadena pasada como parámetro. Una vez recibida la cadena, el servidor debe imprimirla.

Explicación Visual y Ejemplos
============================================================
Gráfico 1: Comunicación Cliente-Servidor

Cliente
  |
  |-- (Señal con PID del Cliente en binario) -->
  |
Servidor

Servidor
  |
  |-- (Señal de confirmación SIGUSR1) -->
  |
Cliente

    Cliente envía su PID en binario: El cliente convierte su PID a binario y envía cada bit como una señal al servidor.
    Servidor envía confirmación: Cuando el servidor recibe correctamente el PID del cliente, envía una señal de confirmación.

Gráfico 2: Envío de Mensajes



Cliente
  |
  |-- (Señal con mensaje en binario) -->
  |
Servidor

    Cliente convierte el mensaje a binario: Cada carácter del mensaje se convierte a binario.
    Cliente envía señales: Envía cada bit del mensaje como una señal.


#### Archivo: [`minitalk.h`])
*************************************
Este archivo contiene las definiciones y declaraciones necesarias para el proyecto Minitalk. Incluye las bibliotecas estándar y define varias constantes de error y una estructura para el servidor.

**Definiciones de errores:**
- [`ERROR_1`] "Signal error\n"
- [`ERROR_2`] "Arguments error, please retry\n"
- [`ERROR_3`] "PID error, retry\n"
- [`ERROR_4`] "Connection error\n"
- [`ERROR_5`] "Empty message\n"
- [`ERROR_6`] "Server busy. Try later\n"
- [`ERROR_7`] "Connection error\n"

**Estructura [`t_server`]:**
typedef struct s_server
{
	int				pid_client;    // PID del cliente
	unsigned char	chr;           // Caracter a transmitir
	int				bit;           // Bit actual en transmisión
	int				transmiting;   // Estado de transmisión
}	t_server;

======================================================================
**Funciones declaradas en [`minitalk.h`]**

- [`void manage_errors_c(char *error);  
  Maneja errores en el cliente.
  
- [`void send_signal_s(int pid, int signal);
  Envía señales desde el servidor.
  
- [`void check_arg(char *arg_1, char *arg_2);
  Verifica los argumentos.
  
- [`void send_signal_c(int pid, int signal);
  Envía señales desde el cliente.
  
- [`void init_server(void);
  Inicializa el servidor.
  
- [`void manage_errors_s(char *error);
  Maneja errores en el servidor.
  
- [`void reset_server(char *error);
  Reinicia el servidor.

=============================================================
#### Archivo: client.c
***********************************
Lógica de Uso de Variables Globales
++++++++++++++++++++++++++++++++++++
Accesibilidad: Al ser global, g_checker puede ser accedida y modificada por múltiples funciones sin necesidad de pasarla como argumento. Esto es útil en situaciones donde varias funciones necesitan compartir un estado común, como en la recepción de señales.
Sincronización: En este código, g_checker actúa como un indicador que permite a la función send_to_server saber cuándo ha sido recibida una señal específica. Esto es crucial en la programación de señales, donde el flujo de ejecución puede ser interrumpido por eventos externos.
Simplicidad: Usar una variable global puede simplificar el código al evitar la necesidad de pasar múltiples parámetros entre funciones, especialmente en un contexto donde el estado debe ser compartido.

**Resumen de Funciones en client.c**
**1. recive_signal(int sig, siginfo_t *info, void *context)**
Propósito: Maneja las señales recibidas (SIGUSR1 y SIGUSR2).

Lógica:
Si recibe SIGUSR1, establece g_checker a 1 y marca connected como 1, indicando que el cliente está conectado.
Si recibe SIGUSR2 y connected es verdadero, imprime un mensaje de éxito y termina el programa.
Si recibe SIGUSR2 y connected es falso, llama a manage_errors_c(ERROR_6) y termina el programa.

**2. send_to_server(int pid, char c)**
Propósito: Envía un carácter al servidor como una serie de señales.

Lógica:
Itera sobre cada bit del carácter (8 bits en total).
Establece g_checker a 0 y envía SIGUSR1 si el bit correspondiente es 1, o SIGUSR2 si es 0.
Espera a que g_checker se establezca en 1 antes de continuar, asegurando que la señal fue recibida.

**3. client_loop(int pid, char *str)**
Propósito: Envía una cadena de caracteres al servidor.

Lógica:
Itera sobre cada carácter de la cadena hasta el carácter nulo ('\0').
Llama a send_to_server para cada carácter, y finalmente envía un carácter nulo para indicar el final de la cadena.

**4. main(int argc, char **argv)**
Propósito: Punto de entrada del programa.

Lógica:
Configura la acción de las señales para SIGUSR1 y SIGUSR2 utilizando sigaction.
Verifica que se pasen los argumentos correctos (PID y mensaje).
Llama a client_loop para iniciar el envío de mensajes al servidor.
Maneja errores si los argumentos no son válidos.


"Funciones declaradas en minitalk.h:"
*******************************************
"void manage_errors_c(char *error);  // Maneja errores en el cliente" 
"void send_signal_s(int pid, int signal);  // Envía señales desde el servidor" 
 "void check_arg(char *arg_1, char *arg_2);  // Verifica los argumentos" 
 "void send_signal_c(int pid, int signal);  // Envía señales desde el cliente"
 "void init_server(void);  // Inicializa el servidor" 
 "void manage_errors_s(char *error);  // Maneja errores en el servidor" 
 "void reset_server(char *error);  // Reinicia el servidor"


# Explicación de server.c
**********************************
Este archivo contiene la lógica del servidor que recibe y procesa los mensajes del cliente."

"Funciones en server.c:" 
"int main(void);  // Función principal del servidor" 
 "void init_server(void);  // Inicializa la estructura del servidor" 
"void handle_signal(int sig, siginfo_t *info, void *context);  // Manejador de señales" >
"void manage_errors_s(char *error);  // Maneja errores en el servidor" 
"void reset_server(char *error);  // Reinicia el servidor en caso de error" 


Bibliography
=================================
Signal (IPC)

Sending and Intercepting a Signal in C

sigaction

Playing around with signals

Bitwise Operators in C/C++

Bitwise Operators in C Programming

BitwiseCmd

How many bits or bytes are there in a character?

