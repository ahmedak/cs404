/***********************************
* Ahmed Karanath (B13104)
* Date: 14-Oct-2015
*
***********************************/

//header files
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <signal.h>    // Defines signal-handling functions (i.e. trap Ctrl-C)
#include "bbb_gpio.h"  // Contains necessary macros for the mmap function and other manipulations

int continue_loop = 1;

void signal_handler(int sig);

/* Callback called when interrupt SIGINT is sent to the process (Ctrl-C) */
void signal_handler(int sig){
  printf( "\nCtrl-C pressed, cleaning up and exiting...\n" );
	continue_loop = 0;
}

int main(){
	volatile void *gpio0_addr;
	volatile unsigned int *gpio0_setdataout_addr;
	volatile unsigned int *gpio0_cleardataout_addr;
	
	volatile void *gpio1_addr;
	volatile unsigned int *gpio1_setdataout_addr;
	volatile unsigned int *gpio1_cleardataout_addr;

	int switch0 = 0,switch1 = 0;
	// Set the signal callback for Ctrl-C
    signal(SIGINT, signal_handler);
	
	int fd = open("/dev/mem", O_RDWR);
	
	/* Mapping GPIO PORT 0 */
	gpio0_addr = mmap(0, GPIO0_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO0_START_ADDR);
  
  /* Mapping GPIO PORT 1 */
	gpio1_addr = mmap(0, GPIO1_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO1_START_ADDR);	
	
	if(gpio1_addr == MAP_FAILED) {
        printf("Unable to map GPIO1\n");
        exit(1);
    }
	
	if(gpio0_addr == MAP_FAILED) {
        printf("Unable to map GPIO0\n");
        exit(1);
    }
		
	gpio0_datain            = gpio0_addr + GPIO_DATAIN;
	gpio0_oe_addr           = gpio0_addr + GPIO_OE;
	gpio0_setdataout_addr   = gpio0_addr + GPIO_SETDATAOUT;
	gpio0_cleardataout_addr = gpio0_addr + GPIO_CLEARDATAOUT;
	
	gpio1_datain            = gpio1_addr + GPIO_DATAIN;
	gpio1_oe_addr           = gpio1_addr + GPIO_OE;
	gpio1_setdataout_addr   = gpio1_addr + GPIO_SETDATAOUT;
	gpio1_cleardataout_addr = gpio1_addr + GPIO_CLEARDATAOUT;
	
	printf("GPIO0 mapped to %p\n", gpio0_addr);
  printf("GPIO0 OE mapped to %p\n", gpio0_oe_addr);
  printf("GPIO0 SETDATAOUTADDR mapped to %p\n", gpio0_setdataout_addr);
  printf("GPIO0 CLEARDATAOUT mapped to %p\n", gpio0_cleardataout_addr);
	
	printf("GPIO1 mapped to %p\n", gpio1_addr);
  printf("GPIO1 OE mapped to %p\n", gpio1_oe_addr);
  printf("GPIO1 SETDATAOUTADDR mapped to %p\n", gpio1_setdataout_addr);
  printf("GPIO1 CLEARDATAOUT mapped to %p\n", gpio1_cleardataout_addr);
	
	/* Loop to read from switch0 and switch1  */
	while(continue_loop) {
		switch0 = 0;
		switch1 = 0;
		if(*gpio0_datain==0xFFFFFFFF & P8_17)
			switch0 = 1;
		if(*gpio1_datain==0xFFFFFFFF & P9_12)
			switch1 = 1;
		if(switch0)
			*gpio0_setdataout_addr = USR2;
		if(switch1)
			*gpio1_setdataout_addr = USR3;
	}
	
	/* Unmap the memory map
	munmap((void *)gpio0_addr, GPIO0_SIZE);
	munmap((void *)gpio1_addr, GPIO1_SIZE);
  
  close(fd);
  return 0;
}
