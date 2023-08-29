const int trigPin = 2;  // Pino de saída para o trigger do sensor
const int echoPin = 3;  // Pino de entrada para o eco do sensor

void setup() {
  Serial.begin(9600);  // Inicializa a comunicação serial
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Gera um pulso no pino TRIG
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Mede o tempo que o eco leva para voltar
  long duration = pulseIn(echoPin, HIGH);
  
  // Calcula a distância com base na velocidade do som (aproximadamente 343 m/s)
  float distance = duration * 0.0343 / 2;
  
  // Exibe a distância no monitor serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(1000);  // Aguarda 1 segundo antes da próxima leitura
}