import bs4
from bs4 import BeautifulSoup as soup
from urllib.request import urlopen as uReq
uClient=uReq('https://www.flipkart.com/search?q=iphone&otracker=search&otracker1=search&marketplace=FLIPKART&as-show=on&as=off&as-pos=0&as-type=HISTORY');
html_page=uClient.read()
uClient.close()
page_soup=soup(html_page,"html.parser");
container=page_soup.findAll("div",{"class":"CXW8mj"});
print(container[0].text)
