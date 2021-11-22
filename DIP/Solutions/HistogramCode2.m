I = imread('D:\Muniat\ImageProcessing\image.jpg');
a=rgb2gray(I);
subplot(4,2,1)
imshow(a)
title('Low contrast Image ')
subplot(4,2,2)
imhist(a,64)
title('Low contrast Image Histogram')
J = histeq(a);
subplot(4,2,3)


T = imadjust(a,[0;1])
subplot(4,2,3)
imshow(T)

title('Adjust Image')
subplot(4,2,4)
imhist(T)
title('Adjust Histogram')
T = imadjust(a,[0.5;1])
subplot(4,2,5)
imshow(T)

title('Adjust Image2')
subplot(4,2,6)
imhist(T)
title('Adjust Histogram2')
T = imadjust(a,[0.75;1])
subplot(4,2,7)
imshow(T)

title('Dark Image')
subplot(4,2,8)
imhist(T)
title('Dark image Histogram3')