int analogPin1 = A0; // pino de entrada do 
int analogPin2 = A1;
int analogPin3 = A2;
int analogPin4 = A3;   
                
int val_1 = 0;        // variável para guardar o valor lido
int val_2 = 0;
int val_3 = 0;
int val_4 = 0;

void setup() {
  Serial.begin(9600);           // configura a porta serial
}

void loop() {
  val_1 = analogRead(analogPin1);  // lê o pino de entrada
  val_2 = analogRead(analogPin2);
  val_3 = analogRead(analogPin3);
  val_4 = analogRead(analogPin4);
  
  if (val_1 >= 500){
  Serial.println("Linha 1 foi pisada");          // imprime o valor na porta serial
}
 if (val_2 >= 500){
   Serial.println("Linha 2 foi pisada");            // imprime o valor na porta serial
}
 if (val_3 >= 500){
  Serial.println("Coluna 1 foi piasada");          // imprime o valor na porta serial
}
 if (val_4 >= 500){
  Serial.println("Coluna 2 foi piasada");          // imprime o valor na porta serial
}
}
