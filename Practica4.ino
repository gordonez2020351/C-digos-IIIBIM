#include <SPI.h>
#include <MFRC522.h>


//variables
#define pin_RST 9 //pin 9 ardui para pin reset
#define pin_SS 10 //pin 10 ardui para pin SS (SDA)
const int pin_led1 = 2;
const int pin_led2 = 3;
const int pin_buzz = 5;
int diley = 4000;


//Constructor
MFRC522 mi_RFID(pin_SS, pin_RST);


void setup() {
  Serial.begin(9600); // iniciamos monitor serie
  SPI.begin(); //iniciamos bus spi
  mi_RFID.PCD_Init();
  Serial.println("Lectura de UID: ");
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);

}

//codigos de las tarjetas
byte ActualUID[4]; //almacenará el código del Tag leído
byte Usuario1[4] = {0x13, 0x26, 0xCE, 0x1C} ;
byte Usuario2[4] = {0xD3, 0XF0, 0XAE, 0X0D} ;

void loop() {
  // Revisamos si hay nuevas tarjetas  presentes
  if ( mi_RFID.PICC_IsNewCardPresent())
  {
    //Seleccionamos una tarjeta
    if ( mi_RFID.PICC_ReadCardSerial())
    {
      // Enviamos serialemente su UID
      Serial.print("Card UID: ");
      for (byte i = 0; i < mi_RFID.uid.size; i++) {
        Serial.print(mi_RFID.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mi_RFID.uid.uidByte[i], HEX);
        ActualUID[i] = mi_RFID.uid.uidByte[i];
      } //for
      Serial.println();
      //cuando es correcto el usuario
      if (compareArray(ActualUID, Usuario1)) {
        Serial.println("Acceso permitido...");
        digitalWrite(pin_led1, HIGH);
        digitalWrite(pin_led2, LOW);
        tone(pin_buzz, 500, 4000);
        delay(diley);
        digitalWrite(pin_led1, LOW);
        
      }

      else if (compareArray(ActualUID, Usuario2)) {
        Serial.println("Acceso denegado...");
        digitalWrite(pin_led1, LOW);
        digitalWrite(pin_led2, HIGH);      
        tone(pin_buzz, 250, 4000);
        delay(diley);
        digitalWrite(pin_led2, LOW);

        //se termina la lectura
        mi_RFID.PICC_HaltA();
      }//else
    }//2do if
  }//1er if
}//loop


//Función para comparar dos vectores
boolean compareArray(byte array1[], byte array2[])
{
  if (array1[0] != array2[0])return (false);
  if (array1[1] != array2[1])return (false);
  if (array1[2] != array2[2])return (false);
  if (array1[3] != array2[3])return (false);
  return (true);
}
