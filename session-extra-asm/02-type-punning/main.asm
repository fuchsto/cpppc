
main.g.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <main>:
//       production-ready implementations!
//       In particular, consider pointer aliasing:
//       http://cellperformance.beyond3d.com/articles/2006/06/understanding-strict-aliasing.html

int main(int argc, char * argv[])
{
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 40          	sub    rsp,0x40
   8:	89 7d cc             	mov    DWORD PTR [rbp-0x34],edi
   b:	48 89 75 c0          	mov    QWORD PTR [rbp-0x40],rsi
  wno_unused_(argc);
  wno_unused_(argv);

  cout << "  Hank the Hacker claims that type punning is best done" << endl
   f:	be 00 00 00 00       	mov    esi,0x0
  14:	bf 00 00 00 00       	mov    edi,0x0
  19:	e8 00 00 00 00       	call   1e <main+0x1e>
  1e:	be 00 00 00 00       	mov    esi,0x0
  23:	48 89 c7             	mov    rdi,rax
  26:	e8 00 00 00 00       	call   2b <main+0x2b>
       << "  using reinterpret_cast in C++11 because compilers" << endl
  2b:	be 00 00 00 00       	mov    esi,0x0
  30:	48 89 c7             	mov    rdi,rax
  33:	e8 00 00 00 00       	call   38 <main+0x38>
  38:	be 00 00 00 00       	mov    esi,0x0
  3d:	48 89 c7             	mov    rdi,rax
  40:	e8 00 00 00 00       	call   45 <main+0x45>
       << "  are clever and better than us." << endl
  45:	be 00 00 00 00       	mov    esi,0x0
  4a:	48 89 c7             	mov    rdi,rax
  4d:	e8 00 00 00 00       	call   52 <main+0x52>
  52:	be 00 00 00 00       	mov    esi,0x0
  57:	48 89 c7             	mov    rdi,rax
  5a:	e8 00 00 00 00       	call   5f <main+0x5f>
       << "  Bob the Bullshitter objects that it has some overhead" << endl
  5f:	be 00 00 00 00       	mov    esi,0x0
  64:	48 89 c7             	mov    rdi,rax
  67:	e8 00 00 00 00       	call   6c <main+0x6c>
  6c:	be 00 00 00 00       	mov    esi,0x0
  71:	48 89 c7             	mov    rdi,rax
  74:	e8 00 00 00 00       	call   79 <main+0x79>
       << "  compared to a C-style-cast and memcpy, C being low-level" << endl
  79:	be 00 00 00 00       	mov    esi,0x0
  7e:	48 89 c7             	mov    rdi,rax
  81:	e8 00 00 00 00       	call   86 <main+0x86>
  86:	be 00 00 00 00       	mov    esi,0x0
  8b:	48 89 c7             	mov    rdi,rax
  8e:	e8 00 00 00 00       	call   93 <main+0x93>
       << "  and all and easier for compilers to optimize." << endl
  93:	be 00 00 00 00       	mov    esi,0x0
  98:	48 89 c7             	mov    rdi,rax
  9b:	e8 00 00 00 00       	call   a0 <main+0xa0>
  a0:	be 00 00 00 00       	mov    esi,0x0
  a5:	48 89 c7             	mov    rdi,rax
  a8:	e8 00 00 00 00       	call   ad <main+0xad>
       << "  Is Bob right?" << endl
  ad:	be 00 00 00 00       	mov    esi,0x0
  b2:	48 89 c7             	mov    rdi,rax
  b5:	e8 00 00 00 00       	call   ba <main+0xba>
  ba:	be 00 00 00 00       	mov    esi,0x0
  bf:	48 89 c7             	mov    rdi,rax
  c2:	e8 00 00 00 00       	call   c7 <main+0xc7>
       << endl;
  c7:	be 00 00 00 00       	mov    esi,0x0
  cc:	48 89 c7             	mov    rdi,rax
  cf:	e8 00 00 00 00       	call   d4 <main+0xd4>


  double double_value    = 1.0e+2;
  d4:	f2 0f 10 05 00 00 00 	movsd  xmm0,QWORD PTR [rip+0x0]        # dc <main+0xdc>
  db:	00 
  dc:	f2 0f 11 45 e0       	movsd  QWORD PTR [rbp-0x20],xmm0
  pun_t  punned_value_mc = 0;
  e1:	48 c7 45 d8 00 00 00 	mov    QWORD PTR [rbp-0x28],0x0
  e8:	00 
  pun_t  punned_value_rc = 0;
  e9:	48 c7 45 f8 00 00 00 	mov    QWORD PTR [rbp-0x8],0x0
  f0:	00 

  // BEGIN MEMCPY VARIANT {
  double * punned_dest_mc = (double *)(&punned_value_mc);
  f1:	48 8d 45 d8          	lea    rax,[rbp-0x28]
  f5:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
  memcpy(punned_dest_mc,
         &double_value,
         sizeof(double));
  f9:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
  fd:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
 101:	48 89 10             	mov    QWORD PTR [rax],rdx
  // } END MEMCPY VARIANT

  cout << "Using memcpy:            ";
 104:	be 00 00 00 00       	mov    esi,0x0
 109:	bf 00 00 00 00       	mov    edi,0x0
 10e:	e8 00 00 00 00       	call   113 <main+0x113>
  cout << punned_value_mc << endl;
 113:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
 117:	48 89 c6             	mov    rsi,rax
 11a:	bf 00 00 00 00       	mov    edi,0x0
 11f:	e8 00 00 00 00       	call   124 <main+0x124>
 124:	be 00 00 00 00       	mov    esi,0x0
 129:	48 89 c7             	mov    rdi,rax
 12c:	e8 00 00 00 00       	call   131 <main+0x131>

  // BEGIN REINTERPRET_CAST VARIANT {
  pun_t  * punned_dest_rc = reinterpret_cast<pun_t *>(&double_value);
 131:	48 8d 45 e0          	lea    rax,[rbp-0x20]
 135:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
  punned_value_rc = *punned_dest_rc;
 139:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
 13d:	48 8b 00             	mov    rax,QWORD PTR [rax]
 140:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  // } END REINTERPRET_CAST VARIANT

  cout << "Using reinterprest_cast: ";
 144:	be 00 00 00 00       	mov    esi,0x0
 149:	bf 00 00 00 00       	mov    edi,0x0
 14e:	e8 00 00 00 00       	call   153 <main+0x153>
  cout << punned_value_rc << endl;
 153:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
 157:	48 89 c6             	mov    rsi,rax
 15a:	bf 00 00 00 00       	mov    edi,0x0
 15f:	e8 00 00 00 00       	call   164 <main+0x164>
 164:	be 00 00 00 00       	mov    esi,0x0
 169:	48 89 c7             	mov    rdi,rax
 16c:	e8 00 00 00 00       	call   171 <main+0x171>

  // Bonus question:
  // What if we are punning an array of values?

  return EXIT_SUCCESS;
 171:	b8 00 00 00 00       	mov    eax,0x0
}
 176:	c9                   	leave  
 177:	c3                   	ret    

