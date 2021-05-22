#include <stdint.h>
#include <stdbool.h>

#define ALL_LEDS_OFF    0x0000
#define ALL_LEDS_ON     0xFFFF
#define LED_ON          1
#define LED_OFFSET      1
#define LED_COUNT       16

#define led_to_bit( led ) (uint16_t)( LED_ON << (led - LED_OFFSET) )


void Leds_Create( uint16_t *puerto );
void Led_TurnOn( uint8_t led );
void Led_TurnOff( uint8_t led );
void Leds_TurnOnAll( void );
void Leds_TurnOffAll( void );
bool Led_Get( uint8_t led );