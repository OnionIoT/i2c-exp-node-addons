var relayAddon = require("/usr/bin/relay-exp-addon");
module.exports = function(RED) {
    function RelayExpNodeWrite(config) {
        RED.nodes.createNode(this,config);
        relayAddon.init(config.address);
        var node = this;
        this.on('input', function(msg) {
            var result = relayAddon.setChannel(config.address,config.channel,msg.payload.state);
            var returnMsg = {};
            returnMsg.payload = {};
            if(result == 0){
                //Only returning an object with state info
                returnMsg.payload.state = msg.payload.state;
                returnMsg.payload.address = config.address;
                returnMsg.payload.channel = config.channel;
                node.send(returnMsg);
            } else{
                returnMsg.payload.state = msg.payload.state;
                returnMsg.payload.address = config.address;
                returnMsg.payload.channel = config.channel;
                returnMsg.payload.err = "Unable to write relay state";
                node.send(returnMsg);
            }
        });
    }
    RED.nodes.registerType("relay-exp-write",RelayExpNodeWrite);
}