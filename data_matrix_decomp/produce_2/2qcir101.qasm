OPENQASM 2.0;
include "qelib1.inc";
qreg q[2];
cx q[0],q[1];
cx q[1],q[0];
cx q[0],q[1];
cx q[1],q[0];
cx q[1],q[0];
cx q[0],q[1];
cx q[0],q[1];
h q[0];
y q[1];
cx q[1],q[0];
cx q[0],q[1];
cx q[1],q[0];
h q[0];
x q[1];
cx q[1],q[0];
rz(0.2234248611811473) q[0];
rz(6.251931072980382) q[1];
cx q[1],q[0];
rx(2.170394962620342) q[0];
ry(4.348790701596607) q[1];
cx q[1],q[0];
y q[0];
x q[1];
z q[0];
h q[1];
ry(0.3890102725296209) q[0];
ry(0.0684669004343715) q[1];
z q[0];
h q[1];
cx q[1],q[0];
cx q[1],q[0];
x q[0];
rx(3.534686932275583) q[1];
z q[1];
ry(1.6475371691390825) q[0];
cx q[0],q[1];
h q[1];
z q[0];
y q[0];
x q[1];
cx q[0],q[1];
cx q[0],q[1];
rz(1.748922815575624) q[0];
rx(3.7446790519457345) q[1];
rz(4.694187777467351) q[0];
rz(4.242448978755589) q[1];
rx(5.613411455362593) q[0];
y q[1];
cx q[0],q[1];
y q[0];
rz(4.5745619289023605) q[1];
rz(3.1299350911114283) q[1];
h q[0];
cx q[1],q[0];
cx q[0],q[1];
cx q[0],q[1];
y q[1];
z q[0];
h q[0];
h q[1];
y q[0];
y q[1];
cx q[0],q[1];
cx q[0],q[1];
cx q[1],q[0];
cx q[1],q[0];
y q[0];
z q[1];
cx q[0],q[1];
y q[1];
h q[0];
h q[0];
y q[1];
ry(5.6630894873212645) q[0];
rx(2.0499777255178895) q[1];
ry(3.4102122486370976) q[0];
y q[1];
cx q[1],q[0];
ry(0.9731108586783892) q[1];
x q[0];
x q[0];
rx(1.9572783031159897) q[1];
cx q[1],q[0];
z q[1];
rx(5.702647663349466) q[0];
y q[0];
rz(1.4063585005580077) q[1];
cx q[0],q[1];
z q[0];
ry(2.6868331382383563) q[1];
cx q[1],q[0];
y q[1];
z q[0];
cx q[1],q[0];
cx q[1],q[0];
rz(2.741637853805599) q[0];
y q[1];
cx q[1],q[0];
cx q[1],q[0];
cx q[0],q[1];
rz(3.9910979641013604) q[1];
x q[0];
y q[0];
x q[1];
rz(3.906744926811851) q[1];
ry(6.2307665834571795) q[0];
ry(4.024106338410973) q[1];
rx(4.123093965846852) q[0];
cx q[1],q[0];
cx q[1],q[0];
cx q[1],q[0];
h q[0];
x q[1];
ry(3.1324161415209337) q[0];
h q[1];
rz(4.346801333108909) q[0];
x q[1];
cx q[0],q[1];
rx(3.348134982667038) q[0];
h q[1];
ry(3.8015400769849856) q[0];
rx(2.8988638314699426) q[1];
x q[1];
x q[0];
x q[1];
y q[0];
z q[1];
x q[0];
ry(2.0295289851588056) q[0];
rx(2.9695295690910055) q[1];
rx(1.5189254588898238) q[1];
rx(0.8138890157340576) q[0];
cx q[0],q[1];
ry(5.245689973675338) q[0];
x q[1];
ry(2.752214671232063) q[0];
rx(2.6104488926740013) q[1];
ry(6.039114811224995) q[0];
h q[1];
ry(5.518747124132985) q[1];
rz(2.5143367858980477) q[0];
cx q[0],q[1];
h q[0];
x q[1];
cx q[1],q[0];
cx q[0],q[1];
rz(5.822229912149427) q[1];
y q[0];
cx q[1],q[0];
cx q[0],q[1];
cx q[0],q[1];
cx q[0],q[1];
cx q[0],q[1];
