#include <iostream>
#include <SFML/Graphics.hpp>

#include <chrono>

int main()
{
    std::cout << "Hello World!\n";
    auto rw = new sf::RenderWindow(
        sf::VideoMode(640, 480),
        "Hello SFML!",
        sf::Style::Default
    );
    rw->setFramerateLimit(60);

    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({ 120.f, 30.f });
    shape.setSize({ 50.f, 50.f });

    sf::Event e;
    sf::Clock clock;
    while (rw->isOpen()) {
        const auto dt = clock.restart().asMilliseconds();

        while (rw->pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                rw->close();
            }
        }

        rw->clear(sf::Color::Black);

        // doSomething(dt);
        rw->draw(shape);

        rw->display();
    }

    delete rw;
}