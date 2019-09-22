# Homework1 for CS305

Author: 11711918 吴烨昌

## Problem 1

### Description

Compare packet switch and circuit switch under the following scenario. Suppose you would like to deliver a message of $x$ bit. There are $k$ links from the source to destination. The propagation delay of each link is $d$ second, the transmission rate is $b$ bit/second. The circuit setup time under circuit switch is $s$ second. Under packet switch network, when the packet length is $p$ bit, the queue delay in every node can be neglected. Please calculate the condition, under which the delay of packet switch is smaller than that of the circuit switch.

### Solution

In circuit switch, total delay is

$$
t_{c} = s + k \times d + \frac{x}{b}
$$

In packet switch, total delay is

$$
t_{s} = \frac{(k - 1) \times p }{b} + \lceil \frac{x}{p}\rceil \times \frac{p}{b} + k \times  d
$$

When $t_s < t_c$, or

$$
(k - 1) \times p  + \lceil \frac{x}{p}\rceil \times p < s \times b + x
$$

## Problem 2


### Description

Calculate the overall delay of transmitting a $1000KB$ file under the following circumstance. The overall delay is defined as the time from the starting point of the transmission until the arrival of the last bit to the destination. RTT is assumed to be $100ms$, one packet is 1KB (1024B) size. The handshaking process costs 2RTT before transmitting the file. 

1. Transmission bandwidth is 1.5Mb/s, the packets can be continuously transmitted.
2. Transmission bandwidth is 1.5Mb/s, but when one packet is transmitted, the next packet should wait for 1 RTT (waiting for the acknowledgement of the receiver) before being transmitted.
3. Transmission bandwidth is infinite, i.e. transmission delay is 0. After every 1 RTT, as many as 20 packets can be transmitted. 

### Solution

The number of packets $n$ is $\frac{1000\text{KB}}{1KB}=1000$.

1. The delay under that transmission bandwidth is 1.5Mb/s, the packets can be continuously transmitted

$$
t_1 = 2\text{RTT} + n \times \frac{1\text{KB}}{1.5\times1024\text{KB/s}} = 1.66\text{s}
$$

2. The delay under that transmission bandwidth is 1.5Mb/s, but when one packet is transmitted, the next packet should wait for 1RTT (waiting for the acknowledgement of the receiver) before being transmitted:

$$
t_2 = 2\text{RTT} + n \times (\frac{1\text{KB}}{1.5\times1024\text{KB/s}} + 1\text{RTT})
$$
$$
t_2 = t_1 + n\text{RTT} = 101.66s
$$

3. The delay under transmission bandwidth is infinite, i.e. transmission delay is 0. After every 1RTT, as many as 20 packets can be transmitted.

$$
t_3 = 2\text{RTT} + \frac{n}{20/\text{RTT}} = 52\text{RTT} = 5.2\text{s}
$$

## Problem 3

### Description

List six access technologies. Classify each of them as home access, enterprise access, or wide-area mobile access. 

### Solution

|                         |         |
| :---------------------: | :--:|
|       Home access       | Dial-up modem over telephone line, Hybrid fiber-coaxial cable |WLAN|
|    Enterprise access    | IEEE 802.1X|
| Wide-area mobile access | 3G, 4G, 5G|



## Problem 4
### Description
1. List five nonproprietary Internet applications and the application-layer protocols that they use.
2. What information is used by a process running on one host to identify a process running on another host? 
### Solution
1. As followed
	1. web: http/https
	2. e-mail: imap/smtp/pop3
	3. remote desktop: rdp
	4. file transform: ftp
	5. remote access: ssh, telnet
2. The IP address and port number of the destination host