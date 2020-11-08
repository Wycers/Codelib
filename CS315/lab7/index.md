# Lab7 for CS315

## Some info...

Author: 11711918 吴烨昌

## Tasks

### Part 1

Read the lab instructions above and finish all the tasks.

### Part 2

Answer the questions and justify your answers. Simple yes or no answer will not get any credits.

1. What is a zero-day attack?

   An kind of attack that exploits some unknown vulnerability.

2. Can Snort catch zero-day network attacks? If not, why not? If yes, how?

   No, because snort is a Signature-based IDS, which can not catch zero-day network attack. Because there is no signature for a brand new zero-day attack.

3. Given a network that has 1 million connections daily where 0.1% (not 10%) are attacks. If the IDS has a true positive rate of 95%, and the probability that an alarm is an attack is 95%. What is false alarm rate? (You may use the math approach from the slides.)
   $$
   95\% = \frac{n_\text{alarmed_attack}}{n_\text{alarm}} = \frac{0.1\% \times10^{6} \times 95\%}{0.1\% \times10^{6}\times 95\% + 99.9\% \times10^{6}\times P_{FP}}
   $$

   $$
   P_{FP} \approx 0.005\%
   $$

### Part 3

Write a rule that will fire when you browse to craigslist.org or another particular website from the machine Snort is running on; it should look for any outbound TCP request to craigslist.org and alert on it.

1. The rule you added (from the rules file)

   ```snort
   alert tcp $HOME_NET any -> $EXTERNAL_NET $HTTP_PORTS (msg:"Craigslist http"; content:"craigslist.org"; http_header; sid:1000001; rev:1;)
   ```

2. A description of how you triggered the alert

   This rule constrains any tcp packets having `craigslist.org` in http header.

3. The alert itself from the log file (after converting it to readable text)

   ``` plaintext
   (Event)
   	sensor id: 0	event id: 4	event second: 1604489271	event microsecond: 776266
   	sig id: 1000001	gen id: 1	revision: 1	 classification: 0
   	priority: 0	ip source: 192.168.198.136	ip destination: 208.82.237.129
   	src port: 45316	dest port: 80	protocol: 6	impact_flag: 0	blocked: 0
   	mpls label: 0	vland id: 0	policy id: 0

   Packet
   	sensor id: 0	event id: 4	event second: 1604489271
   	packet second: 1604489271	packet microsecond: 776266
   	linktype: 1	packet_length: 132
   [    0] 00 50 56 FE E1 CA 00 0C 29 47 CE 16 08 00 45 00  .PV.....)G....E.
   [   16] 00 76 66 E2 40 00 40 06 8E 9A C0 A8 C6 88 D0 52  .vf.@.@........R
   [   32] ED 81 B1 04 00 50 04 65 9C 65 74 AC 2B F1 50 18  .....P.e.et.+.P.
   [   48] 72 10 E1 04 00 00 47 45 54 20 2F 20 48 54 54 50  r.....GET / HTTP
   [   64] 2F 31 2E 31 0D 0A 55 73 65 72 2D 41 67 65 6E 74  /1.1..User-Agent
   [   80] 3A 20 63 75 72 6C 2F 37 2E 33 35 2E 30 0D 0A 48  : curl/7.35.0..H
   [   96] 6F 73 74 3A 20 63 72 61 69 67 73 6C 69 73 74 2E  ost: craigslist.
   [  112] 6F 72 67 0D 0A 41 63 63 65 70 74 3A 20 2A 2F 2A  org..Accept: */*
   [  128] 0D 0A 0D 0A                                      ....
   ```

