/**
 * Onion I2C OLED display example
 * @license: GNU GPL (https://raw.githubusercontent.com/OnionIoT/i2c-exp-node-addons/master/LICENSE)
 *
 * Note that setTimeout function - asynchronous, and delay for it is counting
 * from the very beginning of the script's execution.
 */

// Use ES6
'use strict';

// Load module
const oledAddon = require('/usr/bin/oled-exp-addon');

// Initialize display
console.log('Initializing Display..');

if (oledAddon.init()) {

  console.log('Display initialized');

} else {

  // Log error
  console.error('Error while Display initializing');

  // Stop script with error code
  process.exit(1);

}

// Wait three seconds and write single 'X' character
setTimeout(() => {

  console.log('Printing "X" character on display...');
  oledAddon.writeChar('X');

}, 3000);


// Wait another three seconds, and invert display colors
setTimeout(() => {

  console.log('Invert display colors...');
  oledAddon.setDisplayMode(1);

}, 6000);


// After that - dim screen brightness
setTimeout(() => {

  console.log('Dim screen brightness...');
  oledAddon.setDim(1);

}, 9000);

// Clear display
setTimeout(() => {

  console.log('Clearing display...');
  oledAddon.clear();

}, 12000);

// Write another message on cleared screen
setTimeout(() => {

  console.log('Printing "Invent the Future" on display...');
  oledAddon.write("Invent the Future");

}, 15000);

// Invert colors one more time (back to normal)
setTimeout(() => {

  console.log('Inverting display\'s colors back to normal...');
  oledAddon.setDisplayMode(0);

}, 18000);

// Set maximum (255) brightness level
setTimeout(() => {

  console.log('Setting brightness up to maximum...');
  oledAddon.setBrightness(255);

}, 21000);

// Clear display
setTimeout(() => {

  console.log('Clearing display...');
  oledAddon.clear();

}, 24000);

// Set cursor position by pixel (second page and middle row)
setTimeout(() => {

  console.log('Setting the pixel cursor at Page #1 and Segment #64...');
  oledAddon.setCursorByPixel(1, 64);

} ,27000);

// Draw few segments (from segment #64 to segment #67)
setTimeout(() => {

  console.log('Drawing segments like this:');
  process.stdout.write('\n');
  process.stdout.write('BIT 0   . X . X\n');
  process.stdout.write('BIT 1   . X . X\n');
  process.stdout.write('BIT 2   . X . X\n');
  process.stdout.write('BIT 3   . X . X\n');
  process.stdout.write('BIT 4   X . X .\n');
  process.stdout.write('BIT 5   X . X .\n');
  process.stdout.write('BIT 6   X . X .\n');
  process.stdout.write('BIT 7   X . X .\n');
  process.stdout.write('\n');
  process.stdout.write('SEG 6x  4 5 6 7\n\n');

  console.log('Writing segment #64...');
	oledAddon.writeByte(0x0f);

  console.log('Writing segment #65...');
	oledAddon.writeByte(0xf0);

  console.log('Writing segment #66...');
	oledAddon.writeByte(0x0f);

  console.log('Writing segment #67...');
	oledAddon.writeByte(0xf0);

}, 30000);

// Move cursor to latest segment of page #1
setTimeout(() => {

  console.log('Setting the pixel cursor at Page #1 and Segment #127...');
  oledAddon.setCursorByPixel(1, 127);

}, 33000);

// Draw same pattern
setTimeout(() => {

	console.log("Drawing same pattern, but now at last segment of the page...");
	oledAddon.writeByte(0x0f);
	oledAddon.writeByte(0xf0);
	oledAddon.writeByte(0x0f);
	oledAddon.writeByte(0xf0);

  console.log('Done.');
  process.exit(0);

}, 36000);
