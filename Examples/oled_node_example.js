var oledExp = require("/usr/bin/node-oled-exp");

var timeout = 3000;

//Initialize
oledExp.init();

var testWriteChar =  () => { 
	return new Promise ( function(resolve, reject) {
		setTimeout( () => {
			console.log("Writing a character to display");
			oledExp.writeChar("X");
			resolve();
		}, timeout);
	});
};

var testInvertDisplay =  () => { 
	return new Promise ( function(resolve, reject) {
		setTimeout( () => {
			oledExp.setDisplayMode(1);
			resolve();
		}, timeout);
	});
};

var testSetDim =  () => { 
	return new Promise ( function(resolve, reject) {
		setTimeout( () => {
			oledExp.setDim(1);
			resolve();
		}, timeout);
	});
};

var testClearDisplay =  () => { 
	return new Promise ( function(resolve, reject) {
		setTimeout( () => {
			console.log("Clearing the Display");
			oledExp.clear();
			resolve();
		}, timeout);
	});
};

var testWriteString =  () => { 
	return new Promise ( function(resolve, reject) {
		setTimeout( () => {
			oledExp.write("Invent the Future");
			resolve();
		}, timeout);
	});
};

var testUnInvertDisplay =  () => { 
	return new Promise ( function(resolve, reject) {
		setTimeout( () => {
			console.log("Inverting Display Back to Normal");
			oledExp.setDisplayMode(0);
			resolve();
		}, timeout);
	});
};

var testSetBrightest =  () => { 
	return new Promise ( function(resolve, reject) {
		setTimeout( () => {
			console.log("Setting brightness mode to Brightest");
			oledExp.setBrightness(255);
			resolve();
		}, timeout);
	});
};

var testCursorByPixel =  () => { 
	return new Promise ( function(resolve, reject) {
		setTimeout( () => {
			console.log("Setting the pixel cursor");
			oledExp.setCursorByPixel(1,64);
			resolve();
		}, timeout);
	});
};

var testWriteByte =  () => { 
	return new Promise ( function(resolve, reject) {
		setTimeout( () => {
			console.log("Drawing a few bytes");
			oledExp.writeByte(0x0f);
			oledExp.writeByte(0xf0);
			oledExp.writeByte(0x0f);
			oledExp.writeByte(0xf0);
			resolve();
		}, timeout);
	});
};

var testCursorByPixel2 =  () => { 
	return new Promise ( function(resolve, reject) {
		setTimeout( () => {
			console.log("Setting the cursor by pixel");
			oledExp.setCursorByPixel(1,127);
			resolve();
		}, timeout);
	});
};


testWriteChar()
	.then(testInvertDisplay)
	.then(testSetDim)
	.then(testClearDisplay)
	.then(testWriteString)
	.then(testUnInvertDisplay)
	.then(testSetBrightest)
	.then(testClearDisplay)
	.then(testCursorByPixel)
	.then(testWriteByte)
	.then(testCursorByPixel2)
	.then(testWriteByte)
	.then(() => { console.log('done'); });

