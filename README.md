# Channel_sensing

IEEE 802.15.4 uses ISM band 2.4 GHz radio frequencies (from channel 11 to channel 26) to transmit sensor data. These frequency are also used by other radio technologies, such as WiFi, Bluetooth, and others. To setup a WSN, it is an important step to select a channel with minimum interference. A practical approach is to leverage channel sensing to identify the channel interference status by measuring the noise/interference signal strength.

The following steps should be completed using a sensor node:

1. Write a program to measure the noise/interference signal strength of different channels (from channel 11 to channel 26).
• To learn how to set up a given channel.
• To measure RSSI of the noise/interference at different channels. You  should decide how long to measure the RSSI value and how to deal with the measures in each channel.

2. Compare noise/interference status at different channels and select the best
channel. The Fig. 1 shows the 16 channels of 802.15.4 coexist with the
channels of Bluetooth Low Energy and the Channels of WiFi.
<img width="530" alt="image" src="https://user-images.githubusercontent.com/43139396/197492014-39e7bf1d-60af-4a0a-ba99-32ea0763ab41.png">

# Results
See main.c for the implementation of how I got these results. An important note about these values, is that cc2420 library[^1] already implies the RSSI_OFFSET of approximately -45 dbm.

<img width="479" alt="image" src="https://user-images.githubusercontent.com/43139396/197492308-d465baec-3cf5-4067-9c5b-80ea1fae737f.png">

As we can see in this example of my code running, channel 25 has the lowest dbm and thereby being the best channel.

[^1]: https://www.ti.com/lit/ds/symlink/cc2420.pdf?ts=1666540020827
