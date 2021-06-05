#include "unity.h"
#include "leds.h"

#define ALL_LEDS_OFF    0x0000
#define ALL_LEDS_ON     0xFFFF
#define LED_ON          1
#define LED_OFFSET      1
#define led_to_bit( led ) (uint16_t)( LED_ON << (led - LED_OFFSET) )

#define LED                 5
#define LED_OUT_OF_BOUNDS   17

uint16_t ledsVirtuales;


void setUp(void)
{
    Leds_Create( &ledsVirtuales );
}

void tearDown(void)
{
}

// Despues de la inicialización todos los LEDs deben quedar apagados
void test_LedsOffAfterCreate(void)
{
    ledsVirtuales = ALL_LEDS_ON;
    Leds_Create( &ledsVirtuales );
    TEST_ASSERT_EQUAL_HEX16( ALL_LEDS_OFF, ledsVirtuales );
}

// Se puede prender un LED individual
void test_TurnOnOneLed(void)
{
    Led_TurnOn( LED );
    TEST_ASSERT_EQUAL_HEX16( led_to_bit(LED), ledsVirtuales );
}

// Se puede apagar un LED individualmente
void test_TurnOffOneLed(void)
{
    Led_TurnOn( LED );
    Led_TurnOff( LED );
    TEST_ASSERT_EQUAL_HEX16( ALL_LEDS_OFF, ledsVirtuales );

}

// Se puede encender y apagar varios LEDs
void test_TurnOnAndOffManyLeds(void)
{
    Led_TurnOn( 3 );
    Led_TurnOn( LED );
    Led_TurnOff( 3 );
    TEST_ASSERT_EQUAL_HEX16( led_to_bit(LED), ledsVirtuales );
}

// Se pueden encender todos los LEDs a la vez
void test_TurnOnAllLeds(void)
{
    Leds_TurnOnAll();
    TEST_ASSERT_EQUAL_HEX16( ALL_LEDS_ON, ledsVirtuales );
}

// Se pueden apagar todos los LEDs a la vez
void test_TurnOffAllLeds(void)
{
    Led_TurnOn( LED );
    Leds_TurnOffAll();
    TEST_ASSERT_EQUAL_HEX16( ALL_LEDS_OFF, ledsVirtuales );
}

// Se puede obtener el estado encendido de un LED
void test_GetOneLedStatusOn(void)
{
    bool ledStatus = false;
    Led_TurnOn( LED );
    ledStatus = Led_Get( LED );
    TEST_ASSERT_EQUAL_HEX16( true, ledStatus );
}

// Se puede obtener el estado apagado de un LED
void test_GetOneLedStatusOff(void)
{
    bool ledStatus = false;
    Led_TurnOn( LED );
    Led_TurnOff( LED );
    ledStatus = Led_Get( LED );
    TEST_ASSERT_EQUAL_HEX16( false, ledStatus );
}

// Se puede enviar leds fuera de los limites y no sucede nada
void test_LedOutOfBounds(void)
{
    Led_TurnOn( LED );
    Led_TurnOn( LED_OUT_OF_BOUNDS );
    TEST_ASSERT_EQUAL_HEX16( led_to_bit(LED), ledsVirtuales );
}