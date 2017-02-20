
#Importo libreria pymongo
from pymongo import MongoClient
from datetime import datetime
import time


#Conecto al servidor
client = MongoClient()
#Selecciono la base de datos "proyecto"
db = client.proyecto
#Indico  las colecciones
sensores = db.sensores
modulos = db.modulos
medidas = db.medidas
mod_sensor= db.mod_sensor

#Funcion para incrementar  el ID de cada elemento cuando se vaya a guardar un nuevo item
def siguiente_secuencia(name):
    result =""
    result = db.secuencias.update_one(
        {"_id": name},
        {"$inc": {"seq": 1}}
    )
    #print result.raw_result
    ultimo_id = db.secuencias.find_one({"_id": name})
    return ultimo_id["seq"]



#insertar un modulo
insertar  = modulos.insert_one(
    {
        "id": siguiente_secuencia("modulo_id"),
        "estado": True,  #Si esta activo o no
        "posicion": 3 #Posicion dentro de la finca

        })


#insertar un sensor
insertar  = sensores.insert_one(
    {
        "id": siguiente_secuencia("sensor_id"),
        "tipo": "Temperatura",  #Indico la clase de sensor
        "min": 3,  #Valor minimo que puede registrar
        "max": 100, #Valor maximo que puede registrar
        "muestreo" : 10 #Tiempo de muestreo [segundos]

        })

#Asociar los sensores a los modulos
insertar  = mod_sensor.insert_one(
    {
        "id": siguiente_secuencia("mod_sensor_id"),
        "id_modulo": 1 ,  #Id del modulo
        "id_sensor": 1,  #Id del sensor
        "estado": True,  #El sensor 1 del modulo 1 esta activo
        })

#Insertar Una medida
fecha = time.strftime("%d/%m/%Y")
hora=  time.strftime("%H:%M:%S")


insertar  = medidas.insert_one(
    {
        "id": siguiente_secuencia("medidas_id"),
        "id_modulo": 1 ,  #Id del modulo
        "id_sensor": 1,  #Id del sensor
        "valor_medida": 12.5, #Valor de la medida tomada del modulo 1 del sensor 1
        "fecha": fecha,  #guarda el dia mes ano
        "hora": hora  #guarda la hora en formato 24h
        })




#Mostrar el primer valor de la coleccion
print sensores.find_one()

 #Muestra la cantidad de datos guardados en la colecion
print "La cantidad de modulos guardados son: "+ str(modulos.count())
print "La cantidad de sensores guardos  son: "+ str(sensores.count())
print "La cantidad de medidas guardadas  son: "+ str(medidas.count())



#Mostrar todos los datos de los modulos
print "####################"
print "Los modulos guardados son:"
for modulos in modulos.find():
    print modulos



#Mostrar todos los datos de los sensores
print "####################"
print "Los sensores guardados son:"
for sensores in sensores.find():
    print sensores


#Mostrar todos los datos de las medidas
print "####################"
print "Las medidas guardadas son:"
for medidas in medidas.find():
    print medidas

