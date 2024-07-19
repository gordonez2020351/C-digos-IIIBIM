
/*
  Fundación Kinal
  Centro Educativo Técnico Laboral Kinal
  Quinto Perito
  Quinto Electronica
  Codigo Técnico: EB5AM
  Curso: Taller de Electrónica Digital y Reparación de Computadoras
  Proyecto: Práctica 2 - Parte 1
  Dev: Gabriel José María Ordoñez Rubí
  Fecha: 19 de Julio
*/


#include <Wire.h>
#include <SparkFun_ADXL345.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>

ADXL345 aceleMache = ADXL345();
int valorX, valorY, valorZ;
float sumaCuadrados, resX, resY, resZ, resultado;
float medida;

SoftwareSerial dfPlayerSerial(10, 11); // RX, TX
DFRobotDFPlayerMini reprodu;

void configuracion() {
  Serial.begin(9600);

  aceleMache.powerOn();
  aceleMache.setRangeSetting(2);

  dfPlayerSerial.begin(9600);
  reprodu.begin(dfPlayerSerial);
  reprodu.volume(25);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
}


void setup() {
  configuracion();
}

void loop() {
  aceleMache.readAccel(&valorX, &valorY, &valorZ);
  resX = valorX * 0.04;
  resY = valorY * 0.04;
  resZ = valorZ * 0.04;
  sumaCuadrados = ((resX * resX) + (resY * resY) + (resZ * resZ));

  resultado = sqrt(sumaCuadrados);

  medida = map(resultado, 8, 25.70, 0, 10);

  if (medida == 1) {
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
  }

  if (medida == 2) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }

  if (medida == 3) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }

  if (medida == 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }

  if (medida == 5) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }

  if (medida == 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);

    reprodu.play(1);
    delay(3000);

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    reprodu.pause();
  }

  if (medida == 7) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);

    reprodu.play(1);
    delay(3000);

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    reprodu.pause();
  }

  if (medida == 8) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(12, HIGH);

    reprodu.play(1);
    delay(3000);

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
    reprodu.pause();
  }

  if (medida == 9) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(12, HIGH);

    reprodu.play(1);
    delay(3000);

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
    reprodu.pause();
  }

  if (medida == 10) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(12, HIGH);

    reprodu.play(1);
    delay(5000);

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
    reprodu.pause();
  }
}
