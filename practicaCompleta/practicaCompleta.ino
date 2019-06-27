//PRACTICA: Que el LED y el RELAY se enciendan cuando la temperatura sea mayor a la variable definida.

//Declaramos la libreria de control de sensores DHT
#include <DHT.h>

//Definimos el pin del LED
#define LED 13
// Definimos el pin digital donde se conecta el sensor
#define DHTPIN 2
// Definimos el tipo de sensor
//#define DHTTYPE DHT11   // Descomentar si se usa el DHT 11
#define DHTTYPE DHT22   // Sensor DHT22
// Definimos el pin del relay
#define control 3

// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Inicializamos comunicación serie
  Serial.begin(9600);
  Serial.println("Iniciando...");
  //Definimos el pin del LED como salida
  pinMode(LED, OUTPUT);

  // Inicializamos el sensor DHT
  dht.begin();
  // Inicializamos el RELAY
  pinMode(control,  OUTPUT) ;
}

void loop() {
  delay(5000);  // Esperamos 5 segundos entre lecturas

  float h = dht.readHumidity(); //Leemos la Humedad
  float t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
  float f = dht.readTemperature(true); //Leemos la temperatura en grados Fahrenheit
  
  //Si la temperatura leida es mayor a 30 grados centigrados encedemos el led, sino lo apagamos
  if (t > 30)
  {
    digitalWrite(LED, HIGH);
    digitalWrite(control, LOW); //El RELAY se enciende en bajo
  } else {
    digitalWrite(LED, LOW);
    digitalWrite(control, HIGH);
  }
  
  //Enviamos las lecturas por el puerto serial
  Serial.print("Humedad ");
  Serial.print(h);
  Serial.print(" %t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.println(" *F");
}
