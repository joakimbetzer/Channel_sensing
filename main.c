#include <stdio.h> /* For printing */
#include "contiki.h"
#include "cc2420.h"

int measureChannel();

/*-----------------------------------------------------------*/
PROCESS(mainProcess, "Process for everything");
AUTOSTART_PROCESSES(&mainProcess);
/*-----------------------------------------------------------*/

PROCESS_THREAD(mainProcess,ev,data)
{  

    PROCESS_BEGIN();

    int i = 0;

    cc2420_init();
    for (i = 11; i <= 26; i++)
    {
      printf("Channel: %d    Value: %d dbm\n", i, measureChannel(i));
    }

    PROCESS_END();
}

int measureChannel(int channel){
  static struct timer timer;
  int mean;

  //Instantiate the cc2420
  cc2420_on();
  cc2420_set_channel((int)channel);

  int Output = 0;
  int amountOfOutputs = 10;

  for (int i = 0; i < amountOfOutputs; i++)
  {
    Output += cc2420_rssi();
    timer_set(&timer, CLOCK_SECOND * 2);
    timer_reset(&timer);
  }

  mean = Output / amountOfOutputs;
  
  //Reset the cc2420
  cc2420_off();
  
  return mean;
}