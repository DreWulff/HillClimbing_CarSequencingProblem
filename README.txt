EJECUCION:
Para la ejecucion del programa primero se debe de compilar.
Para esto se puede utilizar el siguiente comando:

    make

Lo cual genera un archivo ejecutable de nombre "main".
Para ejecutar este se debe de especificar tambien el directorio
y nombre de una instancia del problema CSP de la siguiente forma:

    ./main ./instances/pb_200_01.txt

Donde "./instances/" refiere al directorio en que se encuentra
la instancia, y "pb_200_01.txt" es el archivo correspondiente a
la instancia con la que trabajar.
No se incluyen las instancias, pero se considera que el formato de
las instancias a trabajar es el definido en CSPLib, en la pagina
https://www.csplib.org/Problems/prob001/, y se pueden descargar
instancias con este formato desde la seccion "Data files" en
https://www.csplib.org/Problems/prob001/data/ProblemDataSet200to400.zip

Para borrar los archivos .o y el archivo ejecutable producidos con el
comando "make", se puede ejecutar el siguiente comando:

    make clean

OUTPUT:
El programa al ser ejecutado con una instancia valida del problema
segun las consideraciones previamente mencionadas, ha de imprimir en
la terminal de ejecucion un arreglo correspondiente a la solucion
inicial aleatoria generada a partir de los parametros de la instancia.