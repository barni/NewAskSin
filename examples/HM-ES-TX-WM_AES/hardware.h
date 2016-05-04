//- -----------------------------------------------------------------------------------------------------------------------
// AskSin driver implementation
// 2013-08-03 <trilu@gmx.de> Creative Commons - http://creativecommons.org/licenses/by-nc-sa/3.0/de/
//- -----------------------------------------------------------------------------------------------------------------------
//- AskSin hardware definition ----------------------------------------------------------------------------------------
//- with a lot of support from martin876 at FHEM forum
//- -------------------------------------------------------------------------------------------------------------------

#include <HAL.h>

#ifndef _HARDWARE_h
	#define _HARDWARE_h

	#define DEBOUNCE                   5										// input debounce time in ms - 5 seems to be a good value

	#if defined(__AVR_ATmega328P__)
		//- cc1100 hardware CS and GDO0 definitions -------------------------------------------------------------------
		#define CC_CS_DDR              DDRB										// SPI chip select definition
		#define CC_CS_PORT             PORTB
		#define CC_CS_PIN              PORTB2

		#define CC_GDO0_DDR            DDRD										// GDO0 pin, signals received data
		#define CC_GDO0_PIN            PORTB2

		#define CC_GDO0_PCICR          PCICR									// GDO0 interrupt register
		#define CC_GDO0_PCIE           PCIE2
		#define CC_GDO0_PCMSK          PCMSK2									// GDO0 interrupt mask
		#define CC_GDO0_INT            PCINT18									// pin interrupt

		//- LED's definition ------------------------------------------------------------------------------------------
		#define LED_RED_DDR            DDRD										// define led port and remaining pin
		#define LED_RED_PORT           PORTD
		#define LED_RED_PIN            PORTD4

		#define LED_GRN_DDR            DDRD
		#define LED_GRN_PORT           PORTD
		#define LED_GRN_PIN            PORTD4

		#define LED_ACTIVE_LOW         0										// leds connected to GND = 0, VCC = 1

		//- configuration key  ----------------------------------------------------------------------------------------
		#define CONFIG_KEY_DDR         DDRB										// define config key port and remaining pin
		#define CONFIG_KEY_PORT	       PORTB
		#define CONFIG_KEY_PIN         PORTB0

		#define CONFIG_KEY_PCICR       PCICR									// interrupt register
		#define CONFIG_KEY_PCIE        PCIE0									// pin change interrupt port bit
		#define CONFIG_KEY_PCMSK       PCMSK0									// interrupt mask
		#define CONFIG_KEY_INT         PCINT0									// pin interrupt

		//- battery external measurement functions --------------------------------------------------------------------
		#define BATT_ENABLE_DDR        DDRD										// define battery measurement enable pin, has to be low to start measuring
		#define BATT_ENABLE_PORT       PORTD
		#define BATT_ENABLE_PIN        PORTD7

		#define BATT_MEASURE_DDR       DDRC										// define battery measure pin, where ADC gets the measurement
		#define BATT_MEASURE_PORT      PORTC
		#define BATT_MEASURE_PIN       PORTC1
	#endif

#endif
