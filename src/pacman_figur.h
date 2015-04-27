#ifndef PACMAN_FIGUR_H
#define PACMAN_FIGUR_H

#include "figur.h"
#include "rail.h"

class Pacman : public Figur {
	public:
		// constructor and destructor
		Pacman(int init_x, int init_y, float init_v, int init_wechsel_rate);
		~Pacman();
		// draw pacman
		void draw();
		
		//move pacman
		void move(int moving, float ms);

		// pacman all direction animation
		void left_pic(int cnt_pic);
		void up_pic(int cnt_pic);
		void right_pic(int cnt_pic);
		void down_pic(int cnt_pic);
		
		// for pacman die animation
		void die_pic(int cnt_pic);
		
		// animate pacman
		void animate();
		
		// moves a ghost on the defined rails
		void move_on_rails(float ms, int anz_schienen, Rail **ar_s);
		
		// returns whether pacman has stopped
		int is_pacman_stopped();
		
		// direction that pacman will next go to
		int richtung_pre;
		
		// reset pacman
		void reset();

		/* collision handling pacman <-> ghosts */
		int touch(Figur **ghost_array) const;
		
		// return the surface
		SDL_Surface* get_Surface() const;

		void check_eat_pills(int *punktestand);

		// pacman dies
		void set_dying(int dying);
		int is_dying() const;
		int die_animation();
		

	private:
		static const float PACMAN_V_FAST = 0.2f; // pacman's speed when not eating
		static const float PACMAN_V_SLOW = 0.18f; // pacman's speed while eating
		// four directions for movement
		void move_left(float ms, float max_step = 999);
		void move_up(float ms, float max_step = 999);
		void move_right(float ms, float max_step = 999);
		void move_down(float ms, float max_step = 999);
		int pacman_stopped; 
		int animation;
		int cnt_animation;
		int cnt_slow; // number of loops that pacman will stay slow
		int dying; // saves whether pacman is dying at the moment
		int die_counter; // counter for die animation
		SDL_Surface *pacman_sf;
		SDL_Surface *pacman_normal;
		SDL_Surface *pacman_links_1, *pacman_links_2, *ar_pacman_links[4];
		SDL_Surface *pacman_oben_1, *pacman_oben_2, *ar_pacman_oben[4];
		SDL_Surface *pacman_rechts_1, *pacman_rechts_2, *ar_pacman_rechts[4];
		SDL_Surface *pacman_unten_1, *pacman_unten_2, *ar_pacman_unten[4];
		SDL_Surface *ar_pacman_die[13];
};
#endif
