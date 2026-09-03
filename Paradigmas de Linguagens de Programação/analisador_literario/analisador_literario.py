import csv
from functools import reduce

CAMINHO_CSV = "obras.csv"

STOPWORDS = {
    "de", "a", "o", "que", "e", "do", "da", "em", "um", "para",
    "com", "uma", "os", "no", "se", "na", "por", "mais", "as",
    "dos", "como", "mas", "ao", "ele", "das", "seu", "sua", "ou",
    "quando", "muito", "nos", "ja", "eu", "tambem", "so", "pelo",
    "pela", "ate", "isso", "ela", "entre", "era", "depois", "sem",
    "mesmo", "aos", "seus", "suas", "lhe", "me", "te", "meu", "minha",
    "foi", "nao", "não", "this", "the", "disse", "bem", "tao", "tão",
    "nem", "si", "ha", "há", "ter", "ser", "vai", "ia", "ali", "aqui",
    "já", "ja", "também", "tambem", "só", "so", "até", "ate",
    "então", "entao", "ainda", "assim", "lá", "la", "sim"
}

PONTUACAO = set(".,;:!?\"'()[]{}—-_/\\@#$%^&*+=<>|`~\n\t0123456789")

ler_csv = lambda caminho: list(csv.DictReader(open(caminho, encoding="utf-8")))

filtrar_obra = lambda dados, nome_obra: list(filter(lambda linha: linha["obra"] == nome_obra, dados))

extrair_texto = lambda linhas: reduce(lambda acc, linha: acc + " " + linha["texto"],linhas,"")

obter_obras = lambda dados: reduce(lambda acc, linha: acc if linha["obra"] in acc else acc + [linha["obra"]],dados,[])

normalizar = lambda texto: reduce(lambda acc, c: acc + str.lower(c), texto, "")

sem_pontuacao = lambda texto: reduce(lambda acc, c: acc + c if c not in PONTUACAO else acc,texto,"")

#tokenizar = lambda texto: texto.split()
tokenizar = lambda texto: list(filter(
    lambda t: len(t) > 0,
    reduce(
        lambda acc, c: acc[:-1] + [acc[-1] + c] if c != " " else acc + [""],
        texto,
        [""]
    )
))

sem_stopwords = lambda palavras: list(filter(lambda p: p not in STOPWORDS and len(p) > 2, palavras))

preprocessar = lambda texto: sem_stopwords(tokenizar(sem_pontuacao(normalizar(texto))))

contar_frequencias = lambda palavras: reduce(lambda acc, palavra: {**acc,palavra: (acc[palavra] + 1) if palavra in acc else 1},palavras,{})

pares = lambda d: reduce(lambda acc, k: acc + [(k, d[k])], d, [])

criar_ranking = lambda n: lambda frequencias: sorted(pares(frequencias),key=lambda item: item[1],reverse=True)[:n]

top_10 = criar_ranking(10)

calcular_riqueza = lambda palavras: round(len(set(palavras)) / len(palavras), 4) if palavras else 0

vocabulario = lambda freq: set(freq)

vocab_comum = lambda sets: reduce(lambda a, b: a & b, sets)

vocab_exclusivo = lambda vocab_obra, comum: vocab_obra - comum

dados_csv = ler_csv(CAMINHO_CSV)
obras = obter_obras(dados_csv)

palavras_por_obra = dict(map(lambda obra: (obra, preprocessar(extrair_texto(filtrar_obra(dados_csv, obra)))),obras))

frequencias_por_obra = dict(map(lambda par: (par[0], contar_frequencias(par[1])),pares(palavras_por_obra)))

rankings_por_obra = dict(map(lambda par: (par[0], top_10(par[1])),pares(frequencias_por_obra)))

riqueza_por_obra = dict(map(lambda par: (par[0], calcular_riqueza(par[1])),pares(palavras_por_obra)))

vocab_comum_obras = vocab_comum(list(map(vocabulario, map(lambda par: par[1], pares(frequencias_por_obra)))))

exclusivo_por_obra = dict(map(lambda par: (par[0], vocab_exclusivo(vocabulario(par[1]), vocab_comum_obras)),pares(frequencias_por_obra)))

imprimir_ranking = lambda obra, ranking: (
    print(f"\n--- {obra} ---"),
    print(f"Total de palavras: {len(palavras_por_obra[obra])}"),
    list(map(
        lambda r: print(f"  {r[0]+1:2}. {r[1][0]:<22} {r[1][1]} ocorrencias"),
        enumerate(ranking)
    ))
)

imprimir_riqueza = lambda par: print(f"  {par[0]:<40} -> {par[1]}")

imprimir_exclusivo = lambda par: print(f"  {par[0]:<40} -> {len(par[1])} palavras exclusivas")

(
    print("ANALISADOR DE TEXTO LITERARIO — MACHADO DE ASSIS"),
    print("FREQUENCIA ABSOLUTA E RANKING"),
    list(map(lambda par: imprimir_ranking(par[0], par[1]), pares(rankings_por_obra))),

    print("\nRIQUEZA VOCABULAR"),
    print("  (quanto mais proximo de 1.0, mais variado o vocabulario)"),
    list(map(imprimir_riqueza, pares(riqueza_por_obra))),

    print("\nCOMPARACAO LEXICAL ENTRE OBRAS"),
    print(f"  Palavras em comum entre todas as obras: {len(vocab_comum_obras)}"),
    print(f"  Exemplos: {sorted(list(vocab_comum_obras))[:10]}"),
    print("\n  Vocabulario exclusivo por obra:"),
    list(map(imprimir_exclusivo, pares(exclusivo_por_obra)))
)