#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Enhanced SFML Game");
    window.setFramerateLimit(60);

    sf::RectangleShape box(sf::Vector2f(50, 50));
    box.setFillColor(sf::Color::Blue);
    box.setPosition(375, 275);

    float boxSpeed = 200.0f;

    sf::Clock clock;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
    }

    sf::Text text("Hello SFML!", font, 24);
    text.setPosition(10, 10);

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && box.getPosition().x > 0) {
            box.move(-boxSpeed * dt, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && box.getPosition().x < 750) {
            box.move(boxSpeed * dt, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && box.getPosition().y > 0) {
            box.move(0, -boxSpeed * dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && box.getPosition().y < 550) {
            box.move(0, boxSpeed * dt);
        }

        // Rotate the box when the 'R' key is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            box.rotate(50.0f * dt);
        }

        // Change box color when the 'C' key is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
            sf::Color newColor(rand() % 256, rand() % 256, rand() % 256);
            box.setFillColor(newColor);
        }


        sf::Vector2f boxPosition = box.getPosition();
        text.setString("Box Position: (" + std::to_string(boxPosition.x) + ", " + std::to_string(boxPosition.y) + ")");

        window.clear();
        window.draw(box);
        window.draw(text);
        window.display();
    }

    return 0;
}
