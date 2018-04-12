#if _WINDOWS
#include <GL/glut.h>
#include <GL/GLU.h>
#else
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>
#endif
#include "Config.h"
#include "framework/SceneManager.h"

SceneManager* manager = nullptr;

void init()
{
	manager = SceneManager::getInstance();
	manager->pushScene(new START_SCENE());

    glEnable(GL_DOUBLEBUFFER);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -1.0f, 1.0f);
}

void update(int value)
{
	manager->topScene()->update();
    glutTimerFunc(1000 / 60, update, 1);
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT);
	manager->topScene()->render();
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -1.0f, 1.0f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow(TITLE_NAME);
    init();
    
    glutDisplayFunc(render);
    glutReshapeFunc(reshape);
    update(1);
    glutMainLoop();
    
    return 0;
}
