import streamlit as st
import pandas as pd
import plotly.express as px

st.set_page_config(
    page_title="ENEM 2019 - Araranguá",
    page_icon="📊",
    layout="wide"
)


@st.cache_data
def carregar_dados():
    df = pd.read_csv("enem_ararangua_2019.csv")
    df["TESTS_GRADE"] = (df["NU_NOTA_CN"] + df["NU_NOTA_CH"] + df["NU_NOTA_LC"] + df["NU_NOTA_MT"]) / 5
    return df

@st.cache_data
def criar_histograma(df, x_column, title, x_label, nbins=None):
    color_sequence = px.colors.qualitative.Plotly
    fig = px.histogram(
        df, 
        x=x_column, 
        nbins=nbins,
        labels={x_column: x_label, "count": "Quantidade"},
        title=title,
        color_discrete_sequence=color_sequence
    )
    fig.update_layout(
        bargap=0.1,
        title_font_size=24,
        xaxis_title_font_size=18,
        yaxis_title_font_size=18
    )
    return fig


df_aru = carregar_dados()

# Interface do usuário
st.title("ENEM 2019 - Araranguá")

st.write("""
    Bem-vindo à análise dos dados do ENEM 2019 para a cidade de Araranguá. 
    Esta dashboard apresenta informações sobre os candidatos.
""")


col1, col2 = st.columns(2)

with col1:
    
    fig_notas = criar_histograma(df_aru, "TESTS_GRADE", "Distribuição das Notas", "Notas")
    st.plotly_chart(fig_notas, use_container_width=True, theme="streamlit")

    
    fig_generos = criar_histograma(df_aru, "TP_SEXO", "Distribuição dos Gêneros", "Gêneros")
    st.plotly_chart(fig_generos, use_container_width=True, theme="streamlit")

with col2:
    
    fig_idades = criar_histograma(df_aru, "NU_IDADE", "Distribuição das Idades", "Idade", nbins=30)
    st.plotly_chart(fig_idades, use_container_width=True, theme="streamlit")


st.subheader("Estatísticas Resumidas")
st.dataframe(df_aru.describe())


st.markdown("---")
st.caption("Dados fornecidos pelo INEP")