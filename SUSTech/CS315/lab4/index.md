# Lab4 for CS315

## Some info...

Author: 11711918 吴烨昌

## Tasks

### Part 1

![image-20201018163209458](image-20201018163209458.png)

The target's IP is `192.168.198.133`

![image-20201018163304241](image-20201018163304241.png)

Use nmap to scan the target and find the software version of the OS

![image-20201018163744331](image-20201018163744331.png)

The software version of the OS is `Linux 2.6.9-2.6.33`



The running services (list at least 3 of the running services).

![image-20201018163728086](image-20201018163728086.png)

The target has services ssh(port 22), ftp (port 21), smtp (port 25) and so on.



What are the differences if we use T1, T2, T3 flags? 

T0, T1 is for IDS version. T1 waits for 15 seconds between sending each probe.

T2 slows down the can to use less bandwidth and target machine resources. T2 waits for 0.4 seconds between sending each probe.

T3 is the default behaviour.



How to avoid detection from an intrusion detection system (e.g., stealthy scanning)? 

Use `-T0` or `-T1`.



### Part 2

1. Read the lab instructions above and finish all the tasks

   ![image-20201018165401372](image-20201018165401372.png)

   

   ![image-20201018165657389](image-20201018165657389.png)

   

   

   Using UnreaIRCD IRC Daemon Backdoor to Attack

   ![image-20201018170031875](image-20201018170031875.png)

   

   Using Vsftpd v2.3.4 Backdoor to attack

   ![image-20201018170258503](image-20201018170258503.png)

   

   

   

   Using armitage

   ![image-20201018170933648](image-20201018170933648.png)

   ![image-20201018171039415](image-20201018171039415.png)

   

   ![image-20201018171126417](image-20201018171126417.png)

   ![image-20201018171213280](image-20201018171213280.png)

   



2. Why do we need to assign an internal IP address (i.e., behind NAT) for Metasploitable2-Linux? What will happen if we assign a public IP to it?

   Publishing a host with so many vulnerabilities will bring security problem. For example, use reverse shell to attack internal network hosts.

3. Besides the two vulnerabilities we used, exploit another vulnerability using both msfconsole and Armitage. Show me that you have placed a file in the exploited remote machine via screenshots and by creating the file with the command “touch ” where  should be replaced with your full name

   ![image-20201018183144635](image-20201018183144635.png)

   ![image-20201018183158410](image-20201018183158410.png)