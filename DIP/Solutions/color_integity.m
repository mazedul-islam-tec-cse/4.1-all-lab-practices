 
rgbImage = imread('image.jpg');
 
redChannel = rgbImage(:,:,1); % Red channel
greenChannel = rgbImage(:,:,2); % Green channel
blueChannel = rgbImage(:,:,3); % Blue channel
 
allBlack = zeros(size(rgbImage, 1), size(rgbImage, 2), 'uint8');
% Create color versions of the individual color channels.
just_red = cat(3, redChannel, allBlack, allBlack);
just_green = cat(3, allBlack, greenChannel, allBlack);
just_blue = cat(3, allBlack, allBlack, blueChannel);
% Recombine the individual color channels to create the original RGB image again.
recombinedRGBImage = cat(3, redChannel, greenChannel, blueChannel);
% Display them all.
subplot(3, 3, 2);
imshow(rgbImage);
fontSize = 20;
title('Original RGB Image')
subplot(3, 3, 4);
imshow(just_red);
title('Red Channel in Red')
subplot(3, 3, 5);
imshow(just_green)
title('Green Channel in Green')
subplot(3, 3, 6);
imshow(just_blue);
title('Blue Channel in Blue');
subplot(3, 3, 7);
imshow(recombinedRGBImage);
title('Recombined to Form Original RGB Image Again')
rgb=rgb2gray(rgbImage)
subplot(3,3,9)
imshow(rgb)
title('Gray scale image');
a=imfinfo('image.jpg')
size(rgbImage)
 


