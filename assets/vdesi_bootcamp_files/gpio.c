
#include "xparameters.h"
#include "xgpio.h"
#include "platform.h"

/************************** Constant Definitions *****************************/
//Bits set to 0 are output and bits set to 1 are input.

#define But 0x01
#define Led 0x00

/*
 * The following constants map to the XPAR parameters created in the
 * xparameters.h file. They are defined here such that a user can easily
 * change all the needed parameters in one place.
 */
#define GPIO_BUTTON_DEVICE_ID  XPAR_GPIO_0_DEVICE_ID
#define GPIO_LED_DEVICE_ID  XPAR_GPIO_1_DEVICE_ID
/*
 * The following constant is used to wait after an LED is turned on to make
 * sure that it is visible to the human eye.  This constant might need to be
 * tuned for faster or slower processor speeds.
 */
#define LED_DELAY     10000000

/*
 * The following constant is used to determine which channel of the GPIO is
 * used for the LED if there are 2 channels supported.
 */
#define LED_CHANNEL 1

/**************************** Type Definitions *******************************/


/***************** Macros (Inline Functions) Definitions *********************/

#ifdef PRE_2_00A_APPLICATION

/*
 * The following macros are provided to allow an application to compile that
 * uses an older version of the driver (pre 2.00a) which did not have a channel
 * parameter. Note that the channel parameter is fixed as channel 1.
 */
#define XGpio_SetDataDirection(InstancePtr, DirectionMask) \
        XGpio_SetDataDirection(InstancePtr, LED_CHANNEL, DirectionMask)

#define XGpio_DiscreteRead(InstancePtr) \
        XGpio_DiscreteRead(InstancePtr, LED_CHANNEL)

#define XGpio_DiscreteWrite(InstancePtr, Mask) \
        XGpio_DiscreteWrite(InstancePtr, LED_CHANNEL, Mask)

#define XGpio_DiscreteSet(InstancePtr, Mask) \
        XGpio_DiscreteSet(InstancePtr, LED_CHANNEL, Mask)

#endif

/************************** Function Prototypes ******************************/


/************************** Variable Definitions *****************************/

/*
 * The following are declared globally so they are zeroed and so they are
 * easily accessible from a debugger
 */

XGpio Button; /* The Instance of the GPIO Driver */
XGpio ld;

/*****************************************************************************/
/**
*
* The purpose of this function is to illustrate how to use the GPIO
* driver to turn on and off an LED.
*
* @param	None
*
* @return	XST_FAILURE to indicate that the GPIO Initialization had
*		failed.
*
* @note		This function will not return if the test is running.
*
******************************************************************************/
int main(void)
{
	int Status;
	volatile int Delay;
	int btn;

	init_platform();
	xil_printf("-- Start of the Program --\r\n");

	/* Initialize the Button driver */
	Status = XGpio_Initialize(&Button, GPIO_BUTTON_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/* Initialize the LED driver */
	Status = XGpio_Initialize(&ld, GPIO_LED_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/* Set the direction for all signals as inputs except the LED output */
	XGpio_SetDataDirection(&Button, LED_CHANNEL, But);
	XGpio_SetDataDirection(&ld, LED_CHANNEL, Led);

	while (1) {

		btn = XGpio_DiscreteRead(&Button, LED_CHANNEL);
		XGpio_DiscreteWrite(&ld, 1, btn);

		/* Wait a small amount of time so the LED is visible */
		for (Delay = 0; Delay < LED_DELAY; Delay++);
	}

	return XST_SUCCESS;
}
