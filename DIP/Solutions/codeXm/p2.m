clear all
clc
%reading image
a=imread('download.jpg');
r=size(a,1);
c=size(a,2);
subplot(1,2,1),imshow(a);
%gray to monochrome image
for i=1:r;
    for j=1:c;
        if a(i,j)>128;
            b(i,j)=255;
        else
            b(i,j)=0;
        end
    end
end
subplot(1,2,2),imshow(b);
