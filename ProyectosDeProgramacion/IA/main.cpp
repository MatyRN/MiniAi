#include <iostream>
#include "WINDOW.cpp"

int main(){
    WINDOW* PWI = new WINDOW();

    bool running = true;
while(running){
    if(!PWI->ProcessMessages()){
        running = false;
    }
    ///Renderizar
    Sleep(10);
    PWI->UPDATE();
}
    delete PWI;
    return 0;
}
