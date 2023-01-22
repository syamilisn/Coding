typedef char string[100];

struct Stats{
    int flag;
};
struct Info{
    int n;
    int m;
    int x;
    int y;
};

typedef struct Screen{
    int row;
    int col;
}screen;

typedef struct Movie{
    int id_movie;
    string name;
    string language;
}movie;