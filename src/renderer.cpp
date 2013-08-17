#include "renderer.h"
#include <iostream>
#define PROGRAM_NAME "Yard Work Simulator"

using namespace std;

renderer::renderer() {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
 
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
 
    mainwindow = SDL_CreateWindow(PROGRAM_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        512, 512, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
 
    maincontext = SDL_GL_CreateContext(mainwindow);

    glewInit();
 
    SDL_GL_SetSwapInterval(1);


    const GLchar* vs_source = "#version 120\n"
                "attribute vec2 coord2d;\n"
                "void main(void) {\n"
                "  gl_Position = vec4(coord2d, 0.0, 1.0);\n"
                "}";
    const GLchar* fs_source = "#version 120\n"
                "uniform vec3 colour;"
                "void main(void) {\n"
                "  gl_FragColor = vec4(colour, 1.0);\n"
                "}";

    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vs_source, NULL);
    glCompileShader(vs);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fs_source, NULL);
    glCompileShader(fs);
    program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glUseProgram(program);
    attribute_coord2d = glGetAttribLocation(program, "coord2d");
    uniform_colour = glGetUniformLocation(program, "colour");
}

renderer::~renderer() {
	glDeleteProgram(program);
    SDL_GL_DeleteContext(maincontext);
    SDL_DestroyWindow(mainwindow);
    SDL_Quit();
}

void renderer::render() {
	glClearColor ( 1.0, 1.0, 1.0, 1.0 );
    glClear ( GL_COLOR_BUFFER_BIT );


    SDL_GL_SwapWindow(mainwindow);
}