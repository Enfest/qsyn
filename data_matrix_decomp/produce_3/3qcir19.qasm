OPENQASM 2.0;
include "qelib1.inc";
qreg q[3];
y q[2];
cx q[0],q[1];
cx q[2],q[1];
ry(2.0704832927437007) q[0];
rz(3.8168401948711246) q[2];
rx(1.9848461161356437) q[0];
h q[1];
