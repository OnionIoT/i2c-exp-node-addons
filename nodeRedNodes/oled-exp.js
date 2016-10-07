var oledAddon = require("/usr/bin/oled-exp-addon");

module.exports = function(RED) {
    function oledExp(config) {
        RED.nodes.createNode(this,config);
        //Initialize the oled-exp 
        oledAddon.init();
        var node = this;
        this.on('input', function(msg) {
            oledAddon.write(msg.payload.msg)
            node.send(msg)
        });
    }
    RED.nodes.registerType("oled-exp",oledExp);
}