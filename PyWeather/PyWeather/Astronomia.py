# -*- coding: utf-8 -*-
class Astronomia:
    def __init__(self, amanecer, ocaso):
        """Representa los datos astronómicos de la ubicación."""
        self._amanecer = amanecer
        self._ocaso = ocaso

    @property
    def amanecer(self):
        """Obtiene la hora del amanecer"""
        return self._amanecer

    @property
    def ocaso(self):
        """Obtiene la hora del ocaso."""
        return self._ocaso