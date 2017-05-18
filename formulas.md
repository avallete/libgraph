# Formulas:

Some useful formulas for lem_in project.

## Calculate the number of turn needed to pass ants into one path:
    l = lemins
    P = Path len

#### Formula:
    l + (P - 1) = Number of turns


## Get the max useful len for alternatives paths:
    l = lemins
    p = shortest path len

#### Formula:
    (abs(p - l) - 1) = Size max of useful path.