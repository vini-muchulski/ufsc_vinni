import pandas as pd
import streamlit as st
import plotly.express as px


st.set_page_config(page_title="Dashboard Síndrome Gripal - Araranguá", layout="wide")
st.title("Dashboard Interativo de Síndrome Gripal - Araranguá")
st.markdown("""
<style>
    .reportview-container {
        background-color: #f0f2f6;
    }
    .sidebar .sidebar-content {
        background-color: #f0f2f6;
    }
</style>
""", unsafe_allow_html=True)

st.write("""
Este dashboard apresenta uma análise exploratória dos casos de Síndrome Gripal no município de **Araranguá - SC** no ano de 2024.
Os dados foram obtidos a partir da plataforma **[Open Data SUS](https://opendatasus.saude.gov.br/dataset/notificacoes-de-sindrome-gripal-leve-2024)**.
""")


df = pd.read_csv('dados_gripe_aru.csv', sep=',', encoding='utf-8', engine='python')

# Converter a coluna 'dataNotificacao' para formato de data
# Remover registros sem data válida
# Filtrar os dados para o ano de 2024


df['dataNotificacao'] = pd.to_datetime(df['dataNotificacao'], errors='coerce')
df_filtered = df.dropna(subset=['dataNotificacao'])
df_filtered_2024 = df_filtered[df_filtered['dataNotificacao'].dt.year == 2024]


col1, col2 = st.columns(2)

with col1:
    st.subheader("Distribuição Temporal dos Casos em 2024")
    fig1 = px.histogram(df_filtered_2024, x='dataNotificacao', title='Distribuição Temporal dos Casos', nbins=30)
    fig1.update_layout(xaxis_title='Data de Notificação', yaxis_title='Número de Casos', bargap=0.2)
    st.plotly_chart(fig1, use_container_width=True)


with col2:
    st.subheader("Distribuição por Sexo e Idade")
    fig2 = px.box(df_filtered, x='sexo', y='idade', color='sexo', title='Distribuição por Sexo e Idade')
    fig2.update_layout(xaxis_title='Sexo', yaxis_title='Idade')
    st.plotly_chart(fig2, use_container_width=True)


st.subheader("Distribuição das Evoluções dos Casos")
fig3 = px.histogram(df_filtered, x='evolucaoCaso', title='Evolução dos Casos')
fig3.update_layout(xaxis_title='Evolução do Caso', yaxis_title='Número de Casos', bargap=0.2)
st.plotly_chart(fig3, use_container_width=True)


st.subheader("Estatísticas de Evolução dos Casos")
evolucao_contagem = df['evolucaoCaso'].value_counts()
st.write(evolucao_contagem)

# Filtro interativo de evolução
st.sidebar.title("Filtros")
evolucoes_selecionadas = st.sidebar.multiselect('Selecione as Evoluções do Caso', df['evolucaoCaso'].unique(), default=df['evolucaoCaso'].unique())


df_filtrado = df[df['evolucaoCaso'].isin(evolucoes_selecionadas)]

st.subheader("Distribuição dos Casos Filtrados")
fig_filtrado = px.histogram(df_filtrado, x='dataNotificacao', nbins=30, title='Distribuição dos Casos Filtrados')
st.plotly_chart(fig_filtrado, use_container_width=True)
