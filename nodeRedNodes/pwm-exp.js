var pwmAddon = require("/usr/bin/pwm-exp-addon");
module.exports = function(RED) {
    function PwmNode(config) {
        RED.nodes.createNode(this,config);
        var channel = config.channel;
        if(channel == 'all'){
        	channel = -1;
        }
        var delay = 0;
        pwmAddon.driverInit();
        pwmAddon.setFrequency(50);
        var node = this;
        this.on('input', function(msg) {
            var dutyCycle = msg.payload.dutyCycle;
            pwmAddon.setupDriver(channel,dutyCycle,delay);
            node.send(msg);
        });
    }
    RED.nodes.registerType("pwm-exp",PwmNode);
}