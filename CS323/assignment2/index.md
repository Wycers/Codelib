### Exercise 1

Design NFAs and DFAs to recognize each of the following regular languages:


1. $ L((a|b)^*b)$ [10 points]
	NFA:

   <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="149.5" cy="148.5" rx="30" ry="30"/>
   	<text x="144.5" y="154.5" font-family="Times New Roman" font-size="20">0</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="261.5" cy="148.5" rx="30" ry="30"/>
   	<text x="256.5" y="154.5" font-family="Times New Roman" font-size="20">1</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="261.5" cy="148.5" rx="24" ry="24"/>
   	<polygon stroke="black" stroke-width="1" points="77.5,148.5 119.5,148.5"/>
   	<text x="22.5" y="154.5" font-family="Times New Roman" font-size="20">start</text>
   	<polygon fill="black" stroke-width="1" points="119.5,148.5 111.5,143.5 111.5,153.5"/>
   	<path stroke="black" stroke-width="1" fill="none" d="M 136.275,121.703 A 22.5,22.5 0 1 1 162.725,121.703"/>
   	<text x="144.5" y="72.5" font-family="Times New Roman" font-size="20">a</text>
   	<polygon fill="black" stroke-width="1" points="162.725,121.703 171.473,118.17 163.382,112.292"/>
   	<path stroke="black" stroke-width="1" fill="none" d="M 162.725,175.297 A 22.5,22.5 0 1 1 136.275,175.297"/>
   	<text x="144.5" y="237.5" font-family="Times New Roman" font-size="20">b</text>
   	<polygon fill="black" stroke-width="1" points="136.275,175.297 127.527,178.83 135.618,184.708"/>
   	<polygon stroke="black" stroke-width="1" points="179.5,148.5 231.5,148.5"/>
   	<polygon fill="black" stroke-width="1" points="231.5,148.5 223.5,143.5 223.5,153.5"/>
   	<text x="200.5" y="169.5" font-family="Times New Roman" font-size="20">b</text>
   </svg>



   DFA:

   <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="149.5" cy="148.5" rx="30" ry="30"/>
   	<text x="144.5" y="154.5" font-family="Times New Roman" font-size="20">0</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="269.5" cy="148.5" rx="30" ry="30"/>
   	<text x="264.5" y="154.5" font-family="Times New Roman" font-size="20">1</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="269.5" cy="148.5" rx="24" ry="24"/>
   	<polygon stroke="black" stroke-width="1" points="77.5,148.5 119.5,148.5"/>
   	<text x="22.5" y="154.5" font-family="Times New Roman" font-size="20">start</text>
   	<polygon fill="black" stroke-width="1" points="119.5,148.5 111.5,143.5 111.5,153.5"/>
   	<path stroke="black" stroke-width="1" fill="none" d="M 136.275,121.703 A 22.5,22.5 0 1 1 162.725,121.703"/>
   	<text x="144.5" y="72.5" font-family="Times New Roman" font-size="20">a</text>
   	<polygon fill="black" stroke-width="1" points="162.725,121.703 171.473,118.17 163.382,112.292"/>
   	<path stroke="black" stroke-width="1" fill="none" d="M 241.62,159.389 A 127.492,127.492 0 0 1 177.38,159.389"/>
   	<polygon fill="black" stroke-width="1" points="241.62,159.389 232.618,156.565 235.138,166.243"/>
   	<text x="204.5" y="184.5" font-family="Times New Roman" font-size="20">b</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 178.335,140.366 A 168.57,168.57 0 0 1 240.665,140.366"/>
   	<polygon fill="black" stroke-width="1" points="178.335,140.366 187.122,143.801 185.273,133.973"/>
   	<text x="204.5" y="128.5" font-family="Times New Roman" font-size="20">a</text>
   </svg>

2. $L(((\epsilon|a)^*b)^* )$ [10 points]

   NFA & DFA are both:


   <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="233.5" cy="149.5" rx="30" ry="30"/>
   	<text x="228.5" y="155.5" font-family="Times New Roman" font-size="20">1</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="133.5" cy="149.5" rx="30" ry="30"/>
   	<text x="128.5" y="155.5" font-family="Times New Roman" font-size="20">0</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="133.5" cy="149.5" rx="24" ry="24"/>
   	<path stroke="black" stroke-width="1" fill="none" d="M 220.275,122.703 A 22.5,22.5 0 1 1 246.725,122.703"/>
   	<text x="228.5" y="73.5" font-family="Times New Roman" font-size="20">a</text>
   	<polygon fill="black" stroke-width="1" points="246.725,122.703 255.473,119.17 247.382,113.292"/>
   	<path stroke="black" stroke-width="1" fill="none" d="M 159.585,135.062 A 77.761,77.761 0 0 1 207.415,135.062"/>
   	<polygon fill="black" stroke-width="1" points="159.585,135.062 168.735,137.36 165.66,127.844"/>
   	<text x="178.5" y="122.5" font-family="Times New Roman" font-size="20">b</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 208.644,165.884 A 69.874,69.874 0 0 1 158.356,165.884"/>
   	<polygon fill="black" stroke-width="1" points="208.644,165.884 199.38,164.097 202.979,173.428"/>
   	<text x="178.5" y="191.5" font-family="Times New Roman" font-size="20">a</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 120.275,122.703 A 22.5,22.5 0 1 1 146.725,122.703"/>
   	<text x="128.5" y="73.5" font-family="Times New Roman" font-size="20">b</text>
   	<polygon fill="black" stroke-width="1" points="146.725,122.703 155.473,119.17 147.382,113.292"/>
   	<polygon stroke="black" stroke-width="1" points="62.5,149.5 103.5,149.5"/>
   	<text x="7.5" y="155.5" font-family="Times New Roman" font-size="20">start</text>
   	<polygon fill="black" stroke-width="1" points="103.5,149.5 95.5,144.5 95.5,154.5"/>
   </svg>

3. $L((a|b)^*a(a|b)(a|b)) $ [10 points]

   NFA：


   <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="147.5" cy="148.5" rx="30" ry="30"/>
   	<text x="142.5" y="154.5" font-family="Times New Roman" font-size="20">0</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="244.5" cy="148.5" rx="30" ry="30"/>
   	<text x="239.5" y="154.5" font-family="Times New Roman" font-size="20">1</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="338.5" cy="148.5" rx="30" ry="30"/>
   	<text x="333.5" y="154.5" font-family="Times New Roman" font-size="20">2</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="435.5" cy="148.5" rx="30" ry="30"/>
   	<text x="430.5" y="154.5" font-family="Times New Roman" font-size="20">3</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="435.5" cy="148.5" rx="24" ry="24"/>
   	<polygon stroke="black" stroke-width="1" points="76.5,148.5 117.5,148.5"/>
   	<text x="21.5" y="154.5" font-family="Times New Roman" font-size="20">start</text>
   	<polygon fill="black" stroke-width="1" points="117.5,148.5 109.5,143.5 109.5,153.5"/>
   	<path stroke="black" stroke-width="1" fill="none" d="M 134.275,121.703 A 22.5,22.5 0 1 1 160.725,121.703"/>
   	<text x="142.5" y="72.5" font-family="Times New Roman" font-size="20">a</text>
   	<polygon fill="black" stroke-width="1" points="160.725,121.703 169.473,118.17 161.382,112.292"/>
   	<path stroke="black" stroke-width="1" fill="none" d="M 160.725,175.297 A 22.5,22.5 0 1 1 134.275,175.297"/>
   	<text x="142.5" y="237.5" font-family="Times New Roman" font-size="20">b</text>
   	<polygon fill="black" stroke-width="1" points="134.275,175.297 125.527,178.83 133.618,184.708"/>
   	<polygon stroke="black" stroke-width="1" points="177.5,148.5 214.5,148.5"/>
   	<polygon fill="black" stroke-width="1" points="214.5,148.5 206.5,143.5 206.5,153.5"/>
   	<text x="191.5" y="169.5" font-family="Times New Roman" font-size="20">a</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 269.46,132.337 A 65.225,65.225 0 0 1 313.54,132.337"/>
   	<polygon fill="black" stroke-width="1" points="313.54,132.337 307.7,124.927 304.321,134.339"/>
   	<text x="286.5" y="119.5" font-family="Times New Roman" font-size="20">a</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 313.083,163.97 A 67.613,67.613 0 0 1 269.917,163.97"/>
   	<polygon fill="black" stroke-width="1" points="313.083,163.97 303.906,161.785 307.098,171.262"/>
   	<text x="286.5" y="188.5" font-family="Times New Roman" font-size="20">b</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 364.497,133.941 A 74.169,74.169 0 0 1 409.503,133.941"/>
   	<polygon fill="black" stroke-width="1" points="409.503,133.941 403.397,126.75 400.363,136.278"/>
   	<text x="382.5" y="121.5" font-family="Times New Roman" font-size="20">a</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 410.36,164.431 A 68.754,68.754 0 0 1 363.64,164.431"/>
   	<polygon fill="black" stroke-width="1" points="410.36,164.431 401.137,162.447 404.535,171.852"/>
   	<text x="382.5" y="189.5" font-family="Times New Roman" font-size="20">b</text>
   </svg>


   DFA:

   <svg width="800" height="330" version="1.1" xmlns="http://www.w3.org/2000/svg">
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="147.5" cy="148.5" rx="30" ry="30"/>
   	<text x="142.5" y="154.5" font-family="Times New Roman" font-size="20">0</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="244.5" cy="148.5" rx="30" ry="30"/>
   	<text x="239.5" y="154.5" font-family="Times New Roman" font-size="20">1</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="337.5" cy="96.5" rx="30" ry="30"/>
   	<text x="332.5" y="102.5" font-family="Times New Roman" font-size="20">2</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="337.5" cy="227.5" rx="30" ry="30"/>
   	<text x="332.5" y="233.5" font-family="Times New Roman" font-size="20">3</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="433.5" cy="39.5" rx="30" ry="30"/>
   	<text x="428.5" y="45.5" font-family="Times New Roman" font-size="20">4</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="433.5" cy="39.5" rx="24" ry="24"/>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="433.5" cy="119.5" rx="30" ry="30"/>
   	<text x="428.5" y="125.5" font-family="Times New Roman" font-size="20">5</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="433.5" cy="119.5" rx="24" ry="24"/>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="433.5" cy="204.5" rx="30" ry="30"/>
   	<text x="428.5" y="210.5" font-family="Times New Roman" font-size="20">6</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="433.5" cy="204.5" rx="24" ry="24"/>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="433.5" cy="283.5" rx="30" ry="30"/>
   	<text x="428.5" y="289.5" font-family="Times New Roman" font-size="20">7</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="433.5" cy="283.5" rx="24" ry="24"/>
   	<polygon stroke="black" stroke-width="1" points="76.5,148.5 117.5,148.5"/>
   	<text x="21.5" y="154.5" font-family="Times New Roman" font-size="20">start</text>
   	<polygon fill="black" stroke-width="1" points="117.5,148.5 109.5,143.5 109.5,153.5"/>
   	<path stroke="black" stroke-width="1" fill="none" d="M 134.275,121.703 A 22.5,22.5 0 1 1 160.725,121.703"/>
   	<text x="142.5" y="72.5" font-family="Times New Roman" font-size="20">b</text>
   	<polygon fill="black" stroke-width="1" points="160.725,121.703 169.473,118.17 161.382,112.292"/>
   	<polygon stroke="black" stroke-width="1" points="177.5,148.5 214.5,148.5"/>
   	<polygon fill="black" stroke-width="1" points="214.5,148.5 206.5,143.5 206.5,153.5"/>
   	<text x="191.5" y="169.5" font-family="Times New Roman" font-size="20">a</text>
   	<polygon stroke="black" stroke-width="1" points="270.685,133.859 311.315,111.141"/>
   	<polygon fill="black" stroke-width="1" points="311.315,111.141 301.892,110.681 306.773,119.409"/>
   	<text x="295.5" y="143.5" font-family="Times New Roman" font-size="20">a</text>
   	<polygon stroke="black" stroke-width="1" points="267.364,167.922 314.636,208.078"/>
   	<polygon fill="black" stroke-width="1" points="314.636,208.078 311.776,199.088 305.302,206.709"/>
   	<text x="275.5" y="208.5" font-family="Times New Roman" font-size="20">b</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 362.102,210.532 A 99.426,99.426 0 0 1 403.879,200.523"/>
   	<polygon fill="black" stroke-width="1" points="403.879,200.523 395.794,195.663 395.968,205.661"/>
   	<text x="370.5" y="193.5" font-family="Times New Roman" font-size="20">a</text>
   	<polygon stroke="black" stroke-width="1" points="363.413,242.616 407.587,268.384"/>
   	<polygon fill="black" stroke-width="1" points="407.587,268.384 403.196,260.034 398.157,268.672"/>
   	<text x="370.5" y="276.5" font-family="Times New Roman" font-size="20">b</text>
   	<polygon stroke="black" stroke-width="1" points="363.296,81.184 407.704,54.816"/>
   	<polygon fill="black" stroke-width="1" points="407.704,54.816 398.273,54.601 403.378,63.2"/>
   	<text x="390.5" y="89.5" font-family="Times New Roman" font-size="20">a</text>
   	<polygon stroke="black" stroke-width="1" points="366.674,103.49 404.326,112.51"/>
   	<polygon fill="black" stroke-width="1" points="404.326,112.51 397.711,105.784 395.381,115.509"/>
   	<text x="373.5" y="129.5" font-family="Times New Roman" font-size="20">b</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 460.297,26.275 A 22.5,22.5 0 1 1 460.297,52.725"/>
   	<text x="506.5" y="45.5" font-family="Times New Roman" font-size="20">a</text>
   	<polygon fill="black" stroke-width="1" points="460.297,52.725 463.83,61.473 469.708,53.382"/>
   	<path stroke="black" stroke-width="1" fill="none" d="M 408.072,299.354 A 179.076,179.076 0 0 1 151.422,178.207"/>
   	<polygon fill="black" stroke-width="1" points="151.422,178.207 148.244,187.09 158.013,184.956"/>
   	<text x="235.5" y="323.5" font-family="Times New Roman" font-size="20">b</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 405.839,294.936 A 128.464,128.464 0 0 1 242.654,178.375"/>
   	<polygon fill="black" stroke-width="1" points="242.654,178.375 238.102,186.638 248.086,186.088"/>
   	<text x="281.5" y="296.5" font-family="Times New Roman" font-size="20">a</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 462.969,124.147 A 82.029,82.029 0 0 1 462.969,278.853"/>
   	<polygon fill="black" stroke-width="1" points="462.969,278.853 472.177,280.905 468.849,271.475"/>
   	<text x="522.5" y="207.5" font-family="Times New Roman" font-size="20">b</text>
   	<polygon stroke="black" stroke-width="1" points="433.5,149.5 433.5,174.5"/>
   	<polygon fill="black" stroke-width="1" points="433.5,174.5 438.5,166.5 428.5,166.5"/>
   	<text x="438.5" y="168.5" font-family="Times New Roman" font-size="20">a</text>
   	<polygon stroke="black" stroke-width="1" points="413.569,182.078 357.431,118.922"/>
   	<polygon fill="black" stroke-width="1" points="357.431,118.922 359.009,128.223 366.483,121.58"/>
   	<text x="370.5" y="171.5" font-family="Times New Roman" font-size="20">a</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 406.994,218.432 A 142.318,142.318 0 0 1 367.442,227.908"/>
   	<polygon fill="black" stroke-width="1" points="367.442,227.908 375.866,232.154 374.95,222.196"/>
   	<text x="389.5" y="246.5" font-family="Times New Roman" font-size="20">b</text>
   	<polygon stroke="black" stroke-width="1" points="433.5,69.5 433.5,89.5"/>
   	<polygon fill="black" stroke-width="1" points="433.5,89.5 438.5,81.5 428.5,81.5"/>
   	<text x="438.5" y="85.5" font-family="Times New Roman" font-size="20">b</text>
   </svg>



