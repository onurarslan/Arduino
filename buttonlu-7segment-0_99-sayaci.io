#define AA 2
#define BB 3
#define CC 4
#define DD 5
#define EE 6
#define FF 8
#define GG 7

#define DIGIT0 9
#define DIGIT1 10

#define BUTON 11
char sayac;
char sira;
unsigned long zaman;
char segment[10] =
{
    //xgfedcba
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
};

void setup(){
  pinMode(AA, OUTPUT);
  pinMode(BB, OUTPUT);
  pinMode(CC, OUTPUT);
  pinMode(DD, OUTPUT);
  pinMode(EE, OUTPUT);
  pinMode(FF, OUTPUT);
  pinMode(GG, OUTPUT);
  pinMode(DIGIT0, OUTPUT);
  pinMode(DIGIT1, OUTPUT);
  pinMode(BUTON, INPUT_PULLUP);
  sayac=0;
  sira=0;
  zaman=0;
}

void disp(char sayi){
  char c=segment[sayi];
  digitalWrite(AA, c & 0x01);
  digitalWrite(BB, c & 0x02);
  digitalWrite(CC, c & 0x04);
  digitalWrite(DD, c & 0x08);
  digitalWrite(EE, c & 0x10);
  digitalWrite(FF, c & 0x20); 
  digitalWrite(GG, c & 0x40);
}

void loop(){
  int butonOku=digitalRead(BUTON);
  if(butonOku==LOW){
    switch(sira){
      case 0:{
        digitalWrite(DIGIT0, LOW);
        digitalWrite(DIGIT1, LOW);
        disp(sayac%10);
        digitalWrite(DIGIT0, HIGH);
        sira=1;
        break;
      }
      case 1:{
        digitalWrite(DIGIT0, LOW);
        digitalWrite(DIGIT1, LOW);
        disp(sayac/10);
        digitalWrite(DIGIT1, HIGH);
        sira=0;
        break;
      }
    }
     if(millis()>zaman+1000){
       zaman=millis();
       sayac++;
       if(sayac>99) sayac=0;
     }
     //delay(100);//bloklar
      //milis();
  }
  
}
