#ifndef NODEJS_IMAGE_H
#define NODEJS_IMAGE_H

#include <v8.h>
#include <node.h>

#include "SDL.h"
#include "SDL_image.h"


namespace sdl {
	namespace IMG {
		void Initialize(v8::Handle<v8::Object> exports);

		// documentation for SDL_image 1.2.8 (2.0.0 docs not found)
		// https://www.libsdl.org/projects/SDL_image/docs/SDL_image.html

		// v8::Handle<v8::Value> Linked_Version(const v8::Arguments &args);
		v8::Handle<v8::Value> Init(const v8::Arguments &args);
		v8::Handle<v8::Value> Quit(const v8::Arguments &args);
	
		v8::Handle<v8::Value> Load(const v8::Arguments &args);
		// v8::Handle<v8::Value> Load_RW(const v8::Arguments &args);
		// v8::Handle<v8::Value> LoadTyped_RW(const v8::Arguments &args);
		// v8::Handle<v8::Value> LoadCUR_RW(const v8::Arguments &args);
		// v8::Handle<v8::Value> LoadICO_RW(const v8::Arguments &args);
		// v8::Handle<v8::Value> LoadBMP_RW(const v8::Arguments &args);
		// v8::Handle<v8::Value> LoadPNM_RW(const v8::Arguments &args);
		// v8::Handle<v8::Value> LoadXPM_RW(const v8::Arguments &args);
		// v8::Handle<v8::Value> LoadXCF_RW(const v8::Arguments &args);
		// v8::Handle<v8::Value> LoadPCX_RW(const v8::Arguments &args);
		// v8::Handle<v8::Value> LoadGIF_RW(const v8::Arguments &args);
		// v8::Handle<v8::Value> LoadJPG_RW(const v8::Arguments &args);
		// v8::Handle<v8::Value> LoadTIF_RW(const v8::Arguments &args);
		// v8::Handle<v8::Value> LoadPNG_RW(const v8::Arguments &args);
		// v8::Handle<v8::Value> LoadTGA_RW(const v8::Arguments &args);
		// v8::Handle<v8::Value> LoadLBM_RW(const v8::Arguments &args);
		// v8::Handle<v8::Value> LoadXV_RW(const v8::Arguments &args);
		// v8::Handle<v8::Value> ReadXPMFromArray(const v8::Arguments &args);

		// v8::Handle<v8::Value> isCUR(const v8::Arguments &args);
		// v8::Handle<v8::Value> isICO(const v8::Arguments &args);
		// v8::Handle<v8::Value> isBMP(const v8::Arguments &args);
		// v8::Handle<v8::Value> isPNM(const v8::Arguments &args);
		// v8::Handle<v8::Value> isXPM(const v8::Arguments &args);
		// v8::Handle<v8::Value> isXCF(const v8::Arguments &args);
		// v8::Handle<v8::Value> isPCX(const v8::Arguments &args);
		// v8::Handle<v8::Value> isGIF(const v8::Arguments &args);
		// v8::Handle<v8::Value> isJPG(const v8::Arguments &args);
		// v8::Handle<v8::Value> isTIF(const v8::Arguments &args);
		// v8::Handle<v8::Value> isPNG(const v8::Arguments &args);
		// v8::Handle<v8::Value> isLBM(const v8::Arguments &args);
		// v8::Handle<v8::Value> isXV(const v8::Arguments &args);

		// v8::Handle<v8::Value> SetError(const v8::Arguments &args);
		// v8::Handle<v8::Value> GetError(const v8::Arguments &args);
	}
}

#endif