4. $L(a^*ba^*ba^*ba^* )$ [10 points]

   NFA & DFA are both:

   <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="147.5" cy="148.5" rx="30" ry="30"/>
   	<text x="142.5" y="154.5" font-family="Times New Roman" font-size="20">0</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="248.5" cy="150.5" rx="30" ry="30"/>
   	<text x="243.5" y="156.5" font-family="Times New Roman" font-size="20">1</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="338.5" cy="150.5" rx="30" ry="30"/>
   	<text x="333.5" y="156.5" font-family="Times New Roman" font-size="20">2</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="441.5" cy="150.5" rx="30" ry="30"/>
   	<text x="436.5" y="156.5" font-family="Times New Roman" font-size="20">3</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="441.5" cy="150.5" rx="24" ry="24"/>
   	<polygon stroke="black" stroke-width="1" points="76.5,148.5 117.5,148.5"/>
   	<text x="21.5" y="154.5" font-family="Times New Roman" font-size="20">start</text>
   	<polygon fill="black" stroke-width="1" points="117.5,148.5 109.5,143.5 109.5,153.5"/>
   	<path stroke="black" stroke-width="1" fill="none" d="M 134.275,121.703 A 22.5,22.5 0 1 1 160.725,121.703"/>
   	<text x="142.5" y="72.5" font-family="Times New Roman" font-size="20">a</text>
   	<polygon fill="black" stroke-width="1" points="160.725,121.703 169.473,118.17 161.382,112.292"/>
   	<polygon stroke="black" stroke-width="1" points="177.494,149.094 218.506,149.906"/>
   	<polygon fill="black" stroke-width="1" points="218.506,149.906 210.606,144.749 210.408,154.747"/>
   	<text x="192.5" y="170.5" font-family="Times New Roman" font-size="20">b</text>
   	<polygon stroke="black" stroke-width="1" points="278.5,150.5 308.5,150.5"/>
   	<polygon fill="black" stroke-width="1" points="308.5,150.5 300.5,145.5 300.5,155.5"/>
   	<text x="288.5" y="171.5" font-family="Times New Roman" font-size="20">b</text>
   	<polygon stroke="black" stroke-width="1" points="368.5,150.5 411.5,150.5"/>
   	<polygon fill="black" stroke-width="1" points="411.5,150.5 403.5,145.5 403.5,155.5"/>
   	<text x="385.5" y="171.5" font-family="Times New Roman" font-size="20">b</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 428.275,123.703 A 22.5,22.5 0 1 1 454.725,123.703"/>
   	<text x="436.5" y="74.5" font-family="Times New Roman" font-size="20">a</text>
   	<polygon fill="black" stroke-width="1" points="454.725,123.703 463.473,120.17 455.382,114.292"/>
   	<path stroke="black" stroke-width="1" fill="none" d="M 325.275,123.703 A 22.5,22.5 0 1 1 351.725,123.703"/>
   	<text x="333.5" y="74.5" font-family="Times New Roman" font-size="20">a</text>
   	<polygon fill="black" stroke-width="1" points="351.725,123.703 360.473,120.17 352.382,114.292"/>
   	<path stroke="black" stroke-width="1" fill="none" d="M 235.275,123.703 A 22.5,22.5 0 1 1 261.725,123.703"/>
   	<text x="243.5" y="74.5" font-family="Times New Roman" font-size="20">a</text>
   	<polygon fill="black" stroke-width="1" points="261.725,123.703 270.473,120.17 262.382,114.292"/>
   </svg>


### Exercise 2

Convert the following regular expressions to NFAs using the Thompson’s Construction Algorithm (Algorithm 3.23 in the dragon book). Please put down the detailed steps.

1. $((\epsilon|a)^*b)^*$ [10 points]

   1. <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="210.5" cy="132.5" rx="30" ry="30"/>
         	<text x="205.5" y="138.5" font-family="Times New Roman" font-size="20">0</text>
         	<ellipse stroke="black" stroke-width="1" fill="none" cx="318.5" cy="132.5" rx="30" ry="30"/>
         	<text x="313.5" y="138.5" font-family="Times New Roman" font-size="20">1</text>
         	<ellipse stroke="black" stroke-width="1" fill="none" cx="318.5" cy="132.5" rx="24" ry="24"/>
         	<ellipse stroke="black" stroke-width="1" fill="none" cx="210.5" cy="211.5" rx="30" ry="30"/>
         	<text x="205.5" y="217.5" font-family="Times New Roman" font-size="20">2</text>
         	<ellipse stroke="black" stroke-width="1" fill="none" cx="318.5" cy="211.5" rx="30" ry="30"/>
         	<text x="313.5" y="217.5" font-family="Times New Roman" font-size="20">3</text>
         	<ellipse stroke="black" stroke-width="1" fill="none" cx="318.5" cy="211.5" rx="24" ry="24"/>
         	<polygon stroke="black" stroke-width="1" points="240.5,132.5 288.5,132.5"/>
         	<polygon fill="black" stroke-width="1" points="288.5,132.5 280.5,127.5 280.5,137.5"/>
         	<text x="254.5" y="123.5" font-family="Times New Roman" font-size="20">&#949;</text>
         	<polygon stroke="black" stroke-width="1" points="240.5,211.5 288.5,211.5"/>
         	<polygon fill="black" stroke-width="1" points="288.5,211.5 280.5,206.5 280.5,216.5"/>
         	<text x="259.5" y="202.5" font-family="Times New Roman" font-size="20">a</text>
         	<polygon stroke="black" stroke-width="1" points="133.5,132.5 180.5,132.5"/>
         	<text x="78.5" y="138.5" font-family="Times New Roman" font-size="20">start</text>
         	<polygon fill="black" stroke-width="1" points="180.5,132.5 172.5,127.5 172.5,137.5"/>
         	<polygon stroke="black" stroke-width="1" points="132.5,211.5 180.5,211.5"/>
         	<text x="77.5" y="217.5" font-family="Times New Roman" font-size="20">start</text>
         	<polygon fill="black" stroke-width="1" points="180.5,211.5 172.5,206.5 172.5,216.5"/>
      </svg>

   2. <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
        	<ellipse stroke="black" stroke-width="1" fill="none" cx="210.5" cy="132.5" rx="30" ry="30"/>
             	<text x="205.5" y="138.5" font-family="Times New Roman" font-size="20">0</text>
             	<ellipse stroke="black" stroke-width="1" fill="none" cx="318.5" cy="132.5" rx="30" ry="30"/>
             	<text x="313.5" y="138.5" font-family="Times New Roman" font-size="20">1</text>
             	<ellipse stroke="black" stroke-width="1" fill="none" cx="210.5" cy="211.5" rx="30" ry="30"/>
             	<text x="205.5" y="217.5" font-family="Times New Roman" font-size="20">2</text>
             	<ellipse stroke="black" stroke-width="1" fill="none" cx="318.5" cy="211.5" rx="30" ry="30"/>
             	<text x="313.5" y="217.5" font-family="Times New Roman" font-size="20">3</text>
             	<ellipse stroke="black" stroke-width="1" fill="none" cx="121.5" cy="177.5" rx="30" ry="30"/>
             	<text x="116.5" y="183.5" font-family="Times New Roman" font-size="20">4</text>
             	<ellipse stroke="black" stroke-width="1" fill="none" cx="409.5" cy="177.5" rx="30" ry="30"/>
             	<text x="404.5" y="183.5" font-family="Times New Roman" font-size="20">5</text>
             	<ellipse stroke="black" stroke-width="1" fill="none" cx="409.5" cy="177.5" rx="24" ry="24"/>
             	<polygon stroke="black" stroke-width="1" points="240.5,132.5 288.5,132.5"/>
             	<polygon fill="black" stroke-width="1" points="288.5,132.5 280.5,127.5 280.5,137.5"/>
             	<text x="254.5" y="123.5" font-family="Times New Roman" font-size="20">&#949;</text>
             	<polygon stroke="black" stroke-width="1" points="240.5,211.5 288.5,211.5"/>
             	<polygon fill="black" stroke-width="1" points="288.5,211.5 280.5,206.5 280.5,216.5"/>
             	<text x="259.5" y="202.5" font-family="Times New Roman" font-size="20">a</text>
             	<polygon stroke="black" stroke-width="1" points="58.5,177.5 91.5,177.5"/>
             	<text x="3.5" y="183.5" font-family="Times New Roman" font-size="20">start</text>
             	<polygon fill="black" stroke-width="1" points="91.5,177.5 83.5,172.5 83.5,182.5"/>
             	<polygon stroke="black" stroke-width="1" points="148.272,163.963 183.728,146.037"/>
             	<polygon fill="black" stroke-width="1" points="183.728,146.037 174.332,145.184 178.844,154.108"/>
             	<text x="141.5" y="145.5" font-family="Times New Roman" font-size="20">&#949;</text>
             	<polygon stroke="black" stroke-width="1" points="149.525,188.206 182.475,200.794"/>
             	<polygon fill="black" stroke-width="1" points="182.475,200.794 176.786,193.268 173.218,202.61"/>
             	<text x="141.5" y="215.5" font-family="Times New Roman" font-size="20">&#949;</text>
             	<polygon stroke="black" stroke-width="1" points="345.392,145.798 382.608,164.202"/>
             	<polygon fill="black" stroke-width="1" points="382.608,164.202 377.654,156.174 373.221,165.138"/>
             	<text x="368.5" y="145.5" font-family="Times New Roman" font-size="20">&#949;</text>
             	<polygon stroke="black" stroke-width="1" points="346.603,201 381.397,188"/>
             	<polygon fill="black" stroke-width="1" points="381.397,188 372.153,186.116 375.653,195.484"/>
             	<text x="368.5" y="215.5" font-family="Times New Roman" font-size="20">&#949;</text>
        </svg>

   3. <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="210.5" cy="132.5" rx="30" ry="30"/>
         	<text x="205.5" y="138.5" font-family="Times New Roman" font-size="20">0</text>
         	<ellipse stroke="black" stroke-width="1" fill="none" cx="318.5" cy="132.5" rx="30" ry="30"/>
         	<text x="313.5" y="138.5" font-family="Times New Roman" font-size="20">1</text>
         	<ellipse stroke="black" stroke-width="1" fill="none" cx="210.5" cy="211.5" rx="30" ry="30"/>
         	<text x="205.5" y="217.5" font-family="Times New Roman" font-size="20">2</text>
         	<ellipse stroke="black" stroke-width="1" fill="none" cx="318.5" cy="211.5" rx="30" ry="30"/>
         	<text x="313.5" y="217.5" font-family="Times New Roman" font-size="20">3</text>
         	<ellipse stroke="black" stroke-width="1" fill="none" cx="126.5" cy="177.5" rx="30" ry="30"/>
         	<text x="121.5" y="183.5" font-family="Times New Roman" font-size="20">4</text>
         	<ellipse stroke="black" stroke-width="1" fill="none" cx="409.5" cy="177.5" rx="30" ry="30"/>
         	<text x="404.5" y="183.5" font-family="Times New Roman" font-size="20">5</text>
         	<ellipse stroke="black" stroke-width="1" fill="none" cx="126.5" cy="269.5" rx="30" ry="30"/>
         	<text x="121.5" y="275.5" font-family="Times New Roman" font-size="20">6</text>
         	<ellipse stroke="black" stroke-width="1" fill="none" cx="409.5" cy="269.5" rx="30" ry="30"/>
         	<text x="404.5" y="275.5" font-family="Times New Roman" font-size="20">7</text>
         	<ellipse stroke="black" stroke-width="1" fill="none" cx="409.5" cy="269.5" rx="24" ry="24"/>
         	<polygon stroke="black" stroke-width="1" points="240.5,132.5 288.5,132.5"/>
         	<polygon fill="black" stroke-width="1" points="288.5,132.5 280.5,127.5 280.5,137.5"/>
         	<text x="254.5" y="123.5" font-family="Times New Roman" font-size="20">&#949;</text>
         	<polygon stroke="black" stroke-width="1" points="240.5,211.5 288.5,211.5"/>
         	<polygon fill="black" stroke-width="1" points="288.5,211.5 280.5,206.5 280.5,216.5"/>
         	<text x="259.5" y="202.5" font-family="Times New Roman" font-size="20">a</text>
         	<polygon stroke="black" stroke-width="1" points="152.944,163.333 184.056,146.667"/>
         	<polygon fill="black" stroke-width="1" points="184.056,146.667 174.643,146.037 179.365,154.852"/>
         	<text x="143.5" y="145.5" font-family="Times New Roman" font-size="20">&#949;</text>
         	<polygon stroke="black" stroke-width="1" points="154.308,188.756 182.692,200.244"/>
         	<polygon fill="black" stroke-width="1" points="182.692,200.244 177.152,192.608 173.4,201.877"/>
         	<text x="144.5" y="215.5" font-family="Times New Roman" font-size="20">&#949;</text>
         	<polygon stroke="black" stroke-width="1" points="345.392,145.798 382.608,164.202"/>
         	<polygon fill="black" stroke-width="1" points="382.608,164.202 377.654,156.174 373.221,165.138"/>
         	<text x="368.5" y="145.5" font-family="Times New Roman" font-size="20">&#949;</text>
         	<polygon stroke="black" stroke-width="1" points="346.603,201 381.397,188"/>
         	<polygon fill="black" stroke-width="1" points="381.397,188 372.153,186.116 375.653,195.484"/>
         	<text x="368.5" y="215.5" font-family="Times New Roman" font-size="20">&#949;</text>
         	<polygon stroke="black" stroke-width="1" points="68.5,269.5 96.5,269.5"/>
         	<text x="13.5" y="275.5" font-family="Times New Roman" font-size="20">start</text>
         	<polygon fill="black" stroke-width="1" points="96.5,269.5 88.5,264.5 88.5,274.5"/>
         	<polygon stroke="black" stroke-width="1" points="126.5,239.5 126.5,207.5"/>
         	<polygon fill="black" stroke-width="1" points="126.5,207.5 121.5,215.5 131.5,215.5"/>
         	<text x="101.5" y="229.5" font-family="Times New Roman" font-size="20">&#949;</text>
         	<polygon stroke="black" stroke-width="1" points="156.5,269.5 379.5,269.5"/>
         	<polygon fill="black" stroke-width="1" points="379.5,269.5 371.5,264.5 371.5,274.5"/>
         	<text x="258.5" y="260.5" font-family="Times New Roman" font-size="20">&#949;</text>
         	<polygon stroke="black" stroke-width="1" points="409.5,207.5 409.5,239.5"/>
         	<polygon fill="black" stroke-width="1" points="409.5,239.5 414.5,231.5 404.5,231.5"/>
         	<text x="414.5" y="229.5" font-family="Times New Roman" font-size="20">&#949;</text>
         	<path stroke="black" stroke-width="1" fill="none" d="M 133.728,148.441 A 142.874,142.874 0 0 1 402.272,148.441"/>
         	<polygon fill="black" stroke-width="1" points="133.728,148.441 141.161,142.631 131.763,139.213"/>
         	<text x="258.5" y="45.5" font-family="Times New Roman" font-size="20">&#949;</text>

   4. <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
        <ellipse stroke="black" stroke-width="1" fill="none" cx="210.5" cy="132.5" rx="30" ry="30"/>
            <text x="205.5" y="138.5" font-family="Times New Roman" font-size="20">0</text>
            <ellipse stroke="black" stroke-width="1" fill="none" cx="318.5" cy="132.5" rx="30" ry="30"/>
            <text x="313.5" y="138.5" font-family="Times New Roman" font-size="20">1</text>
            <ellipse stroke="black" stroke-width="1" fill="none" cx="210.5" cy="211.5" rx="30" ry="30"/>
            <text x="205.5" y="217.5" font-family="Times New Roman" font-size="20">2</text>
            <ellipse stroke="black" stroke-width="1" fill="none" cx="318.5" cy="211.5" rx="30" ry="30"/>
            <text x="313.5" y="217.5" font-family="Times New Roman" font-size="20">3</text>
            <ellipse stroke="black" stroke-width="1" fill="none" cx="126.5" cy="177.5" rx="30" ry="30"/>
            <text x="121.5" y="183.5" font-family="Times New Roman" font-size="20">4</text>
            <ellipse stroke="black" stroke-width="1" fill="none" cx="409.5" cy="177.5" rx="30" ry="30"/>
            <text x="404.5" y="183.5" font-family="Times New Roman" font-size="20">5</text>
            <ellipse stroke="black" stroke-width="1" fill="none" cx="126.5" cy="269.5" rx="30" ry="30"/>
            <text x="121.5" y="275.5" font-family="Times New Roman" font-size="20">6</text>
            <ellipse stroke="black" stroke-width="1" fill="none" cx="409.5" cy="269.5" rx="30" ry="30"/>
            <text x="404.5" y="275.5" font-family="Times New Roman" font-size="20">7</text>
            <ellipse stroke="black" stroke-width="1" fill="none" cx="505.5" cy="269.5" rx="30" ry="30"/>
            <text x="500.5" y="275.5" font-family="Times New Roman" font-size="20">8</text>
            <ellipse stroke="black" stroke-width="1" fill="none" cx="505.5" cy="269.5" rx="24" ry="24"/>
            <polygon stroke="black" stroke-width="1" points="240.5,132.5 288.5,132.5"/>
            <polygon fill="black" stroke-width="1" points="288.5,132.5 280.5,127.5 280.5,137.5"/>
            <text x="254.5" y="123.5" font-family="Times New Roman" font-size="20">&#949;</text>
            <polygon stroke="black" stroke-width="1" points="240.5,211.5 288.5,211.5"/>
            <polygon fill="black" stroke-width="1" points="288.5,211.5 280.5,206.5 280.5,216.5"/>
            <text x="259.5" y="202.5" font-family="Times New Roman" font-size="20">a</text>
            <polygon stroke="black" stroke-width="1" points="152.944,163.333 184.056,146.667"/>
            <polygon fill="black" stroke-width="1" points="184.056,146.667 174.643,146.037 179.365,154.852"/>
            <text x="143.5" y="145.5" font-family="Times New Roman" font-size="20">&#949;</text>
            <polygon stroke="black" stroke-width="1" points="154.308,188.756 182.692,200.244"/>
            <polygon fill="black" stroke-width="1" points="182.692,200.244 177.152,192.608 173.4,201.877"/>
            <text x="144.5" y="215.5" font-family="Times New Roman" font-size="20">&#949;</text>
            <polygon stroke="black" stroke-width="1" points="345.392,145.798 382.608,164.202"/>
            <polygon fill="black" stroke-width="1" points="382.608,164.202 377.654,156.174 373.221,165.138"/>
            <text x="368.5" y="145.5" font-family="Times New Roman" font-size="20">&#949;</text>
            <polygon stroke="black" stroke-width="1" points="346.603,201 381.397,188"/>
            <polygon fill="black" stroke-width="1" points="381.397,188 372.153,186.116 375.653,195.484"/>
            <text x="368.5" y="215.5" font-family="Times New Roman" font-size="20">&#949;</text>
            <polygon stroke="black" stroke-width="1" points="126.5,239.5 126.5,207.5"/>
            <polygon fill="black" stroke-width="1" points="126.5,207.5 121.5,215.5 131.5,215.5"/>
            <text x="101.5" y="229.5" font-family="Times New Roman" font-size="20">&#949;</text>
            <polygon stroke="black" stroke-width="1" points="156.5,269.5 379.5,269.5"/>
            <polygon fill="black" stroke-width="1" points="379.5,269.5 371.5,264.5 371.5,274.5"/>
            <text x="258.5" y="260.5" font-family="Times New Roman" font-size="20">&#949;</text>
            <polygon stroke="black" stroke-width="1" points="409.5,207.5 409.5,239.5"/>
            <polygon fill="black" stroke-width="1" points="409.5,239.5 414.5,231.5 404.5,231.5"/>
            <text x="414.5" y="229.5" font-family="Times New Roman" font-size="20">&#949;</text>
            <path stroke="black" stroke-width="1" fill="none" d="M 133.728,148.441 A 142.874,142.874 0 0 1 402.272,148.441"/>
            <polygon fill="black" stroke-width="1" points="133.728,148.441 141.161,142.631 131.763,139.213"/>
            <text x="258.5" y="45.5" font-family="Times New Roman" font-size="20">&#949;</text>
            <polygon stroke="black" stroke-width="1" points="439.5,269.5 475.5,269.5"/>
            <polygon fill="black" stroke-width="1" points="475.5,269.5 467.5,264.5 467.5,274.5"/>
            <text x="452.5" y="260.5" font-family="Times New Roman" font-size="20">b</text>
            <polygon stroke="black" stroke-width="1" points="66.5,269.5 96.5,269.5"/>
            <text x="11.5" y="275.5" font-family="Times New Roman" font-size="20">start</text>
            <polygon fill="black" stroke-width="1" points="96.5,269.5 88.5,264.5 88.5,274.5"/>
        </svg>

	5. 
		
		<svg width="800" height="450" version="1.1" xmlns="http://www.w3.org/2000/svg">
	         	<ellipse stroke="black" stroke-width="1" fill="none" cx="210.5" cy="132.5" rx="30" ry="30"/>
	             	<text x="205.5" y="138.5" font-family="Times New Roman" font-size="20">0</text>
	             	<ellipse stroke="black" stroke-width="1" fill="none" cx="318.5" cy="132.5" rx="30" ry="30"/>
	             	<text x="313.5" y="138.5" font-family="Times New Roman" font-size="20">1</text>
	             	<ellipse stroke="black" stroke-width="1" fill="none" cx="210.5" cy="211.5" rx="30" ry="30"/>
	             	<text x="205.5" y="217.5" font-family="Times New Roman" font-size="20">2</text>
	             	<ellipse stroke="black" stroke-width="1" fill="none" cx="318.5" cy="211.5" rx="30" ry="30"/>
	             	<text x="313.5" y="217.5" font-family="Times New Roman" font-size="20">3</text>
	             	<ellipse stroke="black" stroke-width="1" fill="none" cx="126.5" cy="177.5" rx="30" ry="30"/>
	             	<text x="121.5" y="183.5" font-family="Times New Roman" font-size="20">4</text>
	             	<ellipse stroke="black" stroke-width="1" fill="none" cx="409.5" cy="177.5" rx="30" ry="30"/>
	             	<text x="404.5" y="183.5" font-family="Times New Roman" font-size="20">5</text>
	             	<ellipse stroke="black" stroke-width="1" fill="none" cx="126.5" cy="269.5" rx="30" ry="30"/>
	             	<text x="121.5" y="275.5" font-family="Times New Roman" font-size="20">6</text>
	             	<ellipse stroke="black" stroke-width="1" fill="none" cx="409.5" cy="269.5" rx="30" ry="30"/>
	             	<text x="404.5" y="275.5" font-family="Times New Roman" font-size="20">7</text>
	             	<ellipse stroke="black" stroke-width="1" fill="none" cx="505.5" cy="269.5" rx="30" ry="30"/>
	             	<text x="500.5" y="275.5" font-family="Times New Roman" font-size="20">8</text>
	             	<ellipse stroke="black" stroke-width="1" fill="none" cx="126.5" cy="355.5" rx="30" ry="30"/>
	             	<text x="121.5" y="361.5" font-family="Times New Roman" font-size="20">9</text>
	             	<ellipse stroke="black" stroke-width="1" fill="none" cx="505.5" cy="355.5" rx="30" ry="30"/>
	             	<text x="495.5" y="361.5" font-family="Times New Roman" font-size="20">10</text>
	             	<ellipse stroke="black" stroke-width="1" fill="none" cx="505.5" cy="355.5" rx="24" ry="24"/>
	             	<polygon stroke="black" stroke-width="1" points="240.5,132.5 288.5,132.5"/>
	             	<polygon fill="black" stroke-width="1" points="288.5,132.5 280.5,127.5 280.5,137.5"/>
	             	<text x="254.5" y="123.5" font-family="Times New Roman" font-size="20">&#949;</text>
	             	<polygon stroke="black" stroke-width="1" points="240.5,211.5 288.5,211.5"/>
	             	<polygon fill="black" stroke-width="1" points="288.5,211.5 280.5,206.5 280.5,216.5"/>
	             	<text x="259.5" y="202.5" font-family="Times New Roman" font-size="20">a</text>
	             	<polygon stroke="black" stroke-width="1" points="152.944,163.333 184.056,146.667"/>
	             	<polygon fill="black" stroke-width="1" points="184.056,146.667 174.643,146.037 179.365,154.852"/>
	             	<text x="143.5" y="145.5" font-family="Times New Roman" font-size="20">&#949;</text>
	             	<polygon stroke="black" stroke-width="1" points="154.308,188.756 182.692,200.244"/>
	             	<polygon fill="black" stroke-width="1" points="182.692,200.244 177.152,192.608 173.4,201.877"/>
	             	<text x="144.5" y="215.5" font-family="Times New Roman" font-size="20">&#949;</text>
	             	<polygon stroke="black" stroke-width="1" points="345.392,145.798 382.608,164.202"/>
	             	<polygon fill="black" stroke-width="1" points="382.608,164.202 377.654,156.174 373.221,165.138"/>
	             	<text x="368.5" y="145.5" font-family="Times New Roman" font-size="20">&#949;</text>
	             	<polygon stroke="black" stroke-width="1" points="346.603,201 381.397,188"/>
	             	<polygon fill="black" stroke-width="1" points="381.397,188 372.153,186.116 375.653,195.484"/>
	             	<text x="368.5" y="215.5" font-family="Times New Roman" font-size="20">&#949;</text>
	             	<polygon stroke="black" stroke-width="1" points="126.5,239.5 126.5,207.5"/>
	             	<polygon fill="black" stroke-width="1" points="126.5,207.5 121.5,215.5 131.5,215.5"/>
	             	<text x="101.5" y="229.5" font-family="Times New Roman" font-size="20">&#949;</text>
	             	<polygon stroke="black" stroke-width="1" points="156.5,269.5 379.5,269.5"/>
	             	<polygon fill="black" stroke-width="1" points="379.5,269.5 371.5,264.5 371.5,274.5"/>
	             	<text x="258.5" y="260.5" font-family="Times New Roman" font-size="20">&#949;</text>
	             	<polygon stroke="black" stroke-width="1" points="409.5,207.5 409.5,239.5"/>
	             	<polygon fill="black" stroke-width="1" points="409.5,239.5 414.5,231.5 404.5,231.5"/>
	             	<text x="414.5" y="229.5" font-family="Times New Roman" font-size="20">&#949;</text>
	             	<path stroke="black" stroke-width="1" fill="none" d="M 133.728,148.441 A 142.874,142.874 0 0 1 402.272,148.441"/>
	             	<polygon fill="black" stroke-width="1" points="133.728,148.441 141.161,142.631 131.763,139.213"/>
	             	<text x="258.5" y="45.5" font-family="Times New Roman" font-size="20">&#949;</text>
	             	<polygon stroke="black" stroke-width="1" points="439.5,269.5 475.5,269.5"/>
	             	<polygon fill="black" stroke-width="1" points="475.5,269.5 467.5,264.5 467.5,274.5"/>
	             	<text x="452.5" y="260.5" font-family="Times New Roman" font-size="20">b</text>
	             	<polygon stroke="black" stroke-width="1" points="66.5,355.5 96.5,355.5"/>
	             	<text x="11.5" y="361.5" font-family="Times New Roman" font-size="20">start</text>
	             	<polygon fill="black" stroke-width="1" points="96.5,355.5 88.5,350.5 88.5,360.5"/>
	             	<polygon stroke="black" stroke-width="1" points="126.5,325.5 126.5,299.5"/>
	             	<polygon fill="black" stroke-width="1" points="126.5,299.5 121.5,307.5 131.5,307.5"/>
	             	<text x="101.5" y="318.5" font-family="Times New Roman" font-size="20">&#949;</text>
	             	<path stroke="black" stroke-width="1" fill="none" d="M 156.146,350.912 A 1142.262,1142.262 0 0 1 475.854,350.912"/>
	             	<polygon fill="black" stroke-width="1" points="475.854,350.912 468.632,344.842 467.233,354.743"/>
	             	<text x="306.5" y="330.5" font-family="Times New Roman" font-size="20">&#949;</text>
	             	<path stroke="black" stroke-width="1" fill="none" d="M 475.863,360.144 A 1128.462,1128.462 0 0 1 156.137,360.144"/>
	             	<polygon fill="black" stroke-width="1" points="156.137,360.144 163.348,366.227 164.765,356.328"/>
	             	<text x="306.5" y="392.5" font-family="Times New Roman" font-size="20">&#949;</text>
	             	<polygon stroke="black" stroke-width="1" points="505.5,299.5 505.5,325.5"/>
	             	<polygon fill="black" stroke-width="1" points="505.5,325.5 510.5,317.5 500.5,317.5"/>
	             	<text x="510.5" y="318.5" font-family="Times New Roman" font-size="20">&#949;</text>
	    </svg>





