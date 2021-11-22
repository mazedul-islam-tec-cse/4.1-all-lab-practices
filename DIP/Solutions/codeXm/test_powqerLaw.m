clear all;
clc
close all;
oriImg=imread('1.jpg')
subplot(3,3,1)
imshow(oriImg);
title('Original Image');
or=double(oriImg);
[m,n]=size(or);

y=1.5;
out=abs((1*or).^y);
maxm=max(out(:));
minm=min(out(:));
for i=1:m
    for j=1:n
        out(i,j)=(255.*out(i,j))/(maxm-minm)
    end
end
out=unit8(out)
subplot(3,3,2)
imshow(out);

        


