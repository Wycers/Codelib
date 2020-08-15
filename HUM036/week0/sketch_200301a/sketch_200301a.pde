
int anzahl=40;
import ddf.minim.*;
import ddf.minim.analysis.*;
float [] radios = new float[ 0 ];
float [] speeds = new float[ 0 ];

float speed = 0;
float r = 1500;

//the main minim object
Minim minim;
//the audio input
AudioInput in;
//the frequency analyzer
FFT fft;



void setup() {

 size(1024,768);
  //smooth();
  minim = new Minim(this);
  minim.debugOn();
   //get a line in from Minim, default bit depth is 16
  in = minim.getLineIn(Minim.STEREO, 512);

  //create frequency analyzer for the audio input
  fft = new FFT(in.bufferSize(), in.sampleRate());

  //also calculate averages of frequency amplitudes
  fft.logAverages(22, 3);
  
  //ohne dampavarage
  
}

void draw() {
  frameRate(10);
  background(0);
  stroke(255);
  fft.forward(in.mix);
    int wo=0;
  float staerke = 0;
  for(int i = 0; i < fft.avgSize(); i++) {
    if(fft.getAvg(i)>staerke) {
      staerke = fft.getAvg(i);
      wo = i;
    }
  }
   // ellipse (width/2,height/2,0 + in.mix.level() * 1500,in.mix.level() * 1500);
  //float r=in.mix.level()*900;
  if(in.mix.level() > 0.1)  {
    r = 0;
    speed = in.mix.level() * 1000;
    
    radios = append(radios, 0);
    speeds = append(speeds, in.mix.level() * 50);
  }
  
  r += speed;
  for(int i = 0; i < radios.length; i++) {
    radios[i] += speeds[i];
  }
 
  for(int x=0; x<=width; x++){
    for(int y=height/anzahl; y<=height; y=y+height/anzahl){
      boolean inRadius = false;
      for(int i = 0; i < radios.length; i++) {
         if(dist(x,y,width/2,height/2) > radios[i]-20 && dist(x,y,width/2,height/2) < radios[i]+20) {
           point(x,y + sin(map(dist(x,y,width/2,height/2),radios[i]-20,radios[i]+20,0,PI))*5);
           inRadius = true;
         }
      }  
      if(inRadius == false)  {
         point(x,y); 
      }
   } 
 } 
  
  
  for(int y=0; y<=height; y++){
   for(int x=height/anzahl; x<=width; x=x+height/anzahl){
    point(x,y);
   } 
  }  
  
}
