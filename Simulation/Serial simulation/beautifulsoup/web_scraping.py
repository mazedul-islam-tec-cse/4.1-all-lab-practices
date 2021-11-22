from bs4 import BeautifulSoup as soup
from  urllib.request import urlopen as uReq
my_url = 'https://www.flipkart.com/search?q=iphone&otracker=search&otracker1=search&marketplace=FLIPKART&as-show=on&as=off&as-pos=0&as-type=HISTORY'
uClient = uReq(my_url)
page_html = uClient.read()
uClient.close()
page_soup = soup(page_html, "html.parser")
containers = page_soup.findAll("div",{"class":"_13oc-S"})
print(len(containers))
print(soup.prettify(containers[0]))
container = containers[0]
print(container.div.img["alt"])
product_rating = container.findAll("div",{"class":"hGSR34"})
print(product_rating[0].text)
product_price = container.findAll("div",{"class":"_1vC4OE _2rQ-NK"})
print(product_price[0].text)

filename = "products.csv"
f = open(filename,"w",encoding="utf8")
headers = "Products_Name, Rating, Pricing\n"
f.write(headers)
for container in containers:
    product_container = container.findAll("div",{"class":"_3wU53n"})
    product_name = product_container[0].text
    product_name = product_name.replace(",", " - ")
    rating_container = container.findAll("div", {"class": "hGSR34"})
    product_rating = rating_container[0].text
    price_container = container.findAll("div", {"class": "_1vC4OE _2rQ-NK"})
    product_price = price_container[0].text
    product_price = product_price.replace(",", " - ")
    product_price = product_price.replace("?", " Rs. ")

    #print("product_name: " + product_name )
    #print("product_rating: " + product_rating)
    #print("product_price: " + product_price)
    #print("\n")
    print("product_name: " + product_name,"product_rating: " + product_rating, "product_price: " + product_price)
    st = product_name+","+product_rating+","+product_price+"\n"
    f.write(st)
f.close()


