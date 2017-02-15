var oledExp = require("/usr/bin/node-oled-exp");

const EventEmitter = require('events');
class timer extends EventEmitter {}
const threeSeconds = new timer();

var functionList = [];
var currFunction = 0;
var timeout = 3000;

threeSeconds.on('now', () => {
	functionList[currFunction]();
	currFunction++;
});

//Initialize
oledExp.init();

// write a character
functionList.push( () => {
    console.log("Writing a character to display");
    oledExp.writeChar("X");
});

// invert the colors

functionList.push( () => {
    oledExp.setDisplayMode(1);
});

// dim
functionList.push( () => {
    oledExp.setDim(1);
});

// clear the display
functionList.push( () => {
    console.log("Clearing the Display");
    oledExp.clear();
});
// write a message
functionList.push( () => {
    oledExp.write("Invent the Future");
});
// invert the colors to normal
functionList.push( () => {
    console.log("Inverting Display Back to Normal");
    oledExp.setDisplayMode(0);
});
// set the highest brightness
functionList.push( () => {
    console.log("Setting brightness mode to Brightest");
    oledExp.setBrightness(255);
});
// clear the display
functionList.push( () => {
    console.log("Clearing the Display");
    oledExp.clear();
});
// set the cursor by pixel
functionList.push( () => {
    console.log("Setting the pixel cursor");
    oledExp.setCursorByPixel(1,64);
});
// draw a few bytes
functionList.push( () => {
	console.log("Drawing a few bytes");
	oledExp.writeByte(0x0f);
	oledExp.writeByte(0xf0);
	oledExp.writeByte(0x0f);
	oledExp.writeByte(0xf0);
});
// set the cursor by pixel
functionList.push( () => {
    console.log("Setting the cursor by pixel");
    oledExp.setCursorByPixel(1,127);
});
// draw a few bytes
functionList.push(	() => {
	console.log("Drawing a few bytes");
	oledExp.writeByte(0x0f);
	oledExp.writeByte(0xf0);
	oledExp.writeByte(0x0f);
	oledExp.writeByte(0xf0);
});

functionList.push( () => {
    console.log("Done");
});

setInterval( () => {
	threeSeconds.emit('now'); 
}, timeout);
