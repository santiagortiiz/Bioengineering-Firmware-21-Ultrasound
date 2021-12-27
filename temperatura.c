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
#include "temperatura.h"

/*** VARIABLES ***/
uint16 temperatura_ambiente = 0;

/*** FUNCIONES ***/
void sensar_temperatura(void){                              // Rutina del conversor ADC para
    ADC_StartConvert();                                     // el sensado de la temperatura
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);               // ambiente
    temperatura_ambiente = ADC_GetResult16()*100/89;
}

/*** INTERRUPCIONES ***/

/* [] END OF FILE */
