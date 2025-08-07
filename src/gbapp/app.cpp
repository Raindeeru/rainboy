#include "app.h"
#include "SDL3/SDL_error.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include "render.h"
#include <cstdio>
#include <iostream>

#define CPS 69905 //Cycles Per Frame, if 60 FPS
#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 100

SDL_Window* window;
SDL_Renderer* renderer;

bool running = false;

bool Init(){
    //Initialize SDL
    if(!SDL_Init(SDL_INIT_VIDEO)){
        std::cout << "Could Not Initialize SDL:" << SDL_GetError() <<"\n";
        return false;
    }

    if(!SDL_CreateWindowAndRenderer(
                "RainBoy", 
                SCREEN_WIDTH, SCREEN_HEIGHT, 
                SDL_WINDOW_OPENGL, 
                &window, &renderer)){
        
        std::cout << "Could Not Initialize Window or Renderer:" << SDL_GetError() <<"\n";
        return false;
    }


    bool running = true;
    std::printf("Initialized RainBoy!");
    return true;
}

void Update(){
    //SDL_Update
    //Replace This with a more comprehenssive input schem
    SDL_Event event;

    while(SDL_PollEvent(&event)){
        if(event.type == SDL_EVENT_QUIT){
            running = false;
        }
    }

    int update_cycles = 0;
    while(update_cycles < CPS){
        update_cycles++; //Temporary until we implement following in core
        //Executing the Next Opcode
        //Update Timers
        //Update Graphics
        //Interuppts
    }
    //In another Script in App make a Render Function
    RenderScreen();
}

void End(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::printf("Ended RainBoy!");
}

void GameBoyApp::Start(){
    if(!Init()){
        std::printf("Could Not Properly Initialize RainBoy!");
        return; 
    }

    while(running){
        Update();
    }

    End();
}
