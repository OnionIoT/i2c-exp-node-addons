var pwmAddon = require("/usr/bin/pwm-exp-addon");

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

//Check initialization, Should return 0 if PWM Expansion has just been plugged in

//setTimeout(function(){
//console.log("Checking if PWM Expansion is initialized");
//console.log("checkInit:",pwmAddon.checkInit());
//},3000);


// initialize the expansion
functionList.push( () => {
console.log("Initializing Relay Expansion");
console.log("driverInit:",pwmAddon.driverInit());
});

// check initialization, should return 1 since the expansion was just initializaed above. 
//setTimeout(function(){
//console.log("Checking if PWM Expansion is initialized");
//console.log("checkInit:",pwmAddon.checkInit());
//},9000);

// set channel 0 
functionList.push( () => {
console.log("Setting Channel 0 t0 50% Duty Cycle");
console.log("setupDriver:",pwmAddon.setupDriver(0,50,0));
});
// change the frequency
functionList.push( () => {
console.log("Change the frequency");
console.log("setFrequency:",pwmAddon.setFrequency(60));
});
// set channel 0
functionList.push( () => {
console.log("Setting Channel 0 to 100% Duty Cycle");
console.log("setupDriver:",pwmAddon.setupDriver(0,100,0));
});

setInterval( () => {
	threeSeconds.emit('now'); 
}, timeout);
