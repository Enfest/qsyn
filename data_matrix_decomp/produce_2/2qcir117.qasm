OPENQASM 2.0;
include "qelib1.inc";
qreg q[2];
cx q[1],q[0];
cx q[0],q[1];
cx q[0],q[1];
cx q[1],q[0];
z q[0];
h q[1];
cx q[0],q[1];
cx q[1],q[0];
rx(5.725865613987582) q[0];
rz(2.7263504295017724) q[1];
cx q[1],q[0];
z q[1];
rz(4.849447826552127) q[0];
cx q[0],q[1];
cx q[0],q[1];
x q[0];
x q[1];
cx q[0],q[1];
cx q[0],q[1];
cx q[1],q[0];
y q[0];
ry(5.791981861320499) q[1];
x q[1];
y q[0];
cx q[1],q[0];
cx q[0],q[1];
ry(4.575651039623656) q[1];
x q[0];
ry(1.1018210907404438) q[0];
ry(2.5299090813194662) q[1];
cx q[1],q[0];
x q[0];
x q[1];
cx q[1],q[0];
ry(5.625804124528125) q[0];
z q[1];
cx q[0],q[1];
cx q[0],q[1];
rz(1.1697169978877673) q[0];
x q[1];
z q[0];
rx(4.162213593743887) q[1];
z q[1];
ry(3.4405190096202727) q[0];
z q[1];
y q[0];
y q[1];
y q[0];
y q[0];
y q[1];
cx q[0],q[1];
cx q[0],q[1];
cx q[1],q[0];
cx q[0],q[1];
z q[1];
x q[0];
cx q[0],q[1];
cx q[0],q[1];
y q[1];
x q[0];
ry(5.46545026557498) q[0];
ry(1.4205743858172153) q[1];
h q[1];
x q[0];
cx q[1],q[0];
cx q[0],q[1];
ry(4.5011300619175465) q[1];
rz(3.901147276367229) q[0];
cx q[1],q[0];
cx q[1],q[0];
cx q[0],q[1];
cx q[0],q[1];
cx q[1],q[0];
cx q[0],q[1];
rz(5.14351212306175) q[1];
ry(3.9797951993626293) q[0];
rx(5.271045351471108) q[1];
h q[0];
cx q[1],q[0];
ry(4.374735863335387) q[1];
rz(6.1194250677333) q[0];
cx q[1],q[0];
cx q[0],q[1];
z q[0];
z q[1];
ry(5.406267020973546) q[0];
x q[1];
cx q[0],q[1];
x q[1];
rz(3.1894438995725958) q[0];
h q[1];
z q[0];
x q[0];
x q[1];
cx q[0],q[1];
h q[0];
ry(0.9758224489435131) q[1];
x q[1];
rz(0.9387451470858332) q[0];
cx q[1],q[0];
y q[1];
z q[0];
cx q[1],q[0];
h q[1];
h q[0];
z q[1];
h q[0];
cx q[1],q[0];
cx q[0],q[1];
x q[1];
h q[0];
rx(4.349221710226955) q[0];
x q[1];
y q[1];
x q[0];
cx q[0],q[1];
cx q[1],q[0];
cx q[0],q[1];
y q[1];
ry(0.532483162672736) q[0];
cx q[0],q[1];
cx q[0],q[1];
cx q[0],q[1];
y q[1];
h q[0];
cx q[1],q[0];
y q[0];
ry(4.651276957134135) q[1];
x q[0];
y q[1];
cx q[1],q[0];
cx q[0],q[1];
cx q[1],q[0];
rx(0.28659648203579074) q[1];
ry(3.0640503976396456) q[0];
cx q[0],q[1];
cx q[0],q[1];
y q[1];
rz(1.0982132651644259) q[0];
cx q[0],q[1];
