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
#include "input_capture.h"

/*** VARIABLES ***/
static volatile uint8 registro;
estructura_1 timer;


/*** FUNCIONES ***/

/*** INTERRUPCIONES ***/
CY_ISR(flanco_detectado){
    registro = Timer_ReadStatusRegister();              // Registros del Timer
    
    if (registro & Timer_STATUS_CAPTURE){               // Si la interrupcion se genero por captura
        if (flanco_de_subida){                          // verifica que tipo de flanco fue detectado
            timer.valor_1 = Timer_ReadCapture();        // para asignar el contador del timer al
            flanco_de_subida_capturado;                 // valor 1 o 2 segun corresponda
        }
        
        else if (flanco_de_bajada){
            timer.valor_2 = Timer_ReadCapture();
            flanco_de_bajada_capturado;
            timer.capturas_listas = 1;
        }
    }
}

/* [] END OF FILE */
