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

#ifndef ULTRASONIDO_H
    #define ULTRASONIDO_H
    
    #include "project.h"

    /*** MACROS ***/
    #define ALTO 1
    #define BAJO 0
    
    /*** PROTOTIPO DE VARIABLES GLOBALES ***/
    extern uint8 activar_ultrasonido;
    
    /*** PROTOTIPO DE FUNCIONES ***/
    void enviar_pulso(void);
    
    /*** PROTOTIPO DE INTERRUPCIONES ***/
    CY_ISR_PROTO(sensar);
    
#endif

/* [] END OF FILE */
