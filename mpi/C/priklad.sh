#!/bin/bash

#SBATCH -p express
#SBATCH -n 4
#SBATCH -N 1
#SBATCH --job-name=priklad
#SBATCH --output=priklad_output.txt

srun ./priklad.x
