enum tile {
    grass=-1, 
    tree, 
    small_rock, 
    big_rock, 
    long_rock, 
    fence, 
    move_log, 
    enemy,
    nothing
};

vector <vector <vector <tile>>> chunks = {
    {{tree, tree, tree},
    {tree, small_rock, tree},
    {tree, tree, tree}},

    {{fence, grass, fence},
    {fence, tree, fence},
    {fence, grass, fence}},

    {{long_rock, grass, tree},
    {tree, long_rock, long_rock},
    {long_rock, grass, tree}},

    {{long_rock, small_rock, long_rock},
    {long_rock, tree, long_rock},
    {long_rock, grass, long_rock}},

    {{tree, grass},
    {grass, grass}},

    {{small_rock, tree},
    {tree, small_rock}},

    {{grass, small_rock},
    {grass, tree}},

    {{big_rock, big_rock},
    {big_rock, big_rock}},

    {{move_log, grass, move_log},
    {move_log, grass, move_log},
    {move_log, grass, move_log},
    {move_log, tree, move_log},
    {move_log, move_log, move_log}},

    {{big_rock, big_rock},
    {big_rock, big_rock},
    {tree, tree},
    {big_rock, big_rock},
    {big_rock, big_rock}},

    {{grass}}
};

void rotate_tile_map(vector <vector <tile>>& tile_map) {
    vector <vector <tile>> temp((int)tile_map[0].size(), vector <tile>((int)tile_map.size()));

    for (int x = 0; x < (int)temp.size(); x++) {
        for (int y = 0; y < (int)temp[0].size(); y++) {
            temp[x][y] = tile_map[y][(int)tile_map[0].size()-1-x];
        }
    }

    tile_map = temp;
}

void invert_tile_map_y(vector <vector <tile>>& tile_map) {
    for (int x = 0; x <= (int)tile_map.size()/2; x++) {
        for (int y = 0; y <= (int)tile_map[0].size()/2; y++) {
            swap(tile_map[x][y], tile_map[(int)tile_map.size()-1-x][y]);
        }
    }
}

void invert_tile_map_x(vector <vector <tile>>& tile_map) {
    for (int x = 0; x <= (int)tile_map.size()/2; x++) {
        for (int y = 0; y < (int)tile_map[0].size()/2; y++) {
            swap(tile_map[x][y], tile_map[x][(int)tile_map[0].size()-1-y]);
        }
    }
}

vector <vector <bool>> is_field_taken(101, vector <bool>(101));
vector <vector <tile>> field_type(101, vector <tile>(101, nothing));

bool check_if_field_is_taken(pair <int, int> position, pair <int, int> size) {
    //cout<<"check\n";
    for (int x = position.first; x < position.first+size.first; x++) {
        for (int y = position.second; y < position.second+size.second; y++) {
            if (is_field_taken[x][y]) return true;
        }
    }
    return false;
}