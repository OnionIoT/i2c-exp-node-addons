# Nodes Documentation

The table below summarizes the functionality of custom Nodes provided by the Onion Team for interfacing with device hardware and expansions.

| Node | Description |
|-----|---------|
|gpio-read| Reads(high or low) and outputs the value of a gpio in msg.payload|
|gpio-write| Writes a value(high or low) to a gpio and outputs the written value in msg.payload|
|relay-exp-read| Reads(on or off) and outputs the state of a channel on a given relay in msg.payload|
|relay-exp-write| Writes a state (on or off) and outputs the state of a channel on a given relay in msg.payload|
|pwm-exp| Sets the duty cycle on a specified channel of the pwm expansion, outputs the specified duty cycle in msg.payload|
|servo-exp| Sets a servo motor connected to a specified channel of the pwm expansion to a given angle, outputs the angle in msg.payload|
|oled-exp-clear| Clears the Oled Display|
|oled-exp| Writes a msg to the Oled Expansion, additionally can be used to modify the color,brightness and scroll modes of the display|


# Usage

The following sections describe the expected inputs, outputs, configurations of each node as well as their functionality. Note: configurations are properties that can be set when double clicking on a node prior to deploying the flow.

## gpio-read

Reads the state of a specified gpio.

### Config

Pin: This is the number of the specific pin to be read.

### Input

Input is only necessary to trigger the node's action. The input's content does not affect the node's functionality.

### Output 

Returns the state of the pin in msg.payload.state as either a 1 for high or 0 for low.

## gpio-write

Sets the state of a specified gpio

### Config 

Pin: This is the number of the pin to be written to.

### Input

Contains the state of the gpio to be written in the form of msg.payload.state = 1 for high or msg.payload.state = 0 for low.

### Output

Returns the state that was written to the gpio in the form of msg.payload.state.

## relay-exp-read

Reads the state of a channel on a specified relay expansion

### Config

I2C Address: Corresponds to the address of the relay-expansion of interest, can be a value from 0 to 7

Channel: Refers to one of the two channels on a relay expansion, can be 0 or 1.

### Input 

Input is only necessary to trigger the node's action. The input's content does not affect the node's functionality.

### Output

Returns the relay's address, channel and state in msg.payload.

## relay-exp-write

Sets the state of a channel on a specified relay expansion.

### Config

I2C Address: Corresponds to the address of the relay-expansion of interest, can be a value from 0 to 7

Channel: Refers to one of the two channels on a relay expansion, can be 0 or 1.

### Input

Contains the state of the channel to be written in the form of msg.payload.state = 1 for closed or msg.payload.state = 0 for open.

### Output

Returns the relay's address, channel and state in msg.payload.

## pwm-exp

Sets a channel on the pwm expansion to a particular duty cycle.

### Config

Channel: The desired channel to be set

### Input:

Input the desired duty cycle in the form, msg.payload.dutyCycle = 0 to 100

### Output:

Return the input

## servo-exp

Used to control a servo motor connected to a specific channel on the pwm expansion.

### Config 

Channel: The channel number that the servo is connected to.

Min Pulse Width: The time in ms for the 0 deg position. Tune to specific motor.

Max Pulse Width: The time in ms for the 180 deg position. Tune to specfic motor.

### Input

Pass in the desired angle in the form msg.payload.angle = 0 to 180.

### Output

Returns the input

## oled-clear

Clears the Oled Display

### Config

None

### Input

Input is only necessary to trigger the node's action. The input's content does not affect the node's functionality.

### Output 

Returns the input

## oled-exp

### Config

None

### Input

Depending on the input passed the node will perform different funtions to the Oled display.

* In general the message to be written will be contained in msg.payload.msg = "Example Text".

* To clear the screen prior to writing define msg.payload.clear with anything.

* To scroll the display, define msg.payload.scroll with 'left'|'right'|'up-left'|'up-right'.

* To stop scrolling, define msg.payload.scroll with 'stop'.

* Color can be inverted by setting with msg.payload.invert with 'true'|'false'.

* Brightness can be set by defining msg.payload.dim with 'true'|'false'

### Output

Returns the input

