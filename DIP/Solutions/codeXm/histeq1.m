a=imread('cameraman.jpg');

r=size(a,1);
c=size(a,2);
x=uint8(zeros(r,c));
f=zeros(256,1);
pdf=zeros(256,1);
cdf=zeros(256,1);
lcdf=zeros(256,1);
rcdf=zeros(256,1);
n=r*c;

for i=1:r
	for j=1:c
	v=a(i,j)+1;
f(v)=f(v)+1;
pdf(v)=f(v)/n;
end
end

l=255; pcdf=0;
for i=1:size(pdf)
	cdf(i)=pcdf+pdf(i);
	pcdf=cdf(i);
	lcdf(i)=l*cdf(i);
	rcdf(i)=round(lcdf(i));
end

for i =1:r
	for j=1:c
		x(i,j)=rcdf(a(i,j)+1);
		end
end

 y=histeq(a);

subplot(2,2,1),imshow(a);
subplot(2,2,3),imshow(x);
 subplot(2,2,4),imshow(y);