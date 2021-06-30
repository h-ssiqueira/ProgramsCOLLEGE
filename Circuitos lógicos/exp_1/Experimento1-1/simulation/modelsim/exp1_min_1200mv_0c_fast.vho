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

-- DATE "03/02/2020 16:10:38"

-- 
-- Device: Altera EP4CE115F29C7 Package FBGA780
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	hard_block IS
    PORT (
	devoe : IN std_logic;
	devclrn : IN std_logic;
	devpor : IN std_logic
	);
END hard_block;

-- Design Ports Information
-- ~ALTERA_ASDO_DATA1~	=>  Location: PIN_F4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_FLASH_nCE_nCSO~	=>  Location: PIN_E2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_DCLK~	=>  Location: PIN_P3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_DATA0~	=>  Location: PIN_N7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_nCEO~	=>  Location: PIN_P28,	 I/O Standard: 2.5 V,	 Current Strength: 8mA


ARCHITECTURE structure OF hard_block IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL \~ALTERA_ASDO_DATA1~~padout\ : std_logic;
SIGNAL \~ALTERA_FLASH_nCE_nCSO~~padout\ : std_logic;
SIGNAL \~ALTERA_DATA0~~padout\ : std_logic;
SIGNAL \~ALTERA_ASDO_DATA1~~ibuf_o\ : std_logic;
SIGNAL \~ALTERA_FLASH_nCE_nCSO~~ibuf_o\ : std_logic;
SIGNAL \~ALTERA_DATA0~~ibuf_o\ : std_logic;

BEGIN

ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
END structure;


LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	exp1 IS
    PORT (
	f1 : OUT std_logic;
	a : IN std_logic;
	f2 : OUT std_logic;
	b : IN std_logic;
	f3 : OUT std_logic;
	c : IN std_logic;
	f4 : OUT std_logic;
	d : IN std_logic
	);
END exp1;

-- Design Ports Information
-- f1	=>  Location: PIN_U6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- f2	=>  Location: PIN_AC1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- f3	=>  Location: PIN_Y4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- f4	=>  Location: PIN_U5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a	=>  Location: PIN_W1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b	=>  Location: PIN_AC3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- c	=>  Location: PIN_Y3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d	=>  Location: PIN_AC2,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF exp1 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_f1 : std_logic;
SIGNAL ww_a : std_logic;
SIGNAL ww_f2 : std_logic;
SIGNAL ww_b : std_logic;
SIGNAL ww_f3 : std_logic;
SIGNAL ww_c : std_logic;
SIGNAL ww_f4 : std_logic;
SIGNAL ww_d : std_logic;
SIGNAL \f1~output_o\ : std_logic;
SIGNAL \f2~output_o\ : std_logic;
SIGNAL \f3~output_o\ : std_logic;
SIGNAL \f4~output_o\ : std_logic;
SIGNAL \a~input_o\ : std_logic;
SIGNAL \b~input_o\ : std_logic;
SIGNAL \c~input_o\ : std_logic;
SIGNAL \inst5~0_combout\ : std_logic;
SIGNAL \d~input_o\ : std_logic;
SIGNAL \inst9~0_combout\ : std_logic;

COMPONENT hard_block
    PORT (
	devoe : IN std_logic;
	devclrn : IN std_logic;
	devpor : IN std_logic);
END COMPONENT;

BEGIN

f1 <= ww_f1;
ww_a <= a;
f2 <= ww_f2;
ww_b <= b;
f3 <= ww_f3;
ww_c <= c;
f4 <= ww_f4;
ww_d <= d;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
auto_generated_inst : hard_block
PORT MAP (
	devoe => ww_devoe,
	devclrn => ww_devclrn,
	devpor => ww_devpor);

-- Location: IOOBUF_X0_Y25_N23
\f1~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \a~input_o\,
	devoe => ww_devoe,
	o => \f1~output_o\);

-- Location: IOOBUF_X0_Y23_N16
\f2~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \b~input_o\,
	devoe => ww_devoe,
	o => \f2~output_o\);

-- Location: IOOBUF_X0_Y24_N9
\f3~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst5~0_combout\,
	devoe => ww_devoe,
	o => \f3~output_o\);

-- Location: IOOBUF_X0_Y24_N2
\f4~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst9~0_combout\,
	devoe => ww_devoe,
	o => \f4~output_o\);

-- Location: IOIBUF_X0_Y25_N15
\a~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a,
	o => \a~input_o\);

-- Location: IOIBUF_X0_Y23_N22
\b~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b,
	o => \b~input_o\);

-- Location: IOIBUF_X0_Y24_N15
\c~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_c,
	o => \c~input_o\);

-- Location: LCCOMB_X1_Y24_N16
\inst5~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst5~0_combout\ = (\c~input_o\ & ((!\a~input_o\) # (!\b~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100010011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b~input_o\,
	datab => \c~input_o\,
	datad => \a~input_o\,
	combout => \inst5~0_combout\);

-- Location: IOIBUF_X0_Y24_N22
\d~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d,
	o => \d~input_o\);

-- Location: LCCOMB_X1_Y24_N18
\inst9~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst9~0_combout\ = (\d~input_o\ & ((\b~input_o\ & (!\c~input_o\ & !\a~input_o\)) # (!\b~input_o\ & ((!\a~input_o\) # (!\c~input_o\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001000001110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b~input_o\,
	datab => \c~input_o\,
	datac => \d~input_o\,
	datad => \a~input_o\,
	combout => \inst9~0_combout\);

ww_f1 <= \f1~output_o\;

ww_f2 <= \f2~output_o\;

ww_f3 <= \f3~output_o\;

ww_f4 <= \f4~output_o\;
END structure;


