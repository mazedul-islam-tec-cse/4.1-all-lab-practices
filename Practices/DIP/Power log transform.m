% s = c * r^y
% Map a narrow range of dark input values into a wider range of output
% values or vise versa
r = imread('C:\Users\user\Desktop\lab image\butterfly.jpg')
r = rgb2gray(r)
r = im2double(r)

[m n] = size(r)
gamma = 0.2
c = 1

for i = 1 : m
    for j = 1 : n
        s(i j) = c * (r(i j).^gamma)
    end
end

subplot(1,2,1)
imshow(r)
title('Original Image')
subplot(1,2,2)
imshow(s)
title('Power transform Image')
