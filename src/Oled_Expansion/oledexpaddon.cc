// oledexpnodeaddon.cc
#include <node.h>
#include <v8.h>
#include <oled-exp.h>
#include <string>


char 	*param;
uint8_t	*buffer;



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

//Initializing and Clearing

void oledInit(const FunctionCallbackInfo<Value>& args) {
	//Add init oled-display here
	Isolate* isolate = args.GetIsolate();
	int ret = oledDriverInit();

	Local<Function> callback = Local<Function>::Cast(args[0]);
	const unsigned argc = 1;
	Local<Value> argv[argc] = { Number::New(isolate, ret) };
	cb->Call(Null(isolate), argc, argv);

	Local<Number> num = Number::New(isolate, ret);
	args.GetReturnValue().Set(num);
}

void checkInit(const FunctionCallbackInfo<Value>& args) {
	//Add checkinit oled-display here
	Isolate* isolate = args.GetIsolate();
	int ret = oledCheckInit();

	Local<Function> callback = Local<Function>::Cast(args[0]);
	const unsigned argc = 1;
	Local<Value> argv[argc] = { Number::New(isolate, ret) };
	callback->Call(Null(isolate), argc, argv);

	Local<Number> num = Number::New(isolate, ret);
	args.GetReturnValue().Set(num);

}

void clear(const FunctionCallbackInfo<Value>& args) {
	//Add clear oled-display here
	Isolate* isolate = args.GetIsolate();
	int ret = oledClear();

	Local<Function> cb = Local<Function>::Cast(args[0]);
	const unsigned argc = 1;
	Local<Value> argv[argc] = { Number::New(isolate, ret) };
	cb->Call(Null(isolate), argc, argv);

	Local<Number> num = Number::New(isolate, ret);
	args.GetReturnValue().Set(num);

}

//Configuration
void setDisplayPower(const FunctionCallbackInfo<Value>& args) {
	//Add set-display-power here
	Isolate* isolate = args.GetIsolate();
	int powerState = args[0]->IntegerValue();
	int ret = oledSetDisplayPower(powerState);

	Local<Function> cb = Local<Function>::Cast(args[1]);
	const unsigned argc = 1;
	Local<Value> argv[argc] = { Number::New(isolate, ret) };
	cb->Call(Null(isolate), argc, argv);

	Local<Number> num = Number::New(isolate, ret);
	args.GetReturnValue().Set(num);
}

void setDisplayMode(const FunctionCallbackInfo<Value>& args) {
	//Add set-display-mode here
	Isolate* isolate = args.GetIsolate();
	int bInvert = args[0]->IntegerValue();
	int ret = oledSetDisplayMode(bInvert);

	Local<Function> cb = Local<Function>::Cast(args[1]);
	const unsigned argc = 1;
	Local<Value> argv[argc] = { Number::New(isolate, ret) };
	cb->Call(Null(isolate), argc, argv);

	Local<Number> num = Number::New(isolate, a);
	args.GetReturnValue().Set(num);
}

void setBrightness(const FunctionCallbackInfo<Value>& args) {
    //Add set-brightness here
    Isolate* isolate = args.GetIsolate();
    int brightness = args[0]->IntegerValue();
    int ret = oledSetBrightness(brightness);

	Local<Function> cb = Local<Function>::Cast(args[1]);
	const unsigned argc = 1;
	Local<Value> argv[argc] = { Number::New(isolate, ret) };
	cb->Call(Null(isolate), argc, argv);
	
    Local<Number> num = Number::New(isolate, ret);
    args.GetReturnValue().Set(num);
}

void setDim(const FunctionCallbackInfo<Value>& args) {
    //Add set-Dim here
    Isolate* isolate = args.GetIsolate();
    int bDim = args[0]->IntegerValue();
    int ret = oledSetDim(bDim);

	Local<Function> cb = Local<Function>::Cast(args[1]);
	const unsigned argc = 1;
	Local<Value> argv[argc] = { Number::New(isolate, ret) };
	cb->Call(Null(isolate), argc, argv);

    Local<Number> num = Number::New(isolate, ret);
    args.GetReturnValue().Set(num);
}

