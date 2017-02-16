var relayAddon = require("/usr/bin/relay-exp-addon");
var timeout = 3000;

var addr=0;

var testCheckInit =  function () {
	var promise = new Promise ( function(resolve, reject) {
		setTimeout( () => {
			console.log("Checking if Relay Expansion is initialized");
			relayAddon.checkInit(addr, () => {
				console.log("checked");
			});
			resolve();
		}, timeout);
	});
	return promise;
};

var testInit =  function () {
	var promise = new Promise ( function(resolve, reject) {
		setTimeout( () => {
			console.log("Initializing Relay Expansion");
			relayAddon.init(addr, () => {
				console.log("Relay Initialised");
			});
			resolve();
		}, timeout);
	});
	return promise;
};

var testSetChannelOff =  function () {
	var promise = new Promise ( function(resolve, reject) {
		setTimeout( () => {
			console.log("Setting Channel 0 to On");
			relayAddon.setChannel(addr,0,1, () => {
				console.log("Channel 0 on");
			});
			resolve();
		}, timeout);
	});
	return promise;
};

var testSetAllChannelsOn =  function () {
	var promise = new Promise ( function(resolve, reject) {
		setTimeout( () => {
			console.log("Setting Both Channels to On");
			relayAddon.setAllChannels(addr,1, () => {
				console.log("All channels on");
			});
			resolve();
		}, timeout);
	});
	return promise;
};

var testSetChannelOn =  function () {
	var promise = new Promise ( function(resolve, reject) {
		setTimeout( () => {
			console.log("Setting Channel 0 to Off");
			relayAddon.setChannel(addr,0,0, () => {
				console.log("Channel 0 off");
			});
			resolve();
		}, timeout);
	});
	return promise;
};

testCheckInit()
	.then(testInit)
	.then(testSetChannelOff)
	.then(testSetAllChannelsOn)
	.then(testSetChannelOn)
