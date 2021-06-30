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

-- VENDOR "Altera"
-- PROGRAM "Quartus Prime"
-- VERSION "Version 18.1.0 Build 625 09/12/2018 SJ Lite Edition"

-- DATE "09/26/2020 17:20:03"

-- 
-- Device: Altera 5CSEMA5F31C6 Package FBGA896
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY ALTERA_LNSIM;
LIBRARY CYCLONEV;
LIBRARY IEEE;
USE ALTERA_LNSIM.ALTERA_LNSIM_COMPONENTS.ALL;
USE CYCLONEV.CYCLONEV_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	REGS IS
    PORT (
	RegWrite : IN std_logic;
	load : IN std_logic;
	reset : IN std_logic;
	regA : IN std_logic_vector(1 DOWNTO 0);
	regB : IN std_logic_vector(1 DOWNTO 0);
	writeR : IN std_logic_vector(1 DOWNTO 0);
	data : IN std_logic_vector(7 DOWNTO 0);
	Rdata1 : OUT std_logic_vector(7 DOWNTO 0);
	Rdata2 : OUT std_logic_vector(7 DOWNTO 0)
	);
END REGS;

-- Design Ports Information
-- Rdata1[0]	=>  Location: PIN_AG21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Rdata1[1]	=>  Location: PIN_AH20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Rdata1[2]	=>  Location: PIN_AE19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Rdata1[3]	=>  Location: PIN_AJ16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Rdata1[4]	=>  Location: PIN_AH22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Rdata1[5]	=>  Location: PIN_AH24,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Rdata1[6]	=>  Location: PIN_AH18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Rdata1[7]	=>  Location: PIN_AA18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Rdata2[0]	=>  Location: PIN_AK16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Rdata2[1]	=>  Location: PIN_AE18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Rdata2[2]	=>  Location: PIN_AK21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Rdata2[3]	=>  Location: PIN_AF16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Rdata2[4]	=>  Location: PIN_AG22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Rdata2[5]	=>  Location: PIN_AC18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Rdata2[6]	=>  Location: PIN_AH17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Rdata2[7]	=>  Location: PIN_AK22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- regA[0]	=>  Location: PIN_AJ17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- regA[1]	=>  Location: PIN_AJ21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- RegWrite	=>  Location: PIN_AJ19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- regB[0]	=>  Location: PIN_W17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- regB[1]	=>  Location: PIN_V17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- data[0]	=>  Location: PIN_AH19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- writeR[1]	=>  Location: PIN_AG18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- writeR[0]	=>  Location: PIN_AK19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- load	=>  Location: PIN_AA16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reset	=>  Location: PIN_AK18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- data[1]	=>  Location: PIN_AB17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- data[2]	=>  Location: PIN_AJ20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- data[3]	=>  Location: PIN_W16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- data[4]	=>  Location: PIN_AD17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- data[5]	=>  Location: PIN_AG23,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- data[6]	=>  Location: PIN_AF19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- data[7]	=>  Location: PIN_AG20,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF REGS IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_RegWrite : std_logic;
SIGNAL ww_load : std_logic;
SIGNAL ww_reset : std_logic;
SIGNAL ww_regA : std_logic_vector(1 DOWNTO 0);
SIGNAL ww_regB : std_logic_vector(1 DOWNTO 0);
SIGNAL ww_writeR : std_logic_vector(1 DOWNTO 0);
SIGNAL ww_data : std_logic_vector(7 DOWNTO 0);
SIGNAL ww_Rdata1 : std_logic_vector(7 DOWNTO 0);
SIGNAL ww_Rdata2 : std_logic_vector(7 DOWNTO 0);
SIGNAL \~QUARTUS_CREATED_GND~I_combout\ : std_logic;
SIGNAL \RegWrite~input_o\ : std_logic;
SIGNAL \writeR[0]~input_o\ : std_logic;
SIGNAL \writeR[1]~input_o\ : std_logic;
SIGNAL \reset~input_o\ : std_logic;
SIGNAL \load~input_o\ : std_logic;
SIGNAL \R0[0]~1_combout\ : std_logic;
SIGNAL \data[0]~input_o\ : std_logic;
SIGNAL \R0[0]~0_combout\ : std_logic;
SIGNAL \R1[0]~0_combout\ : std_logic;
SIGNAL \R1[0]~1_combout\ : std_logic;
SIGNAL \R3[0]~1_combout\ : std_logic;
SIGNAL \R3[0]~0_combout\ : std_logic;
SIGNAL \R2[0]~1_combout\ : std_logic;
SIGNAL \R2[0]~0_combout\ : std_logic;
SIGNAL \regA[0]~input_o\ : std_logic;
SIGNAL \regA[1]~input_o\ : std_logic;
SIGNAL \Mux7~0_combout\ : std_logic;
SIGNAL \Rdata1[0]$latch~combout\ : std_logic;
SIGNAL \data[1]~input_o\ : std_logic;
SIGNAL \R0[1]~2_combout\ : std_logic;
SIGNAL \R1[1]~2_combout\ : std_logic;
SIGNAL \R3[1]~2_combout\ : std_logic;
SIGNAL \R2[1]~2_combout\ : std_logic;
SIGNAL \Mux6~0_combout\ : std_logic;
SIGNAL \Rdata1[1]$latch~combout\ : std_logic;
SIGNAL \data[2]~input_o\ : std_logic;
SIGNAL \R3[2]~3_combout\ : std_logic;
SIGNAL \R0[2]~3_combout\ : std_logic;
SIGNAL \R2[2]~3_combout\ : std_logic;
SIGNAL \R1[2]~3_combout\ : std_logic;
SIGNAL \Mux5~0_combout\ : std_logic;
SIGNAL \Rdata1[2]$latch~combout\ : std_logic;
SIGNAL \data[3]~input_o\ : std_logic;
SIGNAL \R1[3]~4_combout\ : std_logic;
SIGNAL \R3[3]~4_combout\ : std_logic;
SIGNAL \R2[3]~4_combout\ : std_logic;
SIGNAL \R0[3]~4_combout\ : std_logic;
SIGNAL \Mux4~0_combout\ : std_logic;
SIGNAL \Rdata1[3]$latch~combout\ : std_logic;
SIGNAL \data[4]~input_o\ : std_logic;
SIGNAL \R0[4]~5_combout\ : std_logic;
SIGNAL \R3[4]~5_combout\ : std_logic;
SIGNAL \R2[4]~5_combout\ : std_logic;
SIGNAL \R1[4]~5_combout\ : std_logic;
SIGNAL \Mux3~0_combout\ : std_logic;
SIGNAL \Rdata1[4]$latch~combout\ : std_logic;
SIGNAL \data[5]~input_o\ : std_logic;
SIGNAL \R3[5]~6_combout\ : std_logic;
SIGNAL \R1[5]~6_combout\ : std_logic;
SIGNAL \R0[5]~6_combout\ : std_logic;
SIGNAL \R2[5]~6_combout\ : std_logic;
SIGNAL \Mux2~0_combout\ : std_logic;
SIGNAL \Rdata1[5]$latch~combout\ : std_logic;
SIGNAL \data[6]~input_o\ : std_logic;
SIGNAL \R0[6]~7_combout\ : std_logic;
SIGNAL \R2[6]~7_combout\ : std_logic;
SIGNAL \R1[6]~7_combout\ : std_logic;
SIGNAL \R3[6]~7_combout\ : std_logic;
SIGNAL \Mux1~0_combout\ : std_logic;
SIGNAL \Rdata1[6]$latch~combout\ : std_logic;
SIGNAL \data[7]~input_o\ : std_logic;
SIGNAL \R0[7]~8_combout\ : std_logic;
SIGNAL \R1[7]~8_combout\ : std_logic;
SIGNAL \R3[7]~8_combout\ : std_logic;
SIGNAL \R2[7]~8_combout\ : std_logic;
SIGNAL \Mux0~0_combout\ : std_logic;
SIGNAL \Rdata1[7]$latch~combout\ : std_logic;
SIGNAL \regB[0]~input_o\ : std_logic;
SIGNAL \regB[1]~input_o\ : std_logic;
SIGNAL \Mux15~0_combout\ : std_logic;
SIGNAL \Rdata2[0]$latch~combout\ : std_logic;
SIGNAL \Mux14~0_combout\ : std_logic;
SIGNAL \Rdata2[1]$latch~combout\ : std_logic;
SIGNAL \Mux13~0_combout\ : std_logic;
SIGNAL \Rdata2[2]$latch~combout\ : std_logic;
SIGNAL \Mux12~0_combout\ : std_logic;
SIGNAL \Rdata2[3]$latch~combout\ : std_logic;
SIGNAL \Mux11~0_combout\ : std_logic;
SIGNAL \Rdata2[4]$latch~combout\ : std_logic;
SIGNAL \Mux10~0_combout\ : std_logic;
SIGNAL \Rdata2[5]$latch~combout\ : std_logic;
SIGNAL \Mux9~0_combout\ : std_logic;
SIGNAL \Rdata2[6]$latch~combout\ : std_logic;
SIGNAL \Mux8~0_combout\ : std_logic;
SIGNAL \Rdata2[7]$latch~combout\ : std_logic;
SIGNAL R0 : std_logic_vector(7 DOWNTO 0);
SIGNAL R1 : std_logic_vector(7 DOWNTO 0);
SIGNAL R2 : std_logic_vector(7 DOWNTO 0);
SIGNAL R3 : std_logic_vector(7 DOWNTO 0);
SIGNAL \ALT_INV_data[7]~input_o\ : std_logic;
SIGNAL \ALT_INV_data[6]~input_o\ : std_logic;
SIGNAL \ALT_INV_data[5]~input_o\ : std_logic;
SIGNAL \ALT_INV_data[4]~input_o\ : std_logic;
SIGNAL \ALT_INV_data[3]~input_o\ : std_logic;
SIGNAL \ALT_INV_data[2]~input_o\ : std_logic;
SIGNAL \ALT_INV_data[1]~input_o\ : std_logic;
SIGNAL \ALT_INV_reset~input_o\ : std_logic;
SIGNAL \ALT_INV_load~input_o\ : std_logic;
SIGNAL \ALT_INV_writeR[0]~input_o\ : std_logic;
SIGNAL \ALT_INV_writeR[1]~input_o\ : std_logic;
SIGNAL \ALT_INV_data[0]~input_o\ : std_logic;
SIGNAL \ALT_INV_regB[1]~input_o\ : std_logic;
SIGNAL \ALT_INV_regB[0]~input_o\ : std_logic;
SIGNAL \ALT_INV_RegWrite~input_o\ : std_logic;
SIGNAL \ALT_INV_regA[1]~input_o\ : std_logic;
SIGNAL \ALT_INV_regA[0]~input_o\ : std_logic;
SIGNAL ALT_INV_R3 : std_logic_vector(7 DOWNTO 0);
SIGNAL ALT_INV_R2 : std_logic_vector(7 DOWNTO 0);
SIGNAL ALT_INV_R1 : std_logic_vector(7 DOWNTO 0);
SIGNAL ALT_INV_R0 : std_logic_vector(7 DOWNTO 0);
SIGNAL \ALT_INV_Rdata2[7]$latch~combout\ : std_logic;
SIGNAL \ALT_INV_Rdata2[6]$latch~combout\ : std_logic;
SIGNAL \ALT_INV_Rdata2[5]$latch~combout\ : std_logic;
SIGNAL \ALT_INV_Rdata2[4]$latch~combout\ : std_logic;
SIGNAL \ALT_INV_Rdata2[3]$latch~combout\ : std_logic;
SIGNAL \ALT_INV_Rdata2[2]$latch~combout\ : std_logic;
SIGNAL \ALT_INV_Rdata2[1]$latch~combout\ : std_logic;
SIGNAL \ALT_INV_Rdata2[0]$latch~combout\ : std_logic;
SIGNAL \ALT_INV_Rdata1[7]$latch~combout\ : std_logic;
SIGNAL \ALT_INV_Rdata1[6]$latch~combout\ : std_logic;
SIGNAL \ALT_INV_Rdata1[5]$latch~combout\ : std_logic;
SIGNAL \ALT_INV_Rdata1[4]$latch~combout\ : std_logic;
SIGNAL \ALT_INV_Rdata1[3]$latch~combout\ : std_logic;
SIGNAL \ALT_INV_Rdata1[2]$latch~combout\ : std_logic;
SIGNAL \ALT_INV_Rdata1[1]$latch~combout\ : std_logic;
SIGNAL \ALT_INV_Rdata1[0]$latch~combout\ : std_logic;
SIGNAL \ALT_INV_R3[7]~8_combout\ : std_logic;
SIGNAL \ALT_INV_R2[7]~8_combout\ : std_logic;
SIGNAL \ALT_INV_R1[7]~8_combout\ : std_logic;
SIGNAL \ALT_INV_R0[7]~8_combout\ : std_logic;
SIGNAL \ALT_INV_R3[6]~7_combout\ : std_logic;
SIGNAL \ALT_INV_R2[6]~7_combout\ : std_logic;
SIGNAL \ALT_INV_R1[6]~7_combout\ : std_logic;
SIGNAL \ALT_INV_R0[6]~7_combout\ : std_logic;
SIGNAL \ALT_INV_R3[5]~6_combout\ : std_logic;
SIGNAL \ALT_INV_R2[5]~6_combout\ : std_logic;
SIGNAL \ALT_INV_R1[5]~6_combout\ : std_logic;
SIGNAL \ALT_INV_R0[5]~6_combout\ : std_logic;
SIGNAL \ALT_INV_R3[4]~5_combout\ : std_logic;
SIGNAL \ALT_INV_R2[4]~5_combout\ : std_logic;
SIGNAL \ALT_INV_R1[4]~5_combout\ : std_logic;
SIGNAL \ALT_INV_R0[4]~5_combout\ : std_logic;
SIGNAL \ALT_INV_R3[3]~4_combout\ : std_logic;
SIGNAL \ALT_INV_R2[3]~4_combout\ : std_logic;
SIGNAL \ALT_INV_R1[3]~4_combout\ : std_logic;
SIGNAL \ALT_INV_R0[3]~4_combout\ : std_logic;
SIGNAL \ALT_INV_R3[2]~3_combout\ : std_logic;
SIGNAL \ALT_INV_R2[2]~3_combout\ : std_logic;
SIGNAL \ALT_INV_R1[2]~3_combout\ : std_logic;
SIGNAL \ALT_INV_R0[2]~3_combout\ : std_logic;
SIGNAL \ALT_INV_R3[1]~2_combout\ : std_logic;
SIGNAL \ALT_INV_R2[1]~2_combout\ : std_logic;
SIGNAL \ALT_INV_R1[1]~2_combout\ : std_logic;
SIGNAL \ALT_INV_R0[1]~2_combout\ : std_logic;
SIGNAL \ALT_INV_R3[0]~1_combout\ : std_logic;
SIGNAL \ALT_INV_R3[0]~0_combout\ : std_logic;
SIGNAL \ALT_INV_R2[0]~1_combout\ : std_logic;
SIGNAL \ALT_INV_R2[0]~0_combout\ : std_logic;
SIGNAL \ALT_INV_R1[0]~1_combout\ : std_logic;
SIGNAL \ALT_INV_R1[0]~0_combout\ : std_logic;
SIGNAL \ALT_INV_R0[0]~1_combout\ : std_logic;
SIGNAL \ALT_INV_R0[0]~0_combout\ : std_logic;
SIGNAL \ALT_INV_Mux8~0_combout\ : std_logic;
SIGNAL \ALT_INV_Mux9~0_combout\ : std_logic;
SIGNAL \ALT_INV_Mux10~0_combout\ : std_logic;
SIGNAL \ALT_INV_Mux11~0_combout\ : std_logic;
SIGNAL \ALT_INV_Mux12~0_combout\ : std_logic;
SIGNAL \ALT_INV_Mux13~0_combout\ : std_logic;
SIGNAL \ALT_INV_Mux14~0_combout\ : std_logic;
SIGNAL \ALT_INV_Mux15~0_combout\ : std_logic;
SIGNAL \ALT_INV_Mux0~0_combout\ : std_logic;
SIGNAL \ALT_INV_Mux1~0_combout\ : std_logic;
SIGNAL \ALT_INV_Mux2~0_combout\ : std_logic;
SIGNAL \ALT_INV_Mux3~0_combout\ : std_logic;
SIGNAL \ALT_INV_Mux4~0_combout\ : std_logic;
SIGNAL \ALT_INV_Mux5~0_combout\ : std_logic;
SIGNAL \ALT_INV_Mux6~0_combout\ : std_logic;
SIGNAL \ALT_INV_Mux7~0_combout\ : std_logic;

