# CatFlap
A cat door manage with an arduino

Edit with Arduino IDE 2.2.1

The RFID reader :
| parameter | description |
|---|----|
| model | CZSTAR-R134 |
| dimension | 35 x 36 mm |
| freqency | AM 134.2k |
| Power supply voltage | 5-9V battery or power supply. Using low frequency DC-DC or switching power supply will affect the reading distance. |
| Working current | 120mA @ 9V recommended 100mA @ 7V |
| Working temperature | -40 - +80°C |
| Default antenna inductance | 580uH |

| pin | description |
|----|-----|
| 1 | +5V to +9V Pure power supply |
| 2 | RST reset, low level effective |
| 3 | TX serial port number output, TTL, 5V level |
| 4 | GND |
| L1 | Antenna 1 |
| L2 | Antenna 2 (360V vpp)

Read card distance reference list:
-Use length 97x97mm square antenna reading card distance are as follows
-2x12mm glass tube is about 18cm
-The diameter of 3cm ear tag reading distance is about 36cm

TX Data format (ASCII): Baudrate 9600, 8N2
| LSB |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    | MSB |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
| 02 | 36 | 34 | 45 | 38 | 34 | 33 | 32 | 31 | 30 | 37 | 45 | 33 | 30 | 30 | 31 | 30 | 30 | 30 | 30 | 30 | 30 | 30 | 30 | 30 | 30 | 0B | F4 | 03 |


| LSB |    |    |    |    |    |    |    |    | MSB |
|----|----|----|----|----|----|----|----|----|----|
| 02 | Card number 10byte | Country number 4byte | Data Block 1byte | Animal Flag 1byte | Reserved 4byte | Reserved 4byte | Checksum 1byte | /Checksum 1byte | 03 |
| 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 |
