const int mqAO = A0;      // Pin analógico para la salida analógica del sensor MQ-4
const int mqDO = 2;       // Pin digital para la salida digital del sensor MQ-4
const int buzzerPin = 9;  // Pin digital para el zumbador
const int fanPin = 3;     // Pin digital para el control del ventilador

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(mqDO, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorAnalogValue = analogRead(mqAO);
  int sensorDigitalValue = digitalRead(mqDO);

  Serial.print("Analog: ");
  Serial.print(sensorAnalogValue);
  Serial.print(" | Digital: ");
  Serial.println(sensorDigitalValue);

  // Ajusta estos valores según la calibración de tu sensor y el comportamiento deseado
  int umbralDigital = HIGH; // Ajusta según la salida digital del sensor
  int umbralNivel10 = 315;  // Ajusta según la calibración de tu sensor
  int umbralNivel9 = 290;   // Ajusta según la calibración de tu sensor
  int umbralNivel8 = 265;   // Ajusta según la calibración de tu sensor
  int umbralNivel7 = 240;   // Ajusta según la calibración de tu sensor
  int umbralNivel6 = 215;   // Ajusta según la calibración de tu sensor
  int umbralNivel5 = 190;   // Ajusta según la calibración de tu sensor
  int umbralNivel4 = 165;   // Ajusta según la calibración de tu sensor
  int umbralNivel3 = 140;   // Ajusta según la calibración de tu sensor
  int umbralNivel2 = 115;   // Ajusta según la calibración de tu sensor
  int umbralNivel1 = 110;   // Ajusta según la calibración de tu sensor

  int fanSpeed = 0; // Velocidad inicial del ventilador

  if (sensorAnalogValue > umbralNivel10 || sensorDigitalValue == umbralDigital) {
    fanSpeed = 255; // Velocidad máxima
    tone(buzzerPin, 100);
    Serial.println("Gas detectado - Nivel 10");
  } else if (sensorAnalogValue > umbralNivel9) {
    fanSpeed = 200; // Velocidad alta
    tone(buzzerPin, 90);
    Serial.println("Gas detectado - Nivel 9");
  } else if (sensorAnalogValue > umbralNivel8) {
    fanSpeed = 150; // Velocidad media
    tone(buzzerPin, 80);
    Serial.println("Gas detectado - Nivel 8");
  } else if (sensorAnalogValue > umbralNivel7) {
    fanSpeed = 100; // Velocidad baja
    tone(buzzerPin, 70);
    Serial.println("Gas detectado - Nivel 7");
  } else if (sensorAnalogValue > umbralNivel6) {
    fanSpeed = 50; // Velocidad mínima
    tone(buzzerPin, 60);
    Serial.println("Gas detectado - Nivel 6");
  } else if (sensorAnalogValue > umbralNivel5) {
    fanSpeed = 30; // Velocidad mínima
    tone(buzzerPin, 50);
    Serial.println("Gas detectado - Nivel 5");
  } else if (sensorAnalogValue > umbralNivel4) {
    fanSpeed = 20; // Velocidad mínima
    tone(buzzerPin, 40);
    Serial.println("Gas detectado - Nivel 4");
  } else if (sensorAnalogValue > umbralNivel3) {
    fanSpeed = 10; // Velocidad mínima
    tone(buzzerPin, 30);
    Serial.println("Gas detectado - Nivel 3");
  } else if (sensorAnalogValue > umbralNivel2) {
    fanSpeed = 5; // Velocidad mínima
    tone(buzzerPin, 20);
    Serial.println("Gas detectado - Nivel 2");
  } else if (sensorAnalogValue > umbralNivel1) {
    fanSpeed = 2; // Velocidad mínima
    tone(buzzerPin, 10);
    Serial.println("Gas detectado - Nivel 1");
  } else {
    noTone(buzzerPin);
    Serial.println("No hay gas detectado");
  }

  analogWrite(fanPin, fanSpeed); // Controla la velocidad del ventilador
  delay(1000);
}
