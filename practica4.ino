#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Dirección I2C del LCD
#define LCD_ADDR 0x27

// Número de columnas y filas del LCD
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Inicializa el objeto LCD
LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLUMNS, LCD_ROWS);

// Texto a mostrar

void setup() {
  // Inicializa la comunicación I2C
  Wire.begin();
  lcd.backlight();
  // Inicializa el LCD
  lcd.begin(LCD_COLUMNS, LCD_ROWS);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hola mundo");
  delay(200);
  //desplazar a der
  for(int i = 0; i < LCD_COLUMNS - 1; i++) {
    lcd.scrollDisplayRight();
    delay(200);
  }
  //regresar al normal
  delay(500);
  for(int i = 0; i < LCD_COLUMNS-1; i++) {
    lcd.scrollDisplayLeft();
    delay(200);
  }
  delay(500);
  //desplazar a izq
  for(int i = 0; i < LCD_COLUMNS - 7; i++) {
    lcd.scrollDisplayLeft();
    delay(200);
  }
  //regresar al normal
  delay(500);
  for(int i = 0; i < LCD_COLUMNS-7; i++) {
    lcd.scrollDisplayRight();
    delay(200);
  }
  lcd.setCursor(0,1);
  char arreglo[22] = "Lenguajes de interfaz";
  String cadena = "Lenguajes de interfaz";
  for(int i = 0; i<6; i++) {
    lcd.setCursor(0,0);
    lcd.print("Hola mundo");
    lcd.setCursor(0,1);
    lcd.print(cadena.substring(i, cadena.length()));
    delay(500);
    lcd.clear();
  }
  for(int i = 5; i>=0; i--) {
    lcd.setCursor(0,0);
    lcd.print("Hola mundo");
    lcd.setCursor(0,1);
    lcd.print(cadena.substring(i, cadena.length()));
    delay(500);
  }
  delay(2000);
}
