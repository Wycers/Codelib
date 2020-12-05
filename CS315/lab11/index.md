# Lab11 for CS315

## Some info...

Author: 11711918 吴烨昌

## Tasks

### Task 1: Posting a Malicious Message to Display an Alert Window

![image-20201205153059602](image-20201205153059602.png)

After that, when anybody visits Alice's profile, the alert popups.

![image-20201205153128752](image-20201205153128752.png)

### Task 2: Posting a Malicious Message to Display Cookies

![image-20201205153326190](image-20201205153326190.png)

![image-20201205153315169](image-20201205153315169.png)

### Task 3: Stealing Cookies from the Victim’s Machine

![image-20201205154407317](image-20201205154407317.png)

![image-20201205154350736](image-20201205154350736.png)



### Task 4: Becoming the Victim’s Friend

Alice edit her profile as follows:

![image-20201205162224946](image-20201205162224946.png)

​	After victim Boby visits Alice's profile, he becomes a friend of Alice:

![image-20201205162330636](image-20201205162330636.png) 

#### Questions. Please answer the following questions: 

 - Question 1: Explain the purpose of Lines ➀ and ➁, why are they are needed? 

   1. ts is timestamp, which is used by server to prevent replay attack. Provide this field to cheat server that it's a normal request.
   2. token is used by server to identify user. Provide this  field to cheat server that it's a normal request from current user.

 - Question 2: If the Elgg application only provide the Editor mode for the "About Me" field, i.e., you cannot switch to the Text mode, can you still launch a successful attack?

   Observe that saving profile action makes POST request to `/action/profile/edit`, we can construct such a request to freely modify fileds.

   ![image-20201205160958987](image-20201205160958987.png)

### Task 5: Modifying the Victim’s Profile

Alice sets her profile as follows:

![image-20201205165952655](image-20201205165952655.png)

Before boby visiting Alice's profile:

![image-20201205165414171](image-20201205165414171.png)



After visiting Alice's profile:

![image-20201205165903068](image-20201205165903068.png)

#### Questions. Please answer the following questions: 

- Question 3: Why do we need Line ➀? Remove this line, and repeat your attack. Report and explain your observation.

  It will accidently overwrite attacker's profile.

### Task 6: Writing a Self-Propagating XSS Worm

Samy change his profile to 

![image-20201205180549559](image-20201205180549559.png)

It's will make visitor Samy's friend and make visitor's profile a same copy as samy's profile.

Alice visits Samy's profile, and then Boby visits Alice's profile, which make Alice and Boby both Samy's friends.

![image-20201205180700341](image-20201205180700341.png)



### Task 7: Countermeasures

`HTMLawed` is already activated, malicious code can be executed normally

`htmlspecialchars`, the malicious code is invalid because the script is now common text.

