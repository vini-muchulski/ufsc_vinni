# -*- coding: utf-8 -*-
"""open data sus



## **Fonte dos dados** :

[Link Open Data SUS](https://opendatasus.saude.gov.br/organization/ministerio-da-saude)
[sindrome gripal](https://opendatasus.saude.gov.br/dataset/notificacoes-de-sindrome-gripal-leve-2024)

"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import streamlit as st
import plotly.express as px

"""# Sindrome Gripal"""
# Título do Dashboard
st.title("Dashboard Interativo de Síndrome Gripal - Araranguá")
st.write("Análise exploratória dos dados de síndrome gripal em Araranguá - SC")
st.write("Fonte dos dados: [Open Data SUS](https://opendatasus.saude.gov.br/dataset/notificacoes-de-sindrome-gripal-leve-2024)")

df = pd.read_csv('dados_gripe_aru.csv', sep=';', encoding='utf-8', engine='python', on_bad_lines='skip')

# Converter a coluna 'dataNotificacao' para formato de data
df['dataNotificacao'] = pd.to_datetime(df['dataNotificacao'], errors='coerce')

# Remover registros sem dataNotificacao válida
df_filtered = df.dropna(subset=['dataNotificacao'])

# Filtrar os dados apenas para o ano de 2024
df_filtered_2024 = df_filtered[df_filtered['dataNotificacao'].dt.year == 2024]

# Gráfico mais detalhado para o ano de 2024
plt.figure(figsize=(10, 6))
sns.histplot(df_filtered_2024['dataNotificacao'], kde=True) # bins=30
plt.title('Distribuição Temporal dos Casos em 2024')
plt.xlabel('Data de Notificação')
plt.ylabel('Número de Casos')
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()

# Gráfico 2: Distribuição por Sexo e Idade
plt.figure(figsize=(6, 6))
sns.boxplot(x='sexo', y='idade', data=df, palette='Set2')
plt.title('Distribuição por Sexo e Idade')
plt.xlabel('Sexo')
plt.ylabel('Idade')
plt.tight_layout()
plt.show()

# Gráfico 3: Evolução dos Casos
plt.figure(figsize=(6, 6))
sns.countplot(x='evolucaoCaso', data=df, palette='Set3')
plt.title('Distribuição das Evoluções dos Casos')
plt.xlabel('Evolução do Caso')
plt.ylabel('Número de Casos')
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()

df['evolucaoCaso'].value_counts()

