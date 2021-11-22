clear all
clc

a= imread('cameraman.jpg');
imshow(a);
r=size(a,1);
c=size(a,2);
x=uint8(zeros(r-2,c-2));
for i=2:r-1
    for j=2:c-1
        
            r=[ a(i,j-1), a(i-1,j), a(i,j+1), a(i+1,j), a(i+1,j+1), a(i-1,j-1) ,a(i-1,j+1), a(i+1,j-1)];
            
            for k=1:8
                for l=1:8-k-1
                    if r(l)>r(l+1)
                        temp=r(l);
                        r(l)=r(l+1);
                        r(l+1)=temp;
                    end
                end
            end
            
                        
            
            
            x(i,j)=r(4);
    end
end
figure;
imshow(x)
            