2. $(a|b)^*a(a|b)(a|b) $ [10 points]

    1.$a$ and $b$

    <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
        <ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="113.5" rx="30" ry="30"/>
        <text x="188.5" y="119.5" font-family="Times New Roman" font-size="20">0</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="113.5" rx="30" ry="30"/>
        <text x="287.5" y="119.5" font-family="Times New Roman" font-size="20">1</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="113.5" rx="24" ry="24"/>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="194.5" rx="30" ry="30"/>
        <text x="188.5" y="200.5" font-family="Times New Roman" font-size="20">2</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="194.5" rx="30" ry="30"/>
        <text x="287.5" y="200.5" font-family="Times New Roman" font-size="20">3</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="194.5" rx="24" ry="24"/>
        <polygon stroke="black" stroke-width="1" points="223.5,113.5 262.5,113.5"/>
        <polygon fill="black" stroke-width="1" points="262.5,113.5 254.5,108.5 254.5,118.5"/>
        <text x="238.5" y="104.5" font-family="Times New Roman" font-size="20">a</text>
        <polygon stroke="black" stroke-width="1" points="223.5,194.5 262.5,194.5"/>
        <polygon fill="black" stroke-width="1" points="262.5,194.5 254.5,189.5 254.5,199.5"/>
        <text x="238.5" y="215.5" font-family="Times New Roman" font-size="20">b</text>
        <polygon stroke="black" stroke-width="1" points="124.5,113.5 163.5,113.5"/>
        <text x="69.5" y="119.5" font-family="Times New Roman" font-size="20">start</text>
        <polygon fill="black" stroke-width="1" points="163.5,113.5 155.5,108.5 155.5,118.5"/>
        <polygon stroke="black" stroke-width="1" points="124.5,194.5 163.5,194.5"/>
        <text x="69.5" y="200.5" font-family="Times New Roman" font-size="20">strat</text>
        <polygon fill="black" stroke-width="1" points="163.5,194.5 155.5,189.5 155.5,199.5"/>
    </svg>

    2.$(a|b)$

    <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
        <ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="113.5" rx="30" ry="30"/>
        <text x="188.5" y="119.5" font-family="Times New Roman" font-size="20">0</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="113.5" rx="30" ry="30"/>
        <text x="287.5" y="119.5" font-family="Times New Roman" font-size="20">1</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="194.5" rx="30" ry="30"/>
        <text x="188.5" y="200.5" font-family="Times New Roman" font-size="20">2</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="194.5" rx="30" ry="30"/>
        <text x="287.5" y="200.5" font-family="Times New Roman" font-size="20">3</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="116.5" cy="155.5" rx="30" ry="30"/>
        <text x="111.5" y="161.5" font-family="Times New Roman" font-size="20">4</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="373.5" cy="155.5" rx="30" ry="30"/>
        <text x="368.5" y="161.5" font-family="Times New Roman" font-size="20">5</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="373.5" cy="155.5" rx="24" ry="24"/>
        <polygon stroke="black" stroke-width="1" points="223.5,113.5 262.5,113.5"/>
        <polygon fill="black" stroke-width="1" points="262.5,113.5 254.5,108.5 254.5,118.5"/>
        <text x="238.5" y="104.5" font-family="Times New Roman" font-size="20">a</text>
        <polygon stroke="black" stroke-width="1" points="223.5,194.5 262.5,194.5"/>
        <polygon fill="black" stroke-width="1" points="262.5,194.5 254.5,189.5 254.5,199.5"/>
        <text x="238.5" y="215.5" font-family="Times New Roman" font-size="20">b</text>
        <polygon stroke="black" stroke-width="1" points="60.5,155.5 86.5,155.5"/>
        <text x="5.5" y="161.5" font-family="Times New Roman" font-size="20">start</text>
        <polygon fill="black" stroke-width="1" points="86.5,155.5 78.5,150.5 78.5,160.5"/>
        <polygon stroke="black" stroke-width="1" points="142.837,141.134 167.163,127.866"/>
        <polygon fill="black" stroke-width="1" points="167.163,127.866 157.746,127.307 162.534,136.086"/>
        <text x="130.5" y="125.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="143.263,169.055 166.737,180.945"/>
        <polygon fill="black" stroke-width="1" points="166.737,180.945 161.859,172.87 157.341,181.79"/>
        <text x="130.5" y="196.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="319.133,127.31 346.867,141.69"/>
        <polygon fill="black" stroke-width="1" points="346.867,141.69 342.067,133.569 337.464,142.447"/>
        <text x="337.5" y="125.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="319.53,181.486 346.47,168.514"/>
        <polygon fill="black" stroke-width="1" points="346.47,168.514 337.093,167.48 341.431,176.49"/>
        <text x="337.5" y="196.5" font-family="Times New Roman" font-size="20">&#949;</text>
    </svg>

    3.$(a|b)^*$

    <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
        <ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="113.5" rx="30" ry="30"/>
        <text x="188.5" y="119.5" font-family="Times New Roman" font-size="20">0</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="113.5" rx="30" ry="30"/>
        <text x="287.5" y="119.5" font-family="Times New Roman" font-size="20">1</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="194.5" rx="30" ry="30"/>
        <text x="188.5" y="200.5" font-family="Times New Roman" font-size="20">2</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="194.5" rx="30" ry="30"/>
        <text x="287.5" y="200.5" font-family="Times New Roman" font-size="20">3</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="116.5" cy="155.5" rx="30" ry="30"/>
        <text x="111.5" y="161.5" font-family="Times New Roman" font-size="20">4</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="373.5" cy="155.5" rx="30" ry="30"/>
        <text x="368.5" y="161.5" font-family="Times New Roman" font-size="20">5</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="116.5" cy="257.5" rx="30" ry="30"/>
        <text x="111.5" y="263.5" font-family="Times New Roman" font-size="20">6</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="373.5" cy="257.5" rx="30" ry="30"/>
        <text x="368.5" y="263.5" font-family="Times New Roman" font-size="20">7</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="373.5" cy="257.5" rx="24" ry="24"/>
        <polygon stroke="black" stroke-width="1" points="223.5,113.5 262.5,113.5"/>
        <polygon fill="black" stroke-width="1" points="262.5,113.5 254.5,108.5 254.5,118.5"/>
        <text x="238.5" y="104.5" font-family="Times New Roman" font-size="20">a</text>
        <polygon stroke="black" stroke-width="1" points="223.5,194.5 262.5,194.5"/>
        <polygon fill="black" stroke-width="1" points="262.5,194.5 254.5,189.5 254.5,199.5"/>
        <text x="238.5" y="215.5" font-family="Times New Roman" font-size="20">b</text>
        <polygon stroke="black" stroke-width="1" points="142.837,141.134 167.163,127.866"/>
        <polygon fill="black" stroke-width="1" points="167.163,127.866 157.746,127.307 162.534,136.086"/>
        <text x="130.5" y="125.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="143.263,169.055 166.737,180.945"/>
        <polygon fill="black" stroke-width="1" points="166.737,180.945 161.859,172.87 157.341,181.79"/>
        <text x="130.5" y="196.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="319.133,127.31 346.867,141.69"/>
        <polygon fill="black" stroke-width="1" points="346.867,141.69 342.067,133.569 337.464,142.447"/>
        <text x="337.5" y="125.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="319.53,181.486 346.47,168.514"/>
        <polygon fill="black" stroke-width="1" points="346.47,168.514 337.093,167.48 341.431,176.49"/>
        <text x="337.5" y="196.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="116.5,227.5 116.5,185.5"/>
        <polygon fill="black" stroke-width="1" points="116.5,185.5 111.5,193.5 121.5,193.5"/>
        <text x="91.5" y="212.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="146.5,257.5 343.5,257.5"/>
        <polygon fill="black" stroke-width="1" points="343.5,257.5 335.5,252.5 335.5,262.5"/>
        <text x="235.5" y="278.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="373.5,185.5 373.5,227.5"/>
        <polygon fill="black" stroke-width="1" points="373.5,227.5 378.5,219.5 368.5,219.5"/>
        <text x="378.5" y="212.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="63.5,257.5 86.5,257.5"/>
        <text x="8.5" y="263.5" font-family="Times New Roman" font-size="20">start</text>
        <polygon fill="black" stroke-width="1" points="86.5,257.5 78.5,252.5 78.5,262.5"/>
        <path stroke="black" stroke-width="1" fill="none" d="M 121.961,126.07 A 128.789,128.789 0 0 1 368.039,126.07"/>
        <polygon fill="black" stroke-width="1" points="121.961,126.07 129.101,119.904 119.547,116.95"/>
        <text x="234.5" y="26.5" font-family="Times New Roman" font-size="20">&#949;</text>
    </svg>

    4. $(a|b)*a$

    <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
        <ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="113.5" rx="30" ry="30"/>
        <text x="188.5" y="119.5" font-family="Times New Roman" font-size="20">0</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="113.5" rx="30" ry="30"/>
        <text x="287.5" y="119.5" font-family="Times New Roman" font-size="20">1</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="186.5" rx="30" ry="30"/>
        <text x="188.5" y="192.5" font-family="Times New Roman" font-size="20">2</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="186.5" rx="30" ry="30"/>
        <text x="287.5" y="192.5" font-family="Times New Roman" font-size="20">3</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="123.5" cy="153.5" rx="30" ry="30"/>
        <text x="118.5" y="159.5" font-family="Times New Roman" font-size="20">4</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="359.5" cy="153.5" rx="30" ry="30"/>
        <text x="354.5" y="159.5" font-family="Times New Roman" font-size="20">5</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="123.5" cy="251.5" rx="30" ry="30"/>
        <text x="118.5" y="257.5" font-family="Times New Roman" font-size="20">6</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="359.5" cy="251.5" rx="30" ry="30"/>
        <text x="354.5" y="257.5" font-family="Times New Roman" font-size="20">7</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="502.5" cy="251.5" rx="30" ry="30"/>
        <text x="497.5" y="257.5" font-family="Times New Roman" font-size="20">8</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="502.5" cy="251.5" rx="24" ry="24"/>
        <polygon stroke="black" stroke-width="1" points="223.5,113.5 262.5,113.5"/>
        <polygon fill="black" stroke-width="1" points="262.5,113.5 254.5,108.5 254.5,118.5"/>
        <text x="238.5" y="104.5" font-family="Times New Roman" font-size="20">a</text>
        <polygon stroke="black" stroke-width="1" points="223.5,186.5 262.5,186.5"/>
        <polygon fill="black" stroke-width="1" points="262.5,186.5 254.5,181.5 254.5,191.5"/>
        <text x="238.5" y="207.5" font-family="Times New Roman" font-size="20">b</text>
        <polygon stroke="black" stroke-width="1" points="149.547,138.616 167.453,128.384"/>
        <polygon fill="black" stroke-width="1" points="167.453,128.384 158.026,128.012 162.987,136.694"/>
        <text x="163.5" y="154.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="150.636,166.293 166.364,173.707"/>
        <polygon fill="black" stroke-width="1" points="166.364,173.707 161.26,165.773 156.996,174.819"/>
        <text x="133.5" y="191.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="318.259,128.878 333.741,138.122"/>
        <polygon fill="black" stroke-width="1" points="333.741,138.122 329.435,129.728 324.309,138.314"/>
        <text x="301.5" y="154.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="319.413,173.245 332.587,166.755"/>
        <polygon fill="black" stroke-width="1" points="332.587,166.755 323.201,165.805 327.62,174.776"/>
        <text x="330.5" y="191.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <path stroke="black" stroke-width="1" fill="none" d="M 128.776,124.049 A 118.15,118.15 0 0 1 354.224,124.049"/>
        <polygon fill="black" stroke-width="1" points="128.776,124.049 135.943,117.915 126.402,114.919"/>
        <text x="231.5" y="32.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="123.5,221.5 123.5,183.5"/>
        <polygon fill="black" stroke-width="1" points="123.5,183.5 118.5,191.5 128.5,191.5"/>
        <text x="98.5" y="208.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="153.5,251.5 329.5,251.5"/>
        <polygon fill="black" stroke-width="1" points="329.5,251.5 321.5,246.5 321.5,256.5"/>
        <text x="231.5" y="272.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="359.5,183.5 359.5,221.5"/>
        <polygon fill="black" stroke-width="1" points="359.5,221.5 364.5,213.5 354.5,213.5"/>
        <text x="364.5" y="208.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="70.5,251.5 93.5,251.5"/>
        <text x="15.5" y="257.5" font-family="Times New Roman" font-size="20">start</text>
        <polygon fill="black" stroke-width="1" points="93.5,251.5 85.5,246.5 85.5,256.5"/>
        <polygon stroke="black" stroke-width="1" points="389.5,251.5 472.5,251.5"/>
        <polygon fill="black" stroke-width="1" points="472.5,251.5 464.5,246.5 464.5,256.5"/>
        <text x="426.5" y="272.5" font-family="Times New Roman" font-size="20">a</text>
    </svg>

    5.$(a|b)^*a(a|b)(a|b)$ (reuse $(a|b)$)

    <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
        <ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="113.5" rx="30" ry="30"/>
        <text x="188.5" y="119.5" font-family="Times New Roman" font-size="20">0</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="113.5" rx="30" ry="30"/>
        <text x="287.5" y="119.5" font-family="Times New Roman" font-size="20">1</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="186.5" rx="30" ry="30"/>
        <text x="188.5" y="192.5" font-family="Times New Roman" font-size="20">2</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="186.5" rx="30" ry="30"/>
        <text x="287.5" y="192.5" font-family="Times New Roman" font-size="20">3</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="123.5" cy="153.5" rx="30" ry="30"/>
        <text x="118.5" y="159.5" font-family="Times New Roman" font-size="20">4</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="359.5" cy="153.5" rx="30" ry="30"/>
        <text x="354.5" y="159.5" font-family="Times New Roman" font-size="20">5</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="123.5" cy="251.5" rx="30" ry="30"/>
        <text x="118.5" y="257.5" font-family="Times New Roman" font-size="20">6</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="359.5" cy="251.5" rx="30" ry="30"/>
        <text x="354.5" y="257.5" font-family="Times New Roman" font-size="20">7</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="502.5" cy="251.5" rx="30" ry="30"/>
        <text x="497.5" y="257.5" font-family="Times New Roman" font-size="20">8</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="461.5" cy="186.5" rx="30" ry="30"/>
        <text x="456.5" y="192.5" font-family="Times New Roman" font-size="20">9</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="541.5" cy="186.5" rx="30" ry="30"/>
        <text x="531.5" y="192.5" font-family="Times New Roman" font-size="20">11</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="461.5" cy="102.5" rx="30" ry="30"/>
        <text x="451.5" y="108.5" font-family="Times New Roman" font-size="20">10</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="541.5" cy="102.5" rx="30" ry="30"/>
        <text x="531.5" y="108.5" font-family="Times New Roman" font-size="20">12</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="595.5" cy="30.5" rx="30" ry="30"/>
        <text x="585.5" y="36.5" font-family="Times New Roman" font-size="20">13</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="654.5" cy="102.5" rx="30" ry="30"/>
        <text x="644.5" y="108.5" font-family="Times New Roman" font-size="20">14</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="739.5" cy="102.5" rx="30" ry="30"/>
        <text x="729.5" y="108.5" font-family="Times New Roman" font-size="20">16</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="654.5" cy="186.5" rx="30" ry="30"/>
        <text x="644.5" y="192.5" font-family="Times New Roman" font-size="20">15</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="739.5" cy="186.5" rx="30" ry="30"/>
        <text x="729.5" y="192.5" font-family="Times New Roman" font-size="20">17</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="697.5" cy="251.5" rx="30" ry="30"/>
        <text x="687.5" y="257.5" font-family="Times New Roman" font-size="20">18</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="697.5" cy="251.5" rx="24" ry="24"/>
        <polygon stroke="black" stroke-width="1" points="223.5,113.5 262.5,113.5"/>
        <polygon fill="black" stroke-width="1" points="262.5,113.5 254.5,108.5 254.5,118.5"/>
        <text x="238.5" y="104.5" font-family="Times New Roman" font-size="20">a</text>
        <polygon stroke="black" stroke-width="1" points="223.5,186.5 262.5,186.5"/>
        <polygon fill="black" stroke-width="1" points="262.5,186.5 254.5,181.5 254.5,191.5"/>
        <text x="238.5" y="207.5" font-family="Times New Roman" font-size="20">b</text>
        <polygon stroke="black" stroke-width="1" points="149.547,138.616 167.453,128.384"/>
        <polygon fill="black" stroke-width="1" points="167.453,128.384 158.026,128.012 162.987,136.694"/>
        <text x="163.5" y="154.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="150.636,166.293 166.364,173.707"/>
        <polygon fill="black" stroke-width="1" points="166.364,173.707 161.26,165.773 156.996,174.819"/>
        <text x="133.5" y="191.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="318.259,128.878 333.741,138.122"/>
        <polygon fill="black" stroke-width="1" points="333.741,138.122 329.435,129.728 324.309,138.314"/>
        <text x="301.5" y="154.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="319.413,173.245 332.587,166.755"/>
        <polygon fill="black" stroke-width="1" points="332.587,166.755 323.201,165.805 327.62,174.776"/>
        <text x="330.5" y="191.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <path stroke="black" stroke-width="1" fill="none" d="M 128.776,124.049 A 118.15,118.15 0 0 1 354.224,124.049"/>
        <polygon fill="black" stroke-width="1" points="128.776,124.049 135.943,117.915 126.402,114.919"/>
        <text x="231.5" y="32.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="123.5,221.5 123.5,183.5"/>
        <polygon fill="black" stroke-width="1" points="123.5,183.5 118.5,191.5 128.5,191.5"/>
        <text x="98.5" y="208.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="153.5,251.5 329.5,251.5"/>
        <polygon fill="black" stroke-width="1" points="329.5,251.5 321.5,246.5 321.5,256.5"/>
        <text x="231.5" y="272.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="359.5,183.5 359.5,221.5"/>
        <polygon fill="black" stroke-width="1" points="359.5,221.5 364.5,213.5 354.5,213.5"/>
        <text x="364.5" y="208.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="70.5,251.5 93.5,251.5"/>
        <text x="15.5" y="257.5" font-family="Times New Roman" font-size="20">start</text>
        <polygon fill="black" stroke-width="1" points="93.5,251.5 85.5,246.5 85.5,256.5"/>
        <polygon stroke="black" stroke-width="1" points="389.5,251.5 472.5,251.5"/>
        <polygon fill="black" stroke-width="1" points="472.5,251.5 464.5,246.5 464.5,256.5"/>
        <text x="426.5" y="272.5" font-family="Times New Roman" font-size="20">a</text>
        <polygon stroke="black" stroke-width="1" points="461.5,156.5 461.5,132.5"/>
        <polygon fill="black" stroke-width="1" points="461.5,132.5 456.5,140.5 466.5,140.5"/>
        <text x="446.5" y="150.5" font-family="Times New Roman" font-size="20">a</text>
        <polygon stroke="black" stroke-width="1" points="541.5,156.5 541.5,132.5"/>
        <polygon fill="black" stroke-width="1" points="541.5,132.5 536.5,140.5 546.5,140.5"/>
        <text x="546.5" y="150.5" font-family="Times New Roman" font-size="20">b</text>
        <polygon stroke="black" stroke-width="1" points="654.5,132.5 654.5,156.5"/>
        <polygon fill="black" stroke-width="1" points="654.5,156.5 659.5,148.5 649.5,148.5"/>
        <text x="639.5" y="150.5" font-family="Times New Roman" font-size="20">a</text>
        <polygon stroke="black" stroke-width="1" points="739.5,132.5 739.5,156.5"/>
        <polygon fill="black" stroke-width="1" points="739.5,156.5 744.5,148.5 734.5,148.5"/>
        <text x="724.5" y="150.5" font-family="Times New Roman" font-size="20">b</text>
        <path stroke="black" stroke-width="1" fill="none" d="M 481.618,80.29 A 185.448,185.448 0 0 1 565.875,35.018"/>
        <polygon fill="black" stroke-width="1" points="565.875,35.018 556.939,31.993 559.241,41.725"/>
        <text x="495.5" y="43.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="559.5,78.5 577.5,54.5"/>
        <polygon fill="black" stroke-width="1" points="577.5,54.5 568.7,57.9 576.7,63.9"/>
        <text x="574.5" y="86.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="614.515,53.704 635.485,79.296"/>
        <polygon fill="black" stroke-width="1" points="635.485,79.296 634.282,69.939 626.547,76.277"/>
        <text x="599.5" y="86.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <path stroke="black" stroke-width="1" fill="none" d="M 624.933,36.21 A 246.308,246.308 0 0 1 717.273,82.38"/>
        <polygon fill="black" stroke-width="1" points="717.273,82.38 714.15,73.478 707.902,81.286"/>
        <text x="678.5" y="45.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="486.495,226.126 477.505,211.874"/>
        <polygon fill="black" stroke-width="1" points="477.505,211.874 477.544,221.308 486.002,215.973"/>
        <text x="455.5" y="237.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="517.935,225.775 526.065,212.225"/>
        <polygon fill="black" stroke-width="1" points="526.065,212.225 517.662,216.512 526.237,221.657"/>
        <text x="528.5" y="237.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="671.052,211.521 680.948,226.479"/>
        <polygon fill="black" stroke-width="1" points="680.948,226.479 680.704,217.049 672.364,222.566"/>
        <text x="649.5" y="238.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <polygon stroke="black" stroke-width="1" points="723.219,211.698 713.781,226.302"/>
        <polygon fill="black" stroke-width="1" points="713.781,226.302 722.323,222.297 713.924,216.87"/>
        <text x="724.5" y="238.5" font-family="Times New Roman" font-size="20">&#949;</text>
    </svg>



