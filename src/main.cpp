#include <iostream>

#include "ofMain.h"
#include "ofApp.h"

std::string default_vertex_shader(
R"(
#version 120

void main()
{
    gl_Position = ftransform(); 
}
)");


void usage() {
    std::cout << "ADfgadfg" << std::endl;
}

//========================================================================
int main(int argc, char * argv[]){
    std::stringstream fragment_shader;
    std::stringstream vertex_shader;

	ofSetupOpenGL(1, 1, OF_WINDOW);			// <-------- setup the GL context

    switch (argc) {
        case 1:
            fragment_shader << std::cin.rdbuf();
            vertex_shader.str(default_vertex_shader);
            break;
        case 2:
            fragment_shader << std::ifstream(argv[1]).rdbuf();
            vertex_shader.str(default_vertex_shader);
            break;
        case 3:
            fragment_shader << std::ifstream(argv[1]).rdbuf();
            vertex_shader << std::ifstream(argv[2]).rdbuf();
            break;
        default:
            usage();
            return -1;
            break;
    }
    
    auto app = new ofApp();
    app->setupShader(vertex_shader.str(), fragment_shader.str());
    ofRunApp(app);

}
