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

-- DATE "09/10/2020 09:09:14"

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

ENTITY 	adder8b IS
    PORT (
	Cin : IN std_logic;
	X : IN std_logic_vector(7 DOWNTO 0);
	Y : IN std_logic_vector(7 DOWNTO 0);
	S : BUFFER std_logic_vector(7 DOWNTO 0);
	Cout : BUFFER std_logic;
	Overflow : BUFFER std_logic
	);
END adder8b;

-- Design Ports Information
-- S[0]	=>  Location: PIN_AG3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- S[1]	=>  Location: PIN_AD10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- S[2]	=>  Location: PIN_AD12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- S[3]	=>  Location: PIN_AG2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- S[4]	=>  Location: PIN_AF10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- S[5]	=>  Location: PIN_AH4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- S[6]	=>  Location: PIN_AD7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- S[7]	=>  Location: PIN_AE7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Cout	=>  Location: PIN_AC12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Overflow	=>  Location: PIN_AE11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y[7]	=>  Location: PIN_AJ1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- X[7]	=>  Location: PIN_AH2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Cin	=>  Location: PIN_AJ2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y[0]	=>  Location: PIN_AH5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- X[0]	=>  Location: PIN_AF9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y[1]	=>  Location: PIN_AF6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- X[1]	=>  Location: PIN_AH3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y[2]	=>  Location: PIN_AF8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- X[2]	=>  Location: PIN_AF5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y[3]	=>  Location: PIN_AG7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- X[3]	=>  Location: PIN_AA12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y[4]	=>  Location: PIN_AF4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- X[4]	=>  Location: PIN_AG5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y[5]	=>  Location: PIN_AG6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- X[5]	=>  Location: PIN_AB12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y[6]	=>  Location: PIN_AG1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- X[6]	=>  Location: PIN_AG8,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF adder8b IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_Cin : std_logic;
SIGNAL ww_X : std_logic_vector(7 DOWNTO 0);
SIGNAL ww_Y : std_logic_vector(7 DOWNTO 0);
SIGNAL ww_S : std_logic_vector(7 DOWNTO 0);
SIGNAL ww_Cout : std_logic;
SIGNAL ww_Overflow : std_logic;
SIGNAL \~QUARTUS_CREATED_GND~I_combout\ : std_logic;
SIGNAL \X[0]~input_o\ : std_logic;
SIGNAL \Cin~input_o\ : std_logic;
SIGNAL \Y[0]~input_o\ : std_logic;
SIGNAL \_~1_sumout\ : std_logic;
SIGNAL \X[1]~input_o\ : std_logic;
SIGNAL \Y[1]~input_o\ : std_logic;
SIGNAL \_~2\ : std_logic;
SIGNAL \_~3\ : std_logic;
SIGNAL \_~5_sumout\ : std_logic;
SIGNAL \X[2]~input_o\ : std_logic;
SIGNAL \Y[2]~input_o\ : std_logic;
SIGNAL \_~6\ : std_logic;
SIGNAL \_~7\ : std_logic;
SIGNAL \_~9_sumout\ : std_logic;
SIGNAL \Y[3]~input_o\ : std_logic;
SIGNAL \X[3]~input_o\ : std_logic;
SIGNAL \_~10\ : std_logic;
SIGNAL \_~11\ : std_logic;
SIGNAL \_~13_sumout\ : std_logic;
SIGNAL \X[4]~input_o\ : std_logic;
SIGNAL \Y[4]~input_o\ : std_logic;
SIGNAL \_~14\ : std_logic;
SIGNAL \_~15\ : std_logic;
SIGNAL \_~17_sumout\ : std_logic;
SIGNAL \X[5]~input_o\ : std_logic;
SIGNAL \Y[5]~input_o\ : std_logic;
SIGNAL \_~18\ : std_logic;
SIGNAL \_~19\ : std_logic;
SIGNAL \_~21_sumout\ : std_logic;
SIGNAL \X[6]~input_o\ : std_logic;
SIGNAL \Y[6]~input_o\ : std_logic;
SIGNAL \_~22\ : std_logic;
SIGNAL \_~23\ : std_logic;
SIGNAL \_~25_sumout\ : std_logic;
SIGNAL \Y[7]~input_o\ : std_logic;
SIGNAL \X[7]~input_o\ : std_logic;
SIGNAL \_~26\ : std_logic;
SIGNAL \_~27\ : std_logic;
SIGNAL \_~29_sumout\ : std_logic;
SIGNAL \_~30\ : std_logic;
SIGNAL \_~31\ : std_logic;
SIGNAL \_~33_sumout\ : std_logic;
SIGNAL \Overflow~0_combout\ : std_logic;
SIGNAL \ALT_INV_X[6]~input_o\ : std_logic;
SIGNAL \ALT_INV_Y[6]~input_o\ : std_logic;
SIGNAL \ALT_INV_X[5]~input_o\ : std_logic;
SIGNAL \ALT_INV_Y[5]~input_o\ : std_logic;
SIGNAL \ALT_INV_X[4]~input_o\ : std_logic;
SIGNAL \ALT_INV_Y[4]~input_o\ : std_logic;
SIGNAL \ALT_INV_X[3]~input_o\ : std_logic;
SIGNAL \ALT_INV_Y[3]~input_o\ : std_logic;
SIGNAL \ALT_INV_X[2]~input_o\ : std_logic;
SIGNAL \ALT_INV_Y[2]~input_o\ : std_logic;
SIGNAL \ALT_INV_X[1]~input_o\ : std_logic;
SIGNAL \ALT_INV_Y[1]~input_o\ : std_logic;
SIGNAL \ALT_INV_X[0]~input_o\ : std_logic;
SIGNAL \ALT_INV_Y[0]~input_o\ : std_logic;
SIGNAL \ALT_INV_Cin~input_o\ : std_logic;
SIGNAL \ALT_INV_X[7]~input_o\ : std_logic;
SIGNAL \ALT_INV_Y[7]~input_o\ : std_logic;
SIGNAL \ALT_INV__~33_sumout\ : std_logic;
SIGNAL \ALT_INV__~29_sumout\ : std_logic;

