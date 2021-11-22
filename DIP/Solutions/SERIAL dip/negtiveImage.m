OriImg = imread('D:\muniat.jpg')
NegImg=255-OriImg
subplot(1,2,1)
imshow(OriImg)
title('Original image')

subplot(1,2,2)
imshow(NegImg)
title('Negative image')