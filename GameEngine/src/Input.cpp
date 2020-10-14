#include "Input.h"

bool Input::isKeyPressed(int key) {
    for (int i = 0; i < pressedChar.size(); ++i) {
        if (pressedChar.at(i) == key) {
            return true;
        }
    }

    return false;
}

Input::Input() {}