Link para o dataset no Hugging Face: https://huggingface.co/datasets/vinimuchulski/perguntas_e_respostas_astronomia_pt_br


# Chatbots de Astronomia e Geração de Dados com IA

Este repositório contém implementações de chatbots focados em astronomia, utilizando diferentes abordagens e bibliotecas Python, além de um script para gerar dados de treinamento (perguntas e respostas) usando a API Gemini do Google através do LangChain.

## Visão Geral

O projeto demonstra duas maneiras de construir um chatbot simples baseado em um conjunto de perguntas e respostas pré-definido:

1.  **NLTK + spaCy:** Utiliza NLTK e spaCy para pré-processamento de texto avançado (tokenização, lematização, remoção de stopwords, stemming) e TF-IDF com similaridade de cossenos para encontrar a resposta mais relevante em uma base de conhecimento (arquivo JSON).
2.  **ChatterBot:** Utiliza a biblioteca ChatterBot, que é treinada diretamente com os pares de pergunta e resposta do arquivo JSON e usa sua própria lógica para encontrar a melhor correspondência.

Além disso, inclui um script para popular e expandir a base de conhecimento:

3.  **Gemini + LangChain:** Usa um modelo de linguagem grande (Google Gemini) via LangChain para gerar novos pares de perguntas e respostas sobre astronomia, garantindo que sejam diferentes das já existentes e salvando-as no mesmo arquivo JSON.

## Estrutura do Projeto

*   `chatbot_com_nltk_e_spacy.py`: Script que implementa o chatbot usando NLTK, spaCy e Scikit-learn (TF-IDF/Cosine Similarity).
*   `chatbot_astrobot.py`: Script que implementa o chatbot usando a biblioteca ChatterBot.
*   `gemini_dados_astrobot_langchain.py`: Script para gerar dados (perguntas e respostas) usando a API Google Gemini e LangChain.
*   `perguntas_astronomia_langchain.json`: Arquivo JSON contendo os pares de pergunta e resposta usados como base de conhecimento pelos chatbots. Este arquivo é lido pelos chatbots e modificado/expandido pelo script de geração de dados.
*   `(Opcional) db_astronomia.sqlite3`: Banco de dados SQLite criado automaticamente pelo ChatterBot (`chatbot_astrobot.py`) para armazenar seu conhecimento treinado.

## Pré-requisitos

*   Python 3.x
*   Bibliotecas Python (instale via pip):
    ```bash
    pip install nltk spacy scikit-learn chatterbot chatterbot_corpus langchain-google-genai google-generativeai
    ```
*   Modelos de linguagem e dados NLTK:
    ```bash
    python -m spacy download pt_core_news_sm
    python -m nltk.download stopwords
    python -m nltk.download rslp
    ```
*   **API Key do Google Gemini:** Para usar o script `gemini_dados_astrobot_langchain.py`, você precisará de uma chave de API do Google Gemini. O script espera que a chave esteja configurada como um segredo no Google Colab (`userdata.get('GEMINI_API_KEY')`). Se estiver executando localmente, você precisará adaptar o código para carregar a chave de um arquivo `.env` ou variável de ambiente (ex: `os.getenv("GEMINI_API_KEY")`).

## Como Usar

1.  **Gerar/Expandir Dados (Opcional, requer API Key):**
    *   Certifique-se de que sua API Key do Google Gemini está configurada corretamente (veja Pré-requisitos).
    *   Execute o script:
        ```bash
        python gemini_dados_astrobot_langchain.py
        ```
    *   Este script tentará ler o `perguntas_astronomia_langchain.json` existente, gerar 10 novas perguntas e respostas usando o Gemini (evitando duplicatas com base nas perguntas já existentes) e salvará o resultado combinado de volta no arquivo JSON.

2.  **Executar o Chatbot NLTK/spaCy:**
    *   Execute o script:
        ```bash
        python chatbot_com_nltk_e_spacy.py
        ```
    *   O script, como está, irá processar as perguntas no arquivo JSON, treinar o vetorizador TF-IDF e, em seguida, testar algumas perguntas pré-definidas no código, imprimindo a pergunta e a resposta encontrada com base na similaridade de cossenos. Você pode adaptar a parte final do script para criar um loop interativo que aceite perguntas do usuário.

3.  **Executar o Chatbot ChatterBot:**
    *   Execute o script:
        ```bash
        python chatbot_astrobot.py
        ```
    *   Na primeira execução (ou se o banco `db_astronomia.sqlite3` não existir), o ChatterBot será treinado com os dados do `perguntas_astronomia_langchain.json`.
    *   Após o treinamento (ou se já treinado), ele iniciará um prompt interativo no console onde você pode fazer perguntas sobre astronomia. Digite `parar` para sair.

## O Arquivo `perguntas_astronomia_langchain.json`

Este arquivo é central para o funcionamento dos chatbots. Ele contém uma lista de objetos JSON, onde cada objeto tem duas chaves:

*   `"pergunta"`: Uma string contendo a pergunta sobre astronomia.
*   `"resposta"`: Uma string contendo a resposta correspondente.

Este arquivo é usado como fonte de dados para treinamento (ChatterBot) e como base de consulta (NLTK/spaCy). O script `gemini_dados_astrobot_langchain.py` adiciona novos pares a este arquivo.

## Como Funciona (Resumo Técnico)

*   **`chatbot_com_nltk_e_spacy.py`:**
    1.  Lê perguntas e respostas do JSON.
    2.  Pré-processa as perguntas: remove pontuação, converte para minúsculas, lematiza com spaCy, remove stopwords do NLTK e aplica stemming (RSLP) com NLTK.
    3.  Cria uma matriz TF-IDF a partir das perguntas processadas.
    4.  Quando uma nova pergunta chega, ela é pré-processada da mesma forma.
    5.  Calcula a similaridade de cossenos entre o vetor TF-IDF da nova pergunta e os vetores de todas as perguntas na base de conhecimento.
    6.  Retorna a resposta correspondente à pergunta com a maior similaridade.

*   **`chatbot_astrobot.py`:**
    1.  Lê os pares de pergunta e resposta do JSON.
    2.  Usa o `ListTrainer` do ChatterBot para treinar o bot com essa lista como uma sequência de conversa.
    3.  Armazena o conhecimento treinado em um banco de dados SQLite.
    4.  Ao receber uma pergunta, usa o adaptador lógico `BestMatch` para encontrar a resposta mais similar no conhecimento treinado, com um limiar de confiança (`maximum_similarity_threshold`).

*   **`gemini_dados_astrobot_langchain.py`:**
    1.  Lê as perguntas existentes do arquivo JSON (se houver).
    2.  Constrói um prompt para o LLM (Gemini), instruindo-o a gerar 10 *novos* pares de pergunta/resposta sobre astronomia, fornecendo as perguntas existentes como contexto para evitar repetições.
    3.  Define um formato de saída esperado (JSON) usando Pydantic e `JsonOutputParser` do LangChain.
    4.  Envia o prompt para a API Gemini através do LangChain.
    5.  Faz o parse da resposta JSON do LLM.
    6.  Combina os dados existentes com os novos dados gerados.
    7.  Salva a lista combinada de volta no arquivo JSON.

---

