clear all
clc
a=imread('cameraman.jpg');
r=size(a,1);
c=size(a,2);

for i=1:r
	for j=1:c
		b(i,j)=255-a(i,j);
	end
end
subplot(1,2,1),imshow(a);
subplot(1,2,2),imshow(b);