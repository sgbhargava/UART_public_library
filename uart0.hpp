/**
 * @file
 * @brief UART0 Interrupt driven IO driver
 * @ingroup Drivers
 */
#ifndef UART0_HPP_
#define UART0_HPP_

#include "uart_dev.hpp"            // Base class
#include "singleton_template.hpp"  // Singleton Template



/**
 * UART0 Interrupt Driven Driver
 */
class Uart0 : public UartDev, public SingletonTemplate<Uart0>
{
    public:
        /**
         * Initializes UART0 at the given @param baudRate
         * @param rxQSize   The size of the receive queue  (optional, defaults to 32)
         * @param txQSize   The size of the transmit queue (optional, defaults to 64)
         */
        bool init(unsigned int baudRate, int rxQSize=32, int txQSize=64);

    private:
        Uart0();  ///< Private constructor of this Singleton class
        friend class SingletonTemplate<Uart0>;  ///< Friend class used for Singleton Template
};


#endif /* UART0_HPP_ */
