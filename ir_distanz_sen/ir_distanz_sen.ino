#include <Wire.h>                                  // Die Datei Wire.h ist eine Programmbibliothek, um über einen I²C-Bus zu kommunizieren.
#define adresse 0x0C                               // Das Wort "adresse" bedeutet später "0x0C".
                                                   // Nebenbei: Halbe Adresse vom NXT: 24 beim Arduino entspricht 18 im Hexadezimalcode. Die Hälfte davon ist 12, also 0C beim NXT.
int einlesen;
int lese_Daten;
byte daten[10];                                     // Es handelt sich um ein Array mit 2 Bytes. Ein Byte hat Werte von 0 bis 255.

int ir_sen_wert;

void Daten_erhalten(int bytesErhalten)             // Methode zum Empfangen
{
  einlesen = bytesErhalten;                        // ***
  while(1 < Wire.available())                      // *** loop through all but the last
  {                                                // ***
  }                                                // ***
  lese_Daten = Wire.read();                        // Die Daten vom NXT werden gelesen.
  Serial.println(lese_Daten);                      // Die Daten werden am serielle Monitor angezeigt.
}

void Daten_senden()                                // Methode zum Senden
{
  if(lese_Daten == 0x00)                           // Wenn eine "0" vom NXT empfangen wurde, dann sende die Daten
  {
    daten[0] = 77;
    Wire.write(daten,1);                           // Sende die Werte über den I²C-Bus zum NXT.
  }
}

void setup()
{
  Serial.begin(115200);                            // Die Kommunikationsadresse mit dem seriellen Monitor
  
  Wire.begin(adresse);                             // Die Kommunikationsadresse vom NXT
  Wire.onReceive(Daten_erhalten);                  // Die Methode zum Empfangen wird gestartet und dauerhaft ausgeführt.
  Wire.onRequest(Daten_senden);                    // Die Methode zum Senden wird gestartet und dauerhaft ausgeführt.
}


void loop()
{
  ir_sen_wert = analogRead(A0);
  Serial.print(ir_sen_wert);
  Serial.println();
  delay(100);
}
