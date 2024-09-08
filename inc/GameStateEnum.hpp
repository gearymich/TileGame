#ifndef GAMESTATEENUM_HPP
#define GAMESTATEENUM_HPP

// if tile d.n.e in game hashmap, color black
enum class TileState {
	NA,
	FILLED,
	EMPTY,
	PLAYER
};

enum class LevelState {
	SUCCESS,
	FAIL,
	PROGRESS
};

enum class TileShape {
	SQUARE,
	TRIANGLE,
	HEXAGON
};

#endif // GAMESTATEENUM_HPP
