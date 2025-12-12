count=0
num=1

while [ $count -lt 10 ]
do
  echo $num
  num=$((num + 2))
  count=$((count + 1))
done
count=0
num=19

while [ $count -lt 10 ]
do
  echo $num
  num=$((num - 2))
  count=$((count + 1))
done