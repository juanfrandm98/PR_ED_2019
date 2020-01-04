//////////////////////////////////////////////////
//                                              //
//              Cifras y Letras                 //
//                                              //
//         Juan Francisco Díaz Moreno           //
//                                              //
//////////////////////////////////////////////////

La práctica se ha hecho implementando todas las
clases recomendadas en el guión: Letra, BolsaLetras
ConjuntoLetras y Diccionario. Además, se han creado
otras tres, JuegoCifras y JuegoLetras para
encapsular cada juego; y Juego para reunir las dos.

El algoritmo para la obtención de palabras válidas
en el juego de las letras consiste en la ordenación
de las letras_en_juego y de las letras de la palabra
según su orden en el abecedario, e ir comprobando
si las letras de la palabra son en todo momento
menores o iguales a las que están en juego. En el
momento en que exista una letra mayor la palabra
se descarta, pues considera que esa letra no está
en juego y, por lo tanto, no se podría formar.

Para comprobar las palabras del diccionario,
las recorre todas, comprobando cuáles son válidas.

Para la prueba del juego se ha utilizado el
diccionario pokemon.txt, disponible en la carpeta
data, que incluye los nombres de los pokemon de
las tres primeras generaciones. Sin embargo,
para cargar otro diccionario basta con que esté
construido de tal forma que haya una palabra por
línea.

En la parte de las cifras hay un problema:
contempla la división no entera, pues no he
encontrado ningún algoritmo que mantuviese ese
requisito. Otra opción que encontré fue uno que
utilizaba sí o sí todas las cifras, de tal forma
que con 1, 1 y 7 no era capaz de calcular 2.

Para ejecutar el programa (desde la carpeta del
makefile):

$> ./bin/practicafinal ./datos/pokemon.txt
