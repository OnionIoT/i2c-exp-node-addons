// relayexpaddon.cc
#include <node.h>
#include <v8.h>
#include <relay-exp.h>
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
using v8::Boolean;


// NodeJS wrapper for C relayDriverInit() Function
//  arguments:
//    address - number - specifies I2C address offset for the Relay Expansion
//    callback - function (optional)
//  returns:
//    true - successfully initialized
//    false - initialization failed
void relayInit(const FunctionCallbackInfo<Value>& args) {
  //// read in the arguments
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
  int addr = args[0]->IntegerValue();

  // perform the C library operation
  int ret = relayDriverInit(addr);
  Local<Number> retVal = Number::New(isolate, ret);

  // handle (optional) callback argument
  if (args.Length() > 1) {
    // TODO: ensure cb is actually a function
    Local<Function> cb = Local<Function>::Cast(args[1]);
    const unsigned argc = 1;
    Local<Value> argv[argc] = { retVal };
    cb->Call(Null(isolate), argc, argv);
  }

  // return a value
  args.GetReturnValue().Set(retVal);
}


// NodeJS wrapper for C relayCheckInit() Function
//  arguments:
//    address - number - specifies I2C address offset for the Relay Expansion
//    callback - function (optional)
//  returns:
//    false - not initialized
//    true - initialized
void checkInit(const FunctionCallbackInfo<Value>& args) {
  //// read in the arguments
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
  int addr = args[0]->IntegerValue();

  // perform the C library operation
  int bInit;
  int ret = relayCheckInit(addr, &bInit);
  Local<Boolean> retVal = Boolean::New(isolate, bInit == 1 ? true : false );

  // handle (optional) callback argument
  if (args.Length() > 1) {
    Local<Function> cb = Local<Function>::Cast(args[1]);
    const unsigned argc = 1;
    Local<Value> argv[argc] = { retVal };
    cb->Call(Null(isolate), argc, argv);
  }

  // return a value
  args.GetReturnValue().Set(retVal);
}

void getChannel(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int addr = args[0]->IntegerValue();
  int channel = args[1]->IntegerValue();


  // handle (optional) callback argument
  if (args.Length() > 2) {
    Local<Function> cb = Local<Function>::Cast(args[2]);
    const unsigned argc = 1;
    Local<Value> argv[argc] = { Number::New(isolate, state) };
    cb->Call(Null(isolate), argc, argv);
  }
  int state;
  int ret = relayReadChannel(addr,channel,&state);
  Local<Number> num = Number::New(isolate, state);
  args.GetReturnValue().Set(num);
}


void setChannel(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int addr = args[0]->IntegerValue();
  int channel = args[1]->IntegerValue();
  int state = args[2]->IntegerValue();

  // handle (optional) callback argument
  if (args.Length() > 3) {
    Local<Function> cb = Local<Function>::Cast(args[3]);
    const unsigned argc = 1;
    Local<Value> argv[argc] = { Number::New(isolate, ret) };
    cb->Call(Null(isolate), argc, argv);
  }

  int ret = relaySetChannel(addr,channel,state);
  Local<Number> num = Number::New(isolate, ret);
  args.GetReturnValue().Set(num);
}

void setAllChannels(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int addr = args[0]->IntegerValue();
  int state = args[1]->IntegerValue();

  int ret = relaySetAllChannels(addr,state);

  // handle (optional) callback argument
  if (args.Length() > 2) {
    Local<Function> cb = Local<Function>::Cast(args[2]);
    const unsigned argc = 1;
    Local<Value> argv[argc] = { Number::New(isolate, ret) };
    cb->Call(Null(isolate), argc, argv);
  }

  args.GetReturnValue().Set(num);
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "init", relayInit);
  NODE_SET_METHOD(exports, "checkInit", checkInit);
  NODE_SET_METHOD(exports, "setChannel", setChannel);
  NODE_SET_METHOD(exports, "setAllChannels", setAllChannels);
  NODE_SET_METHOD(exports, "getChannel", getChannel);
}
//This defines the entry point for the addon
NODE_MODULE(addon, init)

}  // namespace demo
