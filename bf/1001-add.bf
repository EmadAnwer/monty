,       #read character
>       #move pointer
,       #read character
[       #loop
    <       #move to p1
    +       #increment p1
    >       #move to p2
    -       #decrement p2
]           #we exit the loop
<       #go back to p1
------------------------------------------------ ; subtract 48 (ie ASCII char code of '0')
.       #print p1
