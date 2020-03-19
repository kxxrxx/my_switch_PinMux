#include <stdint.h>		// variable definitions for the C99 standard
#include <stdbool.h>		// Boolean definitions for the C99 standard
#include "switch_PinMux.h"
#include "inc/hw_types.h"	// Defines common types and macros
#include "inc/hw_memmap.h"	// Macros defining the memory map of the Tiva C Series device. This includes defines such as peripheral base address locations such as GPIO_PORTF_BASE.
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"	// Defines and macros for System Control API of DriverLib
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"	// Defines and macros for GPIO API of DriverLib. This includes API functions such as GPIOPinRead and GPIOPinWrite.
#include "inc/tm4c123gh6pm.h"	// manually added by the programmer

#define 	RED_LED 	0x02

//*****************************************************************************
void
PortFunctionInit(void)
{
    //
    // Enable Peripheral Clocks 
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    //
    // Enable pin PF1 for GPIOOutput
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);

    //
    // Enable pin PF0 for GPIOInput
    //

    //
    //First open the lock and select the bits we want to modify in the GPIO commit register.
    //
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR) = 0x1;

    //
    //Now modify the configuration of the pins that we unlocked.
    //
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);
		
//*************************************************************
//	The code above is automatically generated by PinMux
//  The code below should be manually added by the programmer
//*************************************************************
		
//Enable pull-up on PF0
GPIO_PORTF_PUR_R |= 0x01; 
		
}

int main(void)
{
	
    //initialize the GPIO ports	
    PortFunctionInit();
	
    //
    // Loop forever.
    //
    while(1)
    {

		if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0)==0x00)	 //SW2 is pressed
		{
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x00); // red LED is off
		}
		else
		{
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, RED_LED); // red LED is on
		}
    }
}
