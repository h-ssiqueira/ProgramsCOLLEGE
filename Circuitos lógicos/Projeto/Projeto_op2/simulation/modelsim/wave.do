view wave 
wave clipboard store
wave create -driver freeze -pattern constant -value 0 -starttime 0ns -endtime 2000ns sim:/teste/reset 
wave create -driver freeze -pattern clock -initialvalue 0 -period 100ns -dutycycle 50 -starttime 0ns -endtime 2000ns sim:/teste/clock 
wave create -driver freeze -pattern constant -value 0 -starttime 0ns -endtime 2000ns sim:/teste/sensor1 
wave create -driver freeze -pattern constant -value 0 -starttime 0ns -endtime 2000ns sim:/teste/sensor1 
wave create -driver freeze -pattern constant -value 0 -starttime 0ns -endtime 2000ns sim:/teste/sensor2 
wave create -driver freeze -pattern constant -value 0 -starttime 0ns -endtime 2000ns sim:/teste/sensor3 
wave create -driver freeze -pattern constant -value 0 -starttime 0ns -endtime 2000ns sim:/teste/sensor4 
wave create -driver freeze -pattern constant -value 0 -starttime 0ns -endtime 2000ns sim:/teste/sensor5 
wave edit change_value -start 2450ps -end 151925ps -value 1 Edit:/teste/reset 
wave edit change_value -start 249942ps -end 350408ps -value 1 Edit:/teste/sensor5 
wave edit change_value -start 333256ps -end 548891ps -value 1 Edit:/teste/sensor5 
wave edit change_value -start 450875ps -end 551342ps -value 1 Edit:/teste/sensor2 
wave edit change_value -start 512059ps -end 754649ps -value 1 Edit:/teste/sensor5 
wave edit change_value -start 651732ps -end 752199ps -value 1 Edit:/teste/sensor3 
wave edit change_value -start 850215ps -end 948232ps -value 1 Edit:/teste/sensor2 
wave edit change_value -start 1047452ps -end 1147918ps -value 1 Edit:/teste/sensor4 
wave edit change_value -start 1253286ps -end 1351302ps -value 1 Edit:/teste/sensor3 
wave edit change_value -start 1451769ps -end 1552236ps -value 1 Edit:/teste/sensor1 
wave edit change_value -start 1647802ps -end 1753169ps -value 1 Edit:/teste/sensor2 
WaveCollapseAll -1
wave clipboard restore
