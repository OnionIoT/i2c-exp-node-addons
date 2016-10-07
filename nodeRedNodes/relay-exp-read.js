var relayAddon = require("/usr/bin/relay-exp-addon");
module.exports = function(RED) {
    function RelayExpNodeRead(config) {
        RED.nodes.createNode(this,config);
        relayAddon.init(config.address);
        var node = this;
        this.on('input', function(msg) {
            var result = relayAddon.getChannel(config.address,config.channel);
            var returnMsg = {};
            returnMsg.payload = {};
            returnMsg.payload.state = result;
            returnMsg.payload.address = config.address;
            returnMsg.payload.channel = config.channel;
            node.send(returnMsg);
        });
    }
    RED.nodes.registerType("relay-exp-read",RelayExpNodeRead);
}