0000000000000178 <_Z41__static_initialization_and_destruction_0ii>:
 178:	55                   	push   rbp
 179:	48 89 e5             	mov    rbp,rsp
 17c:	48 83 ec 10          	sub    rsp,0x10
 180:	89 7d fc             	mov    DWORD PTR [rbp-0x4],edi
 183:	89 75 f8             	mov    DWORD PTR [rbp-0x8],esi
 186:	83 7d fc 01          	cmp    DWORD PTR [rbp-0x4],0x1
 18a:	75 27                	jne    1b3 <_Z41__static_initialization_and_destruction_0ii+0x3b>
 18c:	81 7d f8 ff ff 00 00 	cmp    DWORD PTR [rbp-0x8],0xffff
 193:	75 1e                	jne    1b3 <_Z41__static_initialization_and_destruction_0ii+0x3b>
  extern wostream wclog;	/// Linked to standard error (buffered)
#endif
  //@}

  // For construction of filebuffers for cout, cin, cerr, clog et. al.
  static ios_base::Init __ioinit;
 195:	bf 00 00 00 00       	mov    edi,0x0
 19a:	e8 00 00 00 00       	call   19f <_Z41__static_initialization_and_destruction_0ii+0x27>
 19f:	ba 00 00 00 00       	mov    edx,0x0
 1a4:	be 00 00 00 00       	mov    esi,0x0
 1a9:	bf 00 00 00 00       	mov    edi,0x0
 1ae:	e8 00 00 00 00       	call   1b3 <_Z41__static_initialization_and_destruction_0ii+0x3b>
 1b3:	90                   	nop
 1b4:	c9                   	leave  
 1b5:	c3                   	ret    

00000000000001b6 <_GLOBAL__sub_I_main>:
 1b6:	55                   	push   rbp
 1b7:	48 89 e5             	mov    rbp,rsp
 1ba:	be ff ff 00 00       	mov    esi,0xffff
 1bf:	bf 01 00 00 00       	mov    edi,0x1
 1c4:	e8 af ff ff ff       	call   178 <_Z41__static_initialization_and_destruction_0ii>
 1c9:	5d                   	pop    rbp
 1ca:	c3                   	ret    
