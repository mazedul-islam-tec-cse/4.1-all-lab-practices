clear all
clc
z=100
a=imread('pic.jpg');
r=size(a,1);
c=size(a,2);
d=size(a,3);
for i=1:r
	for j=1:c
		b(i,j)=255-2*a(i,j);
	end
end
subplot(1,2,1),imshow(a);
subplot(1,2,2),imshow(b);