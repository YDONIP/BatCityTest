#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
int g_windowSizeX = 620;
int g_windowSizeY = 480 ;


void glwfWindowSizeCallback(GLFWwindow* pWindow, int wight, int height){
    g_windowSizeX = wight;
    g_windowSizeY = height;
    glViewport(0, 0, g_windowSizeX, g_windowSizeY);
}

void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode){
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}

int main(void)
{
    
  
    if (!glfwInit()){
        return -1;
        std::cout << "NONE GLFW" << std::endl;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    
    //Выключение возможности изменения размера окна
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow* pWindow = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "BatCityTest", nullptr, nullptr);
    if (!pWindow)
    {
        std::cout << "Window not create"<<std::endl;
        glfwTerminate();
        return -1;
    }
        glfwMakeContextCurrent(pWindow);
    if(!gladLoadGL()){
        std::cout<<"ERROR LOAD GLAD"<<std::endl;
        return -1;
    }
    
    
    
   std::cout <<"REnderer:"<<glGetString(GL_RENDERER)<<std::endl;
   std::cout <<"GLVersion"<<glGetString(GL_VERSION)<<std::endl;

    glClearColor(1, 0, 1, 1);
    
    glfwSetWindowSizeCallback(pWindow, glwfWindowSizeCallback);
    glfwSetKeyCallback(pWindow, glfwKeyCallback);
        while (!glfwWindowShouldClose(pWindow))
    {
        
        glClear(GL_COLOR_BUFFER_BIT);

      
        glfwSwapBuffers(pWindow);

        
        glfwPollEvents();
    }

    glfwTerminate();
}
