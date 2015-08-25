#include <stdio.h>

#define MAXX 50
#define MAXY 50

/* Function to print screen to terminal */
void print_screen(char screen[MAXX][MAXY]){
	int i,	j;
	for(i =0; i < MAXX; i++){
		for(j = 0; j < MAXY; j++){
			if(screen[i][j]=='x')
				printf("x");
			else	printf(" ");
		}
		printf("\n");
	}
}

int main(int argc, char **argv) {
	int xpos = 0, ypos = 0;
	int i, j;

	// The array which stores the position of the cursor
	char screen[MAXX][MAXY];
	
	//Initialise to a blank screen
	for(i =0; i < MAXX; i++)
		for(j = 0; j < MAXY; j++)
			screen[i][j] = ' ';	
	char c;
	while(1){
		c= getchar();
		//Exit out of the program
		if(c == 'x')
			break;
		
		//The keys wasd are used to go up, left, down, roght respectively
		else if(c == 'w'){	
			xpos--;
			screen[xpos][ypos] = 'x';
		}
		else if(c == 's'){
			xpos++;
			screen[xpos][ypos] = 'x';
		}
		else if(c == 'a'){
			ypos--;
			screen[xpos][ypos] = 'x';
		}
		else if(c == 'd'){
			ypos++;
			screen[xpos][ypos] = 'x';
		}
		else
			continue;

		//Print screen after every keypress
		print_screen(screen);	
	}
	return 0;
}
