all:
	g++ main.cpp snake.cpp board.cpp snakeView.cpp controllerAndEngine.cpp -o snake.exe -DSFML_STATIC -I C:\Users\konra\CLionProjects\SNAKE_WINDOWS_SFML\SFML\include -L C:\Users\konra\CLionProjects\SNAKE_WINDOWS_SFML\SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype
