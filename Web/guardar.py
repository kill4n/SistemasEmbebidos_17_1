#Importo libreria pymongo
from pymongo import MongoClient
from datetime import datetime

#import libreria para trabajar con fechas
import time
import datetime
import sys

#Importo libreria para recibir parametros
import argparse


#OBTENER LA FECHA DEL SISTEMA 
dtime = datetime.datetime.utcnow()

#CONVERTIR LA FECHA A FORMATO UNIX
fecha =int( time.mktime(dtime.timetuple()))

#print  fecha


#print(
#    datetime.datetime.fromtimestamp(
#        fecha
#    ).strftime('%Y-%m-%d %H:%M:%S')
#)


#OBTENER PARAMETROS COMO ARGUMENTOS EN PYTHON
parser = argparse.ArgumentParser(description='Parametros a recibir')

parser.add_argument('-mod', '--mod', help='ID Modulo', type=int,  default=0, required=False )
parser.add_argument('-temp', '--temp', help='Temperatura',  default="null", required=False )

parser.add_argument('-hum_s', '--hum_s', help='Humedad del suelo', default="null", required=False )

parser.add_argument('-hum_a', '--hum_a', help='Humedad Aire', default="null", required=False )

parser.add_argument('-pres', '--pres', help='Presion',  default="null", required=False )
parser.add_argument('-lum', '--lum', help='Luminocidad',  default="null", required=False )



args = parser.parse_args()
modulo= args.mod

if args.temp!="null":
 temperatura= float(args.temp)
else:
 temperatura=args.temp

if args.hum_s!="null":
 humedad_suelo= float(args.hum_s)
else:
 humedad_suelo= args.hum_s



if  args.hum_a!="null":
 humedad_aire= float(args.hum_a)
else:
 humedad_aire= args.hum_a


if  args.pres!="null":
 presion= float(args.pres)
else:
 presion= args.pres


if args.lum!="null":
 lumi=float(args.lum)
else:
 lumi=args.lum

#Si no llega valor del modulo  terminar programa
if  modulo == 0:
 print "No se ha indicado el modulo"
 sys.exit()
elif type(modulo) is int: 
    #MOSTRAR LOS VALORES QUE LLEGUEN DESDE EL WEB SERVICE
    print modulo
    print temperatura
    print humedad_suelo
    print humedad_aire
    print presion
    print lumi

    #Conecto al servidor
    client = MongoClient()
    #Selecciono la base de datos "proyecto_embebidos"
    db = client.proyecto_embebidos
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

    #Insertar Una medida
    insertar  = medidas.insert_one(
        {
        "id": siguiente_secuencia("medidas_id"),
        "id_modulo": modulo ,  #Id del modulo
        "fecha":  datetime.datetime.utcnow(),
    	"temp": (temperatura),
    	"hum_s": (humedad_suelo),
    	"hum_a": (humedad_aire),
    	"pres": (presion),
    	"lum": (lumi)
        })
else:
    print "El el valor del modulo no es un numero"
