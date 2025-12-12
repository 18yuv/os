echo "Yuvraj Singh"
echo "24SCSE1430412"

rows=5 
for (( i=1; i<=rows; i++ )) 
do 
   for (( j=1; j<=i; j++ )) 
   do 
      echo -n "* " 
   done 
   echo "" 
done 
echo "Pattern 2"
for (( i=1; i<=rows; i++ )) 
do 
   for (( j=i; j<rows; j++ )) 
   do 
      echo -n "  " 
   done 
   for (( k=1; k<=i; k++ )) 
   do 
      echo -n "* " 
   done 
   echo "" 
done 