
main.g.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <main>:

using std::cout;
using std::endl;

int main(int argc, char * argv[])
{
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	53                   	push   rbx
   5:	48 81 ec 88 00 00 00 	sub    rsp,0x88
   c:	89 7d 8c             	mov    DWORD PTR [rbp-0x74],edi
   f:	48 89 75 80          	mov    QWORD PTR [rbp-0x80],rsi
  wno_unused_(argc);
  wno_unused_(argv);

  // See constant folding in action;
  int const_val = 0x0f + 0xf0;
  13:	c7 45 ec ff 00 00 00 	mov    DWORD PTR [rbp-0x14],0xff

  Heap heap_0("pool_0", 0, 100.0);
  1a:	48 8d 45 eb          	lea    rax,[rbp-0x15]
  1e:	48 89 c7             	mov    rdi,rax
  21:	e8 00 00 00 00       	call   26 <main+0x26>
  26:	48 8d 55 eb          	lea    rdx,[rbp-0x15]
  2a:	48 8d 45 c0          	lea    rax,[rbp-0x40]
  2e:	be 00 00 00 00       	mov    esi,0x0
  33:	48 89 c7             	mov    rdi,rax
  36:	e8 00 00 00 00       	call   3b <main+0x3b>
  3b:	48 ba 00 00 00 00 00 	movabs rdx,0x4059000000000000
  42:	00 59 40 
  45:	48 8d 4d c0          	lea    rcx,[rbp-0x40]
  49:	48 8d 45 90          	lea    rax,[rbp-0x70]
  4d:	48 89 95 78 ff ff ff 	mov    QWORD PTR [rbp-0x88],rdx
  54:	f2 0f 10 85 78 ff ff 	movsd  xmm0,QWORD PTR [rbp-0x88]
  5b:	ff 
  5c:	ba 00 00 00 00       	mov    edx,0x0
  61:	48 89 ce             	mov    rsi,rcx
  64:	48 89 c7             	mov    rdi,rax
  67:	e8 00 00 00 00       	call   6c <main+0x6c>
  6c:	48 8d 45 c0          	lea    rax,[rbp-0x40]
  70:	48 89 c7             	mov    rdi,rax
  73:	e8 00 00 00 00       	call   78 <main+0x78>
  78:	48 8d 45 eb          	lea    rax,[rbp-0x15]
  7c:	48 89 c7             	mov    rdi,rax
  7f:	e8 00 00 00 00       	call   84 <main+0x84>

  heap_0[0] = HeapElement { const_val * 310.0 };
  84:	48 8d 45 90          	lea    rax,[rbp-0x70]
  88:	be 00 00 00 00       	mov    esi,0x0
  8d:	48 89 c7             	mov    rdi,rax
  90:	e8 00 00 00 00       	call   95 <main+0x95>
  95:	66 0f ef c0          	pxor   xmm0,xmm0
  99:	f2 0f 2a 45 ec       	cvtsi2sd xmm0,DWORD PTR [rbp-0x14]
  9e:	f2 0f 10 0d 00 00 00 	movsd  xmm1,QWORD PTR [rip+0x0]        # a6 <main+0xa6>
  a5:	00 
  a6:	f2 0f 59 c1          	mulsd  xmm0,xmm1
  aa:	f2 0f 11 00          	movsd  QWORD PTR [rax],xmm0
  heap_0[1] = HeapElement { const_val * 320.0 };
  ae:	48 8d 45 90          	lea    rax,[rbp-0x70]
  b2:	be 01 00 00 00       	mov    esi,0x1
  b7:	48 89 c7             	mov    rdi,rax
  ba:	e8 00 00 00 00       	call   bf <main+0xbf>
  bf:	66 0f ef c0          	pxor   xmm0,xmm0
  c3:	f2 0f 2a 45 ec       	cvtsi2sd xmm0,DWORD PTR [rbp-0x14]
  c8:	f2 0f 10 0d 00 00 00 	movsd  xmm1,QWORD PTR [rip+0x0]        # d0 <main+0xd0>
  cf:	00 
  d0:	f2 0f 59 c1          	mulsd  xmm0,xmm1
  d4:	f2 0f 11 00          	movsd  QWORD PTR [rax],xmm0

  cout << heap_0 << endl;
  d8:	48 8d 45 90          	lea    rax,[rbp-0x70]
  dc:	48 89 c6             	mov    rsi,rax
  df:	bf 00 00 00 00       	mov    edi,0x0
  e4:	e8 00 00 00 00       	call   e9 <main+0xe9>
  e9:	be 00 00 00 00       	mov    esi,0x0
  ee:	48 89 c7             	mov    rdi,rax
  f1:	e8 00 00 00 00       	call   f6 <main+0xf6>

  return EXIT_SUCCESS;
  f6:	bb 00 00 00 00       	mov    ebx,0x0
  wno_unused_(argv);

  // See constant folding in action;
  int const_val = 0x0f + 0xf0;

  Heap heap_0("pool_0", 0, 100.0);
  fb:	48 8d 45 90          	lea    rax,[rbp-0x70]
  ff:	48 89 c7             	mov    rdi,rax
 102:	e8 00 00 00 00       	call   107 <main+0x107>
 107:	89 d8                	mov    eax,ebx
 109:	eb 45                	jmp    150 <main+0x150>
 10b:	48 89 c3             	mov    rbx,rax
 10e:	48 8d 45 c0          	lea    rax,[rbp-0x40]
 112:	48 89 c7             	mov    rdi,rax
 115:	e8 00 00 00 00       	call   11a <main+0x11a>
 11a:	eb 03                	jmp    11f <main+0x11f>
 11c:	48 89 c3             	mov    rbx,rax
 11f:	48 8d 45 eb          	lea    rax,[rbp-0x15]
 123:	48 89 c7             	mov    rdi,rax
 126:	e8 00 00 00 00       	call   12b <main+0x12b>
 12b:	48 89 d8             	mov    rax,rbx
 12e:	48 89 c7             	mov    rdi,rax
 131:	e8 00 00 00 00       	call   136 <main+0x136>
 136:	48 89 c3             	mov    rbx,rax
 139:	48 8d 45 90          	lea    rax,[rbp-0x70]
 13d:	48 89 c7             	mov    rdi,rax
 140:	e8 00 00 00 00       	call   145 <main+0x145>
 145:	48 89 d8             	mov    rax,rbx
 148:	48 89 c7             	mov    rdi,rax
 14b:	e8 00 00 00 00       	call   150 <main+0x150>
  heap_0[1] = HeapElement { const_val * 320.0 };

  cout << heap_0 << endl;

  return EXIT_SUCCESS;
}
 150:	48 81 c4 88 00 00 00 	add    rsp,0x88
 157:	5b                   	pop    rbx
 158:	5d                   	pop    rbp
 159:	c3                   	ret    

