/* @file HelloKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| Traducido por @konredus
*/

//Defino la libreria de Keypad
#include <Keypad.h>

//Esta parte es para indicar cuantas filas y columnas tiene el 
//teclado matricial, osea que se puede modificar tambien
const byte FILAS = 4; //4 filas
const byte COLUMNAS = 4; //4 columnas

//Con esta matriz lo que se declara es que nombres tienen
//cada uno de los botones del teclado
char variable_teclado[FILAS][COLUMNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'} };

//aqui defino en donde tengo conectado los 4 primeros pines
byte filaPins[FILAS] = {12, 11, 10, 9}; 
//Aqui se definen donde estan conectados los 4 ultimos pines del teclado
byte columnaPins[COLUMNAS] = {8, 7, 6, 5};

//Declaro la clase del teclado y le paso todas las configuraciones anteriores
Keypad teclado = Keypad( makeKeymap(variable_teclado), filaPins, columnaPins, FILAS, COLUMNAS );

void setup()
{
  //inicializo el puerto serial
  Serial.begin(9600);
}
  
void loop()
{
  //leo con la funcion get.Key() a ver si se presiono algo
  char lectura = teclado.getKey();
  
  //solo entra si este valor es verdadero
  //osea que si le llego alguna info
  
   if (lectura != NO_KEY)
  {
    //mando la info por puerto serie
    Serial.println(lectura);
  }
}
