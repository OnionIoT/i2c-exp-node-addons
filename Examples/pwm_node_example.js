var pwmAddon = require("/usr/bin/pwm-exp-addon");

//Wait 3 Seconds,Check initialization, Should return 0 if PWM Expansion has just been plugged in

setTimeout(function(){
console.log("Checking if PWM Expansion is initialized");
console.log("checkInit:",pwmAddon.checkInit());
},3000);


//Wait 3 Seconds, initialize the expansion
setTimeout(function(){
console.log("Initializing Relay Expansion");
console.log("driverInit:",pwmAddon.driverInit());
},6000);

//Wait 3 seconds, check initialization, should return 1 since the expansion was just initializaed above. 
setTimeout(function(){
console.log("Checking if PWM Expansion is initialized");
console.log("checkInit:",pwmAddon.checkInit());
},9000);
//Wait 3 seconds, set channel 0 
setTimeout(function(){
console.log("Setting Channel 0 t0 50% Duty Cycle");
console.log("setupDriver:",pwmAddon.setupDriver(0,50,0));
},12000);
//Wait 3 seconds, change the frequency
setTimeout(function(){
console.log("Change the frequency");
console.log("setFrequency:",pwmAddon.setFrequency(60));
},15000);
//Wait 3 seconds, set channel 0
setTimeout(function(){
console.log("Setting Channel 0 to 100% Duty Cycle");
console.log("setupDriver:",pwmAddon.setupDriver(0,100,0));
},18000);