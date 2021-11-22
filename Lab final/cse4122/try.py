import bs4
from bs4 import BeautifulSoup as soup
from urllib.request import urlopen as uReq
uClient=uReq('http://rurfid.ru.ac.bd/ru_profile/public/staff/227/profiles');
html_page=uClient.read()
uClient.close()
page_soup=soup(html_page,"html.parser");
container=page_soup.findAll("div",{"class":"col-xs-8 col-lg-10"});
print(container[0].text)

