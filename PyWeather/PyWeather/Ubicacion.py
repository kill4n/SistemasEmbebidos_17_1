# -*- coding: utf-8 -*-
class Ubicacion:
    def __init__(self, ciudad, pais, region):
        """Representa los datos de la ubicación en donde se realiza el pronóstico del clima."""
        self._ciudad = ciudad
        self._pais = pais
        self._region = region

    @property
    def ciudad(self):
        """Obtiene la ciudad de la ubicación."""
        return self._ciudad

    @property
    def pais(self):
        """Obtiene el país de la ubicación."""
        return self._pais

    @property
    def region(self):
        """Obtiene la región de la ubicación"""
        return self._region