OPENQASM 2.0;
include "qelib1.inc";
qreg q[2];
h q[0];
y q[1];
cx q[1],q[0];
rx(1.8403400748909333) q[1];
x q[0];
cx q[0],q[1];
z q[1];
x q[0];
z q[0];
rx(0.4261369240588795) q[1];
cx q[1],q[0];
cx q[1],q[0];
x q[0];
y q[1];
y q[1];
ry(4.203122242849921) q[0];
z q[0];
z q[1];
cx q[1],q[0];
cx q[1],q[0];
cx q[0],q[1];
