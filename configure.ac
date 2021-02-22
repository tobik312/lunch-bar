#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([lunch-bar], [0.1.0], [http://github.com/tobik312])

AC_CONFIG_SRCDIR([src/main.cpp])
AC_PREFIX_DEFAULT(/usr)

AM_INIT_AUTOMAKE([subdir-objects])

PKG_CHECK_MODULES(GTK, gtkmm-3.0 >= 3.24)

AC_PROG_CXX
AC_PROG_CC

AC_CONFIG_FILES([Makefile])

AC_OUTPUT