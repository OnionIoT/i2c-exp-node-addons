var pwmExp = require("/usr/bin/node-pwm-exp");
var timeout = 3000;

var testDriverInit =  function () {
	var promise = new Promise ( function(resolve, reject) {
		setTimeout( () => {
			console.log("Initializing PWM Expansion");
			pwmExp.driverInit( () => {
				console.log("Initialization returned");
			});
			resolve();
		}, timeout);
	});
	return promise;
};

var testSetupDriver =  function () {
	var promise = new Promise ( function(resolve, reject) {
		setTimeout( () => {
			console.log("Setting Channel 0 to 50% Duty Cycle");
			pwmExp.setupDriver(0,50,0, () => {
				console.log("Driver succesfully set.");
			});
			resolve();
		}, timeout);
	});
	return promise;
};

var testSetFrequency =  function () {
	var promise = new Promise ( function(resolve, reject) {
		setTimeout( () => {
			console.log("Changing frequency.");
			pwmExp.setFrequency(60, () => {
				console.log("Frequency changed to 60Hz.");
			});
			resolve();
		}, timeout);
	});
	return promise;
};

var testDisableChip =  function () {
	var promise = new Promise ( function(resolve, reject) {
		setTimeout( () => {
			console.log("Disabling PWM chip.");
			pwmExp.disableChip( () => {
				console.log("PWM disabled.");
			});
			resolve();
		}, timeout);
	});
	return promise;
};

testDriverInit()
	.then(testSetFrequency)
	.then(testSetupDriver)
	.then(testDisableChip)
