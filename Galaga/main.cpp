#include "framework/OpenGL.h"
#include "Config.h"
#include "assets/Resources.h"
#include "framework/SceneManager.h"
#include "framework/Input.h"
#include "framework/Timer.h"
#include "framework/Scheduler.h"

#if _WINDOWS
#include <crtdbg.h>
#endif

SceneManager* manager = nullptr;
Timer timer;
GLint menuID = 0;

void menuEvents(int value)
{
	if (value == 0)
	{
		exit(0);
	}
}

void init()
{
	manager = SceneManager::getInstance();
	manager->pushScene(new START_SCENE());
	GLint menuID = glutCreateMenu(menuEvents);
	glutAddMenuEntry("Á¾·á", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

    glEnable(GL_DOUBLEBUFFER);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -1.0f, 1.0f);
}

void update(int value)
{
	timer.tick();
	manager->topScene()->update(timer);
	glutTimerFunc(1000 / 60, update, 0);
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT);
	manager->topScene()->render();
    glFlush();
	glutSwapBuffers();
}

void postSync(int value)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, postSync, 0);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -1.0f, 1.0f);
}

void specialKeyDown(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_LEFT:
            Input::keyFunc(KeyCode::Left);
            break;
        case GLUT_KEY_RIGHT:
            Input::keyFunc(KeyCode::Right);
            break;
        case GLUT_KEY_UP:
            Input::keyFunc(KeyCode::Up);
            break;
        case GLUT_KEY_DOWN:
            Input::keyFunc(KeyCode::Down);
            break;
        default:
            break;
    }
}

void specialKeyup(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_LEFT:
            Input::keyUpFunc(KeyCode::Left);
            break;
        case GLUT_KEY_RIGHT:
            Input::keyUpFunc(KeyCode::Right);
            break;
        case GLUT_KEY_UP:
            Input::keyUpFunc(KeyCode::Up);
            break;
        case GLUT_KEY_DOWN:
            Input::keyUpFunc(KeyCode::Down);
            break;
        default:
            break;
    }
}

void keyDown(unsigned char key, int x, int y)
{
    if (key == GLUT_ASCII_SPACE)
    {
        Input::keyFunc(KeyCode::Space);
    }
}

void keyUp(unsigned char key, int x, int y)
{
    if (key == GLUT_ASCII_SPACE)
    {
        Input::keyUpFunc(KeyCode::Space);
    }
}

void destroy()
{
	SceneManager::destroy();
	CacheManager::destroy();
}

int main(int argc, char** argv)
{
#if defined(_WINDOWS) & defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(940);
#endif

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow(TITLE_NAME);

	atexit(destroy);
    Input::init();
    
	Resources resources;
	if (!resources.load())
	{
		return -1;
	}
    init();
    
    glutDisplayFunc(render);
    glutReshapeFunc(reshape);

    glutSpecialFunc(specialKeyDown);
	glutSpecialUpFunc(specialKeyup);

	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);

	update(1);
	postSync(1);
	glutMainLoop();
    
    return 0;
}
