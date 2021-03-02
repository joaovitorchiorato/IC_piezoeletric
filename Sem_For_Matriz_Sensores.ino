// Para a chave e sensor
int sensor1Count = 0;         //Numero de vezes que leu entrada do sensor 1 em alto
int sensor2Count = 0;         //Numero de vezes que leu entrada do sensor 2 em alto
int sensor3Count = 0;         //Numero de vezes que leu entrada do sensor 3 em alto
int sensor4Count = 0;         //Numero de vezes que leu entrada do sensor 4 em alto
//
int sensor1Done = 0;         //Quando em 1, sensor 1 foi pisado
int sensor2Done = 0;         //Quando em 1, sensor 2 foi pisado
int sensor3Done = 0;         //Quando em 1, sensor 3 foi pisado
int sensor4Done = 0;         //Quando em 1, sensor 4 foi pisado
int k = 0;                   //Variável auxiliar para mudança do "if" da chave para o "if" do sensor
int i = 1;                   //Variável auxiliar para indicação do número do teste
//
long sensor1Time;           //Instante em que sensor 1 foi pisado
long sensor2Time;           //Instante em que sensor 2 foi pisado
long sensor3Time;           //Instante em que sensor 3 foi pisado
long sensor4Time;           //Instante em que sensor 4 foi pisado

// Para o sensor
const int sensor1Pin = 2;     //Numero do pino do sensor 1
const int sensor2Pin = 3;     //Numero do pino do sensor 2
const int sensor3Pin = 4;     //Numero do pino do sensor 3
const int sensor4Pin = 5;     //Numero do pino do sensor 4
//


void setup() {
  // put your setup code here, to run once:
  pinMode (sensor1Pin, INPUT);
  pinMode (sensor2Pin, INPUT);
  pinMode (sensor3Pin, INPUT);
  pinMode (sensor4Pin, INPUT);
  Serial.begin (9600);
}

void loop() {

  if (k == 0){
     Serial.print ("  Início do teste:");
     Serial.print (i);
     Serial.println (); //pula uma linha
  k=1;
  } 


  if (k == 1){
   int sensor1Value = digitalRead(sensor1Pin);
   int sensor2Value = digitalRead(sensor2Pin);
   int sensor3Value = digitalRead(sensor3Pin);
   int sensor4Value = digitalRead(sensor4Pin);
  //
  if (sensor1Value == HIGH) {
    sensor1Time = millis();
    Serial.print ("Alvo 1 foi pisado no instante: ");
    Serial.println (sensor1Time);
  }
  if (sensor2Value == HIGH) {
    sensor2Time = millis();
    Serial.print ("Alvo 2 foi pisado no instante: ");
    Serial.println (sensor2Time);   
   
  }
  if (sensor3Value == HIGH) {
     sensor3Time = millis();
     Serial.print ("Alvo 3 foi pisado no instante: ");
     Serial.println (sensor3Time);
     
   }
  if (sensor4Value == HIGH) {
     sensor4Time = millis();
     Serial.print ("Alvo 4 foi pisado no instante: ");
     Serial.println (sensor4Time);
  }
 


  delay (10);
}
}
