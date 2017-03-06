
from pymongo import MongoClient

client = MongoClient('mongodb://192.168.1.104:27017/')

db = client.proyecto

for prueba in db.prueba.find():
    print prueba
