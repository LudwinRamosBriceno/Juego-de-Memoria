#include <QCoreApplication>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <socketserver.h>
#include <servidor.h>
#include <QDebug>

class MockClient: public socketServer{ // simulacion del cliente, con los posibles casos
    public:
        int numCaso = 0;
        MockClient(int caso){
            numCaso = caso;
        }
        QString read();
        void setCaso(int casoNuevo){
            numCaso = casoNuevo;
        }
};
QString MockClient::read(){
    qDebug()<<"hola \n";
    switch(numCaso){
        case 1:
            return "iniciar,Juan,Pablo"; // Mensaje de Inicio
        case 2:
            return "primeraTarjeta,6"; // primera tarjeta en memoria
        case 3:
            return "segundaTarjeta,25"; // segunda tarjeta en disco
        case 4:
            return "primeraTarjeta,20"; // primera tarjeta en disco
        case 5:
            return "segundaTarjeta,3"; // segunda tarjeta en memoria
        case 6:
            return "finalizar";
        default:
            return "";
    }
}


TEST(verificacionMensajes,mensajeInicio){ // primer mensaje
    // Arrange
    MockClient *mockclient = new MockClient(1);
    Servidor server = Servidor(mockclient);

    // Act
    bool resultado = server.leer_mensaje();
    //Assert
    delete mockclient;
    mockclient = nullptr;
    EXPECT_EQ(resultado,true);
}
TEST(verificacionMensajes,primeraTarjetaEnMemoria){ // Solicitar Imagen primera tarjeta en memoria
    // Arrange
    MockClient *mockclient = new MockClient(2);
    Servidor server = Servidor(mockclient);

    // Act
    bool resultado = server.leer_mensaje();
    //Assert
    EXPECT_EQ(resultado,true);
}
TEST(verificacionMensajes,primeraTarjetaEnDisco){ // Solicitar Imagen de primera tarjeta en Disco
    // Arrange
    MockClient *mockclient = new MockClient(4);
    Servidor server = Servidor(mockclient);

    // Act
    bool resultado = server.leer_mensaje();
    //Assert
    EXPECT_EQ(resultado,true);
}
TEST(verificacionMensajes,segundaTarjetaEnMemoria){ // Solicitar Imagen de segunda tarjeta en memoria
    // Arrange
    MockClient *mockclient = new MockClient(5);
    Servidor server = Servidor(mockclient);

    // Act
    bool resultado = server.leer_mensaje();
    //Assert
    EXPECT_EQ(resultado,true);
}
TEST(verificacionMensajes,segundaTarjetaEnDisco){ // Solicitar Imagen de segunda tarjeta en Disco
    // Arrange
    MockClient *mockclient = new MockClient(3);
    Servidor server = Servidor(mockclient);

    // Act
    bool resultado = server.leer_mensaje();
    //Assert
    EXPECT_EQ(resultado,true);
}
TEST(verificacionMensajes,AmbasTarjetasEnMemoria){ // Solicitar Imagen de Ambas de tarjetas en Memoria
    // Arrange
    MockClient *mockclient = new MockClient(2);
    Servidor server = Servidor(mockclient);

    // Act
    bool resultado1 = server.leer_mensaje();
    mockclient->numCaso = 5;
    bool resultado2 = server.leer_mensaje();
    //Assert
    EXPECT_EQ(resultado1,true);
    EXPECT_EQ(resultado2,true);
}
TEST(verificacionMensajes,AmbasTarjetasEnDisco){ // Solicitar Imagen de Ambas de tarjetas en Disco
    // Arrange
    MockClient *mockclient = new MockClient(4);
    Servidor server = Servidor(mockclient);

    // Act
    bool resultado1 = server.leer_mensaje();
    mockclient->numCaso = 3;
    bool resultado2 = server.leer_mensaje();
    //Assert
    EXPECT_EQ(resultado1,true);
    EXPECT_EQ(resultado2,true);
}
TEST(verificacionMensajes,tarjeta1EnMemoriaTarjeta2EnDisco){ /* Solicitar Imagen de la primera tarjeta en memoria y
                                                                la imagen de la segunda tarjeta en Disco */
    // Arrange
    MockClient *mockclient = new MockClient(2);
    Servidor server = Servidor(mockclient);

    bool resultado1 = server.leer_mensaje();
    mockclient->numCaso = 3;
    bool resultado2 = server.leer_mensaje();
    //Assert
    EXPECT_EQ(resultado1,true);
    EXPECT_EQ(resultado2,true);
}
TEST(verificacionMensajes,tarjeta1EnDiscoTarjeta2EnMemoria){/* Solicitar Imagen de la primera tarjeta en Disco y
                                                                la imagen de la segunda tarjeta en memoria */
    // Arrange
    MockClient *mockclient = new MockClient(4);
    Servidor server = Servidor(mockclient);

    bool resultado1 = server.leer_mensaje();
    mockclient->numCaso = 5;
    bool resultado2 = server.leer_mensaje();
    //Assert
    EXPECT_EQ(resultado1,true);
    EXPECT_EQ(resultado2,true);
}
TEST(verificacionMensajes,finalizarJuego){/* Solicitar Imagen de la primera tarjeta en Disco y
                                                                la imagen de la segunda tarjeta en memoria */
    // Arrange
    MockClient *mockclient = new MockClient(6);
    Servidor server = Servidor(mockclient);

    // Act
    bool resultado = server.leer_mensaje();
    //Assert
    EXPECT_EQ(resultado,true);
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    testing::InitGoogleTest(&argc,argv);

    return RUN_ALL_TESTS();
}