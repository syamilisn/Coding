#include <stdlib.h>
#include <unistd.h>
#include <vga.h>
#define MAXCOLOR 32

int main(void){
	int x, y, c=2;
	vga_init();
	vga_setmode(G320x200x256);
	vga_setcolor(1);
	for(x=0; x<320; x++){
		vga_drawpixel(x, 10);//paint horizontallu
		for(y=0; y<200; y++)
			vga_drawpixel(x, y);
		if(!(x % 32)){
			vga_setcolor(c++);
			if(c >= (MAXCOLOR-1))
				c=0;
		}
	}
	sleep(5);
	vga_setmode(TEXT);
	return EXIT_SUCCESS;
}
