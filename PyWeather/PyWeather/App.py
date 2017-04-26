# -*- coding: utf-8 -*-
from Weather import Weather
weather = Weather('368148', 'c')
print "Descripción condición: " + str(weather.canal.condicion.descripcion)
print "Temperatura: " + str(weather.canal.condicion.temperatura)
print "Pronóstico temperatura Minima: " + str(weather.canal.pronosticos[0].min_temp)
print "Pronóstico temperatura Maxima: " + str(weather.canal.pronosticos[0].max_temp)
print "Humedad: " + str(weather.canal.atmosfera.humedad)
