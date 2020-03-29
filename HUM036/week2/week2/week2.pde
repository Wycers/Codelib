// Author: Yechang WU, 11711918, This version is adpated from P_2_1_2_01.pde
//
// Original license description
//
// Generative Gestaltung, ISBN: 978-3-87439-759-9
// First Edition, Hermann Schmidt, Mainz, 2009
// Hartmut Bohnacker, Benedikt Gross, Julia Laub, Claudius Lazzeroni
// Copyright 2009 Hartmut Bohnacker, Benedikt Gross, Julia Laub, Claudius Lazzeroni
//
// http://www.generative-gestaltung.de
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * changing size and position of circles in a grid
 *
 * MOUSE
 * position x          : circle position
 * position y          : circle size
 * left click          : random position
 *
 * KEYS
 * s                   : save png
 * p                   : save pdf
 */

import processing.pdf.*;
import java.util.Calendar;

boolean savePDF = false;

color circleColor = color(0);
int circleAlpha = 180;
int actRandomSeed = 0;
int tileCount = 12;
float interval = 5;
float shortest = 1000;
float furthest = 0.1;

class Ball {
  float x, y;
  float shiftX, shiftY;
  float posX, posY;
  float lastUpdate;
  float r, g, b;

  Ball() {
    shiftX = random(-mouseX, mouseX)/20;
    shiftY = random(-mouseX, mouseX)/20;
    posX = x = random(0, height);
    posY = y = random(0, width);
    lastUpdate = millis();
    r = random(0, 255);
    g = random(0, 255);
    b = random(0, 255);
  }

  Ball(float x, float y) {
    this();
    this.x = x;
    this.y = y;

    this.posX = x;
    this.posY = y;
  }

  // Every interval, update posX and posY.
  void update() {
    if (millis() - lastUpdate > interval) {
      posX = posX + shiftX + random(-1, 1);
      posY = posY + shiftY + random(-1, 1);
      lastUpdate = millis();
    }
  }

  // Draw a solid circle.
  void display() {
    fill(r, g, b);
    ellipse(posX, posY, mouseY/15, mouseY/15);
  }
}

Ball[][] balls = new Ball[tileCount][tileCount];

// Calculate the distance between two balls.
double distance(Ball a, Ball b) {
  return Math.sqrt(Math.pow(a.posX - b.posX, 2) + Math.pow(a.posY - b.posY, 2));
}

// Connect two balls with a line.
void connect(Ball a, Ball b) {
  //furthest = max(furthest, (float)distance(a, b));
  //System.out.println((float)distance(a, b));
  float alpha = map((float)distance(a, b), 0, 5, 0, 1);
  stroke(0, alpha);
  line(a.posX, a.posY, b.posX, b.posY);
}

void setup() {
  size(600, 600);

  smooth();

  for (int gridY=0; gridY<tileCount; gridY++) {
    for (int gridX=0; gridX<tileCount; gridX++) {
      balls[gridY][gridX] = new Ball((float)width/tileCount * gridX, (float)height/tileCount * gridY);
    }
  }
}

void draw() {

  if (savePDF) beginRecord(PDF, timestamp()+".pdf");

  translate(width/tileCount/2, height/tileCount/2);

  background(255);
  smooth();
  noFill();

  //randomSeed(actRandomSeed);

  stroke(circleColor, circleAlpha);
  strokeWeight(mouseY/120);

  // Update balls' position.
  for (int gridY=0; gridY<tileCount; gridY++) {
    for (int gridX=0; gridX<tileCount; gridX++) {
      balls[gridY][gridX].update();
    }
  }

  // draw lines between adjacent grid.
  for (int gridY=0; gridY<tileCount; gridY++) {
    for (int gridX=0; gridX<tileCount; gridX++) {
      // Line to bottom grid
      if (gridY + 1 < tileCount) {
        connect(balls[gridY][gridX], balls[gridY + 1][gridX]);
      }
      // Line to right grid
      if (gridX + 1 < tileCount) {
        connect(balls[gridY][gridX], balls[gridY][gridX + 1]);
      }
    }
  }

  // draw colored circle at last so that the cross lines will be blocked.
  for (int gridY=0; gridY<tileCount; gridY++) {
    for (int gridX=0; gridX<tileCount; gridX++) {
      balls[gridY][gridX].display();
    }
  }

  if (savePDF) {
    savePDF = false;
    endRecord();
  }
}

void mousePressed() {
  actRandomSeed = (int) random(100000);
}

void keyReleased() {
  if (key == 's' || key == 'S') saveFrame(timestamp()+"_##.png");
  if (key == 'p' || key == 'P') savePDF = true;
}

// timestamp
String timestamp() {
  Calendar now = Calendar.getInstance();
  return String.format("%1$ty%1$tm%1$td_%1$tH%1$tM%1$tS", now);
}
