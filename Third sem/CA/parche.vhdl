library ieee;
use ieee.std_logic_1164.all;

entity parcheck_4bit is
port
(
    S: in std_logic_vector(3 downto 0);
    ep, op: out std_logic
);
end parcheck_4bit;

architecture behave_4bit of parcheck_4bit is
begin
    op <= S(3) xor S(2) xor S(1) xor S(0);
    ep <= not (S(3) xor S(2) xor S(1) xor S(0));
end behave_4bit;
