# -*- coding: utf-8 -*-
class Atmosfera:
    def __init__(self, humedad, presion, elevacion, visibilidad):
        """Representa la información atmosférica de la ubicación."""
        self._humedad = humedad
        self._presion = presion
        self._elevacion = elevacion
        self._visibilidad = visibilidad

    @property
    def humedad(self):
        """Obtiene la humedad."""
        return self._humedad

    @property
    def presion(self):
        """Obtiene la presion atmosférica."""
        return self._presion

    @property
    def elevacion(self):
        """Obtiene la elevacion"""
        return self._elevacion

    @property
    def visibilidad(self):
        """Obtiene la visilibidad."""
        return self._visibilidad