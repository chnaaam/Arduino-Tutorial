// First, You must be open and upload the "Sample_1_MPU6050" arduino source code.
// But you should not open serial monitor because this program read through serial port.

import processing.serial.*;
Serial myPort;
 
float xRot = 0;
float yRot = 0;
 
int hWall =  30;
int wall[][] = 
    {
    {-400, -400, 800, 0}, 
    {-400, -400, 0, 800}, 
    {-400, -200, 100, 0}, 
    {-300, -300, 0, 100}, 
    {-300, -300, 100, 0}, 
    {-200, -300, 0, 100}, 
    {-100, -300, 0, 200}, 
    {0, -300, 0, 100}, 
    {100, -300, 0, 400}, 
    {100, -300, 100, 0}, 
 
    {300, -300, 0, 200}, 
    {300, -300, 100, 0}, 
    {0, -200, 100, 0}, 
    {200, -200, 100, 0}, 
    {400, -400, 0, 800}, 
    {-300, -100, 200, 0}, 
    {100, -100, 100, 0}, 
    {-300, -100, 0, 200}, 
    {-200, -100, 0, 100}, 
    {0, -100, 0, 100}, 
 
    {0, 0, 100, 0}, 
    {-100, 0, 0, 100}, 
    {200, 0, 0, 100}, 
    {300, 0, 0, 100}, 
    {-400, 100, 100, 0}, 
    {-100, 100, 400, 0}, 
    {-200, 100, 0, 200}, 
    {-300, 100, 100, 0}, 
    {200, 200, 200, 0}, 
    {-300, 200, 0, 200}, 
 
    {-100, 200, 0, 100}, 
    {0, 200, 0, 200}, 
    {100, 200, 0, 100}, 
    {-200, 300, 100, 0}, 
    {100, 300, 300, 0}, 
    {-400, 400, 700, 0}
};
 
float xBall = 50;
float yBall = -350;
float vxBall = 0;
float vyBall = 0;
 
void setup() 
{
    frameRate(40);
    size(1400, 800, P3D);
 
    println("Available serial ports:");
    println(Serial.list());
    myPort = new Serial(this, Serial.list()[1], 9600);
 
    setup2();
}
 
void setup2() 
{
    xBall = 50;
    yBall = -350;
    vxBall = 0;
    vyBall = 0;
}
 
void draw() 
{
    background(255);
 
    float fov = PI/10.0; 
    float cameraZ = (height/2.0) / tan(fov/2.0); 
    perspective(fov, float(width)/float(height), cameraZ/2.0, cameraZ*2.0); 
    camera(width/2, height/2, cameraZ, width/2, height/2, 0, 0, 1, 0);
    lights();
 
    translate(width/2, height/2);
    rotateX(1.0);
 
    pushMatrix();
 
    int nBuffer = 0;
    while  (myPort.available() > 0) 
    {
        String inBuffer = myPort.readString();
        String subBuffer[] = { "", "", ""};
        int max = 0;
        int len = inBuffer.length();
        for (int i = 0; i < len; i++)
        {
            if (inBuffer.charAt(i) == ' ')
            {
                max++;
                if (max >= 3) break;
            } else
                subBuffer[max] = subBuffer[max] + inBuffer.charAt(i);
        }
        if (max != 3) break;
 
        int x = -int(subBuffer[1]);
        if (x > 0) x = max(x - 4, 0);
        if (x < 0) x = min(x + 4, 0);           
        xRot = x/8000.0;
        xRot = constrain(xRot, -PI/7, PI/7);
 
        int y = -int(subBuffer[0]);
        if (y > 0) y = max(y - 4, 0);
        if (y < 0) y = min(y + 4, 0);           
        yRot = y/8000.0;
        yRot = constrain(yRot, -PI/7, PI/7);
    }
 
    noFill();
    stroke(0, 255, 0);
    {
        pushMatrix();
        translate(0, 0, 0);
        box(1024, 1024, 1);
        popMatrix();
    }
 
    rotateX(xRot);
    rotateY(yRot);
    fill(255);
    stroke(64);
 
    {
        pushMatrix();
        translate(0, 0, -1);
        box(800, 800, 1);
        popMatrix();
    }
 
    for (int n = 0; n < wall.length; n++)
    {
        pushMatrix();
        translate(wall[n][0] + wall[n][2]/2 - 2, wall[n][1] + wall[n][3]/2 - 2, hWall/2);
        box(wall[n][2] + 5, wall[n][3] + 5, hWall);
        popMatrix();
    }
 
    vxBall += yRot * 5;
    vyBall -= xRot * 5;
    if (abs(vxBall) >= 20) vxBall = vxBall*20/abs(vxBall);
    if (abs(vyBall) >= 20) vyBall = vyBall*20/abs(vyBall);
    xBall += vxBall;
    yBall += vyBall;
 
    float tollerence = 23;
    for (int n = 0; n < wall.length; n++)
    {
        // horizontal Wall
        if (wall[n][2] > 0)
            if ((wall[n][0] - tollerence*0.9) < xBall && (wall[n][0] + wall[n][2] + tollerence*0.9) > xBall)
            {
                if (abs(wall[n][1] - yBall) < tollerence)
                {
                    if (wall[n][1] < yBall)
                    {
                        yBall += 2;
                        vyBall = 0;
                    } else
                    {
                        yBall -= 2;
                        vyBall = 0;
                    }
                }
            }
 
        // vertical Wall
        if (wall[n][3] > 0)
            if ((wall[n][1] - tollerence*0.9) < yBall && (wall[n][1] + wall[n][3] + tollerence*0.9) > yBall)
            {
                if (abs(wall[n][0] - xBall) < tollerence)
                {
                    if (wall[n][0] < xBall)
                    {
                        xBall += 2;
                        vxBall = 0;
                    } else
                    {
                        xBall -= 2;
                        vxBall = 0;
                    }
                }
            }
    }
 
    {
        fill(255, 0, 0);
        noStroke();
        pushMatrix();
        translate(xBall, yBall, 20);
        sphere(20);
        popMatrix();
    }
 
    if (yBall > 420) setup2();
 
    popMatrix();
}
