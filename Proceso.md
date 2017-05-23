# CheckPoints
Juego para la clase  de ambientes interactivos
Proceso

El proceso para crear CheckPoints, comenzó desde una idea inicial de llevar un juego infantil 
que implicase movimiento en un área, y que tuviese un factor de suerte y competitividad.

Previo a la conceptualización del juego como una carrera de estaciones, el juego pretendía ser 
una variación de “Pato-Ganzo”, donde el objeto seleccionaba los jugadores a competir de manera aleatoria. 
Los jugadores, sentados en un círculo,  debían rotarse dos objetos, los cuales se accionarían al mismo tiempo, 
seleccionando a dos de ellos y haciéndolos correr alrededor del círculo. El primero en volver, ganaría la carrera.

De esta idea inicial surgieron los conceptos de competitividad y suerte. 
La suerte, determinada por la aleatoriedad del dispositivo.

Posteriormente, en la re conceptualización, se quiso mantener el juego en términos sencillos 
con objetivos claros y determinados. Surge la idea de una carrera de estaciones, en la cual 
los jugadores deben completar un circuito dado de manera aleatoria. 

Se consideró un dispositivo el cual tendría una serie de leds, los cuales indicarían el color 
de la estación a la cual dirigirse, confirmando con algún tipo de patrón la llegada a esta, 
y enseguida señalando la siguiente estación.

Inicialmente, se pensaron las estaciones como bases con encajes metálicos para poder realizar el 
empate entre el dispositivo y la estación. Se encontraron varios problemas al hacerlo de esta manera, 
lo cual dificulto el proceso. Posteriormente, el mecanismo de empate cambio, haciéndose con lectores de 
RFID en el dispositivo, y sus respectivas tarjetas en las estaciones.

El contenedor elegido fue una caja, de un tamaño óptimo para poder ser cargada, fue hecha en corte laser, 
abriendo una abertura en la parte inferior para permitir la lectura del sensor RFID, 
se colocó un acrílico del color de la caja allí para poder ocultar la abertura. 

El código consta de series de loops, en los cuales las luces obedecen un patrón de parpadeo cuando indican 
la estación a la cual debe dirigirse, y quedándose en prendido perpetuo cuando se ha “checkeado” la estación.

Mediante pruebas, se llegó a la conclusión de que las carreras si bien eran divertidas, 
no lograban una competitividad justa debido al orden en el que se prendían las luces, 
pues a un jugador le podían corresponder estaciones más cercanas entre sí, mientras que al otro, 
más lejanas. La solución  fue hacer dos modalidades de juego, el recorrido aleatorio que ya se conocía,
y otro, con un condicional de volver al punto inicial para recibir la siguiente estación. Para esto,
se creó una nueva estación llamada base.

Se observó que la aleatoriedad era difícil de lograr debido al método de aleatoriedad de arduino 
( random()), el cual requería un seedeo para funcionar. Inicialmente se pensó en utilizar una entrada 
análoga de cualquier tipo, para así obtener un dato aleatorio, mas la solución que se dio fue con la función millis(), 
haciendo lecturas en cada loop().

La selección del formato de las bases fue de láminas de poliestireno de gran formato,
debido a su color y tamaño, pues funcionaban para dar una mejor visibilidad de la posición de las estaciones.
El último paso consto de hacer iluminación estética: Colocar un patrón de inicio y su posterior inicio colocando 
el objeto en la base (este paso al tomar tiempo, contribuye también a la aleatoriedad del randomSeed()) 
y una celebración final al terminar las estaciones. 