3. $a^*ba^*ba^*ba^*$ [10 points]

    1. $a$

       <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="113.5" rx="30" ry="30"/>
       	<text x="188.5" y="119.5" font-family="Times New Roman" font-size="20">0</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="113.5" rx="30" ry="30"/>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="113.5" rx="24" ry="24"/>
       	<text x="287.5" y="119.5" font-family="Times New Roman" font-size="20">1</text>
       	<polygon stroke="black" stroke-width="1" points="223.5,113.5 262.5,113.5"/>
       	<polygon fill="black" stroke-width="1" points="262.5,113.5 254.5,108.5 254.5,118.5"/>
       	<text x="238.5" y="104.5" font-family="Times New Roman" font-size="20">a</text>
       	<polygon stroke="black" stroke-width="1" points="128.5,113.5 163.5,113.5"/>
       	<text x="73.5" y="119.5" font-family="Times New Roman" font-size="20">start</text>
       	<polygon fill="black" stroke-width="1" points="163.5,113.5 155.5,108.5 155.5,118.5"/>
       </svg>

    2. $a^*$

       <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="113.5" rx="30" ry="30"/>
       	<text x="188.5" y="119.5" font-family="Times New Roman" font-size="20">0</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="296.5" cy="113.5" rx="30" ry="30"/>
       	<text x="291.5" y="119.5" font-family="Times New Roman" font-size="20">1</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="198.5" rx="30" ry="30"/>
       	<text x="188.5" y="204.5" font-family="Times New Roman" font-size="20">2</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="296.5" cy="198.5" rx="30" ry="30"/>
       	<text x="291.5" y="204.5" font-family="Times New Roman" font-size="20">3</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="296.5" cy="198.5" rx="24" ry="24"/>
       	<polygon stroke="black" stroke-width="1" points="223.5,113.5 266.5,113.5"/>
       	<polygon fill="black" stroke-width="1" points="266.5,113.5 258.5,108.5 258.5,118.5"/>
       	<text x="240.5" y="134.5" font-family="Times New Roman" font-size="20">a</text>
       	<path stroke="black" stroke-width="1" fill="none" d="M 192.325,83.905 A 54.191,54.191 0 0 1 297.675,83.905"/>
       	<polygon fill="black" stroke-width="1" points="192.325,83.905 199.064,77.303 189.344,74.954"/>
       	<text x="235.5" y="33.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="193.5,168.5 193.5,143.5"/>
       	<polygon fill="black" stroke-width="1" points="193.5,143.5 188.5,151.5 198.5,151.5"/>
       	<text x="198.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="223.5,198.5 266.5,198.5"/>
       	<polygon fill="black" stroke-width="1" points="266.5,198.5 258.5,193.5 258.5,203.5"/>
       	<text x="235.5" y="219.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="296.5,143.5 296.5,168.5"/>
       	<polygon fill="black" stroke-width="1" points="296.5,168.5 301.5,160.5 291.5,160.5"/>
       	<text x="271.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="132.5,198.5 163.5,198.5"/>
       	<text x="77.5" y="204.5" font-family="Times New Roman" font-size="20">start</text>
       	<polygon fill="black" stroke-width="1" points="163.5,198.5 155.5,193.5 155.5,203.5"/>
       </svg>

    3. $b$

       <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="113.5" rx="30" ry="30"/>
       	<text x="188.5" y="119.5" font-family="Times New Roman" font-size="20">0</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="113.5" rx="30" ry="30"/>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="113.5" rx="24" ry="24"/>
       	<text x="287.5" y="119.5" font-family="Times New Roman" font-size="20">1</text>
       	<polygon stroke="black" stroke-width="1" points="223.5,113.5 262.5,113.5"/>
       	<polygon fill="black" stroke-width="1" points="262.5,113.5 254.5,108.5 254.5,118.5"/>
       	<text x="238.5" y="104.5" font-family="Times New Roman" font-size="20">b</text>
       	<polygon stroke="black" stroke-width="1" points="128.5,113.5 163.5,113.5"/>
       	<text x="73.5" y="119.5" font-family="Times New Roman" font-size="20">start</text>
       	<polygon fill="black" stroke-width="1" points="163.5,113.5 155.5,108.5 155.5,118.5"/>
       </svg>

    4. $a^*b$

       <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="113.5" rx="30" ry="30"/>
       	<text x="188.5" y="119.5" font-family="Times New Roman" font-size="20">0</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="296.5" cy="113.5" rx="30" ry="30"/>
       	<text x="291.5" y="119.5" font-family="Times New Roman" font-size="20">1</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="198.5" rx="30" ry="30"/>
       	<text x="188.5" y="204.5" font-family="Times New Roman" font-size="20">2</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="296.5" cy="198.5" rx="30" ry="30"/>
       	<text x="291.5" y="204.5" font-family="Times New Roman" font-size="20">3</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="383.5" cy="198.5" rx="30" ry="30"/>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="383.5" cy="198.5" rx="24" ry="24"/>
       	<text x="378.5" y="204.5" font-family="Times New Roman" font-size="20">4</text>
       	<polygon stroke="black" stroke-width="1" points="223.5,113.5 266.5,113.5"/>
       	<polygon fill="black" stroke-width="1" points="266.5,113.5 258.5,108.5 258.5,118.5"/>
       	<text x="240.5" y="134.5" font-family="Times New Roman" font-size="20">a</text>
       	<path stroke="black" stroke-width="1" fill="none" d="M 192.325,83.905 A 54.191,54.191 0 0 1 297.675,83.905"/>
       	<polygon fill="black" stroke-width="1" points="192.325,83.905 199.064,77.303 189.344,74.954"/>
       	<text x="235.5" y="33.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="193.5,168.5 193.5,143.5"/>
       	<polygon fill="black" stroke-width="1" points="193.5,143.5 188.5,151.5 198.5,151.5"/>
       	<text x="198.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="223.5,198.5 266.5,198.5"/>
       	<polygon fill="black" stroke-width="1" points="266.5,198.5 258.5,193.5 258.5,203.5"/>
       	<text x="235.5" y="219.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="296.5,143.5 296.5,168.5"/>
       	<polygon fill="black" stroke-width="1" points="296.5,168.5 301.5,160.5 291.5,160.5"/>
       	<text x="271.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="132.5,198.5 163.5,198.5"/>
       	<text x="77.5" y="204.5" font-family="Times New Roman" font-size="20">start</text>
       	<polygon fill="black" stroke-width="1" points="163.5,198.5 155.5,193.5 155.5,203.5"/>
       	<polygon stroke="black" stroke-width="1" points="326.5,198.5 353.5,198.5"/>
       	<polygon fill="black" stroke-width="1" points="353.5,198.5 345.5,193.5 345.5,203.5"/>
       	<text x="335.5" y="219.5" font-family="Times New Roman" font-size="20">b</text>
       </svg>

    5. $a^*ba^*ba^*ba^*$ (reuse $a^*$ and $a^*b$)

       <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="113.5" rx="30" ry="30"/>
       	<text x="188.5" y="119.5" font-family="Times New Roman" font-size="20">0</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="296.5" cy="113.5" rx="30" ry="30"/>
       	<text x="291.5" y="119.5" font-family="Times New Roman" font-size="20">1</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="198.5" rx="30" ry="30"/>
       	<text x="188.5" y="204.5" font-family="Times New Roman" font-size="20">2</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="296.5" cy="198.5" rx="30" ry="30"/>
       	<text x="291.5" y="204.5" font-family="Times New Roman" font-size="20">3</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="383.5" cy="198.5" rx="30" ry="30"/>
       	<text x="378.5" y="204.5" font-family="Times New Roman" font-size="20">4</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="383.5" cy="113.5" rx="30" ry="30"/>
       	<text x="378.5" y="119.5" font-family="Times New Roman" font-size="20">5</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="463.5" cy="113.5" rx="30" ry="30"/>
       	<text x="458.5" y="119.5" font-family="Times New Roman" font-size="20">6</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="463.5" cy="198.5" rx="30" ry="30"/>
       	<text x="458.5" y="204.5" font-family="Times New Roman" font-size="20">7</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="536.5" cy="198.5" rx="30" ry="30"/>
       	<text x="531.5" y="204.5" font-family="Times New Roman" font-size="20">8</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="536.5" cy="113.5" rx="30" ry="30"/>
       	<text x="531.5" y="119.5" font-family="Times New Roman" font-size="20">9</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="622.5" cy="113.5" rx="30" ry="30"/>
       	<text x="612.5" y="119.5" font-family="Times New Roman" font-size="20">10</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="622.5" cy="198.5" rx="30" ry="30"/>
       	<text x="612.5" y="204.5" font-family="Times New Roman" font-size="20">11</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="695.5" cy="113.5" rx="30" ry="30"/>
       	<text x="685.5" y="119.5" font-family="Times New Roman" font-size="20">13</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="768.5" cy="113.5" rx="30" ry="30"/>
       	<text x="758.5" y="119.5" font-family="Times New Roman" font-size="20">14</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="695.5" cy="198.5" rx="30" ry="30"/>
       	<text x="685.5" y="204.5" font-family="Times New Roman" font-size="20">12</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="768.5" cy="198.5" rx="30" ry="30"/>
       	<text x="758.5" y="204.5" font-family="Times New Roman" font-size="20">15</text>
       	<ellipse stroke="black" stroke-width="1" fill="none" cx="768.5" cy="198.5" rx="24" ry="24"/>
       	<polygon stroke="black" stroke-width="1" points="223.5,113.5 266.5,113.5"/>
       	<polygon fill="black" stroke-width="1" points="266.5,113.5 258.5,108.5 258.5,118.5"/>
       	<text x="240.5" y="134.5" font-family="Times New Roman" font-size="20">a</text>
       	<path stroke="black" stroke-width="1" fill="none" d="M 192.325,83.905 A 54.191,54.191 0 0 1 297.675,83.905"/>
       	<polygon fill="black" stroke-width="1" points="192.325,83.905 199.064,77.303 189.344,74.954"/>
       	<text x="235.5" y="33.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="193.5,168.5 193.5,143.5"/>
       	<polygon fill="black" stroke-width="1" points="193.5,143.5 188.5,151.5 198.5,151.5"/>
       	<text x="198.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="223.5,198.5 266.5,198.5"/>
       	<polygon fill="black" stroke-width="1" points="266.5,198.5 258.5,193.5 258.5,203.5"/>
       	<text x="235.5" y="219.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="296.5,143.5 296.5,168.5"/>
       	<polygon fill="black" stroke-width="1" points="296.5,168.5 301.5,160.5 291.5,160.5"/>
       	<text x="271.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="132.5,198.5 163.5,198.5"/>
       	<text x="77.5" y="204.5" font-family="Times New Roman" font-size="20">start</text>
       	<polygon fill="black" stroke-width="1" points="163.5,198.5 155.5,193.5 155.5,203.5"/>
       	<polygon stroke="black" stroke-width="1" points="326.5,198.5 353.5,198.5"/>
       	<polygon fill="black" stroke-width="1" points="353.5,198.5 345.5,193.5 345.5,203.5"/>
       	<text x="335.5" y="219.5" font-family="Times New Roman" font-size="20">b</text>
       	<polygon stroke="black" stroke-width="1" points="383.5,168.5 383.5,143.5"/>
       	<polygon fill="black" stroke-width="1" points="383.5,143.5 378.5,151.5 388.5,151.5"/>
       	<text x="388.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="413.5,113.5 433.5,113.5"/>
       	<polygon fill="black" stroke-width="1" points="433.5,113.5 425.5,108.5 425.5,118.5"/>
       	<text x="418.5" y="134.5" font-family="Times New Roman" font-size="20">a</text>
       	<polygon stroke="black" stroke-width="1" points="463.5,143.5 463.5,168.5"/>
       	<polygon fill="black" stroke-width="1" points="463.5,168.5 468.5,160.5 458.5,160.5"/>
       	<text x="438.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="493.5,198.5 506.5,198.5"/>
       	<polygon fill="black" stroke-width="1" points="506.5,198.5 498.5,193.5 498.5,203.5"/>
       	<text x="495.5" y="219.5" font-family="Times New Roman" font-size="20">b</text>
       	<polygon stroke="black" stroke-width="1" points="536.5,168.5 536.5,143.5"/>
       	<polygon fill="black" stroke-width="1" points="536.5,143.5 531.5,151.5 541.5,151.5"/>
       	<text x="541.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="566.5,113.5 592.5,113.5"/>
       	<polygon fill="black" stroke-width="1" points="592.5,113.5 584.5,108.5 584.5,118.5"/>
       	<text x="574.5" y="134.5" font-family="Times New Roman" font-size="20">a</text>
       	<polygon stroke="black" stroke-width="1" points="622.5,143.5 622.5,168.5"/>
       	<polygon fill="black" stroke-width="1" points="622.5,168.5 627.5,160.5 617.5,160.5"/>
       	<text x="597.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="652.5,198.5 665.5,198.5"/>
       	<polygon fill="black" stroke-width="1" points="665.5,198.5 657.5,193.5 657.5,203.5"/>
       	<text x="654.5" y="219.5" font-family="Times New Roman" font-size="20">b</text>
       	<polygon stroke="black" stroke-width="1" points="725.5,113.5 738.5,113.5"/>
       	<polygon fill="black" stroke-width="1" points="738.5,113.5 730.5,108.5 730.5,118.5"/>
       	<text x="727.5" y="134.5" font-family="Times New Roman" font-size="20">a</text>
       	<polygon stroke="black" stroke-width="1" points="768.5,143.5 768.5,168.5"/>
       	<polygon fill="black" stroke-width="1" points="768.5,168.5 773.5,160.5 763.5,160.5"/>
       	<text x="743.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="695.5,168.5 695.5,143.5"/>
       	<polygon fill="black" stroke-width="1" points="695.5,143.5 690.5,151.5 700.5,151.5"/>
       	<text x="700.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="725.5,198.5 738.5,198.5"/>
       	<polygon fill="black" stroke-width="1" points="738.5,198.5 730.5,193.5 730.5,203.5"/>
       	<text x="722.5" y="219.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="566.5,198.5 592.5,198.5"/>
       	<polygon fill="black" stroke-width="1" points="592.5,198.5 584.5,193.5 584.5,203.5"/>
       	<text x="569.5" y="219.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<polygon stroke="black" stroke-width="1" points="413.5,198.5 433.5,198.5"/>
       	<polygon fill="black" stroke-width="1" points="433.5,198.5 425.5,193.5 425.5,203.5"/>
       	<text x="413.5" y="219.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<path stroke="black" stroke-width="1" fill="none" d="M 687.964,85.054 A 44.179,44.179 0 0 1 776.036,85.054"/>
       	<polygon fill="black" stroke-width="1" points="687.964,85.054 693.591,77.483 683.624,76.678"/>
       	<text x="722.5" y="35.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<path stroke="black" stroke-width="1" fill="none" d="M 533.853,84.128 A 46.882,46.882 0 0 1 625.147,84.128"/>
       	<polygon fill="black" stroke-width="1" points="533.853,84.128 540.546,77.479 530.81,75.199"/>
       	<text x="569.5" y="38.5" font-family="Times New Roman" font-size="20">&#949;</text>
       	<path stroke="black" stroke-width="1" fill="none" d="M 375.165,85.18 A 48.349,48.349 0 0 1 471.835,85.18"/>
       	<polygon fill="black" stroke-width="1" points="375.165,85.18 380.355,77.302 370.358,77.063"/>
       	<text x="413.5" y="28.5" font-family="Times New Roman" font-size="20">&#949;</text>
       </svg>

