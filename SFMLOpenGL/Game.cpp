#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{

}

Game::~Game() {}

float vertices[] = {
							// *** FRONT FACE START ***
							 1.0f,  1.0f,  -5.0f,	//1st Tri Start 
							-1.0f,  1.0f,  -5.0f,
							-1.0f, -1.0f,  -5.0f,	//1st Tri End
							 1.0f,  1.0f,  -5.0f,	//2nd Tri Start
							 1.0f, -1.0f,  -5.0f,
							-1.0f, -1.0f,  -5.0f,	//2nd Tri End
							//  *** FRONT FACE END ***

							// *** BACK FACE START ***
							 1.0f,  1.0f, -15.0f,	//3rd Tri Start 
							-1.0f,  1.0f, -15.0f,
							-1.0f, -1.0f, -15.0f,	//3rd Tri End
							 1.0f,  1.0f, -15.0f,	//4th Tri Start
							 1.0f, -1.0f, -15.0f,
							-1.0f, -1.0f, -15.0f,	//4th Tri End  
							// *** BACK FACE END ***

							// *** LEFT FACE START ***
							-1.0f,  1.0f,  -5.0f,	//5th Tri Start
							-1.0f,  1.0f, -15.0f,
							-1.0f, -1.0f, -15.0f,	//5th Tri End
							-1.0f,  1.0f,  -5.0f,	//6th Tri Start
							-1.0f, -1.0f,  -5.0f,
							-1.0f, -1.0f, -15.0f,	//6th Tri End
							// *** LEFT FACE END ***

							// *** RIGHT FACE START ***
							 1.0f,  1.0f,  -5.0f,	//7th Tri Start
							 1.0f,  1.0f, -15.0f,
							 1.0f, -1.0f, -15.0f,	//7the Tri End
							 1.0f,  1.0f,  -5.0f,	//8th Tri Start
							 1.0f, -1.0f,  -5.0f,
							 1.0f, -1.0f, -15.0f,	//8th Tri End
							// *** RIGHT FACE END ***

							// *** TOP FACE START ***
							-1.0f,  1.0f,  -5.0f,	//9th Tri Start
							-1.0f,  1.0f, -15.0f,
							 1.0f,  1.0f, -15.0f,	//9th Tri End
							-1.0f,  1.0f,  -5.0f,	//10th Tri Start
							 1.0f,  1.0f,  -5.0f,
							 1.0f,  1.0f, -15.0f,	//10th Tri End
							// *** TOP FACE END ***

							// *** BOT FACE START ***
							-1.0f, -1.0f,  -5.0f,	//11th Tri Start
							-1.0f, -1.0f, -15.0f,
							 1.0f, -1.0f, -15.0f,	//11th Tri End
							-1.0f, -1.0f,  -5.0f,	//12th Tri Start
							 1.0f, -1.0f,  -5.0f,
							 1.0f, -1.0f, -15.0f,	//12th Tri End
							// ***BOT FACE END ***

};
float colors[] = { 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f };
unsigned int vertex_index[] = { 0, 1, 2 };

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	glDrawArrays(GL_TRIANGLES, 0, 36);

	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

