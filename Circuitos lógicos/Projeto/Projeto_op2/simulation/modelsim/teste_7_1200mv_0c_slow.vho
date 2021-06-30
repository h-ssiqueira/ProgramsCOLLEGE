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

-- DATE "06/05/2020 20:18:17"

-- 
-- Device: Altera EP4CE15E22C7 Package TQFP144
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
-- ~ALTERA_ASDO_DATA1~	=>  Location: PIN_6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_FLASH_nCE_nCSO~	=>  Location: PIN_8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_DCLK~	=>  Location: PIN_12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_DATA0~	=>  Location: PIN_13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_nCEO~	=>  Location: PIN_101,	 I/O Standard: 2.5 V,	 Current Strength: 8mA


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


LIBRARY ALTERA;
LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	teste IS
    PORT (
	reset : IN std_logic;
	clock : IN std_logic;
	sensor1 : IN std_logic;
	sensor2 : IN std_logic;
	sensor3 : IN std_logic;
	sensor4 : IN std_logic;
	sensor5 : IN std_logic;
	switch1 : OUT std_logic;
	switch2 : OUT std_logic;
	switch3 : OUT std_logic;
	dirA : OUT std_logic_vector(1 DOWNTO 0);
	dirB : OUT std_logic_vector(1 DOWNTO 0)
	);
END teste;

-- Design Ports Information
-- switch1	=>  Location: PIN_49,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- switch2	=>  Location: PIN_51,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- switch3	=>  Location: PIN_64,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- dirA[0]	=>  Location: PIN_60,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- dirA[1]	=>  Location: PIN_61,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- dirB[0]	=>  Location: PIN_134,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- dirB[1]	=>  Location: PIN_65,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sensor3	=>  Location: PIN_90,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sensor1	=>  Location: PIN_91,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clock	=>  Location: PIN_23,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reset	=>  Location: PIN_24,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sensor2	=>  Location: PIN_58,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sensor4	=>  Location: PIN_59,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sensor5	=>  Location: PIN_50,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF teste IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_reset : std_logic;
SIGNAL ww_clock : std_logic;
SIGNAL ww_sensor1 : std_logic;
SIGNAL ww_sensor2 : std_logic;
SIGNAL ww_sensor3 : std_logic;
SIGNAL ww_sensor4 : std_logic;
SIGNAL ww_sensor5 : std_logic;
SIGNAL ww_switch1 : std_logic;
SIGNAL ww_switch2 : std_logic;
SIGNAL ww_switch3 : std_logic;
SIGNAL ww_dirA : std_logic_vector(1 DOWNTO 0);
SIGNAL ww_dirB : std_logic_vector(1 DOWNTO 0);
SIGNAL \reset~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \clock~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \switch1~output_o\ : std_logic;
SIGNAL \switch2~output_o\ : std_logic;
SIGNAL \switch3~output_o\ : std_logic;
SIGNAL \dirA[0]~output_o\ : std_logic;
SIGNAL \dirA[1]~output_o\ : std_logic;
SIGNAL \dirB[0]~output_o\ : std_logic;
SIGNAL \dirB[1]~output_o\ : std_logic;
SIGNAL \clock~input_o\ : std_logic;
SIGNAL \clock~inputclkctrl_outclk\ : std_logic;
SIGNAL \sensor4~input_o\ : std_logic;
SIGNAL \sensor2~input_o\ : std_logic;
SIGNAL \sensor1~input_o\ : std_logic;
SIGNAL \sensor3~input_o\ : std_logic;
SIGNAL \Selector4~0_combout\ : std_logic;
SIGNAL \reset~input_o\ : std_logic;
SIGNAL \reset~inputclkctrl_outclk\ : std_logic;
SIGNAL \state.Bstop~q\ : std_logic;
SIGNAL \sensor5~input_o\ : std_logic;
SIGNAL \Selector7~0_combout\ : std_logic;
SIGNAL \state.Aback~0_combout\ : std_logic;
SIGNAL \state.Aback~q\ : std_logic;
SIGNAL \Selector5~0_combout\ : std_logic;
SIGNAL \state.Bset~q\ : std_logic;
SIGNAL \Selector6~0_combout\ : std_logic;
SIGNAL \Selector6~1_combout\ : std_logic;
SIGNAL \state.Bset2~q\ : std_logic;
SIGNAL \Selector7~1_combout\ : std_logic;
SIGNAL \state.STARTING~q\ : std_logic;
SIGNAL \Selector0~0_combout\ : std_logic;
SIGNAL \Selector0~1_combout\ : std_logic;
SIGNAL \Selector0~2_combout\ : std_logic;
SIGNAL \state.ABout~q\ : std_logic;
SIGNAL \Selector2~0_combout\ : std_logic;
SIGNAL \Selector2~1_combout\ : std_logic;
SIGNAL \state.Bin~q\ : std_logic;
SIGNAL \Selector3~0_combout\ : std_logic;
SIGNAL \state.Astop~q\ : std_logic;
SIGNAL \Selector1~0_combout\ : std_logic;
SIGNAL \Selector1~1_combout\ : std_logic;
SIGNAL \state.Ain~q\ : std_logic;
SIGNAL \WideOr8~0_combout\ : std_logic;
SIGNAL \WideOr9~combout\ : std_logic;
SIGNAL \WideOr10~0_combout\ : std_logic;
SIGNAL \WideOr8~1_combout\ : std_logic;
SIGNAL \ALT_INV_WideOr8~0_combout\ : std_logic;
SIGNAL \ALT_INV_state.Aback~q\ : std_logic;
SIGNAL \ALT_INV_reset~inputclkctrl_outclk\ : std_logic;
SIGNAL \ALT_INV_WideOr10~0_combout\ : std_logic;

