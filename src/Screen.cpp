//
// Created by Abdollah Ebadi on 2018-12-25.
//

#include "Screen.h"
#include <iostream>

using namespace std ;

Screen::Screen() : mWindow(nullptr) , mRenderer(nullptr) , mTexture(nullptr) , mBuffer(nullptr) {

    cout << "Creating screen object" << endl ;
}

Screen::~Screen() {
    cout << "Destroying Object" << endl ;

    delete [] mBuffer ;
    SDL_DestroyTexture(mTexture) ;
    SDL_DestroyRenderer(mRenderer) ;
    SDL_DestroyWindow(mWindow) ;
    SDL_Quit() ;
}

int Screen::init() {

    if( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        cout << "SDL initialization failed" << endl ;
        return 1 ;
    }
    else {
        cout << "SDL initialization successful" << endl ;
    }

    mWindow = SDL_CreateWindow("BasicShell" , SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED , SCREEN_WIDTH ,
            SCREEN_HEIGHT , SDL_WINDOW_SHOWN) ;

    if(mWindow == nullptr) {
        cout << "Could not create window - " << SDL_GetError() << endl ;
        SDL_Quit() ;
        return 2 ;
    }

    mRenderer = SDL_CreateRenderer(mWindow , -1 , SDL_RendererFlags::SDL_RENDERER_PRESENTVSYNC) ;

    if(mRenderer == nullptr) {
        cout << "Could not create renderer - " << SDL_GetError() << endl ;
        SDL_DestroyWindow(mWindow) ;
        SDL_Quit() ;
        return 3 ;
    }

    mTexture = SDL_CreateTexture(mRenderer , SDL_PIXELFORMAT_RGBA8888 , SDL_TEXTUREACCESS_STATIC ,
            SCREEN_WIDTH , SCREEN_HEIGHT) ;

    if(mTexture == nullptr) {
        cout << "Could not create texture - " << SDL_GetError() << endl ;
        SDL_DestroyRenderer(mRenderer) ;
        SDL_DestroyWindow(mWindow) ;
        SDL_Quit() ;
        return 4 ;
    }

    mBuffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT] ;
    memset(mBuffer , 0xFFFFFF , SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32)) ;

    updateScreen() ;

    return 0 ;

}


int Screen::getScreenHeight() {
    return SCREEN_HEIGHT ;
}

int Screen::getScreenWidth() {
    return SCREEN_WIDTH ;
}

void Screen::updateScreen() {

    SDL_UpdateTexture(mTexture , nullptr , mBuffer , SCREEN_WIDTH * sizeof(Uint32) ) ;
    SDL_RenderClear(mRenderer) ;
    SDL_RenderCopy(mRenderer , mTexture , nullptr , nullptr) ;
    SDL_RenderPresent(mRenderer) ;

}

