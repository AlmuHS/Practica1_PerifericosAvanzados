// Conexión del pulsador
long tiempo = 0;
long cuenta = 0;

const int LDR = A5;
const int MAX_LUZ = 950;


void setup() {

  // Inicialización del RS232
  Serial.begin(9600);
  // Definición del pulsador
  pinMode(LDR, INPUT);

}

void loop() {
  char cadena[50];
  int rebote;

  Serial.println(analogRead(LDR));
  // Espera hasta que el pulsador vale HIGH
  while (analogRead(LDR) < MAX_LUZ);
  // Incrementa el contador
  cuenta++;
  tiempo = millis();

  
  
  // Se genera la cadena a enviar
  sprintf(cadena, "Cuenta: %d; Tiempo: %lu", cuenta, tiempo);
  Serial.println(cadena);

  rebote = millis();
  while(millis()-rebote < 20);
  // Se espera a que se suelte el pulsador
  while(digitalRead(LDR) >= MAX_LUZ);

}
