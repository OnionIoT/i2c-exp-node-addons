// relayexpaddon.cc
#include <node.h>
#include <v8.h>
#include <relay-exp.h>
#include <string>



namespace demo {
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
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
}


void checkInit(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int addr = args[0]->IntegerValue();
  int binit;
  int a = relayCheckInit(addr, &binit);
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
}
 


void setChannel(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int value1 = args[0]->IntegerValue();
  int value2 = args[1]->IntegerValue();
  int value3 = args[2]->IntegerValue();
  int a = relaySetChannel(value1,value2,value3);
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
	
}

void setAllChannels(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int value1 = args[0]->IntegerValue();
  int value2 = args[1]->IntegerValue();
  int a = relaySetAllChannels(value1,value2);
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "init", relayInit);
  NODE_SET_METHOD(exports, "checkInit", checkInit);
  NODE_SET_METHOD(exports, "setChannel", setChannel);
  NODE_SET_METHOD(exports, "setAllChannels", setAllChannels);

}
//This defines the entry point for the addon
NODE_MODULE(addon, init)

}  // namespace demo
