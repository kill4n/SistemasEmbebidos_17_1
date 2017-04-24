from pymongo import MongoClient
import pymongo
import pprint

#---------- 1 ------------------------------#

#CONECTO AL SERVIDOR LOCAL (RASPBERYY)
local = MongoClient()

#CONECTO A LA BASE DE DATOS
db = local.proyecto_embebidos


#BUSCO EL ULTIMO ID DE MEDIDAS DEL SERVIDOR
for prueba in db.medidas.find({"id":{'$exists': 'true' }}).sort("id", pymongo.DESCENDING).limit(1):
    last_id_local=prueba["id"]

print "Ultimo ID de las medidas LOCAL: "+ str(last_id_local)

#CIERRO CONEXION
local.close()


#---------- 2 ------------------------------#


#CONECTO AL SERVIDOR REMOTAMENTE
client = MongoClient('mongodb://186.155.238.250:27017/')

#CONECTO A LA BASE DE DATOS
db = client.proyecto_embebidos


#BUSCO EL ULTIMO ID DE MEDIDAS DEL SERVIDOR
for prueba in db.medidas.find({"id":{'$exists': 'true' }}).sort("id", pymongo.DESCENDING).limit(1):
    last_id_server=prueba["id"]
print "Ultimo ID de las medidas SERVIDOR: "+ str(last_id_server)
client.close()


#---------- 3 ------------------------------#

#SI LOS DATOS DEL SERVIDOR SON MENORES AL LOCAL
#ACTUALIZAR EL SERVIDOR CON LOS DATOS DE LA RASPBERRY#


if last_id_server <= last_id_local:
 print "HAY MENOS DATOS EN EL SERVIDOR"

 #---------- 3.1  ------------------------------#
 print "COENCTANDO AL SERVIDOR..."
 #CONECTO AL SERVIDOR LOCAL (RASPBERYY) y REMOTO
 local = MongoClient()
 client = MongoClient('mongodb://186.155.238.250:27017/')
 #CONECTO A LA BASE DE DATOS
 db = local.proyecto_embebidos
 db2 = client.proyecto_embebidos
 #CREO UN ARRAY CON LOS DATOS DEL SERVIDOR LOCAL A PRTIR DEL ID DEL SERVIDOR (DATOS FALTANTES PARA QUE QUEDE IGUAL EN EL SERVIDOR REMOTO)
 print "GENERANDO DATOS DEL SERVIDOR LOCAL  A PARTIR DEL ID DEL SERVIDOR REMOTO"
 nuevos_datos={}
 for prueba in db.medidas.find({"id":{'$exists': 'true' },"id": { "$gt": last_id_server }   }).sort("id", pymongo.ASCENDING):
    nuevos_datos=prueba
    print "SE HA ACTUALIZADO LA MEDIDA CON EL ID: "+str(prueba["id"])
    #INSERTO DATOS EN EL SERVIDOR REMOTO
    result = db2.medidas.insert_one(nuevos_datos)
    #ACTUALIZO LA SECUENCIA
    result2 = db2.secuencias.update_one( { "_id":"medidas_id"  } , {  "$set": { "seq":  prueba["id"]   } }    )



 #CIERRO CONEXION
 local.close()
 client.close()


