#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>


namespace tvd {

class Screen {
public:
    const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

private:
	SDL_Window* m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;
	Uint32 *m_frontBuffer;
	Uint32 *m_backBuffer;

	const static short RED_SHIFT = 24;
	const static short GREEN_SHIFT = 16;
	const static short BLUE_SHIFT = 8;

public:
	Screen();
	virtual ~Screen();

	bool init();
	void update();
	bool processEvents();
	void close();
	void boxBlur();
	void setPixel(int x, int y, unsigned char red, unsigned char  green, unsigned char blue) ;
	const int width() { return SCREEN_WIDTH; }
	const int height() { return SCREEN_HEIGHT; }
};

}

#endif