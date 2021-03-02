// Boa parte do programa será feito com 2 laços de repetição, 1 para a linha e outro para a coluna, necessário quando o programa estiver testando todos os sensores

// Para a chave e sensor
// Número de vezes que uma linha ou coluna foram lidas em alto
int lineCount[2] = {0,0}; 
int columnCount[2] = {0,0};


// Colunas e linhas que foram pisadas
int Done[4] = {0,0,0,0};     //Vetor com o valor lógico de cada sensor


// Valores assumidos por uma linha ou coluna;
int lineValue[2];
int columnValue[2];


// Variáveis auxiliares
int k = 0;                //Variável auxiliar para mudança do "if" da chave para o "if" do sensor
int i = 1;               //Variável auxiliar para indicação do número do teste
int x;                  //Variável auxiliar para o laço de repetição
int y= 0;                 // Variável auxiliar para finalizar um teste e começar outro
//
long Time[4];     //Vetor com o valor do tempo de cada sensor


// Para o sensor
const int linePin[2]= {2,3};     //Vetor com os pinos de cada linha
const int columnPin[2]= {4,5};  //Vetor com os pinos de cada coluna
//




void setup() {
  // put your setup code here, to run once:
 for (x = 0; x <= 2; x = x+1){         
  pinMode (linePin[x], INPUT);
  pinMode (columnPin[x], INPUT);
 }
  Serial.begin (9600);
}




void loop() {

//Print incial
  if (k == 0){
     Serial.print ("  Início do teste:");
     Serial.print (i);
     Serial.println (); //pula uma linha
  k=1;
  } 



//Verificação das linhas e colunas
  if (k == 1){
    
  for (x = 0; x <= 2; x = x+1){         
  lineValue[x] = digitalRead(linePin[x]);
  columnValue[x] = digitalRead(columnPin[x]);
}

           
    for (x = 0; x <= 2; x = x+1){         
        if (lineValue[1] == HIGH && columnValue[x] == HIGH){
          lineCount[1]++;
          columnCount[x]++;
        }
        if (lineCount[1] > 2 && lineCount[1] < 10 && columnCount[x] > 2 && columnCount[x] < 10){
          Time[x] = millis();
          Done[x] = 1;
          Serial.print ("Alvo "); 
          Serial.print (x+1);
          Serial.print (" foi pisado no instante: ");
          Serial.println (Time[x]);
        }
        if (lineValue[2] == HIGH && columnValue[x] == HIGH){
          lineCount[2]++;
          columnCount[x]++;
        }
        if (lineCount[2] > 2 && lineCount[2] < 10 && columnCount[x] > 2 && columnCount[x] < 10){
          Time[x+2] = millis();
          Done[x+2] = 1;
          Serial.print ("Alvo ");
          Serial.print (x+3); 
          Serial.print (" foi pisado no instante: ");
          Serial.println (Time[x+2]); 
        } 
    }


    // Para iniciar um novo teste uma soma dos valores do vetor Done[4] será feita, se der 4 quer dizer que todos os sensores foram pisados e outro teste iniciará.
    for (x = 0; x <= 4; x = x+1){
      y = Done[x] + y;
    }
    if (y == 4){
     Done[4] = (0,0,0,0);
    for (x = 0; x <= 2; x = x+1) {
     lineCount[x] = 0; 
     columnCount[x] = 0;
    }
     k=0; 
     i=i+1;
    }
    y=0;
 
  delay (10);
}
}
