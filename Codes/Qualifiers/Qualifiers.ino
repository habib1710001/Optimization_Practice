#define MASK(x) ({\
                  (uint8_t)(1<<(x)); \ 
                 })

#define MEASURE
#define TIME 100000; //though this is an error that will replace the whole 10000; 
                     //the compiler won't warn 

//const uint16_t TIME = 100000;

#ifdef MEASURE
   uint32_t startTime, currentTime;
#endif 

void wait(){
    volatile uint32_t x = TIME;  //disables the complier optimization
                               //don't let the optimizer to remove the while loop 
   //uint32_t x = TIME;
   while(x)
     x--;
}

void setup(){ 
  DDRB|= MASK(5);
  Serial.begin(9600);
}
void loop(){
  PORTB ^= MASK(5);

  #ifdef MEASURE
     startTime = millis();
  #endif

  wait();
  wait();
  wait();
  wait();
  wait();
  wait();


  #ifdef MEASURE
     currentTime = millis();
     Serial.print("Time: ");
     Serial.print((float)(currentTime - startTime)*0.001,3);
     Serial.println(" seconds");
  #endif
}