COMPONENT hard_block
    PORT (
	devoe : IN std_logic;
	devclrn : IN std_logic;
	devpor : IN std_logic);
END COMPONENT;

BEGIN

ww_reset <= reset;
ww_clock <= clock;
ww_sensor1 <= sensor1;
ww_sensor2 <= sensor2;
ww_sensor3 <= sensor3;
ww_sensor4 <= sensor4;
ww_sensor5 <= sensor5;
switch1 <= ww_switch1;
switch2 <= ww_switch2;
switch3 <= ww_switch3;
dirA <= ww_dirA;
dirB <= ww_dirB;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\reset~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \reset~input_o\);

\clock~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \clock~input_o\);
\ALT_INV_WideOr8~0_combout\ <= NOT \WideOr8~0_combout\;
\ALT_INV_state.Aback~q\ <= NOT \state.Aback~q\;
\ALT_INV_reset~inputclkctrl_outclk\ <= NOT \reset~inputclkctrl_outclk\;
\ALT_INV_WideOr10~0_combout\ <= NOT \WideOr10~0_combout\;
auto_generated_inst : hard_block
PORT MAP (
	devoe => ww_devoe,
	devclrn => ww_devclrn,
	devpor => ww_devpor);

-- Location: IOOBUF_X19_Y0_N30
\switch1~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_WideOr8~0_combout\,
	devoe => ww_devoe,
	o => \switch1~output_o\);

-- Location: IOOBUF_X19_Y0_N2
\switch2~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_WideOr8~0_combout\,
	devoe => ww_devoe,
	o => \switch2~output_o\);

-- Location: IOOBUF_X30_Y0_N23
\switch3~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \WideOr9~combout\,
	devoe => ww_devoe,
	o => \switch3~output_o\);

-- Location: IOOBUF_X26_Y0_N9
\dirA[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_state.Aback~q\,
	devoe => ww_devoe,
	o => \dirA[0]~output_o\);

-- Location: IOOBUF_X26_Y0_N2
\dirA[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_WideOr10~0_combout\,
	devoe => ww_devoe,
	o => \dirA[1]~output_o\);

-- Location: IOOBUF_X11_Y29_N2
\dirB[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \dirB[0]~output_o\);

