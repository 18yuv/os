echo "Yuvraj Singh"
echo "24SCSE1430412"

day=5
while [ $day -le 6 ]
do
    case $day in 
    1) echo "Monday" ;; 
    2) echo "Tuesday" ;; 
    3) echo "Wednesday" ;; 
    4) echo "thursday" ;; 
    5) echo "friday" ;; 
    6) echo "saturday" ;; 
    7) echo "sunday" ;; 
    *) echo "Invalid" ;; 
    esac
    day=$((day+1))
done