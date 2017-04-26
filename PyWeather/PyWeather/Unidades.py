# -*- coding: utf-8 -*-
class Unidades:
    def __init__(self, distancia, presion, velocidad, temperatura):
        """Representa la entidad de descripción de las unidades de medida."""
        self._distancia = distancia
        self._presion = presion
        self._velocidad = velocidad
        self._temperatura = temperatura

    @property
    def distancia(self):
        """Obtiene las unidades de distancia."""
        return self._distancia

    @property
    def presion(self):
        """Obtiene las unidades de presión."""
        return self._presion

    @property
    def velocidad(self):
        """Obtiene las unidades de velocidad."""
        return self._velocidad

    @property
    def temperatura(self):
        """Obtiene las unidades de temperatura."""
        return self._temperatura