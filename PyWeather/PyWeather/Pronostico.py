# -*- coding: utf-8 -*-
class Pronostico:
    def __init__(self, codigo, fecha, dia, max_temp, min_temp, descripcion):
        """Representa un estado meteorológico."""
        self._codigo = codigo
        self._fecha = fecha
        self._dia = dia
        self._max_temp = max_temp
        self._min_temp = min_temp
        self._descripcion = descripcion

    @property
    def codigo(self):
        """Obtiene el código (consecutivo) del pronóstico."""
        return self._codigo

    @property
    def fecha(self):
        """Obtiene la fecha del pronóstico."""
        return self._fecha

    @property
    def max_temp(self):
        """Obtiene la temperatura máxima del pronóstico."""
        return self._max_temp

    @property
    def min_temp(self):
        """Obtiene la temperatura mínima del pronóstico."""
        return self._min_temp

    @property
    def descripcion(self):
        """Obtiene la descripción (estado) del pronóstico."""
        return self._descripcion