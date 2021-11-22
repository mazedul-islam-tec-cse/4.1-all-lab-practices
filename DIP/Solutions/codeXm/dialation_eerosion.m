clear all;
clc;
close all;
ori=imread('image2.jpg');
imre=imresize(ori,[500,600])
 
 
bw=im2bw(imre)
subplot(3,1,1)
imshow(bw)
title('Original Image')
se=strel('line',3,3)
 
 
I=imdilate(bw,se)
subplot(3,1,2) 
I2=imerode(bw,se);
imshow(I)
title('dilation')
subplot(3,1,3)

imshow(I2)
title('Erosion')
i1=imdilate(I2,se)
figure 
imshow(i1)
title('Opening1')
figure
open=imopen(bw,se);
imshow(open)
closing=imclose(bw,se);
figure
imshow(closing)