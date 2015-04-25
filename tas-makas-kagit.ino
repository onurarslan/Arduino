#define OYUNCU1_LED 6
#define OYUNCU2_LED 5

#define OYUNCU1_TAS 9
#define OYUNCU1_MAKAS 8
#define OYUNCU1_KAGIT 7

#define OYUNCU2_TAS 4
#define OYUNCU2_MAKAS 3
#define OYUNCU2_KAGIT 2

void setup(){
  pinMode(OYUNCU1_LED, OUTPUT);
  pinMode(OYUNCU2_LED, OUTPUT);

  pinMode(OYUNCU1_TAS, INPUT_PULLUP);
  pinMode(OYUNCU1_MAKAS, INPUT_PULLUP);
  pinMode(OYUNCU1_KAGIT, INPUT_PULLUP);

  pinMode(OYUNCU2_TAS, INPUT_PULLUP);
  pinMode(OYUNCU2_MAKAS, INPUT_PULLUP);
  pinMode(OYUNCU2_KAGIT, INPUT_PULLUP);
}

void loop(){
  int butonO1_TAS=digitalRead(OYUNCU1_TAS);
  int butonO1_MAKAS=digitalRead(OYUNCU1_MAKAS);
  int butonO1_KAGIT=digitalRead(OYUNCU1_KAGIT);
  
  int butonO2_TAS=digitalRead(OYUNCU2_TAS);
  int butonO2_MAKAS=digitalRead(OYUNCU2_MAKAS);
  int butonO2_KAGIT=digitalRead(OYUNCU2_KAGIT);
  
  if(butonO1_TAS==LOW && butonO2_MAKAS==LOW){
    digitalWrite(OYUNCU1_LED,HIGH);
    digitalWrite(OYUNCU2_LED,LOW);
  }
  else if(butonO1_MAKAS==LOW && butonO2_TAS==LOW){
    digitalWrite(OYUNCU1_LED,LOW);
    digitalWrite(OYUNCU2_LED,HIGH);
  }
  else if(butonO1_KAGIT==LOW &&  butonO2_TAS==LOW){
    digitalWrite(OYUNCU1_LED,HIGH);
    digitalWrite(OYUNCU2_LED,LOW);
  }
  else if(butonO1_TAS==LOW && butonO2_KAGIT==LOW){
    digitalWrite(OYUNCU1_LED,LOW);
    digitalWrite(OYUNCU2_LED,HIGH);
  }
  else if(butonO1_MAKAS==LOW && butonO2_KAGIT==LOW){
    digitalWrite(OYUNCU1_LED,HIGH);
    digitalWrite(OYUNCU2_LED,LOW);
  }
  else if(butonO1_KAGIT==LOW &&  butonO2_MAKAS==LOW){
    digitalWrite(OYUNCU1_LED,LOW);
    digitalWrite(OYUNCU2_LED,HIGH);
  }
  else if((butonO1_TAS==LOW && butonO2_TAS==LOW) || (butonO1_MAKAS==LOW && butonO2_MAKAS==LOW) || (butonO1_KAGIT==LOW && butonO2_KAGIT==LOW)){
    digitalWrite(OYUNCU1_LED,HIGH);
    digitalWrite(OYUNCU2_LED,HIGH);
  }
}
