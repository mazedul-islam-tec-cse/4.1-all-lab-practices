clear all;
clc
a=imread('cameraman.jpg');
r=size(a,1);
c=size(a,2)
 
r1=round(r/2);
c1=round(c/2);

subplot(3,2,1),imshow(a);

for i=1:r
    for j=1:c
        if i<r1 & j<c1
            x1(i,j)=a(i,j);
        end
        
        if i>r1 & j<c1
            x2(i-r1,j)=a(i,j);
            
        end
        if i<r1 & j>c1
            x3(i,j-c1)=a(i,j); 
            
        end
          if i>r1  & j>c1 
            x4(i-r1,j-c1)=a(i,j);
            
           
          end
             
        
    end
end
imwrite(x1,'im1.jpg');
imwrite(x2,'im2.jpg');
imwrite(x3,'im3.jpg');
imwrite(x4,'im4.jpg');

subplot(3,2,3),imshow(x1);
subplot(3,2,4),imshow(x3);
subplot(3,2,5),imshow(x2);
subplot(3,2,6),imshow(x4);

