a=imread('image.jpg')
subplot(2,2,1)
imshow(a)
subplot(2,2,2)
gray=rgb2gray(a)
imshow(gray);
d=im2bw(a);
subplot(2,2,3);
imshow(d)
e=imadjust(gray)

%subplot(2,2,4)

 %imshow(e)
% A = rand(50);
imwrite(a,'F:\image1.jpg')
%b=imread('F:\image1.jpg')
figure(2);
imshow('F:\image1.jpg')
title('Write image')