    #include <SFML/Graphics.hpp>
    #include <time.h>
    #include <iostream>

    const int N = 6;

    // tile size
    int ts = 54;

    sf::Vector2f offset(65, 55);

    sf::Vector2i Up(0, -1);
    sf::Vector2i Down(0, 1);
    sf::Vector2i Right(1, 0);
    sf::Vector2i Left(-1, 0);

    sf::Vector2i DIR[4] = {Up, Right, Down, Left};

    // структура - труба
    struct pipe {

        std::vector <sf::Vector2i> dirs;

        int orientation;
        float angle;
        bool on;

        // конструктор
        pipe() {
            angle = 0;
        }

        void rotate() {
            for (int i = 0; i < dirs.size(); i++)
                if (dirs[i] == Up)
                    dirs[i] = Right;
                else if (dirs[i] == Right)
                    dirs[i] = Down;
                else if (dirs[i] == Down)
                    dirs[i] = Left;
                else if (dirs[i] == Left)
                    dirs[i] = Up;
        };
        bool isConnect(sf::Vector2i dir) {
            for (auto d: dirs)
                if (d == dir) return true;
            return false;
        }

    } grid[N][N];

    pipe &cell(sf::Vector2i v) {
        return grid[v.x][v.y];
    }

    bool isOut(sf::Vector2i v) {
        return !sf::IntRect(0, 0, N, N).contains(v);
    }

    void generatePuzzle() {
        std::vector <sf::Vector2i> nodes;
        nodes.push_back(sf::Vector2i(rand() % N, rand() % N));

        while (!nodes.empty()) {
            int n = rand() % nodes.size();
            sf::Vector2i v = nodes[n];
            sf::Vector2i d = DIR[rand() % 4];

            if (cell(v).dirs.size() == 3) {
                nodes.erase(nodes.begin() + n);
                continue;
            }

            if (cell(v).dirs.size() == 2) {
                if (rand() % 50)
                    continue;
            }

            bool complete = 1;
            for (auto D:DIR)
                if (!isOut(v + D) && cell(v + D).dirs.empty()) complete = 0;
            if (complete) {
                nodes.erase(nodes.begin() + n);
                continue;
            }
            if (isOut(v + d)) continue;
            if (!cell(v + d).dirs.empty()) continue;
            cell(v).dirs.push_back(d);
            cell(v + d).dirs.push_back(-d);
            nodes.push_back(v + d);
        }
    }

    void drop (sf::Vector2i v) {
        if (cell(v).on)
            return;
        cell(v).on = true;

        for (auto d: DIR)
            if (!isOut(v + d))
                if (cell(v).isConnect(d) && cell(v + d).isConnect(-d))
                drop(v + d);
    }

    int main() {

        srand(time(NULL));

        std::cout << "START!" << '\n';

        sf::RenderWindow app(sf::VideoMode(390, 390), "The Pipe Puzzle!");
        app.setFramerateLimit(60);
        sf::Texture t1, t2, t3, t4;

        t1.loadFromFile("images/background.png");
        t2.loadFromFile("images/pipes.png");
        t3.loadFromFile("images/comp.png");
        t4.loadFromFile("images/server.png");

        sf::Sprite sBackground(t1), sPipe(t2), sComp(t3), sServer(t4);

        sPipe.setOrigin(27, 27);
        sComp.setOrigin(18, 18);
        sServer.setOrigin(20, 20);

        generatePuzzle();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                pipe &p = grid[j][i];

                // find orientation
                for (int n = 4; n > 0; n--) {
                    std::string s = "";
                    for (auto d: DIR)
                        s+= p.isConnect(d) ? '1' : '0';
                    if (s == "0011" || s == "0111" || s == "0101" || s == "0010")
                        p.orientation = n;
                    p.rotate();
                }
                for(int n = 0; n < rand() % 4; n++) { //shuffle//
                    grid[j][i].orientation++;
                    grid[j][i].rotate();
                }
            }
        }

        sf::Vector2i servPos;

        while(cell(servPos).dirs.size() == 1) {
            servPos = sf::Vector2i(rand() % N, rand() % N);
        }

        sServer.setPosition(sf::Vector2f(servPos * ts));
        sServer.move(offset);

        while(app.isOpen()) {
            sf::Event e;
            while(app.pollEvent(e)) {
                if (e.type == sf::Event::Closed)
                    app.close();
                if (e.type == sf::Event::MouseButtonPressed) {
                    if (e.key.code == sf::Mouse::Left) {
                        sf::Vector2i pos = sf::Mouse::getPosition(app) + sf::Vector2i(ts / 2, ts / 2) - sf::Vector2i(offset);
                        pos /= ts;
                        // grid[pos.x][pos.y].orientation++;
                        // grid[pos.x][pos.y].rotate();
                        cell(pos).orientation++;
                        cell(pos).rotate();

                        for (int i = 0; i < N; i++){
                            for (int j = 0; j < N; j++){
                                grid[j][i].on = 0;
                            }
                        }
                        drop(sf::Vector2i(3, 3));
                    }
                }
            }

            app.clear();
            app.draw(sBackground);

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    // ссылка для укорачивания имён
                    pipe &p = grid[j][i];

                    int kind = p.dirs.size();
                    if (kind == 2 && p.dirs[0] == -p.dirs[1])
                        kind = 0;

                    // поворот
                    p.angle += 5;
                    if (p.angle > p.orientation * 90)
                        p.angle = p.orientation * 90;

                    sPipe.setTextureRect(sf::IntRect(ts * kind, 0, ts, ts));
                    sPipe.setRotation(p.angle);
                    sPipe.setPosition(j * ts, i *ts);
                    sPipe.move(offset);
                    app.draw(sPipe);

                    if (kind == 1) {
                        if (p.on)
                            sComp.setTextureRect(sf::IntRect(53, 0, 36, 36));
                        else
                            sComp.setTextureRect(sf::IntRect(0, 0, 36, 36));
                        sComp.setPosition(j * ts, i * ts);
                        sComp.move(offset);
                        app.draw(sComp);
                    }
                }
            }

            app.draw(sServer);
            app.display();
        }

        return 0;
    }