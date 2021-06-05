#include "leds.h"

#define ALL_LEDS_OFF    0x0000
#define ALL_LEDS_ON     0xFFFF
#define LED_ON          1
#define LED_OFFSET      1
#define LED_COUNT       16

#define led_to_bit( led ) (uint16_t)( LED_ON << (led - LED_OFFSET) )

#define led_inBound( led ) (bool)( led >= LED_OFFSET && led < (LED_COUNT + LED_OFFSET) )

static uint16_t *puerto;

void Leds_Create( uint16_t *puntero )
{
    puerto = puntero;
    Leds_TurnOffAll();
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