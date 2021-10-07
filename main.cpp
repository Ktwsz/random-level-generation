#include <SDL2/SDL.h>
#include <bits/stdc++.h>

using namespace std;

#include "chunks.cpp"
#include "chunk.cpp"

int main(int argv, char** args) {

    srand(time(NULL));
	Chunk first_chunk({50, 50}, 0, chunks[(int)chunks.size()-1], {0, 0});
	first_chunk.take_field();
	first_chunk.generate_next_tilemap();
	cout<<"done2\n";

    SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 850, 850, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	bool isRunning = true;
	SDL_Event event;

	while (isRunning)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				isRunning = false;
				break;

			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					isRunning = false;
				}
			}
		}

		SDL_RenderClear(renderer);

		for (int x = 0; x < 101; x++) {
			for (int y = 0; y < 101; y++) {
				SDL_Rect rect;
				rect.x = x*8;
				rect.y = y*8;
				rect.w = 8;
				rect.h = 8;

				tuple <int, int, int> C;
				switch (field_type[x][y]) {
					case grass:
						get<0>(C) = 0; get<1>(C) = 255; get<2>(C) = 0;
						break;
					case tree:
						get<0>(C) = 236; get<1>(C) = 199; get<2>(C) = 83;
						break;
					case small_rock:
						get<0>(C) = 195; get<1>(C) = 195; get<2>(C) = 195;
						break;
					case big_rock:
						get<0>(C) = 195; get<1>(C) = 195; get<2>(C) = 195;
						break;
					case long_rock:
						get<0>(C) = 195; get<1>(C) = 195; get<2>(C) = 195;
						break;
					case fence:
						get<0>(C) = 170; get<1>(C) = 144; get<2>(C) = 64;
						break;
					case move_log:
						get<0>(C) = 208; get<1>(C) = 170; get<2>(C) = 84;
						break;
					case enemy:
						get<0>(C) = 255; get<1>(C) = 0; get<2>(C) = 0;
						break;
					default:
						get<0>(C) = 109; get<1>(C) = 208; get<2>(C) = 84;
						break;
				}
				SDL_SetRenderDrawColor(renderer, get<0>(C), get<1>(C), get<2>(C), 255);// (is_field_taken[x][y]? 0 : 255)
				SDL_RenderFillRect(renderer, &rect);
			}
		}

		//SDL_Rect rect; rect.x = 0; rect.y = 0; rect.w = 100; rect.h = 100;
		//SDL_Rect rect2; rect2.x = 100; rect2.y = 100; rect2.w = 100; rect2.h = 100;

		//SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    	//SDL_RenderFillRect(renderer, &rect);
    	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		//SDL_RenderFillRect(renderer, &rect2);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

    return 0;
}
