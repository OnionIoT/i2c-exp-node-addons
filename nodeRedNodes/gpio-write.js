var exec = require('child_process').exec;
module.exports = function(RED) {
    function gpioWrite(config) {
        RED.nodes.createNode(this,config);
        var pin = config.pin;
        var node = this;
        var cmd1 = "gpioctl dirout-low "+pin;
        var cmd2 = "gpioctl dirout-high "+pin;
        exec(cmd1, function(error, stdout, stderr){
            return
        });
        var returnMsg = {};
        returnMsg.payload = {};
        returnMsg.payload.pin = pin;
        this.on('input', function(msg) {
            returnMsg.payload.state = msg.payload.state;
            console.log(msg);
            if(msg.payload.state == 0){
                exec(cmd1, function(error, stdout, stderr){
                    node.send(returnMsg);
                });
            } else{
                exec(cmd2, function(error, stdout, stderr){
                    node.send(returnMsg);
                });                
            }
        });
    }
    RED.nodes.registerType("gpio-write",gpioWrite);
}