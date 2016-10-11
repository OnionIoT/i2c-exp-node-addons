var oledAddon = require("/usr/bin/oled-exp-addon");

module.exports = function(RED) {
    function oledExpClear(config) {
        RED.nodes.createNode(this,config);
        //Initialize the oled-exp 
        oledAddon.init();
        console.log("This should only be displayed once");
        var node = this;
        this.on('input', function(msg) {
            oledAddon.clear();
            node.send(msg);
        });
    }
    RED.nodes.registerType("oled-exp-clear",oledExpClear);
}