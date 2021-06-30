-- Copyright (C) 2018  Intel Corporation. All rights reserved.
-- Your use of Intel Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Intel Program License 
-- Subscription Agreement, the Intel Quartus Prime License Agreement,
-- the Intel FPGA IP License Agreement, or other applicable license
-- agreement, including, without limitation, that your use is for
-- the sole purpose of programming logic devices manufactured by
-- Intel and sold by Intel or its authorized distributors.  Please
-- refer to the applicable agreement for further details.

-- *****************************************************************************
-- This file contains a Vhdl test bench with test vectors .The test vectors     
-- are exported from a vector file in the Quartus Waveform Editor and apply to  
-- the top level entity of the current Quartus project .The user can use this   
-- testbench to simulate his design using a third-party simulation tool .       
-- *****************************************************************************
-- Generated on "03/27/2020 13:16:40"
                                                             
-- Vhdl Test Bench(with test vectors) for design  :          Exp2
-- 
-- Simulation tool : 3rd Party
-- 

LIBRARY ieee;                                               
USE ieee.std_logic_1164.all;                                

ENTITY Exp2_vhd_vec_tst IS
END Exp2_vhd_vec_tst;
ARCHITECTURE Exp2_arch OF Exp2_vhd_vec_tst IS
-- constants                                                 
-- signals                                                   
SIGNAL A : STD_LOGIC;
SIGNAL E : STD_LOGIC;
SIGNAL output : STD_LOGIC;
SIGNAL P : STD_LOGIC;
SIGNAL S : STD_LOGIC;
COMPONENT Exp2
	PORT (
	A : IN STD_LOGIC;
	E : IN STD_LOGIC;
	output : BUFFER STD_LOGIC;
	P : IN STD_LOGIC;
	S : IN STD_LOGIC
	);
END COMPONENT;
BEGIN
	i1 : Exp2
	PORT MAP (
-- list connections between master ports and signals
	A => A,
	E => E,
	output => output,
	P => P,
	S => S
	);

-- A
t_prcs_A: PROCESS
BEGIN
LOOP
	A <= '0';
	WAIT FOR 50000 ps;
	A <= '1';
	WAIT FOR 50000 ps;
	IF (NOW >= 1000000 ps) THEN WAIT; END IF;
END LOOP;
END PROCESS t_prcs_A;

-- E
t_prcs_E: PROCESS
BEGIN
LOOP
	E <= '0';
	WAIT FOR 100000 ps;
	E <= '1';
	WAIT FOR 100000 ps;
	IF (NOW >= 1000000 ps) THEN WAIT; END IF;
END LOOP;
END PROCESS t_prcs_E;

-- P
t_prcs_P: PROCESS
BEGIN
	FOR i IN 1 TO 2
	LOOP
		P <= '0';
		WAIT FOR 200000 ps;
		P <= '1';
		WAIT FOR 200000 ps;
	END LOOP;
	P <= '0';
WAIT;
END PROCESS t_prcs_P;

-- S
t_prcs_S: PROCESS
BEGIN
	S <= '0';
	WAIT FOR 400000 ps;
	S <= '1';
	WAIT FOR 400000 ps;
	S <= '0';
WAIT;
END PROCESS t_prcs_S;
END Exp2_arch;
