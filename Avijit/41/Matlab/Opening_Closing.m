I = imread('C:\Users\user\Desktop\Pics\Binary.png');

%Convert to Binary Image
BW1 =im2bw(I);

%Structuring Element
SE = strel('rectangle',[50 60]);

%Opening
%Erosion
BW2 = imerode(BW1,SE);

%Dilation
subplot(1,2,1);
BW3 = imdilate(BW2,SE);
imshow(BW3);

%Closing
%Dilation
BW4 = imdilate(BW1,SE);

%Erosion
subplot(1,2,2);
BW5 = imerode(BW4,SE);
imshow(BW5);