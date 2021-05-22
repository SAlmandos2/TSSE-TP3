#include "leds.h"

#define led_inBound( led ) (bool)( led >= LED_OFFSET && led < (LED_COUNT + LED_OFFSET) )


static uint16_t *puerto;

void Leds_Create( uint16_t *puntero )
{
    puerto = puntero;
    *puerto = ALL_LEDS_OFF;
}

void Led_TurnOn( uint8_t led )
{
    if( led_inBound(led) )
        *puerto |= led_to_bit(led);
}

void Led_TurnOff( uint8_t led )
{
    if( led_inBound(led) )
        *puerto &= ~led_to_bit(led);
}

void Leds_TurnOnAll( void )
{
    *puerto = ALL_LEDS_ON;
}

void Leds_TurnOffAll( void )
{
    *puerto = ALL_LEDS_OFF;
}

bool Led_Get( uint8_t led )
{
    if( led_inBound(led) )
        return *puerto & led_to_bit(led) ? true : false;
    return false;
}