#include "unity.h"
#include "leds.h"

#define LED_5_ON        0b10000

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
    ledsVirtuales = 0xFFFF;
    Leds_Create( &ledsVirtuales );
    TEST_ASSERT_EQUAL_HEX16( 0x0000, ledsVirtuales );
}

// Se puede prender un LED individual
void test_TurnOnOneLed(void)
{
    Led_TurnOn( LED );
    TEST_ASSERT_EQUAL_HEX16( LED_5_ON, ledsVirtuales );
}

// Se puede apagar un LED individualmente
void test_TurnOffOneLed(void)
{
    Led_TurnOn( LED );
    Led_TurnOff( LED );
    TEST_ASSERT_EQUAL_HEX16( 0x0000, ledsVirtuales );

}

// Se puede encender y apagar varios LEDs
void test_TurnOnAndOffManyLeds(void)
{
    Led_TurnOn( 3 );
    Led_TurnOn( LED );
    Led_TurnOff( 3 );
    TEST_ASSERT_EQUAL_HEX16( LED_5_ON, ledsVirtuales );
}

// Se pueden encender todos los LEDs a la vez
void test_TurnOnAllLeds(void)
{
    Leds_TurnOnAll();
    TEST_ASSERT_EQUAL_HEX16( 0xFFFF, ledsVirtuales );
}

// Se pueden apagar todos los LEDs a la vez
void test_TurnOffAllLeds(void)
{
    Leds_TurnOnAll();
    Leds_TurnOffAll();
    TEST_ASSERT_EQUAL_HEX16( 0x0000, ledsVirtuales );
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
    TEST_ASSERT_EQUAL_HEX16( LED_5_ON, ledsVirtuales );
}