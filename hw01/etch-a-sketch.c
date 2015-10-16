#include <stdio.h>

//Maximum size of screen
#define MAXX 15
#define MAXY 15

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


//The main function - Execution starts from here:
int main(int argc, char **argv) {
	int xpos = 0, ypos = 0;
	int flag =1;
	int i, j;

	// The array which stores the position of the cursor
	char screen[MAXX][MAXY];
	
	//Initialise to a blank screen
	for(i =0; i < MAXX; i++)
		for(j = 0; j < MAXY; j++)
			screen[i][j] = ' ';	
	char c;
	
	//prompt message:
	printf("Type:\n\tw to go up\n\ta to go left\n\ts to go down\n\td to go right\n\n\tx to quit.");
	while(1){
		if(flag == 1){
			//initial coordinates:
			printf("Enter the initial coordinates of the cursor(Max x= %d and Max y= %d): ",MAXX, MAXY);
			scanf("%d\n%d",&xpos,&ypos);
			flag = 0 ;
		}
		printf("\n");
		c= getchar();
		
		//Exit out of the program
		if(c == 'x')
			break;
		
		//The keys wasd are used to go up, left, down, right respectively
		else if(c == 'w'){	
			xpos--;
			if(xpos == MAXX)		//check if the x part of cursor goes out of screen and adjust accordingly
				xpos = 0;
		 	else if(xpos < 0)
		 		xpos = MAXX-1;
			screen[xpos][ypos] = 'x';
		}
		else if(c == 's'){
			xpos++;
			if(xpos == MAXX)		//check if the x part of cursor goes out of screen and adjust accordingly
				xpos = 0;
			else if(xpos < 0)
				xpos = MAXX-1;
			screen[xpos][ypos] = 'x';
		}
		else if(c == 'a'){
			ypos--;
			if(ypos == MAXY)		//check if the y part of cursor goes out of screen and adjust accordingly
				ypos = 0;
			else if(ypos < 0)
				ypos = MAXY-1;
			screen[xpos][ypos] = 'x';
		}
		else if(c == 'd'){
			ypos++;
			if(ypos == MAXY)		//check if the y part of cursor goes out of screen and adjust accordingly
				ypos = 0;
			else if(ypos < 0)
				ypos = MAXY-1;
			screen[xpos][ypos] = 'x';
		}
        
        else if(c == 'c'){
           //clear the screen(shake)
            for(i =0; i < MAXX; i++)
                for(j = 0; j < MAXY; j++)
                    screen[i][j] = ' ';
			xpos = 0; ypos = 0; //Reset the position of the cursor
			flag = 1;
        }

		else
			continue;

		//Print screen after every keypress
		print_screen(screen);	
	}
	return 0;
}
