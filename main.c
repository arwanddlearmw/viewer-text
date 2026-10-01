#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{ 
  int row, col;
  int line = 0;
  FILE *fp;
  char buffer[256];

  if(argc != 2)
  {
    printf("Usage: %s <a c file name>\n", argv[0]);
    exit(1);
  }
  
  fp = fopen(argv[1], "r");
  if(fp == NULL)
  {
    perror("Cannot open input file");
    exit(1);
  }
  
  initscr();
  getmaxyx(stdscr, row, col);
  noecho();

  while(fgets(buffer, sizeof(buffer), fp) != NULL)
  {
    int y, x;
    getyx(stdscr, y, x);
    
    if(y >= row - 2)          
    {
      mvprintw(row - 1, 0, "PRESS 'l' TO CONTINUE");  
      refresh();
      
      int key;
      do {
        key = getch();          
      } while(key != 'l' && key != 'L'); 
      
      clear();
      move(0, 0);
    }

    printw("%d- %s", ++line, buffer);
    refresh();
  }


  mvprintw(row - 1, 0, "End of file. Press any key to exit.");
  refresh();
  getch();

  endwin();
  fclose(fp);
  return 0;
}