clear all;
clc;
orimg=imread('img1.png');
imshow(orimg);
r=size(orimg,1);
c=size(orimg,2);

smothimg=uint8(zeros(r-2,c-2));

r1=0;
for i=2:r-1;
    for j=2:c-1;
        r1=orimg(i-1,j-1)/8+orimg(i-1,j)/8+orimg(i-1,j+1)/8+orimg(i,j-1)/8+orimg(i,j+1)/8+orimg(i+1,j-1)/8+orimg(i+1,j)/8+orimg(i+1,j+1)/8;
        smothimg(i,j)=r1;
    end
end
figure
imshow(smothimg);
