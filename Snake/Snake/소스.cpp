#include "Game.h"

const int BoundaryX = 42;
const int BoundaryY = 42;

Game game;

void Arrowkeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		if (game.getSnake().getDir() != down) {
			game.getSnake().setDir(up);
			glutPostRedisplay();
		}
		break;
	case GLUT_KEY_DOWN:
		if (game.getSnake().getDir() != up) {
			game.getSnake().setDir(down);
			glutPostRedisplay();
		}
		break;
	case GLUT_KEY_LEFT:
		if (game.getSnake().getDir() != right) {
			game.getSnake().setDir(left);
			glutPostRedisplay();
		}
		break;
	case GLUT_KEY_RIGHT:
		if (game.getSnake().getDir() != left) {
			game.getSnake().setDir(right);
			glutPostRedisplay();
		}
		break;
	}
}

void renderScene(void) {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, BoundaryX, 0, BoundaryY);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	game.Run();
	
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(720, 720);
	glutCreateWindow("Snake");

	//callback
	glutDisplayFunc(renderScene);
	glutSpecialFunc(Arrowkeys);
	
	glutMainLoop();
	
	return 0;
}