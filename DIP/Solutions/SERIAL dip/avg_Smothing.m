clear all
clc

a= imread('check.jpg');

imshow(a);
r=size(a,1);
c=size(a,2);
x=uint8(zeros(r-2,c-2));
for i=2:r-2
    for j=2:c-1
        
            x(i,j)=(a(i,j-1)/8+ a(i-1,j)/8+ a(i,j+1)/8+ a(i+1,j)/8+ a(i+1,j+1)/8+ a(i-1,j-1)/8+a(i-1,j+1)/8+ a(i+1,j-1)/8);
            
            temp=0;
           % for k=1:size(r,1)
                
                     %   temp=(temp+r(k))/size(r,1);
           
            %end
             
             %temp=temp/size(r,1);           
            
           
            
    end
end
figure;
imshow(x)
            