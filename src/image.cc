#include "image.h"
#include "helpers.h"
#include "container.h"
#include "surface.h"

#include <iostream>

using namespace v8;
using namespace node;


void sdl::IMG::Initialize(Handle<Object> exports) {
	Handle<Object> IMG = Object::New();
	exports->Set(String::New("IMG"), IMG);
	NODE_SET_METHOD(IMG, "init", Init);
	NODE_SET_METHOD(IMG, "quit", Quit);
	NODE_SET_METHOD(IMG, "load", Load);

	Local<Object> INIT = Object::New();
	IMG->Set(String::New("INIT"), INIT);
	INIT->Set(String::New("JPG"), Number::New(IMG_INIT_JPG));
	INIT->Set(String::New("PNG"), Number::New(IMG_INIT_PNG));
	INIT->Set(String::New("TIF"), Number::New(IMG_INIT_TIF));
}

Handle<Value> sdl::IMG::Init(const Arguments &args) {
	HandleScope scope;

	if (!(args.Length() == 1)) {
		return ThrowException(Exception::TypeError(String::New("Invalid arguments: Expected IMG::Init(Integer)")));
	}
	if(!args[0]->IsInt32()) {
		return ThrowException(Exception::TypeError(
			String::New("Invalid arguments: First argument to IMG::Init must be a Int32.")));
	}

	int flags = static_cast<int>(args[0]->Int32Value());

	if (IMG_Init(flags) < 0) {
		return ThrowException(Exception::Error(String::Concat(
			String::New("IMG::Init: "),
			String::New(IMG_GetError())
			)));
	}

	return Undefined();
}

Handle<Value> sdl::IMG::Quit(const Arguments &args) {
	HandleScope scope;

	IMG_Quit();

	return Undefined();
}

// TODO: make an async version so this can be used in loops or parallel load images
Handle<Value> sdl::IMG::Load(const Arguments &args) {
	HandleScope scope;

	if (!(args.Length() == 1 && args[0]->IsString())) {
		return ThrowException(Exception::TypeError(String::New("Invalid arguments: Expected IMG::Load(String)")));
	}

	String::Utf8Value file(args[0]);

	SDL_Surface *image;
	image = IMG_Load(*file);
	if (!image) {
		return ThrowException(Exception::Error(String::Concat(
			String::New("IMG::Load: "),
			String::New(IMG_GetError())
			)));
	}

	Handle<Object> ret = Object::New();
	SurfaceWrapper *wrap = new SurfaceWrapper(ret);
	wrap->surface_ = image;
	return scope.Close(ret);
}
