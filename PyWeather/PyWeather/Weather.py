# -*- coding: utf-8 -*-
import urllib2, urllib, json

from Canal import Canal
from Imagen import Imagen
from Unidades import Unidades
from Ubicacion import Ubicacion
from Viento import Viento
from Atmosfera import Atmosfera
from Astronomia import Astronomia
from Condicion import Condicion
from Pronostico import Pronostico

class Weather:
    def __init__(self, woeid, grados = 'c'):
        """Crea una instancia para obtener el estado meteorológico."""
        baseurl = "https://query.yahooapis.com/v1/public/yql?"
        yql_query = "select * from weather.forecast where woeid=" + woeid + " and u='" + grados + "'"
        yql_url = baseurl + urllib.urlencode({'q' : yql_query}) + "&format=json"
        result = urllib2.urlopen(yql_url).read()
        data = json.loads(result)

        jsonChannel = data['query']['results']['channel']

        jsonUnidades = jsonChannel['units']
        unidades = Unidades(jsonUnidades['distance'], jsonUnidades['pressure'], jsonUnidades['speed'], jsonUnidades['temperature'])

        jsonUbicacion = jsonChannel['location']
        ubicacion = Ubicacion(jsonUbicacion['city'], jsonUbicacion['country'], jsonUbicacion['region'])

        jsonViento = jsonChannel['wind']
        viento = Viento(jsonViento['chill'], jsonViento['direction'], jsonViento['speed'])

        jsonAtmosfera = jsonChannel['atmosphere']
        atmosfera = Atmosfera(jsonAtmosfera['humidity'], jsonAtmosfera['pressure'], jsonAtmosfera['rising'], jsonAtmosfera['visibility'])

        jsonAstronomia = jsonChannel['astronomy']
        astronomia = Astronomia(jsonAstronomia['sunrise'], jsonAstronomia['sunset'])

        jsonImagen = jsonChannel['image']
        imagen = Imagen(jsonImagen['width'], jsonImagen['height'], jsonImagen['url'])

        jsonCondicion = jsonChannel['item']['condition']
        condicion = Condicion(jsonCondicion['date'], jsonCondicion['temp'], jsonCondicion['text'])

        latitud = jsonChannel['item']['lat']
        longitud = jsonChannel['item']['long']
        link = jsonChannel['item']['link']

        pronosticos = []
        for f in data['query']['results']['channel']['item']['forecast']:
            pronostico = Pronostico(f['code'], f['date'], f['day'], f['high'], f['low'], f['text'])
            pronosticos.append(pronostico)

        self._canal = Canal(unidades, ubicacion, viento, atmosfera, astronomia, imagen, latitud, longitud, link, condicion, pronosticos)

    @property
    def canal(self):
        """Obtiene el canal de entrega de datos de la consulta del estado meteorológico."""
        return self._canal