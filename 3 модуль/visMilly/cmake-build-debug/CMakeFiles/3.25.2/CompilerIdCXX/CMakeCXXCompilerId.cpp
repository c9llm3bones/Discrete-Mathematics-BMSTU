package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	/*var p int
	fmt.Scanln(&p)

	a := inserter()
	b := inserter()*/
	a := []int32{1, 2, 3}
	b := []int32{4, 5, 6}
	fmt.Println(add(a, b, 10))
}

func add(a, b []int32, p int) []int32 {

	output := []int32{}
	ost := 0
	minLen := min(len(a), len(b))

	for i := 0; i < minLen; i++ {
		output = append(output, int32((int(a[i])+int(b[i])+ost)%p))
		ost = (int(a[i]) + int(b[i]) + ost) / p
	}

	for _, slice := range [][]int32{a, b} {
		if len(slice) > minLen {
			for i := minLen; i < len(slice); i++ {
				output = append(output, int32((int(slice[i])+ost)%p))
				ost = (int(slice[i]) + ost) / p
			}
		}
	}

	if ost != 0 {
		output = append(output, int32(ost%p))
	}

	return output

}

func min(i int, i2 int) int {
	if i < i2 {
		return i
	}
	return i2
}

func inserter() []int32 {
	arr := []int32{}

	reader := bufio.NewReader(os.Stdin)

	input, err := reader.ReadString('\n')

	if err != nil {
		fmt.Println("Ошибка чтения ввода:", err)
	}

	for _, str := range strings.Fields(input) {
		num, err := strconv.ParseInt(str, 10, 32)
		if err != nil {
			fmt.Println("Ошибка преобразования строки в число:", err)
			continue
		}
		arr = append(arr, int32(num))
	}

	return arr
}

