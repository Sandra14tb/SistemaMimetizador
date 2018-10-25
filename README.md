# Practica 3 Sistema Mimetizador

**INSTITUTO TECNOLOGICO DE LEÓN.**


	Integrantes:
				- Godinez Guerrero Sandra Luz.
				- Santos Salas Abril Alejandra.
				- Espinoza Amaro Maria de los Angeles.
				
        
	Sistemas Programables.
				-Ing. Carlos Rafael Levy Rojas.
				

Practica 3 Sistema Mimetizador

Realice un sistema de despliegue de mensajes en una pantalla LCD, 
el objetivo es que al llegar el individuo puedas ver un pequeño tablero electronico con una serie de mensajes o notas almacenados.

	Cada mensaje tiene las siguientes caracterisiticas 
		* Tienes que mostrar el mensaje que se entienda, con solo 140 caracteres de espacio.
		*Debe de mostrar fecha y hora en la que fue emitido el mensaje.
		*Además debe de mostrar un mensaje del estdo del tiempo (temperatura, luminocidad, humedad). 
    
    
El sistema debe de contener; 
		*Una interfaz de Hardware para navegar entre los mensajes. 
		*Una interfaz de software para enviar los mensajes desde la computadora via serial.
		*La interfaz de software debe permitir agregar mensajes y/ó borrarlos.
		
**Proposito.**

	El proposito educativo a denotar en esta practica es el uso de la comunicacion serial entre arduino y un lenguaje de programacion,
	en este caso se utilizo java con ayuda de Netbeans.
	
**Entorno.**

	Para el desarrollo de esta practica se utilizo el sistema operativo Elementary OS 0.4.14, complementandose con windows 10, 
	con apoyo de IDE ARDUINO, Fritzing 0.9.1 para la simulacion del circuito, Netbeans para el envio de mensajes con Java.
	
**Materiales usados.**

	_Arduino UNO 
	-Cable USB 
	-Placa de prototipado o protoboard 
	-Cables
	-LCD 16x2
	-Potencimetro 10K
	-Sensor DHT11
	-Fotoresistencia
	-2 Resistencias de 220O y 10KO 
	
	
**Procedimiento.**
Para realizar dicho proyecto se investigaron algunas librerias que nos permitieran la comunicación via serial entre arduino y Java, dicha libreria no forma parte como creacion propia de Java, es una implementacion de "PANAMA SERVICE". De igual forma en Arduino se implementan las librerias que nos permiten medir la temperatura, humedad, luminosidad etc.


**Interfaz de Java**
![Diseño en Java](https://github.com/Sandra14tb/SistemaMimetizador/blob/master/InterfazJava.JPG?raw=true)

**Simulado**
![Simulado realizado en fritzing](https://github.com/Sandra14tb/SistemaMimetizador/blob/master/Simulado.jpg?raw=true)

**Diagrama de Esquema**
![Esquema obtenido en fritzing](https://github.com/Sandra14tb/SistemaMimetizador/blob/master/practica3_esquema.jpg?raw=true)

**Esquema Fisico Arduino 1**
![Esquema Físico](https://github.com/Sandra14tb/SistemaMimetizador/blob/master/arduino.jpeg?raw=true)

**Esquema Fisico Arduino 1.1**
![Esquema Físico](https://github.com/Sandra14tb/SistemaMimetizador/blob/master/1.jpeg?raw=true)


**Esquema Fisico Arduino 1.1.2**
![Esquema Físico](https://github.com/Sandra14tb/SistemaMimetizador/blob/master/2.jpeg?raw=true)


**Esquema Fisico Arduino 1.1.3**
![Esquema Físico](https://github.com/Sandra14tb/SistemaMimetizador/blob/master/3.jpeg?raw=true)

**Esquema Fisico Arduino 1.1.4**
![Esquema Físico](https://github.com/Sandra14tb/SistemaMimetizador/blob/master/4.jpeg?raw=true)

**Esquema Fisico Arduino 1.1.5**
![Esquema Físico](https://github.com/Sandra14tb/SistemaMimetizador/blob/master/5.jpeg?raw=true)

**A continuación se presenta una sustracción de código el cual delimita los caracteres permitidos  que se establecen como requerimientos.**


private void txtMensajeKeyPressed(java.awt.event.KeyEvent evt) {                                      
        // Limitar el numero de caracteres a 140
        if (txtMensaje.getText().length() + 1 > limite) {
                    txtMensaje.setEditable(false);
                } else {
                    txtMensaje.setEditable(true);
                }
            
    }


