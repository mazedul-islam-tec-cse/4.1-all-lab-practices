clear all;
clc
close all;
oriImg=imread('cameraman.jpg')
subplot(3,3,4)
imshow(oriImg);
title('Original Image');

c=0.9; 
s=c.*log(double(1+oriImg));


subplot(3,3,1)
imshow(s);
c=0.5; 
neg2=c.*log(double(1+oriImg));

subplot(3,3,2)
imshow(neg2);

c=0.25; 
neg3=c.*log(double(1+oriImg));
subplot(3,3,3)
imshow(neg3);




