import streamlit as st
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import plotly.express as px

@st.cache_data
def carregar_dados():
    df_aru = pd.read_csv("enem_ararangua_2019.csv")
    df_aru["TESTS_GRADE"] = (df_aru["NU_NOTA_CN"] + df_aru["NU_NOTA_CH"] + df_aru["NU_NOTA_LC"] + df_aru["NU_NOTA_MT"])/5
    
    return df_aru

df_aru = carregar_dados()

st.write(""" 
         # ENEM 2019 - Araranguá
        
         """) #markdown

st.write('apresentamos dados dos candidatos que realizaram o ENEM 2019 na cidade,incluindo informações demográficas, tipo de escola, notas das provas e respostas a questões socioeconômicas.')

@st.cache_data
def get_histogram_enem(df, x_column, title, x_label, nbins=None):
    fig = px.histogram(df, x=x_column, nbins=nbins,
                       labels={x_column: x_label, "count": "Quantidade"},
                       title=title)
    fig.update_layout(bargap=0.1)
    return fig


st.write("Distribuição das notas das provas")
fig_notas = get_histogram_enem(df_aru, "TESTS_GRADE", "Distribuição das Notas das Provas", "Notas")
st.plotly_chart(fig_notas, theme="streamlit")

st.write("Distribuição das idades")
fig_idades = get_histogram_enem(df_aru, "NU_IDADE", "Distribuição das Idades", "Idade", nbins=30)
st.plotly_chart(fig_idades, theme="streamlit")

st.write("Distribuição dos gêneros na prova")
fig_generos = get_histogram_enem(df_aru, "TP_SEXO", "Distribuição dos Gêneros", "Gêneros")
st.plotly_chart(fig_generos, theme="streamlit", use_container_width=True)



