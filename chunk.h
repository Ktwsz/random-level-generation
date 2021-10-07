#pragma once

class Chunk {
    protected:
        pair <int, int> size, position;
        vector <vector <tile>> tile_map;
        int depth;
        pair <int, int> direction;
        //Chunk* previous_chunk;
        
    public:
        //Chunk(pair <int, int> c_position, int c_depth, Chunk* c_previous_chunk);
        Chunk(pair <int, int> c_position, int c_depth, vector <vector <tile>> c_tile_map, pair <int, int> c_direction);//, Chunk* c_previous_chunk
        vector <vector <tile>> choose_tile_map();
        void generate_next_tilemap();
        void take_field();
};