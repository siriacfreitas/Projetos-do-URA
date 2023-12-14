//NOTAS
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST 0

int tempo=120; 

int buzzerPin = 9;

int melody[] = {

  NOTE_AS4,4,  NOTE_F4,-4,  NOTE_AS4,8,  NOTE_AS4,16,  NOTE_C5,16, NOTE_D5,16, NOTE_DS5,16,//7
  NOTE_F5,2,  NOTE_F5,8,  NOTE_F5,8,  NOTE_F5,8,  NOTE_FS5,16, NOTE_GS5,16,
  NOTE_AS5,-2,  NOTE_AS5,8,  NOTE_AS5,8,  NOTE_GS5,8,  NOTE_FS5,16,
  NOTE_GS5,-8,  NOTE_FS5,16,  NOTE_F5,2,  NOTE_F5,4, 
};

int notes=sizeof(melody)/sizeof(melody[0])/2; 

int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void playWinnerMusic() {
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }
    tone(buzzerPin, melody[thisNote], noteDuration*0.9);
    delay(noteDuration);
    noTone(buzzerPin);
  } 
      }

#define led1_azul  10
#define led1_vermelho  11
#define led1_amarelo  12
#define btn1  13

#define led2_azul  7 
#define led2_vermelho 6
#define led2_amarelo  5
#define btn2  4

int btn1clicado=0;
int btn1liberado=0;
int btn2clicado=0;
int btn2liberado=0;

void ligaled1(){
  if(digitalRead(led1_amarelo)==HIGH){
     if(digitalRead(led1_vermelho)==HIGH){
        digitalWrite(led1_azul,HIGH);
    }else{
    digitalWrite(led1_vermelho,HIGH);
    }
 }else{
  digitalWrite(led1_amarelo,HIGH);
  }
}

void ligaled2(){
  if(digitalRead(led2_amarelo)==HIGH){
     if(digitalRead(led2_vermelho)==HIGH){
        digitalWrite(led2_azul,HIGH);
    }else{
    digitalWrite(led2_vermelho,HIGH);
    }
 }else{
  digitalWrite(led2_amarelo,HIGH);
  }
}

void keyup(){
  if((btn1clicado==1)and(btn1liberado==1)){
    btn1clicado=0;
    btn1liberado=0; 
    delay(500);
    ligaled1();
}
  if((btn2clicado==1)and(btn2liberado==1)){
    btn2clicado=0;
    btn2liberado=0; 
    delay(500);
    ligaled2();
}
}
 
void setup() {
  pinMode(led1_azul,OUTPUT);
  pinMode(led1_vermelho,OUTPUT);
  pinMode(led1_amarelo,OUTPUT);
  pinMode(btn1,INPUT);
 
  pinMode(led2_azul,OUTPUT);
  pinMode(led2_vermelho,OUTPUT);
  pinMode(led2_amarelo,OUTPUT);
  pinMode(btn2,INPUT);
  
  pinMode(buzzerPin, OUTPUT);

}
void loop() {
  if(digitalRead(btn1)==HIGH){
    btn1clicado=1;
    btn1liberado=0;
  }
  else{
    btn1liberado=1;
  }
   if(digitalRead(btn2)==HIGH){
    btn2clicado=1;
    btn2liberado=0;
  }
  else{
    btn2liberado=1;
  }
  keyup();
  
  if (((digitalRead(led1_azul)==HIGH) and (digitalRead(led1_vermelho)==HIGH) and (digitalRead(led1_amarelo)==HIGH))or ((digitalRead(led2_azul)==HIGH) and (digitalRead(led2_vermelho)==HIGH) and (digitalRead(led2_amarelo)==HIGH))){
     playWinnerMusic();
     digitalWrite(led1_azul,LOW);
     digitalWrite(led1_vermelho,LOW);
     digitalWrite(led1_amarelo,LOW);
     digitalWrite(led2_azul,LOW);
     digitalWrite(led2_vermelho,LOW);
     digitalWrite(led2_amarelo,LOW);
  }
   
}
