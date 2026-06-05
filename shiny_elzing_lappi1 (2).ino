#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trig = 2;
const int echo = 3;

long duracion;
float distancia;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Velocimetro");
  lcd.setCursor(0,1);
  lcd.print("Iniciando...");
  delay(2000);

  lcd.clear();
  
  Serial.begin(9600);
  
}

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  duracion = pulseIn(echo, HIGH);

  distancia = duracion * 0.0343 / 2;

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Distancia:");

  lcd.setCursor(0,1);
  lcd.print(distancia, 1);
  lcd.print(" cm");
  
  Serial.print(distancia);

  delay(200);
}