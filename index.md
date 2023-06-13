Professor: [João Vicente Ferreira Lima](http://www.inf.ufsm.br/~jvlima)

Contato: jvlima em inf.ufsm.br ou CT/UFSM sala 380 Anexo B.

Carga horária: 60h.

Ementa oficial: https://www.ufsm.br/ementario/disciplinas/ELC139

Horários: terças e quintas, 16:30 às 18:30.

Calendário UFSM: https://www.ufsm.br/calendario/

## Sobre a disciplina

Utilizar métodos  e  técnicas  para  o  projeto, implementação  e  uso  de sistemas  de  programação  para  o  desenvolvimento  de  programas  paralelos   e distribuídos.

## Material de apoio

- [Designing and Building Parallel Programs](https://www.mcs.anl.gov/~itf/dbpp/), Ian Foster
- [An Introduction to Parallel Programming](https://www.cs.usfca.edu/~peter/ipp/), Peter Pacheco
- [Introduction to Parallel Computing Tutorial](https://hpc.llnl.gov/documentation/tutorials/introduction-parallel-computing-tutorial)
- [MPI Tutorial](https://hpc-tutorials.llnl.gov/mpi/)
- [OpenMP Tutorial](https://hpc-tutorials.llnl.gov/openmp/)
- [GitHub Handbook](https://guides.github.com/introduction/git-handbook/)
- [Git Cheat Sheets](https://github.github.com/training-kit/)
- [Tech Talk: Linux Tolvards on Git](http://youtu.be/4XpnKHJAok8)
- [Introduction to Git with Scott Chacon of GitHub](https://youtu.be/ZDR433b0HJY)

## Aulas e trabalhos

|  # | Data             | Assunto          |
|---:|------------------|:-----------------|
|  1 | 2022-03-21 Ter | Apresentação da disciplina   |
|  2 | 2022-03-23 Qui   | [Introdução C++](./aulas/introducao_cxx) ([vídeo](https://youtu.be/pB-MdBKNpNo), [slides](./aulas/02_intro_cxx/02_intro_cxx.pdf)) |
|  3 | 2022-03-28 Ter   | [Introdução a Programação Paralela](./aulas/01_progpar/01_intro_progpar.pdf) |
|  4 | 2022-03-30 Qui   | [Arquiteturas de Computadores Paralelos](./aulas/03_arquiteturas/03_arquiteturas.pdf) |
|  5 | 2022-04-04 Ter   | Arquiteturas de Computadores Paralelos  |
|  6 | 2022-04-06 Qui   | Arquiteturas de Computadores Paralelos |
|  7 | 2022-04-11 Ter   | [Modelos de Programação Paralela](./aulas/04_modelos_programacao/04_modelos_programacao.pdf) |
|  8 | 2022-04-13 Qui   | [Programação Paralela com MPI](./aulas/05_mpi/05_mpi.pdf). MPI no [Google Colab](https://colab.research.google.com/drive/16FqO4uorwcd7jUMQnHsqXWscKE2qz2Xa?usp=sharing) |
|  9 | 2022-04-18 Ter   | [Análise de Desempenho](./aulas/06_metricas/06_metricas.pdf) |
| 10 | 2022-04-20 Qui   | [Programação Paralela com MPI](./aulas/07_mpi/07_mpi.pdf), [Google Colab com exemplos](https://colab.research.google.com/drive/1E0Q20YoaT1XZJf0YDEy4NFJsf55fcr3I?usp=sharing)  |
| 11 | 2022-04-25 Ter   | [Programação Paralela com MPI](./aulas/08_mpi/08_mpi.pdf)  |
| 12 | 2022-04-27 Qui   | [Fractais de Mandelbrot em MPI](https://colab.research.google.com/drive/1g_wij0TMO1uZy2UH99Y7FCC6q-EBOr0n?usp=sharing), [código fonte](https://github.com/joao-ufsm/par2023a/tree/master/exemplos/fractal) |
| 13 | 2022-05-02 Ter   | [Programação Paralela com OpenMP - Introdução](./aulas/13_openmp/13_openmp.pdf)   |
|  | 2022-05-02 Ter   | [T1 - Mandelbrot](./trabalhos/T1) |
| 14 | 2022-05-04 Qui   | Programação Paralela com OpenMP |
| 15 | 2022-05-09 Ter   | [Programação Paralela com OpenMP - Exemplos](aulas/14_openmp/14_openmp.pdf) |
| 16 | 2022-05-11 Qui   | [Programação Paralela com OpenMP - Tarefas](https://tinyurl.com/openmp-umt-tasking) |
| 17 | 2022-05-16 Ter   | [Programação Paralela com OpenMP - Tarefas e dados)](./aulas/15_openmp/15_openmp.pdf) |
|     | 2022-05-16 Ter   | [T2 - Mandelbrot (bugado)](./trabalhos/T2) |
| 18 | 2022-05-18 Qui   | [Programação Paralela com OpenMP - target](https://www.alcf.anl.gov/sites/default/files/2020-01/OpenMP45_Bertoni.pdf), [tutorial](https://www.nersc.gov/users/training/events/introduction-to-openmp-offload-aug-sep-2022/), [Exemplo DAXY](https://blog.rwth-aachen.de/itc-events/files/2021/02/17-openmp-CT-offloading.pdf) |
| 19 | 2022-05-23 Ter   | [Programação Paralela com CUDA (LNCC)](http://www.cenapad-rj.lncc.br/tutoriais/materiais-hpc/semana-sdumont/verao2021/MC-SD03-I-2021-slides.pdf), [CUDA C Programming Guide](https://docs.nvidia.com/cuda/cuda-c-programming-guide/) |
| 20 | 2022-05-25 Qui   | [Programação Paralela com CUDA (Colab)](https://colab.research.google.com/drive/1qqaAhT33m2GjivaDCMmwiNhFDqIaALRV?usp=sharing) |
| 21 | 2022-05-30 Ter   | [Programação Paralela com CUDA (LNCC)](http://www.cenapad-rj.lncc.br/tutoriais/materiais-hpc/semana-sdumont/verao2021/MC-SD03-II-2021-slides.pdf)  |
| 22 | 2022-06-01 Qui   | [Programação Paralela com CUDA](https://developer.download.nvidia.com/video/gputechconf/gtc/2019/presentation/S9593/) | 
| 23 | 2022-06-06 Ter   | [Programação Paralela com CUDA (Depuração)](https://www.olcf.ornl.gov/wp-content/uploads/2019/08/NVIDIA-Profilers.pdf), [Exemplo CUBLAS Batched](https://colab.research.google.com/drive/1vwuGNBBJwDszxLJqfMGe4AxyZlVRegF2?usp=sharing) | 
| - | 2022-06-08 Qui   | **Feriado** (Corpus Christi)  |
| 24 | 2022-06-13 Ter   | [Programação Paralela com OpenACC](https://docs.google.com/presentation/d/1nVNP05GEzb2uACy4grNr_KwZPsiTtDBe/edit?usp=sharing&ouid=113036597464866182871&rtpof=true&sd=true), [Exemplos no Google Colab](https://colab.research.google.com/drive/1QDdHBCJeGWUL6Y7FYi1hccLuie9eVPZI?usp=sharing) |
| 25 | 2022-06-15 Qui   | [Programação Paralela com OpenACC](https://docs.google.com/presentation/d/1nKQ9Yh51i4TD5x_Zd8l1jaDyprNqXeyZ/edit?usp=sharing&ouid=113036597464866182871&rtpof=true&sd=true) |
| - | 2022-06-15 Qui   | T3 |
| 26 | 2022-06-20 Ter   | [Programação Paralela com OpenACC](https://docs.google.com/presentation/d/1-CvoiQRqqnhK-MFzW0hZ7QxF0cEVJuHS/edit?usp=sharing&ouid=113036597464866182871&rtpof=true&sd=true) |
| 27 | 2022-06-22 Qui   | Programação Paralela com TBB |
| 28 | 2022-06-27 Ter   | T4 |
| 29 | 2022-06-29 Qui   | - |
| 30 | 2022-07-04 Ter   | T5 |
|  | 2022-07-06 Qui   | |
| - | 2022-07-11 Ter   | **Sem aula** (Sexta-feira)  |
| - | 2022-07-13 Qui   | **Sem aula** (Sábado)  |
| - | 2023-07-18 Ter | **Avaliações Finais** |
