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
#include "calculos.h"
#include "input_capture.h"
#include "temperatura.h"

/*** VARIABLES ***/
uint32 conteos_entre_eventos;
uint16 velocidad_sonido;
uint16 distancia;

uint8 altura_del_sensor_guardada;
uint16 altura_del_sensor;
uint16 altura_de_la_persona;

/*** FUNCIONES ***/
void calcular_tiempo_transcurrido(void){
    conteos_entre_eventos = timer.valor_1 - timer.valor_2;          // Conteos realizados por el Timer
}

void calcular_velocidad_sonido(void){
    velocidad_sonido = 3316 + 6*temperatura_ambiente/10;            // Velocidad del sonido con 1 decimal
}

void calcular_distancia(void){
    distancia = velocidad_sonido * conteos_entre_eventos / 2000;    // Distancia en cm con 2 decimales
    
    if (altura_del_sensor_guardada == 0){                           // Si es la primera vez que mide el sensor
        altura_del_sensor = distancia;                              // la distancia calculada sera marcada
        altura_del_sensor_guardada = 1;                             // como altura de referencia
    }
}

void calcular_altura(void){                                         // Diferencia entre la altura del sensor
    if (altura_del_sensor > distancia){                             // y la distancia que recorre el eco
        altura_de_la_persona = altura_del_sensor - distancia;
    }
}

/*** INTERRUPCIONES ***/

/* [] END OF FILE */
