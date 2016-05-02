#!bin/bash
chmod +x makefile.sh
g++ main.cpp OPENGL.cpp GAME.cpp CHARACTER.cpp TextureManager.cpp SCENE.cpp RECT.cpp -lGL -lglut -lGLU -lfreeimageplus -w -o test
./test
