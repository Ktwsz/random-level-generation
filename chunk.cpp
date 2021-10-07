#include "chunk.h"

/*
Chunk::Chunk(pair <int, int> c_position, int c_depth, Chunk* c_previous_chunk) {
    position = c_position;
    depth = c_depth;
    previous_chunk = c_previous_chunk;

    tile_map = choose_tile_map();
    size = {(int)tile_map.size(), (int)tile_map[0].size()};
}
*/

Chunk::Chunk(pair <int, int> c_position, int c_depth, vector <vector <tile>> c_tile_map, pair <int, int> c_direction) {// Chunk* c_previous_chunk,
    position = c_position;
    depth = c_depth;
    direction = c_direction;
    //previous_chunk = c_previous_chunk;

    tile_map = c_tile_map;
    size = {(int)tile_map.size(), (int)tile_map[0].size()};
}

vector <vector <tile>> Chunk::choose_tile_map() {
    return chunks[rand()%(int)chunks.size()];
}

void Chunk::take_field() {
    for (int x = position.first; x < position.first+size.first; x++) {
        for (int y = position.second; y < position.second+size.second; y++) {
            is_field_taken[x][y] = 1;
            field_type[x][y] = tile_map[x-position.first][y-position.second];
            //cout<<field_type[x][y]<<endl;
        }
    }
}

void Chunk::generate_next_tilemap() {
    for (int x = -1; x < 2; x++) {
        for (int y = -1; y < 2; y++) {
            pair <int, int> next_inverted_direction = {-x, -y};
            if (abs(x) == abs(y) || rand()%4+1 < depth || next_inverted_direction == direction) continue;
            //cout<<"start\n";
            vector <vector <tile>> next_tile_map = choose_tile_map();
            if (rand()%2) {
                rotate_tile_map(next_tile_map);
                //if (rand()%2) invert_tile_map(next_tile_map);
            }
            //cout<<"rotate\n";

            pair <int, int> next_direction = {x, y};
            pair <int, int> next_chunk_position = position;

            if (next_direction.first == 1) next_chunk_position.first += ((rand()%2)? 1 : 2) + size.first;
            else if (next_direction.first == -1) next_chunk_position.first -= ((rand()%2)? 1 : 2) + (int)next_tile_map.size();
            else if (next_direction.second == 1) next_chunk_position.second += ((rand()%2)? 1 : 2) + size.second;
            else if (next_direction.second == -1) next_chunk_position.second -= ((rand()%2)? 1 : 2) + (int)next_tile_map[0].size();

            //cout<<"if\n";
            while (check_if_field_is_taken(next_chunk_position, {(int)next_tile_map.size(), (int)next_tile_map[0].size()})) {
                next_chunk_position.first += next_direction.first; next_chunk_position.second += next_direction.second;
            }
            //cout<<"while\n";

            Chunk next_chunk(next_chunk_position, depth+1, next_tile_map, next_direction);// this,
            next_chunk.take_field();
            next_chunk.generate_next_tilemap();
        }
    }
}
