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

    // perform the C library operation
    int bInit;
    int ret = pwmCheckInit(&bInit);
    Local<Number> retVal = Number::New(isolate, bInit);

    // handle (optional) callback argument
    if (args.Length() > 1) {
        Local<Function> callback = Local<Function>::Cast(args[0]);
        const unsigned argc = 1;
        Local<Value> argv[argc] = { Number::New(isolate, bInit) };
        callback->Call(Null(isolate), argc, argv);
    }

    args.GetReturnValue().Set(retVal);
}


void driverInit(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // perform the C library operation
    int ret = pwmDriverInit();
    Local<Number> retVal = Number::New(isolate, ret);

    // handle (optional) callback argument
    if (args.Length() > 0) {
        Local<Function> callback = Local<Function>::Cast(args[0]);
        const unsigned argc = 1;
        Local<Value> argv[argc] = { retVal };
        callback->Call(Null(isolate), argc, argv);
    }
    args.GetReturnValue().Set(retVal);
}


void disableChip(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // perform the C library operation
    int ret = pwmDisableChip();
    Local<Number> retVal = Number::New(isolate, ret);

    // handle (optional) callback argument
    if (args.Length() > 0) {
        Local<Function> callback = Local<Function>::Cast(args[0]);
        const unsigned argc = 1;
        Local<Value> argv[argc] = { retVal };
        callback->Call(Null(isolate), argc, argv);
    }

    args.GetReturnValue().Set(retVal);
}

void setFrequency(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    double frequency = args[0]->NumberValue();

    // perform the C library operation
    int ret = pwmSetFrequency(frequency);
    Local<Number> retVal = Number::New(isolate, ret);

    // handle (optional) callback argument
    if (args.Length() > 1) {
        Local<Function> callback = Local<Function>::Cast(args[1]);
        const unsigned argc = 1;
        Local<Value> argv[argc] = { retVal };
        callback->Call(Null(isolate), argc, argv);
    }

    args.GetReturnValue().Set(retVal);

}
void setupDriver(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    int channel = args[0]->IntegerValue();
    double duty = args[1]->NumberValue();
    double delay = args[2]->NumberValue();

    // perform the C library operation
    int ret = pwmSetupDriver(channel,duty,delay);
    Local<Number> retVal = Number::New(isolate, ret);

    // handle (optional) callback argument
    if (args.Length() > 1) {
        Local<Function> callback = Local<Function>::Cast(args[3]);
        const unsigned argc = 1;
        Local<Value> argv[argc] = { retVal };
        callback->Call(Null(isolate), argc, argv);
    }

    args.GetReturnValue().Set(retVal);

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
