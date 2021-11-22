% Read source image file
Image = imread('C:\Users\user\Desktop\Pics\cube.jpg');

GrayImage = rgb2gray(Image)
subplot(1,2,1);
imshow(GrayImage);

Bit = 8;
changed_bit = 8 - 1;
subplot(1,2,2);
imshow(GrayImage,colormap(gray(2^changed_bit)));

