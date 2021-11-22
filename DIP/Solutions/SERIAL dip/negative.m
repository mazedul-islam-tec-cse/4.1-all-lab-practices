clear all;
clc
close all;
oriImg=imread('1.JPG')
subplot(1,2,1)
imshow(oriImg);
title('Original Image');
neg=255-1-oriImg;
neg2=255-oriImg;
subplot(1,2,2)
imshow(neg);
imwrite(neg,'image4.jpg')
imwrite(neg2,'image5.jpg')




