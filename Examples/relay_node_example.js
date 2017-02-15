var relayAddon = require("/usr/bin/relay-exp-addon");

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

var addr=0;


//Wait 3 seconds,check Initialiation, should return 0 if the expansion has just been plugged in
functionList.push( () => {
console.log("Checking if Relay Expansion is initialized");
console.log("checkInit:",relayAddon.checkInit(addr));
});

//Wait 3 seconds,Initialize the relay-exp
functionList.push( () => {
console.log("Initializing Relay Expansion");
console.log("init:",relayAddon.init(addr));
});
//Wait 3 seconds, check the initializion, should return 1, since it was just initialized
functionList.push( () => {
console.log("Checking if Relay Expansion is initialized");
console.log("checkInit:",relayAddon.checkInit(addr));
});
//Wait 3 seconds, set Channel 0 to On
functionList.push( () => {
console.log("Setting Channel 0 to On");
console.log("setChannel:",relayAddon.setChannel(addr,0,1));
});
//Wait 3 seconds, set both channels to On
functionList.push( () => {
console.log("Setting Both Channels to On");
console.log("setAllChannel:",relayAddon.setAllChannels(addr,1));
});
//Wait 3 seconds, Set Channel 0 to Off
functionList.push( () => {
console.log("Setting Channel 0 to Off");
console.log("setChannel:",relayAddon.setChannel(addr,0,0));
});

functionList.push( () => {
console.log("Done!");
});

setInterval( () => {
	threeSeconds.emit('now'); 
}, timeout);
