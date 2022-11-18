// Declaração dos pinos
const int pinoLEDR = 11;
const int pinoLEDG = 10;
const int pinoLEDB = 9;
const int pinoBotaoR = 7;
const int pinoBotaoG = 6;
const int pinoBotaoB = 5;
const int pinoBotaoA = 4; // botao de ajuste
const int pinoPotenciometro = A0; // potenciometro de intensidade

// Variáveis para armazenar o estado de cada botão
int leituraBotaoR;
int leituraBotaoG;
int leituraBotaoB;
int leituraBotaoA;
int leituraPotenciometro;
int pwmR = 255;
int pwmG = 255;
int pwmB = 255;

void setup() {
  // Configura os pinos
  pinMode(pinoLEDR,OUTPUT);
  pinMode(pinoLEDG,OUTPUT);
  pinMode(pinoLEDB,OUTPUT);
  pinMode(pinoBotaoR,INPUT_PULLUP);
  pinMode(pinoBotaoG,INPUT_PULLUP);
  pinMode(pinoBotaoB,INPUT_PULLUP);
  pinMode(pinoBotaoA,INPUT_PULLUP);
  pinMode(pinoPotenciometro,INPUT);
}

void loop() {
  // le estado dos botões e do potenciometro
  leituraBotaoR = digitalRead(pinoBotaoR);
  leituraBotaoG = digitalRead(pinoBotaoG);
  leituraBotaoB = digitalRead(pinoBotaoB);
  leituraBotaoA = digitalRead(pinoBotaoA);
  leituraPotenciometro = analogRead(pinoPotenciometro);

  if(leituraBotaoR == LOW) { // verifica se o botão foi pressionado
    // Se o botao de ajuste estiver pressionado
    if (leituraBotaoA == LOW) {
      // ajusta a intensidade da cor de acordo com o potenciometro
      pwmR = map(leituraPotenciometro, 0, 1023, 0, 255);
    }
    // aciona a cor com a intensidade configurada
    analogWrite(pinoLEDR, pwmR);
  }else { // senão
    analogWrite(pinoLEDR, 0); // apaga o LED
  }
  
  if(leituraBotaoG == LOW) {  // verifica se o botão foi pressionado
    // Se o botao de ajuste estiver pressionado
    if (leituraBotaoA == LOW) {
      // ajusta a intensidade da cor de acordo com o potenciometro
      pwmG = map(leituraPotenciometro, 0, 1023, 0, 255);
    }
    // aciona a cor com a intensidade configurada
    analogWrite(pinoLEDG, pwmG);
  }else { // senão
    analogWrite(pinoLEDG, 0); // apaga o LED
  }
  
  if(leituraBotaoB == LOW) {  // verifica se o botão foi pressionado
    // Se o botao de ajuste estiver pressionado
    if (leituraBotaoA == LOW) {
      // ajusta a intensidade da cor de acordo com o potenciometro
      pwmB = map(leituraPotenciometro, 0, 1023, 0, 255);
    }
    // aciona a cor com a intensidade configurada
    analogWrite(pinoLEDB, pwmB);
  }else { // senão
    analogWrite(pinoLEDB, 0); // apaga o LED
  }
  
  delay(100); // aguarda 100 milissegundos para uma nova leitura
}