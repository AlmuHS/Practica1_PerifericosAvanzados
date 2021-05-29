// Conexión del pulsador
long tiempo = 0;
long cuenta = 0;

const int LDR = A0;
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
  
  // Espera hasta que se corte el foco de luz
  while (analogRead(LDR) >= MAX_LUZ);
  
  // Incrementa el contador
  cuenta++;
  tiempo = millis();
  
  // Se genera la cadena a enviar
  sprintf(cadena, "Cuenta: %d; Tiempo: %lu", cuenta, tiempo);
  Serial.println(cadena);

  // Espera a que se estabilice el valor
  rebote = millis();
  while(millis()-rebote < 20);
  
  // Se espera a que vuelva a subir la luz
  while(digitalRead(LDR) < MAX_LUZ);

}