void setMemoryMode(const FunctionCallbackInfo<Value>& args) {
    //Add set-Memory-Mode here
    Isolate* isolate = args.GetIsolate();
    int mode = args[0]->IntegerValue();
	int ret = oledSetMemoryMode(mode);

	Local<Function> cb = Local<Function>::Cast(args[1]);
	const unsigned argc = 1;
	Local<Value> argv[argc] = { Number::New(isolate, ret) };
	cb->Call(Null(isolate), argc, argv);

    Local<Number> num = Number::New(isolate, ret);
    args.GetReturnValue().Set(num);
}

void setCursor(const FunctionCallbackInfo<Value>& args) {
    //Add set-Cursor here
    Isolate* isolate = args.GetIsolate();
    int row = args[0]->IntegerValue();
    int col = args[1]->IntegerValue();
    int ret = oledSetCursor(row, col);
	
	Local<Function> cb = Local<Function>::Cast(args[2]);
	const unsigned argc = 1;
	Local<Value> argv[argc] = { Number::New(isolate, ret) };
	cb->Call(Null(isolate), argc, argv);

    Local<Number> num = Number::New(isolate, ret);
    args.GetReturnValue().Set(num);
}

void setCursorByPixel(const FunctionCallbackInfo<Value>& args) {
    //Add set-CursorByPixel here
    Isolate* isolate = args.GetIsolate();
    int row = args[0]->IntegerValue();
    int column = args[1]->IntegerValue();
    int ret = oledSetCursorByPixel(row, column);

	Local<Function> cb = Local<Function>::Cast(args[2]);
	const unsigned argc = 1;
	Local<Value> argv[argc] = { Number::New(isolate, ret) };
	cb->Call(Null(isolate), argc, argv);

    Local<Number> num = Number::New(isolate, ret);
    args.GetReturnValue().Set(num);
}

void setColumnAddressing(const FunctionCallbackInfo<Value>& args) {
    //Add set-ColumnAddressing here
    Isolate* isolate = args.GetIsolate();
    int startPixel = args[0]->IntegerValue();
    int endPixel = args[1]->IntegerValue();
    int ret = oledSetColumnAddressing(startPixel, endPixel);

	Local<Function> cb = Local<Function>::Cast(args[2]);
	const unsigned argc = 1;
	Local<Value> argv[argc] = { Number::New(isolate, ret) };
	cb->Call(Null(isolate), argc, argv);

    Local<Number> num = Number::New(isolate, ret);
    args.GetReturnValue().Set(num);
}
void setTextColumns(const FunctionCallbackInfo<Value>& args) {
    //Add setTextColumns here
    Isolate* isolate = args.GetIsolate();
    int ret = oledSetTextColumns();

	Local<Function> cb = Local<Function>::Cast(args[0]);
	const unsigned argc = 1;
	Local<Value> argv[argc] = { Number::New(isolate, ret) };
	cb->Call(Null(isolate), argc, argv);

    Local<Number> num = Number::New(isolate, ret);
    args.GetReturnValue().Set(num);
}

void setImageColumns(const FunctionCallbackInfo<Value>& args) {
    //Add setImageColumns here
    Isolate* isolate = args.GetIsolate();
    int ret = oledSetImageColumns();

	Local<Function> cb = Local<Function>::Cast(args[0]);
	const unsigned argc = 1;
	Local<Value> argv[argc] = { Number::New(isolate, ret) };
	cb->Call(Null(isolate), argc, argv);

    Local<Number> num = Number::New(isolate, ret);
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
    int ret = oledWriteChar(*writable);

	Local<Function> cb = Local<Function>::Cast(args[1]);
	const unsigned argc = 1;
	Local<Value> argv[argc] = { Number::New(isolate, ret) };
	cb->Call(Null(isolate), argc, argv); 

    Local<Number> num = Number::New(isolate, ret);
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
    int ret = oledWrite(writable); 

	Local<Function> cb = Local<Function>::Cast(args[1]);
	const unsigned argc = 1;
	Local<Value> argv[argc] = { Number::New(isolate, ret) };
	cb->Call(Null(isolate), argc, argv);

    Local<Number> num = Number::New(isolate, ret);
    delete[] writable;
    args.GetReturnValue().Set(num);
}

