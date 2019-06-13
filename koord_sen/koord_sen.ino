const int xpin = A1;                    // Port x-Achse
const int ypin = A2;                    // Port y-Achse
const int zpin = A3;                    // Port z-Achse

int offset_start;                       // Wenn Taste S7 gedrückt wird, geht die Messung des Offsets los.
int offset_x;                           // Der Offset ist ein Wert, der von den gemessenen abgezogen werden sollte, um Veränderungen besser zu sehen.
int offset_y;
int offset_z;

int x_wert;                             // x-Achsen-Werte
int y_wert;                             // y-Achsen-Werte
int z_wert;                             // z-Achsen-Werte


void setup()
{
  Serial.begin(9600);    
  offset_x = analogRead(xpin);        // Die Offsets werden gemessen.
  offset_y = analogRead(ypin);
  offset_z = analogRead(zpin);
}


void loop()
{
  x_wert = analogRead(xpin)-offset_x;
  y_wert = analogRead(ypin)-offset_y;
  z_wert = analogRead(zpin)-offset_z;

  Serial.print(digitalRead(3));             // Die Funktion des Tasters wird mit angezeigt.
  Serial.print(" ");                        // Alles folgende ist nur zur Anzeige der Werte.
  Serial.print(x_wert);  
  Serial.print(" ");
  Serial.print(y_wert);  
  Serial.print(" ");
  Serial.print(z_wert);  
  Serial.print(" ");
  Serial.println();
  delay(30);
}






