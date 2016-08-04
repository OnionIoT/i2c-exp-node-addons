// oledexpnodeaddon.cc
#include <node.h>
#include <v8.h>
#include <oled-exp.h>
#include <string>


char 	*param;
uint8_t	*buffer;



namespace demo {
using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;

//Initializing and Clearing

void oledInit(const FunctionCallbackInfo<Value>& args) {
  //Add init oled-display here
  Isolate* isolate = args.GetIsolate();
  int a = oledDriverInit();
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);

}

void checkInit(const FunctionCallbackInfo<Value>& args) {
  //Add checkinit oled-display here
  Isolate* isolate = args.GetIsolate();
  int a = oledCheckInit();
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);

}

void clear(const FunctionCallbackInfo<Value>& args) {
  //Add clear oled-display here
  Isolate* isolate = args.GetIsolate();
  int a = oledClear();
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);

}

//Configuration
void setDisplayPower(const FunctionCallbackInfo<Value>& args) {
  //Add set-display-power here
  Isolate* isolate = args.GetIsolate();
  int value = args[0]->IntegerValue();
  int a = oledSetDisplayPower(value);
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
}

void setDisplayMode(const FunctionCallbackInfo<Value>& args) {
  //Add set-display-mode here
  Isolate* isolate = args.GetIsolate();
  int value = args[0]->IntegerValue();
  int a = oledSetDisplayMode(value);
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
}

void setBrightness(const FunctionCallbackInfo<Value>& args) {
  //Add set-brightness here
  Isolate* isolate = args.GetIsolate();
  int value = args[0]->IntegerValue();
  int a = oledSetBrightness(value);
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
}
void setDim(const FunctionCallbackInfo<Value>& args) {
  //Add set-Dim here
  Isolate* isolate = args.GetIsolate();
  int value = args[0]->IntegerValue();
  int a = oledSetDim(value);
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
}
void setMemoryMode(const FunctionCallbackInfo<Value>& args) {
  //Add set-Memory-Mode here
  Isolate* isolate = args.GetIsolate();
  int value = args[0]->IntegerValue();
  int a = oledSetMemoryMode(value);
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
}
void setCursor(const FunctionCallbackInfo<Value>& args) {
  //Add set-Cursor here
  Isolate* isolate = args.GetIsolate();
  int value1 = args[0]->IntegerValue();
  int value2 = args[1]->IntegerValue();
  int a = oledSetCursor(value1,value2);
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
}
void setCursorByPixel(const FunctionCallbackInfo<Value>& args) {
  //Add set-CursorByPixel here
  Isolate* isolate = args.GetIsolate();
  int value1 = args[0]->IntegerValue();
  int value2 = args[1]->IntegerValue();
  int a = oledSetCursorByPixel(value1,value2);
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
}
void setColumnAddressing(const FunctionCallbackInfo<Value>& args) {
  //Add set-ColumnAddressing here
  Isolate* isolate = args.GetIsolate();
  int value1 = args[0]->IntegerValue();
  int value2 = args[1]->IntegerValue();
  int a = oledSetColumnAddressing(value1,value2);
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
}
void setTextColumns(const FunctionCallbackInfo<Value>& args) {
  //Add setTextColumns here
  Isolate* isolate = args.GetIsolate();
  int a = oledSetTextColumns();
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
}
void setImageColumns(const FunctionCallbackInfo<Value>& args) {
  //Add setImageColumns here
  Isolate* isolate = args.GetIsolate();
  int a = oledSetImageColumns();
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
}

//writing to the display

void writeChar(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  v8::String::Utf8Value s(args[0]);
  std::string str(*s);
  char * writable = new char[str.size() + 1];
  std::copy(str.begin(), str.end(), writable);
  writable[str.size()] = '\0';
  int a = oledWriteChar(*writable);
  Local<Number> num = Number::New(isolate, a);
  delete[] writable;
  args.GetReturnValue().Set(num);
}
void write(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  v8::String::Utf8Value s(args[0]);
  std::string str(*s);
  char * writable = new char[str.size() + 1];
  std::copy(str.begin(), str.end(), writable);
  writable[str.size()] = '\0';
  int a = oledWrite(writable);
  Local<Number> num = Number::New(isolate, a);
  delete[] writable;
  args.GetReturnValue().Set(num);
}

void writeByte(const FunctionCallbackInfo<Value>& args) {
  //Add set-Memory-Mode here
  Isolate* isolate = args.GetIsolate();
  int value = args[0]->IntegerValue();
  int a = oledWriteByte(value);
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
}
/**
 *void draw(const FunctionCallbackInfo<Value>& args) {
 *  Isolate* isolate = args.GetIsolate();
 *  v8::String::Utf8Value s(args[0]);
 *  std::string str(*s);
 *  char * writable = new char[str.size() + 1];
 *  std::copy(str.begin(), str.end(), writable);
 *  writable[str.size()] = '\0';
 *  buffer 	= malloc(OLED_EXP_WIDTH*OLED_EXP_HEIGHT/8 * sizeof *buffer);
 *}
 */