BEGIN

ww_Cin <= Cin;
ww_X <= X;
ww_Y <= Y;
S <= ww_S;
Cout <= ww_Cout;
Overflow <= ww_Overflow;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_X[6]~input_o\ <= NOT \X[6]~input_o\;
\ALT_INV_Y[6]~input_o\ <= NOT \Y[6]~input_o\;
\ALT_INV_X[5]~input_o\ <= NOT \X[5]~input_o\;
\ALT_INV_Y[5]~input_o\ <= NOT \Y[5]~input_o\;
\ALT_INV_X[4]~input_o\ <= NOT \X[4]~input_o\;
\ALT_INV_Y[4]~input_o\ <= NOT \Y[4]~input_o\;
\ALT_INV_X[3]~input_o\ <= NOT \X[3]~input_o\;
\ALT_INV_Y[3]~input_o\ <= NOT \Y[3]~input_o\;
\ALT_INV_X[2]~input_o\ <= NOT \X[2]~input_o\;
\ALT_INV_Y[2]~input_o\ <= NOT \Y[2]~input_o\;
\ALT_INV_X[1]~input_o\ <= NOT \X[1]~input_o\;
\ALT_INV_Y[1]~input_o\ <= NOT \Y[1]~input_o\;
\ALT_INV_X[0]~input_o\ <= NOT \X[0]~input_o\;
\ALT_INV_Y[0]~input_o\ <= NOT \Y[0]~input_o\;
\ALT_INV_Cin~input_o\ <= NOT \Cin~input_o\;
\ALT_INV_X[7]~input_o\ <= NOT \X[7]~input_o\;
\ALT_INV_Y[7]~input_o\ <= NOT \Y[7]~input_o\;
\ALT_INV__~33_sumout\ <= NOT \_~33_sumout\;
\ALT_INV__~29_sumout\ <= NOT \_~29_sumout\;

-- Location: IOOBUF_X6_Y0_N36
\S[0]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \_~1_sumout\,
	devoe => ww_devoe,
	o => ww_S(0));

