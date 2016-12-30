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


void relayInit(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int value = args[0]->IntegerValue();
  int a = relayDriverInit(value);
  Local<Function> cb = Local<Function>::Cast(args[1]);
  const unsigned argc = 1;
  Local<Value> argv[argc] = { Number::New(isolate, a) };
  cb->Call(Null(isolate), argc, argv);
  // Local<Number> num = Number::New(isolate, a);
  // args.GetReturnValue().Set(num);
}


void checkInit(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int addr = args[0]->IntegerValue();
  int binit;
  int a = relayCheckInit(addr, &binit);
  Local<Function> cb = Local<Function>::Cast(args[1]);
  const unsigned argc = 1;
  Local<Value> argv[argc] = { Number::New(isolate, binit) };
  cb->Call(Null(isolate), argc, argv);
  // Local<Number> num = Number::New(isolate, binit);
  // args.GetReturnValue().Set(num);
}

void getChannel(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int value1 = args[0]->IntegerValue();
  int value2 = args[1]->IntegerValue();
  Local<Function> cb = Local<Function>::Cast(args[2]);
  const unsigned argc = 1;
  int state;
  int a = relayReadChannel(value1,value2,&state);
  Local<Value> argv[argc] = { Number::New(isolate, a) };
  cb->Call(Null(isolate), argc, argv);
  // Local<Number> num = Number::New(isolate, state);
  // args.GetReturnValue().Set(num);
}


void setChannel(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int value1 = args[0]->IntegerValue();
  int value2 = args[1]->IntegerValue();
  int value3 = args[2]->IntegerValue();
  Local<Function> cb = Local<Function>::Cast(args[3]);
  const unsigned argc = 1;
  int a = relaySetChannel(value1,value2,value3);
  Local<Value> argv[argc] = { Number::New(isolate, a) };
  cb->Call(Null(isolate), argc, argv);
  // Local<Number> num = Number::New(isolate, a);
  // args.GetReturnValue().Set(num);
}

void setAllChannels(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int value1 = args[0]->IntegerValue();
  int value2 = args[1]->IntegerValue();
  Local<Function> cb = Local<Function>::Cast(args[2]);
  const unsigned argc = 1;
  int a = relaySetAllChannels(value1,value2);
  Local<Value> argv[argc] = { Number::New(isolate, a) };
  cb->Call(Null(isolate), argc, argv);  
  // Local<Number> num = Number::New(isolate, a);
  // args.GetReturnValue().Set(num);
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
