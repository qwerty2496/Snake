#include "Game.h"

const int BoundaryX = 40;
const int BoundaryY = 40;

Game game;

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

void renderScene(void) {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0, BoundaryX, 0, BoundaryY);
	if (!game.Run()) Game game;
	

	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Snake");
	glutDisplayFunc(renderScene);

	glutSpecialFunc(processSpecialKeys);
	
	glutMainLoop();

	return 0;
}