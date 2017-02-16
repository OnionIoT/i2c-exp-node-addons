var pwmAddon = require("/usr/bin/pwm-exp-addon");
var timeout = 3000;

var testDriverInit =  function () {
	var promise = new Promise ( function(resolve, reject) {
		setTimeout( () => {
			console.log("Initializing PWM Expansion");
			pwm.driverInit( () => {
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
			pwmAddon.setupDriver(0,50,0, () => {
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
			pwmAddon.setFrequency(60, () => {
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
			pwmAddon.disableChip( () => {
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

