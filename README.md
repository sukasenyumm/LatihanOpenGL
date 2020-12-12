# LatihanOpenGL
Repository untuk berlatih OpenGL dari NOL.

==Persiapan sebelum instalasi OpenGL==
Pastikan sudah terinstal Visual Studio 2019 dengan C++ 
Jika belum ada C++ bisa install via Visual Studio Installer, Modify

==Instalasi OpenGL dengan Visual Studio 2019==

1. Buka Visual Studio 2019
2. Create New Project
3. C++ Empty Project
4. Pilih nama dan lokasi --> create
5. Setelah Project dibuat, minimize (jangan di tutup)
6. Download GLFW di halaman resminya https://www.glfw.org/download.html
7. Pilih yang source package
8. Ekstrak ke folder
9. Ke CMake website https://cmake.org/download/ download Binary distributions: platform windows disesuikan bitnya
10. Install Cmake, Next terus sampai selesai
11. Buka cmake gui -> "Where is source code" di isi direktori glfw tadi dimana didalamnya ada folder cmake
12. Letakkan "Where to build binaries" isikan sama dengan "Where is source code"
13. Klik Configure-> pilih visual studio 2019 -> finish (tunggu, lihat prosesnya di bawah)
14. Klik Generate
15. Klik Open project
16. Setelah didalam project GLFW klik kanan di Solution, Klik Build Solution (tunggu sampai selesai)
17. Close project GLFW
18. buat folder dengan nama "include" dan "lib" satu direktori dengan file sln project kita 
19. Isi didalam folder lib dengan melakukan copy paste file glfw3.lib didalam direktori glfw masuk ke src masuk ke debug.
20. Ke folder gflw ada folder include copy folder GLFW kedalam folder include pada project kita
21. Sekarang, glad website https://glad.dav1d.de/ , pilih versi gl 4.6, Language: C++; Specification OpenGL; Profile Core;
22. Klik Generate dan download glad.zip
23. Ekstrak glad.zip masuk ke include copy semua isinya ke include project kita
24. Masuk ke src didalam folder glad copy dan paste glad.h ke source project kita
25. Sekarang ke project kita, Klik Debug x64 Local Windows Debugger
26. Di VS 2019 menu, pilih debug pilih Properties bawah sendiri
27. ke vc++ directories-> lihat saja -> close
28. ke menu Project -> properties -> pastikan sudah di VC++ directories -> include directories -> Edit
29. click simbol folder kuning --> isikan $(SolutionDir)include lalu klik ok
30. Ke general -> linker -> additional directories -> edit -> klik simbol kuning -> isikan $(SolutionDir)lib -> oke
31. ke Input -> additional dependencies -> edit -> ketik opengl32.lib enter glfw3.lib ->ok -> apply 
32. close box menu tadi
33. klik kanan di Source buat kode baru dengan nama Source.cpp
34. Buka Glfw documentation (https://www.glfw.org/documentation.html) ada sample code -> copy paste di kode kita Source.cpp 
35. pastikan tidak ada error dan terlihat ada window hitam baru
