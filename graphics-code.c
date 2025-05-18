void calculator_graphic()
{
    int x = 200, y = 150, width = 50, height = 40;
    rectangle(x,y,x+width*4,y+height);                   //rectangle function to make boxes of that particular size
    outtextxy(x+10,y+10, " ");                          //outtextxy function to print the required thing at the particular place

    rectangle(x,y+height,x+width,y+2*height);
    outtextxy(x+20,y+height+10,"7");

    rectangle(x+width,y+height,x+2*width,y+2*height);
    outtextxy(x+width+20,y+height+10,"8");

    rectangle(x+2*width,y+height,x+3*width,y+2*height);
    outtextxy(x+2*width+20,y+height+10,"9");

    rectangle(x+3*width,y+height,x+4*width,y+2*height);
    outtextxy(x+3*width+15,y+height+10,"+");

    rectangle(x,y+2*height,x+width,y+3*height);
    outtextxy(x+20,y+2*height+10,"4");

    rectangle(x+width,y+2*height,x+2*width,y+3*height);
    outtextxy(x+width+20,y+2*height+10,"5");

    rectangle(x+2*width,y+2*height,x+3*width,y+3*height);
    outtextxy(x+2*width+20,y+2*height+10,"6");

    rectangle(x+3*width,y+2*height,x+4*width,y+3*height);
    outtextxy(x+3*width+15,y+2*height+10,"-");

    rectangle(x,y+3*height,x+width,y+4*height);
    outtextxy(x+20,y+3*height+10,"1");

    rectangle(x+width,y+3*height,x+2*width,y+4*height);
    outtextxy(x+width+20,y+3*height+10,"2");

    rectangle(x+2*width,y+3*height,x+3*width,y+4*height);
    outtextxy(x+2*width+20,y+3*height+10,"3");

    rectangle(x+3*width,y+3*height,x+4*width,y+4*height);
    outtextxy(x+3*width+15,y+3*height+10,"*");

    rectangle(x,y+4*height,x+width,y+5*height);
    outtextxy(x+20,y+4*height+10,"0");

    rectangle(x+width,y+4*height,x+2*width,y+5*height);
    outtextxy(x+width+20,y+4*height+10,"=");

    rectangle(x+2*width,y+4*height,x+3*width,y+5* height);
    outtextxy(x+2*width+20,y+4*height+10,".");

    rectangle(x+3*width,y+4*height,x+4*width,y+5*height);
    outtextxy(x+3*width+15,y+4*height+10,"/");
}
