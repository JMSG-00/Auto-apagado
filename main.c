#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16f886.h>
#define FCY 8000000UL

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

unsigned char cont = 0;

int main(int argc, char** argv) {
    OSCCON |=0b01110101;        // 8MHz
    _delay(1000000);
//    TRISA   =   0x00;
//    TRISB   =   0x00;
//    TRISC   =   0x00;
     TRISCbits.TRISC3 = 0;      //Salida
     TRISCbits.TRISC2 = 0;      //Salida
     PORTCbits.RC3=0;
     PORTCbits.RC2=0;
  
     do{
         PORTCbits.RC3++;
         _delay(1000000);
         _delay(1000000);
         cont++;
         if (cont==6){
             PORTCbits.RC2++;
             _delay(1000000);
             _delay(1000000);
//             do{_delay(1);}while(1);
             cont=0;
         }
     }while(1);
    return (EXIT_SUCCESS);
}


