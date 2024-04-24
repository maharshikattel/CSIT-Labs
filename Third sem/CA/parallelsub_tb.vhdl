library ieee;
use ieee.std_logic_1164.all;
entity ps_tb is
end ps_tb;

architecture test of ps_tb is
component ps
port(
	A, B: in std_logic_vector(3 downto 0);
	S: out std_logic_vector(3 downto 0);
	cin: in std_logic;
	cout: out std_logic
);
end component;
signal A, B, S: std_logic_vector(3 downto 0):=(others=>'0');
signal cin: std_logic:='1';
signal cout: std_logic;
begin
parallel_subtractor: ps port map
(A=>A, B=>B, S=>S, cin=>cin, cout=>cout);
process begin
	 A<="0101"; 
	 B<="0100";  
	 wait for 20 ns; 
	 A<="1101"; 
	 B<="0011"; 
	 wait for 20 ns;
	 A<="1000"; 
	 B<="1001"; 
	wait for 20 ns;
	 A<="1000"; 
	 B<="1111"; 
	wait for 20 ns;
	assert false report "Reached end of test";
wait; 
end process; 
end test;