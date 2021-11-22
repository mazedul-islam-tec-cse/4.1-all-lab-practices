clear all;

a=imread('neg.png');
r=size(a,1);
c=size(a,2);


for i=1:r;
    for j=1:c;
        b(i,j)=256-a(i,j);
    end
end
imshow(b);