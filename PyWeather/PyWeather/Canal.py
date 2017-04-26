# -*- coding: utf-8 -*-
class Canal:
    def __init__(self, unidades, ubicacion, viento, atmosfera, astronomia, imagen, latitud, longitud, link, condicion, pronosticos):
        """Representa el canal de presentación del estado metereológico."""
        self._unidades = unidades
        self._ubicacion = ubicacion
        self._viento = viento
        self._atmosfera = atmosfera
        self._astronomia = astronomia
        self._imagen = imagen
        self._latitud = latitud
        self._longitud = longitud
        self._link = link
        self._condicion = condicion
        self._pronosticos = pronosticos

    @property
    def unidades(self):
        """Obtiene la entidad que representa las unidades del estado meteorológico."""
        return self._unidades

    @property
    def ubicacion(self):
        """Obtiene la entidad que presenta los datos de la ubicación del estado meteorológico."""
        return self._ubicacion

    @property
    def viento(self):
        """Obtiene la entidad que presenta los datos del viento del estado metereológico."""
        return self._viento

    @property
    def atmosfera(self):
        """Obtiene la entidad que representa los datos atmosféricos del estado metereológico."""
        return self._atmosfera

    @property
    def astronomia(self):
        """Obtiene la entidad que representa los datos astronómicos del estado metereológico."""
        return self._astronomia

    @property
    def imagen(self):
        """Obtiene la entidad que representa la imagen del estado metereológico."""
        return self._imagen

    @property
    def latitud(self):
        """Obtiene la latitud de la ubicación del estado meteorológico."""
        return self._latitud

    @property
    def longitud(self):
        """Obtiene la longitud de la ubicación del estado meteorológico."""
        return self._longitud

    @property
    def link(self):
        """Obtiene el enlace Web de la ubicación del estado meteorológico."""
        return self._link

    @property
    def condicion(self):
        """Obtiene la entidad que representa las condiciones del estado metereológico."""
        return self._condicion

    @property
    def pronosticos(self):
        """Obtiene la entidad que presenta los datos de los pronósticos del estado metereológico."""
        return self._pronosticos