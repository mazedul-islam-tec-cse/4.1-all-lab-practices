grayimage = imread('C:\Users\user\Desktop\lab image\ball.jpg');
subplot(3,1,1);
imshow(grayimage);
axis on;
title('Original imge')

smallImage = imresize(grayimage, 1/10, 'nearest');
subplot(3,1,2);
imshow(smallImage);
axis on;
title('Spatial resulotion by half')

bigImage = imresize(smallImage, 1, 'nearest');
subplot(3,1,3);
imshow(bigImage);
axis on;