-- Location: IOOBUF_X4_Y0_N19
\S[1]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \_~5_sumout\,
	devoe => ww_devoe,
	o => ww_S(1));

-- Location: IOOBUF_X16_Y0_N19
\S[2]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \_~9_sumout\,
	devoe => ww_devoe,
	o => ww_S(2));

-- Location: IOOBUF_X16_Y0_N36
\S[3]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \_~13_sumout\,
	devoe => ww_devoe,
	o => ww_S(3));

-- Location: IOOBUF_X4_Y0_N53
\S[4]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \_~17_sumout\,
	devoe => ww_devoe,
	o => ww_S(4));

-- Location: IOOBUF_X6_Y0_N53
\S[5]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \_~21_sumout\,
	devoe => ww_devoe,
	o => ww_S(5));

-- Location: IOOBUF_X6_Y0_N2
\S[6]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \_~25_sumout\,
	devoe => ww_devoe,
	o => ww_S(6));

-- Location: IOOBUF_X6_Y0_N19
\S[7]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \_~29_sumout\,
	devoe => ww_devoe,
	o => ww_S(7));

-- Location: IOOBUF_X16_Y0_N2
\Cout~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \_~33_sumout\,
	devoe => ww_devoe,
	o => ww_Cout);

-- Location: IOOBUF_X4_Y0_N36
\Overflow~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \Overflow~0_combout\,
	devoe => ww_devoe,
	o => ww_Overflow);

-- Location: IOIBUF_X8_Y0_N35
\X[0]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_X(0),
	o => \X[0]~input_o\);

-- Location: IOIBUF_X14_Y0_N18
\Cin~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Cin,
	o => \Cin~input_o\);

-- Location: IOIBUF_X14_Y0_N52
\Y[0]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Y(0),
	o => \Y[0]~input_o\);

-- Location: LABCELL_X11_Y1_N0
\_~1\ : cyclonev_lcell_comb
-- Equation(s):
-- \_~1_sumout\ = SUM(( !\X[0]~input_o\ $ (!\Cin~input_o\ $ (\Y[0]~input_o\)) ) + ( !VCC ) + ( !VCC ))
-- \_~2\ = CARRY(( !\X[0]~input_o\ $ (!\Cin~input_o\ $ (\Y[0]~input_o\)) ) + ( !VCC ) + ( !VCC ))
-- \_~3\ = SHARE((!\X[0]~input_o\ & (\Cin~input_o\ & \Y[0]~input_o\)) # (\X[0]~input_o\ & ((\Y[0]~input_o\) # (\Cin~input_o\))))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000001010101111100000000000000000101101010100101",
	shared_arith => "on")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_X[0]~input_o\,
	datac => \ALT_INV_Cin~input_o\,
	datad => \ALT_INV_Y[0]~input_o\,
	cin => GND,
	sharein => GND,
	sumout => \_~1_sumout\,
	cout => \_~2\,
	shareout => \_~3\);

-- Location: IOIBUF_X16_Y0_N52
\X[1]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_X(1),
	o => \X[1]~input_o\);

-- Location: IOIBUF_X12_Y0_N35
\Y[1]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Y(1),
	o => \Y[1]~input_o\);

-- Location: LABCELL_X11_Y1_N3
\_~5\ : cyclonev_lcell_comb
-- Equation(s):
-- \_~5_sumout\ = SUM(( !\X[1]~input_o\ $ (!\Y[1]~input_o\) ) + ( \_~3\ ) + ( \_~2\ ))
-- \_~6\ = CARRY(( !\X[1]~input_o\ $ (!\Y[1]~input_o\) ) + ( \_~3\ ) + ( \_~2\ ))
-- \_~7\ = SHARE((\X[1]~input_o\ & \Y[1]~input_o\))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000110000001100000000000000000011110000111100",
	shared_arith => "on")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_X[1]~input_o\,
	datac => \ALT_INV_Y[1]~input_o\,
	cin => \_~2\,
	sharein => \_~3\,
	sumout => \_~5_sumout\,
	cout => \_~6\,
	shareout => \_~7\);

-- Location: IOIBUF_X8_Y0_N18
\X[2]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_X(2),
	o => \X[2]~input_o\);

