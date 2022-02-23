#include "16F877A.h"
#use delay (oscillator=20M)
#use rs232 (baud=57600, parity=N, bits=8, xmit=PIN_C6, rcv=PIN_C7)
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "pwm.c"
#include <string.h>

#define ON_STR "##startON"
#define OFF_STR "##startOFF"
#define SET_STR "##startSET"
#define GET_STR "##startGET"
#define ACK "##ACK "
#define NACK "##NACK"
#define PWM "##ACK%3.2f\n\r"
int main()
{
   char on[]=ON_STR;
   char off[]=OFF_STR;
   char set[]=SET_STR;
   char get[]=GET_STR;
   int end=0;
   int i=0;
   uint8_t str[20];
   float dcf=0.0;
   float temp=0.0;
   setup_uart(57600);
   printf("Hello World\n\r");
   setupPwm();
   while(!end)
   {
      //printf("WAITING...\n");
      gets(str);
      i=0;
      while(str[i++]!='#');
      i--;
      //printf("GOT...%s\n",str+i);
      //##startON -> responde : ##ACK
      if(strncmp(str+i, on, 9)==0)
      {
         dcf=100.0;
         setPwm(dcf);
         printf("%s\n\r",ACK);
      }
      //##startOFF -> responde : ##ACK
      else if(strncmp(str+i, off, 10)==0)
      {
         dcf=0.0;
         setPwm(dcf);
         printf("%s\n\r",ACK);
      }
      else if(strncmp(str+i,set, 10)==0)
      {
         temp=atof(str+i+10);
         if((temp>=0.0)&&(temp<=100.0))
         {
            dcf=temp;
            setPwm(dcf);
            printf("%s\n\r",ACK);
         }
         else
         {
            printf("%s\n\r",NACK);
         }
      }
      else if(strncmp(str+i, get, 10)==0)
      {
         printf(PWM,dcf);
      }
   }
   return 0;
}

