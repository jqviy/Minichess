# PLANTILLA DE EJEMPLO DE COMO INCIAR UN REPOSITORIO
Este repositorio está orientado para facilitar la creación de un proyecto inicial para los trabajos de informática industrial de la ETSIDI (UPM).

Se han incluido los siguientes aspectos:
* un fichero gitignore que excluye del control de versiones los ficheros temporales generados al compilar así como las configuraciones propias de cada usuario. 
* las configuraciones para que se genere el ejecutable en bin, y además ese sea su directorio de trabajo tanto en la ejecución directa como desde el IDE
* la inclusion del directorio lib con los ficheros de cabecera y librerias freeglut y etsidilib
* la inclusion de las dll necesarias para el correcto funcionamiento de estas librerías y que deben acompañar al ejecutable en su ejecución.

Para verificar su correcto funcionamiento se ha incluido la estructura típica de datos con directorios para imagenes, sonidos y fuentes, pero que obviametne ya dependerá de como se deseea estructurar. En base a la misma se ha introducido en un main el código mínimo para mostrar una imagen plana en un mundo 3D. Los directorios usados por el binario serán relativos a su ubicación.

## USO DE LA PLANTILLA
Basta para ello descargarse el código copiarlo en el repositorio que se desee empezar y desde el IDE de Visual Studio 2022, cambiar los nombres del proyecto y de la solución al propio del grupo. Modificar este fichero de readme. En principio no haría falta hacer mas. 