//scroll the display

void scroll(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int value1 = args[0]->IntegerValue();
  int value2 = args[1]->IntegerValue();
  int value3 = args[2]->IntegerValue();
  int value4 = args[3]->IntegerValue();
  int a = oledScroll(value1,value2,value3,value4);
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
}
void scrollDiagonal(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int value1 = args[0]->IntegerValue();
  int value2 = args[1]->IntegerValue();
  int value3 = args[2]->IntegerValue();
  int value4 = args[3]->IntegerValue();
  int value5 = args[4]->IntegerValue();
  int value6 = args[5]->IntegerValue();
  int value7 = args[6]->IntegerValue();
  int a = oledScrollDiagonal(value1,value2,value3,value4,value5,value6,value7);
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
}
void scrollStop(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int a = oledScrollStop();
  Local<Number> num = Number::New(isolate, a);
  args.GetReturnValue().Set(num);
}

//reading lcd data

void readLcdFile(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = args.GetIsolate();
	//buffer is a global variable and path is passed in as a string
	buffer 	= (uint8_t*)malloc(OLED_EXP_WIDTH*OLED_EXP_HEIGHT/8 * sizeof *buffer);
	v8::String::Utf8Value s(args[0]);
	std::string str(*s);
	char * writable = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), writable);
	writable[str.size()] = '\0';
	int status=oledReadLcdFile(writable,buffer);
	if (status == EXIT_SUCCESS) {
			status	= oledDraw(buffer, OLED_EXP_WIDTH*OLED_EXP_HEIGHT/8);
		}
		else {
			printf("ERROR: Cannot draw invalid data\n");
		}

		// deallocate mZZZZZZemory for the buffer
		if (buffer != NULL) {
			printf("> Deallocating buffer array\n");
			free(buffer);
		}
	delete[] writable;
	Local<Number> num = Number::New(isolate, status);
    args.GetReturnValue().Set(num);

}

void readLcdData(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = args.GetIsolate();
	//buffer is a global variable and path is passed in as a string
	buffer 	=(uint8_t*)malloc(OLED_EXP_WIDTH*OLED_EXP_HEIGHT/8 * sizeof *buffer);
	v8::String::Utf8Value s(args[0]);
	std::string str(*s);
	char * writable = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), writable);
	writable[str.size()] = '\0';
	int status=oledReadLcdData(writable,buffer);
	if (status == EXIT_SUCCESS) {
			status	= oledDraw(buffer, OLED_EXP_WIDTH*OLED_EXP_HEIGHT/8);
		}
		else {
			printf( "ERROR: Cannot draw invalid data\n");
		}

		// deallocate memory for the buffer
		if (buffer != NULL) {
			printf("> Deallocating buffer array\n");
			free(buffer);
		}
	delete[] writable;
	Local<Number> num = Number::New(isolate, status);
	args.GetReturnValue().Set(num);

}

void init(Local<Object> exports) {
//This function defines the functions that are going to be exposed to node.js
//Functions
 // NODE_SET_METHOD(exports, "oledSendCommand", oledInit); May not need this command
//initializing and clearing
  NODE_SET_METHOD(exports, "init", oledInit);
  NODE_SET_METHOD(exports, "checkInit", checkInit);
  NODE_SET_METHOD(exports, "clear", clear);

//configuration
  NODE_SET_METHOD(exports, "setDisplayPower", setDisplayPower);
  NODE_SET_METHOD(exports, "setDisplayMode", setDisplayMode);
  NODE_SET_METHOD(exports, "setBrightness", setBrightness);
  NODE_SET_METHOD(exports, "setDim", setDim);
  NODE_SET_METHOD(exports, "setMemoryMode", setMemoryMode);
  NODE_SET_METHOD(exports, "setCursor", setCursor);
  NODE_SET_METHOD(exports, "setCursorByPixel", setCursorByPixel);
  NODE_SET_METHOD(exports, "setColumnAddressing", setColumnAddressing);
  NODE_SET_METHOD(exports, "setTextColumns", setTextColumns);
  NODE_SET_METHOD(exports, "setImageColumns", setImageColumns);

//writing to the display
  NODE_SET_METHOD(exports, "writeChar", writeChar);
  NODE_SET_METHOD(exports, "write", write);
  NODE_SET_METHOD(exports, "writeByte", writeByte);
  //NODE_SET_METHOD(exports, "draw", draw);
//scroll the display
  NODE_SET_METHOD(exports, "scroll", scroll);
  NODE_SET_METHOD(exports, "scrollDiagonal", scrollDiagonal);
  NODE_SET_METHOD(exports, "scrollStop", scrollStop);
//reading lcd data
  NODE_SET_METHOD(exports, "readLcdFile", readLcdFile);
  NODE_SET_METHOD(exports, "readLcdData", readLcdData);

}
//This defines the entry point for the addon
NODE_MODULE(addon, init)

}  // namespace demo
