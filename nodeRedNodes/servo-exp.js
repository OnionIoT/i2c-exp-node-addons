var servoAddon = require("/usr/bin/pwm-exp-addon");

var getTime = function(t1,t2,y1,y2,y){
    var m = (y2-y1)/(t2-t1);
    var b = y2-m*t2;
    var t = y/m - b/m;
    // t = (y*(t1-t0)/(y1-y0)) -y1 +((y1-y0)/(t1-t0))*t1;
    return t;
}

var timeToDuty = function(highTime, frequency){
    period = 1/frequency;
    duty = highTime/period * 100;
    return duty;
}


module.exports = function(RED) {
    function servoNode(config) {
        RED.nodes.createNode(this,config);
        var channel = config.channel;
        if(channel == 'all'){
        	channel = -1;
        }
        var t0 = config.t0;
        t0 = t0 * .001;
        console.log("t0 is:",t0);
        var t180 = config.t180;
        t180 = t180 * .001;
        console.log("t180 is:",t180);
        var delay = 0;
        servoAddon.driverInit();
        servoAddon.setFrequency(50);
        var node = this;
        this.on('input', function(msg) {
            var angle = msg.payload.angle;
            console.log("angle is:",angle);
            var onTime = getTime(t0,t180,0,180,angle);
            console.log("OnTime is:",onTime);
            var dutyCycle = timeToDuty(onTime,50);
            servoAddon.setupDriver(channel,dutyCycle,delay);
            node.send(msg);
        });
    }
    RED.nodes.registerType("servo-exp",servoNode);
}