-- Location: IOOBUF_X30_Y0_N16
\dirB[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \WideOr8~1_combout\,
	devoe => ww_devoe,
	o => \dirB[1]~output_o\);

-- Location: IOIBUF_X0_Y14_N8
\clock~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_clock,
	o => \clock~input_o\);

-- Location: CLKCTRL_G2
\clock~inputclkctrl\ : cycloneive_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \clock~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \clock~inputclkctrl_outclk\);

-- Location: IOIBUF_X26_Y0_N15
\sensor4~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_sensor4,
	o => \sensor4~input_o\);

-- Location: IOIBUF_X26_Y0_N29
\sensor2~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_sensor2,
	o => \sensor2~input_o\);

-- Location: IOIBUF_X41_Y15_N1
\sensor1~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_sensor1,
	o => \sensor1~input_o\);

-- Location: IOIBUF_X41_Y15_N8
\sensor3~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_sensor3,
	o => \sensor3~input_o\);

-- Location: LCCOMB_X26_Y2_N4
\Selector4~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Selector4~0_combout\ = (\sensor3~input_o\ & ((\state.Ain~q\) # ((!\sensor1~input_o\ & \state.Bstop~q\)))) # (!\sensor3~input_o\ & (!\sensor1~input_o\ & (\state.Bstop~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011101000110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \sensor3~input_o\,
	datab => \sensor1~input_o\,
	datac => \state.Bstop~q\,
	datad => \state.Ain~q\,
	combout => \Selector4~0_combout\);

-- Location: IOIBUF_X0_Y14_N15
\reset~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reset,
	o => \reset~input_o\);

-- Location: CLKCTRL_G4
\reset~inputclkctrl\ : cycloneive_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \reset~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \reset~inputclkctrl_outclk\);

-- Location: FF_X26_Y2_N5
\state.Bstop\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clock~inputclkctrl_outclk\,
	d => \Selector4~0_combout\,
	clrn => \ALT_INV_reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \state.Bstop~q\);

-- Location: IOIBUF_X19_Y0_N8
\sensor5~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_sensor5,
	o => \sensor5~input_o\);

-- Location: LCCOMB_X26_Y2_N22
\Selector7~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Selector7~0_combout\ = (!\sensor2~input_o\ & \state.STARTING~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \sensor2~input_o\,
	datad => \state.STARTING~q\,
	combout => \Selector7~0_combout\);

-- Location: LCCOMB_X26_Y2_N10
\state.Aback~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \state.Aback~0_combout\ = (\sensor5~input_o\) # (\state.Aback~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \sensor5~input_o\,
	datac => \state.Aback~q\,
	combout => \state.Aback~0_combout\);

-- Location: FF_X26_Y2_N11
\state.Aback\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clock~inputclkctrl_outclk\,
	d => \state.Aback~0_combout\,
	clrn => \ALT_INV_reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \state.Aback~q\);

-- Location: LCCOMB_X26_Y2_N24
\Selector5~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Selector5~0_combout\ = (\sensor5~input_o\ & (((!\sensor2~input_o\ & \state.Bset~q\)) # (!\state.Aback~q\))) # (!\sensor5~input_o\ & (((\state.Bset~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0111000011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \sensor5~input_o\,
	datab => \sensor2~input_o\,
	datac => \state.Bset~q\,
	datad => \state.Aback~q\,
	combout => \Selector5~0_combout\);

-- Location: FF_X26_Y2_N25
\state.Bset\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clock~inputclkctrl_outclk\,
	d => \Selector5~0_combout\,
	clrn => \ALT_INV_reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \state.Bset~q\);

-- Location: LCCOMB_X26_Y2_N20
\Selector6~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Selector6~0_combout\ = (\sensor2~input_o\ & (\sensor5~input_o\ & \state.Bset~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \sensor2~input_o\,
	datac => \sensor5~input_o\,
	datad => \state.Bset~q\,
	combout => \Selector6~0_combout\);

-- Location: LCCOMB_X26_Y2_N12
\Selector6~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \Selector6~1_combout\ = (\Selector6~0_combout\) # ((\state.Bset2~q\ & ((!\sensor5~input_o\) # (!\sensor3~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111101110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \sensor3~input_o\,
	datab => \sensor5~input_o\,
	datac => \state.Bset2~q\,
	datad => \Selector6~0_combout\,
	combout => \Selector6~1_combout\);

