/**
 * @file
 * @brief Provides UART Base class functionality for UART peripherals
 *
 */
#ifndef UART_DEV_HPP_
#define UART_DEV_HPP_

#include "char_dev.hpp"

/**
 * UART Base class that can be used to write drivers for all UART peripherals.
 * Steps needed to write a UART driver:
 *  - Inherit this class
 *  - Call init() and configure PINSEL to select your UART pins
 *  - When your UART(#) hardware interrupt occurs, call handleInterrupt()
 */
class UartDev : public CharDev
{
    public:
	
        /**
         * @returns a character from the UART input
         * @param   pInputChar  The pointer to input char to store received character
         * @param   timeout Optional parameter which defaults to maximum value that
         *          will allow you to wait forever for a character to be received
         * @returns true if a character was obtained within the given timeout
         */
        bool getChar(char* pInputChar, unsigned int timeout=portMAX_DELAY);

        /**
         * Outputs a char given by @param out
         * @param   timeout Optional parameter which defaults to maximum value that
         *          will allow you to wait forever for a character to be sent
         * @returns true if the output char was successfully written to Queue, or
         *          false if the output queue was full within the given timeout
         */
        bool putChar(char out, unsigned int timeout=portMAX_DELAY);

        /**
         * When the UART interrupt occurs, this function should be called to handle
         * future action to take due to the interrupt cause.
         */
        void handleInterrupt();

    protected:
        /**
         * Initializes the UART register including Queues, baudrate and hardware.
         * Parent class should call this method before initializing Pin-Connect-Block
         * @param pclk      The system peripheral clock for this UART
         * @param baudRate  The baud rate to set
         * @param rxQSize   The receive queue size
         * @param txQSize   The transmit queue size
		 * @returns			true if initialization was successful, or
		 *					false if initialization failed.
         */
        bool init(unsigned int pclk, unsigned int baudRate, int rxQSize=32, int txQSize=32);

        /**
         * Protected constructor that requires parent class to provide UART's
         * base register address for which to operate this UART driver
         */
        UartDev(unsigned int* pUARTBaseAddr);
        ~UartDev() { } /** Nothing to clean up */

    private:
        UartDev(); /** Disallowed constructor */
        QueueHandle_t mRxQueue;         ///< Queue for UARTs receive buffer
        QueueHandle_t mTxQueue;         ///< Queue for UARTs transmit buffer
};



#endif /* UART_DEV_HPP_ */

