/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/*** COMPONENTES INCLUIDOS ***/
#include "interfaz.h"
#include "input_capture.h"
#include "temperatura.h"
#include "calculos.h"

/*** VARIABLES ***/

/*** FUNCIONES ***/
void menu(uint8 indice){                            // Rutinas de impresion en el LCD
    switch(indice){ 
        case 0:   
            LCD_ClearDisplay();
            LCD_Position(0,0);
            LCD_PrintString("Sistema de medicion");
            LCD_Position(1,2);
            LCD_PrintString("de distancia por");
            LCD_Position(2,4);
            LCD_PrintString("Ultrasonido");
            break;
            
        case 1:  
            LCD_ClearDisplay();
            LCD_Position(0,0);
            LCD_PrintString("T:");
            LCD_PrintNumber(temperatura_ambiente/10);
            LCD_PutChar('.');
            LCD_PrintNumber(temperatura_ambiente%10);
            
            LCD_Position(0,9);
            LCD_PrintString("Vs:");
            LCD_PrintNumber(velocidad_sonido/10);
            LCD_PutChar('.');
            LCD_PrintNumber(velocidad_sonido%10);
            LCD_PrintString("m/s");
            
            LCD_Position(1,0);
            LCD_PrintString("C:");
            LCD_PrintU32Number(conteos_entre_eventos);
            
            LCD_Position(1,9);
            LCD_PrintString("Ai:");
            LCD_PrintNumber(altura_del_sensor/100);
            LCD_PutChar('.');
            LCD_PrintNumber(altura_del_sensor%100);
            LCD_PrintString("cm");
            
            LCD_Position(2,0);
            LCD_PrintString("Eco: ");
            LCD_PrintNumber(distancia/100);
            LCD_PutChar('.');
            LCD_PrintNumber(distancia%100);
            LCD_PrintString(" cm");
            
            if (altura_del_sensor_guardada){
                LCD_Position(3,0);
                LCD_PrintString("Altura: ");
                LCD_PrintNumber(altura_de_la_persona/100);
                LCD_PutChar('.');
                LCD_PrintNumber(altura_de_la_persona%100);
                LCD_PrintString(" cm");
            }
            break;
    }
}

/*** INTERRUPCIONES ***/

/* [] END OF FILE */
