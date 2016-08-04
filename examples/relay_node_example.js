/**
 * Relay Expansion example
 * @license: GNU GPL (https://raw.githubusercontent.com/OnionIoT/i2c-exp-node-addons/master/LICENSE)
 *
 * Note that setTimeout function - asynchronous, and delay for it is counting
 * from the very beginning of the script's execution.
 */

// Use ES6
'use strict';

// Load addon
const relayAddon = require('/usr/bin/relay-exp-addon');

// Expansion address (0x2?)
// Based on DIP switch positions
// Equals to 0 if all switches set to On
const addr = 0;

/* Initializing */
console.log('Initializing Relay Expansion..');

if (relayAddon.init(addr)) {

  console.log('Relay Expansion successfull initialized');

} else {

  // Log error
  console.error('Error while initializing Relay Expansion');

  // Stop script with error code
  process.exit(1);

}


/* Checking */
setTimeout((() => {

  console.log('Checking Relay Expansion..');

  if (relayAddon.checkInit(addr)) {

    console.log('Relay Expansion successfull checked up');

  } else {

    // Log error
    console.error('Error while Relay Expansion check');

    // Stop script with error code
    process.exit(1);

  }

}), 3000);


/* Switch Channel 0 to On */
setTimeout((() => {

  console.log('Switching Channel 0 to On..');
  relayAddon.setChannel(addr, 0, 1); // Address, Channel, State

}), 6000);


/* Switching both Channels to On */
setTimeout((() => {

  console.log('Switching both Channels to On..');
  relayAddon.setAllChannels(addr, 1);

}), 9000);


/* Switching Channel 0 to Off */
setTimeout((() => {

  console.log('Switching Channel 0 to Off..')
  relayAddon.setChannel(addr, 0, 0);

}), 12000);


/* Switching Channel 1 to Off */
setTimeout((() => {

  console.log('Switching Channel 1 to Off..');
  relayAddon.setChannel(addr, 1, 0);

  // Everything done
  console.log('Done.')

}), 15000);
