LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
ENTITY alu_tb IS
END alu_tb;
ARCHITECTURE behavior OF alu_tb IS

COMPONENT alu
PORT(
inp_a : IN signed(3 downto 0);
inp_b : IN signed(3 downto 0);
sel : IN std_logic_vector(2 downto 0);
out_alu : OUT signed(3 downto 0)
);
END COMPONENT;

signal inp_a : signed(3 downto 0) := (others => '0');
signal inp_b : signed(3 downto 0) := (others => '0');
signal sel : std_logic_vector(2 downto 0) := (others => '0');

signal out_alu : signed(3 downto 0);

BEGIN
uut: alu PORT MAP (
inp_a => inp_a,
inp_b => inp_b,
sel => sel,
out_alu => out_alu
);

stim_proc: process
begin
wait for 100 ns;
inp_a <= "1001";
inp_b <= "1111";
sel <= "000";
wait for 100 ns;
sel <= "001";
wait for 100 ns;
sel <= "010";
wait for 100 ns;
sel <= "011";
wait for 100 ns;
sel <= "100";
wait for 100 ns;
sel <= "101";
wait for 100 ns;
sel <= "110";
wait for 100 ns;
sel <= "111";
wait;
assert false report "Reached end of test";
end process;
END;