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

#ifndef CALCULOS_H
    #define CALCULOS_H
    
    #include "project.h"

    /*** MACROS ***/
    
    /*** PROTOTIPO DE VARIABLES GLOBALES ***/
    extern uint32 conteos_entre_eventos;
    extern uint16 velocidad_sonido;
    extern uint16 distancia;
    extern uint8  altura_del_sensor_guardada;
    extern uint16 altura_del_sensor;
    extern uint16 altura_de_la_persona;
    
    /*** PROTOTIPO DE FUNCIONES ***/
    void calcular_tiempo_transcurrido(void);
    void calcular_velocidad_sonido(void);
    void calcular_distancia(void);
    void calcular_altura(void);
    
    /*** PROTOTIPO DE INTERRUPCIONES ***/
    
#endif

/* [] END OF FILE */