### Exercise 3

Convert the NFAs in Exercise 2 to DFAs using the Subset Construction Algorithm (Algorithm 3.20 in the dragon book). Please put down the detailed steps. [30 points in total; 10 points for each correct conversion]

1. $((\epsilon|a)^*b)*$ [10 points]

   1. NFA:

      <svg width="800" height="450" version="1.1" xmlns="http://www.w3.org/2000/svg">
            	<ellipse stroke="black" stroke-width="1" fill="none" cx="210.5" cy="132.5" rx="30" ry="30"/>
                	<text x="205.5" y="138.5" font-family="Times New Roman" font-size="20">0</text>
                	<ellipse stroke="black" stroke-width="1" fill="none" cx="318.5" cy="132.5" rx="30" ry="30"/>
                	<text x="313.5" y="138.5" font-family="Times New Roman" font-size="20">1</text>
                	<ellipse stroke="black" stroke-width="1" fill="none" cx="210.5" cy="211.5" rx="30" ry="30"/>
                	<text x="205.5" y="217.5" font-family="Times New Roman" font-size="20">2</text>
                	<ellipse stroke="black" stroke-width="1" fill="none" cx="318.5" cy="211.5" rx="30" ry="30"/>
                	<text x="313.5" y="217.5" font-family="Times New Roman" font-size="20">3</text>
                	<ellipse stroke="black" stroke-width="1" fill="none" cx="126.5" cy="177.5" rx="30" ry="30"/>
                	<text x="121.5" y="183.5" font-family="Times New Roman" font-size="20">4</text>
                	<ellipse stroke="black" stroke-width="1" fill="none" cx="409.5" cy="177.5" rx="30" ry="30"/>
                	<text x="404.5" y="183.5" font-family="Times New Roman" font-size="20">5</text>
                	<ellipse stroke="black" stroke-width="1" fill="none" cx="126.5" cy="269.5" rx="30" ry="30"/>
                	<text x="121.5" y="275.5" font-family="Times New Roman" font-size="20">6</text>
                	<ellipse stroke="black" stroke-width="1" fill="none" cx="409.5" cy="269.5" rx="30" ry="30"/>
                	<text x="404.5" y="275.5" font-family="Times New Roman" font-size="20">7</text>
                	<ellipse stroke="black" stroke-width="1" fill="none" cx="505.5" cy="269.5" rx="30" ry="30"/>
                	<text x="500.5" y="275.5" font-family="Times New Roman" font-size="20">8</text>
                	<ellipse stroke="black" stroke-width="1" fill="none" cx="126.5" cy="355.5" rx="30" ry="30"/>
                	<text x="121.5" y="361.5" font-family="Times New Roman" font-size="20">9</text>
                	<ellipse stroke="black" stroke-width="1" fill="none" cx="505.5" cy="355.5" rx="30" ry="30"/>
                	<text x="495.5" y="361.5" font-family="Times New Roman" font-size="20">10</text>
                	<ellipse stroke="black" stroke-width="1" fill="none" cx="505.5" cy="355.5" rx="24" ry="24"/>
                	<polygon stroke="black" stroke-width="1" points="240.5,132.5 288.5,132.5"/>
                	<polygon fill="black" stroke-width="1" points="288.5,132.5 280.5,127.5 280.5,137.5"/>
                	<text x="254.5" y="123.5" font-family="Times New Roman" font-size="20">&#949;</text>
                	<polygon stroke="black" stroke-width="1" points="240.5,211.5 288.5,211.5"/>
                	<polygon fill="black" stroke-width="1" points="288.5,211.5 280.5,206.5 280.5,216.5"/>
                	<text x="259.5" y="202.5" font-family="Times New Roman" font-size="20">a</text>
                	<polygon stroke="black" stroke-width="1" points="152.944,163.333 184.056,146.667"/>
                	<polygon fill="black" stroke-width="1" points="184.056,146.667 174.643,146.037 179.365,154.852"/>
                	<text x="143.5" y="145.5" font-family="Times New Roman" font-size="20">&#949;</text>
                	<polygon stroke="black" stroke-width="1" points="154.308,188.756 182.692,200.244"/>
                	<polygon fill="black" stroke-width="1" points="182.692,200.244 177.152,192.608 173.4,201.877"/>
                	<text x="144.5" y="215.5" font-family="Times New Roman" font-size="20">&#949;</text>
                	<polygon stroke="black" stroke-width="1" points="345.392,145.798 382.608,164.202"/>
                	<polygon fill="black" stroke-width="1" points="382.608,164.202 377.654,156.174 373.221,165.138"/>
                	<text x="368.5" y="145.5" font-family="Times New Roman" font-size="20">&#949;</text>
                	<polygon stroke="black" stroke-width="1" points="346.603,201 381.397,188"/>
                	<polygon fill="black" stroke-width="1" points="381.397,188 372.153,186.116 375.653,195.484"/>
                	<text x="368.5" y="215.5" font-family="Times New Roman" font-size="20">&#949;</text>
                	<polygon stroke="black" stroke-width="1" points="126.5,239.5 126.5,207.5"/>
                	<polygon fill="black" stroke-width="1" points="126.5,207.5 121.5,215.5 131.5,215.5"/>
                	<text x="101.5" y="229.5" font-family="Times New Roman" font-size="20">&#949;</text>
                	<polygon stroke="black" stroke-width="1" points="156.5,269.5 379.5,269.5"/>
                	<polygon fill="black" stroke-width="1" points="379.5,269.5 371.5,264.5 371.5,274.5"/>
                	<text x="258.5" y="260.5" font-family="Times New Roman" font-size="20">&#949;</text>
                	<polygon stroke="black" stroke-width="1" points="409.5,207.5 409.5,239.5"/>
                	<polygon fill="black" stroke-width="1" points="409.5,239.5 414.5,231.5 404.5,231.5"/>
                	<text x="414.5" y="229.5" font-family="Times New Roman" font-size="20">&#949;</text>
                	<path stroke="black" stroke-width="1" fill="none" d="M 133.728,148.441 A 142.874,142.874 0 0 1 402.272,148.441"/>
                	<polygon fill="black" stroke-width="1" points="133.728,148.441 141.161,142.631 131.763,139.213"/>
                	<text x="258.5" y="45.5" font-family="Times New Roman" font-size="20">&#949;</text>
                	<polygon stroke="black" stroke-width="1" points="439.5,269.5 475.5,269.5"/>
                	<polygon fill="black" stroke-width="1" points="475.5,269.5 467.5,264.5 467.5,274.5"/>
                	<text x="452.5" y="260.5" font-family="Times New Roman" font-size="20">b</text>
                	<polygon stroke="black" stroke-width="1" points="66.5,355.5 96.5,355.5"/>
                	<text x="11.5" y="361.5" font-family="Times New Roman" font-size="20">start</text>
                	<polygon fill="black" stroke-width="1" points="96.5,355.5 88.5,350.5 88.5,360.5"/>
                	<polygon stroke="black" stroke-width="1" points="126.5,325.5 126.5,299.5"/>
                	<polygon fill="black" stroke-width="1" points="126.5,299.5 121.5,307.5 131.5,307.5"/>
                	<text x="101.5" y="318.5" font-family="Times New Roman" font-size="20">&#949;</text>
                	<path stroke="black" stroke-width="1" fill="none" d="M 156.146,350.912 A 1142.262,1142.262 0 0 1 475.854,350.912"/>
                	<polygon fill="black" stroke-width="1" points="475.854,350.912 468.632,344.842 467.233,354.743"/>
                	<text x="306.5" y="330.5" font-family="Times New Roman" font-size="20">&#949;</text>
                	<path stroke="black" stroke-width="1" fill="none" d="M 475.863,360.144 A 1128.462,1128.462 0 0 1 156.137,360.144"/>
                	<polygon fill="black" stroke-width="1" points="156.137,360.144 163.348,366.227 164.765,356.328"/>
                	<text x="306.5" y="392.5" font-family="Times New Roman" font-size="20">&#949;</text>
                	<polygon stroke="black" stroke-width="1" points="505.5,299.5 505.5,325.5"/>
                	<polygon fill="black" stroke-width="1" points="505.5,325.5 510.5,317.5 500.5,317.5"/>
                	<text x="510.5" y="318.5" font-family="Times New Roman" font-size="20">&#949;</text>
        </svg>

   2. table:

      |                             $I$                              |         $I_a$          |      $I_b$      |
      | :----------------------------------------------------------: | :--------------------: | :-------------: |
      | $A = \epsilon\text{-closure}(9)=\{9, 6, 10, 4, 7, 0, 1,2, 5\}$ | $B=\{0,1,2,4,3, 5,7\}$ | $C=\{8\}\cup A$ |
      |                    $B=\{0,1,2,4,3,5,7\}$                     |          $B$           |       $C$       |
      |             $C=\{9, 6, 10, 4, 7, 0, 1,2, 5,8\}$              |          $ B$          |       $C$       |

      $A =\{9, 6, 10, 4, 7, 0, 1,2, 5\}$

      $B=\{0,1,2,4,3, 5,7\}$

      $C=\{9, 6, 10, 4, 7, 0, 1, 5, 8\}$

   3. DFA:

      <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="317.5" cy="225.5" rx="30" ry="30"/>
      	<text x="312.5" y="231.5" font-family="Times New Roman" font-size="20">A</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="317.5" cy="225.5" rx="24" ry="24"/>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="253.5" cy="136.5" rx="30" ry="30"/>
      	<text x="248.5" y="142.5" font-family="Times New Roman" font-size="20">B</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="381.5" cy="136.5" rx="30" ry="30"/>
      	<text x="376.5" y="142.5" font-family="Times New Roman" font-size="20">C</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="381.5" cy="136.5" rx="24" ry="24"/>
      	<path stroke="black" stroke-width="1" fill="none" d="M 282.394,128.55 A 187.403,187.403 0 0 1 352.606,128.55"/>
      	<polygon fill="black" stroke-width="1" points="352.606,128.55 345.684,122.14 343.811,131.963"/>
      	<text x="312.5" y="116.5" font-family="Times New Roman" font-size="20">b</text>
      	<polygon stroke="black" stroke-width="1" points="299.985,201.144 271.015,160.856"/>
      	<polygon fill="black" stroke-width="1" points="271.015,160.856 271.626,170.271 279.745,164.432"/>
      	<text x="291.5" y="173.5" font-family="Times New Roman" font-size="20">a</text>
      	<polygon stroke="black" stroke-width="1" points="335.015,201.144 363.985,160.856"/>
      	<polygon fill="black" stroke-width="1" points="363.985,160.856 355.255,164.432 363.374,170.271"/>
      	<text x="355.5" y="200.5" font-family="Times New Roman" font-size="20">b</text>
      	<path stroke="black" stroke-width="1" fill="none" d="M 240.275,109.703 A 22.5,22.5 0 1 1 266.725,109.703"/>
      	<text x="248.5" y="60.5" font-family="Times New Roman" font-size="20">a</text>
      	<polygon fill="black" stroke-width="1" points="266.725,109.703 275.473,106.17 267.382,100.292"/>
      	<polygon stroke="black" stroke-width="1" points="248.5,225.5 287.5,225.5"/>
      	<text x="193.5" y="231.5" font-family="Times New Roman" font-size="20">start</text>
      	<polygon fill="black" stroke-width="1" points="287.5,225.5 279.5,220.5 279.5,230.5"/>
      	<path stroke="black" stroke-width="1" fill="none" d="M 352.222,142.944 A 230.134,230.134 0 0 1 282.778,142.944"/>
      	<polygon fill="black" stroke-width="1" points="282.778,142.944 289.932,149.094 291.441,139.208"/>
      	<text x="312.5" y="166.5" font-family="Times New Roman" font-size="20">a</text>
      	<path stroke="black" stroke-width="1" fill="none" d="M 389.79,107.79 A 22.5,22.5 0 1 1 409.331,125.617"/>
      	<text x="432.5" y="77.5" font-family="Times New Roman" font-size="20">b</text>
      	<polygon fill="black" stroke-width="1" points="409.331,125.617 418.174,128.902 416.159,119.107"/>
      </svg>

