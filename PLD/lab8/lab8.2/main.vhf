--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : main.vhf
-- /___/   /\     Timestamp : 01/11/2026 18:19:56
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan6 -flat -suppress -vhdl /home/x3r1x/Documents/Study/BMS/Programmable/PLD/lab8/lab8.2/main.vhf -w /home/x3r1x/Documents/Study/BMS/Programmable/PLD/lab8/lab8.2/main.sch
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
   port ( A   : in    std_logic_vector (1 downto 0); 
          sw  : in    std_logic_vector (3 downto 0); 
          AN  : out   std_logic_vector (3 downto 0); 
          seg : out   std_logic_vector (6 downto 0));
end main;

architecture BEHAVIORAL of main is
   attribute HU_SET     : string ;
   signal XLXN_13 : std_logic;
   signal XLXN_14 : std_logic;
   signal XLXN_15 : std_logic;
   signal XLXN_16 : std_logic;
   component hex2seg
      port ( D : in    std_logic_vector (3 downto 0); 
             S : out   std_logic_vector (6 downto 0));
   end component;
   
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
   
   attribute HU_SET of XLXI_4 : label is "XLXI_4_0";
begin
   XLXI_1 : hex2seg
      port map (D(3 downto 0)=>sw(3 downto 0),
                S(6 downto 0)=>seg(6 downto 0));
   
   XLXI_2 : d2_4_vhd
      port map (X0=>A(0),
                X1=>A(1),
                Y0=>XLXN_13,
                Y1=>XLXN_14,
                Y2=>XLXN_15,
                Y3=>XLXN_16);
   
   XLXI_4 : INV4_HXILINX_main
      port map (I0=>XLXN_16,
                I1=>XLXN_15,
                I2=>XLXN_14,
                I3=>XLXN_13,
                O0=>AN(3),
                O1=>AN(2),
                O2=>AN(1),
                O3=>AN(0));
   
end BEHAVIORAL;


