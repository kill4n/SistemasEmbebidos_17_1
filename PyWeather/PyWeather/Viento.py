# -*- coding: utf-8 -*-
class Viento:
    def __init__(self, enfriamiento, direccion, velocidad):
        """Representa los datos del viento."""
        self._enfriamiento = enfriamiento
        self._direccion = direccion
        self._velocidad = velocidad

    @property
    def enfriamiento(self):
        """Obtiene el grado de enfriamiento del viento."""
        return self._enfriamiento

    @property
    def direccion(self):
        """Obtiene la dirección del viento."""
        return self._direccion

    @property
    def velocidad(self):
        """Obtiene la velocidad del viento."""
        return self._velocidad