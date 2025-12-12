swap_by_reference() {
    local var1=$1
    local var2=$2

    local temp=${!var1}
    eval "$var1=\${$var2}"
    eval "$var2=$temp"
}

echo "Enter first number:" 
read a
echo "Enter second number:" 
read b
echo "Before swapping: a = $a, b = $b"

swap_by_reference a b
echo "After swapping:  a = $a, b = $b"
















swap_by_value() {
    local x=$1
    local y=$2
    local temp=$x
    x=$y
    y=$temp
    echo "Inside swap_by_value:
     x = $x, y = $y"
}

echo "Enter first number:" 
read a
echo "Enter second number:" 
read b
echo "Before swapping: a = $a, b = $b"

swap_by_value $a $b

echo "After swap_by_value call:
 a = $a, b = $b"