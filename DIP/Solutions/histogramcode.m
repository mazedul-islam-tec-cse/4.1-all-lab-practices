I=imread('image.jpg');
figure;
subplot(3,2,1) 
imshow(I)

title('Original Image');
subplot(3,2,2)
j=rgb2gray(I)
k=histeq(j);

m=imadjust(j,[0.5;1])
imhist (j,256);
title('Histogram  original');

subplot(3,2,4);
imhist (m,255);
subplot(3,2,3);
imshow(m)




m=imadjust(j,[0.1;1])
 
title('Histogram  original');

subplot(3,2,6);
imhist (m,255);
subplot(3,2,5);
imshow(m)
 

 