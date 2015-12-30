#include "../hd/game_hdlr.hpp"
#include "../hd/constantes.hpp"
#include <iostream>

Game_hdlr::Game_hdlr(Snake *s, sf::RenderWindow* w){
	m_s = s;
	m_w = w;
	s->affichage(w);
	dir_courante = RIGHT;
	dir_suivante = RIGHT;
	generer_food();
	food.setFillColor(sf::Color::Red);
}

bool Game_hdlr::iteration(){
	dir_courante = dir_suivante;
	Retour val = m_s->moove(dir_courante, food.getPosition().x, food.getPosition().y);
	if(val == FIN){
		std::cout << "Fin du jeu!" << std::endl;
		return false;
	}
	else if(val == FOOD){
		generer_food();
		affichage();
	}
	else
		affichage();
	return true;
}

void Game_hdlr::affichage(){
	m_w->clear(sf::Color::Black);
	m_w->draw(food);
	m_s->affichage(m_w);
}

void Game_hdlr::generer_food(){
	int x, y;
	do{
		x = (rand()%(WIND_SZ/PART_SZ))*PART_SZ;
		y = (rand()%(WIND_SZ/PART_SZ))*PART_SZ;
	}while(!m_s->check_food(x,y));
	food.setPosition(x,y);
	std::cout << x << "/" << y << std::endl;
}

void Game_hdlr::chgt_dir(Dir direction){

	switch(dir_courante){
		case RIGHT:
			if(direction != LEFT)
				dir_suivante = direction;
			break;
		case LEFT:
			if(direction != RIGHT)
				dir_suivante = direction;
			break;
		case UP:
			if(direction != DOWN)
				dir_suivante = direction;
			break;
		case DOWN:
			if(direction != UP)
				dir_suivante = direction;
			break;
	}
}
