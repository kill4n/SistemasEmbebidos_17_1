# importing the requests library
import requests
import numpy as np
import random
# api-endpoint
URL = "http://80.30.132.149/recibir_datos.php"
 
b = round(random.uniform( 0, 100 ),3)
#print b
mod=1
temp=np.random.randint(100, size=10)[5]
hum_s=np.random.randint(300, size=10)[5]
hum_a=np.random.randint(200, size=10)[5]
pres=np.random.randint(12, size=10)[5]
lum=np.random.randint(100, size=10)[5]


#temp=round(random.uniform( 0, 100 ),3)
#hum_s=round(random.uniform( 0, 300 ),3)
#hum_a=round(random.uniform( 0, 200 ),3)
#pres=round(random.uniform( 0, 12 ),3)
#lum=round(random.uniform( 0, 100 ),3)




import urllib
import urllib2

#url = 'http://www.someserver.com/cgi-bin/register.cgi'
user_agent = 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'
values = {'mod' : mod,'temp' : temp,'hum_s' : hum_s,'hum_a': hum_a,'pres':pres, 'lum':lum }

r = requests.get(url = URL, params = values)


headers = { 'User-Agent' : user_agent }
data = urllib.urlencode(values)
req = urllib2.Request(URL, data, headers)
response = urllib2.urlopen(req)
the_page = response.read()
