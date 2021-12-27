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
#include "ultrasonido.h"

/*** VARIABLES ***/
uint8 activar_ultrasonido;

/*** FUNCIONES ***/
void enviar_pulso(void){            // Pulso de 10 microsegundos en el Trigger
    SRF05_trigger_Write(ALTO);      // del sensor SRF05 para inicializarlo
    CyDelayUs(10);                  
    SRF05_trigger_Write(BAJO);
}

/*** INTERRUPCIONES ***/
CY_ISR(sensar){                     // Interrupcion del boton que activa
    activar_ultrasonido = 1;        // la bandera para inicializar el sensor
}

/* [] END OF FILE */