BEGIN

ww_RegWrite <= RegWrite;
ww_load <= load;
ww_reset <= reset;
ww_regA <= regA;
ww_regB <= regB;
ww_writeR <= writeR;
ww_data <= data;
Rdata1 <= ww_Rdata1;
Rdata2 <= ww_Rdata2;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_data[7]~input_o\ <= NOT \data[7]~input_o\;
\ALT_INV_data[6]~input_o\ <= NOT \data[6]~input_o\;
\ALT_INV_data[5]~input_o\ <= NOT \data[5]~input_o\;
\ALT_INV_data[4]~input_o\ <= NOT \data[4]~input_o\;
\ALT_INV_data[3]~input_o\ <= NOT \data[3]~input_o\;
\ALT_INV_data[2]~input_o\ <= NOT \data[2]~input_o\;
\ALT_INV_data[1]~input_o\ <= NOT \data[1]~input_o\;
\ALT_INV_reset~input_o\ <= NOT \reset~input_o\;
\ALT_INV_load~input_o\ <= NOT \load~input_o\;
\ALT_INV_writeR[0]~input_o\ <= NOT \writeR[0]~input_o\;
\ALT_INV_writeR[1]~input_o\ <= NOT \writeR[1]~input_o\;
\ALT_INV_data[0]~input_o\ <= NOT \data[0]~input_o\;
\ALT_INV_regB[1]~input_o\ <= NOT \regB[1]~input_o\;
\ALT_INV_regB[0]~input_o\ <= NOT \regB[0]~input_o\;
\ALT_INV_RegWrite~input_o\ <= NOT \RegWrite~input_o\;
\ALT_INV_regA[1]~input_o\ <= NOT \regA[1]~input_o\;
\ALT_INV_regA[0]~input_o\ <= NOT \regA[0]~input_o\;
ALT_INV_R3(7) <= NOT R3(7);
ALT_INV_R2(7) <= NOT R2(7);
ALT_INV_R1(7) <= NOT R1(7);
ALT_INV_R0(7) <= NOT R0(7);
ALT_INV_R3(6) <= NOT R3(6);
ALT_INV_R2(6) <= NOT R2(6);
ALT_INV_R1(6) <= NOT R1(6);
ALT_INV_R0(6) <= NOT R0(6);
ALT_INV_R3(5) <= NOT R3(5);
ALT_INV_R2(5) <= NOT R2(5);
ALT_INV_R1(5) <= NOT R1(5);
ALT_INV_R0(5) <= NOT R0(5);
ALT_INV_R3(4) <= NOT R3(4);
ALT_INV_R2(4) <= NOT R2(4);
ALT_INV_R1(4) <= NOT R1(4);
ALT_INV_R0(4) <= NOT R0(4);
ALT_INV_R3(3) <= NOT R3(3);
ALT_INV_R2(3) <= NOT R2(3);
ALT_INV_R1(3) <= NOT R1(3);
ALT_INV_R0(3) <= NOT R0(3);
ALT_INV_R3(2) <= NOT R3(2);
ALT_INV_R2(2) <= NOT R2(2);
ALT_INV_R1(2) <= NOT R1(2);
ALT_INV_R0(2) <= NOT R0(2);
ALT_INV_R3(1) <= NOT R3(1);
ALT_INV_R2(1) <= NOT R2(1);
ALT_INV_R1(1) <= NOT R1(1);
ALT_INV_R0(1) <= NOT R0(1);
ALT_INV_R3(0) <= NOT R3(0);
ALT_INV_R2(0) <= NOT R2(0);
ALT_INV_R1(0) <= NOT R1(0);
ALT_INV_R0(0) <= NOT R0(0);
\ALT_INV_Rdata2[7]$latch~combout\ <= NOT \Rdata2[7]$latch~combout\;
\ALT_INV_Rdata2[6]$latch~combout\ <= NOT \Rdata2[6]$latch~combout\;
\ALT_INV_Rdata2[5]$latch~combout\ <= NOT \Rdata2[5]$latch~combout\;
\ALT_INV_Rdata2[4]$latch~combout\ <= NOT \Rdata2[4]$latch~combout\;
\ALT_INV_Rdata2[3]$latch~combout\ <= NOT \Rdata2[3]$latch~combout\;
\ALT_INV_Rdata2[2]$latch~combout\ <= NOT \Rdata2[2]$latch~combout\;
\ALT_INV_Rdata2[1]$latch~combout\ <= NOT \Rdata2[1]$latch~combout\;
\ALT_INV_Rdata2[0]$latch~combout\ <= NOT \Rdata2[0]$latch~combout\;
\ALT_INV_Rdata1[7]$latch~combout\ <= NOT \Rdata1[7]$latch~combout\;
\ALT_INV_Rdata1[6]$latch~combout\ <= NOT \Rdata1[6]$latch~combout\;
\ALT_INV_Rdata1[5]$latch~combout\ <= NOT \Rdata1[5]$latch~combout\;
\ALT_INV_Rdata1[4]$latch~combout\ <= NOT \Rdata1[4]$latch~combout\;
\ALT_INV_Rdata1[3]$latch~combout\ <= NOT \Rdata1[3]$latch~combout\;
\ALT_INV_Rdata1[2]$latch~combout\ <= NOT \Rdata1[2]$latch~combout\;
\ALT_INV_Rdata1[1]$latch~combout\ <= NOT \Rdata1[1]$latch~combout\;
\ALT_INV_Rdata1[0]$latch~combout\ <= NOT \Rdata1[0]$latch~combout\;
\ALT_INV_R3[7]~8_combout\ <= NOT \R3[7]~8_combout\;
\ALT_INV_R2[7]~8_combout\ <= NOT \R2[7]~8_combout\;
\ALT_INV_R1[7]~8_combout\ <= NOT \R1[7]~8_combout\;
\ALT_INV_R0[7]~8_combout\ <= NOT \R0[7]~8_combout\;
\ALT_INV_R3[6]~7_combout\ <= NOT \R3[6]~7_combout\;
\ALT_INV_R2[6]~7_combout\ <= NOT \R2[6]~7_combout\;
\ALT_INV_R1[6]~7_combout\ <= NOT \R1[6]~7_combout\;
\ALT_INV_R0[6]~7_combout\ <= NOT \R0[6]~7_combout\;
\ALT_INV_R3[5]~6_combout\ <= NOT \R3[5]~6_combout\;
\ALT_INV_R2[5]~6_combout\ <= NOT \R2[5]~6_combout\;
\ALT_INV_R1[5]~6_combout\ <= NOT \R1[5]~6_combout\;
\ALT_INV_R0[5]~6_combout\ <= NOT \R0[5]~6_combout\;
\ALT_INV_R3[4]~5_combout\ <= NOT \R3[4]~5_combout\;
\ALT_INV_R2[4]~5_combout\ <= NOT \R2[4]~5_combout\;
\ALT_INV_R1[4]~5_combout\ <= NOT \R1[4]~5_combout\;
\ALT_INV_R0[4]~5_combout\ <= NOT \R0[4]~5_combout\;
\ALT_INV_R3[3]~4_combout\ <= NOT \R3[3]~4_combout\;
\ALT_INV_R2[3]~4_combout\ <= NOT \R2[3]~4_combout\;
\ALT_INV_R1[3]~4_combout\ <= NOT \R1[3]~4_combout\;
\ALT_INV_R0[3]~4_combout\ <= NOT \R0[3]~4_combout\;
\ALT_INV_R3[2]~3_combout\ <= NOT \R3[2]~3_combout\;
\ALT_INV_R2[2]~3_combout\ <= NOT \R2[2]~3_combout\;
\ALT_INV_R1[2]~3_combout\ <= NOT \R1[2]~3_combout\;
\ALT_INV_R0[2]~3_combout\ <= NOT \R0[2]~3_combout\;
\ALT_INV_R3[1]~2_combout\ <= NOT \R3[1]~2_combout\;
\ALT_INV_R2[1]~2_combout\ <= NOT \R2[1]~2_combout\;
\ALT_INV_R1[1]~2_combout\ <= NOT \R1[1]~2_combout\;
\ALT_INV_R0[1]~2_combout\ <= NOT \R0[1]~2_combout\;
\ALT_INV_R3[0]~1_combout\ <= NOT \R3[0]~1_combout\;
\ALT_INV_R3[0]~0_combout\ <= NOT \R3[0]~0_combout\;
\ALT_INV_R2[0]~1_combout\ <= NOT \R2[0]~1_combout\;
\ALT_INV_R2[0]~0_combout\ <= NOT \R2[0]~0_combout\;
\ALT_INV_R1[0]~1_combout\ <= NOT \R1[0]~1_combout\;
\ALT_INV_R1[0]~0_combout\ <= NOT \R1[0]~0_combout\;
\ALT_INV_R0[0]~1_combout\ <= NOT \R0[0]~1_combout\;
\ALT_INV_R0[0]~0_combout\ <= NOT \R0[0]~0_combout\;
\ALT_INV_Mux8~0_combout\ <= NOT \Mux8~0_combout\;
\ALT_INV_Mux9~0_combout\ <= NOT \Mux9~0_combout\;
\ALT_INV_Mux10~0_combout\ <= NOT \Mux10~0_combout\;
\ALT_INV_Mux11~0_combout\ <= NOT \Mux11~0_combout\;
\ALT_INV_Mux12~0_combout\ <= NOT \Mux12~0_combout\;
\ALT_INV_Mux13~0_combout\ <= NOT \Mux13~0_combout\;
\ALT_INV_Mux14~0_combout\ <= NOT \Mux14~0_combout\;
\ALT_INV_Mux15~0_combout\ <= NOT \Mux15~0_combout\;
\ALT_INV_Mux0~0_combout\ <= NOT \Mux0~0_combout\;
\ALT_INV_Mux1~0_combout\ <= NOT \Mux1~0_combout\;
\ALT_INV_Mux2~0_combout\ <= NOT \Mux2~0_combout\;
\ALT_INV_Mux3~0_combout\ <= NOT \Mux3~0_combout\;
\ALT_INV_Mux4~0_combout\ <= NOT \Mux4~0_combout\;
\ALT_INV_Mux5~0_combout\ <= NOT \Mux5~0_combout\;
\ALT_INV_Mux6~0_combout\ <= NOT \Mux6~0_combout\;
\ALT_INV_Mux7~0_combout\ <= NOT \Mux7~0_combout\;

