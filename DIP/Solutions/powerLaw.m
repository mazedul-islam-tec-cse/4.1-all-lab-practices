clear all;
clc
close all;
oriImg=imread('pic.jpg')
subplot(3,3,1)
imshow(oriImg);
title('Original Image');

 
 
y=3;
or=im2double(oriImg);
s=or.^y;

subplot(3,3,2)

imshow(s);
title('Y=3');
 
y=4.0;
s=or.^y;
subplot(3,3,3)

imshow(s);
title('Y=4');

c=1; 
y=5.0;
s2=or.^y;
subplot(3,3,4)

imshow(s2);
title('Y= 5');