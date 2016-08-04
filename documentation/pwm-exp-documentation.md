# PWM Expansion Node Addon
The Onion Servo (PWM) Node Addon, pwm-node-addon is a wrapper aroung the libonionpwmexp dynamic C library that provides functions to setu the servo Expansion and generate PWM signals.

![imgur](http://i.imgur.com/aNoYCZc.png)


## Programming Flow
After each power-cycle, the chip that controls the PWM Expansion must be programmed with an initialization sequence to enable the on-board oscillator so that PWM signals can be generated. After the initialization, the other functions can be used to generate PWM signals on specific channels or to change the PWM signal frequency.

Additionally, it is possible to disable to the oscillator, disabling the generation of all PWM signals at once.
> Before generating new PWM signals, the initialization sequence must be run again.

The PWM Expansion has **16** channels that can generate distinct PWM signals. Note that **they will all be running on the same frequency**.


## PWM Signal Refresher
Pulse Width Modulated signals can be described with duty cycle percentages and frequencies/periods:

![imgur](http://www.bristolwatch.com/picaxe/images/io43.gif)

The *duty cycle* indicates what percentage of time a signal is on or high voltage.

The *frequency* determines the overall period of the pulse.

For a more detailed explanation, see the guide on using the [Servo Expansion](https://wiki.onion.io/Tutorials/Expansions/Using-the-Servo-Expansion#pwm-signals).


## The Node Addon
The pwm-exp-addon exposes a series of methods that perform all of the actions specified in the Programming Flow section.


### Using the Addon
Install the addon into your project folder from our repo using opkg install.
```
opkg install pwm_addon
```


### Importing the addon into your Node Script
To use the addon within your script you have to import it into your node program as you would a module:

```javascript
var pwmAddon = require('./pwm-node-addon');
```


### Calling Methods
Methods are called in the following format.

```javascript
pwmAddon.method();
```
Replace method with your funcion of interest.


### Return Values
All of the functions will either return a 0 indicating success or 1 indicating failure.

| Return value | Status   |
|:------------:|----------|
|      0       | Failure  |
|      1       | Success  |

You can check execution status by using simple if-else condition:
```javascript
if (pwmAddon.method()) {
  console.log('Execution successfull');
} else {
  console.error('Execution fault');
}
```


### Available Methods

Refer to the table below for a list and brief description of available PWM methods.

|  Method  |  Inputs  | Description     |
|----------|----------|-----------------|
|  driverInit() |  *none*  |  Initialize the PWM expansion for use.  |
|  checkInit()  |  *none*  |  Check to see if the expansion is initialized.  |
|  setupDriver(channel, duty, delay )  |  **0-15** *or* **-1**, **0-100, 0-100** |  Generates the specified PWM signal on the specified channel.  |
|  setFrequency(frequency)  |  **24 - 1526**  |  Sets the frequency for the oscillator chip.  |
|  disableChip()  |  *none*  |  Disables the oscillator chip and stops all PWM signals.  |


## Usage
### Initialization Function
This function programs the initialization sequence on the Servo Expansion, after this step is completed, the functions to generate PWM signals or change the signal frequency can be used with success.
```javascript
pwmAddon.driverInit()
```

#### Examples
Quite simple.
```javascript
pwmAddon.driverInit();
```


-----
### Check for Initialization
This function performs several reads to determine if the Servo Expansion has been initialized and the oscillator is running.
```javascript
pwmAddon.checkInit()
```

#### Examples
Let's check if the oscillator is initialized.
```javascript
if (pwmAddon.checkInit()) {
  console.log('Oscillator sucessfull initialized');
} else {
  console.error('Error with oscillator initializing');
}
```


-----
### Generate a PWM Signal
Here we go! Use this function to generate a PWM signal on a specified channel:
```javascript
pwmAddon.setupDriver(channel, duty, delay);
```

#### Arguments

| Argument | Input | Meaning |
|----------|-------|---------|
| channel   |  **-1** *or* **0 - 15**  |  Detemines on which channel to generate the PWM signal  |
| duty      |  **0.00 - 100.00**  |  Specifies duty cycle percentage for the PWM signal  (decimial allowed)  |
| delay     |  **0.00 - 100.00**  |  Specifies the percentage delay before the PWM signal goes high (decimial allowed) |

> Note that in normal use with servos,  **delay should be set to 0**.

This table describes how to use *channel argument*:

|    Value    | Meaning                                   |
|:-----------:|-------------------------------------------|
|  **0 - 15** | Matches the label on the Servo Expansion  |
|   **-1**    | Generates the same signal on all channels |


#### Examples
Set channel 0 to a PWM signal with a 50% duty cycle:
```javascript
pwmAddon.setupDriver(0, 50, 0);
```

Generate a 3.55% duty cycle PWM signal with a 45% delay on channel 7:
```javascript
pwmAddon.setupDriver(7, 3.55, 45);
```

Set channel 0 to a PWM signal with a 50% duty cycle:
```javascript
pwmAddon.setupDriver(15, 100, 0);
```

Set channel 8 to always off:
```javascript
pwmAddon.setupDriver(8, 0, 0);
```

Set all channels to a 15.65% duty cycle PWM signal:
```javascript
pwmAddon.setupDriver(-1, 15.65, 0);
```


-----
### Set PWM Signal Frequency
The oscillator can be reprogrammed to generate a variety of different frequencies:
```javascript
pwmAddon.setFrequency(frequency)
```
Default oscillator frequency is a **50 Hz**.
> Note that oscillator frequency **is the same for all PWM channels on chip**

#### Arguments

|  Argument  |  Input                |  Meaning                        |
|------------|-----------------------|---------------------------------|
| frequency  |  **24.00 - 1526.00**  |  Specifies the frequency in Hz  |


#### Examples
Change the frequency to 60 Hz and generate a 40% duty cycle signal on channel 14:
```javascript
pwmAddon.setFrequency(60);
pwmAddon.setupDriver(14,40,0);
```

Generate a signal on channel 13, change the chip frequency to 105.45 Hz, and generate a new signal on channel 13:
```javascript
pwmAddon.setupDriver(13,99,0);
pwmAddon.setFrequency(105.45);
pwmAddon.setupDriver(13,82,0);
```


-----
#### Disabling the Oscillator
The oscillator can also be disabled, automatically stopping all PWM signal generation:
```javascript
pwmAddon.disableChip();
```
This might be useful for disabling PWM signal-driven devices while not powering off the Omega. **The initialization function will have to be run before new PWM signals can be generated.**
