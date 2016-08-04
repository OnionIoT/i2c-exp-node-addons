/**
 * PWM Expansion example
 * @license: GNU GPL (https://raw.githubusercontent.com/OnionIoT/i2c-exp-node-addons/master/LICENSE)
 *
 * Note that setTimeout function - asynchronous, and delay for it is counting
 * from the very beginning of the script's execution.
 */

// Use ES6
'use strict';

// Load module
const pwmAddon = require('/usr/bin/pwm-exp-addon');

/* Init PWM Expansion */
console.log('Initializing PWM Expansion..');

// Inir driver and check is it success
if (pwmAddon.driverInit()) {

  console.log('PWM Expansion initialized');

} else {

  console.error('Error while initializing PWM Expansion');

  // Stop script with error code
  process.exit(1);

}


/* Check Expansion */
setTimeout((() => {

  console.log('Checking, is PWM expansion initialized..');

  // Get expansion chip status
  if (pwmAddon.checkInit()) {

    console.log('PWM Expansion successfull checked up');

  } else {

    // Log error
    console.error('Error while PWM Expansion check');

    // Stop script with error code
    process.exit(1);

  }

}), 3000);


/* Set Channel value */
setTimeout((() => {

  console.log('Setting Channel 0 to 50% Duty Cycle..');
  pwmAddon.setupDriver(0, 50, 0); // Channel, Duty Cycle, Delay

}), 6000);


/* Change frequency */
setTimeout((() => {

  console.log('Changing PWM frequency to 60 Hz..');
  pwmAddon.setFrequency(60);

}), 9000);


/* Change Channel value */
setTimeout((() => {

  console.log('Setting Channel 0 to 100% Duty Cycle..');
  pwmAddon.setupDriver(0, 100, 0);

}), 12000);


/* Disable chip */
setTimeout((() => {

  console.log('Disabling chip and stopping oscillator..');
  pwmAddon.disableChip();

}), 15000);
