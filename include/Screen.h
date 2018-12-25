//
// Created by Abdollah Ebadi on 2018-12-25.
//

#ifndef BASICSHELL_SCREEN_H
#define BASICSHELL_SCREEN_H


#include <SDL.h>

class Screen {
private :
  const static int SCREEN_WIDTH = 800 ;
  const static int SCREEN_HEIGHT = 600 ;

  SDL_Window* mWindow;
  SDL_Renderer* mRenderer ;
  SDL_Texture* mTexture ;
  Uint32* mBuffer ;

public:
    Screen() ;
    ~Screen() ;
    int init() ;
    void updateScreen() ;
    int getScreenWidth() ;
    int getScreenHeight() ;
};


#endif //BASICSHELL_SCREEN_H
