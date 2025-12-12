while true
do
  echo "1.Name  2.Gmail  3.Age  4.Gender  5.Show  6.Exit"
  read -p "Enter choice: " c
  case $c in
    1) read -p "Name: " name ;;
    2) read -p "Gmail: " gmail ;;
    3) read -p "Age: " age ;;
    4) read -p "Gender: " gender ;;
    5) echo "Name: $name | Gmail: $gmail | Age: $age | Gender: $gender" ;;
    6) exit ;;
    *) echo "Invalid!" ;;
  esac
done