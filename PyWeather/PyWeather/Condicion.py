# -*- coding: utf-8 -*-
class Condicion:
    def __init__(self, fecha, temperatura, descripcion):
        """Representa las condiciones generales del estado metereológico."""
        self._fecha = fecha
        self._temperatura = temperatura
        self._descripcion = descripcion

    @property
    def fecha(self):
        """Obtiene la fecha en que se efectuó la lectura del estado meteorológico."""
        return self._fecha

    @property
    def temperatura(self):
        """Obtiene la temperatura del estado meteoreológico."""
        return self._temperatura

    @property
    def descripcion(self):
        """Obtiene la descripción del estado meteorológico."""
        return self._descripcion