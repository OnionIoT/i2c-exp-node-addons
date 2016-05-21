var relayAddon = require("/usr/bin/relay-exp-addon");

var addr=0;


//Wait 3 seconds,check Initialiation, should return 0 if the expansion has just been plugged in
setTimeout(function(){
console.log("Checking if Relay Expansion is initialized");
console.log("checkInit:",relayAddon.checkInit(addr));
},3000);
//Wait 3 seconds,Initialize the relay-exp
setTimeout(function(){
console.log("Initializing Relay Expansion");
console.log("init:",relayAddon.init(addr));
},6000);
//Wait 3 seconds, check the initializion, should return 1, since it was just initialized
setTimeout(function(){
console.log("Checking if Relay Expansion is initialized");
console.log("checkInit:",relayAddon.checkInit(addr));
},9000);
//Wait 3 seconds, set Channel 0 to On
setTimeout(function(){
console.log("Setting Channel 0 to On");
console.log("setChannel:",relayAddon.setChannel(addr,0,1));
},12000);
//Wait 3 seconds, set both channels to On
setTimeout(function(){
console.log("Setting Both Channels to On");
console.log("setAllChannel:",relayAddon.setAllChannels(addr,1));
},15000);
//Wait 3 seconds, Set Channel 0 to Off
setTimeout(function(){
console.log("Setting Channel 0 to Off");
console.log("setChannel:",relayAddon.setChannel(addr,0,0));
},18000);

setTimeout(function(){
console.log("Done!");
},21000);