2. $(a|b)^*a(a|b)(a|b) $ [10 points]

   1. NFA：

      <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
          <ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="113.5" rx="30" ry="30"/>
          <text x="188.5" y="119.5" font-family="Times New Roman" font-size="20">0</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="113.5" rx="30" ry="30"/>
          <text x="287.5" y="119.5" font-family="Times New Roman" font-size="20">1</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="186.5" rx="30" ry="30"/>
          <text x="188.5" y="192.5" font-family="Times New Roman" font-size="20">2</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="292.5" cy="186.5" rx="30" ry="30"/>
          <text x="287.5" y="192.5" font-family="Times New Roman" font-size="20">3</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="123.5" cy="153.5" rx="30" ry="30"/>
          <text x="118.5" y="159.5" font-family="Times New Roman" font-size="20">4</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="359.5" cy="153.5" rx="30" ry="30"/>
          <text x="354.5" y="159.5" font-family="Times New Roman" font-size="20">5</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="123.5" cy="251.5" rx="30" ry="30"/>
          <text x="118.5" y="257.5" font-family="Times New Roman" font-size="20">6</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="359.5" cy="251.5" rx="30" ry="30"/>
          <text x="354.5" y="257.5" font-family="Times New Roman" font-size="20">7</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="502.5" cy="251.5" rx="30" ry="30"/>
          <text x="497.5" y="257.5" font-family="Times New Roman" font-size="20">8</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="461.5" cy="186.5" rx="30" ry="30"/>
          <text x="456.5" y="192.5" font-family="Times New Roman" font-size="20">9</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="541.5" cy="186.5" rx="30" ry="30"/>
          <text x="531.5" y="192.5" font-family="Times New Roman" font-size="20">11</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="461.5" cy="102.5" rx="30" ry="30"/>
          <text x="451.5" y="108.5" font-family="Times New Roman" font-size="20">10</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="541.5" cy="102.5" rx="30" ry="30"/>
          <text x="531.5" y="108.5" font-family="Times New Roman" font-size="20">12</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="595.5" cy="30.5" rx="30" ry="30"/>
          <text x="585.5" y="36.5" font-family="Times New Roman" font-size="20">13</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="654.5" cy="102.5" rx="30" ry="30"/>
          <text x="644.5" y="108.5" font-family="Times New Roman" font-size="20">14</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="739.5" cy="102.5" rx="30" ry="30"/>
          <text x="729.5" y="108.5" font-family="Times New Roman" font-size="20">16</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="654.5" cy="186.5" rx="30" ry="30"/>
          <text x="644.5" y="192.5" font-family="Times New Roman" font-size="20">15</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="739.5" cy="186.5" rx="30" ry="30"/>
          <text x="729.5" y="192.5" font-family="Times New Roman" font-size="20">17</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="697.5" cy="251.5" rx="30" ry="30"/>
          <text x="687.5" y="257.5" font-family="Times New Roman" font-size="20">18</text>
          <ellipse stroke="black" stroke-width="1" fill="none" cx="697.5" cy="251.5" rx="24" ry="24"/>
          <polygon stroke="black" stroke-width="1" points="223.5,113.5 262.5,113.5"/>
          <polygon fill="black" stroke-width="1" points="262.5,113.5 254.5,108.5 254.5,118.5"/>
          <text x="238.5" y="104.5" font-family="Times New Roman" font-size="20">a</text>
          <polygon stroke="black" stroke-width="1" points="223.5,186.5 262.5,186.5"/>
          <polygon fill="black" stroke-width="1" points="262.5,186.5 254.5,181.5 254.5,191.5"/>
          <text x="238.5" y="207.5" font-family="Times New Roman" font-size="20">b</text>
          <polygon stroke="black" stroke-width="1" points="149.547,138.616 167.453,128.384"/>
          <polygon fill="black" stroke-width="1" points="167.453,128.384 158.026,128.012 162.987,136.694"/>
          <text x="163.5" y="154.5" font-family="Times New Roman" font-size="20">&#949;</text>
          <polygon stroke="black" stroke-width="1" points="150.636,166.293 166.364,173.707"/>
          <polygon fill="black" stroke-width="1" points="166.364,173.707 161.26,165.773 156.996,174.819"/>
          <text x="133.5" y="191.5" font-family="Times New Roman" font-size="20">&#949;</text>
          <polygon stroke="black" stroke-width="1" points="318.259,128.878 333.741,138.122"/>
          <polygon fill="black" stroke-width="1" points="333.741,138.122 329.435,129.728 324.309,138.314"/>
          <text x="301.5" y="154.5" font-family="Times New Roman" font-size="20">&#949;</text>
          <polygon stroke="black" stroke-width="1" points="319.413,173.245 332.587,166.755"/>
          <polygon fill="black" stroke-width="1" points="332.587,166.755 323.201,165.805 327.62,174.776"/>
          <text x="330.5" y="191.5" font-family="Times New Roman" font-size="20">&#949;</text>
          <path stroke="black" stroke-width="1" fill="none" d="M 128.776,124.049 A 118.15,118.15 0 0 1 354.224,124.049"/>
          <polygon fill="black" stroke-width="1" points="128.776,124.049 135.943,117.915 126.402,114.919"/>
          <text x="231.5" y="32.5" font-family="Times New Roman" font-size="20">&#949;</text>
          <polygon stroke="black" stroke-width="1" points="123.5,221.5 123.5,183.5"/>
          <polygon fill="black" stroke-width="1" points="123.5,183.5 118.5,191.5 128.5,191.5"/>
          <text x="98.5" y="208.5" font-family="Times New Roman" font-size="20">&#949;</text>
          <polygon stroke="black" stroke-width="1" points="153.5,251.5 329.5,251.5"/>
          <polygon fill="black" stroke-width="1" points="329.5,251.5 321.5,246.5 321.5,256.5"/>
          <text x="231.5" y="272.5" font-family="Times New Roman" font-size="20">&#949;</text>
          <polygon stroke="black" stroke-width="1" points="359.5,183.5 359.5,221.5"/>
          <polygon fill="black" stroke-width="1" points="359.5,221.5 364.5,213.5 354.5,213.5"/>
          <text x="364.5" y="208.5" font-family="Times New Roman" font-size="20">&#949;</text>
          <polygon stroke="black" stroke-width="1" points="70.5,251.5 93.5,251.5"/>
          <text x="15.5" y="257.5" font-family="Times New Roman" font-size="20">start</text>
          <polygon fill="black" stroke-width="1" points="93.5,251.5 85.5,246.5 85.5,256.5"/>
          <polygon stroke="black" stroke-width="1" points="389.5,251.5 472.5,251.5"/>
          <polygon fill="black" stroke-width="1" points="472.5,251.5 464.5,246.5 464.5,256.5"/>
          <text x="426.5" y="272.5" font-family="Times New Roman" font-size="20">a</text>
          <polygon stroke="black" stroke-width="1" points="461.5,156.5 461.5,132.5"/>
          <polygon fill="black" stroke-width="1" points="461.5,132.5 456.5,140.5 466.5,140.5"/>
          <text x="446.5" y="150.5" font-family="Times New Roman" font-size="20">a</text>
          <polygon stroke="black" stroke-width="1" points="541.5,156.5 541.5,132.5"/>
          <polygon fill="black" stroke-width="1" points="541.5,132.5 536.5,140.5 546.5,140.5"/>
          <text x="546.5" y="150.5" font-family="Times New Roman" font-size="20">b</text>
          <polygon stroke="black" stroke-width="1" points="654.5,132.5 654.5,156.5"/>
          <polygon fill="black" stroke-width="1" points="654.5,156.5 659.5,148.5 649.5,148.5"/>
          <text x="639.5" y="150.5" font-family="Times New Roman" font-size="20">a</text>
          <polygon stroke="black" stroke-width="1" points="739.5,132.5 739.5,156.5"/>
          <polygon fill="black" stroke-width="1" points="739.5,156.5 744.5,148.5 734.5,148.5"/>
          <text x="724.5" y="150.5" font-family="Times New Roman" font-size="20">b</text>
          <path stroke="black" stroke-width="1" fill="none" d="M 481.618,80.29 A 185.448,185.448 0 0 1 565.875,35.018"/>
          <polygon fill="black" stroke-width="1" points="565.875,35.018 556.939,31.993 559.241,41.725"/>
          <text x="495.5" y="43.5" font-family="Times New Roman" font-size="20">&#949;</text>
          <polygon stroke="black" stroke-width="1" points="559.5,78.5 577.5,54.5"/>
          <polygon fill="black" stroke-width="1" points="577.5,54.5 568.7,57.9 576.7,63.9"/>
          <text x="574.5" y="86.5" font-family="Times New Roman" font-size="20">&#949;</text>
          <polygon stroke="black" stroke-width="1" points="614.515,53.704 635.485,79.296"/>
          <polygon fill="black" stroke-width="1" points="635.485,79.296 634.282,69.939 626.547,76.277"/>
          <text x="599.5" y="86.5" font-family="Times New Roman" font-size="20">&#949;</text>
          <path stroke="black" stroke-width="1" fill="none" d="M 624.933,36.21 A 246.308,246.308 0 0 1 717.273,82.38"/>
          <polygon fill="black" stroke-width="1" points="717.273,82.38 714.15,73.478 707.902,81.286"/>
          <text x="678.5" y="45.5" font-family="Times New Roman" font-size="20">&#949;</text>
          <polygon stroke="black" stroke-width="1" points="486.495,226.126 477.505,211.874"/>
          <polygon fill="black" stroke-width="1" points="477.505,211.874 477.544,221.308 486.002,215.973"/>
          <text x="455.5" y="237.5" font-family="Times New Roman" font-size="20">&#949;</text>
          <polygon stroke="black" stroke-width="1" points="517.935,225.775 526.065,212.225"/>
          <polygon fill="black" stroke-width="1" points="526.065,212.225 517.662,216.512 526.237,221.657"/>
          <text x="528.5" y="237.5" font-family="Times New Roman" font-size="20">&#949;</text>
          <polygon stroke="black" stroke-width="1" points="671.052,211.521 680.948,226.479"/>
          <polygon fill="black" stroke-width="1" points="680.948,226.479 680.704,217.049 672.364,222.566"/>
          <text x="649.5" y="238.5" font-family="Times New Roman" font-size="20">&#949;</text>
          <polygon stroke="black" stroke-width="1" points="723.219,211.698 713.781,226.302"/>
          <polygon fill="black" stroke-width="1" points="713.781,226.302 722.323,222.297 713.924,216.87"/>
          <text x="724.5" y="238.5" font-family="Times New Roman" font-size="20">&#949;</text>
      </svg>

   2. table:

      |                     $I$                      |                    $I_a$                     |                 $I_b$                 |
      | :------------------------------------------: | :------------------------------------------: | :-----------------------------------: |
      |            $A=\{6, 7, 4, 0 ,2 \}$            |         $B=\{5, 4, 0, 2, 7, 9, 11\}$         |        $C = \{5, 4, 0, 2,7\}$         |
      |         $B=\{5, 4, 0, 2, 7, 9, 11\}$         |   $D=\{5, 4, 0, 2, 7, 9, 11, 13, 14, 16\}$   |   $E = \{5, 4, 0, 2,7,13, 14, 16\}$   |
      |            $C = \{5, 4, 0, 2,7\}$            |                     $B$                      |                  $C$                  |
      |   $D=\{5, 4, 0, 2, 7, 9, 11, 13, 14, 16\}$   | $F=\{5, 4, 0, 2, 7, 9, 11, 13, 14, 16, 18\}$ | $G = \{5, 4, 0, 2,7,13, 14, 16, 18\}$ |
      |      $E = \{5, 4, 0, 2,7,13, 14, 16\}$       |       $H=\{5, 4, 0, 2, 7, 9, 11, 18\}$       |       $I= \{5, 4, 0, 2,7, 18\}$       |
      | $F=\{5, 4, 0, 2, 7, 9, 11, 13, 14, 16, 18\}$ |                     $F$                      |                  $G$                  |
      |    $G = \{5, 4, 0, 2,7,13, 14, 16, 18\}$     |                     $H$                      |                  $I$                  |
      |       $H=\{5, 4, 0, 2, 7, 9, 11, 18\}$       |                     $D$                      |                  $E$                  |
      |          $I= \{5, 4, 0, 2,7, 18\}$           |                     $B$                      |                  $C$                  |

      

   3. DFA:

      <svg width="800" height="450" version="1.1" xmlns="http://www.w3.org/2000/svg">
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="131.5" cy="169.5" rx="30" ry="30"/>
      	<text x="126.5" y="175.5" font-family="Times New Roman" font-size="20">A</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="246.5" cy="122.5" rx="30" ry="30"/>
      	<text x="241.5" y="128.5" font-family="Times New Roman" font-size="20">B</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="246.5" cy="222.5" rx="30" ry="30"/>
      	<text x="241.5" y="228.5" font-family="Times New Roman" font-size="20">C</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="371.5" cy="73.5" rx="30" ry="30"/>
      	<text x="366.5" y="79.5" font-family="Times New Roman" font-size="20">D</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="371.5" cy="181.5" rx="30" ry="30"/>
      	<text x="366.5" y="187.5" font-family="Times New Roman" font-size="20">E</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="549.5" cy="47.5" rx="30" ry="30"/>
      	<text x="544.5" y="53.5" font-family="Times New Roman" font-size="20">F</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="549.5" cy="47.5" rx="24" ry="24"/>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="549.5" cy="147.5" rx="30" ry="30"/>
      	<text x="544.5" y="153.5" font-family="Times New Roman" font-size="20">G</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="549.5" cy="147.5" rx="24" ry="24"/>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="549.5" cy="237.5" rx="30" ry="30"/>
      	<text x="544.5" y="243.5" font-family="Times New Roman" font-size="20">H</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="549.5" cy="237.5" rx="24" ry="24"/>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="549.5" cy="337.5" rx="30" ry="30"/>
      	<text x="544.5" y="343.5" font-family="Times New Roman" font-size="20">I</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="549.5" cy="337.5" rx="24" ry="24"/>
      	<polygon stroke="black" stroke-width="1" points="159.27,158.15 218.73,133.85"/>
      	<polygon fill="black" stroke-width="1" points="218.73,133.85 209.433,132.248 213.216,141.505"/>
      	<text x="193.5" y="167.5" font-family="Times New Roman" font-size="20">a</text>
      	<polygon stroke="black" stroke-width="1" points="158.746,182.057 219.254,209.943"/>
      	<polygon fill="black" stroke-width="1" points="219.254,209.943 214.082,202.054 209.896,211.136"/>
      	<text x="174.5" y="217.5" font-family="Times New Roman" font-size="20">b</text>
      	<polygon stroke="black" stroke-width="1" points="274.431,111.551 343.569,84.449"/>
      	<polygon fill="black" stroke-width="1" points="343.569,84.449 334.296,82.713 337.946,92.024"/>
      	<text x="313.5" y="119.5" font-family="Times New Roman" font-size="20">a</text>
      	<polygon stroke="black" stroke-width="1" points="273.63,135.305 344.37,168.695"/>
      	<polygon fill="black" stroke-width="1" points="344.37,168.695 339.27,160.758 335.001,169.802"/>
      	<text x="294.5" y="173.5" font-family="Times New Roman" font-size="20">b</text>
      	<polygon stroke="black" stroke-width="1" points="246.5,192.5 246.5,152.5"/>
      	<polygon fill="black" stroke-width="1" points="246.5,152.5 241.5,160.5 251.5,160.5"/>
      	<text x="251.5" y="178.5" font-family="Times New Roman" font-size="20">a</text>
      	<path stroke="black" stroke-width="1" fill="none" d="M 234.823,250.007 A 22.5,22.5 0 1 1 217.564,229.964"/>
      	<text x="179.5" y="287.5" font-family="Times New Roman" font-size="20">b</text>
      	<polygon fill="black" stroke-width="1" points="217.564,229.964 209.179,225.641 210.004,235.607"/>
      	<path stroke="black" stroke-width="1" fill="none" d="M 576.297,34.275 A 22.5,22.5 0 1 1 576.297,60.725"/>
      	<text x="622.5" y="53.5" font-family="Times New Roman" font-size="20">a</text>
      	<polygon fill="black" stroke-width="1" points="576.297,60.725 579.83,69.473 585.708,61.382"/>
      	<polygon stroke="black" stroke-width="1" points="549.5,77.5 549.5,117.5"/>
      	<polygon fill="black" stroke-width="1" points="549.5,117.5 554.5,109.5 544.5,109.5"/>
      	<text x="554.5" y="103.5" font-family="Times New Roman" font-size="20">b</text>
      	<polygon stroke="black" stroke-width="1" points="401.185,69.164 519.815,51.836"/>
      	<polygon fill="black" stroke-width="1" points="519.815,51.836 511.176,48.045 512.622,57.94"/>
      	<text x="451.5" y="50.5" font-family="Times New Roman" font-size="20">a</text>
      	<polygon stroke="black" stroke-width="1" points="399.202,85.016 521.798,135.984"/>
      	<polygon fill="black" stroke-width="1" points="521.798,135.984 516.331,128.296 512.492,137.53"/>
      	<text x="465.5" y="101.5" font-family="Times New Roman" font-size="20">b</text>
      	<path stroke="black" stroke-width="1" fill="none" d="M 519.517,237.193 A 272.374,272.374 0 0 1 396.258,198.415"/>
      	<polygon fill="black" stroke-width="1" points="519.517,237.193 511.86,231.681 511.207,241.66"/>
      	<text x="441.5" y="246.5" font-family="Times New Roman" font-size="20">a</text>
      	<path stroke="black" stroke-width="1" fill="none" d="M 520.827,328.736 A 255.433,255.433 0 0 1 383.949,208.776"/>
      	<polygon fill="black" stroke-width="1" points="520.827,328.736 515.066,321.265 511.587,330.64"/>
      	<text x="426.5" y="302.5" font-family="Times New Roman" font-size="20">b</text>
      	<polygon stroke="black" stroke-width="1" points="527.437,217.172 393.563,93.828"/>
      	<polygon fill="black" stroke-width="1" points="393.563,93.828 396.059,102.926 402.835,95.571"/>
      	<text x="465.5" y="146.5" font-family="Times New Roman" font-size="20">a</text>
      	<path stroke="black" stroke-width="1" fill="none" d="M 400.922,187.348 A 723.496,723.496 0 0 1 522.029,225.449"/>
      	<polygon fill="black" stroke-width="1" points="400.922,187.348 407.658,193.953 409.811,184.188"/>
      	<text x="465.5" y="194.5" font-family="Times New Roman" font-size="20">b</text>
      	<path stroke="black" stroke-width="1" fill="none" d="M 519.513,337.676 A 297.894,297.894 0 0 1 256.237,150.862"/>
      	<polygon fill="black" stroke-width="1" points="256.237,150.862 254.571,160.148 263.854,156.429"/>
      	<text x="345.5" y="304.5" font-family="Times New Roman" font-size="20">a</text>
      	<path stroke="black" stroke-width="1" fill="none" d="M 524.428,353.918 A 190,190 0 0 1 254.365,251.418"/>
      	<polygon fill="black" stroke-width="1" points="254.365,251.418 252.36,260.637 261.773,257.26"/>
      	<text x="351.5" y="386.5" font-family="Times New Roman" font-size="20">b</text>
      	<polygon stroke="black" stroke-width="1" points="55.5,169.5 101.5,169.5"/>
      	<text x="0.5" y="175.5" font-family="Times New Roman" font-size="20">start</text>
      	<polygon fill="black" stroke-width="1" points="101.5,169.5 93.5,164.5 93.5,174.5"/>
      	<polygon stroke="black" stroke-width="1" points="549.5,177.5 549.5,207.5"/>
      	<polygon fill="black" stroke-width="1" points="549.5,207.5 554.5,199.5 544.5,199.5"/>
      	<text x="554.5" y="198.5" font-family="Times New Roman" font-size="20">a</text>
      	<path stroke="black" stroke-width="1" fill="none" d="M 571.101,168.203 A 118.2,118.2 0 0 1 571.101,316.797"/>
      	<polygon fill="black" stroke-width="1" points="571.101,316.797 580.018,313.718 572.24,307.433"/>
      	<text x="602.5" y="248.5" font-family="Times New Roman" font-size="20">b</text>
      </svg>

