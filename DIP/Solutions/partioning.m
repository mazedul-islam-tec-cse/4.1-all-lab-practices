clear
clc

a=imread('D:\Mahmud\Final_dip\camera.jpg');
r=size(a,1);
c=size(a,2);


subplot(3,2,1)
imshow(a)
title 'Orginal Image'
r1=round(r/2);
c1=round(c/2);

for i=1:r1
    for j=1:c1
        xi(i,j)=a(i,j);
    end
    
end

for i=1:r1
    for j=1:c1
        x1(i,j)=a(i,j);
    end
    
end

for i=1:r1
    for j=1:c1
        x2(i,j)=a(i,j+c1-1);
    end
    
end

for i=1:r1
    for j=1:c1
        x3(i,j)=a(i+r1-1,j);
    end
    
end

for i=1:r1
    for j=1:c1
        x4(i,j)=a(i+r1-1,j+c1-1);
    end
    
end

imwrite(x1,'im1.jpg');
imwrite(x2,'im2.jpg');
imwrite(x3,'im3.jpg');
imwrite(x4,'im4.jpg');
  subplot(3,2,3)      
imshow(x1)

  subplot(3,2,4)      
imshow(x2)

  subplot(3,2,5)      
imshow(x3)

  subplot(3,2,6)      
imshow(x4)
