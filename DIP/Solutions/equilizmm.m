clear all
clc

a= imread('cameraman.png');
r=size(a,1);
c=size(a,2);

x=uint8(zeros(r,c));

n=r*c;
f=zeros(256,1);
pdf=zeros(256,1);
cdf=zeros(256,1);
lcdf=zeros(256,1);
rcdf=zeros(256,1);

for i=1:r
    for j=1:c
  
        f(a(i,j)+1)=f(a(i,j)+1)+1;
        pdf(a(i,j)+1)=f(a(i,j)+1)/n;
    end
end

        
 
pcdf=0;  l=255;      
     for i=1:size(pdf)
            cdf(i)=pcdf+pdf(i);
            pcdf=cdf(i);
            rcdf(i)=round(l*cdf(i));
      end
        
        for i=1:r
            for j=1:c
                x(i,j)=rcdf(a(i,j)+1);
            end
        end
        y=histeq(a);
        subplot(2,2,1)
        imshow(a)
        subplot(2,2,3);
        imshow(x);
        subplot(2,2,4)
        imshow(y);
            
        
  