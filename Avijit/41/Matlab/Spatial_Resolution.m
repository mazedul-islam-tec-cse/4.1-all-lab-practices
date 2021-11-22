% Read source image file
grayImage = imread('C:\Users\user\Desktop\Pics\cube.jpg');


subplot(3,1,1);
imshow(grayImage);
axis on;

smallImage = imresize(grayImage, 1/2, 'nearest');
subplot(3,1,2);
imshow(smallImage);
axis on;

bigImage = imresize(smallImage, 2, 'nearest');
subplot(3,1,3);
imshow(bigImage);
axis on;