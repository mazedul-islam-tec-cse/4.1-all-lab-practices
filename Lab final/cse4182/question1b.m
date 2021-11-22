clear all;
clc;
orimg=imread('cameraman.png');
imshow(orimg);
r=size(orimg,1);
c=size(orimg,2);
orimg=double(orimg);
powrimg=uint8(zeros(r,c));
for i=1:r;
    for j=1:c
        powrimg(i,j)=orimg(i,j)^1.5;
    end
end
figure
imshow(powrimg);
invers=uint8(zeros(r,c));
for i=1:r;
    for j=1:c
       invers(i,j)=2^orimg(i,j);
    end
end
figure
imshow(invers);