-- Location: IOIBUF_X10_Y0_N75
\Y[2]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Y(2),
	o => \Y[2]~input_o\);

-- Location: LABCELL_X11_Y1_N6
\_~9\ : cyclonev_lcell_comb
-- Equation(s):
-- \_~9_sumout\ = SUM(( !\X[2]~input_o\ $ (!\Y[2]~input_o\) ) + ( \_~7\ ) + ( \_~6\ ))
-- \_~10\ = CARRY(( !\X[2]~input_o\ $ (!\Y[2]~input_o\) ) + ( \_~7\ ) + ( \_~6\ ))
-- \_~11\ = SHARE((\X[2]~input_o\ & \Y[2]~input_o\))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000110000001100000000000000000011110000111100",
	shared_arith => "on")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_X[2]~input_o\,
	datac => \ALT_INV_Y[2]~input_o\,
	cin => \_~6\,
	sharein => \_~7\,
	sumout => \_~9_sumout\,
	cout => \_~10\,
	shareout => \_~11\);

-- Location: IOIBUF_X10_Y0_N92
\Y[3]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Y(3),
	o => \Y[3]~input_o\);

-- Location: IOIBUF_X12_Y0_N1
\X[3]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_X(3),
	o => \X[3]~input_o\);

-- Location: LABCELL_X11_Y1_N9
\_~13\ : cyclonev_lcell_comb
-- Equation(s):
-- \_~13_sumout\ = SUM(( !\Y[3]~input_o\ $ (!\X[3]~input_o\) ) + ( \_~11\ ) + ( \_~10\ ))
-- \_~14\ = CARRY(( !\Y[3]~input_o\ $ (!\X[3]~input_o\) ) + ( \_~11\ ) + ( \_~10\ ))
-- \_~15\ = SHARE((\Y[3]~input_o\ & \X[3]~input_o\))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000001010000010100000000000000000101101001011010",
	shared_arith => "on")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y[3]~input_o\,
	datac => \ALT_INV_X[3]~input_o\,
	cin => \_~10\,
	sharein => \_~11\,
	sumout => \_~13_sumout\,
	cout => \_~14\,
	shareout => \_~15\);

-- Location: IOIBUF_X14_Y0_N35
\X[4]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_X(4),
	o => \X[4]~input_o\);

-- Location: IOIBUF_X8_Y0_N1
\Y[4]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Y(4),
	o => \Y[4]~input_o\);

-- Location: LABCELL_X11_Y1_N12
\_~17\ : cyclonev_lcell_comb
-- Equation(s):
-- \_~17_sumout\ = SUM(( !\X[4]~input_o\ $ (!\Y[4]~input_o\) ) + ( \_~15\ ) + ( \_~14\ ))
-- \_~18\ = CARRY(( !\X[4]~input_o\ $ (!\Y[4]~input_o\) ) + ( \_~15\ ) + ( \_~14\ ))
-- \_~19\ = SHARE((\X[4]~input_o\ & \Y[4]~input_o\))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000110000001100000000000000000011110000111100",
	shared_arith => "on")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_X[4]~input_o\,
	datac => \ALT_INV_Y[4]~input_o\,
	cin => \_~14\,
	sharein => \_~15\,
	sumout => \_~17_sumout\,
	cout => \_~18\,
	shareout => \_~19\);

-- Location: IOIBUF_X12_Y0_N18
\X[5]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_X(5),
	o => \X[5]~input_o\);

-- Location: IOIBUF_X12_Y0_N52
\Y[5]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Y(5),
	o => \Y[5]~input_o\);

-- Location: LABCELL_X11_Y1_N15
\_~21\ : cyclonev_lcell_comb
-- Equation(s):
-- \_~21_sumout\ = SUM(( !\X[5]~input_o\ $ (!\Y[5]~input_o\) ) + ( \_~19\ ) + ( \_~18\ ))
-- \_~22\ = CARRY(( !\X[5]~input_o\ $ (!\Y[5]~input_o\) ) + ( \_~19\ ) + ( \_~18\ ))
-- \_~23\ = SHARE((\X[5]~input_o\ & \Y[5]~input_o\))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000001010000010100000000000000000101101001011010",
	shared_arith => "on")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_X[5]~input_o\,
	datac => \ALT_INV_Y[5]~input_o\,
	cin => \_~18\,
	sharein => \_~19\,
	sumout => \_~21_sumout\,
	cout => \_~22\,
	shareout => \_~23\);

