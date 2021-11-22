OriImg = imread('D:\muniat.jpg')
subplot(3,3,1)
imshow(OriImg)
title('Original image')

c=1
g=3
or=im2double( OriImg)
s= c.*(or.^g)
subplot(3,2,2)
imshow(s)
title('power low image1')

g=0.75
or=im2double( OriImg)
s= c.*(or.^g)
subplot(3,2,3)
imshow(s)
title('power low image2')


g=0.50

s2= c.*(or.^g)
subplot(3,2,4)
imshow(s2)
title('power low image3')


