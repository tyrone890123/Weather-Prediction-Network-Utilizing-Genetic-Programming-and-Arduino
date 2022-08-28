

<h1 align="center">Ubiquitous Limited Sensor-based Weather Binary Prediction Network Using 14-gene Genetic Expression</h3>
 
<p align="center">
<img width="260" src="https://raw.githubusercontent.com/tyrone890123/Weather-Prediction-Network-Utilizing-Genetic-Programming-and-Arduino/main/Assets/Circuit.jpg"> 
</p>

 - This project aims to create a weather detection system by utilizing the Arduino Uno board as its microcontroller with several essential components such as the DHT11 to act as the temperature and humidity sensor, an LCD module to display the output

 - Data is initially gathered in various locations using this setup. The data is then used to predict a change in the weather as temperatures fluctuate during rainfall. 

 
<details open="open">
  <h2>Table of Contents</h2>
	  <ol>
	    <li>
		    <a href="#intro">Introduction</a>
				<ul>
					<li><a href="#libs">Libraries Used</a></li>
				</ul>
	    </li>
	    <li><a href="#bd">Block Diagram</a></li>
		<li><a href="#pm">Pin Mapping</a></li>
		<li><a href="#psd">Pseudocode</a></li>
		<li><a href="#contributors">Contributors</a></li>
	</ol>
</details>

<h2 id="intro">Introduction</h2>

Unexpected weather can usually be a problem as they often cause inconveniences when drying clothes or going out without an umbrella which can lead to getting a cold. The project will be done using the Arduino Uno board as microcontroller and the DHT11 temperature and humidity sensor and LCD 1602 module that comes along with it. We expect to be able to approximate if rain will occur through the data received from the humidity and temperature sensor.

Being on the receiving end of an unexpected rainfall is oftentimes challenging and troublesome in a tropical nation like the Philippines where rain is plentiful throughout the year. The group suggests an Arduino weather detection system that employs sensors to gauge the relative humidity and temperature of the environment and provides the user with a forecast of the weather. Users who have access to this information can subsequently modify their behavior as necessary, such as packing an umbrella or choosing not to go outside.
  
<h2 id="libs">Libraries Used</h2>
The microprocessor to be used in the development of the system is the Arduino Uno, this allows for the necessary number of ports for each of the components that are to be used in the system; furthermore, allowing for analog to digital conversion, as well as timer interrupts which are necessary to the functionality of the circuit. 
<br>

 - LiquicCrystal_I2C
 - virtuabotixRTC.h
 - DHT.h

`LiquicCrystal_I2C` is used to control the I2C LCD display that will be used to display the real time values of the DHT11 sensor and the DS1302 RTC module. `virtuabotixRTC.h` is used to set and retrieve data from the RTC module. `DHT.h` is used for gathering the humidity and temperature data from the DHT11 sensor.


<h2 id="bd">Block Diagram</h2>

The block diagram of the system can be seen below, the heart of the system is the Arduino Uno, in which the inputs to the system are from the DHT11 sensor and the DS1302 RTC module, the user can input into the system through the button switch and the potentiometer. The outputs of the system can be seen in the form of the LED and I2C LCD components.
<br>
<p align="center">
<img width="400" src="https://raw.githubusercontent.com/tyrone890123/Weather-Prediction-Network-Utilizing-Genetic-Programming-and-Arduino/main/Assets/Diagram.png"> 
</p>

<h4>DHT11</h4>

-   The DHT11 sensor is a humidity and temperature sensor which is used to gather information about the humidity and temperature of the surroundings. This is the main sensor used in predicting whether there would be rainfall.
 
<h4>DS1302</h4>

-   The DS1302 is a real time clock module which allows the user to see the current time based on the information stored in the component.

<h4>I2C LCD</h4>

-   The I2C LCD is a 16x2 LCD module which is the primary display used to display the information from both the DHT11 sensor and the DS1302 RTC Module.

<h4>LED</h4>

-   The LED is used to display whether or not there is a possibility of rain by blinking allowing the user to prepare for the possible rainfall.

<h4>Potentiometer and Push Buttons</h4>

- The potentiometer is used to adjust the sensitivity of the weather detection, by turning the knob the threshold is increased. The push buttons are used to change the display from either the DHT11 sensor and the DS1302 RTC Module

<h2 id="pm">Pin Mapping</h2>
The pin mapping of the system can be seen in the image below. PORT D2 and D3 are used for the push buttons. Moreover, PORT D4 is used for the DHT11 sensor and D5 to D7 are used for the DS1302 RTC module. Lastly, PORT B1 is used for the LED rain indicator. PORT C0 is used for the input of the potentiometer as the value needs to be converted by the ADC. PORT C4 and C5 are used for the SDA and SCL lines of the I2C LCD.
<br>
<br>
<p align="center">
<img width="500" src="https://raw.githubusercontent.com/tyrone890123/Weather-Prediction-Network-Utilizing-Genetic-Programming-and-Arduino/main/Assets/Pin%20Mapping.jpg"> 
</p>

<h2 id="psd">Pseudocode</h2>
The start of the pseudocode mainly consists of the initializations to the different components that would be used, mainly the LCD, DHT, RTC, buttons, potentiometer, LED, and the various variables that would be used to keep track of the data or which sequence needs to occur. Once the while loop begins, the potentiometer is read and is used alongside the initial threshold which would indicate whether to inform the user through an LED sequence. Button presses from the user are also checked, this is to determine which screen to display, whether its from the DHT11 or the RTC. The DTH11 data is being collected regardless of whether or not the screen is on the DHT11 data or RTC, this is to allow for the system to be able to warn the user if there is incoming rain even if they are on the clock portion of the screen. The LED works using the timer compare interrupt in order to allow for the LED to blink independently from the other processes present. If delay was used instead of the LED, this would cause the other parts of the system to pause while the LED is blinking, in this way it allows for the program to work concurrently.
<br>
<br>
<p align="center">
<img width="300" src="https://raw.githubusercontent.com/tyrone890123/Weather-Prediction-Network-Utilizing-Genetic-Programming-and-Arduino/main/Assets/Pseudocode.png"> 
</p>

<h2 id="contributors">Contributors</h2>
<table>
<tr>
	<th>
		<p align="center">
			Jose Antonio Cadavillo
		</p>
		<p align="center">
			jose_antonio_cadavillo@dlsu.edu.ph
		</p>
	</th>
	<th>
		<p align="center">
			Joyce Yuenlam Cai
		</p>
		<p align="center">
			joyce_yuenlam_cai@dlsu.edu.ph
		</p>
	</th> 
	<th> 
		<p align="center">
			Dmitri Chuacuco
		</p>
		<p align="center">
			dmitri_chuacuco@dlsu.edu.ph
		</p>
	</th>
</tr>
<tr>
	<th>
		<p align="center">
			Tyrone Ashley Go
		</p>
		<p align="center">
			tyrone_go@dlsu.edu.ph
		</p>
	</th>
	<th>
		<p align="center">
			Jonah Jahara Baun
		</p>
		<p align="center">
			jonah_baun@dlsu.edu.ph
		</p>
	</th> 
	<th> 
		<p align="center">
			Argel Bandala
		</p>
		<p align="center">
			argel.bandala@dlsu.edu.ph
		</p>
	</th>
</tr>
<tr>
	<th>
		<p align="center">
			Ronnie Concepcion
		</p>
		<p align="center">
			ronnie.concepcion@dlsu.edu.ph
		</p>
	</th>
</tr>
</table>

