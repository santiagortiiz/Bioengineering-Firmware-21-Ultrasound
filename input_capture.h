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

#ifndef INPUT_CAPTURE_H
    #define INPUT_CAPTURE_H
    
    #include "project.h"

    /*** MACROS ***/
    #define flanco_de_subida timer.contador_de_flancos == 0
    #define flanco_de_bajada timer.contador_de_flancos == 1
    #define flanco_de_subida_capturado timer.contador_de_flancos++
    #define flanco_de_bajada_capturado timer.contador_de_flancos--
    
    /*** PROTOTIPO DE VARIABLES GLOBALES ***/
    typedef struct Estructura_1{
        uint32 contador_de_flancos: 1;
        uint32 valor_1: 24;
        uint32 valor_2: 24;
        uint32 capturas_listas: 1;
    } estructura_1;
    
    extern estructura_1 timer;
    
    /*** PROTOTIPO DE FUNCIONES ***/
    
    /*** PROTOTIPO DE INTERRUPCIONES ***/
    CY_ISR_PROTO(flanco_detectado);
    
#endif

/* [] END OF FILE */
