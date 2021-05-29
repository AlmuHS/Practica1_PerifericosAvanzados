// Conexión del pulsador
int pulsador = 6;
long tiempo = 0;
long cuenta = 0;

void setup() {

  // Inicialización del RS232
  Serial.begin(9600);
  // Definición del pulsador
  pinMode(pulsador, INPUT);

}

void loop() {
  char cadena[50];
  int rebote;
  // Espera hasta que el pulsador vale HIGH
  while (digitalRead(pulsador) == LOW);
  // Incrementa el contador
  cuenta++;
  tiempo = millis();
  
  // Se genera la cadena a enviar
  sprintf(cadena, "Cuenta: %d; Tiempo: %lu", cuenta, tiempo);
  Serial.println(cadena);

  rebote = millis();
  while(millis()-rebote < 20);
  // Se espera a que se suelte el pulsador
  while(digitalRead(pulsador) == HIGH);

}
