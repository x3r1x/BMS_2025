--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   15:23:57 01/07/2026
-- Design Name:   
-- Module Name:   /home/x3r1x/Documents/Study/BMS/Programmable/PLD/lab7/lab7.2/main/main_test.vhd
-- Project Name:  main
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: main
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY main_test IS
END main_test;
 
ARCHITECTURE behavior OF main_test IS 
 
    COMPONENT main
    PORT(
         btn1 : IN  std_logic;
         btn2 : IN  std_logic;
         btn3 : IN  std_logic;
         btn4 : IN  std_logic;
         sw : IN  std_logic_vector(7 downto 0);
         led : OUT  std_logic_vector(5 downto 0)
        );
    END COMPONENT;
    

   -- Inputs
   signal btn1 : std_logic := '0';
   signal btn2 : std_logic := '0';
   signal btn3 : std_logic := '0';
   signal btn4 : std_logic := '0';
   signal sw : std_logic_vector(7 downto 0) := (others => '0');

   -- Outputs
   signal led : std_logic_vector(5 downto 0);
 
BEGIN
   -- Instantiate the Unit Under Test (UUT)
   uut: main PORT MAP (
          btn1 => btn1,
          btn2 => btn2,
          btn3 => btn3,
          btn4 => btn4,
          sw => sw,
          led => led
        );

   -- Stimulus processes
   btn1_proc: process
   begin
      btn1 <= '0';
      wait for 100 ns;
      btn1 <= '1';
      wait for 100 ns;
      wait; -- Завершение процесса
   end process;
   
   btn2_proc: process
   begin
      btn2 <= '0';
      wait for 200 ns;
      btn2 <= '1';
      wait for 200 ns;
      wait; -- Завершение процесса
   end process;
   
   -- Добавьте для остальных входов, чтобы избежать неопределенности
   btn3 <= '0'; -- или создайте аналогичный процесс
   btn4 <= '0';
   sw <= "00000000";

   -- Процесс остановки симуляции
   stop_simulation: process
   begin
      wait for 500 ns; -- Время симуляции
      assert false report "Simulation finished" severity failure;
   end process;

END;
