a=imread('cameraman.jpg');

r=size(a,1);
c=size(a,2);

f=zeros(256,1);


for i=1:r
	for j=1:c
		f(a(i,j)+1)=f(a(i,j)+1)+1;
	end
end

	subplot(1,2,1),bar(f);
	subplot(1,2,2),imhist(a);