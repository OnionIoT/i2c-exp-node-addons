var exec = require('child_process').exec;
module.exports = function(RED) {
    function gpioRead(config) {
        RED.nodes.createNode(this,config);
        var pin = config.pin;
        var node = this;
        var cmd1 = "gpioctl dirin "+pin;
        var cmd2 = "gpioctl get "+pin;
        exec(cmd1, function(error, stdout, stderr){
            return
        });
        var returnMsg = {};
        returnMsg.payload = {};
        returnMsg.payload.pin = pin;
        this.on('input', function(msg) {
            exec(cmd2, function(error, stdout, stderr){
                var outputMsg = new String(stdout);
                if(outputMsg.indexOf("HIGH") > -1){
                    returnMsg.payload.state = 1;
                    node.send(returnMsg);
                }else{
                    returnMsg.payload.state = 0;
                    node.send(returnMsg);
                }
            });
        });
    }
    RED.nodes.registerType("gpio-read",gpioRead);
}