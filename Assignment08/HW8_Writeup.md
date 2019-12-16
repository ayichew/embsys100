// Efrem A.
// HW8_Writeup.md

The biggest problem for me was matching LD2 with the right pin number on the controller. 
I know this has been done at the very early stage of the course, but it took me a lot of searches and circuit tracing to finally figure it out.
The other item I still couldn't fully grasp is the meaning of the PWM setting numbers, specifically:
 -   HAL_Delay(100); 
 -  step                   // this I changed from the degault and gave a visually trackable dimming and brightening.
 -  if(pwm_value == xxx  ) // this changed how long it is on in total and hence the brightest intensity, I think
 -   htim4.Init.Prescaler  // not sure
 -   htim4.Init.Period     // not sure
