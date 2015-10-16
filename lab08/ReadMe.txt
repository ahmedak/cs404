# Comments from Mark A. Yoder

5   hello2.c
6   Makefile
0   Text from /var/log/kern.log
6   ReadMe.txt
5   Not Late

Grade 22/25

------------------------------------------------

To:   Mark A. Yoder

From :    Ahmed Karanath

Date:		08 October 2015

Subject:    LAB 08 REPORT (CS404)

Lab Members: Ahmed Karanath (B13104), Kansul Mahrifa (B13123)

Lab 08 was about working with LKMs (Loadable Kernel Modules). Initial setup instructions were obtained from Derek Molloy's blog (http://derekmolloy.ie/writing-a-linux-kernel-module-part-1-introduction/)

In the first part, the LKM from the above blog was loaded onto the BeagleBone. Output was tested and recorded in /var/ker.log.

In the second part, some modifications were made to the original file to make a new one:
1) Added the lab partners as authors.
2) Added new parameter addr to show address, with default value as "IIT"
3) Print address to ker.log file.
4) Added hello2.o to the makefile to compile it alongwith the hello.c file

"ker_log.txt" contains the last few lines of kern.log in /var/log in the beaglebone when the LKMs are installed and removed.

Lab08 was kindof challenging, since we were completely new to messing aroungd with kernel files and modules. We learnt some of the 'deep and messy stuff' in Linux. We'll do the rest of the tutorial in the coming lab.
