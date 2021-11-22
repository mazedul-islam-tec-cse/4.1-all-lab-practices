clear all;

a=imread('gray_lavel.png');

 
r=size(a,1);
c=size(a,2);
 
 
b=uint8(zeros(r,c));
 
subplot(1,3,1),imshow(a);
for i=1:r;
    for j=1:c;
       if(a(i,j)>128 && a(i,j)<240)
           b(i,j)=a(i,j);
           c(i,j)=0;
       else
           b(i,j)=0;
           c(i,j)=a(i,j);
            
       end
       
         
                   
               
    end
end

subplot(1,3,2),imshow(b);
subplot(1,3,3),imshow(c);
 
 
