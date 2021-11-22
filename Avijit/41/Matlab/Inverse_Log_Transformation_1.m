clc;
clear all;
close all;
a=imread('C:\Users\user\Desktop\Pics\cube.jpg');
ad=im2double(a);
x=ad;
[r,c]=size(ad);
factor=1;
for i=1:r
    for j = 1:c
  x(i,j)= exp(ad(i,j)^factor)-1;
    end
end
subplot(1,2,1);imshow(ad);title('before');
subplot(1,2,2);imshow(x);title('after');