library ieee;
use ieee.std_logic_1164.all;
entity encoder is
port
(
	i: in std_logic_vector(7 downto 0);
	o: out std_logic_vector(2 downto 0)
);
end encoder;

architecture behave of encoder is
begin
process(i) begin
o(0) <= i(4) or i(5) or i(6) or i(7);
o(1) <= i(2) or i(3) or i(6) or i(7);
o(2) <= i(1) or i(3) or i(5) or i(7);
end process;
end behave;