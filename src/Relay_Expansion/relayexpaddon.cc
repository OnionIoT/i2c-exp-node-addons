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
  int addr = args[0]->IntegerValue();
  int ret = relayDriverInit(addr);
  Local<Function> cb = Local<Function>::Cast(args[1]);
  const unsigned argc = 1;
  Local<Value> argv[argc] = { Number::New(isolate, ret) };
  cb->Call(Null(isolate), argc, argv);
  Local<Number> num = Number::New(isolate, ret);
  args.GetReturnValue().Set(num);
}


void checkInit(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int addr = args[0]->IntegerValue();
  int bInit;
  int ret = relayCheckInit(addr, &bInit);
  Local<Function> cb = Local<Function>::Cast(args[1]);
  const unsigned argc = 1;
  Local<Value> argv[argc] = { Number::New(isolate, bInit) };
  cb->Call(Null(isolate), argc, argv);
  Local<Number> num = Number::New(isolate, bInit);
  args.GetReturnValue().Set(num);
}

void getChannel(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int addr = args[0]->IntegerValue();
  int channel = args[1]->IntegerValue();
  Local<Function> cb = Local<Function>::Cast(args[2]);
  const unsigned argc = 1;
  int state;
  int ret = relayReadChannel(addr,channel,&state);
  Local<Value> argv[argc] = { Number::New(isolate, state) };
  cb->Call(Null(isolate), argc, argv);
  Local<Number> num = Number::New(isolate, state);
  args.GetReturnValue().Set(num);
}


void setChannel(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int addr = args[0]->IntegerValue();
  int channel = args[1]->IntegerValue();
  int state = args[2]->IntegerValue();
  Local<Function> cb = Local<Function>::Cast(args[3]);
  const unsigned argc = 1;
  int ret = relaySetChannel(addr,channel,state);
  Local<Value> argv[argc] = { Number::New(isolate, ret) };
  cb->Call(Null(isolate), argc, argv);
  Local<Number> num = Number::New(isolate, ret);
  args.GetReturnValue().Set(num);
}

void setAllChannels(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int addr = args[0]->IntegerValue();
  int state = args[1]->IntegerValue();
  Local<Function> cb = Local<Function>::Cast(args[2]);
  const unsigned argc = 1;
  int ret = relaySetAllChannels(addr,state);
  Local<Value> argv[argc] = { Number::New(isolate, ret) };
  cb->Call(Null(isolate), argc, argv);  
  Local<Number> num = Number::New(isolate, ret);
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
