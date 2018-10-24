/*
 Sistema mimetizador visualizador de mensajes
Comunicación via serial con arduino Uno
Sandra Luz Godinez Guerrero
Abril Alejandra Santos Salas
Maria de los Angeles Espinoza Amaro
 */

//Libreria del LCD
#include <LiquidCrystal.h>
//Libreria del sensor de temperatura y humedad
#include "DHT.h"

// Definir el tipo de DHT que estamos usando, en nuestro caso es DHT11
#define DHTTYPE DHT11   

//Definir el pin al que vamos a conectar el DHT11
#define DHTPin 2

//Definir el pin de la fotoresistencia
#define pinLDR A0

//Variable donde se almacenara el valor de la fotoresistencia
int valorLDR = 0;

//Variables para guardar la humedad y temperatura
float humedad, temperatura = 0;

//Definir el pin y el tipo de DHT para obtener la humedad y temperatura
DHT dht(DHTPin, DHTTYPE);

//Crear el objeto LCD con los números correspondientes (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Velocidad a la que se mueve el texto en el display
#define velocidad 2000


//Variable para guardar el Mensaje que se va a mandar desde java
String Mensaje = "";
String mensajeCalculo = "";

//Cantidad de caracters
//Guardar caracteres del texto
int caracteres = 0;

void setup() {
  //Inicar LCD, es de 16 columnas y dos filas
  lcd.begin(16, 2);
  Serial.begin(9600);
  //Declarar como INPUT el pin de la fotoresistencia
  pinMode(pinLDR, INPUT);
  //Mensaje al imprimir en el monitor serie
  Serial.println("Humedad, Temperatura y Luminosidad");
  //Iniciar el sensor
  dht.begin();
}

void loop() {
  while (Serial.available() > 0) { //Ciclo que se ejecutará mientras halla caracteres que se puedan leer en el puerto Serie
    //En la comunicación serial se envían los mensajes caracter a caracter, por lo que tenemos que leerlos 1 a 1
    //Serial.available() indica la canidad de caracteres disponibles. //Este while no se romperá hasta que se halla leido todo.
    Mensaje = Mensaje + Decimal_to_ASCII(Serial.read()); //Se lee el caracter de entrada, se transforma desde ASCII
    //Se acumulan los caracteres en la variable mensaje
  }
  
  
  //Llamar al método para Calcular luminosidad, humedad y temperatura
  Calculos();
  
  //Concatenar el texto enviado en Java y el de los calculos hechos 
  String mensajeCompleto = mensajeCalculo;
  mensajeCompleto.concat(": ");
  mensajeCompleto.concat(Mensaje);
  caracteres = mensajeCompleto.length(); //Se lee la cantidad de caracteres del mensaje que viene desde Java
  int repeticion = caracteres / 16;
  int sub = 0;
  // Desplazamos el texto hacia la izquierda en la segunda fila
  for(int i=0;i<=repeticion;i++)
  {
    String texto = mensajeCompleto.substring(sub,(sub+16));
    Serial.println(texto);
    // Limpiamos pantalla
    lcd.clear();
 
    //Situamos el cursor
    //lcd.setCursor(0,0);
 
    // Escribimos el texto
    lcd.print(texto);
 
    // Esperamos
    delay(velocidad);
    sub = sub + 16;
  }

  //delay(3000); //Se espera un segundo

}

//Metodo para calcular la luminosidad, temperatura y humedad
void Calculos() {
  //Obtener el valor de la luminosidad con la fotoresistencia
  valorLDR = analogRead(A0);
  //Obtener la temperatura y humedad con el DHT11
  humedad = dht.readHumidity();
  temperatura = dht.readTemperature();

  // Validar que se pudo leer el sensor
  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Fallo la lectura del DHT11");
    return;
  }
  //Concatenar los resultados para guardarlos en la variable mensaje
  mensajeCalculo = "H: ";
  mensajeCalculo.concat(humedad);
  mensajeCalculo.concat(" T: ");
  mensajeCalculo.concat(temperatura);
  mensajeCalculo.concat(" L: ");
  mensajeCalculo.concat(valorLDR);
  Serial.print(mensajeCalculo);
  Serial.print("\n");
  delay(1000);
}

