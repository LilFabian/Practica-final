/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica final
   Dev: Fabian Andree Sinay Canel
   Fecha: 26 de mayo de 2024
   link de la simulacion: https://www.tinkercad.com/things/fCZfxdTI955-practica-final
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Keypad.h>

#define direccion_lcd 0x27
#define filas 2
#define columnas 16

#define filas_teclado 4
#define columnas_teclado 4
#define f1_teclado A0
#define f2_teclado A1
#define f3_teclado A2
#define f4_teclado A3
#define c1_teclado 2
#define c2_teclado 3
#define c3_teclado 4
#define c4_teclado 5

#define led_1  6          
#define led_2  7  
#define led_3  8          
#define led_4  9 
#define led_5  11          
#define led_6  12 
#define led_7  13
#define pin_servo 10

#define ON(pin)     digitalWrite(pin, HIGH)
#define OFF(pin)    digitalWrite(pin, LOW)

int contador = 0;

char keys[filas_teclado][columnas_teclado] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pines_filas[filas_teclado] = {f1_teclado, f2_teclado, f3_teclado, f4_teclado};
byte pines_columnas[columnas_teclado] = {c1_teclado, c2_teclado, c3_teclado, c4_teclado};

LiquidCrystal_I2C lcd(direccion_lcd, columnas, filas);
Keypad tecladoCerradura = Keypad(makeKeymap(keys), pines_filas, pines_columnas, filas_teclado, columnas_teclado);

Servo Servo1;

void config_outputs(void);
void config_HMI(void);

void setup() {
  Serial.begin(9600);
  Serial.println("Practica final");
  OFF(led_1);
  OFF(led_2);
  OFF(led_3);
  OFF(led_4);
  OFF(led_5);
  OFF(led_6);
  OFF(led_7);

  config_outputs();
  config_HMI();
}

void loop() {
  char key = tecladoCerradura.getKey();

  if (key) {
    switch (key) {
      case '1':
        funcion1();
        break;
      case '2':
        funcion2();
        break;
      case '3':
        funcion3();
        break;
      case '4':
        funcion4();
        break;
      case '5':
        funcion5();
        break;
      default:
        break;
    }
  }
}

void funcion1() {
  for(contador = 0; contador <100; contador ++){
   Serial.println(contador);
    delay(100);
  }
}

void funcion2() {
  for(contador = 99; contador >-1; contador --){
   Serial.println(contador);
    delay(100);
    }
}

void funcion3() {
  int i;
  for(i = 1; i <=5; i++){
  for(contador = 0; contador <8; contador ++){
    if(contador == 1){
     ON(led_1);
    }
    if(contador == 2){
     ON(led_2);
     OFF(led_1);
    }
    if(contador == 3){
     ON(led_3);
     OFF(led_2);
    }
     if(contador == 4){
     ON(led_4);
     OFF(led_3);
    }
    if(contador == 5){
     ON(led_3);
     OFF(led_4);
    }
    if(contador == 6){
     ON(led_2);
     OFF(led_3);
    }
    if(contador == 7){
     ON(led_1);
     OFF(led_2);
    }
    delay(200);
  }
  }
  OFF(led_1);
}

void funcion4() {
  ON(led_1);
  ON(led_5);
  ON(led_6);
  delay(400);
  OFF(led_6);
  OFF(led_1);
  ON(led_7);
  ON(led_2);
  delay(400);
  OFF(led_5);
  OFF(led_7);
  ON(led_4);
  ON(led_3);
  delay(400);
  OFF(led_4);
  ON(led_1);
  delay(400);
  OFF(led_3);
  ON(led_6);
  delay(400);
  OFF(led_2);
  ON(led_6);
  ON(led_5);
  delay(400);
  OFF(led_1);
  OFF(led_5);
  OFF(led_6);
}

void funcion5() {
Servo1.write(180);
 delay(4000);
 Servo1.write(0);
}

void config_outputs(void) {
  pinMode(pin_servo, OUTPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);
  pinMode(led_7, OUTPUT);
}

void config_HMI(void) {
  Servo1.attach(pin_servo);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("Fabian Sinay");
  lcd.setCursor(1, 1);
  lcd.print("Practica final");
}