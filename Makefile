GCC = g++

OBJS = Main.o Point2D.o Vector2D.o GameObject.o Building.o Student.o ClassRoom.o DoctorsOffice.o Model.o GameCommand.o View.o Virus.o

default: Covid_game

Covid_game: $(OBJS)
	$(GCC) $(OBJS) -o Covid_game 

Main.o: Main.cpp
	$(GCC) -c Main.cpp

Point2D.o: Point2D.cpp
	$(GCC) -c Point2D.cpp 

Vector2D.o: Vector2D.cpp
	$(GCC) -c Vector2D.cpp

GameObject.o: GameObject.cpp
	$(GCC) -c GameObject.cpp

Building.o: Building.cpp
	$(GCC) -c Building.cpp

Student.o: Student.cpp
	$(GCC) -c Student.cpp

ClassRoom.o: ClassRoom.cpp
	$(GCC) -c ClassRoom.cpp

DoctorsOffice.o: DoctorsOffice.cpp
	$(GCC) -c DoctorsOffice.cpp

Model.o: Model.cpp
	$(GCC) -c Model.cpp

GameCommand.o: GameCommand.cpp
	$(GCC) -c GameCommand.cpp

View.o: View.cpp
	$(GCC) -c View.cpp

Virus.o: Virus.cpp
	$(GCC) -c Virus.cpp

clean:
	rm $(OBJS) Covid_game