OriImg = imread('im1.jpg')
subplot(3,3,1)
imshow(OriImg)
title('Original image')

c=1
s= c.*log(double(1+OriImg))
subplot(3,2,2)
imshow(s)
title('imcomplement image1')

c=0.25
s1= c.*log(double(1+OriImg))
subplot(3,2,3)
imshow(s1)
title('imcomplement image2')

c=0.50
s2= c.*log(double(1+OriImg))
subplot(3,2,4)
imshow(s2)
title('imcomplement image3')


