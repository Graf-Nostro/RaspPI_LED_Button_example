/**
*
* Source file for GPIO_LED_Button_example
*
* @Author: Stf
* @Date:   12.11.2015
* 
*/

/*Include section*/

#include "main.h"

/*Preprocessor section*/

/*Global section*/

const int btnPin = 17; /* Button connected to pin17      */
const int pwmPin = 18; /* LED controlled by PWM on pin18 */
const int ledPin = 23; /* LED connected to pin23         */

const int pwmValue = 512; /* controll LED brightness 1/2 max: 1024 */

/**
* @fnck:   main
* @param:  int argc, char* argv[]
* @return: int return value
*/
int main( int argc, char* argv[] ){

   /*define wiringPi broadcom GPIO pin schema*/
   wiringPiSetupGpio();

   /*set pin mode 17 our button, 23 LED and 18 LED with PWM schema*/
   pinMode( btnPin, INPUT      );
   pinMode( ledPin, OUTPUT     );
   pinMode( pwmPin, PWM_OUTPUT );

   /*Enable pull-up resisor on button*/
   pullUpDnControl( btnPin, PUD_UP );

   printf( "Example setup done escape Program with CTRL-c\n" );

   while( TRUE ){
      if( digitalRead( btnPin) ){
         pwmWrite( pwmPin, pwmValue );
         digitalWrite( ledPin, LOW );
      } else {
         pwmWrite( pwmPin, 1024 - pwmValue ); /*PWM LED at dim setting*/
         digitalWrite( ledPin, HIGH );
         delay( 100 );
         digitalWrite( ledPin, LOW  );
         delay( 100 );
      }
   }

   pwmWrite( pwmPin, 0 );
   
   return 0;
}