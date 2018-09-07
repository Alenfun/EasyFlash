/*
 * This file is part of the EasyFlash Library.
 *
 * Copyright (c) 2015, Armink, <armink.ztl@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * 'Software'), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Function: Portable interface for each platform.
 * Created on: 2015-01-16
 */

#include <easyflash.h>
#include <stdarg.h>

<<<<<<< HEAD
#include "irq.h"
/* default environment variables set for user */
static const ef_env default_env_set[] = {
        {"iap_need_copy_app","0"},
        {"iap_copy_app_size","0"},
        {"stop_in_bootloader","0"},
        {"device_id","1"},
        {"boot_times","0"},
};

static char log_buf[256];

=======
/* default environment variables set for user */
static const ef_env default_env_set[] = {

};
>>>>>>> 90184f9f078915d78da0bbf2769db2c11c6cba43

/**
 * Flash port for hardware initialize.
 *
 * @param default_env default ENV set for user
 * @param default_env_size default ENV size
 *
 * @return result
 */
EfErrCode ef_port_init(ef_env const **default_env, size_t *default_env_size) {
    EfErrCode result = EF_NO_ERR;

    *default_env = default_env_set;
    *default_env_size = sizeof(default_env_set) / sizeof(default_env_set[0]);

    return result;
}

/**
 * Read data from flash.
 * @note This operation's units is word.
 *
 * @param addr flash address
 * @param buf buffer to store read data
 * @param size read bytes size
 *
 * @return result
 */
EfErrCode ef_port_read(uint32_t addr, uint32_t *buf, size_t size) {
    EfErrCode result = EF_NO_ERR;

    EF_ASSERT(size % 4 == 0);

    /* You can add your code under here. */
<<<<<<< HEAD
    addr -= UFLASH_ADDRESS;

    hfuflash_read(addr, buf, size);

=======
>>>>>>> 90184f9f078915d78da0bbf2769db2c11c6cba43

    return result;
}

/**
 * Erase data on flash.
 * @note This operation is irreversible.
 * @note This operation's units is different which on many chips.
 *
 * @param addr flash address
 * @param size erase bytes size
 *
 * @return result
 */
EfErrCode ef_port_erase(uint32_t addr, size_t size) {
    EfErrCode result = EF_NO_ERR;
<<<<<<< HEAD
    size_t start_pages, erase_pages, i;
    uint32_t start_page_addr, end_page_addr;

    EF_DEBUG("addr:%08x  size:%d\r\n\r\n", addr, size);
    /* make sure the start address is a multiple of EF_ERASE_MIN_SIZE */
    EF_ASSERT(addr % EF_ERASE_MIN_SIZE == 0);

    start_page_addr = (addr & (~(uint32_t)(EF_ERASE_MIN_SIZE-1))) - UFLASH_ADDRESS ;
    end_page_addr   = (addr + size) - UFLASH_ADDRESS;
    /* calculate pages */
    start_pages     = start_page_addr >> 12;
    erase_pages     = (end_page_addr - start_page_addr) >> 12;
    if( end_page_addr & (uint32_t)(PAGE_SIZE-1) )
    {
        erase_pages ++;
    }

    u_printf("\r\nstart_page_addr=%08x end_page_addr=%08x\r\nstart_pages=%d erase_pages=%d\r\n\r\n",
        start_page_addr, end_page_addr, start_pages, erase_pages);

    hfuflash_erase_page(start_page_addr, erase_pages);
=======

    /* make sure the start address is a multiple of EF_ERASE_MIN_SIZE */
    EF_ASSERT(addr % EF_ERASE_MIN_SIZE == 0);

    /* You can add your code under here. */

>>>>>>> 90184f9f078915d78da0bbf2769db2c11c6cba43
    return result;
}
/**
 * Write data to flash.
 * @note This operation's units is word.
 * @note This operation must after erase. @see flash_erase.
 *
 * @param addr flash address
 * @param buf the write data buffer
 * @param size write bytes size
 *
 * @return result
 */
EfErrCode ef_port_write(uint32_t addr, const uint32_t *buf, size_t size) {
    EfErrCode result = EF_NO_ERR;

    EF_ASSERT(size % 4 == 0);
    
    /* You can add your code under here. */
<<<<<<< HEAD
    addr -= UFLASH_ADDRESS;
    hfuflash_write(addr, buf, size);
=======
>>>>>>> 90184f9f078915d78da0bbf2769db2c11c6cba43

    return result;
}

/**
 * lock the ENV ram cache
 */
void ef_port_env_lock(void) {
    
    /* You can add your code under here. */
<<<<<<< HEAD
    // irq_disable();
=======
    
>>>>>>> 90184f9f078915d78da0bbf2769db2c11c6cba43
}

/**
 * unlock the ENV ram cache
 */
void ef_port_env_unlock(void) {
    
    /* You can add your code under here. */
<<<<<<< HEAD
    // irq_enable();
=======
>>>>>>> 90184f9f078915d78da0bbf2769db2c11c6cba43
    
}


/**
 * This function is print flash debug info.
 *
 * @param file the file which has call this function
 * @param line the line number which has call this function
 * @param format output format
 * @param ... args
 *
 */
void ef_log_debug(const char *file, const long line, const char *format, ...) {

#ifdef PRINT_DEBUG

    va_list args;

    /* args point to the first variable parameter */
    va_start(args, format);

    /* You can add your code under here. */
<<<<<<< HEAD
    ef_print("[Flash](%s:%d) ", file, line);
    /* must use vprintf to print */
    vsprintf(log_buf, format, args);
    ef_print("%s", log_buf);
    printf("\r");

=======
    
>>>>>>> 90184f9f078915d78da0bbf2769db2c11c6cba43
    va_end(args);

#endif

}

/**
 * This function is print flash routine info.
 *
 * @param format output format
 * @param ... args
 */
void ef_log_info(const char *format, ...) {
    va_list args;

    /* args point to the first variable parameter */
    va_start(args, format);

    /* You can add your code under here. */
<<<<<<< HEAD
    ef_print("[Flash]");
    /* must use vprintf to print */
    vsprintf(log_buf, format, args);
    ef_print("%s", log_buf);

=======
    
>>>>>>> 90184f9f078915d78da0bbf2769db2c11c6cba43
    va_end(args);
}
/**
 * This function is print flash non-package info.
 *
 * @param format output format
 * @param ... args
 */
void ef_print(const char *format, ...) {
    va_list args;

    /* args point to the first variable parameter */
    va_start(args, format);

<<<<<<< HEAD
    /* must use vprintf to print */
    vsprintf(log_buf, format, args);
    u_printf("%s", log_buf);
=======
    /* You can add your code under here. */
>>>>>>> 90184f9f078915d78da0bbf2769db2c11c6cba43
    
    va_end(args);
}
