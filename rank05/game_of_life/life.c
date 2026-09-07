#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


char **createBoard(int width, int height)
{
	char **board = malloc(sizeof(char *) * height);
	for (int y = 0; y < height; y++)
	{
		board[y] = calloc(width, sizeof(char));
	}
	return (board);
}

void initializeBoard(char **board, int width, int height)
{
    //in initialization we move the pen around and write if its int writing mod
    // we read from the stdio, and move pen, in the end we return the board
    char command;
    int x = 0;
    int y = 0;
    int pen = 0; // pen 0 not drawing, pen 1 drawing

    while (read(0, &command, 1) > 0) // read till EOF
    {

	//doin the movin here
		if (command == 'w' && y > 0) 
			--y;
		if (command == 's' && y < height - 1) 
			y++;
		if (command == 'a' && x > 0) 
			--x;
		if (command == 'd' && x < width - 1) 
			x++;
      
    //check for the writin?
		if (command == 'x')
		{
			if (!pen)
				pen = 1;
			else
				pen = 0;
		}

    //write 
		if (pen)
		{
			board[y][x] = 1;
		}

    }
}

void freeBoard(char **board, int height)
{
    for (int y = 0; y < height; y++)
		free (board[y]);
	free (board);
}

int countAliveNeihgbors(char **board, int x, int y, int width, int height)
{
  //here we need to check 3x3 grid around the cell, but not count the middle cell, and return neighbour count
	int aliveCount = 0;
	for (int dy = -1; dy <= 1; dy++)
	{
		for (int dx = -1; dx <= 1; dx++)
		{
			if (dx == 0 && dy == 0)
				continue;
			int neighbour_x = x + dx;
			int neighbour_y = y + dy;
			if (neighbour_x >= 0 && neighbour_x < width && neighbour_y >= 0 && neighbour_y < height)
			{
				if (board[neighbour_y][neighbour_x] == 1)
					aliveCount++;
            }
		}
	}
	return aliveCount;
}

char **simulateOneTurn(char **oldBoard, int width, int height)
{
  // we make a new board
	char **newboard = createBoard(width, height);
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int neighbours = countAliveNeihgbors(oldBoard, x, y, width, height);
            
            //here comes now the rules.
            //if cell is alive, and it has 2 or 3 alive neighbours it will survive. if it has less or more, it will die
            //check from oldboard, draw newboard, return new board, in the end free old board
            
            //first check is cell is alive or dead
            if (oldBoard[y][x] == 1)
            {
                if (neighbours == 2 || neighbours == 3)
                    newboard[y][x] = 1;

            }
            else // cell is dead
            {
                //reproduction if 3
                if (neighbours == 3)
                    newboard[y][x] = 1;
            }
		}
	}
	freeBoard(oldBoard, height);
	return (newboard);
}

int main (int argc, char **argv)
{
	//check argcount
	if (argc != 4 )
		return 1;
	//atoi to parse values
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	int iterations = atoi(argv[3]);
	//check values
	if (width <= 0 || height <= 0 || iterations < 0)
		return 1;
	//create grid
	char **board = createBoard(width, height);

	//draw initial state
	initializeBoard(board, width, height);

	//simulate one turn x iterations
	for (int i = 0; i < iterations; i++)
		board = simulateOneTurn(board, width, height);
	//print result
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (board[y][x] == 1)
				putchar('0');
			else
				putchar(' ');
		}
		putchar('\n');
	}

	//free board and exit
	freeBoard(board, height);
	return 0;
}