//Metodo para convertir los valores ASCII que se mandan de Java
char Decimal_to_ASCII(int entrada) {
  char salida = ' ';
  switch (entrada) {
    case 32:
      salida = ' ';
      break;
    case 33:
      salida = '!';
      break;
    case 34:
      salida = '"';
      break;
    case 35:
      salida = '#';
      break;
    case 36:
      salida = '$';
      break;
    case 37:
      salida = '%';
      break;
    case 38:
      salida = '&';
      break;
    case 39:
      salida = ' ';
      break;
    case 40:
      salida = '(';
      break;
    case 41:
      salida = ')';
      break;
    case 42:
      salida = '*';
      break;
    case 43:
      salida = '+';
      break;
    case 44:
      salida = ',';
      break;
    case 45:
      salida = '-';
      break;
    case 46:
      salida = '.';
      break;
    case 47:
      salida = '/';
      break;
    case 48:
      salida = '0';
      break;
    case 49:
      salida = '1';
      break;
    case 50:
      salida = '2';
      break;
    case 51:
      salida = '3';
      break;
    case 52:
      salida = '4';
      break;
    case 53:
      salida = '5';
      break;
    case 54:
      salida = '6';
      break;
    case 55:
      salida = '7';
      break;
    case 56:
      salida = '8';
      break;
    case 57:
      salida = '9';
      break;
    case 58:
      salida = ':';
      break;
    case 59:
      salida = ';';
      break;
    case 60:
      salida = '<';
      break;
    case 61:
      salida = '=';
      break;
    case 62:
      salida = '>';
      break;
    case 63:
      salida = '?';
      break;
    case 64:
      salida = '@';
      break;
    case 65:
      salida = 'A';
      break;
    case 66:
      salida = 'B';
      break;
    case 67:
      salida = 'C';
      break;
    case 68:
      salida = 'D';
      break;
    case 69:
      salida = 'E';
      break;
    case 70:
      salida = 'F';
      break;
    case 71:
      salida = 'G';
      break;
    case 72:
      salida = 'H';
      break;
    case 73:
      salida = 'I';
      break;
    case 74:
      salida = 'J';
      break;
    case 75:
      salida = 'K';
      break;
    case 76:
      salida = 'L';
      break;
    case 77:
      salida = 'M';
      break;
    case 78:
      salida = 'N';
      break;
    case 79:
      salida = 'O';
      break;
    case 80:
      salida = 'P';
      break;
    case 81:
      salida = 'Q';
      break;
    case 82:
      salida = 'R';
      break;
    case 83:
      salida = 'S';
      break;
    case 84:
      salida = 'T';
      break;
    case 85:
      salida = 'U';
      break;
    case 86:
      salida = 'V';
      break;
    case 87:
      salida = 'W';
      break;
    case 88:
      salida = 'X';
      break;
    case 89:
      salida = 'Y';
      break;
    case 90:
      salida = 'Z';
      break;
    case 91:
      salida = '[';
      break;
    case 92:
      salida = ' ';
      break;
    case 93:
      salida = ']';
      break;
    case 94:
      salida = '^';
      break;
    case 95:
      salida = '_';
      break;
    case 96:
      salida = '`';
      break;
    case 97:
      salida = 'a';
      break;
    case 98:
      salida = 'b';
      break;
    case 99:
      salida = 'c';
      break;
    case 100:
      salida = 'd';
      break;
    case 101:
      salida = 'e';
      break;
    case 102:
      salida = 'f';
      break;
    case 103:
      salida = 'g';
      break;
    case 104:
      salida = 'h';
      break;
    case 105:
      salida = 'i';
      break;
    case 106:
      salida = 'j';
      break;
    case 107:
      salida = 'k';
      break;
    case 108:
      salida = 'l';
      break;
    case 109:
      salida = 'm';
      break;
    case 110:
      salida = 'n';
      break;
    case 111:
      salida = 'o';
      break;
    case 112:
      salida = 'p';
      break;
    case 113:
      salida = 'q';
      break;
    case 114:
      salida = 'r';
      break;
    case 115:
      salida = 's';
      break;
    case 116:
      salida = 't';
      break;
    case 117:
      salida = 'u';
      break;
    case 118:
      salida = 'v';
      break;
    case 119:
      salida = 'w';
      break;
    case 120:
      salida = 'x';
      break;
    case 121:
      salida = 'y';
      break;
    case 122:
      salida = 'z';
      break;
    case 123:
      salida = '{';
      break;
    case 124:
      salida = '|';
      break;
    case 125:
      salida = '}';
      break;
    case 126:
      //salida = '~';
      Mensaje = ""; //Se limpia la variable mensaje. Esto evitará que //se imprima algo en el LCD si no se ha enviado algún mensaje.
      break;
  }
  return salida;
}
