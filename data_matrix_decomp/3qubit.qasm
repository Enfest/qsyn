OPENQASM 2.0;
include "qelib1.inc";
qreg q[3];
rz(-1.5707963267948968) q[0];
cx q[2], q[0];
ry(-0.7853981633974485) q[0];
cx q[2], q[0];
ry(0.7853981633974485) q[0];
rz(1.5707963267948968) q[0];
cx q[1], q[2];
rz(1.5707963267948966) q[0];
cx q[2], q[0];
ry(-0.7853981633974485) q[0];
cx q[2], q[0];
ry(0.7853981633974485) q[0];
rz(-1.5707963267948966) q[0];
cx q[1], q[2];
rz(-1.5707963267948968) q[0];
cx q[1], q[0];
ry(-0.7853981633974485) q[0];
cx q[1], q[0];
ry(0.7853981633974485) q[0];
rz(1.5707963267948968) q[0];
rz(-2.019595277307724) q[1];
cx q[2], q[1];
ry(-0.7489443778164518) q[1];
cx q[2], q[1];
ry(0.7489443778164518) q[1];
rz(2.019595277307724) q[1];
cx q[0], q[2];
rz(1.121997376282069) q[1];
cx q[2], q[1];
ry(-0.7489443778164518) q[1];
cx q[2], q[1];
ry(0.7489443778164518) q[1];
rz(-1.121997376282069) q[1];
cx q[0], q[2];
rz(-2.019595277307724) q[1];
cx q[0], q[1];
ry(-0.7489443778164518) q[1];
cx q[0], q[1];
ry(0.7489443778164518) q[1];
rz(2.019595277307724) q[1];
cx q[1], q[0];
rz(1.121997376282069) q[1];
cx q[2], q[1];
ry(-0.7853981633974484) q[1];
cx q[2], q[1];
ry(0.7853981633974484) q[1];
rz(-1.1219973762820692) q[1];
cx q[0], q[2];
rz(-2.019595277307724) q[1];
cx q[2], q[1];
ry(-0.7853981633974484) q[1];
cx q[2], q[1];
ry(0.7853981633974484) q[1];
rz(2.019595277307724) q[1];
cx q[0], q[2];
rz(1.121997376282069) q[1];
cx q[0], q[1];
ry(-0.7853981633974484) q[1];
cx q[0], q[1];
ry(0.7853981633974484) q[1];
rz(-1.1219973762820692) q[1];
cx q[1], q[0];
x q[0];
cx q[0], q[1];
x q[0];
cx q[0], q[1];
rz(1.121997376282069) q[0];
cx q[2], q[0];
rz(0.29295208262339273) q[0];
ry(-0.6453824733543831) q[0];
cx q[2], q[0];
ry(0.6453824733543831) q[0];
rz(-1.4149494589054616) q[0];
cx q[1], q[2];
rz(-2.019595277307724) q[0];
cx q[2], q[0];
rz(-0.29295208262339256) q[0];
ry(-0.6453824733543831) q[0];
cx q[2], q[0];
ry(0.6453824733543831) q[0];
rz(2.312547359931117) q[0];
cx q[1], q[2];
rz(1.121997376282069) q[0];
cx q[1], q[0];
rz(0.29295208262339273) q[0];
ry(-0.6453824733543831) q[0];
cx q[1], q[0];
ry(0.6453824733543831) q[0];
rz(-1.4149494589054616) q[0];
cx q[0], q[1];
x q[0];
cx q[0], q[1];
x q[0];
cx q[2], q[1];
rz(1.121997376282069) q[2];
cx q[0], q[2];
ry(-0.5738954161010008) q[2];
cx q[0], q[2];
ry(0.5738954161010008) q[2];
rz(-1.121997376282069) q[2];
cx q[1], q[0];
rz(-2.019595277307724) q[2];
cx q[0], q[2];
ry(-0.5738954161010008) q[2];
cx q[0], q[2];
ry(0.5738954161010008) q[2];
rz(2.019595277307724) q[2];
cx q[1], q[0];
rz(1.121997376282069) q[2];
cx q[1], q[2];
ry(-0.5738954161010008) q[2];
cx q[1], q[2];
ry(0.5738954161010008) q[2];
rz(-1.121997376282069) q[2];
cx q[2], q[1];
cx q[2], q[0];
cx q[2], q[1];
rz(-2.0195952773077246) q[2];
cx q[0], q[2];
rz(0.4221874544371157) q[2];
ry(-0.8431178496609125) q[2];
cx q[0], q[2];
ry(0.8431178496609125) q[2];
rz(1.5974078228706088) q[2];
cx q[1], q[0];
rz(1.121997376282069) q[2];
cx q[0], q[2];
rz(-0.4221874544371156) q[2];
ry(-0.8431178496609125) q[2];
cx q[0], q[2];
ry(0.8431178496609125) q[2];
rz(-0.6998099218449534) q[2];
cx q[1], q[0];
rz(-2.0195952773077246) q[2];
cx q[1], q[2];
rz(0.4221874544371157) q[2];
ry(-0.8431178496609125) q[2];
cx q[1], q[2];
ry(0.8431178496609125) q[2];
rz(1.5974078228706088) q[2];
cx q[2], q[1];
cx q[2], q[0];
x q[0];
cx q[0], q[2];
x q[0];
rz(-2.019595277307724) q[0];
cx q[2], q[0];
ry(-0.19587973679679996) q[0];
cx q[2], q[0];
ry(0.19587973679679996) q[0];
rz(2.019595277307724) q[0];
cx q[1], q[2];
rz(1.121997376282069) q[0];
cx q[2], q[0];
ry(-0.19587973679679996) q[0];
cx q[2], q[0];
ry(0.19587973679679996) q[0];
rz(-1.121997376282069) q[0];
cx q[1], q[2];
rz(-2.019595277307724) q[0];
cx q[1], q[0];
ry(-0.19587973679679996) q[0];
cx q[1], q[0];
ry(0.19587973679679996) q[0];
rz(2.019595277307724) q[0];
x q[0];
cx q[0], q[2];
x q[0];
x q[2];
cx q[2], q[0];
x q[2];
cx q[2], q[0];
rz(-2.019595277307724) q[2];
cx q[0], q[2];
ry(-0.6908953146452325) q[2];
cx q[0], q[2];
ry(0.6908953146452325) q[2];
rz(2.019595277307724) q[2];
cx q[1], q[0];
rz(1.121997376282069) q[2];
cx q[0], q[2];
ry(-0.6908953146452325) q[2];
cx q[0], q[2];
ry(0.6908953146452325) q[2];
rz(-1.121997376282069) q[2];
cx q[1], q[0];
rz(-2.019595277307724) q[2];
cx q[1], q[2];
ry(-0.6908953146452325) q[2];
cx q[1], q[2];
ry(0.6908953146452325) q[2];
rz(2.019595277307724) q[2];
cx q[2], q[0];
x q[2];
cx q[2], q[0];
x q[2];
x q[0];
cx q[0], q[2];
x q[0];
cx q[0], q[1];
cx q[1], q[2];
cx q[1], q[2];
cx q[0], q[1];
x q[0];
cx q[0], q[2];
x q[0];
x q[2];
cx q[2], q[0];
x q[2];
cx q[2], q[0];
cx q[2], q[1];
cx q[1], q[0];
cx q[1], q[0];
cx q[2], q[1];
cx q[2], q[0];
x q[2];
cx q[2], q[0];
x q[2];
x q[0];
cx q[0], q[2];
x q[0];
cx q[0], q[2];
rz(1.570796326794897) q[0];
cx q[2], q[0];
ry(-0.7853981633974484) q[0];
cx q[2], q[0];
ry(0.7853981633974484) q[0];
rz(-1.570796326794897) q[0];
cx q[1], q[2];
rz(-1.5707963267948966) q[0];
cx q[2], q[0];
ry(-0.7853981633974484) q[0];
cx q[2], q[0];
ry(0.7853981633974484) q[0];
rz(1.5707963267948966) q[0];
cx q[1], q[2];
rz(1.570796326794897) q[0];
cx q[1], q[0];
ry(-0.7853981633974484) q[0];
cx q[1], q[0];
ry(0.7853981633974484) q[0];
rz(-1.570796326794897) q[0];
cx q[0], q[2];
x q[0];
cx q[0], q[2];
x q[0];
x q[1];
cx q[1], q[2];
x q[1];
rz(-1.5707963267948966) q[1];
cx q[2], q[1];
ry(-0.08056313874806367) q[1];
cx q[2], q[1];
ry(0.08056313874806367) q[1];
rz(1.5707963267948966) q[1];
cx q[0], q[2];
rz(1.5707963267948968) q[1];
cx q[2], q[1];
ry(-0.08056313874806367) q[1];
cx q[2], q[1];
ry(0.08056313874806367) q[1];
rz(-1.5707963267948968) q[1];
cx q[0], q[2];
rz(-1.5707963267948966) q[1];
cx q[0], q[1];
ry(-0.08056313874806367) q[1];
cx q[0], q[1];
ry(0.08056313874806367) q[1];
rz(1.5707963267948966) q[1];
x q[1];
cx q[1], q[2];
x q[1];
x q[1];
cx q[1], q[2];
x q[1];
cx q[1], q[0];
rz(1.5707963267948968) q[1];
cx q[2], q[1];
ry(-0.033687640160020675) q[1];
cx q[2], q[1];
ry(0.033687640160020675) q[1];
rz(-1.5707963267948968) q[1];
cx q[0], q[2];
rz(-1.5707963267948966) q[1];
cx q[2], q[1];
ry(-0.033687640160020675) q[1];
cx q[2], q[1];
ry(0.033687640160020675) q[1];
rz(1.5707963267948966) q[1];
cx q[0], q[2];
rz(1.5707963267948968) q[1];
cx q[0], q[1];
ry(-0.033687640160020675) q[1];
cx q[0], q[1];
ry(0.033687640160020675) q[1];
rz(-1.5707963267948968) q[1];
cx q[1], q[0];
x q[1];
cx q[1], q[2];
x q[1];
x q[2];
cx q[2], q[1];
x q[2];
cx q[2], q[1];
cx q[1], q[0];
cx q[1], q[0];
cx q[2], q[1];
x q[2];
cx q[2], q[1];
x q[2];
x q[2];
cx q[2], q[1];
x q[2];
cx q[2], q[0];
cx q[2], q[1];
cx q[1], q[0];
cx q[1], q[0];
cx q[2], q[1];
cx q[2], q[0];
x q[2];
cx q[2], q[1];
x q[2];
x q[1];
cx q[1], q[2];
x q[1];
cx q[1], q[2];
rz(-1.1219973762820692) q[1];
cx q[2], q[1];
ry(-0.5890486225480862) q[1];
cx q[2], q[1];
ry(0.5890486225480862) q[1];
rz(1.1219973762820692) q[1];
cx q[0], q[2];
rz(2.019595277307724) q[1];
cx q[2], q[1];
ry(-0.5890486225480862) q[1];
cx q[2], q[1];
ry(0.5890486225480862) q[1];
rz(-2.019595277307724) q[1];
cx q[0], q[2];
rz(-1.1219973762820692) q[1];
cx q[0], q[1];
ry(-0.5890486225480862) q[1];
cx q[0], q[1];
ry(0.5890486225480862) q[1];
rz(1.1219973762820692) q[1];
cx q[1], q[2];
x q[1];
cx q[1], q[2];
x q[1];
x q[1];
cx q[1], q[2];
x q[1];
cx q[1], q[0];
cx q[1], q[2];
rz(2.019595277307724) q[1];
cx q[2], q[1];
ry(-0.7853981633974484) q[1];
cx q[2], q[1];
ry(0.7853981633974484) q[1];
rz(-2.0195952773077237) q[1];
cx q[0], q[2];
rz(-1.1219973762820692) q[1];
cx q[2], q[1];
ry(-0.7853981633974484) q[1];
cx q[2], q[1];
ry(0.7853981633974484) q[1];
rz(1.1219973762820692) q[1];
cx q[0], q[2];
rz(2.019595277307724) q[1];
cx q[0], q[1];
ry(-0.7853981633974484) q[1];
cx q[0], q[1];
ry(0.7853981633974484) q[1];
rz(-2.0195952773077237) q[1];
cx q[1], q[2];
cx q[1], q[0];
x q[1];
cx q[1], q[2];
x q[1];
x q[0];
cx q[0], q[1];
cx q[0], q[2];
x q[0];
cx q[0], q[1];
rz(1.5707963267948968) q[0];
cx q[2], q[0];
ry(-0.03325064296520533) q[0];
cx q[2], q[0];
ry(0.03325064296520533) q[0];
rz(-1.5707963267948968) q[0];
cx q[1], q[2];
rz(-1.5707963267948966) q[0];
cx q[2], q[0];
ry(-0.03325064296520533) q[0];
cx q[2], q[0];
ry(0.03325064296520533) q[0];
rz(1.5707963267948966) q[0];
cx q[1], q[2];
rz(1.5707963267948968) q[0];
cx q[1], q[0];
ry(-0.03325064296520533) q[0];
cx q[1], q[0];
ry(0.03325064296520533) q[0];
rz(-1.5707963267948968) q[0];
cx q[0], q[1];
x q[0];
cx q[0], q[2];
cx q[0], q[1];
x q[0];
x q[2];
cx q[2], q[0];
cx q[2], q[1];
x q[2];
cx q[2], q[0];
cx q[2], q[1];
rz(1.5707963267948966) q[2];
cx q[0], q[2];
ry(-0.08074317560637724) q[2];
cx q[0], q[2];
ry(0.08074317560637724) q[2];
rz(-1.5707963267948966) q[2];
cx q[1], q[0];
rz(-1.5707963267948966) q[2];
cx q[0], q[2];
ry(-0.08074317560637724) q[2];
cx q[0], q[2];
ry(0.08074317560637724) q[2];
rz(1.5707963267948966) q[2];
cx q[1], q[0];
rz(1.5707963267948966) q[2];
cx q[1], q[2];
ry(-0.08074317560637724) q[2];
cx q[1], q[2];
ry(0.08074317560637724) q[2];
rz(-1.5707963267948966) q[2];
cx q[2], q[1];
cx q[2], q[0];
x q[2];
cx q[2], q[1];
cx q[2], q[0];
x q[2];
x q[0];
cx q[0], q[1];
cx q[0], q[2];
x q[0];
cx q[0], q[2];
cx q[1], q[2];
cx q[1], q[2];
cx q[0], q[2];
x q[0];
cx q[0], q[2];
cx q[0], q[1];
x q[0];
x q[1];
cx q[1], q[0];
cx q[1], q[2];
x q[1];
cx q[1], q[0];
cx q[1], q[2];
cx q[0], q[2];
cx q[0], q[2];
cx q[1], q[2];
cx q[1], q[0];
x q[1];
cx q[1], q[2];
cx q[1], q[0];
x q[1];
x q[0];
cx q[0], q[1];
cx q[0], q[2];
x q[0];
cx q[0], q[1];
cx q[0], q[2];
rz(2.019595277307724) q[0];
cx q[2], q[0];
rz(-0.9469115327628965) q[0];
ry(-0.357133597762668) q[0];
cx q[2], q[0];
ry(0.357133597762668) q[0];
rz(-1.0726837445448276) q[0];
cx q[1], q[2];
rz(-1.121997376282069) q[0];
cx q[2], q[0];
rz(0.9469115327628965) q[0];
ry(-0.357133597762668) q[0];
cx q[2], q[0];
ry(0.357133597762668) q[0];
rz(0.17508584351917245) q[0];
cx q[1], q[2];
rz(2.019595277307724) q[0];
cx q[1], q[0];
rz(-0.9469115327628965) q[0];
ry(-0.357133597762668) q[0];
cx q[1], q[0];
ry(0.357133597762668) q[0];
rz(-1.0726837445448276) q[0];
cx q[0], q[2];
cx q[0], q[1];
x q[0];
cx q[0], q[2];
cx q[0], q[1];
x q[0];
