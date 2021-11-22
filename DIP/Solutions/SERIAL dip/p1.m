clear all;

a=uint8(zeros(256,256));

for i=1:255
    
        a(i,i)=i;
        a(i,256-i)=i;

end
 
subplot(1,2,1),imshow(a);

for i=1:255
    for j=1:255
        if a(i,j)<128
            b(i,j)=255;
        else
            b(i,j)=0;
            
        end
        if i==1||j==1
            b(i,j)=0;
        end
         
         if i==255||j==255
            b(i,j)=0;
         end
          
        
            
    end
end
 
subplot(1,2,2),imshow(b);
