x = imread('D:\\Pics\center-table.jpg');

ResizeFactor = 1.5;
Zoom = imresize(x,ResizeFactor);
figure(1);
imshow(Zoom);

ResizeFactor = 0.5;
Shrink = imresize(x,ResizeFactor);
figure(2);
imshow(Shrink);

