%divide 1 image into different parts
clear all
clc
%reading image
a=imread('download.jpg');
r=size(a,1);
c=size(a,2);

r1=round(r/2);
c1=round(c/2);

subplot(3,2,1),imshow(a);

for i=1:r1;
    for j=1:c1;
  
           x1(i,j)= a(i,j);
    end
end

    for i=1:r1;
        for j=1:c1;
           
            x2(i,j)=a(i,j+c1-1);
        end
    end
    
    for i=1:r1;
        for j=1:c1;
         
            x3(i,j)=a(i+r1-1,j);
        end
    end
    
    for i=1:r1;
        for j=1:c1;
        
            x4(i,j)=a(i+r1-1,j+c1-1);
         end 
   end
          
   
subplot(3,2,2),imshow(x1);
subplot(3,2,3),imshow(x2);
subplot(3,2,4),imshow(x3);
subplot(3,2,5),imshow(x4);
