#include <stdint.h>
#include <stdbool.h>


void Leds_Create( uint16_t *puerto );
void Led_TurnOn( uint8_t led );
void Led_TurnOff( uint8_t led );
void Leds_TurnOnAll( void );
void Leds_TurnOffAll( void );
bool Led_Get( uint8_t led );