var oledAddon = require("/usr/bin/oled-exp-addon");

// var clearDisplay = function(callback){

// }

module.exports = function(RED) {
    function oledExp(config) {
        RED.nodes.createNode(this,config);
        //Initialize the oled-exp 
        oledAddon.init();
        console.log("This should only be displayed once");
        var node = this;
        this.on('input', function(msg) {
            if(msg.payload.clear){
                oledAddon.clear();
            }
            if(msg.payload.msg){
                oledAddon.write(msg.payload.msg);
            }
            if(msg.payload.scroll){
                //Support left,right,up-left,up-right, as arguments
                if(msg.payload.scroll == 'left'){
                    oledAddon.scroll(0,0,0,7);
                }else if(msg.payload.scroll == 'right'){
                    oledAddon.scroll(1,0,0,7);
                }else if(msg.payload.scroll == 'up-left'){
                    oledAddon.scrollDiagonal(0,5,0,127,1,0,7);
                }else if(msg.payload.scroll == 'up-right'){
                    oledAddon.scrollDiagonal(1,5,0,127,1,0,7);
                }else{
                    console.log("Unrecognized scroll parameter, expected left||right||up-left||up-right");
                }
            }
            if(msg.payload.dim){
                // 0 or 1
                if((msg.payload.dim == 1) || (msg.payload.dim == 0)){
                    oledAddon.setDim(msg.payload.dim);
                }else{
                    console.log("Unrecognized dim parameter, expected 1 or 0");
                }
            }
            if(msg.payload.invert){
                // 0 or 1
                if((msg.payload.invert == 1) || (msg.payload.invert == 0)){
                    oledAddon.setDisplayMode(msg.payload.invert);
                } else{
                    console.log("Unrecognized dim parameter, expected 1 or 0");
                }
            }
            node.send(msg);
        });
    }
    RED.nodes.registerType("oled-exp",oledExp);
}