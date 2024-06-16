#!/bin/bash

id -Gn $FT_USERS | tr ' ' ',' | tr -d '\n'