-- Location: IOIBUF_X8_Y0_N52
\X[6]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_X(6),
	o => \X[6]~input_o\);

-- Location: IOIBUF_X10_Y0_N41
\Y[6]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Y(6),
	o => \Y[6]~input_o\);

-- Location: LABCELL_X11_Y1_N18
\_~25\ : cyclonev_lcell_comb
-- Equation(s):
-- \_~25_sumout\ = SUM(( !\X[6]~input_o\ $ (!\Y[6]~input_o\) ) + ( \_~23\ ) + ( \_~22\ ))
-- \_~26\ = CARRY(( !\X[6]~input_o\ $ (!\Y[6]~input_o\) ) + ( \_~23\ ) + ( \_~22\ ))
-- \_~27\ = SHARE((\X[6]~input_o\ & \Y[6]~input_o\))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000110000001100000000000000000011110000111100",
	shared_arith => "on")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_X[6]~input_o\,
	datac => \ALT_INV_Y[6]~input_o\,
	cin => \_~22\,
	sharein => \_~23\,
	sumout => \_~25_sumout\,
	cout => \_~26\,
	shareout => \_~27\);

-- Location: IOIBUF_X14_Y0_N1
\Y[7]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Y(7),
	o => \Y[7]~input_o\);

-- Location: IOIBUF_X10_Y0_N58
\X[7]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_X(7),
	o => \X[7]~input_o\);

-- Location: LABCELL_X11_Y1_N21
\_~29\ : cyclonev_lcell_comb
-- Equation(s):
-- \_~29_sumout\ = SUM(( !\Y[7]~input_o\ $ (!\X[7]~input_o\) ) + ( \_~27\ ) + ( \_~26\ ))
-- \_~30\ = CARRY(( !\Y[7]~input_o\ $ (!\X[7]~input_o\) ) + ( \_~27\ ) + ( \_~26\ ))
-- \_~31\ = SHARE((\Y[7]~input_o\ & \X[7]~input_o\))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000001010000010100000000000000000101101001011010",
	shared_arith => "on")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y[7]~input_o\,
	datac => \ALT_INV_X[7]~input_o\,
	cin => \_~26\,
	sharein => \_~27\,
	sumout => \_~29_sumout\,
	cout => \_~30\,
	shareout => \_~31\);

-- Location: LABCELL_X11_Y1_N24
\_~33\ : cyclonev_lcell_comb
-- Equation(s):
-- \_~33_sumout\ = SUM(( \Y[7]~input_o\ ) + ( \_~31\ ) + ( \_~30\ ))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000000000000111100001111",
	shared_arith => "on")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_Y[7]~input_o\,
	cin => \_~30\,
	sharein => \_~31\,
	sumout => \_~33_sumout\);

-- Location: LABCELL_X11_Y1_N30
\Overflow~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \Overflow~0_combout\ = ( \X[7]~input_o\ & ( \Y[7]~input_o\ & ( !\_~33_sumout\ $ (!\_~29_sumout\) ) ) ) # ( !\X[7]~input_o\ & ( \Y[7]~input_o\ & ( !\_~33_sumout\ $ (\_~29_sumout\) ) ) ) # ( \X[7]~input_o\ & ( !\Y[7]~input_o\ & ( !\_~33_sumout\ $ 
-- (\_~29_sumout\) ) ) ) # ( !\X[7]~input_o\ & ( !\Y[7]~input_o\ & ( !\_~33_sumout\ $ (!\_~29_sumout\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101101001011010101001011010010110100101101001010101101001011010",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV__~33_sumout\,
	datac => \ALT_INV__~29_sumout\,
	datae => \ALT_INV_X[7]~input_o\,
	dataf => \ALT_INV_Y[7]~input_o\,
	combout => \Overflow~0_combout\);

-- Location: LABCELL_X1_Y33_N0
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


