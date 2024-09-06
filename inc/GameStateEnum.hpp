#ifndef GAMESTATEENUM_HPP
#define GAMESTATEENUM_HPP

// if tile d.n.e in game hashmap, color black
enum class TileState {
	FILLED,
	EMPTY,
    PLAYER
};

enum class LevelState {
	SUCCESS,
	FAIL,
    PROGRESS
};

#endif // GAMESTATEENUM_HPP
