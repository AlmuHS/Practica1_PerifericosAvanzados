// Conexión del pulsador
long tiempo = 0;
long cuenta = 0;

const int LDR = A0;
const int MAX_LUZ = 900;
const int MIN_LUZ = 800;


void setup() {

  // Inicialización del RS232
  Serial.begin(9600);

  // Definición del LDR
  pinMode(LDR, INPUT);

}

void loop() {
  char cadena[20];
  int rebote;
  int luz = analogRead(LDR);
  
  Serial.println(luz);
  
  // Espera hasta que se corte el foco de luz
  while (luz >= MAX_LUZ){
    luz = analogRead(LDR);
    delay(100); // Se realiza una pequeña espera antes de repetir la lectura
  }
  
  // Incrementa el contador
  cuenta++;
  tiempo = millis();
  
  // Se genera la cadena a enviar
  snprintf(cadena, 20, "Cuenta: %d; Tiempo: %lu", cuenta, tiempo);
  Serial.println(cadena);

  // Espera a que se estabilice el valor
  rebote = millis();
  while(millis() - rebote < 20);
  
  // Se espera a que vuelva a subir la luz
  while(luz <= MIN_LUZ){
    luz = analogRead(LDR);
    delay(100); // Se realiza una pequeña espera antes de repetir la lectura
  }
}