3. $a^*ba^*ba^*ba^*$ [10 points]

   1. NFA:

      <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="113.5" rx="30" ry="30"/>
      	<text x="188.5" y="119.5" font-family="Times New Roman" font-size="20">0</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="296.5" cy="113.5" rx="30" ry="30"/>
      	<text x="291.5" y="119.5" font-family="Times New Roman" font-size="20">1</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="193.5" cy="198.5" rx="30" ry="30"/>
      	<text x="188.5" y="204.5" font-family="Times New Roman" font-size="20">2</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="296.5" cy="198.5" rx="30" ry="30"/>
      	<text x="291.5" y="204.5" font-family="Times New Roman" font-size="20">3</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="383.5" cy="198.5" rx="30" ry="30"/>
      	<text x="378.5" y="204.5" font-family="Times New Roman" font-size="20">4</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="383.5" cy="113.5" rx="30" ry="30"/>
      	<text x="378.5" y="119.5" font-family="Times New Roman" font-size="20">5</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="463.5" cy="113.5" rx="30" ry="30"/>
      	<text x="458.5" y="119.5" font-family="Times New Roman" font-size="20">6</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="463.5" cy="198.5" rx="30" ry="30"/>
      	<text x="458.5" y="204.5" font-family="Times New Roman" font-size="20">7</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="536.5" cy="198.5" rx="30" ry="30"/>
      	<text x="531.5" y="204.5" font-family="Times New Roman" font-size="20">8</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="536.5" cy="113.5" rx="30" ry="30"/>
      	<text x="531.5" y="119.5" font-family="Times New Roman" font-size="20">9</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="622.5" cy="113.5" rx="30" ry="30"/>
      	<text x="612.5" y="119.5" font-family="Times New Roman" font-size="20">10</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="622.5" cy="198.5" rx="30" ry="30"/>
      	<text x="612.5" y="204.5" font-family="Times New Roman" font-size="20">11</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="695.5" cy="113.5" rx="30" ry="30"/>
      	<text x="685.5" y="119.5" font-family="Times New Roman" font-size="20">13</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="768.5" cy="113.5" rx="30" ry="30"/>
      	<text x="758.5" y="119.5" font-family="Times New Roman" font-size="20">14</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="695.5" cy="198.5" rx="30" ry="30"/>
      	<text x="685.5" y="204.5" font-family="Times New Roman" font-size="20">12</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="768.5" cy="198.5" rx="30" ry="30"/>
      	<text x="758.5" y="204.5" font-family="Times New Roman" font-size="20">15</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="768.5" cy="198.5" rx="24" ry="24"/>
      	<polygon stroke="black" stroke-width="1" points="223.5,113.5 266.5,113.5"/>
      	<polygon fill="black" stroke-width="1" points="266.5,113.5 258.5,108.5 258.5,118.5"/>
      	<text x="240.5" y="134.5" font-family="Times New Roman" font-size="20">a</text>
      	<path stroke="black" stroke-width="1" fill="none" d="M 192.325,83.905 A 54.191,54.191 0 0 1 297.675,83.905"/>
      	<polygon fill="black" stroke-width="1" points="192.325,83.905 199.064,77.303 189.344,74.954"/>
      	<text x="235.5" y="33.5" font-family="Times New Roman" font-size="20">&#949;</text>
      	<polygon stroke="black" stroke-width="1" points="193.5,168.5 193.5,143.5"/>
      	<polygon fill="black" stroke-width="1" points="193.5,143.5 188.5,151.5 198.5,151.5"/>
      	<text x="198.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
      	<polygon stroke="black" stroke-width="1" points="223.5,198.5 266.5,198.5"/>
      	<polygon fill="black" stroke-width="1" points="266.5,198.5 258.5,193.5 258.5,203.5"/>
      	<text x="235.5" y="219.5" font-family="Times New Roman" font-size="20">&#949;</text>
      	<polygon stroke="black" stroke-width="1" points="296.5,143.5 296.5,168.5"/>
      	<polygon fill="black" stroke-width="1" points="296.5,168.5 301.5,160.5 291.5,160.5"/>
      	<text x="271.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
      	<polygon stroke="black" stroke-width="1" points="132.5,198.5 163.5,198.5"/>
      	<text x="77.5" y="204.5" font-family="Times New Roman" font-size="20">start</text>
      	<polygon fill="black" stroke-width="1" points="163.5,198.5 155.5,193.5 155.5,203.5"/>
      	<polygon stroke="black" stroke-width="1" points="326.5,198.5 353.5,198.5"/>
      	<polygon fill="black" stroke-width="1" points="353.5,198.5 345.5,193.5 345.5,203.5"/>
      	<text x="335.5" y="219.5" font-family="Times New Roman" font-size="20">b</text>
      	<polygon stroke="black" stroke-width="1" points="383.5,168.5 383.5,143.5"/>
      	<polygon fill="black" stroke-width="1" points="383.5,143.5 378.5,151.5 388.5,151.5"/>
      	<text x="388.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
      	<polygon stroke="black" stroke-width="1" points="413.5,113.5 433.5,113.5"/>
      	<polygon fill="black" stroke-width="1" points="433.5,113.5 425.5,108.5 425.5,118.5"/>
      	<text x="418.5" y="134.5" font-family="Times New Roman" font-size="20">a</text>
      	<polygon stroke="black" stroke-width="1" points="463.5,143.5 463.5,168.5"/>
      	<polygon fill="black" stroke-width="1" points="463.5,168.5 468.5,160.5 458.5,160.5"/>
      	<text x="438.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
      	<polygon stroke="black" stroke-width="1" points="493.5,198.5 506.5,198.5"/>
      	<polygon fill="black" stroke-width="1" points="506.5,198.5 498.5,193.5 498.5,203.5"/>
      	<text x="495.5" y="219.5" font-family="Times New Roman" font-size="20">b</text>
      	<polygon stroke="black" stroke-width="1" points="536.5,168.5 536.5,143.5"/>
      	<polygon fill="black" stroke-width="1" points="536.5,143.5 531.5,151.5 541.5,151.5"/>
      	<text x="541.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
      	<polygon stroke="black" stroke-width="1" points="566.5,113.5 592.5,113.5"/>
      	<polygon fill="black" stroke-width="1" points="592.5,113.5 584.5,108.5 584.5,118.5"/>
      	<text x="574.5" y="134.5" font-family="Times New Roman" font-size="20">a</text>
      	<polygon stroke="black" stroke-width="1" points="622.5,143.5 622.5,168.5"/>
      	<polygon fill="black" stroke-width="1" points="622.5,168.5 627.5,160.5 617.5,160.5"/>
      	<text x="597.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
      	<polygon stroke="black" stroke-width="1" points="652.5,198.5 665.5,198.5"/>
      	<polygon fill="black" stroke-width="1" points="665.5,198.5 657.5,193.5 657.5,203.5"/>
      	<text x="654.5" y="219.5" font-family="Times New Roman" font-size="20">b</text>
      	<polygon stroke="black" stroke-width="1" points="725.5,113.5 738.5,113.5"/>
      	<polygon fill="black" stroke-width="1" points="738.5,113.5 730.5,108.5 730.5,118.5"/>
      	<text x="727.5" y="134.5" font-family="Times New Roman" font-size="20">a</text>
      	<polygon stroke="black" stroke-width="1" points="768.5,143.5 768.5,168.5"/>
      	<polygon fill="black" stroke-width="1" points="768.5,168.5 773.5,160.5 763.5,160.5"/>
      	<text x="743.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
      	<polygon stroke="black" stroke-width="1" points="695.5,168.5 695.5,143.5"/>
      	<polygon fill="black" stroke-width="1" points="695.5,143.5 690.5,151.5 700.5,151.5"/>
      	<text x="700.5" y="162.5" font-family="Times New Roman" font-size="20">&#949;</text>
      	<polygon stroke="black" stroke-width="1" points="725.5,198.5 738.5,198.5"/>
      	<polygon fill="black" stroke-width="1" points="738.5,198.5 730.5,193.5 730.5,203.5"/>
      	<text x="722.5" y="219.5" font-family="Times New Roman" font-size="20">&#949;</text>
      	<polygon stroke="black" stroke-width="1" points="566.5,198.5 592.5,198.5"/>
      	<polygon fill="black" stroke-width="1" points="592.5,198.5 584.5,193.5 584.5,203.5"/>
      	<text x="569.5" y="219.5" font-family="Times New Roman" font-size="20">&#949;</text>
      	<polygon stroke="black" stroke-width="1" points="413.5,198.5 433.5,198.5"/>
      	<polygon fill="black" stroke-width="1" points="433.5,198.5 425.5,193.5 425.5,203.5"/>
      	<text x="413.5" y="219.5" font-family="Times New Roman" font-size="20">&#949;</text>
      	<path stroke="black" stroke-width="1" fill="none" d="M 687.964,85.054 A 44.179,44.179 0 0 1 776.036,85.054"/>
      	<polygon fill="black" stroke-width="1" points="687.964,85.054 693.591,77.483 683.624,76.678"/>
      	<text x="722.5" y="35.5" font-family="Times New Roman" font-size="20">&#949;</text>
      	<path stroke="black" stroke-width="1" fill="none" d="M 533.853,84.128 A 46.882,46.882 0 0 1 625.147,84.128"/>
      	<polygon fill="black" stroke-width="1" points="533.853,84.128 540.546,77.479 530.81,75.199"/>
      	<text x="569.5" y="38.5" font-family="Times New Roman" font-size="20">&#949;</text>
      	<path stroke="black" stroke-width="1" fill="none" d="M 375.165,85.18 A 48.349,48.349 0 0 1 471.835,85.18"/>
      	<polygon fill="black" stroke-width="1" points="375.165,85.18 380.355,77.302 370.358,77.063"/>
      	<text x="413.5" y="28.5" font-family="Times New Roman" font-size="20">&#949;</text>
      </svg>

   2. table:

      |         $I$          |        $I_a$         |       $I_b$        |
      | :------------------: | :------------------: | :----------------: |
      |   $A= \{0, 2, 3\}$   |   $B=\{0, 1, 3\}$    | $C = \{4, 5, 7\}$  |
      |   $B=\{0, 1, 3\}$    |         $B$          |        $C$         |
      |  $C = \{4, 5, 7\}$   |  $D = \{5, 6, 7\}$   | $E = \{8,9, 11\}$  |
      |  $D = \{5, 6, 7\}$   |         $D$          |        $E$         |
      |  $E = \{8,9, 11\}$   | $F = \{9, 10, 11\}$  | $G = \{12,13,15\}$ |
      | $F = \{9, 10, 11\}$  |         $F$          |        $G$         |
      |  $G = \{12,13,15\}$  | $H = \{13, 14, 15\}$ |                    |
      | $H = \{13, 14, 15\}$ |         $H$          |                    |

      

   3. DFA:

      <svg width="800" height="300" version="1.1" xmlns="http://www.w3.org/2000/svg">
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="119.5" cy="169.5" rx="30" ry="30"/>
      	<text x="114.5" y="175.5" font-family="Times New Roman" font-size="20">A</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="187.5" cy="98.5" rx="30" ry="30"/>
      	<text x="182.5" y="104.5" font-family="Times New Roman" font-size="20">B</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="265.5" cy="169.5" rx="30" ry="30"/>
      	<text x="260.5" y="175.5" font-family="Times New Roman" font-size="20">C</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="344.5" cy="98.5" rx="30" ry="30"/>
      	<text x="339.5" y="104.5" font-family="Times New Roman" font-size="20">D</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="421.5" cy="169.5" rx="30" ry="30"/>
      	<text x="416.5" y="175.5" font-family="Times New Roman" font-size="20">E</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="505.5" cy="98.5" rx="30" ry="30"/>
      	<text x="500.5" y="104.5" font-family="Times New Roman" font-size="20">F</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="595.5" cy="169.5" rx="30" ry="30"/>
      	<text x="590.5" y="175.5" font-family="Times New Roman" font-size="20">G</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="595.5" cy="169.5" rx="24" ry="24"/>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="710.5" cy="169.5" rx="30" ry="30"/>
      	<text x="705.5" y="175.5" font-family="Times New Roman" font-size="20">H</text>
      	<ellipse stroke="black" stroke-width="1" fill="none" cx="710.5" cy="169.5" rx="24" ry="24"/>
      	<polygon stroke="black" stroke-width="1" points="43.5,169.5 89.5,169.5"/>
      	<text x="-11.5" y="175.5" font-family="Times New Roman" font-size="20">start</text>
      	<polygon fill="black" stroke-width="1" points="89.5,169.5 81.5,164.5 81.5,174.5"/>
      	<polygon stroke="black" stroke-width="1" points="140.251,147.834 166.749,120.166"/>
      	<polygon fill="black" stroke-width="1" points="166.749,120.166 157.605,122.485 164.827,129.402"/>
      	<text x="158.5" y="154.5" font-family="Times New Roman" font-size="20">a</text>
      	<polygon stroke="black" stroke-width="1" points="149.5,169.5 235.5,169.5"/>
      	<polygon fill="black" stroke-width="1" points="235.5,169.5 227.5,164.5 227.5,174.5"/>
      	<text x="187.5" y="190.5" font-family="Times New Roman" font-size="20">b</text>
      	<path stroke="black" stroke-width="1" fill="none" d="M 174.275,71.703 A 22.5,22.5 0 1 1 200.725,71.703"/>
      	<text x="182.5" y="22.5" font-family="Times New Roman" font-size="20">a</text>
      	<polygon fill="black" stroke-width="1" points="200.725,71.703 209.473,68.17 201.382,62.292"/>
      	<polygon stroke="black" stroke-width="1" points="209.685,118.694 243.315,149.306"/>
      	<polygon fill="black" stroke-width="1" points="243.315,149.306 240.764,140.223 234.033,147.618"/>
      	<text x="211.5" y="154.5" font-family="Times New Roman" font-size="20">b</text>
      	<path stroke="black" stroke-width="1" fill="none" d="M 697.275,142.703 A 22.5,22.5 0 1 1 723.725,142.703"/>
      	<text x="705.5" y="93.5" font-family="Times New Roman" font-size="20">a</text>
      	<polygon fill="black" stroke-width="1" points="723.725,142.703 732.473,139.17 724.382,133.292"/>
      	<polygon stroke="black" stroke-width="1" points="287.813,149.447 322.187,118.553"/>
      	<polygon fill="black" stroke-width="1" points="322.187,118.553 312.895,120.182 319.579,127.62"/>
      	<text x="310.5" y="154.5" font-family="Times New Roman" font-size="20">a</text>
      	<path stroke="black" stroke-width="1" fill="none" d="M 331.275,71.703 A 22.5,22.5 0 1 1 357.725,71.703"/>
      	<text x="339.5" y="22.5" font-family="Times New Roman" font-size="20">a</text>
      	<polygon fill="black" stroke-width="1" points="357.725,71.703 366.473,68.17 358.382,62.292"/>
      	<polygon stroke="black" stroke-width="1" points="366.555,118.837 399.445,149.163"/>
      	<polygon fill="black" stroke-width="1" points="399.445,149.163 396.953,140.065 390.174,147.416"/>
      	<text x="367.5" y="154.5" font-family="Times New Roman" font-size="20">b</text>
      	<polygon stroke="black" stroke-width="1" points="295.5,169.5 391.5,169.5"/>
      	<polygon fill="black" stroke-width="1" points="391.5,169.5 383.5,164.5 383.5,174.5"/>
      	<text x="338.5" y="190.5" font-family="Times New Roman" font-size="20">b</text>
      	<path stroke="black" stroke-width="1" fill="none" d="M 492.275,71.703 A 22.5,22.5 0 1 1 518.725,71.703"/>
      	<text x="500.5" y="22.5" font-family="Times New Roman" font-size="20">a</text>
      	<polygon fill="black" stroke-width="1" points="518.725,71.703 527.473,68.17 519.382,62.292"/>
      	<polygon stroke="black" stroke-width="1" points="444.412,150.134 482.588,117.866"/>
      	<polygon fill="black" stroke-width="1" points="482.588,117.866 473.251,119.212 479.706,126.849"/>
      	<text x="468.5" y="154.5" font-family="Times New Roman" font-size="20">a</text>
      	<polygon stroke="black" stroke-width="1" points="529.053,117.081 571.947,150.919"/>
      	<polygon fill="black" stroke-width="1" points="571.947,150.919 568.763,142.039 562.569,149.89"/>
      	<text x="535.5" y="154.5" font-family="Times New Roman" font-size="20">b</text>
      	<polygon stroke="black" stroke-width="1" points="451.5,169.5 565.5,169.5"/>
      	<polygon fill="black" stroke-width="1" points="565.5,169.5 557.5,164.5 557.5,174.5"/>
      	<text x="503.5" y="190.5" font-family="Times New Roman" font-size="20">b</text>
      	<polygon stroke="black" stroke-width="1" points="625.5,169.5 680.5,169.5"/>
      	<polygon fill="black" stroke-width="1" points="680.5,169.5 672.5,164.5 672.5,174.5"/>
      	<text x="648.5" y="190.5" font-family="Times New Roman" font-size="20">a</text>
      </svg>