void writeByte(const FunctionCallbackInfo<Value>& args) {
    //Add set-Memory-Mode here
    Isolate* isolate = args.GetIsolate();
    int byte = args[0]->IntegerValue();
    int ret = oledWriteByte(byte);

    Local<Function> cb = Local<Function>::Cast(args[1]);
    const unsigned argc = 1;
    Local<Value> argv[argc] = { Number::New(isolate, ret) };
    cb->Call(Null(isolate), argc, argv);
    Local<Number> num = Number::New(isolate, ret);
    args.GetReturnValue().Set(num);
}
/**
 *void draw(const FunctionCallbackInfo<Value>& args) {
 *    Isolate* isolate = args.GetIsolate();
 *    v8::String::Utf8Value s(args[0]);
 *    std::string str(*s);
 *    char * writable = new char[str.size() + 1];
 *    std::copy(str.begin(), str.end(), writable);
 *    writable[str.size()] = '\0';
 *    buffer 	= malloc(OLED_EXP_WIDTH*OLED_EXP_HEIGHT/8 * sizeof *buffer);
 *}
 */


//scroll the display

void scroll(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    int direction = args[0]->IntegerValue();
    int scrollSpeed = args[1]->IntegerValue();
    int startPage = args[2]->IntegerValue();
    int stopPage = args[3]->IntegerValue();
    int ret = oledScroll(direction, scrollSpeed, startPage, stopPage);
    Local<Function> cb = Local<Function>::Cast(args[4]);
    const unsigned argc = 1;
    Local<Value> argv[argc] = { Number::New(isolate, ret) };
    cb->Call(Null(isolate), argc, argv);
    Local<Number> num = Number::New(isolate, ret);
    args.GetReturnValue().Set(num);
}

void scrollDiagonal(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    int direction = args[0]->IntegerValue();
    int scrollSpeed = args[1]->IntegerValue();
    int fixedRows = args[2]->IntegerValue();
    int scrollRows = args[3]->IntegerValue();
    int verticalOffset = args[4]->IntegerValue();
    int startPage = args[5]->IntegerValue();
    int stopPage = args[6]->IntegerValue();
    int ret = oledScrollDiagonal(direction, scrollSpeed, 
			fixedRows, scrollRows, verticalOffset, 
			startPage, stopPage);

    Local<Function> cb = Local<Function>::Cast(args[7]);
    const unsigned argc = 1;
    Local<Value> argv[argc] = { Number::New(isolate, ret) };
    cb->Call(Null(isolate), argc, argv);
    Local<Number> num = Number::New(isolate, ret);
    args.GetReturnValue().Set(num);
}

void scrollStop(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    int ret = oledScrollStop();
    Local<Function> cb = Local<Function>::Cast(args[0]);
    const unsigned argc = 1;
    Local<Value> argv[argc] = { Number::New(isolate, ret) };
    cb->Call(Null(isolate), argc, argv);
    Local<Number> num = Number::New(isolate, ret);
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
    Local<Function> cb = Local<Function>::Cast(args[1]);
    const unsigned argc = 1;
    Local<Value> argv[argc] = { Number::New(isolate, status) };
    cb->Call(Null(isolate), argc, argv);

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
    Local<Function> cb = Local<Function>::Cast(args[1]);
    const unsigned argc = 1;
    Local<Value> argv[argc] = { Number::New(isolate, status) };
    cb->Call(Null(isolate), argc, argv);
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

}    // namespace demo
