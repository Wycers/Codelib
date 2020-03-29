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

void setup() {
  size(600, 600);
}

void draw() {
  if (savePDF) beginRecord(PDF, timestamp()+".pdf");

  translate(width/tileCount/2, height/tileCount/2);

  background(255);
  smooth();
  noFill();

  randomSeed(actRandomSeed);

  stroke(circleColor, circleAlpha);
  strokeWeight(mouseY/120);

  // point of all grids.
  float[][] px = new float[tileCount][tileCount];
  float[][] py = new float[tileCount][tileCount];

  for (int gridY=0; gridY<tileCount; gridY++) {
    for (int gridX=0; gridX<tileCount; gridX++) {

      float posX = (float)width/tileCount * gridX;
      float posY = (float)height/tileCount * gridY;

      float shiftX = random(-mouseX, mouseX)/20;
      float shiftY = random(-mouseX, mouseX)/20;

      px[gridY][gridX] = posX+shiftX;
      py[gridY][gridX] = posY+shiftY;
    }
  }

  // draw lines between adjacent grid.
  for (int gridY=0; gridY<tileCount; gridY++) {
    for (int gridX=0; gridX<tileCount; gridX++) {
      // Line to bottom grid
      if (gridY + 1 < tileCount) {
        line(px[gridY][gridX], py[gridY][gridX], px[gridY + 1][gridX], py[gridY + 1][gridX]);
      }
      // Line to right grid
      if (gridX + 1 < tileCount) {
        line(px[gridY][gridX], py[gridY][gridX], px[gridY][gridX + 1], py[gridY][gridX + 1]);
      }
    }
  }

  // draw colored circle at last so that the cross lines will be blocked.
  for (int gridY=0; gridY<tileCount; gridY++) {
    for (int gridX=0; gridX<tileCount; gridX++) {
      // Circle with random color
      fill(random(0, 255), random(0, 255), random(0, 255));
      ellipse(px[gridY][gridX], py[gridY][gridX], mouseY/15, mouseY/15);
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