000000000000015a <_Z41__static_initialization_and_destruction_0ii>:
 15a:	55                   	push   rbp
 15b:	48 89 e5             	mov    rbp,rsp
 15e:	48 83 ec 10          	sub    rsp,0x10
 162:	89 7d fc             	mov    DWORD PTR [rbp-0x4],edi
 165:	89 75 f8             	mov    DWORD PTR [rbp-0x8],esi
 168:	83 7d fc 01          	cmp    DWORD PTR [rbp-0x4],0x1
 16c:	75 27                	jne    195 <_Z41__static_initialization_and_destruction_0ii+0x3b>
 16e:	81 7d f8 ff ff 00 00 	cmp    DWORD PTR [rbp-0x8],0xffff
 175:	75 1e                	jne    195 <_Z41__static_initialization_and_destruction_0ii+0x3b>
  extern wostream wclog;	/// Linked to standard error (buffered)
#endif
  //@}

  // For construction of filebuffers for cout, cin, cerr, clog et. al.
  static ios_base::Init __ioinit;
 177:	bf 00 00 00 00       	mov    edi,0x0
 17c:	e8 00 00 00 00       	call   181 <_Z41__static_initialization_and_destruction_0ii+0x27>
 181:	ba 00 00 00 00       	mov    edx,0x0
 186:	be 00 00 00 00       	mov    esi,0x0
 18b:	bf 00 00 00 00       	mov    edi,0x0
 190:	e8 00 00 00 00       	call   195 <_Z41__static_initialization_and_destruction_0ii+0x3b>
 195:	90                   	nop
 196:	c9                   	leave  
 197:	c3                   	ret    

