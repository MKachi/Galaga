#include "framework/OpenGL.h"
#include "Config.h"
#include "assets/Resources.h"
#include "framework/SceneManager.h"
#include "framework/AudioListener.h"

#if _WINDOWS
#include <crtdbg.h>
#endif

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

void update()
{
	manager->topScene()->update();
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT);
	manager->topScene()->render();
    glFlush();
	glutSwapBuffers();
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
#if defined(_WINDOWS) & defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//	_CrtSetBreakAlloc(241);
#endif

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow(TITLE_NAME);

	Resources resources;
	if (!resources.load())
	{
		return -1;
	}

	AudioListener listener;
	if (!listener.init())
	{
		return -1;
	}
    init();
    
    glutDisplayFunc(render);
    glutReshapeFunc(reshape);
	glutIdleFunc(update);
	glutMainLoop();

	SceneManager::destroy();
	CacheManager::destroy();
    
    return 0;
}
