library ieee;
use ieee.std_logic_1164.all;
entity encoder_tb is
end encoder_tb;

architecture test of encoder_tb is
component encoder
port
(
	i: in std_logic_vector(7 downto 0);
	o: out std_logic_vector(2 downto 0)
);
end component;	
signal o: std_logic_vector(2 downto 0);
signal i: std_logic_vector(7 downto 0);
begin
encoder_8x3: encoder port map
(o=>o, i=>i);
process begin
	i <= "00000001";
	wait for 1 ns;
	i <= "00000010";
	wait for 1 ns;
	i <= "00000100";
	wait for 1 ns;
	i <= "00001000";
	wait for 1 ns;
	i <= "00010000";
	wait for 1 ns;
	i <= "00100000";
	wait for 1 ns;
	i <= "01000000";
	wait for 1 ns;
	i <= "10000000";
	wait for 1 ns;
	assert false report "Reached end of test";
wait;
end process;
end test;