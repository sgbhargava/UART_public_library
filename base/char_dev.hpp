/**
 * @file
 * @brief Provides a 'char' device base class functionality.
 */
 
#ifndef CHAR_DEV_HPP_
#define CHAR_DEV_HPP_

/**
 * Char device base class.
 */
 
class CharDev
{
    public:
        /**
         * @returns a character from the UART input
         * @param   pInputChar  The pointer to input char to store received character
         * @param   timeout Optional parameter which defaults to maximum value that
         *          will allow you to wait forever for a character to be received
         * @returns true if a character was obtained within the given timeout
         */
        virtual bool getChar(char* pInputChar, unsigned int timeout=portMAX_DELAY) = 0;

        /**
         * Outputs a char given by @param out
         * @param   timeout Optional parameter which defaults to maximum value that
         *          will allow you to wait forever for a character to be sent
         * @returns true if the output char was successfully written to Queue, or
         *          false if the output queue was full within the given timeout
         */
        virtual bool putChar(char out, unsigned int timeout=portMAX_DELAY) = 0;

        /**
         * Optional flush to flush out all the data
         */
        virtual bool flush(void) { return true; }

        /**
         * @{ Output a null-terminated string
         * puts() will also output newline chars "\r\n" at the end of the string
         */
        bool puts  (const char* pString, unsigned int timeout=0xffffffff);

        /**
         * Get a string of input up to maxLen
         * @param pBuff The buffer to store data to
         * @param maxLen The maximum chars to get
         * @param timeout The timeout in ticks to wait
         */
        bool gets(char* pBuff, int maxLen, unsigned int timeout=0xffffffff);

        /**
         * Just like printf, except it will print to this output interface
         * @returns the number of characters printed
         */
        int printf(const char *format, ...);

        /**
         * Just like scanf, except this will perform scanf after receiving a line
         * of input using the gets() method.
         */
        int scanf(const char *format, ...);

        /**
         * @{  This API just provides a means to set a flag if UART is ready or not
         *     This doesn't cause any change to the way UART functions.
         */
        bool isReady(void);
        void setReady(bool r);

    protected:
        CharDev();
        virtual ~CharDev();

    private:
        bool mReady;                        ///< Marker if device is ready or not
};

#endif /* CHAR_DEV_HPP_ */
