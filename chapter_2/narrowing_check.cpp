/**
 * @file    <filename>
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates an implicit narrowing conversion warning enabled by the
 * -Wconversion compiler flag.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// With -Wconversion
int main()
{
    int y = 4.2; // Warning: conversion from 'double' to 'int' may alter its value
    return 0;
}