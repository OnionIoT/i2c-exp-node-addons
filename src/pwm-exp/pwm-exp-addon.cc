// pwm-exp-addon.cc
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


// NodeJS wrapper for C pwmCheckInit() Function
//  arguments:
//    callback - function (optional)
//  returns:
//    true - PWM expansion has started
//    false - expansion has not started
void checkInit(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // perform the C library operation
    int bInit;
    int ret = pwmCheckInit(&bInit);
    Local<Number> retVal = Number::New(isolate, bInit);

    // handle (optional) callback argument
    if (args.Length() > 0) {
        Local<Function> callback = Local<Function>::Cast(args[0]);
        const unsigned argc = 1;
        Local<Value> argv[argc] = { retVal };
        callback->Call(Null(isolate), argc, argv);
    }

    args.GetReturnValue().Set(retVal);
}


// NodeJS wrapper for C pwmDriverInit() Function
//  arguments:
//    callback - function (optional)
//  returns:
//    true - PWM initialisation successful
//    false - initialisation failed
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


// NodeJS wrapper for C pwmDisableChip() Function
//  arguments:
//    callback - function (optional)
//  returns:
//    true - PWM successfully disabled
//    false - PWM unable to be disabled
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


// NodeJS wrapper for C pwmSetFrequency() Function
//  arguments:
//    frequency - double - the desired frequency to be set
//    callback - function (optional)
//  returns:
//    true - relay state is on
//    false - relay is off
void setFrequency(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() < 1) {
        // Throw an Error that is passed back to JavaScript
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
    }

    // Check the argument types
    if (!args[0]->IsNumber()) {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong argument type")));
        return;
    }

    // read in the value arguments
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


// NodeJS wrapper for C pwmSetupDriver() Function
//  arguments:
//    channel - integer - specifies which a single channel to driver
//    duty - double - the duty cycle in percent to set the channel to
//    delay - double - the delay in percent in a cycle before the output raises to HIGH
//    callback - function (optional)
//  returns:
//    true - relay state is on
//    false - relay is off
void setupDriver(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() < 2) {
        // Throw an Error that is passed back to JavaScript
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong number of arguments")));
        return;
    }

    // Check the argument types
    if (!args[0]->IsNumber() ||
        !args[1]->IsNumber() ||
        !args[2]->IsNumber()) {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong argument type")));
        return;
    }

    // read in the value arguments
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
