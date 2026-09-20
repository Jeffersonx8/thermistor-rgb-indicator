# thermistor-rgb-indicator
First Arduino project based on a RGB LED that changes color depending on the temperature detected by the thermistor. 

## How it works
The project was initially making a red LED blink when crossing a certain temperature threshold, but after completing that I changed it to this. The to change the shade of red/blue on the RGB LED, I used a thermistor to detect temperature changes and convert it into resistance. I used SunFounder's official documentation of my specific thermistor to find the formula for it, which is $$R_T = R_N \cdot e^{B(\frac{1}{T_K} - \frac{1}{T_N})}$$. And the constants were going to be 10k ohms (RN) at 25 celsius (TN). I also used room temperature of 27C so I can comfortably cross the temperature threshold by just blowing on the thermistor of putting my finger on it. 

As for formula derivations, I had to convert temperature in KELVIN, not celsius, into "units", which is what arduino reads. And since the arduino is 10 bits, the max units is 1023, and the max voltage the arduino can output is 5 volts. Meaning each unit is approximately $5/1023 = .0049 volts$. My goal now is to get temperature to 
