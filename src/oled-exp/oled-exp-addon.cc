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

// NodeJS wrapper for C oledDriverInit() Function
//  arguments:
//    callback - function (optional)
//  returns:
//    true - successfully initialized
//    false - initialization failed

void oledInit(const FunctionCallbackInfo<Value>& args) {
	//Add init oled-display here
	Isolate* isolate = args.GetIsolate();

	// perform the C library operation
	int ret = oledDriverInit();
	Local<Number> retVal = Number::New(isolate, ret);

	if (args.Length() > 0) {
		Local<Function> callback = Local<Function>::Cast(args[0]);
		const unsigned argc = 1;
		Local<Value> argv[argc] = { retVal };
		callback->Call(Null(isolate), argc, argv);
	}

	args.GetReturnValue().Set(retVal);
}

// NodeJS wrapper for C oledCheckInit() Function
//  arguments:
//    callback - function (optional)
//  returns:
//    true - screen has initialised
//    false - screen is not initialised
void checkInit(const FunctionCallbackInfo<Value>& args) {
	//Add checkinit oled-display here
	Isolate* isolate = args.GetIsolate();

	int ret = oledCheckInit();
	Local<Number> retVal = Number::New(isolate, ret);

	if (args.Length() > 0) {
		Local<Function> callback = Local<Function>::Cast(args[0]);
		const unsigned argc = 1;
		Local<Value> argv[argc] = { retVal };
		callback->Call(Null(isolate), argc, argv);
	}

	args.GetReturnValue().Set(retVal);

}

