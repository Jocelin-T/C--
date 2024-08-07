#include <iostream>

// #################################### Interfaces (Pure virtual functions) ####################################
// Notes:   Pure virtual functions NEED to be implement in derived Class!


// IClassName => Interface Class Name (Convention)
class IRenderer{
    public:
    virtual void Draw() = 0; // This is Pure virtual functions (Interface)
    virtual void Update() = 0; // This is Pure virtual functions (Interface)

};

class OpenGL : public IRenderer{
    public:
    void Draw() override {std::cout << "OpenGL::Draw\n";}
    void Update() override {std::cout << "OpenGL::Update\n";}
};

class Vulkan : public IRenderer{
    public:
    void Draw() override {std::cout << "Vulkan::Draw\n";}
    void Update() override {std::cout << "Vulkan::Update\n";}
};

int main(){

    IRenderer* myRenderer = new OpenGL;
    myRenderer->Draw();
    myRenderer->Update();

    return 0;
}