CXX = Main.cpp
CXX += Game.cpp
CXX += Game.hpp
CXX += Bag.cpp
CXX += Bag.hpp
CXX += Player.cpp
CXX += Player.hpp
CXX += RoomStruct.cpp
CXX += RoomStruct.hpp
CXX += Floor.cpp
CXX += Floor.hpp
CXX += WallDoor.cpp
CXX += WallDoor.hpp
CXX += WallBlack.cpp
CXX += WallBlack.hpp
CXX += WallSafe.cpp
CXX += WallSafe.hpp
CXX += WallDesk.cpp
CXX += WallDesk.hpp
CXX += Ceiling.cpp
CXX += Ceiling.hpp

PROG1 = escape
PROGS = ${PROG1}

default:
	g++ -std=c++0x ${CXX} -o escape

clean:
	rm -f ${PROGS} *.o *~
