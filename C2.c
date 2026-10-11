// A basic "passable" C2 answer
//For those who didn't have their last year's log book with them!

#include <studio.h> //Probably gives an error here....
#include <math.h>

void plotval(float value, int width)
{
	int number_of_space = value * width;
			int i=0;
	for(i = number_of_space; i > 0; i--)
	{
printf(" ");
	}
		
	printf("*\n");
					return;
}
		
int main(){
	float y = 0 ;
				int x =0;
	for(int i = 0; i < 5000; i++){
		y = 0.5*sin(x*5*3.14/180)+0.5; //Ugh magic numbers
		printf("X = %i Y = %f", x, y); //Like I said, very basic.... you might want to fix the formatting

		if(x % 10 == 0)
		{
	printf("----");
		}
		else
		{
			printf(" "); //Ugh, look that that glitch in the graph!
		}
		plotval(y, 60);
		x = x+1; //Really?
	}
	
	return 0;
}