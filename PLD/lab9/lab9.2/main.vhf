--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : main.vhf
-- /___/   /\     Timestamp : 01/11/2026 23:30:27
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan6 -flat -suppress -vhdl /home/x3r1x/Documents/Study/BMS/Programmable/PLD/lab9/lab9.2/main.vhf -w /home/x3r1x/Documents/Study/BMS/Programmable/PLD/lab9/lab9.2/main.sch
--Design Name: main
--Device: spartan6
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesized and simulated, but it should not be modified. 
--

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity rs_nor_MUSER_main is
   port ( R : in    std_logic; 
          S : in    std_logic; 
          Q : out   std_logic);
end rs_nor_MUSER_main;

architecture BEHAVIORAL of rs_nor_MUSER_main is
   attribute BOX_TYPE   : string ;
   signal XLXN_3  : std_logic;
   signal Q_DUMMY : std_logic;
   component NOR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of NOR2 : component is "BLACK_BOX";
   
begin
   Q <= Q_DUMMY;
   XLXI_1 : NOR2
      port map (I0=>XLXN_3,
                I1=>R,
                O=>Q_DUMMY);
   
   XLXI_2 : NOR2
      port map (I0=>S,
                I1=>Q_DUMMY,
                O=>XLXN_3);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity d_trigger_MUSER_main is
   port ( C : in    std_logic; 
          D : in    std_logic; 
          Q : out   std_logic);
end d_trigger_MUSER_main;

architecture BEHAVIORAL of d_trigger_MUSER_main is
   attribute BOX_TYPE   : string ;
   signal XLXN_3 : std_logic;
   signal XLXN_5 : std_logic;
   signal XLXN_7 : std_logic;
   component rs_nor_MUSER_main
      port ( R : in    std_logic; 
             S : in    std_logic; 
             Q : out   std_logic);
   end component;
   
   component AND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND2 : component is "BLACK_BOX";
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
begin
   XLXI_1 : rs_nor_MUSER_main
      port map (R=>XLXN_7,
                S=>XLXN_5,
                Q=>Q);
   
   XLXI_2 : AND2
      port map (I0=>C,
                I1=>D,
                O=>XLXN_5);
   
   XLXI_3 : AND2
      port map (I0=>XLXN_3,
                I1=>C,
                O=>XLXN_7);
   
   XLXI_5 : INV
      port map (I=>D,
                O=>XLXN_3);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity main is
   port ( D    : in    std_logic; 
          D_C  : in    std_logic; 
          J    : in    std_logic; 
          JK_C : in    std_logic; 
          K    : in    std_logic; 
          T    : in    std_logic; 
          D_Q  : out   std_logic; 
          JK_Q : out   std_logic; 
          T_Q  : out   std_logic);
end main;

architecture BEHAVIORAL of main is
   component d_trigger_MUSER_main
      port ( D : in    std_logic; 
             C : in    std_logic; 
             Q : out   std_logic);
   end component;
   
   component t_trig
      port ( T : in    std_logic; 
             Q : out   std_logic);
   end component;
   
   component default_jk_trigger
      port ( j : in    std_logic; 
             c : in    std_logic; 
             k : in    std_logic; 
             q : out   std_logic);
   end component;
   
begin
   XLXI_9 : d_trigger_MUSER_main
      port map (C=>D_C,
                D=>D,
                Q=>D_Q);
   
   XLXI_10 : t_trig
      port map (T=>T,
                Q=>T_Q);
   
   XLXI_11 : default_jk_trigger
      port map (c=>JK_C,
                j=>J,
                k=>K,
                q=>JK_Q);
   
end BEHAVIORAL;


