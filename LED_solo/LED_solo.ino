void setup() {
  // inicializacion del pin donde este conectado el LED como salida
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);   // El LED se enciende
  delay(1000);                       // espera en segundos
  digitalWrite(13, LOW);    // El LED se apaga
  delay(1000);                       // espera en segundos
}
