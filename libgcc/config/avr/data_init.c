extern unsigned int _dinit_size;
extern unsigned int _dinit_addr;

extern void __do_copy_data ();
extern void __do_clear_bss ();


extern unsigned char *__data_load_start ;
extern unsigned char *__data_start ;
extern unsigned char *__data_end ;

extern unsigned char *__bss_start ;
extern unsigned char *__bss_end ;

void __attribute__((section(".init4"), naked)) __do_data_init()
{
    
    unsigned int    *pDinit;
    unsigned char   *pDst;
    unsigned int    sec_size;
    unsigned int    format;

    /* init pDinit with .dinit section address */
    pDinit = &_dinit_addr;
    
    /* check the destination address */
    while ((*pDinit != 0) || (*(pDinit+1) != 0)) 
    {
        // take the destination address
     		pDst = (unsigned char*)*pDinit;
        pDinit++;
        pDinit++; 

        // take the size of the section that should be copied
        sec_size = *pDinit;
        pDinit++;
        
        // is initialized data(PROGBITS) or
        // uninitialized data (NOBITS - like .bss)
        format = *pDinit;
        pDinit++;

        if (format)
        {
            // Initialized data. 
            // Get the __data_start and __data_end to copy the data.
            // Get the __data_load_start in the dinit table to copy the data from.
            __data_start =  pDst;
            __data_load_start = (unsigned char*)pDinit; 
            __data_end =  pDst + sec_size;

            __do_copy_data();
        }
        else
        {
            // Uninitialized data
            // Get the start address and size to clear.
            __bss_start =  pDst;
            __bss_end   =  pDst + sec_size;

            __do_clear_bss();
        }
        
        pDinit += (sec_size/2 + (((sec_size%2) != 0)? 1:0));
    }
}