func reverse(arr []int32) []int32 {
	for i, j := 0, len(arr)-1; i < len(arr)/2; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
	return arr
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                The system is: Linux - 5.19.0-35-generic - x86_64
Compiling the C compiler identification source file "CMakeCCompilerId.c" succeeded.
Compiler: /usr/bin/cc 
Build flags: 
Id flags:  

The output was:
0


Compilation of the C compiler identification source "CMakeCCompilerId.c" produced "a.out"

The C compiler identification is GNU, found in "/home/kostya/2_sem/Дискра/2 модуль/MaxComponent/MaxComponent_plus/cmake-build-debug/CMakeFiles/3.24.2/CompilerIdC/a.out"

Compiling the CXX compiler identification source file "CMakeCXXCompilerId.cpp" succeeded.
Compiler: /usr/bin/c++ 
Build flags: 
Id flags:  

The output was:
0


Compilation of the CXX compiler identification source "CMakeCXXCompilerId.cpp" produced "a.out"

The CXX compiler identification is GNU, found in "/home/kostya/2_sem/Дискра/2 модуль/MaxComponent/MaxComponent_plus/cmake-build-debug/CMakeFiles/3.24.2/CompilerIdCXX/a.out"

Detecting C compiler ABI info compiled with the following output:
Change Dir: /home/kostya/2_sem/Дискра/2 модуль/MaxComponent/MaxComponent_plus/cmake-build-debug/CMakeFiles/CMakeTmp

Run Build Command(s):/snap/clion/229/bin/ninja/linux/x64/ninja cmTC_75006 && [1/2] Building C object CMakeFiles/cmTC_75006.dir/CMakeCCompilerABI.c.o
Using built-in specs.
COLLECT_GCC=/usr/bin/cc
OFFLOAD_TARGET_NAMES=nvptx-none:amdgcn-amdhsa
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 11.3.0-1ubuntu1~22.04' --with-bugurl=file:///usr/share/doc/gcc-11/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++,m2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-11 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-bootstrap --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --enable-libphobos-checking=release --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --enable-cet --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none=/build/gcc-11-xKiWfi/gcc-11-11.3.0/debian/tmp-nvptx/usr,amdgcn-amdhsa=/build/gcc-11-xKiWfi/gcc-11-11.3.0/debian/tmp-gcn/usr --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu --with-build-config=bootstrap-lto-lean --enable-link-serialization=2
Thread model: posix
Supported LTO compression algorithms: zlib zstd
gcc version 11.3.0 (Ubuntu 11.3.0-1ubuntu1~22.04) 
COLLECT_GCC_OPTIONS='-fdiagnostics-color=always' '-v' '-o' 'CMakeFiles/cmTC_75006.dir/CMakeCCompilerABI.c.o' '-c' '-mtune=generic' '-march=x86-64' '-dumpdir' 'CMakeFiles/cmTC_75006.dir/'
 /usr/lib/gcc/x86_64-linux-gnu/11/cc1 -quiet -v -imultiarch x86_64-linux-gnu /snap/clion/229/bin/cmake/linux/x64/share/cmake-3.24/Modules/CMakeCCompilerABI.c -quiet -dumpdir CMakeFiles/cmTC_75006.dir/ -dumpbase CMakeCCompilerABI.c.c -dumpbase-ext .c -mtune=generic -march=x86-64 -version -fdiagnostics-color=always -fasynchronous-unwind-tables -fstack-protector-strong -Wformat -Wformat-security -fstack-clash-protection -fcf-protection -o /tmp/ccuYpg6X.s
GNU C17 (Ubuntu 11.3.0-1ubuntu1~22.04) version 11.3.0 (x86_64-linux-gnu)
	compiled by GNU C version 11.3.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
ignoring nonexistent directory "/usr/local/include/x86_64-linux-gnu"
ignoring nonexistent directory "/usr/lib/gcc/x86_64-linux-gnu/11/include-fixed"
ignoring nonexistent directory "/usr/lib/gcc/x86_64-linux-gnu/11/../../../../x86_64-linux-gnu/include"
#include "..." search starts here:
#include <...> search starts here:
 /usr/lib/gcc/x86_64-linux-gnu/11/include
 /usr/local/include
 /usr/include/x86_64-linux-gnu
 /usr/include
End of search list.
GNU C17 (Ubuntu 11.3.0-1ubuntu1~22.04) version 11.3.0 (x86_64-linux-gnu)
	compiled by GNU C version 11.3.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
Compiler executable checksum: 3f6cb05d963ad324b8f9442822c95179
COLLECT_GCC_OPTIONS='-fdiagnostics-color=always' '-v' '-o' 'CMakeFiles/cmTC_75006.dir/CMakeCCompilerABI.c.o' '-c' '-mtune=generic' '-march=x86-64' '-dumpdir' 'CMakeFiles/cmTC_75006.dir/'
 as -v --64 -o CMakeFiles/cmTC_75006.dir/CMakeCCompilerABI.c.o /tmp/ccuYpg6X.s
GNU assembler version 2.38 (x86_64-linux-gnu) using BFD version (GNU Binutils for Ubuntu) 2.38
COMPILER_PATH=/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/:/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/
LIBRARY_PATH=/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/:/usr/lib/gcc/x86_64-linux-gnu/11/../../../../lib/:/lib/x86_64-linux-gnu/:/lib/../lib/:/usr/lib/x86_64-linux-gnu/:/usr/lib/../lib/:/usr/lib/gcc/x86_64-linux-gnu/11/../../../:/lib/:/usr/lib/
COLLECT_GCC_OPTIONS='-fdiagnostics-color=always' '-v' '-o' 'CMakeFiles/cmTC_75006.dir/CMakeCCompilerABI.c.o' '-c' '-mtune=generic' '-march=x86-64' '-dumpdir' 'CMakeFiles/cmTC_75006.dir/CMakeCCompilerABI.c.'
[2/2] Linking C executable cmTC_75006
Using built-in specs.
COLLECT_GCC=/usr/bin/cc
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/11/lto-wrapper
OFFLOAD_TARGET_NAMES=nvptx-none:amdgcn-amdhsa
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 11.3.0-1ubuntu1~22.04' --with-bugurl=file:///usr/share/doc/gcc-11/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++,m2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-11 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-bootstrap --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --enable-libphobos-checking=release --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --enable-cet --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none=/build/gcc-11-xKiWfi/gcc-11-11.3.0/debian/tmp-nvptx/usr,amdgcn-amdhsa=/build/gcc-11-xKiWfi/gcc-11-11.3.0/debian/tmp-gcn/usr --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu --with-build-config=bootstrap-lto-lean --enable-link-serialization=2
Thread model: posix
Supported LTO compression algorithms: zlib zstd
gcc version 11.3.0 (Ubuntu 11.3.0-1ubuntu1~22.04) 
COMPILER_PATH=/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/:/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/
LIBRARY_PATH=/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/:/usr/lib/gcc/x86_64-linux-gnu/11/../../../../lib/:/lib/x86_64-linux-gnu/:/lib/../lib/:/usr/lib/x86_64-linux-gnu/:/usr/lib/../lib/:/usr/lib/gcc/x86_64-linux-gnu/11/../../../:/lib/:/usr/lib/
COLLECT_GCC_OPTIONS='-v' '-o' 'cmTC_75006' '-mtune=generic' '-march=x86-64' '-dumpdir' 'cmTC_75006.'
 /usr/lib/gcc/x86_64-linux-gnu/11/collect2 -plugin /usr/lib/gcc/x86_64-linux-gnu/11/liblto_plugin.so -plugin-opt=/usr/lib/gcc/x86_64-linux-gnu/11/lto-wrapper -plugin-opt=-fresolution=/tmp/ccG60AZs.res -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lgcc_s -plugin-opt=-pass-through=-lc -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lgcc_s --build-id --eh-frame-hdr -m elf_x86_64 --hash-style=gnu --as-needed -dynamic-linker /lib64/ld-linux-x86-64.so.2 -pie -z now -z relro -o cmTC_75006 /usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/Scrt1.o /usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/crti.o /usr/lib/gcc/x86_64-linux-gnu/11/crtbeginS.o -L/usr/lib/gcc/x86_64-linux-gnu/11 -L/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu -L/usr/lib/gcc/x86_64-linux-gnu/11/../../../../lib -L/lib/x86_64-linux-gnu -L/lib/../lib -L/usr/lib/x86_64-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/x86_64-linux-gnu/11/../../.. CMakeFiles/cmTC_75006.dir/CMakeCCompilerABI.c.o -lgcc --push-state --as-needed -lgcc_s --pop-state -lc -lgcc --push-state --as-needed -lgcc_s --pop-state /usr/lib/gcc/x86_64-linux-gnu/11/crtendS.o /usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/crtn.o
COLLECT_GCC_OPTIONS='-v' '-o' 'cmTC_75006' '-mtune=generic' '-march=x86-64' '-dumpdir' 'cmTC_75006.'



Parsed C implicit include dir info from above output: rv=done
  found start of include info
  found start of implicit include info
    add: [/usr/lib/gcc/x86_64-linux-gnu/11/include]
    add: [/usr/local/include]
    add: [/usr/include/x86_64-linux-gnu]
    add: [/usr/include]
  end of search list found
  collapse include dir [/usr/lib/gcc/x86_64-linux-gnu/11/include] ==> [/usr/lib/gcc/x86_64-linux-gnu/11/include]
  collapse include dir [/usr/local/include] ==> [/usr/local/include]
  collapse include dir [/usr/include/x86_64-linux-gnu] ==> [/usr/include/x86_64-linux-gnu]
  collapse include dir [/usr/include] ==> [/usr/include]
  implicit include dirs: [/usr/lib/gcc/x86_64-linux-gnu/11/include;/usr/local/include;/usr/include/x86_64-linux-gnu;/usr/include]


Parsed C implicit link information from above output:
  link line regex: [^( *|.*[/\])(ld|CMAKE_LINK_STARTFILE-NOTFOUND|([^/\]+-)?ld|collect2)[^/\]*( |$)]
  ignore line: [Change Dir: /home/kostya/2_sem/Дискра/2 модуль/MaxComponent/MaxComponent_plus/cmake-build-debug/CMakeFiles/CMakeTmp]
  ignore line: []
  ignore line: [Run Build Command(s):/snap/clion/229/bin/ninja/linux/x64/ninja cmTC_75006 && [1/2] Building C object CMakeFiles/cmTC_75006.dir/CMakeCCompilerABI.c.o]
  ignore line: [Using built-in specs.]
  ignore line: [COLLECT_GCC=/usr/bin/cc]
  ignore line: [OFFLOAD_TARGET_NAMES=nvptx-none:amdgcn-amdhsa]
  ignore line: [OFFLOAD_TARGET_DEFAULT=1]
  ignore line: [Target: x86_64-linux-gnu]
  ignore line: [Configured with: ../src/configure -v --with-pkgversion='Ubuntu 11.3.0-1ubuntu1~22.04' --with-bugurl=file:///usr/share/doc/gcc-11/README.Bugs --enable-languages=c ada c++ go brig d fortran objc obj-c++ m2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-11 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-bootstrap --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --enable-libphobos-checking=release --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --enable-cet --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32 m64 mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none=/build/gcc-11-xKiWfi/gcc-11-11.3.0/debian/tmp-nvptx/usr amdgcn-amdhsa=/build/gcc-11-xKiWfi/gcc-11-11.3.0/debian/tmp-gcn/usr --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu --with-build-config=bootstrap-lto-lean --enable-link-serialization=2]
  ignore line: [Thread model: posix]
  ignore line: [Supported LTO compression algorithms: zlib zstd]
  ignore line: [gcc version 11.3.0 (Ubuntu 11.3.0-1ubuntu1~22.04) ]
  ignore line: [COLLECT_GCC_OPTIONS='-fdiagnostics-color=always' '-v' '-o' 'CMakeFiles/cmTC_75006.dir/CMakeCCompilerABI.c.o' '-c' '-mtune=generic' '-march=x86-64' '-dumpdir' 'CMakeFiles/cmTC_75006.dir/']
  ignore line: [ /usr/lib/gcc/x86_64-linux-gnu/11/cc1 -quiet -v -imultiarch x86_64-linux-gnu /snap/clion/229/bin/cmake/linux/x64/share/cmake-3.24/Modules/CMakeCCompilerABI.c -quiet -dumpdir CMakeFiles/cmTC_75006.dir/ -dumpbase CMakeCCompilerABI.c.c -dumpbase-ext .c -mtune=generic -march=x86-64 -version -fdiagnostics-color=always -fasynchronous-unwind-tables -fstack-protector-strong -Wformat -Wformat-security -fstack-clash-protection -fcf-protection -o /tmp/ccuYpg6X.s]
  ignore line: [GNU C17 (Ubuntu 11.3.0-1ubuntu1~22.04) version 11.3.0 (x86_64-linux-gnu)]
  ignore line: [	compiled by GNU C version 11.3.0  GMP version 6.2.1  MPFR version 4.1.0  MPC version 1.2.1  isl version isl-0.24-GMP]
  ignore line: []
  ignore line: [GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072]
  ignore line: [ignoring nonexistent directory "/usr/local/include/x86_64-linux-gnu"]
  ignore line: [ignoring nonexistent directory "/usr/lib/gcc/x86_64-linux-gnu/11/include-fixed"]
  ignore line: [ignoring nonexistent directory "/usr/lib/gcc/x86_64-linux-gnu/11/../../../../x86_64-linux-gnu/include"]
  ignore line: [#include "..." search starts here:]
  ignore line: [#include <...> search starts here:]
  ignore line: [ /usr/lib/gcc/x86_64-linux-gnu/11/include]
  ignore line: [ /usr/local/include]
  ignore line: [ /usr/include/x86_64-linux-gnu]
  ignore line: [ /usr/include]
  ignore line: [End of search list.]
  ignore line: [GNU C17 (Ubuntu 11.3.0-1ubuntu1~22.04) version 11.3.0 (x86_64-linux-gnu)]
  ignore line: [	compiled by GNU C version 11.3.0  GMP version 6.2.1  MPFR version 4.1.0  MPC version 1.2.1  isl version isl-0.24-GMP]
  ignore line: []
  ignore line: [GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072]
  ignore line: [Compiler executable checksum: 3f6cb05d963ad324b8f9442822c95179]
  ignore line: [COLLECT_GCC_OPTIONS='-fdiagnostics-color=always' '-v' '-o' 'CMakeFiles/cmTC_75006.dir/CMakeCCompilerABI.c.o' '-c' '-mtune=generic' '-march=x86-64' '-dumpdir' 'CMakeFiles/cmTC_75006.dir/']
  ignore line: [ as -v --64 -o CMakeFiles/cmTC_75006.dir/CMakeCCompilerABI.c.o /tmp/ccuYpg6X.s]
  ignore line: [GNU assembler version 2.38 (x86_64-linux-gnu) using BFD version (GNU Binutils for Ubuntu) 2.38]
  ignore line: [COMPILER_PATH=/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/:/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/]
  ignore line: [LIBRARY_PATH=/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/:/usr/lib/gcc/x86_64-linux-gnu/11/../../../../lib/:/lib/x86_64-linux-gnu/:/lib/../lib/:/usr/lib/x86_64-linux-gnu/:/usr/lib/../lib/:/usr/lib/gcc/x86_64-linux-gnu/11/../../../:/lib/:/usr/lib/]
  ignore line: [COLLECT_GCC_OPTIONS='-fdiagnostics-color=always' '-v' '-o' 'CMakeFiles/cmTC_75006.dir/CMakeCCompilerABI.c.o' '-c' '-mtune=generic' '-march=x86-64' '-dumpdir' 'CMakeFiles/cmTC_75006.dir/CMakeCCompilerABI.c.']
  ignore line: [[2/2] Linking C executable cmTC_75006]
  ignore line: [Using built-in specs.]
  ignore line: [COLLECT_GCC=/usr/bin/cc]
  ignore line: [COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/11/lto-wrapper]
  ignore line: [OFFLOAD_TARGET_NAMES=nvptx-none:amdgcn-amdhsa]
  ignore line: [OFFLOAD_TARGET_DEFAULT=1]
  ignore line: [Target: x86_64-linux-gnu]
  ignore line: [Configured with: ../src/configure -v --with-pkgversion='Ubuntu 11.3.0-1ubuntu1~22.04' --with-bugurl=file:///usr/share/doc/gcc-11/README.Bugs --enable-languages=c ada c++ go brig d fortran objc obj-c++ m2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-11 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-bootstrap --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --enable-libphobos-checking=release --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --enable-cet --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32 m64 mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none=/build/gcc-11-xKiWfi/gcc-11-11.3.0/debian/tmp-nvptx/usr amdgcn-amdhsa=/build/gcc-11-xKiWfi/gcc-11-11.3.0/debian/tmp-gcn/usr --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu --with-build-config=bootstrap-lto-lean --enable-link-serialization=2]
  ignore line: [Thread model: posix]
  ignore line: [Supported LTO compression algorithms: zlib zstd]
  ignore line: [gcc version 11.3.0 (Ubuntu 11.3.0-1ubuntu1~22.04) ]
  ignore line: [COMPILER_PATH=/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/:/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/]
  ignore line: [LIBRARY_PATH=/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/:/usr/lib/gcc/x86_64-linux-gnu/11/../../../../lib/:/lib/x86_64-linux-gnu/:/lib/../lib/:/usr/lib/x86_64-linux-gnu/:/usr/lib/../lib/:/usr/lib/gcc/x86_64-linux-gnu/11/../../../:/lib/:/usr/lib/]
  ignore line: [COLLECT_GCC_OPTIONS='-v' '-o' 'cmTC_75006' '-mtune=generic' '-march=x86-64' '-dumpdir' 'cmTC_75006.']
  link line: [ /usr/lib/gcc/x86_64-linux-gnu/11/collect2 -plugin /usr/lib/gcc/x86_64-linux-gnu/11/liblto_plugin.so -plugin-opt=/usr/lib/gcc/x86_64-linux-gnu/11/lto-wrapper -plugin-opt=-fresolution=/tmp/ccG60AZs.res -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lgcc_s -plugin-opt=-pass-through=-lc -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lgcc_s --build-id --eh-frame-hdr -m elf_x86_64 --hash-style=gnu --as-needed -dynamic-linker /lib64/ld-linux-x86-64.so.2 -pie -z now -z relro -o cmTC_75006 /usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/Scrt1.o /usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/crti.o /usr/lib/gcc/x86_64-linux-gnu/11/crtbeginS.o -L/usr/lib/gcc/x86_64-linux-gnu/11 -L/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu -L/usr/lib/gcc/x86_64-linux-gnu/11/../../../../lib -L/lib/x86_64-linux-gnu -L/lib/../lib -L/usr/lib/x86_64-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/x86_64-linux-gnu/11/../../.. CMakeFiles/cmTC_75006.dir/CMakeCCompilerABI.c.o -lgcc --push-state --as-needed -lgcc_s --pop-state -lc -lgcc --push-state --as-needed -lgcc_s --pop-state /usr/lib/gcc/x86_64-linux-gnu/11/crtendS.o /usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/crtn.o]
    arg [/usr/lib/gcc/x86_64-linux-gnu/11/collect2] ==> ignore
    arg [-plugin] ==> ignore
    arg [/usr/lib/gcc/x86_64-linux-gnu/11/liblto_plugin.so] ==> ignore
    arg [-plugin-opt=/usr/lib/gcc/x86_64-linux-gnu/11/lto-wrapper] ==> ignore
    arg [-plugin-opt=-fresolution=/tmp/ccG60AZs.res] ==> ignore
    arg [-plugin-opt=-pass-through=-lgcc] ==> ignore
    arg [-plugin-opt=-pass-through=-lgcc_s] ==> ignore
    arg [-plugin-opt=-pass-through=-lc] ==> ignore
    arg [-plugin-opt=-pass-through=-lgcc] ==> ignore
    arg [-plugin-opt=-pass-through=-lgcc_s] ==> ignore
    arg [--build-id] ==> ignore
    arg [--eh-frame-hdr] ==> ignore
    arg [-m] ==> ignore
    arg [elf_x86_64] ==> ignore
    arg [--hash-style=gnu] ==> ignore
    arg [--as-needed] ==> ignore
    arg [-dynamic-linker] ==> ignore
    arg [/lib64/ld-linux-x86-64.so.2] ==> ignore
    arg [-pie] ==> ignore
    arg [-znow] ==> ignore
    arg [-zrelro] ==> ignore
    arg [-o] ==> ignore
    arg [cmTC_75006] ==> ignore
    arg [/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/Scrt1.o] ==> obj [/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/Scrt1.o]
    arg [/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/crti.o] ==> obj [/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/crti.o]
    arg [/usr/lib/gcc/x86_64-linux-gnu/11/crtbeginS.o] ==> obj [/usr/lib/gcc/x86_64-linux-gnu/11/crtbeginS.o]
    arg [-L/usr/lib/gcc/x86_64-linux-gnu/11] ==> dir [/usr/lib/gcc/x86_64-linux-gnu/11]
    arg [-L/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu] ==> dir [/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu]
    arg [-L/usr/lib/gcc/x86_64-linux-gnu/11/../../../../lib] ==> dir [/usr/lib/gcc/x86_64-linux-gnu/11/../../../../lib]
    arg [-L/lib/x86_64-linux-gnu] ==> dir [/lib/x86_64-linux-gnu]
    arg [-L/lib/../lib] ==> dir [/lib/../lib]
    arg [-L/usr/lib/x86_64-linux-gnu] ==> dir [/usr/lib/x86_64-linux-gnu]
    arg [-L/usr/lib/../lib] ==> dir [/usr/lib/../lib]
    arg [-L/usr/lib/gcc/x86_64-linux-gnu/11/../../..] ==> dir [/usr/lib/gcc/x86_64-linux-gnu/11/../../..]
    arg [CMakeFiles/cmTC_75006.dir/CMakeCCompilerABI.c.o] ==> ignore
    arg [-lgcc] ==> lib [gcc]
    arg [--push-state] ==> ignore
    arg [--as-needed] ==> ignore
    arg [-lgcc_s] ==> lib [gcc_s]
    arg [--pop-state] ==> ignore
    arg [-lc] ==> lib [c]
    arg [-lgcc] ==> lib [gcc]
    arg [--push-state] ==> ignore
    arg [--as-needed] ==> ignore
    arg [-lgcc_s] ==> lib [gcc_s]
    arg [--pop-state] ==> ignore
    arg [/usr/lib/gcc/x86_64-linux-gnu/11/crtendS.o] ==> obj [/usr/lib/gcc/x86_64-linux-gnu/11/crtendS.o]
    arg [/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/crtn.o] ==> obj [/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/crtn.o]
  collapse obj [/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/Scrt1.o] ==> [/usr/lib/x86_64-linux-gnu/Scrt1.o]
  collapse obj [/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/crti.o] ==> [/usr/lib/x86_64-linux-gnu/crti.o]
  collapse obj [/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/crtn.o] ==> [/usr/lib/x86_64-linux-gnu/crtn.o]
  collapse library dir [/usr/lib/gcc/x86_64-linux-gnu/11] ==> [/usr/lib/gcc/x86_64-linux-gnu/11]
  collapse library dir [/usr/lib/gcc/x