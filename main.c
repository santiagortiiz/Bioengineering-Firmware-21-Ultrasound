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
#include "project.h"
#include "ultrasonido.h"
#include "input_capture.h"
#include "temperatura.h"
#include "calculos.h"
#include "interfaz.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_fotointerruptor_StartEx(sensar);
    isr_deteccion_de_flancos_StartEx(flanco_detectado);

    /* Inicializacion de Componentes */
    LCD_Start();
    ADC_Start();
    Seguidor_Start();
    
    menu(0);
    
    for(;;)
    {
        /* Rutina de activacion del sensor de ultrasonido SRF05 */
        if (activar_ultrasonido){                       
            activar_ultrasonido = 0;                // Cuando se presiona el boton de activacion
            Timer_Start();                          // se inicializa el timer y se envia el pulso
            enviar_pulso();                         // indicativo de activacion del sensor
        }
        
        /* Rutina de lectura del sensor de ultrasonido SRF05 */
        if (timer.capturas_listas == 1){            
            timer.capturas_listas = 0;              // Una vez el input capture detecte un flanco de subida 
            Timer_Stop();                           // y uno de bajada, activa una bandera que indica que 
            calcular_tiempo_transcurrido();         // las capturas estan listas y se detiene el timer.
            sensar_temperatura();                   // Luego se procede a calcular el tiempo transcurrido
            calcular_velocidad_sonido();            // entre flancos, se sensa la T y se calcula la Vel. sonido
            calcular_distancia();                   // para calcular finalmente la distancia.
            
            if (altura_del_sensor_guardada){
                calcular_altura();                  
            }
            
            menu(1);
        }
    }
}

/* [] END OF FILE */
