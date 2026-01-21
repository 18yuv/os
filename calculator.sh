echo "Yuvraj Singh"
echo "24SCSE1430412"

read -p "Enter first number: " a
read -p "Enter operator (+, -, *, /): " op
read -p "Enter second number: " b


case $op in
  +) result=$((a + b)) ;;
  -) result=$((a - b)) ;;
  \*) result=$((a * b)) ;;
  /)
    if [ "$b" -eq 0 ]; then
      echo "Error: Division by zero!"
      exit 1
    else
      result=$((a / b))
    fi
    ;;
  *) echo "Invalid operator!"; exit 1 ;;
esac

echo "Result: $result"