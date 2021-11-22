clear all;

a=imread('bitplan2.png');

 
r=size(a,1);
c=size(a,2);
e=uint8(zeros(r,c));
f=uint8(zeros(r,c));
b=uint8(zeros(r,c));
c1=uint8(zeros(r,c));
d=uint8(zeros(r,c));
subplot(3,4,1),imshow(a);
for i=1:r;
    for j=1:c;
       if(a(i,j)>128)
           b(i,j)=128;
           a(i,j)=mod(a(i,j),128);
   
           
     
       if(a(i,j)>64)
               c1(i,j)=64;
               a(i,j)=mod(a(i,j),64);
      
        if (a(i,j)>32)
               d(i,j)=32;
               a(i,j)=mod(a(i,j),32);
             
        if(a(i,j)>16)
               e(i,j)=16;
               a(i,j)=mod(a(i,j),16);
           
        if (a(i,j)>8)
               f(i,j)=8;
                a(i,j)=mod(a(i,j),8);
                
        if (a(i,j)>4)    
               g(i,j)=4;
               a(i,j)=mod(a(i,j),4);
                
         if (a(i,j)>2)
               h(i,j)=2;
                a(i,j)=mod(a(i,j),2);
                  
         if (a(i,j)>1)
               i(i,j)=2;
                a(i,j)=mod(a(i,j),2);
           end  
         end
       end
      end 
      end
      end
        
       end
         end
      
    end
    
                   
end       
 
 

subplot(3,4,2),imshow(b);
subplot(3,4,3),imshow(c1);
subplot(3,4,4),imshow(d);
subplot(3,4,5),imshow(e);
subplot(3,4,6),imshow(f);
subplot(3,4,7),imshow(g);
subplot(3,4,8),imshow(h);
subplot(3,4,9),imshow(i);
 
