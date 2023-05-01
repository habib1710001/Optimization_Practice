struct date{
         uint16_t day : 5;
         uint16_t month: 4;
         uint16_t year;
};


struct datef{
         uint16_t day : 5;
         uint16_t     :0;
         uint16_t month: 4;
         uint16_t year;
};


void setup(){
  Serial.begin(9600);
}
void loop(){
  date dt1,dt2;
  datef dt3;
  dt1.day = 22;
  dt1.month = 12;
  dt1.year = 1998;

  dt2.day = 28;
  dt2.month = 7;
  dt2.year = 2019;

  dt3.day = 24;
  dt3.month = 6;
  dt3.year = 2020;

  
  Serial.println(String(dt1.day)+"/"+String(dt1.month)+"/"+String(dt1.year));
  Serial.println(String(dt2.day)+"/"+String(dt2.month)+"/"+String(dt2.year));
  Serial.println(String(dt3.day)+"/"+String(dt3.month)+"/"+String(dt3.year));
  
  Serial.println(sizeof(struct date));
  Serial.println(sizeof(struct datef));
  delay(1000);
}