// NodeJS wrapper for C clear() Function
//  arguments:
//    callback - function (optional)
//  returns:
//    true - successfully cleared screen
//    false - failed to clear
void clear(const FunctionCallbackInfo<Value>& args) {
	//Add clear oled-display here
	Isolate* isolate = args.GetIsolate();

	// perform the C lib operation
	int ret = oledClear();
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

// NodeJS wrapper for C setDisplyPower() Function
//  arguments:
//    bPowerOn - boolean (0 or 1) - the power state to set the display (0 - off; 1 - on)
//    callback - function (optional)
//  returns:
//    true - setting state successful
//    false - failed to set state
void setDisplayPower(const FunctionCallbackInfo<Value>& args) {
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
	int bPowerOn = args[0]->IntegerValue();

	// perform the C library operation
	int ret = oledSetDisplayPower(bPowerOn);
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

// NodeJS wrapper for C setDisplayMode() Function
//  arguments:
//    mode - boolean - 0/false: normal; 1/true: invert colours
//    callback - function (optional)
//  returns:
//    true - successfully changed display mode
//    false - display mode failed to change
void setDisplayMode(const FunctionCallbackInfo<Value>& args) {
	//Add set-display-mode here
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
	int bInvert = args[0]->IntegerValue();

	// perform the C library operation
	int ret = oledSetDisplayMode(bInvert);
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

// NodeJS wrapper for C oledSetBrightness() Function
//  arguments:
//    brightness - integer - desired brightness level
//    callback - function (optional)
//  returns:
//    true - successfully set brightness
//    false - failed to set brightness
void setBrightness(const FunctionCallbackInfo<Value>& args) {
	//Add set-brightness here
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
	int brightness = args[0]->IntegerValue();

	// perform the C library operation
	int ret = oledSetBrightness(brightness);
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

// NodeJS wrapper for C oledSetDim() Function
//  arguments:
//    bDim - boolean - 0/false: normal brightness; 1/true: dim the display
//    callback - function (optional)
//  returns:
//    true - operation successful
//    false - operation failed
void setDim(const FunctionCallbackInfo<Value>& args) {
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
    int bDim = args[0]->IntegerValue();

	// perform the C library operation
    int ret = oledSetDim(bDim);
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

// NodeJS wrapper for C oledSetMemoryMode() Function
//  arguments:
//    mode - integer - the desired mode, details are in docs
//    callback - function (optional)
//  returns:
//    true - operation successful
//    false - operation failed
void setMemoryMode(const FunctionCallbackInfo<Value>& args) {
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
    int mode = args[0]->IntegerValue();

	// perform the C library operation
	int ret = oledSetMemoryMode(mode);
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

// NodeJS wrapper for C oledSetCursor() Function
//  arguments:
//    row - integer - vertical position of cursor measured in pages
//    column - integer - horizontal position of cursor measured in character columns
//    callback - function (optional)
//  returns:
//    true - operation successful
//    false - operation failed
void setCursor(const FunctionCallbackInfo<Value>& args) {
    //Add set-Cursor here
    Isolate* isolate = args.GetIsolate();
	// Check the number of arguments passed.
	if (args.Length() < 2) {
		// Throw an Error that is passed back to JavaScript
		isolate->ThrowException(Exception::TypeError(
		String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	// Check the argument types
	if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
		isolate->ThrowException(Exception::TypeError(
		String::NewFromUtf8(isolate, "Wrong argument type")));
		return;
	}
	// read in the value arguments
    int row = args[0]->IntegerValue();
    int column = args[1]->IntegerValue();

	// perform the C library operation
    int ret = oledSetCursor(row, column);
    Local<Number> retVal = Number::New(isolate, ret);

	// handle (optional) callback argument
	if (args.Length() > 2) {
		Local<Function> callback = Local<Function>::Cast(args[2]);
		const unsigned argc = 1;
		Local<Value> argv[argc] = { retVal };
		callback->Call(Null(isolate), argc, argv);
	}

    args.GetReturnValue().Set(retVal);
}

// NodeJS wrapper for C oledSetCursorByPixel() Function
//  arguments:
//    row - integer - vertical position of cursor measured in pages
//    pixel - integer - horizontal position of curser measured in pixels
//    callback - function (optional)
//  returns:
//    true - operation successful
//    false - operation failed
void setCursorByPixel(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

	// Check the number of arguments passed.
	if (args.Length() < 2) {
		// Throw an Error that is passed back to JavaScript
		isolate->ThrowException(Exception::TypeError(
		String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	// Check the argument types
	if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
		isolate->ThrowException(Exception::TypeError(
		String::NewFromUtf8(isolate, "Wrong argument type")));
		return;
	}

	// read in the value arguments
    int row = args[0]->IntegerValue();
    int pixel = args[1]->IntegerValue();

	// perform the C library operation
    int ret = oledSetCursorByPixel(row, pixel);
    Local<Number> retVal = Number::New(isolate, ret);

	// handle (optional) callback argument
	if (args.Length() > 2) {
		Local<Function> callback = Local<Function>::Cast(args[2]);
		const unsigned argc = 1;
		Local<Value> argv[argc] = { retVal };
		callback->Call(Null(isolate), argc, argv);
	}

    args.GetReturnValue().Set(retVal);
}

// NodeJS wrapper for C oledSetColumnAddressing() Function
//  arguments:
//	  startPixel - integer - the first addressable pixel in each row/page
//	  endPixel - integer - the last addressable pixel in each row/page
//    callback - function (optional)
//  returns:
//    true - operation successful
//    false - operation failed
void setColumnAddressing(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

	// Check the number of arguments passed.
	if (args.Length() < 2) {
		// Throw an Error that is passed back to JavaScript
		isolate->ThrowException(Exception::TypeError(
		String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	// Check the argument types
	if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
		isolate->ThrowException(Exception::TypeError(
		String::NewFromUtf8(isolate, "Wrong argument type")));
		return;
	}

	// read in the value arguments
    int startPixel = args[0]->IntegerValue();
    int endPixel = args[1]->IntegerValue();

	// perform the C library operation
    int ret = oledSetColumnAddressing(startPixel, endPixel);
    Local<Number> retVal = Number::New(isolate, ret);

	// handle (optional) callback argument
	if (args.Length() > 2) {
		Local<Function> callback = Local<Function>::Cast(args[2]);
		const unsigned argc = 1;
		Local<Value> argv[argc] = { retVal };
		callback->Call(Null(isolate), argc, argv);
	}

    args.GetReturnValue().Set(retVal);
}

// NodeJS wrapper for C oledSetDim() Function
//  arguments:
//    callback - function (optional)
//  returns:
//    true - operation successful
//    false - operation failed
void setTextColumns(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

	// perform the C library operation
    int ret = oledSetTextColumns();
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

// NodeJS wrapper for C oledSetImageColumns() Function
//  arguments:
//    bDim - boolean - 0/false: normal brightness; 1/true: dim the display
//    callback - function (optional)
//  returns:
//    true - operation successful
//    false - operation failed
void setImageColumns(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

	// perform the C library operation
    int ret = oledSetImageColumns();
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


// NodeJS wrapper for C oledWriteChar() Function
//  arguments:
//    writable - string - character to be written, all chars except the first in the string is ignored
//    callback - function (optional)
//  returns:
//    true - operation successful
//    false - operation failed
void writeChar(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

	// Check the number of arguments passed.
	if (args.Length() < 1) {
		// Throw an Error that is passed back to JavaScript
		isolate->ThrowException(Exception::TypeError(
		String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	// parses the argument into c-string
    v8::String::Utf8Value s(args[0]);
    std::string str(*s);
    char* writable = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), writable);
    writable[str.size()] = '\0';

	// perform the C library operation
    int ret = oledWriteChar(*writable);
    Local<Number> retVal = Number::New(isolate, ret);

	// handle (optional) callback argument
	if (args.Length() > 1) {
		Local<Function> callback = Local<Function>::Cast(args[1]);
		const unsigned argc = 1;
		Local<Value> argv[argc] = { retVal };
		callback->Call(Null(isolate), argc, argv);
	}

	// leak prevention
    delete[] writable;
    args.GetReturnValue().Set(retVal);
}

// NodeJS wrapper for C oledWrite() Function
//  arguments:
//    writable - string - string to be written to the screen
//    callback - function (optional)
//  returns:
//    true - operation successful
//    false - operation failed
void write(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

	// Check the number of arguments passed.
	if (args.Length() < 1) {
		// Throw an Error that is passed back to JavaScript
		isolate->ThrowException(Exception::TypeError(
		String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	// parses the argument into c-string
    v8::String::Utf8Value s(args[0]);
    std::string str(*s);
    char *writable = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), writable);
    writable[str.size()] = '\0';

	// perform the C library operation
    int ret = oledWrite(writable);
    Local<Number> retVal = Number::New(isolate, ret);

	// handle (optional) callback argument
	if (args.Length() > 1) {
		Local<Function> callback = Local<Function>::Cast(args[1]);
		const unsigned argc = 1;
		Local<Value> argv[argc] = { retVal };
		callback->Call(Null(isolate), argc, argv);
	}

	// leak prevention
    delete[] writable;
    args.GetReturnValue().Set(retVal);
}

// NodeJS wrapper for C oledWriteByte() Function
//  arguments:
//    byte - int - byte to be written to the display 
//					at the current cursor position
//    callback - function (optional)
//  returns:
//    true - operation successful
//    false - operation failed
void writeByte(const FunctionCallbackInfo<Value>& args) {
    //Add set-Memory-Mode here
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
    int byte = args[0]->IntegerValue();

	// perform the C library operation
    int ret = oledWriteByte(byte);
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

// NodeJS wrapper for C oledScroll() Function
//  arguments:
//    direction - boolean - 0: left; 1: right
//    scrollSpeed - integer - see documentation for arguments
//    startPage - integer - starting page of the section to be scrolled
//    stopPage - integer - ending page of the section to be scrolled
//    callback - function (optional)
//  returns:
//    true - operation successful
//    false - operation failed
void scroll(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

	// Check the number of arguments passed.
	if (args.Length() < 4) {
		// Throw an Error that is passed back to JavaScript
		isolate->ThrowException(Exception::TypeError(
		String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	// Check the argument types
	if (!args[0]->IsNumber() 
		!args[1]->IsNumber() ||
		!args[2]->IsNumber() ||
		!args[3]->IsNumber()) {

		isolate->ThrowException(Exception::TypeError(
		String::NewFromUtf8(isolate, "Wrong argument type")));
		return;
	}

	// read in the value arguments
    int direction = args[0]->IntegerValue();
    int scrollSpeed = args[1]->IntegerValue();
    int startPage = args[2]->IntegerValue();
    int stopPage = args[3]->IntegerValue();

	// perform the C library operation
    int ret = oledScroll(direction, scrollSpeed, startPage, stopPage);
    Local<Number> retVal = Number::New(isolate, ret);

	// handle (optional) callback argument
	if (args.Length() > 4) {
		Local<Function> callback = Local<Function>::Cast(args[4]);
		const unsigned argc = 1;
		Local<Value> argv[argc] = { retVal };
		callback->Call(Null(isolate), argc, argv);
	}

    args.GetReturnValue().Set(retVal);
}

// NodeJS wrapper for C oledScrollDiagonal() Function
// **function always scrolls upwards
//  arguments
//    direction - boolean - 0: left; 1: right
//    scrollSpeed - integer - see documentation for speed settings
//    fixedRows - integer - pixel rows that will not be scrolled (from the top)
//    scrollRows - integer - pixel rows that will be scrolled (from the top)
//    verticalOffset - integer - the number of vertical rows scrolled per frame
//    startPage - integer - starting page of the section to be scrolled
//    stopPage - integer - ending page of the section to be scrolled
//    callback - function (optional)
//  returns:
//    true - operation successful
//    false - operation failed
void scrollDiagonal(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

	// Check the number of arguments passed.
	if (args.Length() < 7) {
		// Throw an Error that is passed back to JavaScript
		isolate->ThrowException(Exception::TypeError(
		String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	// Check the argument types
	if (!args[0]->IsNumber() ||
		!args[1]->IsNumber() ||
		!args[2]->IsNumber() ||
		!args[3]->IsNumber() ||
		!args[4]->IsNumber() ||
		!args[5]->IsNumber() ||
		!args[6]->IsNumber()) {

		isolate->ThrowException(Exception::TypeError(
		String::NewFromUtf8(isolate, "Wrong argument type")));
		return;
	}

	// read in the value arguments
    int direction = args[0]->IntegerValue();
    int scrollSpeed = args[1]->IntegerValue();
    int fixedRows = args[2]->IntegerValue();
    int scrollRows = args[3]->IntegerValue();
    int verticalOffset = args[4]->IntegerValue();
    int startPage = args[5]->IntegerValue();
    int stopPage = args[6]->IntegerValue();

	// perform the C library operation
    int ret = oledScrollDiagonal(direction, scrollSpeed,
			fixedRows, scrollRows, verticalOffset,
			startPage, stopPage);
    Local<Number> retVal = Number::New(isolate, ret);

	// handle (optional) callback argument
	if (args.Length() > 7) {
		Local<Function> callback = Local<Function>::Cast(args[7]);
		const unsigned argc = 1;
		Local<Value> argv[argc] = { retVal };
		callback->Call(Null(isolate), argc, argv);
	}

    args.GetReturnValue().Set(retVal);
}

// NodeJS wrapper for C oledScrollStop() Function
//  arguments:
//    callback - function (optional)
//  returns:
//    true - operation successful
//    false - operation failed
void scrollStop(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

	// perform the C library operation
    int ret = oledScrollStop();
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

// NodeJS wrapper for C oledReadLcdFile() Function
//  arguments:
//    file - string - path of the file to be read
//    callback - function (optional)
//  returns:
//    true - operation successful
//    false - operation failed
void readLcdFile(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = args.GetIsolate();

	// Check the number of arguments passed.
	if (args.Length() < 1) {
		// Throw an Error that is passed back to JavaScript
		isolate->ThrowException(Exception::TypeError(
		String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	// buffer is a global variable and path is passed in as a string
	buffer 	= (uint8_t*)malloc(OLED_EXP_WIDTH*OLED_EXP_HEIGHT/8 * sizeof *buffer);

	// reading the filename from the arguments
	v8::String::Utf8Value s(args[0]);
	std::string str(*s);
	char * file = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), file);
	file[str.size()] = '\0';

	// call the C lib Read function
	int retVal = oledReadLcdFile(file,buffer);

	// check for file r/w errors, then call the C lib draw function
	if (retVal == EXIT_SUCCESS) {
		retVal	= oledDraw(buffer, OLED_EXP_WIDTH*OLED_EXP_HEIGHT/8);
	} else {
		printf("ERROR: Cannot draw invalid data\n");
	}

	// deallocate buffer
	if (buffer != NULL) {
		printf("> Deallocating buffer array\n");
		free(buffer);
	}

	// handle (optional) callback argument
	if (args.Length() > 1) {
		Local<Function> callback = Local<Function>::Cast(args[1]);
		const unsigned argc = 1;
		Local<Value> argv[argc] = { retVal };
		callback->Call(Null(isolate), argc, argv);
	}

	delete[] writable;
	args.GetReturnValue().Set(retVal);

}

void readLcdData(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = args.GetIsolate();

	// TODO: error check args length
	
	//buffer is a global variable and path is passed in as a string
	buffer 	=(uint8_t*)malloc(OLED_EXP_WIDTH*OLED_EXP_HEIGHT/8 * sizeof *buffer);
	v8::String::Utf8Value s(args[0]);
	std::string str(*s);
	char * writable = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), writable);
	writable[str.size()] = '\0';
	int retVal = oledReadLcdData(writable,buffer);
	Local<Number> retVal = Number::New(isolate, status);

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

	// handle (optional) callback argument
	if (args.Length() > 1) {
		Local<Function> callback = Local<Function>::Cast(args[1]);
		const unsigned argc = 1;
		Local<Value> argv[argc] = { Number::New(isolate, status) };
		callback->Call(Null(isolate), argc, argv);
	}
		
	delete[] writable;
	args.GetReturnValue().Set(retVal);

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
