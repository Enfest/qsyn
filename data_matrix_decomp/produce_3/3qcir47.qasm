OPENQASM 2.0;
include "qelib1.inc";
qreg q[3];
y q[1];
cx q[2],q[0];
h q[0];
z q[2];
z q[1];
h q[1];
y q[2];
x q[0];
rz(4.304352779384629) q[2];
cx q[1],q[0];
h q[2];
ry(1.2382934446168208) q[0];
h q[1];
cx q[0],q[1];
y q[2];
z q[1];
cx q[2],q[0];
ry(1.9265140421029763) q[2];
y q[1];
rx(3.475981171881824) q[0];
z q[2];
cx q[1],q[0];
cx q[1],q[0];
y q[2];
y q[0];
cx q[1],q[2];
z q[0];
cx q[1],q[2];
cx q[1],q[0];
z q[2];
cx q[0],q[1];
rx(5.599987527780178) q[2];
cx q[2],q[0];
ry(3.6694002607667673) q[1];
cx q[1],q[0];
y q[2];
h q[1];
rx(2.537530510128941) q[0];
z q[2];
cx q[2],q[0];
rz(4.865849569648717) q[1];
x q[0];
cx q[1],q[2];
ry(5.1312468709391545) q[2];
cx q[1],q[0];
y q[1];
cx q[0],q[2];
ry(6.175047415728594) q[2];
cx q[1],q[0];
rx(1.4336861801590235) q[2];
cx q[0],q[1];
cx q[0],q[1];
z q[2];
cx q[0],q[1];
y q[2];
cx q[1],q[2];
rz(3.99158266160997) q[0];
x q[0];
cx q[2],q[1];
x q[1];
cx q[0],q[2];
x q[0];
cx q[2],q[1];