-- Location: IOOBUF_X54_Y0_N2
\Rdata1[0]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Rdata1[0]$latch~combout\,
	devoe => ww_devoe,
	o => ww_Rdata1(0));

-- Location: IOOBUF_X54_Y0_N19
\Rdata1[1]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Rdata1[1]$latch~combout\,
	devoe => ww_devoe,
	o => ww_Rdata1(1));

-- Location: IOOBUF_X66_Y0_N59
\Rdata1[2]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Rdata1[2]$latch~combout\,
	devoe => ww_devoe,
	o => ww_Rdata1(2));

-- Location: IOOBUF_X54_Y0_N36
\Rdata1[3]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Rdata1[3]$latch~combout\,
	devoe => ww_devoe,
	o => ww_Rdata1(3));

-- Location: IOOBUF_X66_Y0_N93
\Rdata1[4]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Rdata1[4]$latch~combout\,
	devoe => ww_devoe,
	o => ww_Rdata1(4));

-- Location: IOOBUF_X64_Y0_N53
\Rdata1[5]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Rdata1[5]$latch~combout\,
	devoe => ww_devoe,
	o => ww_Rdata1(5));

-- Location: IOOBUF_X56_Y0_N53
\Rdata1[6]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Rdata1[6]$latch~combout\,
	devoe => ww_devoe,
	o => ww_Rdata1(6));

-- Location: IOOBUF_X68_Y0_N19
\Rdata1[7]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Rdata1[7]$latch~combout\,
	devoe => ww_devoe,
	o => ww_Rdata1(7));

-- Location: IOOBUF_X54_Y0_N53
\Rdata2[0]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Rdata2[0]$latch~combout\,
	devoe => ww_devoe,
	o => ww_Rdata2(0));

-- Location: IOOBUF_X66_Y0_N42
\Rdata2[1]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Rdata2[1]$latch~combout\,
	devoe => ww_devoe,
	o => ww_Rdata2(1));

-- Location: IOOBUF_X68_Y0_N36
\Rdata2[2]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Rdata2[2]$latch~combout\,
	devoe => ww_devoe,
	o => ww_Rdata2(2));

-- Location: IOOBUF_X52_Y0_N53
\Rdata2[3]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Rdata2[3]$latch~combout\,
	devoe => ww_devoe,
	o => ww_Rdata2(3));

-- Location: IOOBUF_X66_Y0_N76
\Rdata2[4]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Rdata2[4]$latch~combout\,
	devoe => ww_devoe,
	o => ww_Rdata2(4));

-- Location: IOOBUF_X64_Y0_N2
\Rdata2[5]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Rdata2[5]$latch~combout\,
	devoe => ww_devoe,
	o => ww_Rdata2(5));

-- Location: IOOBUF_X56_Y0_N36
\Rdata2[6]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Rdata2[6]$latch~combout\,
	devoe => ww_devoe,
	o => ww_Rdata2(6));

-- Location: IOOBUF_X68_Y0_N53
\Rdata2[7]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Rdata2[7]$latch~combout\,
	devoe => ww_devoe,
	o => ww_Rdata2(7));

-- Location: IOIBUF_X60_Y0_N35
\RegWrite~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_RegWrite,
	o => \RegWrite~input_o\);

-- Location: IOIBUF_X60_Y0_N52
\writeR[0]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_writeR(0),
	o => \writeR[0]~input_o\);

-- Location: IOIBUF_X58_Y0_N75
\writeR[1]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_writeR(1),
	o => \writeR[1]~input_o\);

-- Location: IOIBUF_X58_Y0_N58
\reset~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reset,
	o => \reset~input_o\);

-- Location: IOIBUF_X56_Y0_N1
\load~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_load,
	o => \load~input_o\);

