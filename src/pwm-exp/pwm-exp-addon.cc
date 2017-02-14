// relayexpaddon.cc
#include <node.h>
#include <v8.h>
#include <pwm-exp.h>
#include <string>



namespace demo {
    
using v8::Null;
using v8::Function;
using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;


void checkInit(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    int bInit;
    int ret = pwmCheckInit(&bInit);
    Local<Function> cb = Local<Function>::Cast(args[0]);
    const unsigned argc = 1;
    Local<Value> argv[argc] = { Number::New(isolate, bInit) };
    cb->Call(Null(isolate), argc, argv);
    Local<Number> num = Number::New(isolate, bInit);
    args.GetReturnValue().Set(num);
}


void driverInit(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    int ret = pwmDriverInit();
    Local<Function> cb = Local<Function>::Cast(args[0]);
    const unsigned argc = 1;
    Local<Value> argv[argc] = { Number::New(isolate, ret) };
    cb->Call(Null(isolate), argc, argv);
    Local<Number> num = Number::New(isolate, ret);
    args.GetReturnValue().Set(num);
}


void disableChip(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    int ret = pwmDisableChip();
    Local<Function> cb = Local<Function>::Cast(args[0]);
    const unsigned argc = 1;
    Local<Value> argv[argc] = { Number::New(isolate, ret) };
    cb->Call(Null(isolate), argc, argv);
    Local<Number> num = Number::New(isolate, ret);
    args.GetReturnValue().Set(num);
}

void setFrequency(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    double frequency = args[0]->NumberValue();
    Local<Function> cb = Local<Function>::Cast(args[1]);
    const unsigned argc = 1;
    int ret = pwmSetFrequency(frequency);
    Local<Value> argv[argc] = { Number::New(isolate, ret) };
    cb->Call(Null(isolate), argc, argv);
    Local<Number> num = Number::New(isolate, ret);
    args.GetReturnValue().Set(num);

}
void setupDriver(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    int channel = args[0]->IntegerValue();
    double duty = args[1]->NumberValue();
    double delay = args[2]->NumberValue();
    Local<Function> cb = Local<Function>::Cast(args[3]);
    const unsigned argc = 1;
    int ret = pwmSetupDriver(channel,duty,delay);
    Local<Value> argv[argc] = { Number::New(isolate, ret) };
    cb->Call(Null(isolate), argc, argv);
    Local<Number> num = Number::New(isolate, ret);
    args.GetReturnValue().Set(num);

}

void init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "checkInit", checkInit);
    NODE_SET_METHOD(exports, "driverInit", driverInit);
    NODE_SET_METHOD(exports, "disableChip", disableChip);
    NODE_SET_METHOD(exports, "setFrequency", setFrequency);
    NODE_SET_METHOD(exports, "setupDriver", setupDriver);

}
//This defines the entry point for the addon
NODE_MODULE(addon, init)

}    // namespace demo
