export default function Home() {
  return (
    <main className="flex min-h-screen items-center justify-center bg-gray-100 p-6">
      <div className="flex gap-10 max-w-4xl items-center bg-white shadow-lg rounded-2xl p-8">
        {}
        <img
          src="/images/me.jpeg"
          alt="Minha Foto"
          className="w-64 h-64 rounded-xl object-cover shadow-md"
        />

        {}
        <div className="text-left text-gray-900">
          <h1 className="text-3xl font-bold mb-4">NOEMI SOARES</h1>

          <p className="mb-4 leading-relaxed">
            Sou estudante do curso de Ciência da Computação da Universidade
            Católica de Pernambuco (UNICAP). Gosto de desenvolver novos projetos
            continuamente, para aplicar meus aprendizados de forma prática.
          </p>

          <p className="mb-4 leading-relaxed">
            Quando não estou programando, você pode me encontrar lendo diversos
            livros, jogando RPG de mesa e passando um tempo em família.
          </p>

          <p className="italic text-gray-600">
            "Trabalho duro é inútil para aqueles que não acreditam em si
            mesmos."
          </p>
        </div>
      </div>
    </main>
  );
}
