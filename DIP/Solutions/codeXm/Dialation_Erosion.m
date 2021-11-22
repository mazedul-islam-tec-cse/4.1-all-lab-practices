clear all;
clc;
close all;
ori=imread('pic.jpg');
imre=imresize(ori,[500,600])
imshow(ori);
figure
imshow(imre)
bw=im2bw(imre)
figure
imshow(bw)
se=[1,1 ,1]
 
for i=2:500
    for j=2:600
         
     
        for k=1:3
            
            if bw(i-1,j-1)~=se(k)
                kk(i,j)=0
            else
                kk(i,j)=1
            end
        end
        disp(bw(i,j))
    end
end
I=mat2gray(kk)
figure 
imshow(I)
title('dilation')