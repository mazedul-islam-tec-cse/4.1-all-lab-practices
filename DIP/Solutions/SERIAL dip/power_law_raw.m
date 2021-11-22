clear all;

a=imread('power.png');
r=size(a,1);
c=size(a,2);
im=im2double(a);
for i=1:r;
    for j=1:c;
       a(i,j)=a(i,j);
    end
end
for i=1:r;
    for j=1:c;
        b(i,j)=im(i,j)^0.6;
    end
end
imshow(b);
