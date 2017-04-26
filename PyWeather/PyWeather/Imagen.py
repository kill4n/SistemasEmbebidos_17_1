# -*- coding: utf-8 -*-
class Imagen:
    def __init__(self, ancho, alto, url):
        """Representa datos de la imagen del estado metereológico."""
        self._ancho = ancho
        self._alto = alto
        self._url = url

    @property
    def ancho(self):
        """Obtiene el ancho de la imagen en píxeles."""
        return self._ancho

    @property
    def alto(self):
        """Obtiene la altura de la imagen en píxeles."""
        return self._alto

    @property
    def url(self):
        """Obtiene el URL de la imagen"""
        return self._url