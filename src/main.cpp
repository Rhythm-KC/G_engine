#include <iostream>
#include <memory.h>
#include <filesystem>

#include "Test/adder.h"
#include "Render/IRender.h"
#include "Render/OpenGL/OpenGLRenderer.h"

int main(){
    int x = add(2, 5);
    
   auto renderer = OpenGLRenderer();
   renderer.Initialize();
   return 0;
}