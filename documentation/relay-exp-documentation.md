# Relay Expanion Node Addon
The Onion Relay Node Addon, relay-node-addon is a wrapper around the libonionrelayexp dynmic C library that provides functions to setup and control the relay expansion. The same library is available for use in C and Python programs.


## Programming Flow
After each power-cycle, the chip that controls the Relay Expansion must be programmed with an initialization sequence. After the initialization, the relays can be turned on and off at will.

## I2C Device Address
The Relay Expansion is the only expansion that has a configurable I2C device address. This was done so that up to eight Relay Expansions can be stacked on a single Omega, giving the user the ability to control 16 relay modules independently.

The **base device address is 0x20**, the DIP switches control the offset added to the base address:

 * The 'Off' position for each switch is when the toggle is close to the numbers on the switch, or away from the relay modules.
 * The 'On' position is when the toggle is away from the numbers on the switch, or closer to the relay modules.

The table below defines the relationship:

|  Switch 1  |  Switch 2  |  Switch 3  |  I2C Device Address  |
|:----------:|:----------:|:----------:|:--------------------:|
|    Off     |    Off     |     Off    |         0x27         |
|    Off     |    Off     |   **On**   |         0x26         |
|    Off     |  **On**    |     Off    |         0x25         |
|    Off     |  **On**    |   **On**   |         0x24         |
|  **On**    |    Off     |     Off    |         0x23         |
|  **On**    |    Off     |   **On**   |         0x22         |
|  **On**    |  **On**    |     Off    |         0x21         |
|  **On**    |  **On**    |   **On**   |         0x20         |


All of the functions in this library will require an address argument that specifies the offset to add to the base address of **0x20**.


## Relay Module Select
Each relay expansion has two channel which can be called using binary values.

![imgur](https://i.imgur.com/Wk6Z9lW.png)


## Using the Addon
Install the addon into your project folder from our repo using opkg install.
```
opkg install relay_addon
```

### Importing the addon into your Node Script
To use the addon within your script you have to import it into your node program as you would a module:
```javascript
var relayAddon = require('./relay-node-addon');
```


### Calling Methods
Methods are called in the following format.

```javascript
relayAddon.method();
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
if (relayAddon.method()) {
  console.log('Execution successfull');
} else {
  console.error('Execution fault');
}
```


### Available Methods
Refer to the table below for a list and brief description of available relay methods.

|  Methods  |  Input  |  Description  |
|-----------|---------|---------------|
|  init(addr)       |**0 - 7**|  Initializes the selected relay expansion, relay states can be set after initialization.  |
|  checkInit(addr)  |**0 - 7**|  Checks initialization state of selected relay expansion.  |
|  setChannel(addr, channel, state)  | **0-7, 0-1, 0-1** |  Sets the selected channel on the selected relay to the specified states.  |
|  setAllChannels(addr, state)  |**0-7, 0-1**|  Sets all channels on the selected relay expansion to the specified state.  |


## Usage
Each of the main functions implemented inthis library are described below.

### Initialization Function
This function programs the initialization sequence on the Relay Expansion, after this step is completed, the functions to set the relay states can be used with success:
```javascript
relayAddon.init(addr)
```

#### Arguments
The addr argument is described above in the I2C Device Address section.

#### Examples
Initialize a Relay Expansion with all DIP switches set to 0, meaning the I2C device address will be 0x27:
```javascript
relayAddon.init(7);
```

Initialize with DIP switches set to on-off-on (device address: 0x22):
```javascript
relayAddon.init(2);
```

Initialize with DIP switches set to on-on-off (device address: 0x24):
```javascript
relayAddon.init(4);
```


-----
### Check for Initialization
This function performs several reads to determine if the Relay Expansion requires the initialization sequence to be programmed before the relay states can be changed.

```javascript
relayAddon.checkInit(addr);
```

#### Arguments
The addr argument is described above in the I2C Device Address section.

#### Example
Check if a Relay Expansion (with all DIP switches set to On) is initialized:

```javascript
if (relayAddon.checkInit(0)) {
  console.log('Relay Expansion with address 0x20 successfull initialized');
} else {
  console.log('Relay Expansion with address 0x20 is not initialized');
}
```


-----
### Set Relay State
Finally the fun stuff! Use this function to change the sate of the relay:
```javascript
relayAddon.setChannel(addr, channel, state);
```

#### Arguments
Function arguments described in table below.

|  Argument  |  Input                |  Meaning                                |
|------------|:---------------------:|-----------------------------------------|
| addr       |  **0 - 7**            |  I2C Device Address                     |
| channel    |  **0**, **1**         |  Relay channel                          |
| state      |  **0**, **1**         |  Relay state (**0** - Off, **1** - On)  |

#### Example
Let's turn Relay 0 **ON** and Relay 1 **OFF** (all DIP switches off)
```javascript
relayAddon.setChannel(7, 0, 1);
relayAddon.setChannel(7, 1, 0);
```


-----
### Set State for both Relays
In the event that both relays need to be turned on or off at the same time:
```javascript
relayAddon.setAllChannels(addr, state);
```
This is performed with a single register write so both relays should react at the same time.

#### Arguments
In a difference with setState function, this function doesn't require relay channel

|  Argument  |  Input                |  Meaning                                |
|------------|:---------------------:|-----------------------------------------|
| addr       |  **0 - 7**            |  I2C Device Address                     |
| state      |  **0**, **1**         |  Relay state (**0** - Off, **1** - On)  |

#### Example

All DIP switches are in Off position, turn both relays on, then turn Relay 0 off, the send a command to turn both off:
```javascript
relayAddon.setAllChannels(7, 1);
relayAddon.setChannel(7, 0, 0);
relayAddon.setAllChannels(7, 0);
```
