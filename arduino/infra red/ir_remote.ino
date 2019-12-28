// install IRremote libryary
#include <IRremote.h>

// KEY MAP
#define CHMIN 0xFFA25D
#define CH    0xFF629D
#define CHPLS 0xFFE21D
#define PREV  0xFF22DD
#define NEXT  0xFF02FD
#define PLAY  0xFFC23D
#define MIN   0xFFE01F
#define PLUS  0xFFA857
#define EQ    0xFF906F
#define PL100 0xFF9867
#define PL200 0xFFB04F
#define ZERO  0XFF6897
#define ONE   0xFF30CF
#define TWO   0xFF18E7
#define THREE 0xFF7A85
#define FOUR  0xFF10EF
#define FIVE  0xFF38C7
#define SIX   0xFF5AA5
#define SEVEN 0xFF42BD
#define EIGHT 0xFF4AB5
#define NINE  0xFF52AD

#define RECVPIN  7

IRrecv irrecv(RECVPIN);
decode_results results;
unsigned long key_value = 0;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;

        switch(results.value){
          case CHMIN:
          Serial.println("CH-");
          break;
          case CH:
          Serial.println("CH");
          break;
          case CHPLS:
          Serial.println("CH+");
          break;
          case PREV:
          Serial.println("|<<");
          break;
          case NEXT:
          Serial.println(">>|");
          break ;  
          case PLAY:
          Serial.println(">|");
          break ;               
          case MIN:
          Serial.println("-");
          break ;  
          case PLUS:
          Serial.println("+");
          break ;  
          case EQ:
          Serial.println("EQ");
          break ;  
          case ZERO:
          Serial.println("0");
          break ;  
          case PL100:
          Serial.println("100+");
          break ;
          case PL200:
          Serial.println("200+");
          break ;
          case ONE:
          Serial.println("1");
          break ;
          case TWO:
          Serial.println("2");
          break ;
          case THREE:
          Serial.println("3");
          break ;
          case FOUR:
          Serial.println("4");
          break ;
          case FIVE:
          Serial.println("5");
          break ;
          case SIX:
          Serial.println("6");
          break ;
          case SEVEN:
          Serial.println("7");
          break ;
          case EIGHT:
          Serial.println("8");
          break ;
          case NINE:
          Serial.println("9");
          break ;      
        }
        key_value = results.value;
        irrecv.resume(); 
  }
}
