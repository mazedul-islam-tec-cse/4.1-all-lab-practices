%add partition pictures into one

clear all
clc
%reading image
x1=imread('im1.jpg');
x2=imread('im2.jpg');
x3=imread('im3.jpg');
x4=imread('im4.jpg');
r=size(x1,1);
c=size(x1,2);


for i=1:r;
    for j=1:c;
  
           a(i,j)= x1(i,j);
    end
end

    for i=1:r;
        for j=1:c;
           
            a(i,j+c)=x2(i,j);
        end
    end

    for i=1:r;
        for j=1:c;
         
            a(i+r,j)=x3(i,j);
        end
    end
  
    
    for i=1:r;
        for j=1:c;
        
            a(i+r,j+c)=x4(i,j);
         end 
   end
          

imshow(a);

