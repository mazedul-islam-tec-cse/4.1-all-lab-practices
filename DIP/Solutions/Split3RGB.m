% Read in original RGB image.
rgbImage = imread('D:\muniat.jpg');
% Extract color channels.
redChannel = rgbImage(:,:,1); % Red channel
greenChannel = rgbImage(:,:,2); % Green channel
blueChannel = rgbImage(:,:,3); % Blue channel
subplot(3, 3, 1);
imshow(rgbImage);
fontSize = 10;
title('Original RGB Image', 'FontSize', fontSize)
subplot(3, 3, 2);
imshow(just_red);
title('Red Channel in Red', 'FontSize', fontSize)
subplot(3, 3, 3);
imshow(just_green)
title('Green Channel in Green', 'FontSize', fontSize)
subplot(3, 3, 4);
imshow(just_blue);
title('Blue Channel in Blue', 'FontSize', fontSize)
subplot(3, 3, 5);
gray=rgb2gray(i)
imshow(gray)
title('Gray Scale Image', 'FontSize', fontSize)
%set(gcf, 'Units', 'Normalized', 'OuterPosition', [0, 0, 1, 1]);
