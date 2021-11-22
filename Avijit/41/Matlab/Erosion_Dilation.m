I = imread('C:\Users\user\Desktop\Pics\Binary.png');

%Convert to Binary Image
BW1 =im2bw(I);

%Structuring Element
SE = strel('rectangle',[50 60]);

%Erosion
subplot(1,2,1);
BW2 = imerode(BW1,SE);
imshow(BW2);

%Dilation
subplot(1,2,2);
BW3 = imdilate(BW1,SE);
imshow(BW3);
