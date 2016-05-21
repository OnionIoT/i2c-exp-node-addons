var oledAddon = require("/usr/bin/oled-exp-addon");

//Initialize
oledAddon.init();
//wait 3 seconds, write a character
setTimeout(function(){console.log("Writing a character to display");
oledAddon.writeChar("X");},3000);
// wait 3 seconds, invert the colors
setTimeout(function(){oledAddon.setDisplayMode(1);},6000);
//wait 3 seconds, dim
setTimeout(function(){oledAddon.setDim(1);},9000);
// wait 3 seconds, clear the display
setTimeout(function(){
console.log("Clearing the Display");
oledAddon.clear();},12000);
//wait 3 seconds, write a message
setTimeout(function(){oledAddon.write("Invent the Future");},15000);
//wait 3 seconds, invert the colors to normal
setTimeout(function(){
console.log("Inverting Display Back to Normal");
oledAddon.setDisplayMode(0);},18000);
//wait 3 seconds, set the highest brightness
setTimeout(function(){
console.log("Setting brightness mode to Brightest");
oledAddon.setBrightness(255);},21000);
//wait 3 seconds, clear the display
setTimeout(function(){
console.log("Clearing the Display");
oledAddon.clear();},24000);
//wait 3 seconds, set the cursor by pixel
setTimeout(function(){
console.log("Setting the pixel cursor");
oledAddon.setCursorByPixel(1,64);},27000);
//wait 3 seconds, draw a few bytes
setTimeout(	function(){
	console.log("Drawing a few bytes");
	oledAddon.writeByte(0x0f);
	oledAddon.writeByte(0xf0);
	oledAddon.writeByte(0x0f);
	oledAddon.writeByte(0xf0);
	
			},30000);
//wait 3 seonds, set the cursor by pixel
setTimeout(function(){
console.log("Setting the cursor by pixel");
oledAddon.setCursorByPixel(1,127);},30000);
//wait 3 seconds, draw a few bytes
setTimeout(	function(){
	console.log("Drawing a few bytes");
	oledAddon.writeByte(0x0f);
	oledAddon.writeByte(0xf0);
	oledAddon.writeByte(0x0f);
	oledAddon.writeByte(0xf0);
	
			},33000);
			
setTimeout(function(){console.log("Done");},36000);

