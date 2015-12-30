#include "../hd/snake.hpp"
#include <cstdlib>
#include <ctime>


class Game_hdlr{

	Snake *m_s;
	sf::RenderWindow *m_w;
	Dir dir_courante;
	Dir dir_suivante;
	sf::RectangleShape *food;
	
	public:
	
	Game_hdlr(sf::RenderWindow *w);
	~Game_hdlr();
	bool iteration();
	void chgt_dir(Dir direction);
	void affichage();
	void init();
	
	private:
	void generer_food();

};
