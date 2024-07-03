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

