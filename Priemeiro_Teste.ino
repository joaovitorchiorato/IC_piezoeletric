const int inputPin = 22;
const int ledPin = 13;
const int debounceDelay = 50;

// Para a chave e sensor
int sensor1Count = 0;         //Numero de vezes que leu entrada do sensor 1 em alto
int sensor2Count = 0;         //Numero de vezes que leu entrada do sensor 2 em alto
//int sensor3Count = 0;         //Numero de vezes que leu entrada do sensor 3 em alto
//int sensor4Count = 0;         //Numero de vezes que leu entrada do sensor 4 em alto
//
int sensor1Done = 0;         //Quando em 1, sensor 1 foi pisado
int sensor2Done = 0;         //Quando em 1, sensor 2 foi pisado
int k = 0;                   //Variável auxiliar para mudança do "if" da chave para o "if" do sensor
int i = 1;                   //Variável auxiliar para indicação do número do teste
//int sensor3Done = 0;         //Quando em 1, sensor 3 foi pisado
//int sensor4Done = 0;         //Quando em 1, sensor 4 foi pisado
//
long sensor1Time;           //Instante em que sensor 1 foi pisado
long sensor2Time;           //Instante em que sensor 2 foi pisado
//long sensor3Time;           //Instante em que sensor 3 foi pisado
//long sensor4Time;           //Instante em que sensor 4 foi pisado

// Para o sensor
const int sensor1Pin = 10;     //Numero do pino do sensor 1
const int sensor2Pin = 11;     //Numero do pino do sensor 2
//const int sensor3Pin = 12;     //Numero do pino do sensor 3
//const int sensor4Pin = 13;     //Numero do pino do sensor 4
//


// Debounce returns true if the switch is close and stable
boolean debounce (int pin)
{
  boolean state;
  boolean previousState;
  
  previousState = digitalRead (pin);    //store switch state
  for (int counter=0; counter < debounceDelay; counter++)
  {
    delay(1);                  //wait 1ms
    state = digitalRead (pin); //read the pin
    if (state != previousState)
    {
      counter = 0;             //reset counter if state changes
      previousState = state;    // save current state
    }
  }
  //  Here, when switch has been stable longer than debounce period
  return state;
}

void setup() {
  // put your setup code here, to run once:
  pinMode (inputPin, INPUT);
  pinMode (ledPin, OUTPUT);
  pinMode (sensor1Pin, INPUT);
  pinMode (sensor2Pin, INPUT);
//  pinMode (sensor3Pin, INPUT);
//  pinMode (sensor4Pin, INPUT);
  Serial.begin (9600);
}

void loop() {
  while (k == 0){
  if (debounce (inputPin)) {
    digitalWrite (ledPin, HIGH);
  if(ledPin, HIGH){
     Serial.print ("  Início do teste:");
     Serial.print (i);
     Serial.println (); //pula uma linha
  k=1;
  } 
  }
  }
  if (k == 1){
  int sensor1Value = digitalRead(sensor1Pin);
  int sensor2Value = digitalRead(sensor2Pin);
//  int sensor3Value = digitalRead(sensor3Pin);
//  int sensor4Value = digitalRead(sensor4Pin);
  //
  if (sensor1Value == HIGH) {
    sensor1Count++;
  }
  if (sensor2Value == HIGH) {
    sensor2Count++;
  }
//  if (sensor3Value == HIGH) {
//    sensor3Count++;
//  }
//  if (sensor4Value == HIGH) {
//    sensor4Count++;
//  }
  if (sensor1Count > 2 && sensor1Count < 10) {
    sensor1Done = 1;
    sensor1Count = 10;
    sensor1Time = millis();
    Serial.print ("Alvo 1 foi pisado no instante: ");
    Serial.println (sensor1Time);
  }
  if (sensor2Count > 2 && sensor2Count < 10) {
    sensor2Done = 1;
    sensor2Count = 10;
    sensor2Time = millis();
    Serial.print ("Alvo 2 foi pisado no instante: ");
    Serial.println (sensor2Time);
  }
//  if (sensor3Count > 2 && sensor3Count < 10) {
//    sensor3Done = 1;
//    sensor3Count = 10;
//    sensor3Time = millis();
//    Serial.print ("Alvo 3 foi pisado no instante: ");
//    Serial.println (sensor3Time);
//  }
//  if (sensor4Count > 2 && sensor4Count < 10) {
//    sensor4Done = 1;
//    sensor4Count = 10;
//    sensor4Time = millis();
//    Serial.print ("Alvo 4 foi pisado no instante: ");
//    Serial.println (sensor4Time);
//  } 
if (sensor1Done == 1 && sensor2Done == 1) {
  sensor1Count = 0;
  sensor2Count = 0;
  sensor1Done=0;
  sensor2Done=0;
  k=0;
  i=i+1;
//  sensor3Count = 0;
//  sensor4Count = 0;
}
  delay (10);
}
}
