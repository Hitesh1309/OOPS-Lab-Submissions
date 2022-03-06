// CS20B1127
// Hitesh Gupta
// Lab-10
// Basics of Java Applets.

// Importing the necessary packages.
import java.applet.Applet;  
import java.awt.*;  
  
// Defining main class and inheriting Applet class.
public class GraphicsDemo_CS20B1127 extends Applet
{  
    public void paint(Graphics g)
    {  
        g.setColor(Color.gray);     // sets the colour to gray.
        g.fillRect(0,0,1024,720);   // creates a filled rectangle.

        g.setColor(Color.black);    // sets the colour to black.
        g.drawRect(0,0,1024,720);   // creates the outline of a rectangle.
        g.fillRect(0,620,200,100);  // creates a filled rectangle.

        g.setColor(Color.darkGray); // sets the colour to dark gray.
        g.fillOval(412,260,200,200);// creates a filled oval.
        
        g.setColor(Color.green);    // sets the colour to green.
        g.drawString("CS20B1127",478,375);  // creates a string.
        g.drawString("Hitesh Gupta",475,355);

        // The below lines are used to centre the circle and not part of the question.
        // The below lines divide the window into 4 equal parts.
        g.setColor(Color.magenta);  // sets the colour to magenta.
        g.drawLine(0,360,1024,360); // creates a line.
        g.drawLine(512,0,512,720);

        g.setColor(Color.cyan); // sets the colour to cyan.
        g.drawRect(50,645,100,50);  // creates an outline of a rectangle.

        g.setColor(Color.red);  // sets the colour to red.
        g.drawOval(865,5,150,200);  // creates an outline of an oval. 

        g.setColor(Color.blue); // sets the colour to blue.
        g.fillOval(915,55,50,100);  // creates an filled oval.

    }  
}  

// The below commented lines help us view the applet without writing any html code.

/* 
<applet code="GraphicsDemo_CS20B1127.class" width="1024" height="720"> 
</applet> 
*/ 