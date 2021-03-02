int analogPin1 = A0; // pino de entrada do 
int analogPin2 = A2;

int val_1 = 0;        // variável para guardar o valor lido
int val_2 = 0;
void setup() {
  Serial.begin(9600);           // configura a porta serial
}

void loop() {
  val_1 = analogRead(analogPin1);  // lê o pino de entrada
  val_2 = analogRead(analogPin2);
  if (val_1 >= 500){
  Serial.println("Linha 1 foi pisada");          // imprime o valor na porta serial
}
 if (val_2 >= 500){
   Serial.println("Linha 2 foi pisada");            // imprime o valor na porta serial
}
}
