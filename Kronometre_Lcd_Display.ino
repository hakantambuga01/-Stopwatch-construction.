#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int btn1=8;
int btn2=9;
int btn3=10;
int buton1,buton2,buton3;
int dk,dakika,sn,saniye,ml,milisaniye;
int a,b,c,d;
int dk1,sn1,ml1;



void setup() {
       lcd.begin(16, 2);
       lcd.setCursor(4,0);
       lcd.print("KRONOMETRE");
       lcd.setCursor(4,1);
       lcd.print("0");
       lcd.setCursor(7,1);
       lcd.print("0");
       lcd.setCursor(10,1);
       lcd.print("0");
       lcd.setCursor(6,1);
       lcd.print(".");
       lcd.setCursor(9,1);
       lcd.print(".");
       pinMode(btn1,INPUT);
       pinMode(btn2,INPUT);
       pinMode(btn3,INPUT);
}

void loop() 
{
        buton1=digitalRead(btn1);
        buton2=digitalRead(btn2);
        buton3=digitalRead(btn3);
        enbas:
        if(buton1==LOW)
        {
          a=1;
          b=0; c=0; d=0;
          baslat();
        }

        
}


void baslat()
{
     enbas:
     buton1=digitalRead(btn1);
     if(buton1==LOW)
        {
          a=1;
          b=0; c=0; d=0;
        }
 
  while(a==1)
  {
//      if(buton3==LOW)
//        {
//          
//          dakika=0;
//          saniye=0;
//          milisaniye=0;
//          lcd.setCursor(4,1);
//          lcd.print(dakika);
//          lcd.setCursor(7,1);
//          lcd.print(saniye);
//          lcd.setCursor(10,1);
//          lcd.print(milisaniye);
//          goto enbas; a=0;
//        }

        
        bas:
        lcd.setCursor(6,1);
        lcd.print(".");
        lcd.setCursor(9,1);
        lcd.print(".");
        dk1=dakika;
        sn1=saniye;
        ml1=milisaniye;
        buton1=digitalRead(btn1);
        if(buton1==LOW)
        {
          b=0; c=0; d=0;
        }

                  
        if(b==0)
        {
        for(dk=dk1; dk<60; dk++)
        {
          dakika=dk;
          lcd.setCursor(4,1);
          lcd.print(dakika);
          if(b==1)
          {
            goto bas;
          }
          

          if(c==0)
          {
          for(sn=sn1; sn<60; sn++)
          {
            saniye=sn;
            lcd.setCursor(7,1);
            lcd.print(saniye);
            if(c==1)
            {
              goto bas;
            }

            if(d==0)
            {
            for(ml=ml1; ml<60; ml++)
            {
              milisaniye=ml;
              lcd.setCursor(10,1);
              lcd.print(milisaniye);
              delay(15);

                 if(d==1)
                 {
                  goto bas;
                 }
//                         buton3=digitalRead(btn3);
//        if(buton3==LOW)
//        {
//         
//          dakika=0;
//          saniye=0;
//          milisaniye=0;
//          lcd.setCursor(4,1);
//          lcd.print(dakika);
//          lcd.setCursor(7,1);
//          lcd.print(saniye);
//          lcd.setCursor(10,1);
//          lcd.print(milisaniye);
//          goto enbas; a=0;
//        }
                 buton2=digitalRead(btn2);
                 if(buton2==LOW)
                 {
                  b=1;
                  c=1;
                  d=1;
                 }
            }
            ml1=0;
            }
          }
          }
        }
        }
  }
}

