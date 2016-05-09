fout='randomtestadventurer.out'
rtc_out='randomtestcard.out'
>$fout
make clean
make randomtestadventurer
echo "-- randomtestadventurer results --" >> $fout
randomtestadventurer >> $fout
echo >> $fout
echo "-- gcov for function 'playAdventurer' in randomtestadventurer --" >> $fout
gcov -fb dominion.c | grep -A 4 "^Function 'playAdventurer'" >> $fout
echo >> $fout
echo >> $fout
echo "Total code coverage for all functions in dominion.c" >> $fout
gcov -fb dominion.c >> $fout

>$rtc_out
make clean
make randomtestcard
echo "-- randomtestcard results --" >> $rtc_out
randomtestcard >> $rtc_out
echo >> $rtc_out
echo "-- gcov for function 'playVillage' in randomtestcard --" >> $rtc_out
gcov -fb dominion.c | grep -A 4 "^Function 'playVillage'" >> $rtc_out
echo >> $rtc_out
echo >> $rtc_out
echo "Total code coverage for all functions in dominion.c" >> $rtc_out
gcov -fb dominion.c >> $rtc_out

echo $fout
echo $rtc_out
