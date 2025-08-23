# I2Y-BDC
Icom to Yaesu - Band Data Converter

this is a copy of MARIOS NICOLAOU's (5B4WN) from https://www.5b4wn.com/main/a1921.html<br/>

Icom rigs have their own unique way of providing  information to external rigs based on the current band. This information is provided on a single pin on the ACC-2 socket by varying the voltage from 0-8V<br/>
<img width="581" height="205" alt="image" src="https://github.com/user-attachments/assets/5a2e77df-da36-452b-a9d8-203f05c8bdff" />

Most peripheral equipment use the ubiquitous YAESU band data method as follows:<br/>
<img width="497" height="141" alt="image" src="https://github.com/user-attachments/assets/7cb79e28-df87-48eb-bddb-bdb238b28fbd" />

This project uses an arduino to read the voltage from the ACC2 pin, determines the band and then converts it to a YAESU band data to use with the many peripherals that support the latter.  As the arduino can sense up to 5V (TTL level) and the icom outputs up to 8V, a voltage divider is required to fool the arduino analog pin that 8V is 5V! Here is the schematic:<br/>
<img width="575" height="266" alt="image" src="https://github.com/user-attachments/assets/d34d71ef-b42c-4234-9e42-cf9080e2bcac" />

Use analog Pin 5 on Arduino<br/>
Use Digital Pins 9, 10, 11, 12 for YAESU output DCBA<br/>
You can use the Pin 1 for ACC2 to supply the voltage for the arduino<br/>
So once the circuit is complete, you need to program this using the arduino development environment<br/>
