onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /light/x1
add wave -noupdate /light/x2
add wave -noupdate /light/f
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {244 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {0 ps} {919 ps}
view wave 
wave clipboard store
wave create -driver freeze -pattern constant -value 0 -starttime 0ps -endtime 400ps sim:/light/x1 
wave create -driver freeze -pattern constant -value 0 -starttime 0ps -endtime 400ps sim:/light/x1 
wave modify -driver freeze -pattern constant -value 1 -starttime 400ps -endtime 800ps Edit:/light/x1 
wave create -driver freeze -pattern clock -initialvalue 0 -period 400ps -dutycycle 50 -starttime 0ps -endtime 800ps sim:/light/x2 
WaveCollapseAll -1
wave clipboard restore
