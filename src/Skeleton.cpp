//=============================================================================================
//
//=============================================================================================
#include "framework.h"

const char * vertSource = R"(
    #version 330                
    precision highp float;

    layout(location = 0) in vec2 cP;    

    void main() {
        gl_Position = vec4(cP.x, cP.y, 0, 1);    
    }
)";

const char * fragSource = R"(
    #version 330
    precision highp float;

    uniform vec3 color;           
    out vec4 fragmentColor;        

    void main() {
        fragmentColor = vec4(color, 1); // RGB -> RGBA
    }
)";

const int winWidth = 600, winHeight = 600;

class GreenTriangleApp : public glApp {
    Geometry<vec2>* triangle;  // geometria
    GPUProgram* gpuProgram;       // csucspont es pixel arnyalok
public:
    GreenTriangleApp() : glApp("Green triangle") { }

    void onInitialization() {
        triangle = new Geometry<vec2>;
        triangle->Vtx() = { vec2(-0.8f, -0.8f), vec2(-0.6f, 1.0f), vec2(0.8f, -0.2f) };
        triangle->updateGPU();
        gpuProgram = new GPUProgram(vertSource, fragSource);
    }

    
    void onDisplay() {
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        glViewport(0, 0, winWidth, winHeight);
        triangle->Draw(gpuProgram, GL_TRIANGLES, vec3(0.0f, 1.0f, 0.0f));
    }
};

GreenTriangleApp app;