-- Location: LABCELL_X60_Y2_N33
\R0[0]~1\ : cyclonev_lcell_comb
-- Equation(s):
-- \R0[0]~1_combout\ = ( \RegWrite~input_o\ & ( (((!\writeR[0]~input_o\ & !\writeR[1]~input_o\)) # (\load~input_o\)) # (\reset~input_o\) ) ) # ( !\RegWrite~input_o\ & ( (\load~input_o\) # (\reset~input_o\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111111111111000011111111111110001111111111111000111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datab => \ALT_INV_writeR[1]~input_o\,
	datac => \ALT_INV_reset~input_o\,
	datad => \ALT_INV_load~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R0[0]~1_combout\);

-- Location: IOIBUF_X58_Y0_N92
\data[0]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_data(0),
	o => \data[0]~input_o\);

-- Location: MLABCELL_X59_Y3_N51
\R0[0]~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \R0[0]~0_combout\ = ( \RegWrite~input_o\ & ( (!\writeR[0]~input_o\ & (!\writeR[1]~input_o\ & \data[0]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000001000000010000000100000001000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datab => \ALT_INV_writeR[1]~input_o\,
	datac => \ALT_INV_data[0]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R0[0]~0_combout\);

-- Location: LABCELL_X60_Y3_N21
\R0[0]\ : cyclonev_lcell_comb
-- Equation(s):
-- R0(0) = ( \R0[0]~0_combout\ & ( (R0(0)) # (\R0[0]~1_combout\) ) ) # ( !\R0[0]~0_combout\ & ( (!\R0[0]~1_combout\ & R0(0)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000011110000000000001111000000001111111111110000111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_R0[0]~1_combout\,
	datad => ALT_INV_R0(0),
	dataf => \ALT_INV_R0[0]~0_combout\,
	combout => R0(0));

-- Location: LABCELL_X60_Y3_N9
\R1[0]~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \R1[0]~0_combout\ = ( \RegWrite~input_o\ & ( (!\writeR[1]~input_o\ & ((!\writeR[0]~input_o\ & (\load~input_o\)) # (\writeR[0]~input_o\ & ((\data[0]~input_o\))))) # (\writeR[1]~input_o\ & (\load~input_o\)) ) ) # ( !\RegWrite~input_o\ & ( \load~input_o\ ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101010101010101010101010101000111010101010100011101",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_load~input_o\,
	datab => \ALT_INV_writeR[1]~input_o\,
	datac => \ALT_INV_data[0]~input_o\,
	datad => \ALT_INV_writeR[0]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R1[0]~0_combout\);

-- Location: MLABCELL_X59_Y3_N3
\R1[0]~1\ : cyclonev_lcell_comb
-- Equation(s):
-- \R1[0]~1_combout\ = ( \RegWrite~input_o\ & ( (((\writeR[0]~input_o\ & !\writeR[1]~input_o\)) # (\load~input_o\)) # (\reset~input_o\) ) ) # ( !\RegWrite~input_o\ & ( (\load~input_o\) # (\reset~input_o\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0011001111111111001100111111111101110011111111110111001111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datab => \ALT_INV_reset~input_o\,
	datac => \ALT_INV_writeR[1]~input_o\,
	datad => \ALT_INV_load~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R1[0]~1_combout\);

-- Location: LABCELL_X60_Y3_N18
\R1[0]\ : cyclonev_lcell_comb
-- Equation(s):
-- R1(0) = ( \R1[0]~1_combout\ & ( \R1[0]~0_combout\ ) ) # ( !\R1[0]~1_combout\ & ( R1(0) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101010101010101010100110011001100110011001100110011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R1(0),
	datab => \ALT_INV_R1[0]~0_combout\,
	dataf => \ALT_INV_R1[0]~1_combout\,
	combout => R1(0));

-- Location: LABCELL_X60_Y2_N30
\R3[0]~1\ : cyclonev_lcell_comb
-- Equation(s):
-- \R3[0]~1_combout\ = ( \RegWrite~input_o\ & ( (((\writeR[0]~input_o\ & \writeR[1]~input_o\)) # (\reset~input_o\)) # (\load~input_o\) ) ) # ( !\RegWrite~input_o\ & ( (\reset~input_o\) # (\load~input_o\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111111111111000011111111111100011111111111110001111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datab => \ALT_INV_writeR[1]~input_o\,
	datac => \ALT_INV_load~input_o\,
	datad => \ALT_INV_reset~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R3[0]~1_combout\);

-- Location: MLABCELL_X59_Y3_N30
\R3[0]~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \R3[0]~0_combout\ = ( \RegWrite~input_o\ & ( (!\writeR[0]~input_o\ & (\load~input_o\)) # (\writeR[0]~input_o\ & ((!\writeR[1]~input_o\ & (\load~input_o\)) # (\writeR[1]~input_o\ & ((\data[0]~input_o\))))) ) ) # ( !\RegWrite~input_o\ & ( \load~input_o\ ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101010101010101010101010101010100110101010101010011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_load~input_o\,
	datab => \ALT_INV_data[0]~input_o\,
	datac => \ALT_INV_writeR[0]~input_o\,
	datad => \ALT_INV_writeR[1]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R3[0]~0_combout\);

-- Location: LABCELL_X60_Y3_N30
\R3[0]\ : cyclonev_lcell_comb
-- Equation(s):
-- R3(0) = ( \R3[0]~0_combout\ & ( (\R3[0]~1_combout\) # (R3(0)) ) ) # ( !\R3[0]~0_combout\ & ( (R3(0) & !\R3[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0011001100000000001100110000000000110011111111110011001111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => ALT_INV_R3(0),
	datad => \ALT_INV_R3[0]~1_combout\,
	dataf => \ALT_INV_R3[0]~0_combout\,
	combout => R3(0));

-- Location: LABCELL_X60_Y2_N36
\R2[0]~1\ : cyclonev_lcell_comb
-- Equation(s):
-- \R2[0]~1_combout\ = ( \RegWrite~input_o\ & ( (((!\writeR[0]~input_o\ & \writeR[1]~input_o\)) # (\reset~input_o\)) # (\load~input_o\) ) ) # ( !\RegWrite~input_o\ & ( (\reset~input_o\) # (\load~input_o\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111111111111000011111111111100101111111111110010111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datab => \ALT_INV_writeR[1]~input_o\,
	datac => \ALT_INV_load~input_o\,
	datad => \ALT_INV_reset~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R2[0]~1_combout\);

-- Location: MLABCELL_X59_Y3_N15
\R2[0]~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \R2[0]~0_combout\ = ( \RegWrite~input_o\ & ( (!\writeR[0]~input_o\ & (\writeR[1]~input_o\ & \data[0]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000010000000100000001000000010",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datab => \ALT_INV_writeR[1]~input_o\,
	datac => \ALT_INV_data[0]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R2[0]~0_combout\);

-- Location: LABCELL_X60_Y3_N39
\R2[0]\ : cyclonev_lcell_comb
-- Equation(s):
-- R2(0) = ( \R2[0]~0_combout\ & ( (\R2[0]~1_combout\) # (R2(0)) ) ) # ( !\R2[0]~0_combout\ & ( (R2(0) & !\R2[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111100000000000011110000000000001111111111110000111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => ALT_INV_R2(0),
	datad => \ALT_INV_R2[0]~1_combout\,
	dataf => \ALT_INV_R2[0]~0_combout\,
	combout => R2(0));

-- Location: IOIBUF_X58_Y0_N41
\regA[0]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_regA(0),
	o => \regA[0]~input_o\);

-- Location: IOIBUF_X62_Y0_N52
\regA[1]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_regA(1),
	o => \regA[1]~input_o\);

-- Location: LABCELL_X60_Y3_N24
\Mux7~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Mux7~0_combout\ = ( \regA[0]~input_o\ & ( \regA[1]~input_o\ & ( R3(0) ) ) ) # ( !\regA[0]~input_o\ & ( \regA[1]~input_o\ & ( R2(0) ) ) ) # ( \regA[0]~input_o\ & ( !\regA[1]~input_o\ & ( R1(0) ) ) ) # ( !\regA[0]~input_o\ & ( !\regA[1]~input_o\ & ( R0(0) 
-- ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101001100110011001100000000111111110000111100001111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R0(0),
	datab => ALT_INV_R1(0),
	datac => ALT_INV_R3(0),
	datad => ALT_INV_R2(0),
	datae => \ALT_INV_regA[0]~input_o\,
	dataf => \ALT_INV_regA[1]~input_o\,
	combout => \Mux7~0_combout\);

-- Location: LABCELL_X60_Y3_N36
\Rdata1[0]$latch\ : cyclonev_lcell_comb
-- Equation(s):
-- \Rdata1[0]$latch~combout\ = ( \Mux7~0_combout\ & ( (!\RegWrite~input_o\) # (\Rdata1[0]$latch~combout\) ) ) # ( !\Mux7~0_combout\ & ( (\RegWrite~input_o\ & \Rdata1[0]$latch~combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000001111000000000000111111110000111111111111000011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_RegWrite~input_o\,
	datad => \ALT_INV_Rdata1[0]$latch~combout\,
	dataf => \ALT_INV_Mux7~0_combout\,
	combout => \Rdata1[0]$latch~combout\);

-- Location: IOIBUF_X56_Y0_N18
\data[1]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_data(1),
	o => \data[1]~input_o\);

-- Location: MLABCELL_X59_Y3_N12
\R0[1]~2\ : cyclonev_lcell_comb
-- Equation(s):
-- \R0[1]~2_combout\ = ( \RegWrite~input_o\ & ( (!\writeR[0]~input_o\ & (!\writeR[1]~input_o\ & \data[1]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000100010000000000010001000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datab => \ALT_INV_writeR[1]~input_o\,
	datad => \ALT_INV_data[1]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R0[1]~2_combout\);

-- Location: LABCELL_X60_Y3_N57
\R0[1]\ : cyclonev_lcell_comb
-- Equation(s):
-- R0(1) = ( \R0[1]~2_combout\ & ( (R0(1)) # (\R0[0]~1_combout\) ) ) # ( !\R0[1]~2_combout\ & ( (!\R0[0]~1_combout\ & R0(1)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000011110000000000001111000000001111111111110000111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_R0[0]~1_combout\,
	datad => ALT_INV_R0(1),
	dataf => \ALT_INV_R0[1]~2_combout\,
	combout => R0(1));

-- Location: MLABCELL_X59_Y3_N57
\R1[1]~2\ : cyclonev_lcell_comb
-- Equation(s):
-- \R1[1]~2_combout\ = ( \RegWrite~input_o\ & ( (\writeR[0]~input_o\ & (!\writeR[1]~input_o\ & \data[1]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000100000001000000010000000100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datab => \ALT_INV_writeR[1]~input_o\,
	datac => \ALT_INV_data[1]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R1[1]~2_combout\);

-- Location: MLABCELL_X59_Y3_N45
\R1[1]\ : cyclonev_lcell_comb
-- Equation(s):
-- R1(1) = ( \R1[1]~2_combout\ & ( (\R1[0]~1_combout\) # (R1(1)) ) ) # ( !\R1[1]~2_combout\ & ( (R1(1) & !\R1[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111100000000000011110000000000001111111111110000111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => ALT_INV_R1(1),
	datad => \ALT_INV_R1[0]~1_combout\,
	dataf => \ALT_INV_R1[1]~2_combout\,
	combout => R1(1));

-- Location: LABCELL_X60_Y3_N3
\R3[1]~2\ : cyclonev_lcell_comb
-- Equation(s):
-- \R3[1]~2_combout\ = ( \RegWrite~input_o\ & ( (!\writeR[0]~input_o\ & (((\load~input_o\)))) # (\writeR[0]~input_o\ & ((!\writeR[1]~input_o\ & ((\load~input_o\))) # (\writeR[1]~input_o\ & (\data[1]~input_o\)))) ) ) # ( !\RegWrite~input_o\ & ( \load~input_o\ 
-- ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000011111111000000001111111100000001111110110000000111111011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datab => \ALT_INV_data[1]~input_o\,
	datac => \ALT_INV_writeR[1]~input_o\,
	datad => \ALT_INV_load~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R3[1]~2_combout\);

-- Location: LABCELL_X60_Y3_N0
\R3[1]\ : cyclonev_lcell_comb
-- Equation(s):
-- R3(1) = ( \R3[1]~2_combout\ & ( (\R3[0]~1_combout\) # (R3(1)) ) ) # ( !\R3[1]~2_combout\ & ( (R3(1) & !\R3[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111100000000000011110000000000001111111111110000111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => ALT_INV_R3(1),
	datad => \ALT_INV_R3[0]~1_combout\,
	dataf => \ALT_INV_R3[1]~2_combout\,
	combout => R3(1));

-- Location: MLABCELL_X59_Y3_N42
\R2[1]~2\ : cyclonev_lcell_comb
-- Equation(s):
-- \R2[1]~2_combout\ = ( \RegWrite~input_o\ & ( (!\writeR[1]~input_o\ & (\load~input_o\)) # (\writeR[1]~input_o\ & ((!\writeR[0]~input_o\ & ((\data[1]~input_o\))) # (\writeR[0]~input_o\ & (\load~input_o\)))) ) ) # ( !\RegWrite~input_o\ & ( \load~input_o\ ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101010101010101010101000101011101010100010101110101",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_load~input_o\,
	datab => \ALT_INV_writeR[1]~input_o\,
	datac => \ALT_INV_writeR[0]~input_o\,
	datad => \ALT_INV_data[1]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R2[1]~2_combout\);

-- Location: LABCELL_X60_Y3_N42
\R2[1]\ : cyclonev_lcell_comb
-- Equation(s):
-- R2(1) = ( \R2[1]~2_combout\ & ( (R2(1)) # (\R2[0]~1_combout\) ) ) # ( !\R2[1]~2_combout\ & ( (!\R2[0]~1_combout\ & R2(1)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000011110000000000001111000000001111111111110000111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_R2[0]~1_combout\,
	datad => ALT_INV_R2(1),
	dataf => \ALT_INV_R2[1]~2_combout\,
	combout => R2(1));

-- Location: LABCELL_X60_Y3_N12
\Mux6~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Mux6~0_combout\ = ( \regA[0]~input_o\ & ( \regA[1]~input_o\ & ( R3(1) ) ) ) # ( !\regA[0]~input_o\ & ( \regA[1]~input_o\ & ( R2(1) ) ) ) # ( \regA[0]~input_o\ & ( !\regA[1]~input_o\ & ( R1(1) ) ) ) # ( !\regA[0]~input_o\ & ( !\regA[1]~input_o\ & ( R0(1) 
-- ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101001100110011001100000000111111110000111100001111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R0(1),
	datab => ALT_INV_R1(1),
	datac => ALT_INV_R3(1),
	datad => ALT_INV_R2(1),
	datae => \ALT_INV_regA[0]~input_o\,
	dataf => \ALT_INV_regA[1]~input_o\,
	combout => \Mux6~0_combout\);

-- Location: LABCELL_X60_Y3_N6
\Rdata1[1]$latch\ : cyclonev_lcell_comb
-- Equation(s):
-- \Rdata1[1]$latch~combout\ = ( \Mux6~0_combout\ & ( (!\RegWrite~input_o\) # (\Rdata1[1]$latch~combout\) ) ) # ( !\Mux6~0_combout\ & ( (\Rdata1[1]$latch~combout\ & \RegWrite~input_o\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000001111000000000000111111111111000011111111111100001111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_Rdata1[1]$latch~combout\,
	datad => \ALT_INV_RegWrite~input_o\,
	dataf => \ALT_INV_Mux6~0_combout\,
	combout => \Rdata1[1]$latch~combout\);

-- Location: IOIBUF_X62_Y0_N35
\data[2]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_data(2),
	o => \data[2]~input_o\);

-- Location: LABCELL_X60_Y3_N45
\R3[2]~3\ : cyclonev_lcell_comb
-- Equation(s):
-- \R3[2]~3_combout\ = ( \RegWrite~input_o\ & ( (\writeR[0]~input_o\ & (\writeR[1]~input_o\ & \data[2]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000100010000000000010001",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datab => \ALT_INV_writeR[1]~input_o\,
	datad => \ALT_INV_data[2]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R3[2]~3_combout\);

-- Location: LABCELL_X61_Y3_N3
\R3[2]\ : cyclonev_lcell_comb
-- Equation(s):
-- R3(2) = ( \R3[2]~3_combout\ & ( (\R3[0]~1_combout\) # (R3(2)) ) ) # ( !\R3[2]~3_combout\ & ( (R3(2) & !\R3[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010100000000010101010000000001010101111111110101010111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R3(2),
	datad => \ALT_INV_R3[0]~1_combout\,
	dataf => \ALT_INV_R3[2]~3_combout\,
	combout => R3(2));

-- Location: LABCELL_X60_Y3_N54
\R0[2]~3\ : cyclonev_lcell_comb
-- Equation(s):
-- \R0[2]~3_combout\ = ( \RegWrite~input_o\ & ( (\data[2]~input_o\ & (!\writeR[0]~input_o\ & !\writeR[1]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000001010000000000000101000000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_data[2]~input_o\,
	datac => \ALT_INV_writeR[0]~input_o\,
	datad => \ALT_INV_writeR[1]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R0[2]~3_combout\);

-- Location: LABCELL_X61_Y3_N27
\R0[2]\ : cyclonev_lcell_comb
-- Equation(s):
-- R0(2) = ( \R0[0]~1_combout\ & ( \R0[2]~3_combout\ ) ) # ( !\R0[0]~1_combout\ & ( R0(2) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000011111111000000001111111100110011001100110011001100110011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_R0[2]~3_combout\,
	datad => ALT_INV_R0(2),
	dataf => \ALT_INV_R0[0]~1_combout\,
	combout => R0(2));

-- Location: LABCELL_X61_Y3_N24
\R2[2]~3\ : cyclonev_lcell_comb
-- Equation(s):
-- \R2[2]~3_combout\ = ( \RegWrite~input_o\ & ( (!\writeR[0]~input_o\ & (\data[2]~input_o\ & \writeR[1]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000010100000000000001010",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datac => \ALT_INV_data[2]~input_o\,
	datad => \ALT_INV_writeR[1]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R2[2]~3_combout\);

-- Location: LABCELL_X61_Y3_N45
\R2[2]\ : cyclonev_lcell_comb
-- Equation(s):
-- R2(2) = ( \R2[0]~1_combout\ & ( \R2[2]~3_combout\ ) ) # ( !\R2[0]~1_combout\ & ( R2(2) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000011111111000000001111111100001111000011110000111100001111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_R2[2]~3_combout\,
	datad => ALT_INV_R2(2),
	dataf => \ALT_INV_R2[0]~1_combout\,
	combout => R2(2));

-- Location: LABCELL_X61_Y3_N57
\R1[2]~3\ : cyclonev_lcell_comb
-- Equation(s):
-- \R1[2]~3_combout\ = ( \RegWrite~input_o\ & ( (\writeR[0]~input_o\ & (!\writeR[1]~input_o\ & \data[2]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000010100000000000001010000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datac => \ALT_INV_writeR[1]~input_o\,
	datad => \ALT_INV_data[2]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R1[2]~3_combout\);

-- Location: LABCELL_X61_Y3_N30
\R1[2]\ : cyclonev_lcell_comb
-- Equation(s):
-- R1(2) = (!\R1[0]~1_combout\ & (R1(2))) # (\R1[0]~1_combout\ & ((\R1[2]~3_combout\)))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0011001100001111001100110000111100110011000011110011001100001111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => ALT_INV_R1(2),
	datac => \ALT_INV_R1[2]~3_combout\,
	datad => \ALT_INV_R1[0]~1_combout\,
	combout => R1(2));

-- Location: LABCELL_X61_Y3_N48
\Mux5~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Mux5~0_combout\ = ( \regA[0]~input_o\ & ( \regA[1]~input_o\ & ( R3(2) ) ) ) # ( !\regA[0]~input_o\ & ( \regA[1]~input_o\ & ( R2(2) ) ) ) # ( \regA[0]~input_o\ & ( !\regA[1]~input_o\ & ( R1(2) ) ) ) # ( !\regA[0]~input_o\ & ( !\regA[1]~input_o\ & ( R0(2) 
-- ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0011001100110011000000001111111100001111000011110101010101010101",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R3(2),
	datab => ALT_INV_R0(2),
	datac => ALT_INV_R2(2),
	datad => ALT_INV_R1(2),
	datae => \ALT_INV_regA[0]~input_o\,
	dataf => \ALT_INV_regA[1]~input_o\,
	combout => \Mux5~0_combout\);

-- Location: LABCELL_X61_Y3_N42
\Rdata1[2]$latch\ : cyclonev_lcell_comb
-- Equation(s):
-- \Rdata1[2]$latch~combout\ = ( \Mux5~0_combout\ & ( (!\RegWrite~input_o\) # (\Rdata1[2]$latch~combout\) ) ) # ( !\Mux5~0_combout\ & ( (\Rdata1[2]$latch~combout\ & \RegWrite~input_o\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000001100000011000000110000001111110011111100111111001111110011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_Rdata1[2]$latch~combout\,
	datac => \ALT_INV_RegWrite~input_o\,
	dataf => \ALT_INV_Mux5~0_combout\,
	combout => \Rdata1[2]$latch~combout\);

-- Location: IOIBUF_X52_Y0_N18
\data[3]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_data(3),
	o => \data[3]~input_o\);

-- Location: MLABCELL_X59_Y3_N6
\R1[3]~4\ : cyclonev_lcell_comb
-- Equation(s):
-- \R1[3]~4_combout\ = ( \RegWrite~input_o\ & ( (!\writeR[1]~input_o\ & (\writeR[0]~input_o\ & \data[3]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000011000000000000001100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_writeR[1]~input_o\,
	datac => \ALT_INV_writeR[0]~input_o\,
	datad => \ALT_INV_data[3]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R1[3]~4_combout\);

-- Location: MLABCELL_X59_Y3_N33
\R1[3]\ : cyclonev_lcell_comb
-- Equation(s):
-- R1(3) = ( \R1[3]~4_combout\ & ( (\R1[0]~1_combout\) # (R1(3)) ) ) # ( !\R1[3]~4_combout\ & ( (R1(3) & !\R1[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111100000000000011110000000000001111111111110000111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => ALT_INV_R1(3),
	datad => \ALT_INV_R1[0]~1_combout\,
	dataf => \ALT_INV_R1[3]~4_combout\,
	combout => R1(3));

-- Location: MLABCELL_X59_Y3_N54
\R3[3]~4\ : cyclonev_lcell_comb
-- Equation(s):
-- \R3[3]~4_combout\ = ( \RegWrite~input_o\ & ( (\writeR[0]~input_o\ & (\writeR[1]~input_o\ & \data[3]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000001000000010000000100000001",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datab => \ALT_INV_writeR[1]~input_o\,
	datac => \ALT_INV_data[3]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R3[3]~4_combout\);

-- Location: MLABCELL_X59_Y3_N27
\R3[3]\ : cyclonev_lcell_comb
-- Equation(s):
-- R3(3) = ( \R3[3]~4_combout\ & ( (\R3[0]~1_combout\) # (R3(3)) ) ) # ( !\R3[3]~4_combout\ & ( (R3(3) & !\R3[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010100000000010101010000000001010101111111110101010111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R3(3),
	datad => \ALT_INV_R3[0]~1_combout\,
	dataf => \ALT_INV_R3[3]~4_combout\,
	combout => R3(3));

-- Location: MLABCELL_X59_Y3_N24
\R2[3]~4\ : cyclonev_lcell_comb
-- Equation(s):
-- \R2[3]~4_combout\ = ( \RegWrite~input_o\ & ( (\data[3]~input_o\ & (!\writeR[0]~input_o\ & \writeR[1]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000001100000000000000110000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_data[3]~input_o\,
	datac => \ALT_INV_writeR[0]~input_o\,
	datad => \ALT_INV_writeR[1]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R2[3]~4_combout\);

-- Location: MLABCELL_X59_Y3_N39
\R2[3]\ : cyclonev_lcell_comb
-- Equation(s):
-- R2(3) = ( R2(3) & ( (!\R2[0]~1_combout\) # (\R2[3]~4_combout\) ) ) # ( !R2(3) & ( (\R2[3]~4_combout\ & \R2[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000001111000000000000111111111111000011111111111100001111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_R2[3]~4_combout\,
	datad => \ALT_INV_R2[0]~1_combout\,
	dataf => ALT_INV_R2(3),
	combout => R2(3));

-- Location: MLABCELL_X59_Y3_N48
\R0[3]~4\ : cyclonev_lcell_comb
-- Equation(s):
-- \R0[3]~4_combout\ = ( \RegWrite~input_o\ & ( (!\writeR[0]~input_o\ & (!\writeR[1]~input_o\ & \data[3]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000001000000010000000100000001000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datab => \ALT_INV_writeR[1]~input_o\,
	datac => \ALT_INV_data[3]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R0[3]~4_combout\);

-- Location: MLABCELL_X59_Y3_N0
\R0[3]\ : cyclonev_lcell_comb
-- Equation(s):
-- R0(3) = ( \R0[3]~4_combout\ & ( (\R0[0]~1_combout\) # (R0(3)) ) ) # ( !\R0[3]~4_combout\ & ( (R0(3) & !\R0[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111100000000000011110000000000001111111111110000111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => ALT_INV_R0(3),
	datad => \ALT_INV_R0[0]~1_combout\,
	dataf => \ALT_INV_R0[3]~4_combout\,
	combout => R0(3));

-- Location: MLABCELL_X59_Y3_N21
\Mux4~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Mux4~0_combout\ = ( \regA[0]~input_o\ & ( \regA[1]~input_o\ & ( R3(3) ) ) ) # ( !\regA[0]~input_o\ & ( \regA[1]~input_o\ & ( R2(3) ) ) ) # ( \regA[0]~input_o\ & ( !\regA[1]~input_o\ & ( R1(3) ) ) ) # ( !\regA[0]~input_o\ & ( !\regA[1]~input_o\ & ( R0(3) 
-- ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000011111111010101010101010100001111000011110011001100110011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R1(3),
	datab => ALT_INV_R3(3),
	datac => ALT_INV_R2(3),
	datad => ALT_INV_R0(3),
	datae => \ALT_INV_regA[0]~input_o\,
	dataf => \ALT_INV_regA[1]~input_o\,
	combout => \Mux4~0_combout\);

-- Location: MLABCELL_X59_Y3_N9
\Rdata1[3]$latch\ : cyclonev_lcell_comb
-- Equation(s):
-- \Rdata1[3]$latch~combout\ = ( \Mux4~0_combout\ & ( (!\RegWrite~input_o\) # (\Rdata1[3]$latch~combout\) ) ) # ( !\Mux4~0_combout\ & ( (\RegWrite~input_o\ & \Rdata1[3]$latch~combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000010100000101000001010000010110101111101011111010111110101111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_RegWrite~input_o\,
	datac => \ALT_INV_Rdata1[3]$latch~combout\,
	dataf => \ALT_INV_Mux4~0_combout\,
	combout => \Rdata1[3]$latch~combout\);

-- Location: IOIBUF_X64_Y0_N18
\data[4]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_data(4),
	o => \data[4]~input_o\);

-- Location: LABCELL_X61_Y2_N51
\R0[4]~5\ : cyclonev_lcell_comb
-- Equation(s):
-- \R0[4]~5_combout\ = ( \RegWrite~input_o\ & ( (\data[4]~input_o\ & (!\writeR[0]~input_o\ & !\writeR[1]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000001010000000000000101000000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_data[4]~input_o\,
	datac => \ALT_INV_writeR[0]~input_o\,
	datad => \ALT_INV_writeR[1]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R0[4]~5_combout\);

-- Location: LABCELL_X61_Y2_N0
\R0[4]\ : cyclonev_lcell_comb
-- Equation(s):
-- R0(4) = ( R0(4) & ( (!\R0[0]~1_combout\) # (\R0[4]~5_combout\) ) ) # ( !R0(4) & ( (\R0[4]~5_combout\ & \R0[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000001111000000000000111111111111000011111111111100001111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_R0[4]~5_combout\,
	datad => \ALT_INV_R0[0]~1_combout\,
	dataf => ALT_INV_R0(4),
	combout => R0(4));

-- Location: LABCELL_X61_Y2_N42
\R3[4]~5\ : cyclonev_lcell_comb
-- Equation(s):
-- \R3[4]~5_combout\ = ( \RegWrite~input_o\ & ( (\writeR[1]~input_o\ & (\writeR[0]~input_o\ & \data[4]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000000110000000000000011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_writeR[1]~input_o\,
	datac => \ALT_INV_writeR[0]~input_o\,
	datad => \ALT_INV_data[4]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R3[4]~5_combout\);

-- Location: LABCELL_X61_Y2_N33
\R3[4]\ : cyclonev_lcell_comb
-- Equation(s):
-- R3(4) = ( \R3[4]~5_combout\ & ( (R3(4)) # (\R3[0]~1_combout\) ) ) # ( !\R3[4]~5_combout\ & ( (!\R3[0]~1_combout\ & R3(4)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000010101010000000001010101001010101111111110101010111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_R3[0]~1_combout\,
	datad => ALT_INV_R3(4),
	dataf => \ALT_INV_R3[4]~5_combout\,
	combout => R3(4));

-- Location: LABCELL_X61_Y2_N3
\R2[4]~5\ : cyclonev_lcell_comb
-- Equation(s):
-- \R2[4]~5_combout\ = ( \RegWrite~input_o\ & ( (!\writeR[0]~input_o\ & (\writeR[1]~input_o\ & \data[4]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000010100000000000001010",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datac => \ALT_INV_writeR[1]~input_o\,
	datad => \ALT_INV_data[4]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R2[4]~5_combout\);

-- Location: LABCELL_X61_Y2_N12
\R2[4]\ : cyclonev_lcell_comb
-- Equation(s):
-- R2(4) = ( \R2[4]~5_combout\ & ( (\R2[0]~1_combout\) # (R2(4)) ) ) # ( !\R2[4]~5_combout\ & ( (R2(4) & !\R2[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0011000000110000001100000011000000111111001111110011111100111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => ALT_INV_R2(4),
	datac => \ALT_INV_R2[0]~1_combout\,
	dataf => \ALT_INV_R2[4]~5_combout\,
	combout => R2(4));

-- Location: LABCELL_X61_Y2_N48
\R1[4]~5\ : cyclonev_lcell_comb
-- Equation(s):
-- \R1[4]~5_combout\ = ( \RegWrite~input_o\ & ( (\data[4]~input_o\ & (\writeR[0]~input_o\ & !\writeR[1]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000010000000100000001000000010000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_data[4]~input_o\,
	datab => \ALT_INV_writeR[0]~input_o\,
	datac => \ALT_INV_writeR[1]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R1[4]~5_combout\);

-- Location: LABCELL_X61_Y2_N15
\R1[4]\ : cyclonev_lcell_comb
-- Equation(s):
-- R1(4) = ( \R1[4]~5_combout\ & ( (\R1[0]~1_combout\) # (R1(4)) ) ) # ( !\R1[4]~5_combout\ & ( (R1(4) & !\R1[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111100000000000011110000000000001111111111110000111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => ALT_INV_R1(4),
	datad => \ALT_INV_R1[0]~1_combout\,
	dataf => \ALT_INV_R1[4]~5_combout\,
	combout => R1(4));

-- Location: LABCELL_X61_Y2_N27
\Mux3~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Mux3~0_combout\ = ( \regA[0]~input_o\ & ( \regA[1]~input_o\ & ( R3(4) ) ) ) # ( !\regA[0]~input_o\ & ( \regA[1]~input_o\ & ( R2(4) ) ) ) # ( \regA[0]~input_o\ & ( !\regA[1]~input_o\ & ( R1(4) ) ) ) # ( !\regA[0]~input_o\ & ( !\regA[1]~input_o\ & ( R0(4) 
-- ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101000000001111111100001111000011110011001100110011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R0(4),
	datab => ALT_INV_R3(4),
	datac => ALT_INV_R2(4),
	datad => ALT_INV_R1(4),
	datae => \ALT_INV_regA[0]~input_o\,
	dataf => \ALT_INV_regA[1]~input_o\,
	combout => \Mux3~0_combout\);

-- Location: LABCELL_X61_Y2_N45
\Rdata1[4]$latch\ : cyclonev_lcell_comb
-- Equation(s):
-- \Rdata1[4]$latch~combout\ = ( \Mux3~0_combout\ & ( (!\RegWrite~input_o\) # (\Rdata1[4]$latch~combout\) ) ) # ( !\Mux3~0_combout\ & ( (\RegWrite~input_o\ & \Rdata1[4]$latch~combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010110101010111111111010101011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_RegWrite~input_o\,
	datad => \ALT_INV_Rdata1[4]$latch~combout\,
	dataf => \ALT_INV_Mux3~0_combout\,
	combout => \Rdata1[4]$latch~combout\);

-- Location: IOIBUF_X64_Y0_N35
\data[5]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_data(5),
	o => \data[5]~input_o\);

-- Location: LABCELL_X61_Y2_N6
\R3[5]~6\ : cyclonev_lcell_comb
-- Equation(s):
-- \R3[5]~6_combout\ = ( \RegWrite~input_o\ & ( (\writeR[1]~input_o\ & (\writeR[0]~input_o\ & \data[5]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000001010000000000000101",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[1]~input_o\,
	datac => \ALT_INV_writeR[0]~input_o\,
	datad => \ALT_INV_data[5]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R3[5]~6_combout\);

-- Location: LABCELL_X61_Y2_N9
\R3[5]\ : cyclonev_lcell_comb
-- Equation(s):
-- R3(5) = ( \R3[0]~1_combout\ & ( \R3[5]~6_combout\ ) ) # ( !\R3[0]~1_combout\ & ( R3(5) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111100001111000011110000111100110011001100110011001100110011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_R3[5]~6_combout\,
	datac => ALT_INV_R3(5),
	dataf => \ALT_INV_R3[0]~1_combout\,
	combout => R3(5));

-- Location: LABCELL_X60_Y2_N24
\R1[5]~6\ : cyclonev_lcell_comb
-- Equation(s):
-- \R1[5]~6_combout\ = ( \RegWrite~input_o\ & ( (\writeR[0]~input_o\ & (!\writeR[1]~input_o\ & \data[5]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000010001000000000001000100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datab => \ALT_INV_writeR[1]~input_o\,
	datad => \ALT_INV_data[5]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R1[5]~6_combout\);

-- Location: LABCELL_X61_Y2_N39
\R1[5]\ : cyclonev_lcell_comb
-- Equation(s):
-- R1(5) = ( \R1[5]~6_combout\ & ( (\R1[0]~1_combout\) # (R1(5)) ) ) # ( !\R1[5]~6_combout\ & ( (R1(5) & !\R1[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111100000000000011110000000000001111111111110000111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => ALT_INV_R1(5),
	datad => \ALT_INV_R1[0]~1_combout\,
	dataf => \ALT_INV_R1[5]~6_combout\,
	combout => R1(5));

-- Location: LABCELL_X60_Y2_N42
\R0[5]~6\ : cyclonev_lcell_comb
-- Equation(s):
-- \R0[5]~6_combout\ = ( \RegWrite~input_o\ & ( (\data[5]~input_o\ & (!\writeR[0]~input_o\ & !\writeR[1]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000110000000000000011000000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_data[5]~input_o\,
	datac => \ALT_INV_writeR[0]~input_o\,
	datad => \ALT_INV_writeR[1]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R0[5]~6_combout\);

-- Location: LABCELL_X60_Y2_N45
\R0[5]\ : cyclonev_lcell_comb
-- Equation(s):
-- R0(5) = ( \R0[5]~6_combout\ & ( (R0(5)) # (\R0[0]~1_combout\) ) ) # ( !\R0[5]~6_combout\ & ( (!\R0[0]~1_combout\ & R0(5)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000010101010000000001010101001010101111111110101010111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_R0[0]~1_combout\,
	datad => ALT_INV_R0(5),
	dataf => \ALT_INV_R0[5]~6_combout\,
	combout => R0(5));

-- Location: LABCELL_X60_Y2_N27
\R2[5]~6\ : cyclonev_lcell_comb
-- Equation(s):
-- \R2[5]~6_combout\ = ( \RegWrite~input_o\ & ( (!\writeR[0]~input_o\ & (\writeR[1]~input_o\ & \data[5]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000001000100000000000100010",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datab => \ALT_INV_writeR[1]~input_o\,
	datad => \ALT_INV_data[5]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R2[5]~6_combout\);

-- Location: LABCELL_X60_Y2_N12
\R2[5]\ : cyclonev_lcell_comb
-- Equation(s):
-- R2(5) = ( \R2[5]~6_combout\ & ( (\R2[0]~1_combout\) # (R2(5)) ) ) # ( !\R2[5]~6_combout\ & ( (R2(5) & !\R2[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0011001100000000001100110000000000110011111111110011001111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => ALT_INV_R2(5),
	datad => \ALT_INV_R2[0]~1_combout\,
	dataf => \ALT_INV_R2[5]~6_combout\,
	combout => R2(5));

-- Location: LABCELL_X61_Y2_N21
\Mux2~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Mux2~0_combout\ = ( \regA[0]~input_o\ & ( \regA[1]~input_o\ & ( R3(5) ) ) ) # ( !\regA[0]~input_o\ & ( \regA[1]~input_o\ & ( R2(5) ) ) ) # ( \regA[0]~input_o\ & ( !\regA[1]~input_o\ & ( R1(5) ) ) ) # ( !\regA[0]~input_o\ & ( !\regA[1]~input_o\ & ( R0(5) 
-- ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111100001111001100110011001100000000111111110101010101010101",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R3(5),
	datab => ALT_INV_R1(5),
	datac => ALT_INV_R0(5),
	datad => ALT_INV_R2(5),
	datae => \ALT_INV_regA[0]~input_o\,
	dataf => \ALT_INV_regA[1]~input_o\,
	combout => \Mux2~0_combout\);

-- Location: LABCELL_X61_Y2_N36
\Rdata1[5]$latch\ : cyclonev_lcell_comb
-- Equation(s):
-- \Rdata1[5]$latch~combout\ = ( \Mux2~0_combout\ & ( (!\RegWrite~input_o\) # (\Rdata1[5]$latch~combout\) ) ) # ( !\Mux2~0_combout\ & ( (\RegWrite~input_o\ & \Rdata1[5]$latch~combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000110011000000000011001111001100111111111100110011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_RegWrite~input_o\,
	datad => \ALT_INV_Rdata1[5]$latch~combout\,
	dataf => \ALT_INV_Mux2~0_combout\,
	combout => \Rdata1[5]$latch~combout\);

-- Location: IOIBUF_X62_Y0_N1
\data[6]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_data(6),
	o => \data[6]~input_o\);

-- Location: LABCELL_X60_Y2_N6
\R0[6]~7\ : cyclonev_lcell_comb
-- Equation(s):
-- \R0[6]~7_combout\ = ( \RegWrite~input_o\ & ( (\data[6]~input_o\ & (!\writeR[0]~input_o\ & !\writeR[1]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000110000000000000011000000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_data[6]~input_o\,
	datac => \ALT_INV_writeR[0]~input_o\,
	datad => \ALT_INV_writeR[1]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R0[6]~7_combout\);

-- Location: LABCELL_X60_Y2_N9
\R0[6]\ : cyclonev_lcell_comb
-- Equation(s):
-- R0(6) = ( \R0[6]~7_combout\ & ( (R0(6)) # (\R0[0]~1_combout\) ) ) # ( !\R0[6]~7_combout\ & ( (!\R0[0]~1_combout\ & R0(6)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000101000001010000010100000101001011111010111110101111101011111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_R0[0]~1_combout\,
	datac => ALT_INV_R0(6),
	dataf => \ALT_INV_R0[6]~7_combout\,
	combout => R0(6));

-- Location: LABCELL_X60_Y2_N15
\R2[6]~7\ : cyclonev_lcell_comb
-- Equation(s):
-- \R2[6]~7_combout\ = ( \RegWrite~input_o\ & ( (!\writeR[0]~input_o\ & (\data[6]~input_o\ & \writeR[1]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000010100000000000001010",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datac => \ALT_INV_data[6]~input_o\,
	datad => \ALT_INV_writeR[1]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R2[6]~7_combout\);

-- Location: LABCELL_X60_Y2_N3
\R2[6]\ : cyclonev_lcell_comb
-- Equation(s):
-- R2(6) = ( \R2[6]~7_combout\ & ( (R2(6)) # (\R2[0]~1_combout\) ) ) # ( !\R2[6]~7_combout\ & ( (!\R2[0]~1_combout\ & R2(6)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000011110000000000001111000000001111111111110000111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_R2[0]~1_combout\,
	datad => ALT_INV_R2(6),
	dataf => \ALT_INV_R2[6]~7_combout\,
	combout => R2(6));

-- Location: LABCELL_X60_Y2_N21
\R1[6]~7\ : cyclonev_lcell_comb
-- Equation(s):
-- \R1[6]~7_combout\ = ( \RegWrite~input_o\ & ( (\writeR[0]~input_o\ & (\data[6]~input_o\ & !\writeR[1]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000010000000100000001000000010000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datab => \ALT_INV_data[6]~input_o\,
	datac => \ALT_INV_writeR[1]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R1[6]~7_combout\);

-- Location: LABCELL_X60_Y2_N39
\R1[6]\ : cyclonev_lcell_comb
-- Equation(s):
-- R1(6) = ( \R1[6]~7_combout\ & ( (\R1[0]~1_combout\) # (R1(6)) ) ) # ( !\R1[6]~7_combout\ & ( (R1(6) & !\R1[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111100000000000011110000000000001111111111110000111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => ALT_INV_R1(6),
	datad => \ALT_INV_R1[0]~1_combout\,
	dataf => \ALT_INV_R1[6]~7_combout\,
	combout => R1(6));

-- Location: LABCELL_X60_Y2_N18
\R3[6]~7\ : cyclonev_lcell_comb
-- Equation(s):
-- \R3[6]~7_combout\ = ( \RegWrite~input_o\ & ( (\writeR[0]~input_o\ & (\data[6]~input_o\ & \writeR[1]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000100010000000000010001",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datab => \ALT_INV_data[6]~input_o\,
	datad => \ALT_INV_writeR[1]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R3[6]~7_combout\);

-- Location: LABCELL_X60_Y2_N51
\R3[6]\ : cyclonev_lcell_comb
-- Equation(s):
-- R3(6) = ( \R3[6]~7_combout\ & ( (\R3[0]~1_combout\) # (R3(6)) ) ) # ( !\R3[6]~7_combout\ & ( (R3(6) & !\R3[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101000001010000010100000101000001011111010111110101111101011111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R3(6),
	datac => \ALT_INV_R3[0]~1_combout\,
	dataf => \ALT_INV_R3[6]~7_combout\,
	combout => R3(6));

-- Location: LABCELL_X60_Y2_N54
\Mux1~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Mux1~0_combout\ = ( \regA[0]~input_o\ & ( \regA[1]~input_o\ & ( R3(6) ) ) ) # ( !\regA[0]~input_o\ & ( \regA[1]~input_o\ & ( R2(6) ) ) ) # ( \regA[0]~input_o\ & ( !\regA[1]~input_o\ & ( R1(6) ) ) ) # ( !\regA[0]~input_o\ & ( !\regA[1]~input_o\ & ( R0(6) 
-- ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101000011110000111100110011001100110000000011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R0(6),
	datab => ALT_INV_R2(6),
	datac => ALT_INV_R1(6),
	datad => ALT_INV_R3(6),
	datae => \ALT_INV_regA[0]~input_o\,
	dataf => \ALT_INV_regA[1]~input_o\,
	combout => \Mux1~0_combout\);

-- Location: LABCELL_X60_Y2_N0
\Rdata1[6]$latch\ : cyclonev_lcell_comb
-- Equation(s):
-- \Rdata1[6]$latch~combout\ = (!\RegWrite~input_o\ & (\Mux1~0_combout\)) # (\RegWrite~input_o\ & ((\Rdata1[6]$latch~combout\)))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000110000111111000011000011111100001100001111110000110000111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_RegWrite~input_o\,
	datac => \ALT_INV_Mux1~0_combout\,
	datad => \ALT_INV_Rdata1[6]$latch~combout\,
	combout => \Rdata1[6]$latch~combout\);

-- Location: IOIBUF_X62_Y0_N18
\data[7]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_data(7),
	o => \data[7]~input_o\);

-- Location: LABCELL_X60_Y3_N51
\R0[7]~8\ : cyclonev_lcell_comb
-- Equation(s):
-- \R0[7]~8_combout\ = ( \RegWrite~input_o\ & ( (!\writeR[0]~input_o\ & (\data[7]~input_o\ & !\writeR[1]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000001010000000000000101000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datac => \ALT_INV_data[7]~input_o\,
	datad => \ALT_INV_writeR[1]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R0[7]~8_combout\);

-- Location: LABCELL_X61_Y3_N9
\R0[7]\ : cyclonev_lcell_comb
-- Equation(s):
-- R0(7) = ( \R0[0]~1_combout\ & ( \R0[7]~8_combout\ ) ) # ( !\R0[0]~1_combout\ & ( R0(7) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111100001111000011110000111100110011001100110011001100110011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_R0[7]~8_combout\,
	datac => ALT_INV_R0(7),
	dataf => \ALT_INV_R0[0]~1_combout\,
	combout => R0(7));

-- Location: LABCELL_X61_Y2_N57
\R1[7]~8\ : cyclonev_lcell_comb
-- Equation(s):
-- \R1[7]~8_combout\ = ( \RegWrite~input_o\ & ( (\writeR[0]~input_o\ & (!\writeR[1]~input_o\ & \data[7]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000010100000000000001010000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_writeR[0]~input_o\,
	datac => \ALT_INV_writeR[1]~input_o\,
	datad => \ALT_INV_data[7]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R1[7]~8_combout\);

-- Location: LABCELL_X61_Y3_N15
\R1[7]\ : cyclonev_lcell_comb
-- Equation(s):
-- R1(7) = ( \R1[7]~8_combout\ & ( (\R1[0]~1_combout\) # (R1(7)) ) ) # ( !\R1[7]~8_combout\ & ( (R1(7) & !\R1[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111100000000000011110000000000001111111111110000111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => ALT_INV_R1(7),
	datad => \ALT_INV_R1[0]~1_combout\,
	dataf => \ALT_INV_R1[7]~8_combout\,
	combout => R1(7));

-- Location: LABCELL_X61_Y3_N12
\R3[7]~8\ : cyclonev_lcell_comb
-- Equation(s):
-- \R3[7]~8_combout\ = ( \RegWrite~input_o\ & ( (\writeR[0]~input_o\ & (\data[7]~input_o\ & \writeR[1]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000000110000000000000011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_writeR[0]~input_o\,
	datac => \ALT_INV_data[7]~input_o\,
	datad => \ALT_INV_writeR[1]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R3[7]~8_combout\);

-- Location: LABCELL_X61_Y3_N54
\R3[7]\ : cyclonev_lcell_comb
-- Equation(s):
-- R3(7) = ( \R3[7]~8_combout\ & ( (\R3[0]~1_combout\) # (R3(7)) ) ) # ( !\R3[7]~8_combout\ & ( (R3(7) & !\R3[0]~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111100000000000011110000000000001111111111110000111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => ALT_INV_R3(7),
	datad => \ALT_INV_R3[0]~1_combout\,
	dataf => \ALT_INV_R3[7]~8_combout\,
	combout => R3(7));

-- Location: LABCELL_X61_Y3_N6
\R2[7]~8\ : cyclonev_lcell_comb
-- Equation(s):
-- \R2[7]~8_combout\ = ( \RegWrite~input_o\ & ( (\data[7]~input_o\ & (!\writeR[0]~input_o\ & \writeR[1]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000010100000000000001010000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_data[7]~input_o\,
	datac => \ALT_INV_writeR[0]~input_o\,
	datad => \ALT_INV_writeR[1]~input_o\,
	dataf => \ALT_INV_RegWrite~input_o\,
	combout => \R2[7]~8_combout\);

-- Location: LABCELL_X61_Y3_N39
\R2[7]\ : cyclonev_lcell_comb
-- Equation(s):
-- R2(7) = ( \R2[7]~8_combout\ & ( (R2(7)) # (\R2[0]~1_combout\) ) ) # ( !\R2[7]~8_combout\ & ( (!\R2[0]~1_combout\ & R2(7)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000101000001010000010100000101001011111010111110101111101011111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_R2[0]~1_combout\,
	datac => ALT_INV_R2(7),
	dataf => \ALT_INV_R2[7]~8_combout\,
	combout => R2(7));

-- Location: LABCELL_X61_Y3_N18
\Mux0~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Mux0~0_combout\ = ( \regA[0]~input_o\ & ( \regA[1]~input_o\ & ( R3(7) ) ) ) # ( !\regA[0]~input_o\ & ( \regA[1]~input_o\ & ( R2(7) ) ) ) # ( \regA[0]~input_o\ & ( !\regA[1]~input_o\ & ( R1(7) ) ) ) # ( !\regA[0]~input_o\ & ( !\regA[1]~input_o\ & ( R0(7) 
-- ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101001100110011001100000000111111110000111100001111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R0(7),
	datab => ALT_INV_R1(7),
	datac => ALT_INV_R3(7),
	datad => ALT_INV_R2(7),
	datae => \ALT_INV_regA[0]~input_o\,
	dataf => \ALT_INV_regA[1]~input_o\,
	combout => \Mux0~0_combout\);

-- Location: LABCELL_X61_Y3_N36
\Rdata1[7]$latch\ : cyclonev_lcell_comb
-- Equation(s):
-- \Rdata1[7]$latch~combout\ = ( \Mux0~0_combout\ & ( (!\RegWrite~input_o\) # (\Rdata1[7]$latch~combout\) ) ) # ( !\Mux0~0_combout\ & ( (\RegWrite~input_o\ & \Rdata1[7]$latch~combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000001111000000000000111111110000111111111111000011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_RegWrite~input_o\,
	datad => \ALT_INV_Rdata1[7]$latch~combout\,
	dataf => \ALT_INV_Mux0~0_combout\,
	combout => \Rdata1[7]$latch~combout\);

-- Location: IOIBUF_X60_Y0_N18
\regB[0]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_regB(0),
	o => \regB[0]~input_o\);

-- Location: IOIBUF_X60_Y0_N1
\regB[1]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_regB(1),
	o => \regB[1]~input_o\);

-- Location: LABCELL_X60_Y3_N27
\Mux15~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Mux15~0_combout\ = ( \regB[0]~input_o\ & ( \regB[1]~input_o\ & ( R3(0) ) ) ) # ( !\regB[0]~input_o\ & ( \regB[1]~input_o\ & ( R2(0) ) ) ) # ( \regB[0]~input_o\ & ( !\regB[1]~input_o\ & ( R1(0) ) ) ) # ( !\regB[0]~input_o\ & ( !\regB[1]~input_o\ & ( R0(0) 
-- ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101001100110011001100001111000011110000000011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R0(0),
	datab => ALT_INV_R1(0),
	datac => ALT_INV_R2(0),
	datad => ALT_INV_R3(0),
	datae => \ALT_INV_regB[0]~input_o\,
	dataf => \ALT_INV_regB[1]~input_o\,
	combout => \Mux15~0_combout\);

-- Location: LABCELL_X60_Y3_N33
\Rdata2[0]$latch\ : cyclonev_lcell_comb
-- Equation(s):
-- \Rdata2[0]$latch~combout\ = ( \Mux15~0_combout\ & ( (!\RegWrite~input_o\) # (\Rdata2[0]$latch~combout\) ) ) # ( !\Mux15~0_combout\ & ( (\Rdata2[0]$latch~combout\ & \RegWrite~input_o\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010111111111010101011111111101010101",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Rdata2[0]$latch~combout\,
	datad => \ALT_INV_RegWrite~input_o\,
	dataf => \ALT_INV_Mux15~0_combout\,
	combout => \Rdata2[0]$latch~combout\);

-- Location: LABCELL_X60_Y3_N15
\Mux14~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Mux14~0_combout\ = ( \regB[0]~input_o\ & ( \regB[1]~input_o\ & ( R3(1) ) ) ) # ( !\regB[0]~input_o\ & ( \regB[1]~input_o\ & ( R2(1) ) ) ) # ( \regB[0]~input_o\ & ( !\regB[1]~input_o\ & ( R1(1) ) ) ) # ( !\regB[0]~input_o\ & ( !\regB[1]~input_o\ & ( R0(1) 
-- ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101001100110011001100001111000011110000000011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R0(1),
	datab => ALT_INV_R1(1),
	datac => ALT_INV_R2(1),
	datad => ALT_INV_R3(1),
	datae => \ALT_INV_regB[0]~input_o\,
	dataf => \ALT_INV_regB[1]~input_o\,
	combout => \Mux14~0_combout\);

-- Location: LABCELL_X60_Y3_N48
\Rdata2[1]$latch\ : cyclonev_lcell_comb
-- Equation(s):
-- \Rdata2[1]$latch~combout\ = (!\RegWrite~input_o\ & (\Mux14~0_combout\)) # (\RegWrite~input_o\ & ((\Rdata2[1]$latch~combout\)))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0011001100001111001100110000111100110011000011110011001100001111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_Mux14~0_combout\,
	datac => \ALT_INV_Rdata2[1]$latch~combout\,
	datad => \ALT_INV_RegWrite~input_o\,
	combout => \Rdata2[1]$latch~combout\);

-- Location: LABCELL_X61_Y3_N51
\Mux13~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Mux13~0_combout\ = ( \regB[0]~input_o\ & ( \regB[1]~input_o\ & ( R3(2) ) ) ) # ( !\regB[0]~input_o\ & ( \regB[1]~input_o\ & ( R2(2) ) ) ) # ( \regB[0]~input_o\ & ( !\regB[1]~input_o\ & ( R1(2) ) ) ) # ( !\regB[0]~input_o\ & ( !\regB[1]~input_o\ & ( R0(2) 
-- ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0011001100110011000011110000111100000000111111110101010101010101",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R3(2),
	datab => ALT_INV_R0(2),
	datac => ALT_INV_R1(2),
	datad => ALT_INV_R2(2),
	datae => \ALT_INV_regB[0]~input_o\,
	dataf => \ALT_INV_regB[1]~input_o\,
	combout => \Mux13~0_combout\);

-- Location: LABCELL_X61_Y3_N0
\Rdata2[2]$latch\ : cyclonev_lcell_comb
-- Equation(s):
-- \Rdata2[2]$latch~combout\ = ( \Mux13~0_combout\ & ( (!\RegWrite~input_o\) # (\Rdata2[2]$latch~combout\) ) ) # ( !\Mux13~0_combout\ & ( (\RegWrite~input_o\ & \Rdata2[2]$latch~combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000001111000000000000111111110000111111111111000011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_RegWrite~input_o\,
	datad => \ALT_INV_Rdata2[2]$latch~combout\,
	dataf => \ALT_INV_Mux13~0_combout\,
	combout => \Rdata2[2]$latch~combout\);

-- Location: MLABCELL_X59_Y3_N18
\Mux12~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Mux12~0_combout\ = ( \regB[0]~input_o\ & ( \regB[1]~input_o\ & ( R3(3) ) ) ) # ( !\regB[0]~input_o\ & ( \regB[1]~input_o\ & ( R2(3) ) ) ) # ( \regB[0]~input_o\ & ( !\regB[1]~input_o\ & ( R1(3) ) ) ) # ( !\regB[0]~input_o\ & ( !\regB[1]~input_o\ & ( R0(3) 
-- ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111100001111010101010101010100000000111111110011001100110011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R1(3),
	datab => ALT_INV_R3(3),
	datac => ALT_INV_R0(3),
	datad => ALT_INV_R2(3),
	datae => \ALT_INV_regB[0]~input_o\,
	dataf => \ALT_INV_regB[1]~input_o\,
	combout => \Mux12~0_combout\);

-- Location: MLABCELL_X59_Y3_N36
\Rdata2[3]$latch\ : cyclonev_lcell_comb
-- Equation(s):
-- \Rdata2[3]$latch~combout\ = ( \Mux12~0_combout\ & ( (!\RegWrite~input_o\) # (\Rdata2[3]$latch~combout\) ) ) # ( !\Mux12~0_combout\ & ( (\RegWrite~input_o\ & \Rdata2[3]$latch~combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000001111000000000000111111110000111111111111000011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_RegWrite~input_o\,
	datad => \ALT_INV_Rdata2[3]$latch~combout\,
	dataf => \ALT_INV_Mux12~0_combout\,
	combout => \Rdata2[3]$latch~combout\);

-- Location: LABCELL_X61_Y2_N24
\Mux11~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Mux11~0_combout\ = ( \regB[0]~input_o\ & ( \regB[1]~input_o\ & ( R3(4) ) ) ) # ( !\regB[0]~input_o\ & ( \regB[1]~input_o\ & ( R2(4) ) ) ) # ( \regB[0]~input_o\ & ( !\regB[1]~input_o\ & ( R1(4) ) ) ) # ( !\regB[0]~input_o\ & ( !\regB[1]~input_o\ & ( R0(4) 
-- ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101000011110000111100000000111111110011001100110011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R0(4),
	datab => ALT_INV_R3(4),
	datac => ALT_INV_R1(4),
	datad => ALT_INV_R2(4),
	datae => \ALT_INV_regB[0]~input_o\,
	dataf => \ALT_INV_regB[1]~input_o\,
	combout => \Mux11~0_combout\);

-- Location: LABCELL_X61_Y2_N30
\Rdata2[4]$latch\ : cyclonev_lcell_comb
-- Equation(s):
-- \Rdata2[4]$latch~combout\ = ( \Mux11~0_combout\ & ( (!\RegWrite~input_o\) # (\Rdata2[4]$latch~combout\) ) ) # ( !\Mux11~0_combout\ & ( (\Rdata2[4]$latch~combout\ & \RegWrite~input_o\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000001100000011000000110000001111110011111100111111001111110011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_Rdata2[4]$latch~combout\,
	datac => \ALT_INV_RegWrite~input_o\,
	dataf => \ALT_INV_Mux11~0_combout\,
	combout => \Rdata2[4]$latch~combout\);

-- Location: LABCELL_X61_Y2_N18
\Mux10~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Mux10~0_combout\ = ( \regB[0]~input_o\ & ( \regB[1]~input_o\ & ( R3(5) ) ) ) # ( !\regB[0]~input_o\ & ( \regB[1]~input_o\ & ( R2(5) ) ) ) # ( \regB[0]~input_o\ & ( !\regB[1]~input_o\ & ( R1(5) ) ) ) # ( !\regB[0]~input_o\ & ( !\regB[1]~input_o\ & ( R0(5) 
-- ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000011111111001100110011001100001111000011110101010101010101",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R3(5),
	datab => ALT_INV_R1(5),
	datac => ALT_INV_R2(5),
	datad => ALT_INV_R0(5),
	datae => \ALT_INV_regB[0]~input_o\,
	dataf => \ALT_INV_regB[1]~input_o\,
	combout => \Mux10~0_combout\);

-- Location: LABCELL_X61_Y2_N54
\Rdata2[5]$latch\ : cyclonev_lcell_comb
-- Equation(s):
-- \Rdata2[5]$latch~combout\ = ( \Mux10~0_combout\ & ( (!\RegWrite~input_o\) # (\Rdata2[5]$latch~combout\) ) ) # ( !\Mux10~0_combout\ & ( (\RegWrite~input_o\ & \Rdata2[5]$latch~combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000110011000000000011001111001100111111111100110011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_RegWrite~input_o\,
	datad => \ALT_INV_Rdata2[5]$latch~combout\,
	dataf => \ALT_INV_Mux10~0_combout\,
	combout => \Rdata2[5]$latch~combout\);

-- Location: LABCELL_X60_Y2_N57
\Mux9~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Mux9~0_combout\ = ( \regB[0]~input_o\ & ( \regB[1]~input_o\ & ( R3(6) ) ) ) # ( !\regB[0]~input_o\ & ( \regB[1]~input_o\ & ( R2(6) ) ) ) # ( \regB[0]~input_o\ & ( !\regB[1]~input_o\ & ( R1(6) ) ) ) # ( !\regB[0]~input_o\ & ( !\regB[1]~input_o\ & ( R0(6) 
-- ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101000000001111111100110011001100110000111100001111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R0(6),
	datab => ALT_INV_R2(6),
	datac => ALT_INV_R3(6),
	datad => ALT_INV_R1(6),
	datae => \ALT_INV_regB[0]~input_o\,
	dataf => \ALT_INV_regB[1]~input_o\,
	combout => \Mux9~0_combout\);

-- Location: LABCELL_X60_Y2_N48
\Rdata2[6]$latch\ : cyclonev_lcell_comb
-- Equation(s):
-- \Rdata2[6]$latch~combout\ = ( \Mux9~0_combout\ & ( (!\RegWrite~input_o\) # (\Rdata2[6]$latch~combout\) ) ) # ( !\Mux9~0_combout\ & ( (\RegWrite~input_o\ & \Rdata2[6]$latch~combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000001100000011000000110000001111001111110011111100111111001111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_RegWrite~input_o\,
	datac => \ALT_INV_Rdata2[6]$latch~combout\,
	dataf => \ALT_INV_Mux9~0_combout\,
	combout => \Rdata2[6]$latch~combout\);

-- Location: LABCELL_X61_Y3_N21
\Mux8~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Mux8~0_combout\ = ( \regB[0]~input_o\ & ( \regB[1]~input_o\ & ( R3(7) ) ) ) # ( !\regB[0]~input_o\ & ( \regB[1]~input_o\ & ( R2(7) ) ) ) # ( \regB[0]~input_o\ & ( !\regB[1]~input_o\ & ( R1(7) ) ) ) # ( !\regB[0]~input_o\ & ( !\regB[1]~input_o\ & ( R0(7) 
-- ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101001100110011001100001111000011110000000011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => ALT_INV_R0(7),
	datab => ALT_INV_R1(7),
	datac => ALT_INV_R2(7),
	datad => ALT_INV_R3(7),
	datae => \ALT_INV_regB[0]~input_o\,
	dataf => \ALT_INV_regB[1]~input_o\,
	combout => \Mux8~0_combout\);

-- Location: LABCELL_X61_Y3_N33
\Rdata2[7]$latch\ : cyclonev_lcell_comb
-- Equation(s):
-- \Rdata2[7]$latch~combout\ = ( \Mux8~0_combout\ & ( (!\RegWrite~input_o\) # (\Rdata2[7]$latch~combout\) ) ) # ( !\Mux8~0_combout\ & ( (\Rdata2[7]$latch~combout\ & \RegWrite~input_o\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010111111111010101011111111101010101",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Rdata2[7]$latch~combout\,
	datad => \ALT_INV_RegWrite~input_o\,
	dataf => \ALT_INV_Mux8~0_combout\,
	combout => \Rdata2[7]$latch~combout\);

-- Location: LABCELL_X64_Y30_N0
\~QUARTUS_CREATED_GND~I\ : cyclonev_lcell_comb
-- Equation(s):

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000000000000000000000000",
	shared_arith => "off")
-- pragma translate_on
;
END structure;


