#include <iostream>
#include <SFML\Graphics.hpp>


using namespace std;
using namespace sf;

int main() {


	bool life = true;//инициализировали логическую переменную жизни
	bool WIN = false;//инициализировали логическую переменную победы



	sf::RenderWindow window(sf::VideoMode(800, 600), "Who want to be a millioner!");
	// рисуем фон
	Image background;
	background.loadFromFile("images/background.bmp");
	Texture background_texture;
	background_texture.setSmooth(true);
	background_texture.loadFromImage(background);
	Sprite background_sprite;//создаем объект Sprite(спрайт)
	background_sprite.setTexture(background_texture);//передаём в него объект Texture (текстуры)
	sf::Vector2f targetSize(800.0f, 400.0f);
	background_sprite.setScale(
		targetSize.x / background_sprite.getLocalBounds().width,
		targetSize.y / background_sprite.getLocalBounds().height
	);
	//конец фона
	// рисуем нижнюю таблицу
	Image table_answers;
	table_answers.loadFromFile("images/table_answers.jpg");
	Texture table_answers_texture;
	table_answers_texture.setSmooth(true);
	table_answers_texture.loadFromImage(table_answers);
	Sprite table_answers_sprite;//создаем объект Sprite(спрайт)
	table_answers_sprite.setTexture(table_answers_texture);//передаём в него объект Texture (текстуры)
	sf::Vector2f table_Size(800.0f, 200.0f);
	table_answers_sprite.setScale(
		table_Size.x / table_answers_sprite.getLocalBounds().width,
		table_Size.y / table_answers_sprite.getLocalBounds().height
	);
	table_answers_sprite.setPosition(0, 400);
	// конец таблицы

	sf::Font font;//шрифт 
	font.loadFromFile("fonts/CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
	sf::Text text_question("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	//text.setColor();//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	//text.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый
	Text text_answer("", font, 20);


	const int N = 4;

	string quest[N];
	quest[0] = "Столица России?";
	quest[1] = "Столица Беларуси?";
	quest[2] = "Столица Франции?";
	quest[3] = "Столица Германии?";

	string answer[N][4];
	// --- 1 вопрос
	answer[0][0] = "Москва";
	answer[0][1] = "Тагил";
	answer[0][2] = "Минск";
	answer[0][3] = "Берлин";
	
	// --- 2 вопрос
	answer[1][0] = "Тогонрог";
	answer[1][1] = "Минск";
	answer[1][2] = "Урал";
	answer[1][3] = "Барановичи";	
	// --- 3 вопрос
	answer[2][0] = "Тогонрог";
	answer[2][1] = "Рим";
	answer[2][2] = "Лондон";
	answer[2][3] = "Париж";
	// --- 4 вопрос
	answer[3][0] = "Сыктывкар";
	answer[3][1] = "Позитив";
	answer[3][2] = "Мозырь";
	answer[3][3] = "Берлин";
	int correct_answer[N];
	correct_answer[0] = 0;
	correct_answer[1] = 1;
	correct_answer[2] = 3;
	correct_answer[3] = 3;

	int a;
	int score = 0;
	int coords[4][2] = { {117,505},{ 482,505 },{ 117,550 },{ 482,550 } };
	for (int i(0); i < 4; i++) {
		for (int j(0); j < 2; j++) {
			cout << coords[i][j] << "    ";
		}
		cout << endl;
	}

	int current_question = 0;
	while (window.isOpen())
	{
		
			if (life) {		

				sf::Vector2i localPosition = Mouse::getPosition(window);//заносим в вектор координаты мыши относительно окна (х,у)

				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();

					if (event.type == Event::MouseButtonPressed) {
						if (event.key.code == Mouse::Left) {
							// A ответ
							if ((localPosition.x > 74 && localPosition.x < 356) && (localPosition.y > 503 && localPosition.y < 533)) {
								a = 1;
								if ((a - 1) == correct_answer[current_question]) {
									current_question++;
									cout << current_question << endl;
									//cout << 1 << endl;
								}
								else {
									life = false;
								}
							}
							// B ответ
							if ((localPosition.x > 436 && localPosition.x < 719) && (localPosition.y > 503 && localPosition.y < 533)) {
								a = 2;
								if ((a - 1) == correct_answer[current_question]) {
									current_question++;
									cout << current_question << endl;
									//cout << 2 << endl;
								}
								else {
									life = false;
								}
							}
							// C ответ
							if ((localPosition.x > 74 && localPosition.x < 356) && (localPosition.y > 547 && localPosition.y < 580)) {
								a = 3;
								if ((a - 1) == correct_answer[current_question]) {	
									current_question++;
									cout << current_question << endl;
									//cout << 3 << endl;
								}
								else {
									life = false;
								}
							}
							// D ответ
							if ((localPosition.x > 436 && localPosition.x < 719) && (localPosition.y > 547 && localPosition.y < 580)) {
								a = 4;
								if ((a - 1) == correct_answer[current_question]) {	
									current_question++;
									cout << current_question << endl;
									//cout << 4 << endl;
								}
								else {
									life = false;
								}
							}


							cout << "locPos " << localPosition.x << "    locPos " << localPosition.y << endl;//посмотрите как себя ведет позиция курсора Х

						}
					}


				}
				if (Keyboard::isKeyPressed(Keyboard::Escape)) {
					window.close();
				}

				//sf::Vector2i localPosition = Mouse::getPosition(window);//заносим в вектор координаты мыши относительно окна (х,у)
				//std::cout << "locPos " << localPosition.x << "locPos " << localPosition.y << endl;//посмотрите как себя ведет позиция курсора Х		

				//ответ позиции А
				//text_answer.setString("Собрано камней:");//задает строку тексту
				//text_answer.setPosition(117, 505);//задаем позицию текста, центр камеры
				//ответ позиции B
				//text_answer.setString("Собрано камней:");//задает строку тексту
				//text_answer.setPosition(482, 505);//задаем позицию текста, центр камеры
				//ответ позиции C
				//text_answer.setString("Собрано камней:");//задает строку тексту
				//text_answer.setPosition(117, 550);//задаем позицию текста, центр камеры
				//ответ позиции D
				//text_answer.setString("Собрано камней:");//задает строку тексту
				//text_answer.setPosition(482, 550);//задаем позицию текста, центр камеры


				window.clear(Color::Blue); //фон
				window.draw(background_sprite); // фон
				window.draw(table_answers_sprite); //нижняя таблица

				if (current_question != N) {
					text_question.setString(quest[current_question]);//задает строку тексту
					text_question.setPosition(117, 440);//задаем позицию текста, центр камеры
					window.draw(text_question);//рисую этот текст
					for (int j(0); j < 4; j++) {
						text_answer.setString(answer[current_question][j]);//задает строку тексту
						text_answer.setPosition(coords[j][0], coords[j][1]);//задаем позицию текста, центр камеры
						window.draw(text_answer);//рисую этот текст
					}
				}
				else {
					cout << "WIN" << endl;
					life = false;
					WIN = true;					
				}
								

				window.display();
			}
			else {
				if (!WIN) {
					// рисуем фон гамаовера
					Image Game_over;
					Game_over.loadFromFile("images/gameover.jpg");
					Texture Game_over_texture;
					Game_over_texture.setSmooth(true);
					Game_over_texture.loadFromImage(Game_over);
					Sprite Game_over_sprite;//создаем объект Sprite(спрайт)
					Game_over_sprite.setTexture(Game_over_texture);//передаём в него объект Texture (текстуры)
					sf::Vector2f Game_over_sprite_Size(800.0f, 600.0f);
					Game_over_sprite.setScale(
						Game_over_sprite_Size.x / Game_over_sprite.getLocalBounds().width,
						Game_over_sprite_Size.y / Game_over_sprite.getLocalBounds().height
					);

					
					Image again_button;
					again_button.loadFromFile("images/again.png");
					Texture again_button_texture;
					again_button_texture.setSmooth(true);
					again_button_texture.loadFromImage(again_button);
					Sprite again_button_sprite;//создаем объект Sprite(спрайт)
					again_button_sprite.setTexture(again_button_texture);//передаём в него объект Texture (текстуры)
					again_button_sprite.setPosition(290, 380);					
					sf::Event event;
					while (window.pollEvent(event)) {
						if (event.type == sf::Event::Closed)
							window.close();
						if (event.type == Event::MouseButtonPressed) {
							if (event.key.code == Mouse::Left) {
								sf::Vector2i localPosition = Mouse::getPosition(window);//заносим в вектор координаты мыши относительно окна (х,у)
								Vector2f pos = window.mapPixelToCoords(localPosition);//переводим их в игровые (уходим от коорд окна)
								if (again_button_sprite.getGlobalBounds().contains(localPosition.x, localPosition.y)) {
									life = true;
									WIN = false;
									current_question = 0;
								}

								cout << localPosition.x << "  " << localPosition.y << endl;
							}
						}
					}
					
					window.clear();
					window.draw(Game_over_sprite);
					window.draw(again_button_sprite);
					window.display();
					//конец фона гамаовера
				}
				else {
					// рисуем фон WINa
					Image Game_win;
					Game_win.loadFromFile("images/winpic.jpg");
					Texture Game_win_texture;
					Game_win_texture.setSmooth(true);
					Game_win_texture.loadFromImage(Game_win);
					Sprite Game_win_sprite;//создаем объект Sprite(спрайт)
					Game_win_sprite.setTexture(Game_win_texture);//передаём в него объект Texture (текстуры)
					sf::Vector2f Game_win_sprite_Size(800.0f, 600.0f);
					Game_win_sprite.setScale(
						Game_win_sprite_Size.x / Game_win_sprite.getLocalBounds().width,
						Game_win_sprite_Size.y / Game_win_sprite.getLocalBounds().height
					);
					if (Keyboard::isKeyPressed(Keyboard::Escape)) {
						window.close();
					}
					window.clear();
					window.draw(Game_win_sprite);					
					//конец фона WINa
					Text win_text("", font, 50);
					win_text.setString("ПОБЕДА");//задает строку тексту
					win_text.setPosition(300, 300);//задаем позицию текста, центр камеры
					window.draw(win_text);//рисую этот текст
					

										  // рисуем фон
					Image again_button;
					again_button.loadFromFile("images/again.png");
					Texture again_button_texture;
					again_button_texture.setSmooth(true);
					again_button_texture.loadFromImage(again_button);
					Sprite again_button_sprite;//создаем объект Sprite(спрайт)
					again_button_sprite.setTexture(again_button_texture);//передаём в него объект Texture (текстуры)
					again_button_sprite.setPosition(290, 380);
					sf::Event event;
					while (window.pollEvent(event)) {
						if (event.type == sf::Event::Closed)
							window.close();
						if (event.type == Event::MouseButtonPressed) {
							if (event.key.code == Mouse::Left) {
								sf::Vector2i localPosition = Mouse::getPosition(window);//заносим в вектор координаты мыши относительно окна (х,у)
								Vector2f pos = window.mapPixelToCoords(localPosition);//переводим их в игровые (уходим от коорд окна)
								if (again_button_sprite.getGlobalBounds().contains(localPosition.x, localPosition.y)) {
									life = true;
									WIN = false;
									current_question = 0;
								}
								cout << localPosition.x << "  " << localPosition.y << endl;
							}
						}
					}


					window.draw(again_button_sprite);
					window.display();
				}
				
			}
		
	}
	return 0;
}