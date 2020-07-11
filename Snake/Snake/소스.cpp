#include "Game.h"

const int BoundaryX = 40;
const int BoundaryY = 40;

Game game;
clock_t start = clock();
clock_t end;

void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		game.getSnake().setDir(up);
		break;
	case GLUT_KEY_DOWN:
		game.getSnake().setDir(down);
		break;
	case GLUT_KEY_LEFT:
		game.getSnake().setDir(left);
		break;
	case GLUT_KEY_RIGHT:
		game.getSnake().setDir(right);
		break;
	}
}
void idle() {
	end = clock();
	if (end - start > ) {
		game.Run();
		start = end;
	}
	glutPostRedisplay();
}

void renderScene(void) {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0, BoundaryX, 0, BoundaryY);

	game.draw();

	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Snake");

	//callback
	glutDisplayFunc(renderScene);
	glutIdleFunc(idle);
	glutSpecialFunc(processSpecialKeys);
	
	glutMainLoop();

	return 0;
}