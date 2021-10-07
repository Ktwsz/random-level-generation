#include <bits/stdc++.h>

using namespace std;

#include "chunks.cpp"
#include "chunk.cpp"

int main() {

    srand(time(NULL));

    Chunk first_chunk({50, 50}, 0, chunks[(int)chunks.size()-1], {0, 0});
    first_chunk.take_field();
    cout<<"done1"<<endl;
    first_chunk.generate_next_tilemap();
    cout<<"done2"<<endl;

    /*vector <vector <tile>> test = chunks[8];
    for (auto& x: test) {
        for (auto& y: x) cout<<y<<" ";
        cout<<endl;
    }
    cout<<"---------------"<<endl;

    vector <vector <tile>> test1 = chunks[8];
    invert_tile_map_y(test1);
    for (auto& x: test1) {
        for (auto& y: x) cout<<y<<" ";
        cout<<endl;
    }
    cout<<"---------------"<<endl;

    vector <vector <tile>> test2 = chunks[8];
    rotate_tile_map(test2);
    for (auto& x: test2) {
        for (auto& y: x) cout<<y<<" ";
        cout<<endl;
    }
    cout<<"---------------"<<endl;

    invert_tile_map_x(test2);
    for (auto& x: test2) {
        for (auto& y: x) cout<<y<<" ";
        cout<<endl;
    }
    cout<<"---------------"<<endl;*/

    return 0;
}
