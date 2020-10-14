#pragma once

#include <vector>

class Input {

    public:
        static Input& getInstance();
         //remove other constructors
        Input(Input const&) = delete;
        void operator=(Input const&) = delete;




        std::vector<int> pressedChar;
        //current mouse pos
        //int is scrolling - 0 not scrolling, 1 is scrolling up, -1 scrolling down
        //vector<int> mouseBtn - 1, 2, 3, 4, 5

        //keycodes for ease of use
        //functions for the user to use for figuring out if an input is pressed this frame

        bool isKeyPressed(int key);

        //isMousePressed
        //isScrolling...



    private:
        Input();
};

inline Input& Input::getInstance() {
    static Input instance;
    return instance;
}