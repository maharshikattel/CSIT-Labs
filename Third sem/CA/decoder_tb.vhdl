library ieee;
use ieee.std_logic_1164.all;
entity decoder_tb is
end decoder_tb;

architecture test of decoder_tb is
component decoder
port
(
	i: in std_logic_vector(2 downto 0);
	o: out std_logic_vector(7 downto 0)
);
end component;	
signal o: std_logic_vector(7 downto 0);
signal i: std_logic_vector(2 downto 0);
begin
decoder_3x8: decoder port map
(i=>i, o=>o);
process begin
	i <= "000";
	wait for 1 ns;
	i <= "001";
	wait for 1 ns;
	i <= "010";
	wait for 1 ns;
	i <= "011";
	wait for 1 ns;
	i <= "100";
	wait for 1 ns;
	i <= "101";
	wait for 1 ns;
	i <= "110";
	wait for 1 ns;
	i <= "111";
	wait for 1 ns;
	assert false report "Reached end of test";
wait;
end process;
end test;