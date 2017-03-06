import pymongo

#client = pymongo.MongoClient("mongodb://usuarop:contrasena@ip/base_datos") # defaults to port 27017

client = pymongo.MongoClient("mongodb://remoteuser:remoteuser@192.168.100.1/proyecto")

db = client.proyecto


# print the number of documents in a collection
print db.prueba.count()

#Muestra los datos de la coleccion
for prueba in db.prueba.find():
    print prueba


print