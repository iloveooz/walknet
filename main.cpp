    #include <SFML/Graphics.hpp>
    #include <time.h>
    #include <iostream>

    const int N = 6;

    // tile size
    int ts = 54;

    sf::Vector2f offset(65, 55);

    // структура - труба
    struct pipe {
        int orientation;
        bool on;
    } grid[N][N];

    int main() {
        std::cout << "START!" << '\n';

        sf::RenderWindow app(sf::VideoMode(390, 390), "The Pipe Puzzle!");
        sf::Texture t1, t2;

        t1.loadFromFile("images/background.png");
        t2.loadFromFile("images/pipes.png");

        sf::Sprite sBackground(t1), sPipe(t2);

        sPipe.setOrigin(27, 27);

        while(app.isOpen()) {
            sf::Event e;
            while(app.pollEvent(e)) {
                if (e.type == sf::Event::Closed)
                    app.close();
                if (e.type == sf::Event::MouseButtonPressed) {
                    if (e.key.code == sf::Mouse::Left) {
                        sf::Vector2i pos = sf::Mouse::getPosition(app) + sf::Vector2i(ts / 2, ts / 2) - sf::Vector2i(offset);
                        pos /= ts;
                        grid[pos.x][pos.y].orientation++;
                    }
                }
            }

            app.clear();
            app.draw(sBackground);

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    pipe &p = grid[j][i];
                    sPipe.setTextureRect(sf::IntRect(ts * 2, 0, ts, ts));
                    sPipe.setRotation(p.orientation * 90);
                    sPipe.setPosition(j * ts, i *ts);
                    sPipe.move(offset);
                    app.draw(sPipe);
                }
            }

            app.display();
        }

        return 0;
    }