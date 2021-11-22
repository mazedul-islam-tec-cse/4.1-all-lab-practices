Image = imread('C:\Users\user\Desktop\Pics\cube.jpg');
x = rgb2gray(Image);
x = im2double(x);
[m,n] = size(x);
gamma = 0.4;
c = 1;
for i = 1:m
    for j = 1:n
        ex(i,j) = c*(x(i,j)^gamma);
    end
end

subplot(1,2,1)
imshow(x);
title('Original');

subplot(1,2,2)
imshow(ex);
title('Power Image');