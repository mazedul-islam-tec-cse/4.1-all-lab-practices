clear all;
clc;
orimg=imread('cameraman.png');
imshow(orimg);
r=size(orimg,1);
c=size(orimg,2);
h=zeros(256,1);
pdf=zeros(r,1);
cdf=zeros(r,1);
roundcdf=zeros(r,1);
hisimg=uint8(zeros(r,c));
n=r*c;
for i=1:r;
    for j=1:c
        h(orimg(i,j)+1)=h(orimg(i,j)+1)+1;
        pdf(orimg(i,j)+1)=h(orimg(i,j)+1)/n;
    end
end
pcdf=0;l=255;
 
for i=1:size(pdf);
    
        cdf(i)=pcdf+pdf(i);
        pcdf=cdf(i);
       
        roundcdf(i)=round(l*cdf(i));
   
end
for i=1:r;
    for j=1:c
        hisimg(i,j)=roundcdf(1);
    end
end
figure
imshow(hisimg);