-- Location: FF_X26_Y2_N13
\state.Bset2\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clock~inputclkctrl_outclk\,
	d => \Selector6~1_combout\,
	clrn => \ALT_INV_reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \state.Bset2~q\);

-- Location: LCCOMB_X26_Y2_N26
\Selector7~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \Selector7~1_combout\ = (\Selector7~0_combout\) # ((\sensor3~input_o\ & (\sensor5~input_o\ & \state.Bset2~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111100011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \sensor3~input_o\,
	datab => \sensor5~input_o\,
	datac => \Selector7~0_combout\,
	datad => \state.Bset2~q\,
	combout => \Selector7~1_combout\);

-- Location: FF_X26_Y2_N27
\state.STARTING\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clock~inputclkctrl_outclk\,
	d => \Selector7~1_combout\,
	clrn => \ALT_INV_reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \state.STARTING~q\);

-- Location: LCCOMB_X26_Y2_N18
\Selector0~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Selector0~0_combout\ = (\sensor2~input_o\ & ((\state.STARTING~q\) # ((!\sensor4~input_o\ & \state.Bin~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100010011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \sensor4~input_o\,
	datab => \sensor2~input_o\,
	datac => \state.STARTING~q\,
	datad => \state.Bin~q\,
	combout => \Selector0~0_combout\);

-- Location: LCCOMB_X26_Y2_N16
\Selector0~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \Selector0~1_combout\ = (\Selector0~0_combout\) # ((!\sensor3~input_o\ & (\sensor1~input_o\ & \state.Ain~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111101000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \sensor3~input_o\,
	datab => \sensor1~input_o\,
	datac => \state.Ain~q\,
	datad => \Selector0~0_combout\,
	combout => \Selector0~1_combout\);

-- Location: LCCOMB_X26_Y2_N0
\Selector0~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \Selector0~2_combout\ = (\Selector0~1_combout\) # ((\state.ABout~q\ & (\sensor3~input_o\ $ (!\sensor4~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \sensor3~input_o\,
	datab => \sensor4~input_o\,
	datac => \state.ABout~q\,
	datad => \Selector0~1_combout\,
	combout => \Selector0~2_combout\);

-- Location: FF_X26_Y2_N1
\state.ABout\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clock~inputclkctrl_outclk\,
	d => \Selector0~2_combout\,
	clrn => \ALT_INV_reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \state.ABout~q\);

-- Location: LCCOMB_X26_Y2_N6
\Selector2~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Selector2~0_combout\ = (\sensor3~input_o\ & ((\state.ABout~q\) # ((!\sensor2~input_o\ & \state.Bin~q\)))) # (!\sensor3~input_o\ & (!\sensor2~input_o\ & (\state.Bin~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011101000110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \sensor3~input_o\,
	datab => \sensor2~input_o\,
	datac => \state.Bin~q\,
	datad => \state.ABout~q\,
	combout => \Selector2~0_combout\);

-- Location: LCCOMB_X26_Y2_N28
\Selector2~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \Selector2~1_combout\ = (\sensor4~input_o\ & (\sensor1~input_o\ & (\state.Bstop~q\))) # (!\sensor4~input_o\ & ((\Selector2~0_combout\) # ((\sensor1~input_o\ & \state.Bstop~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101010111000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \sensor4~input_o\,
	datab => \sensor1~input_o\,
	datac => \state.Bstop~q\,
	datad => \Selector2~0_combout\,
	combout => \Selector2~1_combout\);

-- Location: FF_X26_Y2_N29
\state.Bin\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clock~inputclkctrl_outclk\,
	d => \Selector2~1_combout\,
	clrn => \ALT_INV_reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \state.Bin~q\);