0000000000000198 <_GLOBAL__sub_I_main>:
 198:	55                   	push   rbp
 199:	48 89 e5             	mov    rbp,rsp
 19c:	be ff ff 00 00       	mov    esi,0xffff
 1a1:	bf 01 00 00 00       	mov    edi,0x1
 1a6:	e8 af ff ff ff       	call   15a <_Z41__static_initialization_and_destruction_0ii>
 1ab:	5d                   	pop    rbp
 1ac:	c3                   	ret    

Disassembly of section .text._ZN5cpppc4HeapixEi:

0000000000000000 <_ZN5cpppc4HeapixEi>:

using std::cout;
using std::endl;

int main(int argc, char * argv[])
{
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	41 54                	push   r12
   6:	53                   	push   rbx
   7:	48 83 ec 10          	sub    rsp,0x10
   b:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   f:	89 75 e4             	mov    DWORD PTR [rbp-0x1c],esi
  12:	83 7d e4 00          	cmp    DWORD PTR [rbp-0x1c],0x0
  wno_unused_(argc);
  wno_unused_(argv);

  // See constant folding in action;
  int const_val = 0x0f + 0xf0;
  16:	78 0d                	js     25 <_ZN5cpppc4HeapixEi+0x25>
  18:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]

  Heap heap_0("pool_0", 0, 100.0);
  1c:	48 8b 40 20          	mov    rax,QWORD PTR [rax+0x20]
  20:	3b 45 e4             	cmp    eax,DWORD PTR [rbp-0x1c]
  23:	7f 2c                	jg     51 <_ZN5cpppc4HeapixEi+0x51>
  25:	bf 10 00 00 00       	mov    edi,0x10
  2a:	e8 00 00 00 00       	call   2f <_ZN5cpppc4HeapixEi+0x2f>
  2f:	48 89 c3             	mov    rbx,rax
  32:	be 00 00 00 00       	mov    esi,0x0
  37:	48 89 df             	mov    rdi,rbx
  3a:	e8 00 00 00 00       	call   3f <_ZN5cpppc4HeapixEi+0x3f>
  3f:	ba 00 00 00 00       	mov    edx,0x0
  44:	be 00 00 00 00       	mov    esi,0x0
  49:	48 89 df             	mov    rdi,rbx
  4c:	e8 00 00 00 00       	call   51 <_ZN5cpppc4HeapixEi+0x51>
  51:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  55:	48 8b 40 28          	mov    rax,QWORD PTR [rax+0x28]
  59:	8b 55 e4             	mov    edx,DWORD PTR [rbp-0x1c]
  5c:	48 63 d2             	movsxd rdx,edx
  5f:	48 c1 e2 03          	shl    rdx,0x3
  63:	48 01 d0             	add    rax,rdx
  66:	eb 16                	jmp    7e <_ZN5cpppc4HeapixEi+0x7e>
  68:	49 89 c4             	mov    r12,rax
  6b:	48 89 df             	mov    rdi,rbx
  6e:	e8 00 00 00 00       	call   73 <_ZN5cpppc4HeapixEi+0x73>
  73:	4c 89 e0             	mov    rax,r12
  76:	48 89 c7             	mov    rdi,rax
  79:	e8 00 00 00 00       	call   7e <_ZN5cpppc4HeapixEi+0x7e>
  7e:	48 83 c4 10          	add    rsp,0x10
  82:	5b                   	pop    rbx
  83:	41 5c                	pop    r12

  heap_0[0] = HeapElement { const_val * 310.0 };
  85:	5d                   	pop    rbp
  86:	c3                   	ret    
