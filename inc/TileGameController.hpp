#ifndef TILEGAMECONTROLLER_HPP
#define TILEGAMECONTROLLER_HPP

#include <string>
#include <map>
#include <memory>
#include <Coordinate.hpp>
#include <GameStateEnum.hpp>
#include <GameObserver.hpp>

class TileGameController
{
public:

    TileGameController();

    inline Coordinate GetPlayerLocation() { return PlayerLocation; };

    bool MovePlayer(Coordinate to);

private:

    const int maxX;
    const int maxY;


    // FUTURE: This will be included in constructor/initialazation
    // void registerObserver(GameObserver* observer) {
    //     observers.push_back(observer);
    // }

    // void notifyObservers() {
    //     for (GameObserver* observer : observers) {
    //         observer->update(temperature, humidity, pressure);
    //     }
    // }

    std::shared_ptr<std::map<Coordinate, TileState>> GameBoard;

    Coordinate PlayerLocation;
};

#endif // TILEGAMECONTROLLER_HPP
