library ieee;
use ieee.std_logic_1164.all;

entity parcheck_tb is
end parcheck_tb;

architecture test of parcheck_tb is
  component parcheck_4bit
    port
    (
      S: in std_logic_vector(3 downto 0);
      ep, op: out std_logic
    );
  end component;
  
  signal ep, op: std_logic;
  signal S: std_logic_vector(3 downto 0); -- Adjusted for 4-bit input
  
begin
  parity_checker: parcheck_4bit port map (S=>S, ep=>ep, op=>op); -- Adjusted for 4-bit parity checker

  process
  begin
    S <= "0000"; -- Adjusted for 4-bit input
    wait for 1 ns;
    S <= "0001"; -- Adjusted for 4-bit input
    wait for 1 ns;
    S <= "0010"; -- Adjusted for 4-bit input
    wait for 1 ns;
    S <= "0011"; -- Adjusted for 4-bit input
    wait for 1 ns;
    S <= "0100"; -- Adjusted for 4-bit input
    wait for 1 ns;
    S <= "0101"; -- Adjusted for 4-bit input
    wait for 1 ns;
    S <= "0110"; -- Adjusted for 4-bit input
    wait for 1 ns;
    S <= "0111"; -- Adjusted for 4-bit input
    wait for 1 ns;
    assert false report "Reached end of test";
    wait;
  end process;
  
end test;