-- Location: LCCOMB_X26_Y2_N2
\Selector3~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Selector3~0_combout\ = (\sensor4~input_o\ & ((\state.Bin~q\) # ((!\sensor2~input_o\ & \state.Astop~q\)))) # (!\sensor4~input_o\ & (!\sensor2~input_o\ & (\state.Astop~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011101000110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \sensor4~input_o\,
	datab => \sensor2~input_o\,
	datac => \state.Astop~q\,
	datad => \state.Bin~q\,
	combout => \Selector3~0_combout\);

-- Location: FF_X26_Y2_N3
\state.Astop\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clock~inputclkctrl_outclk\,
	d => \Selector3~0_combout\,
	clrn => \ALT_INV_reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \state.Astop~q\);

-- Location: LCCOMB_X26_Y2_N30
\Selector1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Selector1~0_combout\ = (\sensor4~input_o\ & ((\state.ABout~q\) # ((!\sensor1~input_o\ & \state.Ain~q\)))) # (!\sensor4~input_o\ & (!\sensor1~input_o\ & (\state.Ain~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011101000110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \sensor4~input_o\,
	datab => \sensor1~input_o\,
	datac => \state.Ain~q\,
	datad => \state.ABout~q\,
	combout => \Selector1~0_combout\);

-- Location: LCCOMB_X26_Y2_N14
\Selector1~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \Selector1~1_combout\ = (\state.Astop~q\ & ((\sensor2~input_o\) # ((\Selector1~0_combout\ & !\sensor3~input_o\)))) # (!\state.Astop~q\ & (((\Selector1~0_combout\ & !\sensor3~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000100011111000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \state.Astop~q\,
	datab => \sensor2~input_o\,
	datac => \Selector1~0_combout\,
	datad => \sensor3~input_o\,
	combout => \Selector1~1_combout\);

-- Location: FF_X26_Y2_N15
\state.Ain\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clock~inputclkctrl_outclk\,
	d => \Selector1~1_combout\,
	clrn => \ALT_INV_reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \state.Ain~q\);

-- Location: LCCOMB_X26_Y2_N8
\WideOr8~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \WideOr8~0_combout\ = (\state.Ain~q\) # ((\state.ABout~q\) # ((\state.Bstop~q\) # (!\state.Aback~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \state.Ain~q\,
	datab => \state.ABout~q\,
	datac => \state.Bstop~q\,
	datad => \state.Aback~q\,
	combout => \WideOr8~0_combout\);

-- Location: LCCOMB_X27_Y2_N4
WideOr9 : cycloneive_lcell_comb
-- Equation(s):
-- \WideOr9~combout\ = (\state.STARTING~q\) # ((\state.Bset2~q\) # (!\state.Aback~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110101111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \state.STARTING~q\,
	datac => \state.Aback~q\,
	datad => \state.Bset2~q\,
	combout => \WideOr9~combout\);

-- Location: LCCOMB_X27_Y2_N26
\WideOr10~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \WideOr10~0_combout\ = (\state.Bset2~q\) # ((\state.Bset~q\) # ((\state.Astop~q\) # (!\state.Aback~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \state.Bset2~q\,
	datab => \state.Bset~q\,
	datac => \state.Astop~q\,
	datad => \state.Aback~q\,
	combout => \WideOr10~0_combout\);

-- Location: LCCOMB_X27_Y2_N24
\WideOr8~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \WideOr8~1_combout\ = (!\state.Bstop~q\ & \state.Aback~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \state.Bstop~q\,
	datad => \state.Aback~q\,
	combout => \WideOr8~1_combout\);

ww_switch1 <= \switch1~output_o\;

ww_switch2 <= \switch2~output_o\;

ww_switch3 <= \switch3~output_o\;

ww_dirA(0) <= \dirA[0]~output_o\;

ww_dirA(1) <= \dirA[1]~output_o\;

ww_dirB(0) <= \dirB[0]~output_o\;

ww_dirB(1) <= \dirB[1]~output_o\;
END structure;


