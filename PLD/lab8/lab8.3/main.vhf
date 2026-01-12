--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : main.vhf
-- /___/   /\     Timestamp : 01/11/2026 22:11:44
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan6 -flat -suppress -vhdl /home/x3r1x/Documents/Study/BMS/Programmable/PLD/lab8/lab8.3/main.vhf -w /home/x3r1x/Documents/Study/BMS/Programmable/PLD/lab8/lab8.3/main.sch
--Design Name: main
--Device: spartan6
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesized and simulated, but it should not be modified. 
--
----- CELL INV4_HXILINX_main -----
  
library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity INV4_HXILINX_main is
  
port(
    O0  : out std_logic;
    O1  : out std_logic;
    O2  : out std_logic;
    O3  : out std_logic;

    I0  : in std_logic;
    I1  : in std_logic;
    I2  : in std_logic;
    I3  : in std_logic
  );
end INV4_HXILINX_main;

architecture INV4_HXILINX_main_V of INV4_HXILINX_main is
begin
  O0 <= not I0 ;
  O1 <= not I1 ;
  O2 <= not I2 ;
  O3 <= not I3 ;
end INV4_HXILINX_main_V;

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity main is
   port ( CLK    : in    std_logic; 
          enable : in    std_logic; 
          Mode   : in    std_logic_vector (1 downto 0); 
          sw     : in    std_logic_vector (3 downto 0); 
          AN     : out   std_logic_vector (3 downto 0); 
          S      : out   std_logic_vector (6 downto 0));
end main;

architecture BEHAVIORAL of main is
   attribute HU_SET     : string ;
   signal Q       : std_logic_vector (1 downto 0);
   signal XLXN_8  : std_logic;
   signal XLXN_9  : std_logic;
   signal XLXN_10 : std_logic;
   signal XLXN_11 : std_logic;
   signal XLXN_32 : std_logic_vector (3 downto 0);
   signal XLXN_45 : std_logic_vector (3 downto 0);
   signal XLXN_46 : std_logic_vector (3 downto 0);
   signal XLXN_47 : std_logic_vector (3 downto 0);
   signal XLXN_48 : std_logic_vector (3 downto 0);
   component d2_4_vhd
      port ( X0 : in    std_logic; 
             X1 : in    std_logic; 
             Y0 : out   std_logic; 
             Y1 : out   std_logic; 
             Y2 : out   std_logic; 
             Y3 : out   std_logic);
   end component;
   
   component INV4_HXILINX_main
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             I2 : in    std_logic; 
             I3 : in    std_logic; 
             O0 : out   std_logic; 
             O1 : out   std_logic; 
             O2 : out   std_logic; 
             O3 : out   std_logic);
   end component;
   
   component divider
      port ( C : in    std_logic; 
             Q : out   std_logic_vector (1 downto 0));
   end component;
   
   component hex2seg
      port ( D : in    std_logic_vector (3 downto 0); 
             S : out   std_logic_vector (6 downto 0));
   end component;
   
   component mux4b_4inU
      port ( D0 : in    std_logic_vector (3 downto 0); 
             D1 : in    std_logic_vector (3 downto 0); 
             D2 : in    std_logic_vector (3 downto 0); 
             D3 : in    std_logic_vector (3 downto 0); 
             A  : in    std_logic_vector (1 downto 0); 
             Q  : out   std_logic_vector (3 downto 0));
   end component;
   
   component demul_w_enable
      port ( enable : in    std_logic; 
             sw     : in    std_logic_vector (3 downto 0); 
             mode   : in    std_logic_vector (1 downto 0); 
             Q0     : out   std_logic_vector (3 downto 0); 
             Q1     : out   std_logic_vector (3 downto 0); 
             Q2     : out   std_logic_vector (3 downto 0); 
             Q3     : out   std_logic_vector (3 downto 0));
   end component;
   
   attribute HU_SET of XLXI_2 : label is "XLXI_2_0";
begin
   XLXI_1 : d2_4_vhd
      port map (X0=>Q(0),
                X1=>Q(1),
                Y0=>XLXN_8,
                Y1=>XLXN_9,
                Y2=>XLXN_10,
                Y3=>XLXN_11);
   
   XLXI_2 : INV4_HXILINX_main
      port map (I0=>XLXN_11,
                I1=>XLXN_10,
                I2=>XLXN_9,
                I3=>XLXN_8,
                O0=>AN(0),
                O1=>AN(1),
                O2=>AN(2),
                O3=>AN(3));
   
   XLXI_3 : divider
      port map (C=>CLK,
                Q(1 downto 0)=>Q(1 downto 0));
   
   XLXI_4 : hex2seg
      port map (D(3 downto 0)=>XLXN_32(3 downto 0),
                S(6 downto 0)=>S(6 downto 0));
   
   XLXI_7 : mux4b_4inU
      port map (A(1 downto 0)=>Q(1 downto 0),
                D0(3 downto 0)=>XLXN_45(3 downto 0),
                D1(3 downto 0)=>XLXN_46(3 downto 0),
                D2(3 downto 0)=>XLXN_47(3 downto 0),
                D3(3 downto 0)=>XLXN_48(3 downto 0),
                Q(3 downto 0)=>XLXN_32(3 downto 0));
   
   XLXI_12 : demul_w_enable
      port map (enable=>enable,
                mode(1 downto 0)=>Mode(1 downto 0),
                sw(3 downto 0)=>sw(3 downto 0),
                Q0(3 downto 0)=>XLXN_45(3 downto 0),
                Q1(3 downto 0)=>XLXN_46(3 downto 0),
                Q2(3 downto 0)=>XLXN_47(3 downto 0),
                Q3(3 downto 0)=>XLXN_48(3 downto 0));
   
end BEHAVIORAL;


