/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Parte 2 Practica 3
   Dev: Profe. Alejandro Lopez Navas
   Fecha: 18 de Julio.
*/


#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Directivas del preprocesador
#define widht_oled    128       //128 pixeles de ancho 
#define height_oled   64        //64 pixeles de alto
#define pot_pin       A0

//Constructores
Adafruit_SSD1306 MacheOled(widht_oled, height_oled, &Wire, -1);

//Variables
unsigned int adc_valor;



void setup() {
  Serial.begin(9600);  //Inicio la comunicación serial
  delay(100);          //pausa de 100 milisegundos
  Serial.println("Uso de la pantalla oled - practica 3 parte 2");
  pinMode(A0, INPUT);

//inicio de la comunicacion OLED
  if(!MacheOled.begin(SSD1306_SWITCHCAPVCC, 0x3C))
 {
  Serial.println("No puedo comunicarme con la pantalla oled");
  Serial.println("Favor de revisar conexiones o alimentacion");
  while(1);   //Ciclo infinito

  MacheOled.setTextSize(4);
 //Defino el color del texto a imprimir (la pantalla es monocromatica)
 MacheOled.setTextColor(SSD1306_WHITE);
 //Coloco el cursor en una posicion especifica
 MacheOled.setCursor(0, 0);
 //Imprimo la cadena de texto
 MacheOled.println("Alejandro Navas");
 MacheOled.display();


}
}
void loop() {
   MacheOled.setTextSize(1);
 //Defino el color del texto a imprimir (la pantalla es monocromatica)
 MacheOled.setTextColor(SSD1306_WHITE);
 //Coloco el cursor en una posicion especifica
 MacheOled.setCursor(0, 0);
 //Imprimo la cadena de texto
 MacheOled.println("Valor del ADC");
 //Muestro en pantalla la cadena 
 MacheOled.display();
  adc_valor = analogRead(A0);       //leo el valor del canal 0 del ADC
  Serial.print("El valor del ADC es de: ");
  Serial.println(adc_valor);
  MacheOled.setTextSize(3);
  MacheOled.setTextColor(SSD1306_WHITE);
  MacheOled.setCursor(0,12);
  MacheOled.println(adc_valor);
  MacheOled.display();
  delay(150);
  MacheOled.clearDisplay();

}
