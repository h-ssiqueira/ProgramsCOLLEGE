view wave 
wave clipboard store
wave create -driver freeze -pattern constant -value 00000011 -range 7 0 -starttime 0ns -endtime 1000ns sim:/ula/X 
WaveExpandAll -1
wave create -driver freeze -pattern constant -value 00000010 -range 7 0 -starttime 0ns -endtime 1000ns sim:/ula/Y 
WaveExpandAll -1
wave create -driver freeze -pattern constant -value 11 -range 1 0 -starttime 0ns -endtime 1000ns sim:/ula/op 
wave create -driver freeze -pattern constant -value 00 -range 1 0 -starttime 0ns -endtime 1000ns sim:/ula/op 
wave create -driver freeze -pattern constant -value 01 -range 1 0 -starttime 0ns -endtime 1000ns sim:/ula/op 
wave create -driver freeze -pattern constant -value 10 -range 1 0 -starttime 0ns -endtime 1000ns sim:/ula/op 
wave create -driver freeze -pattern constant -value 00 -range 1 0 -starttime 0ns -endtime 1000ns sim:/ula/op 
wave create -driver freeze -pattern constant -value 00 -range 1 0 -starttime 0ns -endtime 1000ns sim:/ula/op 
WaveExpandAll -1
wave edit change_value -start 100ns -end 200ns -value 01 Edit:/ula/op 
wave edit change_value -start 200ns -end 300ns -value 10 Edit:/ula/op 
wave edit change_value -start 300ns -end 400ns -value 11 Edit:/ula/op 
WaveCollapseAll -1
wave clipboard restore
