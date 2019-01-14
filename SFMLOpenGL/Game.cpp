#include <Game.h>

bool flip = false;
int current = 1;

//Displacement Vectors
MyVector3 moveRight ={  0.001, 0, 0 };
MyVector3 moveLeft = { -0.001, 0, 0 };
MyVector3 moveUp =	 {  0, 0.001, 0 };
MyVector3 moveDown = {  0,-0.001, 0 };

MyVector3 scaleVec = { 1.1,1.1,0 };


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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		for (int i = 0; i < 36; i++)
		{

			int x = i * 3;
			int y = i * 3 + 1;
			int z = i * 3 + 2;
			MyVector3 currentVector = MyVector3{ vertices[x],vertices[y],vertices[z] };

			currentVector = currentVector + moveRight;

			vertices[x] = currentVector.getX();
			vertices[y] = currentVector.getY();
			vertices[z] = currentVector.getZ();
		}		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{

		
		for (int i = 0; i < 36; i++)
		{
			int x = i * 3;
			int y = i * 3 + 1;
			int z = i * 3 + 2;

			MyVector3 currentVector = MyVector3{ vertices[x],vertices[y],vertices[z] };

			currentVector = currentVector + moveLeft;

			vertices[x] = currentVector.getX();
			vertices[y] = currentVector.getY();
			vertices[z] = currentVector.getZ();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		for (int i = 0; i < 36; i++)
		{
			
			int x = i * 3;
			int y = i * 3 + 1;
			int z = i * 3 + 2;

			MyVector3 currentVector = MyVector3{ vertices[x],vertices[y],vertices[z] };

			currentVector = currentVector + moveUp;

			vertices[x] = currentVector.getX();
			vertices[y] = currentVector.getY();
			vertices[z] = currentVector.getZ();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		for (int i = 0; i < 36; i++)
		{

			int x = i * 3;
			int y = i * 3 + 1;
			int z = i * 3 + 2;

			MyVector3 currentVector = MyVector3{ vertices[x],vertices[y],vertices[z] };

			currentVector = currentVector + moveDown;

			vertices[x] = currentVector.getX();
			vertices[y] = currentVector.getY();
			vertices[z] = currentVector.getZ();
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		for (int i = 0; i < 36; i++)
		{

			int x = i * 3;
			int y = i * 3 + 1;
			int z = i * 3 + 2;

			MyVector3 currentVector = MyVector3{ vertices[x],vertices[y],vertices[z] };

			currentVector = MyMatrix3::scale(0.99) * currentVector;
			//currentVector = currentVector * 1.01;

			vertices[x] = currentVector.getX();
			vertices[y] = currentVector.getY();
			vertices[z] = currentVector.getZ();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		for (int i = 0; i < 36; i++)
		{

			int x = i * 3;
			int y = i * 3 + 1;
			int z = i * 3 + 2;
			

			MyVector3 currentVector = MyVector3{ vertices[x],vertices[y],vertices[z] };

			currentVector = MyMatrix3::scale(1.01) * currentVector;
			//currentVector = currentVector * 1.01;

			vertices[x] = currentVector.getX();
			vertices[y] = currentVector.getY();
			vertices[z] = currentVector.getZ();
		}
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
	{
		for (int i = 0; i < 36; i++)
		{

			int x = i * 3;
			int y = i * 3 + 1;
			int z = i * 3 + 2;

			MyVector3 currentVector = MyVector3{ vertices[x],vertices[y],vertices[z] };

			currentVector = MyMatrix3::rotationZ(0.01) * currentVector;

			vertices[x] = currentVector.getX();
			vertices[y] = currentVector.getY();
			vertices[z] = currentVector.getZ();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		for (int i = 0; i < 36; i++)
		{

			int x = i * 3;
			int y = i * 3 + 1;
			int z = i * 3 + 2;

			MyVector3 currentVector = MyVector3{ vertices[x],vertices[y],vertices[z] };

			
			currentVector = MyMatrix3::rotationZ(-0.01) * currentVector;

			vertices[x] = currentVector.getX();
			vertices[y] = currentVector.getY();
			vertices[z] = currentVector.getZ();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
	{
		for (int i = 0; i < 36; i++)
		{

			int x = i * 3;
			int y = i * 3 + 1;
			int z = i * 3 + 2;

			MyVector3 currentVector = MyVector3{ vertices[x],vertices[y],vertices[z] };

			currentVector = MyMatrix3::rotationX(0.01) * currentVector;

			vertices[x] = currentVector.getX();
			vertices[y] = currentVector.getY();
			vertices[z] = currentVector.getZ();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		for (int i = 0; i < 36; i++)
		{

			int x = i * 3;
			int y = i * 3 + 1;
			int z = i * 3 + 2;

			MyVector3 currentVector = MyVector3{ vertices[x],vertices[y],vertices[z] };


			currentVector = MyMatrix3::rotationX(-0.01) * currentVector;

			vertices[x] = currentVector.getX();
			vertices[y] = currentVector.getY();
			vertices[z] = currentVector.getZ();
		}
	}



	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Game::render()
{
	cout << "Drawing" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

