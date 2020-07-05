#include "Game.h"

Game::Game() {
	Item.setColor(RED);
}

void Game::Run() {
	//준영 파트 - Game의 다른 멤버 함수들 조합
	glutPostRedisplay();//요건 지우지마
}

void Game::draw() {
	Item.drawBox();
	snake.drawSnake();
}

void Game::genItem() {
	//준영 파트 - 먹이 좌표가 snake의 머리 및 몸통 좌표와 겹치기 않게 추가
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 40);
	float x = dis(gen);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 40);
	float y = dis(gen);

	Item.setPos(x, y);
}

bool Game::isEat() {
	//유제 파트 - 머리 좌표와 먹이 좌표의 겹칩 여부
	if (snake.getBody()[0].getPosX()==Item.getPosX() && snake.getBody()[0].getPosY()==Item.getPosY())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Game::isDie() {
	/*동헌 파트 
	1.머리가 몸통에 부딪힘 여부
		-snake의 이동방향 (dir) 고려할 것
	2. 머리가 벽에 부딪힘 여부
		-맵 꼭짓점 좌표: (0,0), (0,40), (40,40), (40,0)

		클래스 헤더 파일에 boundaryX, boundaryY를 정의하면 편할 거 같은데
		소스 파일에 정의한 것과 충돌하는지 잘 모르겠다
	*/
}

Snake Game::getSnake() {
	return snake;
}
